#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MusicApplicationByQt.h"

#include "QtInputWindow.h"
#include "QtWindow_playlist.h"
#include "QtWindowSelectPlayList.h"

#include<qstring.h>
#include <iostream>
#include <string>
#include <fstream>
#include <QFileDialog>
#include <cstdlib>
#include <ctime>

#include "ItemType.h"
#include "SortedList.h"
#include "PlayItem.h"
#include "SortedLinkedList.h"
#include "DoublySortedLinkedList.h"
#include "DoublyIterator.h"
#include "PlayerType.h"


enum LoopState { noLoop, totalLoop, curLoop };

class MusicApplicationByQt : public QMainWindow
{
	Q_OBJECT

public:
	MusicApplicationByQt(QWidget* parent = Q_NULLPTR);
	/*
	@ 파일을 읽거나 쓰기 위해 창을 연다. 
	@파라메터 mode : R : 읽기 , W :쓰기 
	@ retrun : QString 형식의 파일경로 
	*/
	QString getFilePath(string mode);


	void ReplaceItem(QStringList tmp);

	/*
	파라메터로 주어진 item을 play.
	pre : 해당 아이템이 m_list에 존재해야함.
	post: item의 정보(제목, 가수, 가사)가 현재 재생 중인 곡 창에 표시 됨.
	      item의 재생 횟수가 증가함.
	*/
	void Play(ItemType item);
	void RandomPlay();
	int GetRandomIndex(int range);


	//----검색------//
	void Search(QString content); // 통합검색
	void SearchById(QString id); // 고유번호로 검색
	void SearchByTitle(QString title); // 제목으로 검색
	void SearchByGenre(QString genre); // 장르로 검색
	void SearchByArtist(QString artist); // 가수로 검색 

	/*
	@ table 위젯에 아이템 정보를 추가합니다. 
	@ 파라메터 - table: 아이템 정보를 추가할 테이블의 포인터
	            - row :아이템 정보를 추가하고자 하는 줄의 인덱스
				- item : 추가하고자 하는 아이템
	@ pre : 파라메터가 모두 주어져야함. 
	@ post : table에 해당 아이템 정보를 표시하는 줄이 생김.
	*/
	void AddItemToTable(QTableWidget* table, int row, ItemType item);

	/*
	 @ m_List 의 정보와 동일하도록 musicTable을 업데이트 해 줌.
	*/
	void UpdateCurMusicList(); 

	/*
	  @ 가장 많이 재생한 곡 플레이 리스트에 곡을 추가함.
	  @ 파라메터 item : 추가할 곡 정보를 담고 있는 item.
	  @ pre: 가장 많이 재생한 곡 플레이 리스트가 존재해야함.
	  @ post: 해당 아이템을 가장 많이 재생한 곡 플레이 리스트에 알맞은 위치에 넣음.
	*/
	void AddSoogToRankList(ItemType item);

	/*
	 @ 파라메터로 넣은 아이템의 가장 많이 재생한 곡 리스트 안 순위를 업데이트 해주는 함수.
	 @ pre: 해당 item이 가장 많이 재생한 곡 리스트 안에 존재해야함.
	 @ post: 순위 변동이 있다면 업데이트 됨. 
	*/
	void UpdateRankList(ItemType item);
	
	


private:
	Ui::MusicApplicationByQtClass ui;

	//가장 많이 재생한 곡 리스트의 이름 정의
	const string RANKLISTNAME = QString::fromLocal8Bit("가장 많이 재생한 곡").toStdString();
	const QString QRANKLISTNAME = QString::fromLocal8Bit("가장 많이 재생한 곡");

	//보조(각 종 입력을 받아오는)창
	QtInputWindow* inputWindow;
	QtWindow_playlist* playlistInput;
	QtWindowSelectPlayList* playlistSelectWindow;
	
	//팝업 메뉴
	QMenu* ContextMenu;
	QMenu* PlaylistMenu;

	// 재생목록 추가할 때 징검다리 변수
	PlayItem tmpPlayItem;

	SortedList<ItemType> m_List;///< item list.
	DoublySortedLinkedList<PlayerType> MasterPlayList; // play list  

	string curPlayerName; // 현재 재생중인 플레이리스트 이름. 
	string curMusicId; // 현재 재생중인 곡의 고유번호
	int curPlayIndex;
	bool isNone; // 현재 재생중인게 아무것도 없는지 확인
	LoopState isLoop; //반복 상태가 어떤지 나타냄.
	bool isRandom; // 랜덤 재생 중인지. 




public slots:
	/*
	새 음악 정보를 얻는 창을 열음.
	*/
	void getMusicInfo();
	/*
	새 플레이리스트를 추가하는 창을 열음
	*/
	void openPlaylistAddWindow();
	/*
	새로운 음악을 추가함.
	파라메터: QStringList tmp. 새로운 음악에 대한 정보를 담고 있음. 
	post : 새로운 음악이 m_list에 추가되고 MusicLIst에 보이게 됨.(고유번호가 같을시 추가되지 않음) 
	*/
	void AddMusic(QStringList tmp);
	/*
	현재 선택된 줄(row)의 음악을 삭제함.
	post: 음악이 m_list에서 삭제되고, MusicList에서도 보이지 않게된다.
	*/
	//-----노래 탭-----//
	void DeleteMusic();
	void MusicPlay();
	void MakeEmpty();
	void ChangeMusic();

	//---- 재생 목록 관련 기능-------//
	void AddPlayList(QString name);
	void AddMusicToPL(QString name);
	void AddAllMusicToPL(QString name);
	void DeletePlayList();
	void ShowInPlayList();
	void DeleteSongInPL();
	void MusicPlayInPL();

	//----- 우클릭시 팝업 메뉴 ---------//
	void ContextMenuShow(const QPoint& pos);
	void PLContextMenuShow(const QPoint& pos);
	
	//------- 파일 입출력--------//
	void OpenTextFile();
	void WriteTextFile();
	
	//------현재 재생 중인 곡 관련 기능-------//
	void NextPlay();
	void PrePlay();
	void SetIsRandom();
	void SetLoop();

	//--- 검색----//
	void SearchMusic(); // 검색 버튼 눌렀을 때 실행.


	//--- 입력 창 열기 ---///
	void OpenPLSelectWindow_All();
	void openPLSelectWindow();
};
