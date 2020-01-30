#pragma once
#define PlayerType_H
#include "PlayItem.h"
#include "ArrayList.h"
#include "SortedList.h"
#include "ItemType.h"

class PlayerType {
public :
	PlayerType() {
		name = "defalut";
	//	curInTime = 0;
	}
	PlayerType(string _name) {
		name = _name;
		//curInTime = 0;
	}
	int AddSong(PlayItem item); // ���� Play list�� �߰�
	int DeleteSong(PlayItem item);	//���� play list���� ����
	int ReplaceSong(PlayItem item); // �ش� ���� playlist���� ����.



	string GetNextSongId(string curid, bool& isend);
	string GetPreSongId(string curid, bool& isfirst);


	/*
	@ playlist�� m_curpointer�� ������.
	*/
	int GetCurIndex();

	/*
	@ �ε����� �̿��� playitem�� ���´�.
	@ pre : index�� [0 ~ playlist ����) ���� ���� �Ѵ�. 
	@ �߸��� �ε��� (0���� �۰ų� playlist�� ���̺��� ū �ε���) ��� 0 ����.
	*/
	int GetSongIdByIndex(int index, PlayItem& item);

	/*
	 @ �ش� id�� ���� ���� �ε����� ����.
	 @ ���� �������� ������ -1 ����
	*/
	int GetSongIndex(string id);

	/*
	 @ playlist �ȿ��� �� ���� swap.
	*/
	void SwapSong(int index1, int index2);

	int GetPlaylistSize(); // playlist�� ����� �� �� ����. 
	string GetPLName();
	ArrayList<PlayItem> GetPlayList();

	void SetName(string _name);
	void SetNameFrKb();
	void SetPlaylist(ArrayList<PlayItem> pl);

	bool operator==(PlayerType other);
	bool operator<(PlayerType other);
	bool operator>(PlayerType other);

private:
	ArrayList<PlayItem> playlist;
	string name; // playlist �� �̸�
	//int curInTime; // playlist�� �������� �� ������ ++. (delete�ص� ���ҽ�Ű�� ����) �� ������ �ľ��ϱ� ���� ����.
};