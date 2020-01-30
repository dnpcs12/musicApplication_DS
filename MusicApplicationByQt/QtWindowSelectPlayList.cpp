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
		if (nameList.at(i) == QString::fromLocal8Bit("���� ���� ����� ��")) continue;
		ui.comboBox->addItem(nameList.at(i));
	}
}
void QtWindowSelectPlayList::AddNewPL(QString name) // ���� ����â�� ���ο� playlist �߰�
{
	ui.comboBox->addItem(name);
}

void QtWindowSelectPlayList::MakeNewPL() // + ��ư�� �������� ����. ���ο� playlist�� �߰��ϴ� â�� ����
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
