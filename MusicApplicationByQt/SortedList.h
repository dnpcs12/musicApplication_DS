#pragma once
#ifndef SortedList_h
#define SortedList_h
#include <iostream>


#define MAXSIZE 100
using namespace std;

template<typename T>

class SortedList {
public:
	SortedList();			// default constructor
	SortedList(int maxSize);			// Create list(max size) using dynamic allocation
	~SortedList();			// default destructor

	void MakeEmpty(); 			// Make list empty
	int GetLength();				// 레코드 수 반환
	bool IsEmpty(); // 배열이 비었는지 확인
	bool IsFull();				// 모든 배열의 사용 여부
	int Add(T data);			// 새로운 데이터 추가
	void ResetList();			// 레코드 포인터(current pointer) 초기화
	int Delete(T data); // 기존 레코드 삭제
	int Replace(T data);  // 입력된 data와 Primary key와 동일한 기록을 찾아서 List의 해당 기록을 입력된 data로 치환한다. 

	int GetNextItem(T& data);	// current pointer를 하나 증가시키고 끝이 아니면 record index를 리턴 끝이면 -1을 리턴
	int Retrieve(T & target); // Find the item whose primary key matches with the primary key of target
									 // and return the copy of the item in target.
	
	/*
	 *@brief: binary search를 이용하여 아이템을 찾아 data에 넘겨준다.
	 *@post : 찾고자 하는 데이터를 찾으면 data에 저장.  
	 *@ return : 찾으면 return 1, 찾지못하면 return 1 
	*/
	int RetrieveByBS(T & data); 

	int GetCurIndex();
	void SetCurIndex(int index);
	T at(int pos);

	bool isPrimary(T data); // 리스트에 이미 같은 아이템이 들어있는지 확인한다. 
private:
	T* m_Array;  		// 레코드 배열
	int m_Length;				// 리스트에 저장된 레코드 수
	int max;
	int m_CurPointer;			// current pointer

};

#endif // !SortedList_h

template<typename T>
inline SortedList<T>::SortedList()
{
	m_Length = 0;
	max = MAXSIZE;
	m_Array = new T[max];
}

template<typename T>
SortedList<T>::SortedList(int maxSize) {
	m_Length = 0;
	max = maxSize;
	m_Array = new T[max];
}			// default constructor	

template<typename T>
inline SortedList<T>::~SortedList()
{
	delete[] m_Array;
}

template<typename T>
void SortedList<T>::MakeEmpty() {
	m_Length = 0;
} 			// Make list empty

template<typename T>
int SortedList<T>::GetLength() {
	return m_Length;
}				// 레코드 수 반환

template<typename T>
bool SortedList<T>::IsEmpty() {
	if (m_Length <= 0) {
		return true;
	}
	else {
		return false;
	}

} // 배열이 비었는지 확인

template<typename T>
bool SortedList<T>::IsFull() {
	if (m_Length >= max) return true;
	else return false;
}				// 모든 배열의 사용 여부

template<typename T>
bool SortedList<T>::isPrimary(T data) { // 리스트에 같은 아이템이 있으면 false 리턴, 해당 아이템이 없으면 true 리턴.   
	if (RetrieveByBS(data)) return false;
	else return true;
}

template<typename T>
int SortedList<T>::Add(T data) {
	if (isPrimary(data)) {
		if (!IsFull()) { // 배열이 꽉 차있지 않을 때
			int i; // 새로운 데이터가 들어갈 인덱스 i.

			for (i = 0; i < m_Length; i++) {
				if (m_Array[i] > data) {  // i번째 id보다 data의 id가 작다면,
					for (int j = m_Length; j > i; j--) { // i번째부터 아이템들을 하나씩 밀고 
						m_Array[j] = m_Array[j - 1];
					}
					m_Array[i] = data; // i번째에 새로운 data를 추가한다.
					m_Length++; // 길이 ++;
					return 1;
				}
			}

			m_Array[m_Length] = data; // 리스트의 길이가 0이거나, i >=  m_Length 일경우,
			m_Length++;
		}
		else return -1; // 꽉 차 있다면 -1을 리턴

		return 1;

	}
	else {
		return -2;
	}
}		// 새로운 데이터 추가

template<typename T>
void SortedList<T>::ResetList() {
	m_CurPointer = -1;
}	// 레코드 포인터(current pointer) 초기화

