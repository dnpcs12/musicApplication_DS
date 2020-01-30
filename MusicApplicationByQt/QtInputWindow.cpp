#include "QtInputWindow.h"
#include "MusicApplicationByQt.h"


QtInputWindow::QtInputWindow(QWidget *parent)
	: QWidget(parent)
{
	setWindowFlags(Qt::Window);
	ui.setupUi(this);

}

QtInputWindow::~QtInputWindow()
{
}


void QtInputWindow::SetChangedMode(ItemType& item)
{

	ui.label->setText(QString::fromLocal8Bit("음악 정보 변경"));
	ui.input_id->setText(QString::fromStdString(item.GetId()));
	ui.input_id->setReadOnly(true);
	ui.input_title->setText(QString::fromStdString(item.GetName()));
	ui.input_singer->setText(QString::fromStdString(item.GetMusician()));
	ui.input_composer->setText(QString::fromStdString(item.GetComposer()));
	ui.comboBox->setCurrentIndex(item.GetGenreNum());
	ui.textEdit->setText(QString::fromStdString(item.GetLyric()));
	//ui.AddButton->setText(QString::fromLocal8Bit("변경"));
	ui.AddButton->hide();
	
	//connect(ui.ChangeButton, SIGNAL(clicked(bool)), this, SLOT(ChangeMusicInfo(item))); 
}

void QtInputWindow::ChangeMusicInfo()
{
	//ui.label->setText("changed");
	ItemType item;
	//QString info[5];
	QStringList info;

	info.append(ui.input_id->text());  //0 id
	info.append(ui.input_title->text());  //1 제목
	info.append(ui.input_singer->text()); //2 가수
	info.append(ui.input_composer->text()); //3 작곡가 
	info.append(ui.comboBox->itemText(ui.comboBox->currentIndex())); // 4 장르
	info.append(0); // 5 재생횟수 
	info.append(ui.textEdit->toPlainText()); // 6 가사 

	((MusicApplicationByQt*)parent())->ReplaceItem(info);
	this->close();
}

void QtInputWindow::lyricfileOpen()
{
	QString path;
	path = ((MusicApplicationByQt*)parent())->getFilePath("R");
	QFile infile(path);
	QString lyric;
	if (infile.open(QIODevice::ReadOnly | QIODevice::Text)) {
		//lyric = QString::fromLocal8Bit(infile.readAll());
		lyric = infile.readAll();                          
		ui.textEdit->setText(lyric);       //QString::fromStdString(lyric.toStdString())

	}
	infile.close();
}

void QtInputWindow::newMusicCreate()
{
	ui.label->setText("clicked");
	
	ItemType item;
	//QString info[5];
	QStringList info;
	
	//QtItem = ui.tableWidget->item(0, 0);
	//info = QtItem->text();
//	item.SetId(info.toStdString());
	
	info.append(ui.input_id->text());  //0 id
	info.append(ui.input_title->text());  //1 제목
	info.append(ui.input_singer->text()); //2 가수
	info.append(ui.input_composer->text()); //3 작곡가 
	info.append(ui.comboBox->itemText(ui.comboBox->currentIndex())); // 4 장르
	info.append(0); // 5 재생횟수 
	info.append(ui.textEdit->toPlainText()); // 6 가사 

	this->close();
	((MusicApplicationByQt*)parent())->AddMusic(info); // 메인창의 addMusic호출
	

	
	//this->destroy(false,true);
	
	
}


