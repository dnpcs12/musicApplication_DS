#pragma once
#ifndef PlayItem_h
#define PlayItem_h
#include <iostream>
#include <string>

using namespace std;
class PlayItem {
public:

	/**
	*	@brief	playitem class를 만드는 생성자
	*	@post	멤버변수를 초기화. 
	*/
	PlayItem();

	/**
	*	@brief	playitem class를 만드는 생성자. string inid를 파라메터로 받아서 id 값에 넣어줌
	*   @pre    string inid가 주어저야 함
	*	@post	id = inid , 나머지 멤버변수를 초기화.
	*/
	PlayItem(string inid);


	/**
	*	@brief  해당 playitem의 id를 리턴.
	*   @return Id
	*/
	string GetId() const;

	/**
	*	@brief  해당 playitem의 멤버변수 numPlay를 리턴.
	*   @return numPlay
	*/
	int GetNumPlay();

	/**
	*	@brief  해당 playitem의 멤버변수 inTime를 리턴.
	*   @return inTime
	*/
	int GetInTime();

	/**
	*	@brief  해당 playitem의 멤버변수 Id 를 파라메터 값으로 넣어줌,
	*   @pre    파라메터로 string inid가 주어저야함. 
	*   @post   Id = inid
	*/
	void SetId(string inid);


	void SetIdFromKB();


	/**
	*	@brief  해당 playitem의 멤버변수 intime 를 파라메터 값으로 넣어줌,
	*   @pre    파라메터로 int time 이 주어저야함.
	*   @post   intime = time
	*/
	void SetInTime(int time);

	/**
	*	@brief  해당 playitem의 멤버변수 numPlay 를 count만큼 증가. 값을 넣어주지 않으면 default값으로 1이 증가됨. 
	*   @post   numPlay += count.
	*/
	void Up_numPlay(int count = 1);
	void setNumplay(int count);

	bool operator==(PlayItem data);// 연산자 == , ID가 같다면 true 리턴, 다르면 false 리턴
	bool operator>(PlayItem data);// 비교연산자 >  , m_Id > data.GetId() 이면 true,  아니면 false
	bool operator<(PlayItem data);//비교연산자 < ,  m_Id < data.GetId() 이면 true,  아니면 false 

	friend ostream& operator<<(ostream& os, const PlayItem& item);
	
private:
	string Id;  // 곡의 primary key
	int numPlay;  // 곡이 play된 횟수
	int inTime;  //곡이 play list에 삽입된 시간(이 과제에서는 들어온 순서를 사용) 
};

#endif // !PlayItem_h
