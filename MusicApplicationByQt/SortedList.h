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
	int GetLength();				// ���ڵ� �� ��ȯ
	bool IsEmpty(); // �迭�� ������� Ȯ��
	bool IsFull();				// ��� �迭�� ��� ����
	int Add(T data);			// ���ο� ������ �߰�
	void ResetList();			// ���ڵ� ������(current pointer) �ʱ�ȭ
	int Delete(T data); // ���� ���ڵ� ����
	int Replace(T data);  // �Էµ� data�� Primary key�� ������ ����� ã�Ƽ� List�� �ش� ����� �Էµ� data�� ġȯ�Ѵ�. 

	int GetNextItem(T& data);	// current pointer�� �ϳ� ������Ű�� ���� �ƴϸ� record index�� ���� ���̸� -1�� ����
	int Retrieve(T & target); // Find the item whose primary key matches with the primary key of target
									 // and return the copy of the item in target.
	
	/*
	 *@brief: binary search�� �̿��Ͽ� �������� ã�� data�� �Ѱ��ش�.
	 *@post : ã���� �ϴ� �����͸� ã���� data�� ����.  
	 *@ return : ã���� return 1, ã�����ϸ� return 1 
	*/
	int RetrieveByBS(T & data); 

	int GetCurIndex();
	void SetCurIndex(int index);
	T at(int pos);

	bool isPrimary(T data); // ����Ʈ�� �̹� ���� �������� ����ִ��� Ȯ���Ѵ�. 
private:
	T* m_Array;  		// ���ڵ� �迭
	int m_Length;				// ����Ʈ�� ����� ���ڵ� ��
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
}				// ���ڵ� �� ��ȯ

template<typename T>
bool SortedList<T>::IsEmpty() {
	if (m_Length <= 0) {
		return true;
	}
	else {
		return false;
	}

} // �迭�� ������� Ȯ��

template<typename T>
bool SortedList<T>::IsFull() {
	if (m_Length >= max) return true;
	else return false;
}				// ��� �迭�� ��� ����

template<typename T>
bool SortedList<T>::isPrimary(T data) { // ����Ʈ�� ���� �������� ������ false ����, �ش� �������� ������ true ����.   
	if (RetrieveByBS(data)) return false;
	else return true;
}

template<typename T>
int SortedList<T>::Add(T data) {
	if (isPrimary(data)) {
		if (!IsFull()) { // �迭�� �� ������ ���� ��
			int i; // ���ο� �����Ͱ� �� �ε��� i.

			for (i = 0; i < m_Length; i++) {
				if (m_Array[i] > data) {  // i��° id���� data�� id�� �۴ٸ�,
					for (int j = m_Length; j > i; j--) { // i��°���� �����۵��� �ϳ��� �а� 
						m_Array[j] = m_Array[j - 1];
					}
					m_Array[i] = data; // i��°�� ���ο� data�� �߰��Ѵ�.
					m_Length++; // ���� ++;
					return 1;
				}
			}

			m_Array[m_Length] = data; // ����Ʈ�� ���̰� 0�̰ų�, i >=  m_Length �ϰ��,
			m_Length++;
		}
		else return -1; // �� �� �ִٸ� -1�� ����

		return 1;

	}
	else {
		return -2;
	}
}		// ���ο� ������ �߰�

template<typename T>
void SortedList<T>::ResetList() {
	m_CurPointer = -1;
}	// ���ڵ� ������(current pointer) �ʱ�ȭ

template<typename T>
int SortedList<T>::Delete(T data) {
	m_CurPointer = 0; // ����Ʈ�� ù��° �����ۺ��� ã�� ����.
	while (m_CurPointer < m_Length) { // ���� ã�� �ε����� ����Ʈ�� ���̺��� ���������� ã�´�
		if (m_Array[m_CurPointer] == data) {
			if (m_CurPointer >= m_Length - 1) { // ����Ʈ�� �� �������� ��ġ������ ���
				m_Length--; // ���̸� -1 ���δ�.
			}
			else { //�ƴ� ���
				for (m_CurPointer; m_CurPointer < m_Length - 1; m_CurPointer++) {
					m_Array[m_CurPointer] = m_Array[m_CurPointer + 1]; // �����۵��� ��ĭ�� ������ �̵������ְ� 
				}
				m_Length--; // ���� -1 
			}
			return 1;
		}
		m_CurPointer++;
	}
	return 0;
} // ���� ���ڵ� ����



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

}  // �Էµ� data�� Primary key�� ������ ����� ã�Ƽ� List�� �ش� ����� �Էµ� data�� ġȯ�Ѵ�. 

template<typename T>
int SortedList<T>::GetNextItem(T& data) {// current pointer�� �ϳ� ������Ű�� ���� �ƴϸ� record index�� ���� ���̸� -1�� ����
	m_CurPointer++;
	if (m_CurPointer >= m_Length) return -1;
	else {
		data = m_Array[m_CurPointer];
		return m_CurPointer;
	}
}
template<typename T>
int SortedList<T>::Retrieve(T & target) {
	//target �� ã���� �ϴ� �׸��� primary key �� ����Ǿ��� ����
	// List�� ���ʴ�� �湮�ϸ鼭 target �� Key �� ��ġ�ϴ� �׸��� ã�´�	
	//m_CourPointer �� ù��° �׸��� ����Ű���� ����
	m_CurPointer = 0;

	while (m_Array[m_CurPointer] < target && m_CurPointer < m_Length) { // ���� �׸��� target�� ID���� ������, ���� �ε����� ����Ʈ�� ���̺��� ���������� 
		m_CurPointer++; //�ε��� 1�� ����
	}

	if (m_Array[m_CurPointer] == target) { //���� �׸��� �������� target�� ���� ���
		target = m_Array[m_CurPointer]; // ã�� �׸��� target�� ����
		return 1; // 1�� �����Ѵ�.
	}
	else return 0; //target�� ID ���� ũ�ų�, ����Ʈ�� ���̸� ��� ��� �������� �������� 0 �� �����Ѵ�. 

}

template<typename T>
int SortedList<T>::RetrieveByBS(T & data)  {
	/*
	binary search�� �̿��� Retrieve�Լ�.

	�ʱⰪ ����
	first = 0, last= length-1 ,mid = (length-1) /2

	1. �˻� ���� �ε����� ����Ʈ�� �߰�(mid)���� ����.

	2. ���� �ε����� �׸�� �����͸� ��, ���ٸ� data�� ���� �׸��� �����ϰ� ���� 1
	3. ���� �ε����� �׸��� data���� �۴ٸ�, first�� ���� �ε���+1�� ����. ũ�ٸ�. last�� ���� �ε��� -1�� ����
	4. mid = (first + last)/2

	5. first > last�̸� �ݺ� ����.
	6. �ݺ��� ���� �ƴٸ�, ���� 0

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
