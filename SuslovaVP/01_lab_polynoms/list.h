#pragma once
#include "node.h"
#include <iostream>

using namespace std;

template<class DataType>
class List
{
private:
	Node<DataType>* head;
	Node<DataType>* curr;
public:
	List();
	~List();
	void Clean();
	List(const List<DataType>& l);
	const List<DataType>& operator=(const List<DataType>& l);
	void InsertCList(const DataType& d);
	void InsertToTail(const DataType d);
	bool operator==(const List<DataType>& l) const;
	bool operator!=(const List<DataType>& l) const;
	void First() { curr = head->next; }
	void Change() { curr = curr->next; }
	bool End() const { return curr == head; }
	bool Empty() const { return (head->next == head); }
	bool Full() const { return(head->next != head); }
	DataType& GetCurr() const { return curr->data; }
};

template <class DataType>
void List<DataType>::Clean()
{
	Node<DataType>* curr = head->next;
	while (curr != head)
	{
		Node<DataType>* tmp = curr->next;
		delete curr;
		curr = tmp;
	}
	head->next = head;
}

template <class DataType>
List<DataType>::List()
{
	head = new Node<DataType>();
	curr = head->next;
	head->next = head;
}

template <class DataType>
List<DataType>::~List()
{
	Clean();
	delete head;
}

template <class DataType>
List<DataType>::List(const List<DataType>& l)
{
	head = new Node<DataType>;
	Node<DataType>* A = l.head;
	Node<DataType>* B = head;
	if (A->next == l.head)
	{
		head->next = head;
		return;
	}
	while (A->next != l.head)
	{
		A = A->next;
		B->next = new Node<DataType>(A->data);
		B = B->next;
	}
	B->next = head;
	curr = head->next;
}

template <class DataType>
const List<DataType>& List<DataType>::operator=(const List<DataType>& l)
{
	Clean();
	Node<DataType>* tmp = l.head;
	Node<DataType>* tmp2 = head;
	while (tmp->next != l.head)
	{
		tmp = tmp->next;
		tmp2->next = new Node<DataType>(tmp->data);
		tmp2 = tmp2->next;
	}
	tmp2->next = head;
	curr = head->next;
	return *this;
}

template <class DataType>
void List<DataType>::InsertCList(const DataType& d)
{
	if (Empty())
	{
		head->next = new Node<DataType>(d);
		head->next->next = head;
	}
	else
	{
		Node<DataType>* tmp = new Node<DataType>(d);
		Node<DataType>* curr = head;

		while ((*(curr->next) < *tmp) && curr->next != head)
			curr = curr->next;
		Node<DataType>* tmp2 = curr->next;
		curr->next = tmp;
		curr->next->next = tmp2;
	}
}

template<class DataType>
inline void List<DataType>::InsertToTail(const DataType d)
{
	First();
	while (curr->next != head)
	{
		Change();
	}
	Node<DataType>* tmp = curr->next;
	curr->next = new Node<DataType>(d);
	curr->next->next = tmp;
}

template<class DataType>
bool List<DataType>::operator==(const List<DataType>& l) const
{
	bool k = true;
	if (this != &l)
	{
		Node<DataType>* tmp = l.head->next;
		Node<DataType>* tmp2 = head->next;
		while (tmp->data == tmp2->data && tmp2 != head && tmp != l.head)
		{
			tmp = tmp->next;
			tmp2 = tmp2->next;
		}
		if (tmp != l.head || tmp2 != head)
			k = false;
	}
	return k;
}

template<class DataType>
inline bool List<DataType>::operator!=(const List<DataType>& l) const
{
	return !(*this == l);
}
