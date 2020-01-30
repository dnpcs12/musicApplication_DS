#pragma once

#include <QWidget>
#include "ui_QtInputWindow.h"
#include <ItemType.h>

class QtInputWindow : public QWidget
{
	Q_OBJECT

public:
	QtInputWindow(QWidget *parent = Q_NULLPTR);
	~QtInputWindow();

	/*
	음악 정보 변경 창으로 변경시키는 함수. 
	파라메터 : item. 원래 갖고 있는 음악 정보
	post: input창의 내용을 item이 갖고 있는 정보로 바꿔준다. (장르는 알 수 없는 장르로 변경됨)
	*/
	void SetChangedMode(ItemType& item);
	

private:
	Ui::QtInputWindow ui;

public slots:
	void newMusicCreate();
	void ChangeMusicInfo();
	void lyricfileOpen();
};

