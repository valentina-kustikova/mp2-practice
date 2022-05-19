#pragma once

#include "node.h"
#include "list.h"

template <class T>
class HeadList : public List<T>
{
protected:
	Node<T>* head;
public:
	HeadList();
	~HeadList();
	virtual void InsertToHead(const T& elem);
	virtual void DeleteFirst();
};

template<class T>
HeadList<T>::HeadList()
{
	head = new Node<T>;
	head->next = List<T>::first;
}

template<class T>
HeadList<T>::~HeadList()
{
	delete head;
}

template <class T>
void HeadList<T>::InsertToHead(const T& elem)
{
	List<T>::InsertToHead(elem);
	head->next = List<T>::first;
}

template <class T>
void HeadList<T>::DeleteFirst()
{
	
	List<T>::DeleteFirst();
	head->next = List<T>::first;
}