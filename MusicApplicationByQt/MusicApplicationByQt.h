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
	@ ������ �аų� ���� ���� â�� ����. 
	@�Ķ���� mode : R : �б� , W :���� 
	@ retrun : QString ������ ���ϰ�� 
	*/
	QString getFilePath(string mode);


	void ReplaceItem(QStringList tmp);

	/*
	�Ķ���ͷ� �־��� item�� play.
	pre : �ش� �������� m_list�� �����ؾ���.
	post: item�� ����(����, ����, ����)�� ���� ��� ���� �� â�� ǥ�� ��.
	      item�� ��� Ƚ���� ������.
	*/
	void Play(ItemType item);
	void RandomPlay();
	int GetRandomIndex(int range);


	//----�˻�------//
	void Search(QString content); // ���հ˻�
	void SearchById(QString id); // ������ȣ�� �˻�
	void SearchByTitle(QString title); // �������� �˻�
	void SearchByGenre(QString genre); // �帣�� �˻�
	void SearchByArtist(QString artist); // ������ �˻� 

	/*
	@ table ������ ������ ������ �߰��մϴ�. 
	@ �Ķ���� - table: ������ ������ �߰��� ���̺��� ������
	            - row :������ ������ �߰��ϰ��� �ϴ� ���� �ε���
				- item : �߰��ϰ��� �ϴ� ������
	@ pre : �Ķ���Ͱ� ��� �־�������. 
	@ post : table�� �ش� ������ ������ ǥ���ϴ� ���� ����.
	*/
	void AddItemToTable(QTableWidget* table, int row, ItemType item);

	/*
	 @ m_List �� ������ �����ϵ��� musicTable�� ������Ʈ �� ��.
	*/
	void UpdateCurMusicList(); 

	/*
	  @ ���� ���� ����� �� �÷��� ����Ʈ�� ���� �߰���.
	  @ �Ķ���� item : �߰��� �� ������ ��� �ִ� item.
	  @ pre: ���� ���� ����� �� �÷��� ����Ʈ�� �����ؾ���.
	  @ post: �ش� �������� ���� ���� ����� �� �÷��� ����Ʈ�� �˸��� ��ġ�� ����.
	*/
	void AddSoogToRankList(ItemType item);

	/*
	 @ �Ķ���ͷ� ���� �������� ���� ���� ����� �� ����Ʈ �� ������ ������Ʈ ���ִ� �Լ�.
	 @ pre: �ش� item�� ���� ���� ����� �� ����Ʈ �ȿ� �����ؾ���.
	 @ post: ���� ������ �ִٸ� ������Ʈ ��. 
	*/
	void UpdateRankList(ItemType item);
	
	


private:
	Ui::MusicApplicationByQtClass ui;

	//���� ���� ����� �� ����Ʈ�� �̸� ����
	const string RANKLISTNAME = QString::fromLocal8Bit("���� ���� ����� ��").toStdString();
	const QString QRANKLISTNAME = QString::fromLocal8Bit("���� ���� ����� ��");

	//����(�� �� �Է��� �޾ƿ���)â
	QtInputWindow* inputWindow;
	QtWindow_playlist* playlistInput;
	QtWindowSelectPlayList* playlistSelectWindow;
	
	//�˾� �޴�
	QMenu* ContextMenu;
	QMenu* PlaylistMenu;

	// ������ �߰��� �� ¡�˴ٸ� ����
	PlayItem tmpPlayItem;

	SortedList<ItemType> m_List;///< item list.
	DoublySortedLinkedList<PlayerType> MasterPlayList; // play list  

	string curPlayerName; // ���� ������� �÷��̸���Ʈ �̸�. 
	string curMusicId; // ���� ������� ���� ������ȣ
	int curPlayIndex;
	bool isNone; // ���� ������ΰ� �ƹ��͵� ������ Ȯ��
	LoopState isLoop; //�ݺ� ���°� ��� ��Ÿ��.
	bool isRandom; // ���� ��� ������. 




public slots:
	/*
	�� ���� ������ ��� â�� ����.
	*/
	void getMusicInfo();
	/*
	�� �÷��̸���Ʈ�� �߰��ϴ� â�� ����
	*/
	void openPlaylistAddWindow();
	/*
	���ο� ������ �߰���.
	�Ķ����: QStringList tmp. ���ο� ���ǿ� ���� ������ ��� ����. 
	post : ���ο� ������ m_list�� �߰��ǰ� MusicLIst�� ���̰� ��.(������ȣ�� ������ �߰����� ����) 
	*/
	void AddMusic(QStringList tmp);
	/*
	���� ���õ� ��(row)�� ������ ������.
	post: ������ m_list���� �����ǰ�, MusicList������ ������ �ʰԵȴ�.
	*/
	//-----�뷡 ��-----//
	void DeleteMusic();
	void MusicPlay();
	void MakeEmpty();
	void ChangeMusic();

	//---- ��� ��� ���� ���-------//
	void AddPlayList(QString name);
	void AddMusicToPL(QString name);
	void AddAllMusicToPL(QString name);
	void DeletePlayList();
	void ShowInPlayList();
	void DeleteSongInPL();
	void MusicPlayInPL();

	//----- ��Ŭ���� �˾� �޴� ---------//
	void ContextMenuShow(const QPoint& pos);
	void PLContextMenuShow(const QPoint& pos);
	
	//------- ���� �����--------//
	void OpenTextFile();
	void WriteTextFile();
	
	//------���� ��� ���� �� ���� ���-------//
	void NextPlay();
	void PrePlay();
	void SetIsRandom();
	void SetLoop();

	//--- �˻�----//
	void SearchMusic(); // �˻� ��ư ������ �� ����.


	//--- �Է� â ���� ---///
	void OpenPLSelectWindow_All();
	void openPLSelectWindow();
};
