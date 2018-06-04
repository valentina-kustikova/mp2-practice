#pragma once
#include <iostream>
#include "link.h"
using namespace std;

template <typename T>
class list
{
private:

	link<T>*root;
public:
	list();
	~list();
	list(const list& a);
	void Add(T key);
	void Add_End(T key);
	void insert_before(T key, T keyNext);
	void insert_after(T key, T keyprev);
	link<T> Search(T key)  const; // tip 
	void Remove(T key);
	int Size() const ;//cons
	link<T>* GetRoot() const ;
};

template <typename T>
list<T>::list()
{
	root = 0;
};

template <typename T>
list<T>::~list()
{
	delete root;
};

template <typename T>
list<T>::list(const list& a)
{
	if (a.root == 0) return 0;
	link<T>*node = a.root;
	root->Key = node->key;
	root->pNext = 0;
	node = node->pNext;
	link<T>*tmp = root;
	while (root != 0)
	{
		tmp->pNext = new link<T>;
		tmp->pNext->pNext = 0;
		tmp = tmp->pNext;
		node = node->pNext;
	}

}

template <typename T>
void list<T>::Add(T key)
{
	link<T>* n = new link<T>;
	n->Key = key;
	n->pNext = root;
	root = n;
};

template <typename T>
void list<T>::Add_End(T key)
{
	if (root == 0)
	{
		root = new link<T>;
		root->key = key;
		root->pNext = 0;
		return;
	}
	while (root->pNext != 0)
	{
		root = root->pNext;
	}
	root->pNext = new link<T>;
	root->pNext->key = key;
	root->pNext->pNext = 0;
};

template <typename T>
void list<T>::insert_before(T key, T keyNext)
{
	if (root == 0)
		return;
	if (root->key == keyNext)
	{
		Add(key);
		return;
	}
	list<T>*Nroot = root;
	while ((Nroot->pNext != 0) && (Nroot->pNext->key != keyNext))
		Nroot = Nroot->pNext;
	if (Nroot->pNext == 0)
	{
		throw "There is no such key";
	}
	list<T>*n = new Node;
	n->key = key;
	n->pNext = Nroot->pNext;
	Nroot->pNext = n;
};

template <typename T>
void list<T>::insert_after(T key, T keyprev)
{
	while (root != 0 && root->key != keyprev)
		root = root->pNext;
	if (root == 0)
	{
		throw "There is no such element";
	}
	list<T>*n = new Node;
	n->key = key;
	n->pNext = root->pNext;
	root->pNext = n;
};


template <typename T>
link<T> list<T>::Search(T key) const
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
void list<T>::Remove(T key)
{
	if (root == 0) return;
	link<T>*node = root;
	if (root->Key = key)
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
	link<T>*node1 = node->pNext;
	node->pNext = node1->pNext;
	delete node1;
};

template <typename T>
link<T>* list<T>::GetRoot() const
{
	return root;
};

template <typename T>
int list<T>::Size() const
{
	link<T>* node = root;
	int count = 0;
	while (node != 0)
	{
		count++;
		node = node->pNext;
	}
	return count;
};

