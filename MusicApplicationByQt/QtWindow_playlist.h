#pragma once

#include <QWidget>

#include "ui_QtWindow_playlist.h"

class QtWindow_playlist : public QWidget
{
	Q_OBJECT

public:
	QtWindow_playlist(QWidget *parent = Q_NULLPTR);
	~QtWindow_playlist();
	

private:
	Ui::QtWindow_playlist ui;

public slots:
	void PlayListNameReturn();

};
