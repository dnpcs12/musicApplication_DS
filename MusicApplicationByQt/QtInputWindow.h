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
	���� ���� ���� â���� �����Ű�� �Լ�. 
	�Ķ���� : item. ���� ���� �ִ� ���� ����
	post: inputâ�� ������ item�� ���� �ִ� ������ �ٲ��ش�. (�帣�� �� �� ���� �帣�� �����)
	*/
	void SetChangedMode(ItemType& item);
	

private:
	Ui::QtInputWindow ui;

public slots:
	void newMusicCreate();
	void ChangeMusicInfo();
	void lyricfileOpen();
};

