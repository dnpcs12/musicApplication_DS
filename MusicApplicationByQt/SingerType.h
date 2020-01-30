#pragma once
#ifndef SingerType_h
#define SingerType_h

#include <string>
#include "ArrayList.h"
using namespace std;


struct SoogType {  // songlist 에 들어갈 songType.
	string id; // 곡의 id
	string soogName; //  곡의 이름
};


class SingerType {

public:
	SingerType(); // 생성자
	void SetName(string _name);  // 가수의 이름(string) 을 파라메터로 받아 저장.
	void SetAge(int _age); // 가수의 나이(int)를 파라메터로 받아 저장.
	void SetIsMale(bool bmale); // 가수의 성별(bool (남자이면 true 아니면 false)을 파라메터로 받아 저장.
	void SetNameByFB(); // 가수의 이름(string)을 키보드로 받아 저장. 
	void SetSingerByFB(); // 가수 정보를 키보드로 받는다.

	string GetName() const; // 가수의 이름(string)을 return 
	int GetAge() const;  // 가수의 나이(int) 를 return
	bool GetIsMale() const; // 가수의 성별(bool)을 return
	void AddSoog(SoogType soog); // sooglist에 새로운 노래를 추가한다. 
	void DisplayAll(); // sooglist에 있는 노래들의 간단한 정보(id와 이름)을 모두 출력
	int GetNextSoogID(string &_id); // sooglist의 curpointer를 하나 증가시키고(curpointer가 마지막 인덱스였다면 -1리턴), 그 인덱스의 soog id를 가지고 옴. 
	void ResetSoogList(); // sooglist의 curpointer를 초기화
	bool operator==(SingerType other);  // 비교연산자 == , 이름을 기준으로 비교하여 같으면 true, 다르면 false 리턴.
	bool operator<(SingerType other); // 비교연산자 <
	bool operator>(SingerType other); // 비교연산자 > 


private:
	string name; // 가수의 이름
	int age; // 가수의 나이
	bool isMale; // 가수의 성별
	ArrayList<SoogType> soogList; // 가수가 부른 노래들을 저장할 songlist  

};


#endif // !SingerType_h

