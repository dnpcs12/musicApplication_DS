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
	friend class DoublyIterator<T>; ///< DoublyIterator�� ģ�� Ŭ����.
public:
	/**
	*	����Ʈ ������.
	*/
	DoublySortedLinkedList();

	/**
	*	�Ҹ���.
	*/
	~DoublySortedLinkedList();

	/**
	*	@brief	����Ʈ�� ������� �ƴ��� �˻��Ѵ�.
	*	@pre	m_nLength�� ���� ������ �־�� �Ѵ�.
	*	@post	������� �ƴ����� �˷��ش�.
	*	@return	��������� true, �ƴϸ� false�� ��ȯ.
	*/
	bool IsEmpty();

	/**
	*	@brief	����Ʈ�� ���� á���� �ƴ��� �˻��Ѵ�.
	*	@pre	m_nLength�� ���� ������ �־�� �Ѵ�.
	*	@post	���� á���� �ƴ����� �˷��ش�.
	*	@return	���� �������� true, �ƴϸ� false�� ��ȯ.
	*/
	bool IsFull();

	/**
	*	@brief	����Ʈ�� ����.
	*	@pre	����.
	*	@post	m_pFirst�� m_pLast�� ������ ��� �����͸� �����.
	*/
	void MakeEmpty();

	/**
	*	@brief	����Ʈ�� ���̸� ��ȯ�Ѵ�.
	*	@pre	����.
	*	@post	����Ʈ�� ���̸� ��ȯ.
	*	@return	m_nLength ����Ʈ�� ���� ��ȯ.
	*/
	int GetLength() const;

	/**
	*	@brief	���ο� �������� ����Ʈ�� �߰��Ѵ�.
	*	@pre	item�� �Է¹޴´�.
	*	@post	�������� ����Ʈ�� �߰��Ѵ�.
	*	@return	���� �������� ������ 0�� ��ȯ�ϰ�, �Է¿� �����ϸ� 1�� ��ȯ.
	*/
	int Add(T item);

	/**
	*	@brief	�Է¹��� �������� ����Ʈ���� �����Ѵ�.
	*	@pre	item�� �Է¹޴´�.
	*	@post	�Է¹��� �������� ����Ʈ���� ã�� �����Ѵ�.
	*   @return ���� �Է¹��� �������� ����Ʈ�� �������� �ʴ´ٸ� 0�� ����, ã�Ƽ� �����ߴٸ� 1����
	*/
	int Delete(T item);

	/**
	*	@brief	�Է¹��� ���������� ������ �ٲ۴�.
	*	@pre	item�� �Է¹޴´�.
	*	@post	���ο� ������ ��ü�ȴ�.
	*/
	void Replace(T item);

	/**
	*	@brief	�Է¹��� �������� ������ ���Ͽ� ���� ����Ʈ�� �������� �����´�.
	*	@pre	item�� �Է¹޴´�.
	*	@post	�˻��� �����͸� �����ۿ� �ִ´�.
	*	@return	��ġ�ϴ� �����͸� ã���� 1, �׷��� ������ 0�� ��ȯ.
	*/
	int Get(T &item);

private:
	DoublyNodeType<T>* m_pFirst; ///< �ּҰ��� ������ ����Ʈ�� �� ó��.
	DoublyNodeType<T>* m_pLast; ///< �ִ��� ������ ����Ʈ�� �� ��.
	int m_nLength; ///< ����Ʈ�� ����.
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
		DoublyIterator<T> iter(*this); // ���ͷ�����
		DoublyNodeType<T> *temp; // ���� �ӽ÷� �����ص� ��.
		iter.Next();
		while (m_nLength != 0) {
			temp = iter.m_pCurPointer; // ���� ���Ͱ� ����Ű�� �� temp�� ����
			iter.Next(); // ���ʹ� ���� ��带 ����Ű�� �ϰ� 
			delete temp; // temp ����
			m_nLength--; // ���� - 1
			
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
			if (item < iter.m_pCurPointer->data || iter.m_pCurPointer == m_pLast) { // �߰��Ϸ��� �������� ���� �����ۺ��� �۰ų�, �� �ڱ��� ã�� �������.
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
		if (iter.m_pCurPointer->data == item) { // �����ϰ��� �ϴ� �������� ã����

			iter.m_pCurPointer->prev->next = iter.m_pCurPointer->next; // �����ϰ��� �ϴ� ������ �� �� ��带 �������ְ�
			iter.m_pCurPointer->next->prev = iter.m_pCurPointer->prev;

			delete iter.m_pCurPointer; // ����.
			m_nLength--; 

			return 1; // ã�Ƽ� ������������ 1 ����; 
		}
		else if (iter.m_pCurPointer->data > item)  break;
		else iter.Next();
		
	}
	return 0; // �ش�������� �������� ��������, 0 ���� 
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
	while (iter.m_pCurPointer != m_pLast) { // ����Ʈ�� �� ������ ã��
		if (iter.m_pCurPointer->data == item) { // ã�Ҵٸ�
			item = iter.m_pCurPointer->data; 
			return 1; // ���� 1
		}
		else if (iter.m_pCurPointer->data > item) {
			break;
		}
		else { 
			iter.Next();
		}
	}
	return 0; // �������� ��ã�������� 0 ����
}


