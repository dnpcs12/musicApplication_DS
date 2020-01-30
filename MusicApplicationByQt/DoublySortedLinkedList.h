#pragma once
#include "DoublyIterator.h"

#define DoublySortedLinkedList_H
#define DSLMAXSIZE 100

template<typename T>
class DoublyIterator;

template <typename T>
struct DoublyNodeType
{
	T data;// data
	DoublyNodeType *prev;// Pointer of previous node
	DoublyNodeType *next;// Pointer of next node
};

template <typename T>
class DoublySortedLinkedList
{
	friend class DoublyIterator<T>; ///< DoublyIterator와 친구 클래스.
public:
	/**
	*	디폴트 생성자.
	*/
	DoublySortedLinkedList();

	/**
	*	소멸자.
	*/
	~DoublySortedLinkedList();

	/**
	*	@brief	리스트가 비었는지 아닌지 검사한다.
	*	@pre	m_nLength가 값을 가지고 있어야 한다.
	*	@post	비었는지 아닌지를 알려준다.
	*	@return	비어있으면 true, 아니면 false를 반환.
	*/
	bool IsEmpty();

	/**
	*	@brief	리스트가 가득 찼는지 아닌지 검사한다.
	*	@pre	m_nLength가 값을 가지고 있어야 한다.
	*	@post	가득 찼는지 아닌지를 알려준다.
	*	@return	가득 차있으면 true, 아니면 false를 반환.
	*/
	bool IsFull();

	/**
	*	@brief	리스트를 비운다.
	*	@pre	없음.
	*	@post	m_pFirst와 m_pLast를 제외한 모든 데이터를 지운다.
	*/
	void MakeEmpty();

	/**
	*	@brief	리스트의 길이를 반환한다.
	*	@pre	없음.
	*	@post	리스트의 길이를 반환.
	*	@return	m_nLength 리스트의 길이 반환.
	*/
	int GetLength() const;

	/**
	*	@brief	새로운 아이템을 리스트에 추가한다.
	*	@pre	item을 입력받는다.
	*	@post	아이템을 리스트에 추가한다.
	*	@return	같은 아이템이 있으면 0을 반환하고, 입력에 성공하면 1을 반환.
	*/
	int Add(T item);

	/**
	*	@brief	입력받은 아이템을 리스트에서 삭제한다.
	*	@pre	item을 입력받는다.
	*	@post	입력받은 아이템을 리스트에서 찾아 삭제한다.
	*   @return 만약 입력받은 아이템이 리스트에 존재하지 않는다면 0을 리턴, 찾아서 삭제했다면 1리턴
	*/
	int Delete(T item);

	/**
	*	@brief	입력받은 아이템으로 정보를 바꾼다.
	*	@pre	item을 입력받는다.
	*	@post	새로운 정보로 교체된다.
	*/
	void Replace(T item);

	/**
	*	@brief	입력받은 아이템의 정보와 비교하여 같은 리스트의 아이템을 가져온다.
	*	@pre	item을 입력받는다.
	*	@post	검색된 데이터를 아이템에 넣는다.
	*	@return	일치하는 데이터를 찾으면 1, 그렇지 않으면 0을 반환.
	*/
	int Get(T &item);

private:
	DoublyNodeType<T>* m_pFirst; ///< 최소값을 가지는 리스트의 맨 처음.
	DoublyNodeType<T>* m_pLast; ///< 최댓값을 가지는 리스트의 맨 끝.
	int m_nLength; ///< 리스트의 길이.
};

template<typename T>
inline DoublySortedLinkedList<T>::DoublySortedLinkedList()
{
	m_pFirst = new DoublyNodeType<T>;
	m_pLast = new DoublyNodeType<T>;

	m_pFirst->prev = nullptr;
	m_pFirst->next = m_pLast;
	//m_pFirst->data = NULL;

	m_pLast->prev = m_pFirst;
	m_pLast->next = nullptr;
	//m_pLast->data = NULL;


	m_nLength = 0;
}

template<typename T>
inline DoublySortedLinkedList<T>::~DoublySortedLinkedList()
{
	MakeEmpty();
	delete m_pFirst;
	delete m_pLast;
}

template<typename T>
inline bool DoublySortedLinkedList<T>::IsEmpty()
{
	return (m_nLength == 0);
}

