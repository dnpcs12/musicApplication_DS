#include "MusicApplicationByQt.h"


MusicApplicationByQt::MusicApplicationByQt(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.MusicList->setEditTriggers(QAbstractItemView::NoEditTriggers); // music ���̺��� �Է� ����
	ui.inPlayList->setEditTriggers(QAbstractItemView::NoEditTriggers); //in play list  �Է� ����
	ui.searchResult->setEditTriggers(QAbstractItemView::NoEditTriggers);

	// ���� �ʱ�ȭ 
	curPlayerName = "None"; // ���� �÷��̾� 
	curMusicId = "None";
	isNone = true;
	isRandom = false;
	isLoop = noLoop;
	curPlayIndex = 0;
	ui.NoLoop->setChecked(true);
	
	inputWindow = nullptr;
	playlistSelectWindow = nullptr;
	playlistInput = nullptr;


	//----------------------- ��Ŭ���� �޴� ���� �κ�(�뷡)-------------------------------------------//
	ui.MusicList->setContextMenuPolicy(Qt::CustomContextMenu); 

	connect(ui.MusicList, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(ContextMenuShow(QPoint)));
	QList <QAction*> ContextAction; 

	ContextAction.append(new QAction(QString::fromLocal8Bit("����")));
	ContextAction.append(new QAction(QString::fromLocal8Bit("����")));
	ContextAction.append(new QAction(QString::fromLocal8Bit("�����Ͽ� �߰�"))); 
	ContextAction.append(new QAction(QString::fromLocal8Bit("��� ���� �����Ͽ� �߰�")));

	ContextMenu = new QMenu();

	connect(ContextAction.at(0), SIGNAL(triggered(bool)), this, SLOT( DeleteMusic() ));
	connect(ContextAction.at(1), SIGNAL(triggered(bool)), this, SLOT( ChangeMusic() ));
	connect(ContextAction.at(2), SIGNAL(triggered(bool)), this, SLOT( openPLSelectWindow()));
	connect(ContextAction.at(3), SIGNAL(triggered(bool)), this, SLOT(OpenPLSelectWindow_All()));

	ContextMenu->addActions(ContextAction);
	//---------------------------------------��Ŭ���� �޴����� �κ�(�÷��� ����Ʈ)--------------------------------- //
	ui.inPlayList->setContextMenuPolicy(Qt::CustomContextMenu);

	connect(ui.inPlayList, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(PLContextMenuShow(QPoint)));
	QList <QAction*> pLContextAction;

	pLContextAction.append(new QAction(QString::fromLocal8Bit("�����Ͽ��� ����")));
	//pLContextAction.append(new QAction(QString::fromLocal8Bit("����")));
	//pLContextAction.append(new QAction(QString::fromLocal8Bit("�����Ͽ� �߰�")));
	PlaylistMenu = new QMenu();

	connect(pLContextAction.at(0), SIGNAL(triggered(bool)), this, SLOT(DeleteSongInPL()));
	//connect(ContextAction.at(1), SIGNAL(triggered(bool)), this, SLOT(ChangeMusic()));
	//connect(ContextAction.at(2), SIGNAL(triggered(bool)), this, SLOT(openPLSelectWindow()));

	PlaylistMenu->addActions(pLContextAction);
	//-----------------------------------------------------------------------------------------------------------------//
	//AddRankPlaylist();
	
	AddPlayList(QRANKLISTNAME);
}




void MusicApplicationByQt::AddMusic(QStringList tmp) {
	
	ItemType item;

	if (tmp[0].length() <= 0) {
		tmp[0] = "music";
	}
	QString origin = tmp[0];
	item.SetId(tmp[0].toStdString());
	int c = 0;
	while (m_List.RetrieveByBS(item)) {
		c++;
		tmp[0] = origin + "("+QString::fromStdString(std::to_string(c)) +")";
		item.SetId(tmp[0].toStdString());

	}
	
	item.SetRecord(tmp[0].toStdString(), tmp[1].toStdString(), tmp[3].toStdString(), tmp[2].toStdString(), tmp[4].toStdString());
	item.SetPlayNum(tmp[5].toInt());
	item.SetLyric(tmp[6].toStdString());


	m_List.Add(item);
	AddSoogToRankList(item);
	/*
		int itemNum = m_List.GetLength();
		ui.MusicList->setRowCount(itemNum);
		for (int i = 0; i < 5; i++) {
			ui.MusicList->setItem(itemNum-1, i, new QTableWidgetItem(tmp[i]));
		}
	*/
	UpdateCurMusicList();
	
}


