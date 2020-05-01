#pragma once
#include "Exception.h"
#include <algorithm>

using namespace std;

template <typename T>
class THeap
{
private:
	int maxsize; // ������������ ����� ��-���
	int size; // ������� ����� ��-���
	int d; // ������� ����
	T* keys; // ��������
public:
	THeap(int maxsize_, int d_);
	THeap(T* keys_, int size_, int maxsize_, int d_);
	THeap(const THeap& heap);
	~THeap();

	// ���������������� ���������
	void Transposition(int i, int j);
	// �������� ��������
	void MoveUp(int i);
	// ������� ������������ �������
	int GetMinChild(int i);
	// ���������� ��������
	void MoveDown(int i);
	// ������� ������������ ��-��
	T GetMinKey();

	bool Empty() const;

	// ����������
	void Heaping();

	friend class DijkstrasAlgorithm;
};

template <typename T>
THeap<T>::THeap(int maxsize_, int d_)
{
	maxsize = maxsize_;
	d = d_;
	size = 0;
	keys = new T[maxsize];
}

template <typename T>
THeap<T>::THeap(T* keys_, int size_, int maxsize_, int d_)
{
	maxsize = maxsize_;
	d = d_;
	size = size_;
	keys = new T[maxsize];
	for (int i = 0; i < size; i++)
		keys[i] = keys_[i];
}

template <typename T>
THeap<T>::THeap(const THeap& heap)
{
	maxsize = heap.maxsize;
	size = heap.size;
	d = heap.d;
	keys = new T[maxsize];
	for (int i = 0; i < size; i++)
		keys[i] = heap.keys[i];
}

template <typename T>
THeap<T>::~THeap()
{
	d = 0;
	maxsize = 0;
	size = 0;
	delete[] keys;
}

template <typename T>
void THeap<T>::Transposition(int i, int j)
{
	T tmp = keys[i];
	keys[i] = keys[j];
	keys[j] = tmp;
}

template <typename T>
void THeap<T>::MoveUp(int i)
{
	while (i > 0)
	{
		int p = (i - 1) / d; // ���������� ������ ������
		if (keys[p] > keys[i])
		{
			Transposition(p, i);
			i = p;
		}
		else
			break;
	}
}

template <typename T>
int THeap<T>::GetMinChild(int i)
{
	// ���������, ���� ��� ��� ���
	if (i * d + 1 > size - 1)
		return -1;
	// ���� ���, �� ����� ������ ������������ �������
	int c1 = i * d + 1; // 1-�� ������� � ��������� ����
	int c2 = min(i * d + d, size - 1); // ��������� �������
	int c = c1; // ���������� ��� ������������ �������
	for (int j = c + 1; j <= c2; j++)
		if (keys[c] > keys[j])
			c = j;
	return c;
}

template <typename T>
void THeap<T>::MoveDown(int i)
{
	int c = GetMinChild(i);
	while ((c != -1) && (keys[c] < keys[i]))
	{
		Transposition(c, i);
		i = c;
		c = GetMinChild(i);
	}
}

template <typename T>
T THeap<T>::GetMinKey()
{
	Heaping();
	Transposition(0, size - 1);
	T result = keys[size - 1];
	size--;
	MoveDown(0);

	return result;
}

template <typename T>
bool THeap<T>::Empty() const
{
	return (size == 0);
}

template <typename T>
void THeap<T>::Heaping()
{
	for (int i = size - 1; i >= 0; i--)
		MoveDown(i);
}