template<typename T>
int SortedList<T>::Delete(T data) {
	m_CurPointer = 0; // 리스트의 첫번째 아이템부터 찾기 시작.
	while (m_CurPointer < m_Length) { // 현재 찾는 인덱스가 리스트의 길이보다 작을때까지 찾는다
		if (m_Array[m_CurPointer] == data) {
			if (m_CurPointer >= m_Length - 1) { // 리스트의 맨 마지막에 위치해있을 경우
				m_Length--; // 길이만 -1 줄인다.
			}
			else { //아닐 경우
				for (m_CurPointer; m_CurPointer < m_Length - 1; m_CurPointer++) {
					m_Array[m_CurPointer] = m_Array[m_CurPointer + 1]; // 아이템들을 한칸씩 앞으로 이동시켜주고 
				}
				m_Length--; // 길이 -1 
			}
			return 1;
		}
		m_CurPointer++;
	}
	return 0;
} // 기존 레코드 삭제



template<typename T>
int SortedList<T>::Replace(T data) {
	m_CurPointer = 0;
	while (m_CurPointer < m_Length) {
		if (m_Array[m_CurPointer] == data) {
			m_Array[m_CurPointer] = data;
			return 1;
		}
		m_CurPointer++;
	}
	return 0;

}  // 입력된 data와 Primary key와 동일한 기록을 찾아서 List의 해당 기록을 입력된 data로 치환한다. 

template<typename T>
int SortedList<T>::GetNextItem(T& data) {// current pointer를 하나 증가시키고 끝이 아니면 record index를 리턴 끝이면 -1을 리턴
	m_CurPointer++;
	if (m_CurPointer >= m_Length) return -1;
	else {
		data = m_Array[m_CurPointer];
		return m_CurPointer;
	}
}
template<typename T>
int SortedList<T>::Retrieve(T & target) {
	//target 에 찾고자 하는 항목의 primary key 가 저장되었고 가정
	// List를 차례대로 방문하면서 target 의 Key 와 일치하는 항목을 찾는다	
	//m_CourPointer 를 첫번째 항목을 가리키도록 세팅
	m_CurPointer = 0;

	while (m_Array[m_CurPointer] < target && m_CurPointer < m_Length) { // 현재 항목이 target의 ID보다 작으며, 현재 인덱스가 리스트의 길이보다 작을때까지 
		m_CurPointer++; //인덱스 1씩 증가
	}

	if (m_Array[m_CurPointer] == target) { //현재 항목의 아이템이 target과 같을 경우
		target = m_Array[m_CurPointer]; // 찾은 항목을 target에 복사
		return 1; // 1을 리턴한다.
	}
	else return 0; //target의 ID 보다 크거나, 리스트의 길이를 벗어난 경우 존재하지 않음으로 0 을 리턴한다. 

}

template<typename T>
int SortedList<T>::RetrieveByBS(T & data)  {
	/*
	binary search를 이용한 Retrieve함수.

	초기값 설정
	first = 0, last= length-1 ,mid = (length-1) /2

	1. 검색 시작 인덱스를 리스트의 중간(mid)으로 설정.

	2. 현재 인덱스의 항목과 데이터를 비교, 같다면 data에 현재 항목을 복사하고 리턴 1
	3. 현재 인덱스의 항목이 data보다 작다면, first를 현재 인덱스+1로 설정. 크다면. last를 현재 인덱스 -1로 설정
	4. mid = (first + last)/2

	5. first > last이면 반복 종료.
	6. 반복이 종료 됐다면, 리턴 0

	*/
	int first = 0;
	int last = m_Length - 1;
	int mid = (m_Length - 1) / 2;

	while (first <= last) {
		if (m_Array[mid] == data) {
			data = m_Array[mid];
			m_CurPointer = mid;
			return 1;
		}
		else if (m_Array[mid] < data) {
			first = mid + 1;
		}
		else if (m_Array[mid] > data) {
			last = mid - 1;
		}
		mid = (first + last) / 2;

	}
	return 0;

} // Retrieve by using binary search

template<typename T>
inline int SortedList<T>::GetCurIndex()
{
	return m_CurPointer;
}

template<typename T>
inline void SortedList<T>::SetCurIndex(int index)
{
	m_CurPointer = index;
}

template<typename T>
inline T SortedList<T>::at(int pos)
{
	m_CurPointer = pos;
	return m_Array[m_CurPointer];
}
