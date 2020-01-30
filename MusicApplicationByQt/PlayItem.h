#pragma once
#ifndef PlayItem_h
#define PlayItem_h
#include <iostream>
#include <string>

using namespace std;
class PlayItem {
public:

	/**
	*	@brief	playitem class�� ����� ������
	*	@post	��������� �ʱ�ȭ. 
	*/
	PlayItem();

	/**
	*	@brief	playitem class�� ����� ������. string inid�� �Ķ���ͷ� �޾Ƽ� id ���� �־���
	*   @pre    string inid�� �־����� ��
	*	@post	id = inid , ������ ��������� �ʱ�ȭ.
	*/
	PlayItem(string inid);


	/**
	*	@brief  �ش� playitem�� id�� ����.
	*   @return Id
	*/
	string GetId() const;

	/**
	*	@brief  �ش� playitem�� ������� numPlay�� ����.
	*   @return numPlay
	*/
	int GetNumPlay();

	/**
	*	@brief  �ش� playitem�� ������� inTime�� ����.
	*   @return inTime
	*/
	int GetInTime();

	/**
	*	@brief  �ش� playitem�� ������� Id �� �Ķ���� ������ �־���,
	*   @pre    �Ķ���ͷ� string inid�� �־�������. 
	*   @post   Id = inid
	*/
	void SetId(string inid);


	void SetIdFromKB();


	/**
	*	@brief  �ش� playitem�� ������� intime �� �Ķ���� ������ �־���,
	*   @pre    �Ķ���ͷ� int time �� �־�������.
	*   @post   intime = time
	*/
	void SetInTime(int time);

	/**
	*	@brief  �ش� playitem�� ������� numPlay �� count��ŭ ����. ���� �־����� ������ default������ 1�� ������. 
	*   @post   numPlay += count.
	*/
	void Up_numPlay(int count = 1);
	void setNumplay(int count);

	bool operator==(PlayItem data);// ������ == , ID�� ���ٸ� true ����, �ٸ��� false ����
	bool operator>(PlayItem data);// �񱳿����� >  , m_Id > data.GetId() �̸� true,  �ƴϸ� false
	bool operator<(PlayItem data);//�񱳿����� < ,  m_Id < data.GetId() �̸� true,  �ƴϸ� false 

	friend ostream& operator<<(ostream& os, const PlayItem& item);
	
private:
	string Id;  // ���� primary key
	int numPlay;  // ���� play�� Ƚ��
	int inTime;  //���� play list�� ���Ե� �ð�(�� ���������� ���� ������ ���) 
};

#endif // !PlayItem_h