void MusicApplicationByQt::DeleteMusic()
{
	int row = ui.MusicList->currentRow();
	string id = ui.MusicList->item(row,0)->text().toStdString();
	ItemType item;
	item.SetId(id);
	m_List.Delete(item);
	ui.MusicList->model()->removeRow(row);
}

void MusicApplicationByQt::MusicPlay()
{
	ui.debuglable->setText("play...");
	curPlayerName = "MasterList";
	int row = ui.MusicList->currentRow();
	string id = ui.MusicList->item(row, 0)->text().toStdString();
	ItemType item;
	item.SetId(id);
	if (m_List.RetrieveByBS(item)) {
		curPlayIndex = m_List.GetCurIndex();
		Play(item);
	}

}

void MusicApplicationByQt::MakeEmpty()
{
	ui.MusicList->setRowCount(0);
	m_List.MakeEmpty();
}

void MusicApplicationByQt::ChangeMusic()
{
	int row = ui.MusicList->currentRow();
	string id = ui.MusicList->item(row, 0)->text().toStdString();
	ItemType item;
	item.SetId(id);
	m_List.RetrieveByBS(item);
	getMusicInfo();
	inputWindow->SetChangedMode(item);
}


void MusicApplicationByQt::openPlaylistAddWindow()
{
	playlistInput = new QtWindow_playlist(this);
	playlistInput->show();
}

void MusicApplicationByQt::AddPlayList(QString name)
{
	if (name.length() == 0) {
		name = QString::fromLocal8Bit("�� ������");
	}
	PlayerType player(name.toStdString());

	//---------�ߺ��� �̸� �˻��ϰ� �ڵ����� ���� �ٿ���------------//
	PlayerType origin(player.GetPLName());
	int c = 0;
	while (MasterPlayList.Get(player)) {
		c++;
		player.SetName(origin.GetPLName() +"(" +std::to_string(c) +")");
	}
	name = QString::fromStdString(player.GetPLName());
	origin.SetName(player.GetPLName());
	MasterPlayList.Add(origin);

	ui.QMasterPlayList->addItem(name);
	if (playlistSelectWindow == nullptr) return;
	if (playlistSelectWindow->isVisible()) {
		ui.debuglable->setText("select window open!");
		playlistSelectWindow->AddNewPL(QString::fromStdString(origin.GetPLName()));
	}

}

void MusicApplicationByQt::ContextMenuShow(const QPoint& pos)

{
 
	if (ui.MusicList->rowCount() > 0) //���̺������� �Ѱ��� ������� ���ؽ�Ʈ �޴� ���� 
//���̺��������� ���콺�����ʹ�ư ������ ���콺 ��ǥ�� ���ؽ�Ʈ �޴� �����ǰԲ� ��ġ��ȯ
	ContextMenu->exec(ui.MusicList->viewport()->mapToGlobal(pos));
	

}

void MusicApplicationByQt::PLContextMenuShow(const QPoint& pos)
{
	if (ui.inPlayList->rowCount() > 0) //���̺������� �Ѱ��� ������� ���ؽ�Ʈ �޴� ���� {
				//���̺��������� ���콺�����ʹ�ư ������ ���콺 ��ǥ�� ���ؽ�Ʈ �޴� �����ǰԲ� ��ġ��ȯ
	PlaylistMenu->exec(ui.inPlayList->viewport()->mapToGlobal(pos));
	
}

