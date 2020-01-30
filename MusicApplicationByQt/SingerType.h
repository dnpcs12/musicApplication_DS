#pragma once
#ifndef SingerType_h
#define SingerType_h

#include <string>
#include "ArrayList.h"
using namespace std;


struct SoogType {  // songlist �� �� songType.
	string id; // ���� id
	string soogName; //  ���� �̸�
};


class SingerType {

public:
	SingerType(); // ������
	void SetName(string _name);  // ������ �̸�(string) �� �Ķ���ͷ� �޾� ����.
	void SetAge(int _age); // ������ ����(int)�� �Ķ���ͷ� �޾� ����.
	void SetIsMale(bool bmale); // ������ ����(bool (�����̸� true �ƴϸ� false)�� �Ķ���ͷ� �޾� ����.
	void SetNameByFB(); // ������ �̸�(string)�� Ű����� �޾� ����. 
	void SetSingerByFB(); // ���� ������ Ű����� �޴´�.

	string GetName() const; // ������ �̸�(string)�� return 
	int GetAge() const;  // ������ ����(int) �� return
	bool GetIsMale() const; // ������ ����(bool)�� return
	void AddSoog(SoogType soog); // sooglist�� ���ο� �뷡�� �߰��Ѵ�. 
	void DisplayAll(); // sooglist�� �ִ� �뷡���� ������ ����(id�� �̸�)�� ��� ���
	int GetNextSoogID(string &_id); // sooglist�� curpointer�� �ϳ� ������Ű��(curpointer�� ������ �ε������ٸ� -1����), �� �ε����� soog id�� ������ ��. 
	void ResetSoogList(); // sooglist�� curpointer�� �ʱ�ȭ
	bool operator==(SingerType other);  // �񱳿����� == , �̸��� �������� ���Ͽ� ������ true, �ٸ��� false ����.
	bool operator<(SingerType other); // �񱳿����� <
	bool operator>(SingerType other); // �񱳿����� > 


private:
	string name; // ������ �̸�
	int age; // ������ ����
	bool isMale; // ������ ����
	ArrayList<SoogType> soogList; // ������ �θ� �뷡���� ������ songlist  

};


#endif // !SingerType_h

