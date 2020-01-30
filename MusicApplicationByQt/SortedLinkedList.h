#pragma once
#ifndef SortedLinkedList
#define SortedLinkedList

template<typename T>
struct NodeType
{
	T info; // 노드에서 관리할 레코드
	NodeType *next;  // 다음 노드를 가리키는 포인터 
};

template <typename T>
class LinkedList {
public:
	LinkedList();
	~LinkedList();

	void MakeEmpty(); // List를 비움
	int GetLength() const; // 리스트가 보유하고 있는 item 개수 반환
	int Add(T item); // 새로운 레코드를 리스트에 삽입
	int Get(T &item); // primary key 를 기준으로 데이터를 검색하고 해당 데이터를 가져옴. 해당데이터가 존재하면 1, 아니면 0 리턴 
	void ResetList(); // 레코드 포인터 초기화
	void GetNextItem(T &item); // Current Pointer 가 다음 node를 가리키도록 이동후 해당 레코드를 가져옴
	int Delete(T item);
	int Replace(T item);

private:
	NodeType<T> *m_pList; // 리스트 포인터
	NodeType<T> *m_pCurPointer; // current pointer
	int m_nLength; // 리스트에 저장된 레코드수 

};

#endif // !SortedLinkedList

template<typename T>
inline LinkedList<T>::LinkedList()
{
	m_pList = nullptr;
	m_pCurPointer = nullptr;
	m_nLength = 0;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
	if (m_nLength != 0) MakeEmpty();

}

template<typename T>
void LinkedList<T>::MakeEmpty()
{
	NodeType<T> *cnt;

	m_pCurPointer = m_pList;
	while (m_pCurPointer != nullptr) {
		
		cnt = m_pCurPointer->next;
		delete m_pCurPointer;
		m_nLength--;
		m_pCurPointer = cnt;
	}


}

template<typename T>
inline int LinkedList<T>::GetLength() const
{
	return m_nLength;
}

template<typename T>
inline int LinkedList<T>::Add(T item)
{
	NodeType<T> *node;
	node = new NodeType<T>;
	node->info = item;

	NodeType<T> *pre;
	
	T temp;

	ResetList(); // current pointer 초기화 

	if (m_nLength == 0) {	// 리스트가 비었을때, 
		m_pList = node;
		node->next = nullptr;
		m_nLength++;
	}
	else { // 아닐때
		pre = nullptr;
		GetNextItem(temp);

		while (1) {
			if (node->info < m_pCurPointer->info) { // 추가하려는 아이템이 더 작을때  
				node->next = m_pCurPointer;
				if (pre == nullptr) { // 맨 앞일때 
					m_pList = node;
				}
				else {// 중간일때 
					pre->next = node;
				}
				m_nLength++;
				break;
			}
			if (m_pCurPointer->next == nullptr) { // 맨 끝의 아이템보다 클 때 
				node->next = nullptr;
				m_pCurPointer->next = node;
				m_nLength++;
				break;
			}
			pre = m_pCurPointer;
			GetNextItem(temp);
			

		}

	}
	
	return 0;
}

template<typename T>
inline int LinkedList<T>::Get(T & item) 
{
	T temp;
	m_pCurPointer = m_pList; 
	while (m_pCurPointer != nullptr) { // m_pCurPointer가 nullptr이 아닐때까지 찾음
		if (m_pCurPointer->info == item) { 
			item = m_pCurPointer->info;
			return 1;
		}
		GetNextItem(temp);
		
	}
	return 0;
}

template<typename T>
inline void LinkedList<T>::ResetList()
{
	m_pCurPointer = nullptr;
}

template<typename T>
inline void LinkedList<T>::GetNextItem(T & item)
{
	if (m_pCurPointer == nullptr) {
		m_pCurPointer = m_pList;
	}
	else {
		m_pCurPointer = m_pCurPointer->next;
		
		if (m_pCurPointer == nullptr) {
			return;
		}
	
	}	
	item = m_pCurPointer->info;

}

template<typename T>
inline int LinkedList<T>::Delete(T item)
{
	m_pCurPointer = m_pList;
	NodeType<T> *pre;
	pre = m_pList;

	while (m_pCurPointer != nullptr) {
		if (m_pCurPointer->info == item) {
			if (m_pCurPointer == m_pList) { // 맨 앞 거일때 
				m_pList = m_pList->next;
				delete m_pCurPointer;
			}
			else {
				pre->next = m_pCurPointer->next;
				delete m_pCurPointer;
			}
			m_nLength--; 
			return 1; // 아이템을 찾음
		}
		pre = m_pCurPointer;
		m_pCurPointer = m_pCurPointer->next;
	}

	return 0; // 아이템을 못찾음 
}

template<typename T>
inline int LinkedList<T>::Replace(T item)
{
	T temp;
	m_pCurPointer = m_pList;
	while (m_pCurPointer != nullptr) { // m_pCurPointer가 nullptr이 아닐때 (끝이 아닐때)까지 찾음
		if (m_pCurPointer->info == item) {
			m_pCurPointer->info = item;
			return 1;
		}
		GetNextItem(temp);

	}
	return 0;

	return 0;
}
