#pragma once
#include"PQueue.h"
#include"btree.h"

template <typename T>
class BQueue : public PQueue <T>
{
private:
	btree<T> *tree;
public:
	BQueue();
	virtual ~BQueue() { delete tree; };

	virtual void push(const T& a);
	virtual void pop();
	virtual bool isEmpty();
	virtual T top();
	virtual int GetSize();
	int operator==(const BQueue<T>&)const;
};

template <typename T>
BQueue<T>::BQueue()
{
	tree = new btree<T>;
}

template<typename T>
void BQueue<T>::push(const T& a)
{
	Node<T> *tmp = new Node<T>(a);
	tree->insert(tree->root, tmp);
}
template<typename T>
void BQueue<T>::pop()
{
	tree->remove(tree->root, tree->root->key);
}
template<typename T>
bool BQueue<T>::isEmpty()
{ 
	return tree->getsize() == 0; 
}

template<typename T>
inline T BQueue<T>::top()
{
	return tree->root->key;
}

template<typename T>
inline int BQueue<T>::GetSize()
{
	 return tree->getsize();
}

template <typename T>
int BQueue<T>::operator==(const BQueue<T>& a)const
{
	return *tree == *a.tree;
}