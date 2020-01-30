#pragma once

#include <QWidget>
#include "ui_QtWindowSelectPlayList.h"
#include "PlayItem.h"

class QtWindowSelectPlayList : public QWidget
{
	Q_OBJECT

public:
	QtWindowSelectPlayList(QWidget *parent = Q_NULLPTR);
	~QtWindowSelectPlayList();
	
	/*
	 @ ���� �����ϴ� �����ϵ��� combobox�� �߰���.
	 @ �Ķ����- nameList: �����ϵ��� �̸��� �Ķ���ͷ� ���;���.
	 @ �Ķ����- _isAll : �����Ͽ� �߰��ϰ��� �ϴ� �뷡�� ��� ���̶�� true. 
	*/
	void SetSelectWindow(QStringList nameList, bool _isAll = false);

	/*
	 @ ���� ����â�� �Ķ���� name�� �̸��� ���� ���ο� playlist �߰�
	*/
	void AddNewPL(QString name);
	

private:
	Ui::QtWindowSelectPlayList ui;
	bool isAll;

public slots:
	void ReturnPLName();
	void MakeNewPL();
};
