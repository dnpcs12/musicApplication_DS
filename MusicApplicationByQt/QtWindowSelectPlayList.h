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
	 @ 현재 존재하는 재생목록들을 combobox에 추가함.
	 @ 파라메터- nameList: 재생목록들의 이름이 파라메터로 들어와야함.
	 @ 파라메터- _isAll : 재생목록에 추가하고자 하는 노래가 모든 곡이라면 true. 
	*/
	void SetSelectWindow(QStringList nameList, bool _isAll = false);

	/*
	 @ 현재 선택창에 파라메터 name의 이름을 가진 새로운 playlist 추가
	*/
	void AddNewPL(QString name);
	

private:
	Ui::QtWindowSelectPlayList ui;
	bool isAll;

public slots:
	void ReturnPLName();
	void MakeNewPL();
};