void MusicApplicationByQt::AddMusicToPL(QString name) // ���� �߰��� �÷��� ����Ʈ�� �̸��� �޾ƿ� �� �÷��̸���Ʈ�� �߰�. 
{
	PlayerType player(name.toStdString());
	//ui.debuglable->setText(name);
	if (!MasterPlayList.Get(player)) return;
	PlayItem pI;
	pI.SetId(tmpPlayItem.GetId());
	player.AddSong(pI);
	MasterPlayList.Replace(player);
}

void MusicApplicationByQt::AddAllMusicToPL(QString name)
{
	ui.debuglable->setText("All Music To PL");
	PlayerType player(name.toStdString());
	if (!MasterPlayList.Get(player)) return;
	
	m_List.ResetList();
	PlayItem pI;
	ItemType item;
	while (m_List.GetNextItem(item) != -1) {
		pI.SetId(item.GetId());
		player.AddSong(pI);
	}
	MasterPlayList.Replace(player);
}

void MusicApplicationByQt::OpenPLSelectWindow_All()
{
	QStringList nameList;
	DoublyIterator<PlayerType> iter(MasterPlayList);
	ui.debuglable->setText(QString::fromStdString(std::to_string(MasterPlayList.GetLength()))); // ����� 
	iter.Next();
	while (iter.NextNotNull()) {
		nameList.append(QString::fromStdString(iter.GetCurrentNode().data.GetPLName()));
		iter.Next();
	}

	playlistSelectWindow = new QtWindowSelectPlayList(this);
	playlistSelectWindow->show();
	playlistSelectWindow->SetSelectWindow(nameList,true);
}

void MusicApplicationByQt::DeletePlayList()
{
	int row = ui.QMasterPlayList->currentRow();
	if (row < 1) return;
	PlayerType player;

	player.SetName(ui.QMasterPlayList->currentItem()->text().toStdString());
	if(MasterPlayList.Delete(player))
	ui.QMasterPlayList->model()->removeRow(row);
	
}

void MusicApplicationByQt::ShowInPlayList()
{
	bool isRankList = false;
	ui.debuglable->setText("double clicked");
	if (ui.QMasterPlayList->currentItem() == nullptr) return;
	PlayerType player(ui.QMasterPlayList->currentItem()->text().toStdString());
	if (player.GetPLName() == RANKLISTNAME) isRankList = true;

	ui.debuglable->setText(QString::fromStdString(player.GetPLName()));
	
	MasterPlayList.Get(player);
	ArrayList<PlayItem> curPL = player.GetPlayList();
	curPL.ResetList();
	PlayItem pI;
	ItemType item;
	QStringList info;
	//int itemNum = curPL.GetLength();
	//ui.inPlayList->clear();
	int row = 0;
	ui.inPlayList->setRowCount(0);
	curPL.ResetList();
	while (curPL.GetNextItem(pI) != -1) {
		item.SetId(pI.GetId());
		
		if (!m_List.RetrieveByBS(item)) { // �����͸���Ʈ���� ������ ���
			player.DeleteSong(pI); // �ش� �÷��̸���Ʈ���� ���� �����ϰ�
			MasterPlayList.Replace(player); // ������Ʈ 
			ui.inPlayList->setRowCount(player.GetPlaylistSize());
		 // �Ʒ��� �������� ����. 
		}
		else {
			if (row > 9 && isRankList)  continue;

				info.append(QString::fromStdString(item.GetId()));
				info.append(QString::fromStdString(item.GetName()));
				info.append(QString::fromStdString(item.GetMusician()));
				info.append(QString::fromStdString(std::to_string(item.GetNumPlay())));

				ui.inPlayList->setRowCount(row + 1);
				for (int i = 0; i < 4; i++) {
					ui.inPlayList->setItem(row, i, new QTableWidgetItem(info[i]));

				}
				row++;
				info.clear();
			

		}
	}
	if (row > 9 && isRankList) {
		ui.inPlayList->setRowCount(10);
	}
}

