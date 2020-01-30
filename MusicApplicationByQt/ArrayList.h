

#ifndef ArrayList_h
#define ArrayList_h
#include <iostream>


#define MAXSIZE 100
using namespace std;

template<typename S>
class ArrayList
{

public:
	ArrayList();			// default constructor
	~ArrayList() {}			// default destructor

	void MakeEmpty(); 			// Make list empty
	int GetLength();				// 레코드 수 반환
	bool IsEmpty(); // 배열이 비었는지 확인
	bool IsFull();				// 모든 배열의 사용 여부
	int Add(S data);			// 새로운 데이터 추가
	int Insert(S data, int index);
	void ResetList();			// 레코드 포인터(current pointer) 초기화
	int Delete(S data); // 기존 레코드 삭제 . 찾아서 삭제했다면 리턴 1, 아니면 리턴 0
	int Replace(S data);  // 입력된 data와 Primary key와 동일한 기록을 찾아서 List의 해당 기록을 입력된 data로 치환한다. 
	int Get(S&  data);    // Primary key를 기준으로 데이터를 검색하고 해당 데이터를 가져옴
	int GetNextItem(S& data);	// current pointer를 하나 증가시키고 끝이 아니면 record index를 리턴 끝이면 -1을 리턴
	int GetCurIndex();
	S at(int pos);//pos 번째 데이터를 리턴해줌. pos < m_Length라고 가정. 
	void swap(int a,int b);

private:
	S m_Array[MAXSIZE];  		// 레코드 배열
	int m_Length;				// 리스트에 저장된 레코드 수
	int m_CurPointer;			// current pointer
};

template<typename S>
ArrayList<S>::ArrayList() {
	m_Length = 0;
	m_CurPointer = -1;
}			// default constructor	

template<typename S>
void ArrayList<S>::MakeEmpty() {
	m_Length = 0;
} 			// Make list empty

template<typename S>
int ArrayList<S>::GetLength() {
	return m_Length;
}				// 레코드 수 반환

template<typename S>
bool ArrayList<S>::IsEmpty() {
	if (m_Length <= 0) {
		return true;
	}
	else {
		return false;
	}

} // 배열이 비었는지 확인

template<typename S>
bool ArrayList<S>::IsFull() {
	if (m_Length >= MAXSIZE) return true;
	else return false;
}				// 모든 배열의 사용 여부

template<typename S>
int ArrayList<S>::Add(S data) {
	if (!IsFull()) { // 리스트가 꽉 차있지 않다면
		m_Array[m_Length] = data;
		m_Length++;
	}
	else return -1; // 리스트가 가득차서 아이템을 추가할 수 없음으로 -1 리턴

	return 1;
}		// 새로운 데이터 추가

template<typename S>
inline int ArrayList<S>::Insert(S data, int index)
{
	if (!IsFull()) {
		if (index > m_Length) return -2;
		else {
			for (int i = m_Length; i > index; i--) {
				m_Array[i] = m_Array[i - 1];
			}
			m_Array[index] = data;
			m_Length++;
		}
		return 1;
	}
	else return -1;

	

}

template<typename S>
void ArrayList<S>::ResetList() {
	m_CurPointer = -1;
}	// 레코드 포인터(current pointer) 초기화


template<typename S>
int ArrayList<S>::Delete(S data) {
	m_CurPointer = 0; // 리스트의 첫번째 아이템부터 찾기 시작.
	while (m_CurPointer < m_Length) { // 현재 찾는 인덱스가 리스트의 길이보다 작을때까지 찾는다
		if (m_Array[m_CurPointer] == data) {
			if (m_CurPointer >= m_Length - 1) { // 리스트의 맨 마지막에 위치해있을 경우
				m_Length--; // 길이만 -1 줄인다.
			}
			else { //리스트의 중간에 있을경우,(첫번째칸 포함)
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

template<typename S>
int ArrayList<S>::Replace(S data) {
	m_CurPointer = 0; //리스트의 첫번째부터 찾기위해

	while (m_CurPointer < m_Length) { // 리스트의 길이보다 짧을때까지 찾는다
		if (m_Array[m_CurPointer] == data) { // 현재 항목과 데이터가 일치하다면,
			m_Array[m_CurPointer] = data; // 현재 항목을 데이터로 바꿔준다.
			return 1;
		}
		m_CurPointer++;
	}
	return 0; // 리스트의 길이를 초과할때까지 같은 데이터를 찾지 못했으므로 0 리턴

}  // 입력된 data와 Primary key와 동일한 기록을 찾아서 List의 해당 기록을 입력된 data로 치환한다. 

template<typename S>
int ArrayList<S>::Get(S&  data) {
	m_CurPointer = 0;
	while (m_CurPointer < m_Length) {
		if (m_Array[m_CurPointer] == data) {
			data = m_Array[m_CurPointer];
			return 1;
		}
		m_CurPointer++;
	}
	return 0;

}    // Primary key를 기준으로 데이터를 검색하고 해당 데이터를 가져옴

template<typename S>
int ArrayList<S>::GetNextItem(S& data) {// current pointer를 하나 증가시키고 끝이 아니면 record index를 리턴 끝이면 -1을 리턴
	m_CurPointer++;
	if (m_CurPointer >= m_Length) return -1;
	else {
		data = m_Array[m_CurPointer];
		return 1;
	}
}
template<typename S>
inline int ArrayList<S>::GetCurIndex()
{
	return m_CurPointer;
}
template<typename S>
S ArrayList<S>::at(int pos) // 파라메터 pos는 반드시  0<=pos < 리스트으 길이 여야함.
{
	m_CurPointer = pos;
	return m_Array[m_CurPointer];
}
template<typename S>
inline void ArrayList<S>::swap(int a, int b)
{
	if (a < 0 || a > m_Length || b <0 || b > m_Length) return;
	S temp;
	temp = m_Array[a];
	m_Array[a] = m_Array[b];
	m_Array[b] = temp;
}
#endif // !ArrayList_h

