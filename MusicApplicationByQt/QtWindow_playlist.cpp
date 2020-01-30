#include "QtWindow_playlist.h"
#include "MusicApplicationByQt.h"

QtWindow_playlist::QtWindow_playlist(QWidget *parent)
	: QWidget(parent)
{
	setWindowFlags(Qt::Window);
	ui.setupUi(this);
}

QtWindow_playlist::~QtWindow_playlist()
{
}

void QtWindow_playlist::PlayListNameReturn() {
	QString playlist_name = ui.lineEdit->text();
	
	((MusicApplicationByQt*)parent())->AddPlayList(playlist_name);
	this->close();
}