void MusicApplicationByQt::DeleteSongInPL()
{
	if (ui.QMasterPlayList->currentRow() < 1) return;

	int song_row = ui.inPlayList->currentRow();
	PlayItem pi;
	pi.SetId(ui.inPlayList->item(song_row, 0)->text().toStdString());
	PlayerType player;
	player.SetName(ui.QMasterPlayList->currentItem()->text().toStdString());
	MasterPlayList.Get(player);
	player.DeleteSong(pi);
	MasterPlayList.Replace(player);
	ShowInPlayList();
}

//playlist �ȿ� �ִ� ������ ���
void MusicApplicationByQt::MusicPlayInPL()
{
	string playerName = ui.QMasterPlayList->currentItem()->text().toStdString();
	curPlayerName = playerName;
	
	int row = ui.inPlayList->currentRow();
	PlayItem pi;
	pi.SetId(ui.inPlayList->item(row, 0)->text().toStdString());
	ItemType item;
	item.SetId(pi.GetId());
	m_List.RetrieveByBS(item);
	Play(item);

}

void MusicApplicationByQt::openPLSelectWindow()
{
	int row = ui.MusicList->currentRow();
	string id = ui.MusicList->item(row, 0)->text().toStdString();
	tmpPlayItem.SetId(id);

	QStringList nameList;
	DoublyIterator<PlayerType> iter(MasterPlayList);
	ui.debuglable->setText(QString::fromStdString(std::to_string(MasterPlayList.GetLength()))); // ����� 
	iter.Next();
	while (iter.NextNotNull()) {
		nameList.append(QString::fromStdString(iter.GetCurrentNode().data.GetPLName()));
		iter.Next();
	}

	playlistSelectWindow = new QtWindowSelectPlayList(this);
	playlistSelectWindow->show();
	playlistSelectWindow->SetSelectWindow(nameList);

}



QString MusicApplicationByQt::getFilePath(string mode)
{//QString strFilter = "bitmap file (*.bmp) ;; text file (*.txt) ;; All files (*.*)";
	QString strFilter = "text file (*.txt)";
	QString strFileName;
	if (mode == "R") {
		strFileName = QFileDialog::getOpenFileName(this, "Open a file", QApplication::applicationDirPath(), strFilter);         //::applicationDirPath() QDir::homePath()
	}
	else if(mode == "W") {
		strFileName = QFileDialog::getSaveFileName(this, "Write a file", QApplication::applicationDirPath(),strFilter);
	}
	 
	//[��ó] [Qt] QFileDialog | �ۼ��� FocalL
	return strFileName;
}

void MusicApplicationByQt::ReplaceItem(QStringList tmp)
{
	ItemType item;
	item.SetRecord(tmp[0].toStdString(), tmp[1].toStdString(), tmp[3].toStdString(), tmp[2].toStdString(), tmp[4].toStdString());
	//item.SetPlayNum(tmp[5].toInt());
	item.SetLyric(tmp[6].toStdString());

	ItemType preItem;
	preItem.SetId(item.GetId());
	
	if(!m_List.RetrieveByBS(preItem)) return;

	item.SetPlayNum(preItem.GetNumPlay());
	m_List.Replace(item);
	int row = -1;

	for (int i = 0; i < ui.MusicList->rowCount(); i++) {
		if (ui.MusicList->item(i, 0)->text() == QString::fromStdString(item.GetId())) {
			row = i;
			break;
		}
	}
	
	for (int j = 0; j < 5; j++) {
		ui.MusicList->setItem(row, j, new QTableWidgetItem(tmp[j]));
	}


}

void MusicApplicationByQt::Play(ItemType item)
{
	ui.groupBox_2->setTitle(QString::fromStdString(curPlayerName));
	curMusicId = item.GetId();
	ui.debuglable->setText("play count : " + QString::fromStdString(std::to_string(item.GetNumPlay())));
	isNone = false;
	ui.curMusicTitle->setText(QString::fromStdString(item.GetName()));
	ui.curMusicArtist->setText(QString::fromStdString(item.GetMusician()));
	ui.curMusiclyric->setText(QString::fromStdString(item.GetLyric()));
	item.upNumPlay();
	m_List.Replace(item);
	UpdateRankList(item);
	
	
}

