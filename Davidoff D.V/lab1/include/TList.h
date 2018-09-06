#ifndef TLIST_H
#define TLIST_H
#include "TLink.h"
#include <iostream>
using namespace std;

template <typename T>
class TList
{
private:
	TLink<T>*root;
public:
	TList();
	~TList();
	TList(const TList& a);
	void Add(T key);
	void Add_End(T key);
	void insert_before(T key, T keyNext);
	void insert_after(T key, T keyprev);
	TLink<T> Search(T key);
	void Remove(T key);
	int Size()const;
	TLink<T>* GetRoot()const;
};

template <typename T>
TList<T>::TList()
{
	root = 0;
};

template <typename T>
TList<T>::~TList()
{
	while (root != 0)
	{
		TLink<T>* node = root;
		root = root->pNext;
		delete node;
	}
};

template <typename T>
TList<T>::TList(const TList& a)
{
	if (a.root == 0) return 0;
	TLink<T>*node = a.root;
	root->Key = node->key;
	root->pNext = 0;
	node = node->pNext;
	TLink<T>*tmp = root;
	while (root != 0)
	{
		tmp->pNext = new TLink<T>;
		tmp->pNext->pNext = 0;
		tmp = tmp->pNext;
		node = node->pNext;
	}

}

template <typename T>
void TList<T>::Add(T key)
{
	TLink<T>*n = new TLink<T>;
	n->Key = key;
	n->pNext = root;
	root = n;
};

template <typename T>
void TList<T>::Add_End(T key)
{
	if (root == 0)
	{
		root = new TLink<T>;
		root->key = key;
		root->pNext = 0;
		return;
	}
	while (root->pNext != 0)
	{
		root = root->pNext;
	}
	root->pNext = new TLink<T>;
	root->pNext->key = key;
	root->pNext->pNext = 0;
};

template <typename T>
void TList<T>::insert_before(T key, T keyNext)
{
	if (root == 0)
		return;
	if (root->key == keyNext)
	{
		Add(key);
		return;
	}
	TList<T>*Nroot = root;
	while ((Nroot->pNext != 0) && (Nroot->pNext->key != keyNext))
		Nroot = Nroot->pNext;
	if (Nroot->pNext == 0)
	{
		throw "There is no such key";
	}
	TList<T>*n = new Node;
	n->key = key;
	n->pNext = Nroot->pNext;
	Nroot->pNext = n;
};

template <typename T>
void TList<T>::insert_after(T key, T keyprev)
{
	while (root != 0 && root->key != keyprev)
		root = root->pNext;
	if (root == 0)
	{
		throw "There is no such element";
	}
	TList<T>*n = new Node;
	n->key = key;
	n->pNext = root->pNext;
	root->pNext = n;
};


template <typename T>
TLink<T> TList<T>::Search(T key)
{
	TList<T>*Nroot = root;
	while (Nroot != 0)
	{
		if (Nroot->key == key)
		{
			return Nroot;
		}
		Nroot = Nroot->pNext;
	}
	throw "There is no such element";
};


template <typename T>
void TList<T>::Remove(T key)
{
	if (root == 0) return;
	TLink<T>*node = root;
	if (root->Key == key)
	{
		root = root->pNext;
		delete node;
		return;
	}
	while ((node->pNext != 0) && (node->pNext->Key != key))
		node = node->pNext;
	if (node->pNext == 0)
	{
		throw "There is no such element";
	}
	TLink<T>*node1 = node->pNext;
	node->pNext = node1->pNext;
	delete node1;
};

template <typename T>
TLink<T>* TList<T>::GetRoot()const
{
	return root;
};

template <typename T>
int TList<T>::Size()const
{
	TLink<T>* node = root;
	int count = 0;
	while (node != 0)
	{
		count++;
		node = node->pNext;
	}
	return count;
};


#endif
