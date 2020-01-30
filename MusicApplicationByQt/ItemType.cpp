
#include "ItemType.h"
#include <iomanip>
#include <string.h>

ItemType::ItemType() {
	m_Genre = " "; ////  0.��, 1.�߶��, 2.���̵�, 3.pop, 4.�ε�, 5.��/����, 6.��, 7.R&B , 8.Ŭ����, 9~.unknown (�� ��)

	composer = ""; // �۰���
	m_Id = "";					// �� ������ȣID
	m_sName = "";				// ���̸�
	m_Musician = ""; // ������
	numPlay = 0;

}

string ItemType::GetId() const {
	return m_Id;
}// ���� ������ȣ(ID) ��ȯ �Լ�
string ItemType::GetName() {
	return m_sName;
}// �� �̸� ��ȯ �Լ�
string ItemType::GetComposer() {
	return composer;
}						// �۰��� ��ȯ �Լ�
string ItemType::GetMusician() {
	return m_Musician;
} // ������ ��ȯ�Լ�

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
} // �帣 ��ȯ �Լ�
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
}						// �� ������ȣ ID ���� �Լ�
void ItemType::SetName(string inName) {
	m_sName = inName;
}// �� �� ���� �Լ�
void ItemType::SetComposer(string inComposer) {
	composer = inComposer;
}// �۰��� ���� �Լ�

void ItemType::SetMusician(string inMusician) {
	m_Musician = inMusician;
} // ������ �����Լ�
void ItemType::SetGenre(string inGenre) {
	m_Genre = inGenre;
} // �帣 ���� �Լ�

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
}	// ���� ���� ���� �Լ�

void ItemType::upNumPlay() {
	numPlay++;
}


void ItemType::DisplayIdOnScreen() {
	cout << m_Id << endl;
}	// �л� ID ��� �Լ�
void ItemType::DisplayNameOnScreen() {
	cout << m_sName << endl;
}					// �� �� ��� �Լ�
void ItemType::DisplayComposerOnScreen() {
	cout << composer << endl;
}				// �۰��� ��� �Լ�

void ItemType::DisplayMusicianOnScreen() {
	cout << m_Musician << endl;
}  // ������ ��� �Լ�
void ItemType::DisplayGenreOnScreen() {
	cout << m_Genre << "\n";
} // �帣 ��� �Լ�


void ItemType::DisplayRecordOnScreen() {
	cout << "\n\tl-----------------------------------------------\n";

	cout << "\tl ID: "  << m_Id << "\n";
	cout << "\tl Name: " << m_sName << "\n";
	cout << "\tl Composer: " << composer << "\n";
	cout << "\tl Musician: " << m_Musician << "\n";
	cout << "\tl Genre: " << m_Genre << "\n";
	cout << "\tl-----------------------------------------------\n";
}					// ���� ���� ��� �Լ�


void ItemType::SetIdFromKB() {
	cout << "Enter music's Id : "; cin >> m_Id;
}				// Ű����� �л� ID �Է� �Լ�
void ItemType::SetNameFromKB() {
	cout << "Enter music's Name : ";
	cin >> m_sName;
}			// Ű����� �л� �̸� �Է� �Լ�
void ItemType::SetComposerFromKB() {
	cout << "Enter music's composer : ";
	cin >> composer;
}			// Ű����� �۰��� �Է� �Լ�

void ItemType::SetMusicianFromKB() {
	cout << "Enter music's Musician : ";
	cin >> m_Musician;
} // Ű����� ������ �Է� �Լ�
void ItemType::SetGenreFromKB() {
	cout << "Enter music's Genre : ";
	//guideGenre();
	cin >> m_Genre;
} // Ű����� �帣 �Է� �Լ�


void ItemType::SetRecordFromKB() { // Ű����� ���� ���� �Է� �Լ�
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

}		// ���� ������ ���Ͽ��� �д� �Լ�
int ItemType::WriteDataToFile(ofstream& fout) {
	fout << m_Id << " " << m_sName << " " << composer << " " << m_Musician << " " << m_Genre << "\n";
	return 1;
}		// ���� ������ ���Ϸ� ����ϴ� �Լ�



bool ItemType::operator==(ItemType data) { // ������ == , ID�� ���ٸ� true ����, �ٸ��� false ����
	if (data.GetId() == this->GetId()) return true;
	else return false;
}

bool ItemType::operator>(ItemType data) { // �񱳿����� >  , m_Id > data.GetId() �̸� true,  �ƴϸ� false 
	return m_Id > data.GetId();
}


bool ItemType::operator<(ItemType data) { //�񱳿����� < ,  m_Id < data.GetId() �̸� true,  �ƴϸ� false 
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