void MusicApplicationByQt::RandomPlay()
{
	ItemType item;
	int index;
	if (curPlayerName == "MasterList") {
		index = GetRandomIndex(m_List.GetLength());
		item = m_List.at(index);
		curPlayIndex = index;
	}
	else {
		PlayerType player(curPlayerName);
		MasterPlayList.Get(player);
		index = GetRandomIndex(player.GetPlaylistSize());
		PlayItem pi = player.GetPlayList().at(index);
		item.SetId(pi.GetId());
		m_List.RetrieveByBS(item);
	}
	Play(item);
}

int MusicApplicationByQt::GetRandomIndex(int range)
{
	srand((unsigned int)time(NULL));
	int random = rand() % range;
	return random;
}

void MusicApplicationByQt::Search(QString content)
{
	string sname = content.toStdString();
	ItemType item;
	m_List.ResetList();
	int row = 0;
	bool found = false;

	while (m_List.GetNextItem(item) != -1) {
		if (item.GetId().find(sname) != string::npos ||  // ������ȣ
			item.GetName().find(sname) != string::npos || // �̸�
			item.GetMusician().find(sname) != string::npos || // ����
			item.GetGenre().find(sname) != string::npos) { // �帣 �� �ϳ��� ���� ������ ������ 

			row++;
			ui.searchResult->setRowCount(row);
			AddItemToTable(ui.searchResult, row - 1, item);
			found = true;
		}
	}
	if (!found) {
		ui.searchResult->setRowCount(0);
		ui.debuglable->setText("Search result : no music");
	}

}

void MusicApplicationByQt::SearchById(QString id) // id�� ��ġ�ϴ� ���� ��� 
{
	ItemType item;
	item.SetId(id.toStdString());
	if (m_List.RetrieveByBS(item)) {
		ui.searchResult->setRowCount(1);
		AddItemToTable(ui.searchResult, 0, item);
	}
	else {
		ui.searchResult->setRowCount(0);
		ui.debuglable->setText("Search result : no music");
	}

}

void MusicApplicationByQt::SearchByTitle(QString title)
{
	string sname = title.toStdString();
	ItemType item;
	m_List.ResetList();
	int row = 0;
	bool found = false;

	while (m_List.GetNextItem(item) != -1) {
		if (item.GetName().find(sname) != string::npos) {
			row++;
			ui.searchResult->setRowCount(row);
			AddItemToTable(ui.searchResult, row - 1, item);
			found = true;
		}
	}
	if (!found) {
		ui.searchResult->setRowCount(0);
		ui.debuglable->setText("Search result : no music");
	}
}

void MusicApplicationByQt::SearchByGenre(QString genre)
{
	string sname = genre.toStdString();
	ItemType item;
	m_List.ResetList();
	int row = 0;
	bool found = false;

	while (m_List.GetNextItem(item) != -1) {
		if (item.GetGenre().find(sname) != string::npos) {
			row++;
			ui.searchResult->setRowCount(row);
			AddItemToTable(ui.searchResult, row - 1, item);
			found = true;
		}
	}
	if (!found) {
		ui.searchResult->setRowCount(0);
		ui.debuglable->setText("Search result : no music");
	}
}

void MusicApplicationByQt::SearchByArtist(QString artist)
{
	string sname = artist.toStdString();
	ItemType item;
	m_List.ResetList();
	int row = 0;
	bool found = false;
	while (m_List.GetNextItem(item) != -1) {
		if (item.GetMusician().find(sname) != string::npos) {
			row++;
			ui.searchResult->setRowCount(row);
			AddItemToTable(ui.searchResult, row - 1, item);
			found = true;
		}
	}
	if (!found) {
		ui.searchResult->setRowCount(0);
		ui.debuglable->setText("Search result : no music");
	}
}

