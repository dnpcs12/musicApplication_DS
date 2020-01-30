#pragma once
#define DoublyIterator_H

#include "DoublySortedLinkedList.h"

template<typename T>
struct DoublyNodeType;

template<typename T>
class DoublySortedLinkedList;

template <typename T>
class DoublyIterator
{
	friend class DoublySortedLinkedList<T>;
public:
	DoublyIterator(const DoublySortedLinkedList<T> &list) : m_List(list), m_pCurPointer(list.m_pFirst) {};// Default constructor
	bool NotNull(); // list의 현재 원소가 Null이 아닌지 검사
	bool NextNotNull(); // list의 다음 원소가Null이 아닌지 검사
	
	/*
	 // list의 처음 node의 item을 리턴
	 post: m_pCurPointer가 맨 첫 노드를 가리키게 됨.
	 return : 처음 노드의 아이템 리턴.
	*/
	T First();

	/*
	// 다음 node로 이동하고 해당 node의 item을 리턴
	post: m_pCurPointer가 맨 마지막 노드를 가리키게 됨.
	return : 다음 node의 아이템 리턴.
	*/
	T Next(); 

	DoublyNodeType<T> GetCurrentNode();// 현재node를리턴
private:
	const DoublySortedLinkedList<T> &m_List;// 사용할 리스트의 참조변수
	DoublyNodeType<T> *m_pCurPointer; // Iterator 변수
};

template<typename T>
inline bool DoublyIterator<T>::NotNull() // 현재 가리키는 노드가 nullptr이면 false, nullptr이 아니면 true 리턴
{
	return (m_pCurPointer != nullptr);
}

template<typename T>
inline bool DoublyIterator<T>::NextNotNull() // next가 null이면 false, null이 아니면 true
{
	return (m_pCurPointer->next != nullptr);
}

template<typename T>
inline T DoublyIterator<T>::First()
{
	m_pCurPointer = m_List.m_pFirst;
	return m_pCurPointer->data;

}

template<typename T>
inline T DoublyIterator<T>::Next()
{
	m_pCurPointer = m_pCurPointer->next;
	return m_pCurPointer->data;
}

template<typename T>
inline DoublyNodeType<T> DoublyIterator<T>::GetCurrentNode()
{
	return *m_pCurPointer;
}


