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
	int AddSong(PlayItem item); // 곡을 Play list에 추가
	int DeleteSong(PlayItem item);	//곡을 play list에서 삭제
	int ReplaceSong(PlayItem item); // 해당 곡을 playlist에서 변경.



	string GetNextSongId(string curid, bool& isend);
	string GetPreSongId(string curid, bool& isfirst);


	/*
	@ playlist의 m_curpointer를 가져옴.
	*/
	int GetCurIndex();

	/*
	@ 인덱스를 이용해 playitem을 얻어온다.
	@ pre : index가 [0 ~ playlist 길이) 범위 여야 한다. 
	@ 잘못된 인덱스 (0보다 작거나 playlist의 길이보다 큰 인덱스) 라면 0 리턴.
	*/
	int GetSongIdByIndex(int index, PlayItem& item);

	/*
	 @ 해당 id를 가진 곡의 인덱스를 리턴.
	 @ 곡이 존재하지 않으면 -1 리턴
	*/
	int GetSongIndex(string id);

	/*
	 @ playlist 안에서 두 곡을 swap.
	*/
	void SwapSong(int index1, int index2);

	int GetPlaylistSize(); // playlist에 저장된 곡 수 리턴. 
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
	string name; // playlist 의 이름
	//int curInTime; // playlist에 아이템이 들어갈 때마다 ++. (delete해도 감소시키지 않음) 들어간 순서를 파악하기 위한 변수.
};