void MusicApplicationByQt::AddItemToTable(QTableWidget* table, int row, ItemType item)
{
	table->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(item.GetId())));
	table->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(item.GetName())));
	table->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(item.GetMusician())));
	table->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(item.GetComposer())));
	table->setItem(row, 4, new QTableWidgetItem(QString::fromStdString(item.GetGenre())));
	table->setItem(row, 5, new QTableWidgetItem(QString::fromStdString(std::to_string(item.GetNumPlay()))));
}

void MusicApplicationByQt::UpdateCurMusicList()
{
	for (int i = 0; i < m_List.GetLength(); i++) {
		ui.MusicList->setRowCount(i+1);
		AddItemToTable(ui.MusicList, i, m_List.at(i));
	}
}


void MusicApplicationByQt::AddSoogToRankList(ItemType item) // ������ ����ִ� item
{
	//string name = ui.QMasterPlayList->item(0)->text().toStdString();
	PlayerType player(RANKLISTNAME);
	MasterPlayList.Get(player);
	ArrayList<PlayItem> rankedPlayer;
	rankedPlayer = player.GetPlayList();
	PlayItem pi;
	pi.SetId(item.GetId());
	int tmpNumplay = item.GetNumPlay();
	pi.setNumplay(tmpNumplay);
	

	if (rankedPlayer.IsEmpty()) { // ������� ���.
		rankedPlayer.Add(pi);
	}
	else { 
		int end = rankedPlayer.GetLength()-1;
		while (rankedPlayer.at(end).GetNumPlay() < tmpNumplay) {
			end--;
			if (end < 0) break;
		}
		rankedPlayer.Insert(pi, end + 1);

	}
	player.SetPlaylist(rankedPlayer);
	MasterPlayList.Replace(player);
}

void MusicApplicationByQt::UpdateRankList(ItemType item)
{
	PlayItem pi;
	pi.SetId(item.GetId());
	pi.setNumplay(item.GetNumPlay());
	PlayerType player(RANKLISTNAME);
	MasterPlayList.Get(player);
	player.ReplaceSong(pi);
	int index = player.GetCurIndex(); // �÷��� ����Ʈ�� ���� �ε����� replace���Ķ� �ش� id�� �־��� index�� ����Ű�� ����.


	
	if(index > 0) {
		PlayItem preitem;
		player.GetSongIdByIndex(index - 1, preitem); 

		while (pi.GetNumPlay() > preitem.GetNumPlay()) {
			player.SwapSong(index - 1, index);
			index--;
			if (index <= 0) break;
			player.GetSongIdByIndex(index - 1, preitem); // ������Ʈ �Ϸ��� ���� �ٷ� �� ��� ���Ͽ� ���Ƚ���� �� ������ swap.
		}
	}
	MasterPlayList.Replace(player);
	ShowInPlayList();
}


void MusicApplicationByQt::OpenTextFile()
{
	QString path = getFilePath("R");
	QFile infile(path);

	if (!infile.open(QIODevice::ReadOnly | QIODevice::Text)){
		ui.debuglable->setText("not open"+'\n'+ path);

	}
	else {
		ui.debuglable->setText("open");

		QString content;
		QStringList allSong;
		QStringList oneSong;
		
		//content = QString::fromLocal8Bit(infile.readAll());
		content = QString::fromUtf8(infile.readAll());
		allSong = content.split(";;;\n");
		
		for (int i = 0; i < allSong.size(); i++) {
			oneSong = allSong[i].split("#");
			if(oneSong.size() >= 7)
			AddMusic(oneSong);
		}
		//ui.plainTextEdit->setPlainText(oneSong[6]);
	//	ui.debuglable->setText(oneSong[6]);
	}
	infile.close();

}

