
#include "ItemType.h"
#include <iomanip>
#include <string.h>

ItemType::ItemType() {
	m_Genre = " "; ////  0.댄스, 1.발라드, 2.아이돌, 3.pop, 4.인디, 5.랩/힙합, 6.락, 7.R&B , 8.클래식, 9~.unknown (그 외)

	composer = ""; // 작곡자
	m_Id = "";					// 곡 고유번호ID
	m_sName = "";				// 곡이름
	m_Musician = ""; // 연주자
	numPlay = 0;

}

string ItemType::GetId() const {
	return m_Id;
}// 음악 고유번호(ID) 반환 함수
string ItemType::GetName() {
	return m_sName;
}// 곡 이름 반환 함수
string ItemType::GetComposer() {
	return composer;
}						// 작곡자 반환 함수
string ItemType::GetMusician() {
	return m_Musician;
} // 연주자 반환함수

int ItemType::GetGenreNum()
{
	for (int i = 0; i < 10; i++) {
		if (genreList[i] == m_Genre) return i;
	}
	return 0;
}

/*
string ItemType::GetGenreNum() {
	return m_Genre;
} // 장르 반환 함수
*/


string ItemType::GetGenre()
{
	return m_Genre;
}
string ItemType::GetLyric()
{
	return m_lyric;
}

int ItemType::GetNumPlay() {
	return numPlay;
}

void ItemType::SetId(string inId) {
	m_Id = inId;
}						// 곡 고유번호 ID 저장 함수
void ItemType::SetName(string inName) {
	m_sName = inName;
}// 곡 명 저장 함수
void ItemType::SetComposer(string inComposer) {
	composer = inComposer;
}// 작곡자 저장 함수

void ItemType::SetMusician(string inMusician) {
	m_Musician = inMusician;
} // 연주자 저장함수
void ItemType::SetGenre(string inGenre) {
	m_Genre = inGenre;
} // 장르 저장 함수

void ItemType::SetLyric(string inLyric)
{
	m_lyric = inLyric;
}

void ItemType::SetPlayNum(int num)
{
	numPlay = num;
}

void ItemType::SetRecord(string inId, string inName, string inComposer, string inMusician, string inGenre) {
	m_Id = inId;
	m_sName = inName;
	composer = inComposer;
	m_Musician = inMusician;
	SetGenre(inGenre);
}	// 음악 정보 저장 함수

void ItemType::upNumPlay() {
	numPlay++;
}


void ItemType::DisplayIdOnScreen() {
	cout << m_Id << endl;
}	// 학생 ID 출력 함수
void ItemType::DisplayNameOnScreen() {
	cout << m_sName << endl;
}					// 곡 명 출력 함수
void ItemType::DisplayComposerOnScreen() {
	cout << composer << endl;
}				// 작곡자 출력 함수

void ItemType::DisplayMusicianOnScreen() {
	cout << m_Musician << endl;
}  // 연주자 출력 함수
void ItemType::DisplayGenreOnScreen() {
	cout << m_Genre << "\n";
} // 장르 출력 함수


void ItemType::DisplayRecordOnScreen() {
	cout << "\n\tl-----------------------------------------------\n";

	cout << "\tl ID: "  << m_Id << "\n";
	cout << "\tl Name: " << m_sName << "\n";
	cout << "\tl Composer: " << composer << "\n";
	cout << "\tl Musician: " << m_Musician << "\n";
	cout << "\tl Genre: " << m_Genre << "\n";
	cout << "\tl-----------------------------------------------\n";
}					// 음악 정보 출력 함수


void ItemType::SetIdFromKB() {
	cout << "Enter music's Id : "; cin >> m_Id;
}				// 키보드로 학생 ID 입력 함수
void ItemType::SetNameFromKB() {
	cout << "Enter music's Name : ";
	cin >> m_sName;
}			// 키보드로 학생 이름 입력 함수
void ItemType::SetComposerFromKB() {
	cout << "Enter music's composer : ";
	cin >> composer;
}			// 키보드로 작곡자 입력 함수

void ItemType::SetMusicianFromKB() {
	cout << "Enter music's Musician : ";
	cin >> m_Musician;
} // 키보드로 연주자 입력 함수
void ItemType::SetGenreFromKB() {
	cout << "Enter music's Genre : ";
	//guideGenre();
	cin >> m_Genre;
} // 키보드로 장르 입력 함수


void ItemType::SetRecordFromKB() { // 키보드로 음악 정보 입력 함수
	cout << "Enter music's Id : "; cin >> m_Id;
	cout << "Enter music's name : "; cin >> m_sName;
	cout << "Enter music's composer  : "; cin >> composer;
	cout << "Enter music's Musician  : "; cin >> m_Musician;
	cout << "Enter music's genre  : "; cin >> m_Genre;
}


int ItemType::ReadDataFromFile(ifstream& fin) {
	fin >> m_Id >> m_sName >> composer >> m_Musician >> m_Genre;

	if (fin.eof()) {
		return 0;
	}
	return 1;

}		// 음악 정보를 파일에서 읽는 함수
int ItemType::WriteDataToFile(ofstream& fout) {
	fout << m_Id << " " << m_sName << " " << composer << " " << m_Musician << " " << m_Genre << "\n";
	return 1;
}		// 음악 정보를 파일로 출력하는 함수



bool ItemType::operator==(ItemType data) { // 연산자 == , ID가 같다면 true 리턴, 다르면 false 리턴
	if (data.GetId() == this->GetId()) return true;
	else return false;
}

bool ItemType::operator>(ItemType data) { // 비교연산자 >  , m_Id > data.GetId() 이면 true,  아니면 false 
	return m_Id > data.GetId();
}


bool ItemType::operator<(ItemType data) { //비교연산자 < ,  m_Id < data.GetId() 이면 true,  아니면 false 
	return m_Id < data.GetId();
}

void ItemType::guideGenre()
{
	cout << "0:Dance        1:Ballad  2:Idol      3:POP       4:Indie\n";
	cout << "5:Rap/Hip-hop  6:Rock    7:R&B/Soul  8:Classic   Otherwise:Unknown \n";
}


/*
ItemType& ItemType::operator=(ItemType data) {
this->SetRecord(data.GetId(), data.GetName(), data.GetComposer(), data.GetMusician(), data.GetGenre(), data.GetType());
return *this;
}
*/

ostream & operator<<(ostream & os, const ItemType & item)
{
	os << "ID : " << item.m_Id;
	return os;
}