template<typename T>
inline bool DoublySortedLinkedList<T>::IsFull()
{
	if (m_nLength > DSLMAXSIZE) return true;
	else return false;
}

template<typename T>
inline void DoublySortedLinkedList<T>::MakeEmpty()
{
	if (m_nLength != 0) {
		DoublyIterator<T> iter(*this); // 이터레이터
		DoublyNodeType<T> *temp; // 값을 임시로 저장해둘 곳.
		iter.Next();
		while (m_nLength != 0) {
			temp = iter.m_pCurPointer; // 현재 이터가 가리키는 걸 temp에 저장
			iter.Next(); // 이터는 다음 노드를 가리키게 하고 
			delete temp; // temp 삭제
			m_nLength--; // 길이 - 1
			
		}
		m_pFirst->next = m_pLast;
		m_pFirst->prev = nullptr;
		m_pLast->prev = m_pFirst;
		m_pLast->next = nullptr;
	}
}

template<typename T>
inline int DoublySortedLinkedList<T>::GetLength() const
{
	return m_nLength;
}

template<typename T>
inline int DoublySortedLinkedList<T>::Add(T item)
{
	DoublyIterator<T> iter(*this);
	iter.Next();

	
	if (IsEmpty()) {
		DoublyNodeType<T> *temp = new DoublyNodeType<T>;
		temp->data = item;

		temp->next = m_pLast;
		temp->prev = m_pFirst;
		m_pFirst->next = temp;
		m_pLast->prev = temp;
		m_nLength++;

	}
	else {
		while (1) {
			if (item < iter.m_pCurPointer->data || iter.m_pCurPointer == m_pLast) { // 추가하려는 아이템이 현재 아이템보다 작거나, 맨 뒤까지 찾아 봤을경우.
				DoublyNodeType<T> *temp = new DoublyNodeType<T>;
				temp->data = item;

				temp->next = iter.m_pCurPointer;
				temp->prev = iter.m_pCurPointer->prev;
				iter.m_pCurPointer->prev->next = temp;
				iter.m_pCurPointer->prev = temp;
				
				m_nLength++;
				break;
			}
			else if (item == iter.m_pCurPointer->data) {
				return 0;
			}
			else {
				iter.Next();
			}
		}
	}
	
	return 1;
}

template<typename T>
inline int DoublySortedLinkedList<T>::Delete(T item)
{
	DoublyIterator<T> iter(*this);
	iter.Next();
	while (iter.m_pCurPointer != m_pLast) {
		if (iter.m_pCurPointer->data == item) { // 삭제하고자 하는 아이템을 찾으면

			iter.m_pCurPointer->prev->next = iter.m_pCurPointer->next; // 삭제하고자 하는 아이템 앞 뒤 노드를 연결해주고
			iter.m_pCurPointer->next->prev = iter.m_pCurPointer->prev;

			delete iter.m_pCurPointer; // 삭제.
			m_nLength--; 

			return 1; // 찾아서 삭제했음으로 1 리턴; 
		}
		else if (iter.m_pCurPointer->data > item)  break;
		else iter.Next();
		
	}
	return 0; // 해당아이템이 존재하지 않음으로, 0 리턴 
}

template<typename T>
inline void DoublySortedLinkedList<T>::Replace(T item)
{
	DoublyIterator<T> iter(*this);
	iter.Next();
	while (iter.m_pCurPointer != m_pLast) {
		if (iter.m_pCurPointer->data == item) {
			iter.m_pCurPointer->data = item;
			return;
		}
		else if (iter.m_pCurPointer->data > item) {
			break;
		}
		else { 
			iter.Next();
		}
	}
	return;
}

template<typename T>
inline int DoublySortedLinkedList<T>::Get(T & item)
{
	DoublyIterator<T> iter(*this);
	iter.Next();
	while (iter.m_pCurPointer != m_pLast) { // 리스트의 맨 끝까지 찾기
		if (iter.m_pCurPointer->data == item) { // 찾았다면
			item = iter.m_pCurPointer->data; 
			return 1; // 리턴 1
		}
		else if (iter.m_pCurPointer->data > item) {
			break;
		}
		else { 
			iter.Next();
		}
	}
	return 0; // 아이템을 못찾았음으로 0 리턴
}


