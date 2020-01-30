#ifndef ItemType_h
#define ItemType_h

#include <iostream>
#include <string>
#include <fstream>
#include <qstring.h>

using namespace std;

enum RelationType { LESS, GREATER, EQUAL };
class ItemType
{
public:
	ItemType();							// default constructor
	~ItemType() {}						// default destructor

	string GetId() const;							// 곡 고유번호 ID 반환 함수
	string GetName();						// 곡 이름 반환 함수
	string GetComposer();		// 작곡가 반환 함수
	string GetMusician(); // 연주자 반환함수
	int GetGenreNum(); // 장르 반환 함수
	string GetGenre();
	string GetLyric(); //가사 반환 함수 

	/*
	현재 곡의 플레이 횟수를 리턴. 
	return numPlay
	*/
	int GetNumPlay(); 

	void SetId(string inId);						// 곡 고유번호 ID 저장 함수
	void SetName(string inName);					// 곡 이름 저장 함수
	void SetComposer(string inComposer); //작곡가 저장 함수
	void SetMusician(string inMusician); // 연주자 저장함수
	void SetGenre(string inGenre); // 장르 저장 함수
	void SetLyric(string inLyric); //가사 저장 합수 
	void SetPlayNum(int num); // 재생횟수 저장 함수 
	void SetRecord(string inId, string inName, string inComposer, string inMusician, string inGenre); 	// 음악 정보 저장 함수
	/*
	플레이 횟수를 1 증가시킨다. 
	post : numPlay ++;
	*/
	void upNumPlay(); 
	
	void DisplayIdOnScreen();					// 곡 고유번호 출력 함수
	void DisplayNameOnScreen();					// 곡 명 출력 함수
	void DisplayComposerOnScreen();				// 작곡자 출력 함수
	void DisplayMusicianOnScreen();  // 연주자 출력 함수
	void DisplayGenreOnScreen(); // 장르 출력 함수
	void DisplayRecordOnScreen();		// 곡 정보 출력 함수

	void SetIdFromKB();				// 키보드로 곡 고유번호(ID) 입력 함수
	void SetNameFromKB();			// 키보드로 학생 이름 입력 함수
	void SetComposerFromKB();			// 키보드로 작곡자 입력 함수
	void SetMusicianFromKB(); // 키보드로 연주자 입력 함수
	void SetGenreFromKB(); // 키보드로 장르 입력 함수
	void SetRecordFromKB();			// 키보드로 학생 정보 입력 함수

	int ReadDataFromFile(ifstream& fin);		//음악 정보를 파일에서 읽는 함수
	int WriteDataToFile(ofstream& fout);		//음악 정보를 파일로 출력하는 함수
	bool operator==(ItemType data);// 연산자 == , ID가 같다면 true 리턴, 다르면 false 리턴
	bool operator>(ItemType data);// 비교연산자 >  , m_Id > data.GetId() 이면 true,  아니면 false
	bool operator<(ItemType data);//비교연산자 < ,  m_Id < data.GetId() 이면 true,  아니면 false 

	friend ostream& operator<<(ostream& os, const ItemType& item);

	void guideGenre();

	//ItemType& operator=(ItemType data);

private:

	string genreList[10] = { "Unknown" ,"Dance","Ballad","Idol","Pop","Indie","Rap/Hiphop","Rock","R&B","Classic" };
	string composer; // 작곡자
	string m_Id;					// 학생 ID
	string m_sName;				// 학생 이름 저장 변수
	string m_Musician; // 연주자 
	string m_Genre;
	string m_lyric; // 가사 
	int numPlay; // 플레이 횟수; 
};
#endif// !ItemType.h
