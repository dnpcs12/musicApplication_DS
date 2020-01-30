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
	bool NotNull(); // list�� ���� ���Ұ� Null�� �ƴ��� �˻�
	bool NextNotNull(); // list�� ���� ���Ұ�Null�� �ƴ��� �˻�
	
	/*
	 // list�� ó�� node�� item�� ����
	 post: m_pCurPointer�� �� ù ��带 ����Ű�� ��.
	 return : ó�� ����� ������ ����.
	*/
	T First();

	/*
	// ���� node�� �̵��ϰ� �ش� node�� item�� ����
	post: m_pCurPointer�� �� ������ ��带 ����Ű�� ��.
	return : ���� node�� ������ ����.
	*/
	T Next(); 

	DoublyNodeType<T> GetCurrentNode();// ����node������
private:
	const DoublySortedLinkedList<T> &m_List;// ����� ����Ʈ�� ��������
	DoublyNodeType<T> *m_pCurPointer; // Iterator ����
};

template<typename T>
inline bool DoublyIterator<T>::NotNull() // ���� ����Ű�� ��尡 nullptr�̸� false, nullptr�� �ƴϸ� true ����
{
	return (m_pCurPointer != nullptr);
}

template<typename T>
inline bool DoublyIterator<T>::NextNotNull() // next�� null�̸� false, null�� �ƴϸ� true
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


