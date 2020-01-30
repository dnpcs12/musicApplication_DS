

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
	int GetLength();				// ���ڵ� �� ��ȯ
	bool IsEmpty(); // �迭�� ������� Ȯ��
	bool IsFull();				// ��� �迭�� ��� ����
	int Add(S data);			// ���ο� ������ �߰�
	int Insert(S data, int index);
	void ResetList();			// ���ڵ� ������(current pointer) �ʱ�ȭ
	int Delete(S data); // ���� ���ڵ� ���� . ã�Ƽ� �����ߴٸ� ���� 1, �ƴϸ� ���� 0
	int Replace(S data);  // �Էµ� data�� Primary key�� ������ ����� ã�Ƽ� List�� �ش� ����� �Էµ� data�� ġȯ�Ѵ�. 
	int Get(S&  data);    // Primary key�� �������� �����͸� �˻��ϰ� �ش� �����͸� ������
	int GetNextItem(S& data);	// current pointer�� �ϳ� ������Ű�� ���� �ƴϸ� record index�� ���� ���̸� -1�� ����
	int GetCurIndex();
	S at(int pos);//pos ��° �����͸� ��������. pos < m_Length��� ����. 
	void swap(int a,int b);

private:
	S m_Array[MAXSIZE];  		// ���ڵ� �迭
	int m_Length;				// ����Ʈ�� ����� ���ڵ� ��
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
}				// ���ڵ� �� ��ȯ

template<typename S>
bool ArrayList<S>::IsEmpty() {
	if (m_Length <= 0) {
		return true;
	}
	else {
		return false;
	}

} // �迭�� ������� Ȯ��

template<typename S>
bool ArrayList<S>::IsFull() {
	if (m_Length >= MAXSIZE) return true;
	else return false;
}				// ��� �迭�� ��� ����

template<typename S>
int ArrayList<S>::Add(S data) {
	if (!IsFull()) { // ����Ʈ�� �� ������ �ʴٸ�
		m_Array[m_Length] = data;
		m_Length++;
	}
	else return -1; // ����Ʈ�� �������� �������� �߰��� �� �������� -1 ����

	return 1;
}		// ���ο� ������ �߰�

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
}	// ���ڵ� ������(current pointer) �ʱ�ȭ


template<typename S>
int ArrayList<S>::Delete(S data) {
	m_CurPointer = 0; // ����Ʈ�� ù��° �����ۺ��� ã�� ����.
	while (m_CurPointer < m_Length) { // ���� ã�� �ε����� ����Ʈ�� ���̺��� ���������� ã�´�
		if (m_Array[m_CurPointer] == data) {
			if (m_CurPointer >= m_Length - 1) { // ����Ʈ�� �� �������� ��ġ������ ���
				m_Length--; // ���̸� -1 ���δ�.
			}
			else { //����Ʈ�� �߰��� �������,(ù��°ĭ ����)
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

template<typename S>
int ArrayList<S>::Replace(S data) {
	m_CurPointer = 0; //����Ʈ�� ù��°���� ã������

	while (m_CurPointer < m_Length) { // ����Ʈ�� ���̺��� ª�������� ã�´�
		if (m_Array[m_CurPointer] == data) { // ���� �׸�� �����Ͱ� ��ġ�ϴٸ�,
			m_Array[m_CurPointer] = data; // ���� �׸��� �����ͷ� �ٲ��ش�.
			return 1;
		}
		m_CurPointer++;
	}
	return 0; // ����Ʈ�� ���̸� �ʰ��Ҷ����� ���� �����͸� ã�� �������Ƿ� 0 ����

}  // �Էµ� data�� Primary key�� ������ ����� ã�Ƽ� List�� �ش� ����� �Էµ� data�� ġȯ�Ѵ�. 

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

}    // Primary key�� �������� �����͸� �˻��ϰ� �ش� �����͸� ������

template<typename S>
int ArrayList<S>::GetNextItem(S& data) {// current pointer�� �ϳ� ������Ű�� ���� �ƴϸ� record index�� ���� ���̸� -1�� ����
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
S ArrayList<S>::at(int pos) // �Ķ���� pos�� �ݵ��  0<=pos < ����Ʈ�� ���� ������.
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

