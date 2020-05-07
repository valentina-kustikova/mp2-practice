#ifndef THEAP_H    
#define THEAP_H

#include "Exception.h"
#include<iostream>

template<typename T>
class THeap
{
private:
	int d;
	int size;
	int max_size;
	T* keys;
	int MinChild(int NodeKey)const;
public:
	THeap(int d, int max_size);
	THeap(int d, int max_size, int size, T* keys);
	THeap(const THeap& h);
	~THeap() {};
	void Transposition(int i, int j);
	void Emersion(int NodeKey);
	void  Immersion(int NodeKey);
	void Hilling();
	void RemoveMin();
	T GetRoot()const;
	int GetSize()const;

	friend std::ostream& operator <<(std::ostream& out, const THeap<T>& heap)
	{
		for (int i = 0; i < heap.size; i++)
		{
			out << "Key = " << heap.keys[i] << endl;
		}
		return out;
	}
};

template<typename T>
THeap<T> ::THeap(int d, int max_size)
{
	this->d = d;
	this->max_size = max_size;
	keys = new T[max_size];
	size = 0;
}

template<typename T>
THeap<T> ::THeap(int d, int max_size, int size, T* _keys)
{
	this->d = d;
	this->max_size = max_size;
	this->size = size;
	keys = _keys;
}

template<typename T>
THeap<T> ::THeap(const THeap& h)
{
	d = h.d;
	size = h.size;
	max_size = h.max_size;
	keys = new T[max_size];
	for (int i = 0; i < size; i++)
		keys[i] = h.keys[i];
}

template<typename T>
int THeap<T> ::MinChild(int NodeKey)const
{
	if (NodeKey * d + 1 >= size)
		return -1;
	int c1 = NodeKey * d + 1;
	int c2 = (NodeKey * d + d < size - 1) ? (NodeKey * d + d) : (size - 1);
	int c = c1;
	for (int i = c1 + 1; i <= c2; i++)
	{
		if (keys[c] > keys[i])
			c = i;
	}
	return c;
}

template<typename T>
void THeap<T> ::Transposition(int i, int j)
{
	if (i >= size || j >= size || i < 0 || j < 0)
		throw M_Exeption("accessing an invalid index");
	T tmp = keys[i];
	keys[i] = keys[j];
	keys[j] = tmp;
}

template<typename T>
void THeap<T> ::Immersion(int NodeKey)
{
	int c = MinChild(NodeKey);
	while (c != -1 && keys[c] < keys[NodeKey])
	{
		Transposition(c, NodeKey);
		NodeKey = c;
		c = MinChild(NodeKey);
	}
}

template<typename T>
void THeap<T> ::Hilling()
{
	for (int i = size - 1; i >= 0; i--)
		Immersion(i);
}

template<typename T>
T THeap<T> ::GetRoot()const
{
	return keys[0];
}

template<typename T>
int THeap<T> ::GetSize()const
{
	return size;
}

template<typename T>
void THeap<T> ::RemoveMin()
{
	Transposition(0, size - 1);
	size--;
	Immersion(0);
}

template<typename T>
void THeap<T> ::Emersion(int NodeKey)
{
	while (NodeKey > 0)
	{
		int p = (NodeKey - 1) / d;
		if (keys[p] > keys[NodeKey])
		{
			Transposition(p, NodeKey);
			NodeKey = p;
		}
		else
			break;
	}
}

#endif
