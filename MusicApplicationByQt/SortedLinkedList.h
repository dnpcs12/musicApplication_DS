#pragma once
#ifndef SortedLinkedList
#define SortedLinkedList

template<typename T>
struct NodeType
{
	T info; // ��忡�� ������ ���ڵ�
	NodeType *next;  // ���� ��带 ����Ű�� ������ 
};

template <typename T>
class LinkedList {
public:
	LinkedList();
	~LinkedList();

	void MakeEmpty(); // List�� ���
	int GetLength() const; // ����Ʈ�� �����ϰ� �ִ� item ���� ��ȯ
	int Add(T item); // ���ο� ���ڵ带 ����Ʈ�� ����
	int Get(T &item); // primary key �� �������� �����͸� �˻��ϰ� �ش� �����͸� ������. �ش絥���Ͱ� �����ϸ� 1, �ƴϸ� 0 ���� 
	void ResetList(); // ���ڵ� ������ �ʱ�ȭ
	void GetNextItem(T &item); // Current Pointer �� ���� node�� ����Ű���� �̵��� �ش� ���ڵ带 ������
	int Delete(T item);
	int Replace(T item);

private:
	NodeType<T> *m_pList; // ����Ʈ ������
	NodeType<T> *m_pCurPointer; // current pointer
	int m_nLength; // ����Ʈ�� ����� ���ڵ�� 

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

	ResetList(); // current pointer �ʱ�ȭ 

	if (m_nLength == 0) {	// ����Ʈ�� �������, 
		m_pList = node;
		node->next = nullptr;
		m_nLength++;
	}
	else { // �ƴҶ�
		pre = nullptr;
		GetNextItem(temp);

		while (1) {
			if (node->info < m_pCurPointer->info) { // �߰��Ϸ��� �������� �� ������  
				node->next = m_pCurPointer;
				if (pre == nullptr) { // �� ���϶� 
					m_pList = node;
				}
				else {// �߰��϶� 
					pre->next = node;
				}
				m_nLength++;
				break;
			}
			if (m_pCurPointer->next == nullptr) { // �� ���� �����ۺ��� Ŭ �� 
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
	while (m_pCurPointer != nullptr) { // m_pCurPointer�� nullptr�� �ƴҶ����� ã��
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
			if (m_pCurPointer == m_pList) { // �� �� ���϶� 
				m_pList = m_pList->next;
				delete m_pCurPointer;
			}
			else {
				pre->next = m_pCurPointer->next;
				delete m_pCurPointer;
			}
			m_nLength--; 
			return 1; // �������� ã��
		}
		pre = m_pCurPointer;
		m_pCurPointer = m_pCurPointer->next;
	}

	return 0; // �������� ��ã�� 
}

template<typename T>
inline int LinkedList<T>::Replace(T item)
{
	T temp;
	m_pCurPointer = m_pList;
	while (m_pCurPointer != nullptr) { // m_pCurPointer�� nullptr�� �ƴҶ� (���� �ƴҶ�)���� ã��
		if (m_pCurPointer->info == item) {
			m_pCurPointer->info = item;
			return 1;
		}
		GetNextItem(temp);

	}
	return 0;

	return 0;
}
