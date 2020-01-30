#include "QtWindowSelectPlayList.h"
#include "MusicApplicationByQt.h"


QtWindowSelectPlayList::QtWindowSelectPlayList(QWidget *parent)
	: QWidget(parent)
{
	setWindowFlags(Qt::Window);
	ui.setupUi(this);
	isAll = false;
}

QtWindowSelectPlayList::~QtWindowSelectPlayList()
{
}

void QtWindowSelectPlayList::SetSelectWindow(QStringList nameList, bool _isAll)
{
	isAll = _isAll;
	for (int i = 0; i < nameList.size(); i++) {
		if (nameList.at(i) == QString::fromLocal8Bit("가장 많이 재생한 곡")) continue;
		ui.comboBox->addItem(nameList.at(i));
	}
}
void QtWindowSelectPlayList::AddNewPL(QString name) // 현재 선택창에 새로운 playlist 추가
{
	ui.comboBox->addItem(name);
}

void QtWindowSelectPlayList::MakeNewPL() // + 버튼을 눌렀을때 실행. 새로운 playlist를 추가하는 창을 열음
{
	((MusicApplicationByQt*)parent())->openPlaylistAddWindow();
	//ui.comboBox->addItem
}
void QtWindowSelectPlayList::ReturnPLName() {
	
	if (isAll) {
		((MusicApplicationByQt*)parent())->AddAllMusicToPL(ui.comboBox->currentText());
	}
	else ((MusicApplicationByQt*)parent())->AddMusicToPL(ui.comboBox->currentText());
	this->close();

}
