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

	string GetId() const;							// �� ������ȣ ID ��ȯ �Լ�
	string GetName();						// �� �̸� ��ȯ �Լ�
	string GetComposer();		// �۰ ��ȯ �Լ�
	string GetMusician(); // ������ ��ȯ�Լ�
	int GetGenreNum(); // �帣 ��ȯ �Լ�
	string GetGenre();
	string GetLyric(); //���� ��ȯ �Լ� 

	/*
	���� ���� �÷��� Ƚ���� ����. 
	return numPlay
	*/
	int GetNumPlay(); 

	void SetId(string inId);						// �� ������ȣ ID ���� �Լ�
	void SetName(string inName);					// �� �̸� ���� �Լ�
	void SetComposer(string inComposer); //�۰ ���� �Լ�
	void SetMusician(string inMusician); // ������ �����Լ�
	void SetGenre(string inGenre); // �帣 ���� �Լ�
	void SetLyric(string inLyric); //���� ���� �ռ� 
	void SetPlayNum(int num); // ���Ƚ�� ���� �Լ� 
	void SetRecord(string inId, string inName, string inComposer, string inMusician, string inGenre); 	// ���� ���� ���� �Լ�
	/*
	�÷��� Ƚ���� 1 ������Ų��. 
	post : numPlay ++;
	*/
	void upNumPlay(); 
	
	void DisplayIdOnScreen();					// �� ������ȣ ��� �Լ�
	void DisplayNameOnScreen();					// �� �� ��� �Լ�
	void DisplayComposerOnScreen();				// �۰��� ��� �Լ�
	void DisplayMusicianOnScreen();  // ������ ��� �Լ�
	void DisplayGenreOnScreen(); // �帣 ��� �Լ�
	void DisplayRecordOnScreen();		// �� ���� ��� �Լ�

	void SetIdFromKB();				// Ű����� �� ������ȣ(ID) �Է� �Լ�
	void SetNameFromKB();			// Ű����� �л� �̸� �Է� �Լ�
	void SetComposerFromKB();			// Ű����� �۰��� �Է� �Լ�
	void SetMusicianFromKB(); // Ű����� ������ �Է� �Լ�
	void SetGenreFromKB(); // Ű����� �帣 �Է� �Լ�
	void SetRecordFromKB();			// Ű����� �л� ���� �Է� �Լ�

	int ReadDataFromFile(ifstream& fin);		//���� ������ ���Ͽ��� �д� �Լ�
	int WriteDataToFile(ofstream& fout);		//���� ������ ���Ϸ� ����ϴ� �Լ�
	bool operator==(ItemType data);// ������ == , ID�� ���ٸ� true ����, �ٸ��� false ����
	bool operator>(ItemType data);// �񱳿����� >  , m_Id > data.GetId() �̸� true,  �ƴϸ� false
	bool operator<(ItemType data);//�񱳿����� < ,  m_Id < data.GetId() �̸� true,  �ƴϸ� false 

	friend ostream& operator<<(ostream& os, const ItemType& item);

	void guideGenre();

	//ItemType& operator=(ItemType data);

private:

	string genreList[10] = { "Unknown" ,"Dance","Ballad","Idol","Pop","Indie","Rap/Hiphop","Rock","R&B","Classic" };
	string composer; // �۰���
	string m_Id;					// �л� ID
	string m_sName;				// �л� �̸� ���� ����
	string m_Musician; // ������ 
	string m_Genre;
	string m_lyric; // ���� 
	int numPlay; // �÷��� Ƚ��; 
};
#endif// !ItemType.h