void MusicApplicationByQt::WriteTextFile()
{
	QString path = getFilePath("W");
	QFile file(path);
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
		ui.debuglable->setText("not open" + '\n' + path);
	}
	else {
		QString content;
		ItemType item;
		string songdata;
		m_List.ResetList();
		while (m_List.GetNextItem(item) != -1) {
			songdata = item.GetId() + "#" + item.GetName() + "#" + item.GetMusician() + "#"+ item.GetComposer()+ "#" + item.GetGenre() + "#" + std::to_string(item.GetNumPlay()) + "#" + item.GetLyric();
			content += QString::fromStdString(songdata) + ";;;\n";
		}


		//file.write(content.toLocal8Bit());
		file.write(content.toUtf8());
		
	}

	file.close();
}

void MusicApplicationByQt::NextPlay()
{
	if (isNone) return; // ���� �ƹ��͵� ��������� �ʴٸ�
	if (isRandom) {
		RandomPlay();
		return;
	}
	bool isend = false;
	string nextid;
	ItemType item;

	if (isLoop == curLoop) {
		item.SetId(curMusicId);
		m_List.RetrieveByBS(item);
	}
	else {
		if (curPlayerName == "MasterList") {
			ui.debuglable->setText("main");

			if (curPlayIndex >= m_List.GetLength() -1) {
				if (isLoop == noLoop) return;
				curPlayIndex = 0;
			}
			else curPlayIndex++;
			item = m_List.at(curPlayIndex);

		}
		else {

			PlayerType curPlayer(curPlayerName);
			MasterPlayList.Get(curPlayer);
			nextid = curPlayer.GetNextSongId(curMusicId, isend);
			if (isend && isLoop == noLoop) return;// ���ε� ���� ����� �ƴ϶��, ����
			item.SetId(nextid);
			m_List.RetrieveByBS(item);

		}

	}
	Play(item);
}

void MusicApplicationByQt::PrePlay()
{
	if (isNone) return; // ���� �ƹ��͵� ��������� �ʴٸ�

	ItemType item;
	bool isfirst = false;
	if (isLoop == curLoop) {
		item.SetId(curMusicId);
		m_List.RetrieveByBS(item);
	}
	if (isRandom) {
		RandomPlay();
		return;
	}
	else {
		if (curPlayerName == "MasterList") {
			ui.debuglable->setText("main");
			if (curPlayIndex == 0) {
				if (isLoop == noLoop) return;
				curPlayIndex = m_List.GetLength() - 1;
			}
			else {
				curPlayIndex--;
			}
			item = m_List.at(curPlayIndex);

		}
		else {
			string preid;
			PlayerType curPlayer(curPlayerName);
			MasterPlayList.Get(curPlayer);
			preid = curPlayer.GetPreSongId(curMusicId, isfirst);
			if (isfirst && isLoop == noLoop) return; // ���ε� ���� ����� �ƴ϶��, ����

			item.SetId(preid);
			m_List.RetrieveByBS(item);
		}
	}
	Play(item);
}

void MusicApplicationByQt::SetIsRandom()
{

	ui.debuglable->setText("Random");
	isRandom = ui.isRandomCheck->isChecked();
}

void MusicApplicationByQt::SetLoop()
{
	if (ui.curLoop->isChecked()) {
		isLoop = curLoop;
		ui.debuglable->setText("curLoop");
	}
	else if (ui.NoLoop->isChecked()) {
		isLoop = noLoop;
		ui.debuglable->setText("noLoop");
	}
	else {
		isLoop = totalLoop;
		ui.debuglable->setText("totalLoop");
	}
}

void MusicApplicationByQt::SearchMusic()
{
	ui.debuglable->setText("Search...");
	int c = ui.searchRange->currentIndex();
	QString content = ui.searchBox->text();
	if (content.isEmpty()) {
		ui.searchResult->setRowCount(0);
		return;
	}

	switch (c)
	{
	case(0):
		Search(content);
		break;
	case(1):
		SearchById(content);
		break;
	case(2):
		SearchByTitle(content);
		break;
	case(3):
		SearchByArtist(content);
		break;
	case(4):
		SearchByGenre(content);
		break;

	default:
		break;
	}
}



void MusicApplicationByQt::getMusicInfo() {
	inputWindow = new QtInputWindow(this);
	inputWindow->show();
}


