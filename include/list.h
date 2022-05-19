#pragma once
#include "node.h"
#include <iostream>

using namespace std;

template<class T>
class List
{
protected:

	Node<T>* first;
	Node<T>* curr;

public:

	List(); 
	List(const List<T>& l); 
	~List(); 

	Node<T>* Search(const T& elem);
	virtual void InsertToHead(const T& elem);
	void InsertInOrder(const T& elem);
	void InsertToTail(const T& elem); 
	void InsertAfter(T* const d, T* const after_d);
	void InsertBefore(T* const d, T* const before_d);
	virtual void DeleteFirst();
	void Delete(const T& elem); 
	void Clean();

	void Reset() { curr = first->next; }
	void Next() { curr = curr->next; }
	bool isEnd() const { return curr == first; }
	bool isEmpty() const { return (first->next == first); }
	T& GetCurr() const { return curr->data; }
	T Head() { return first->next->data; };
	Node<T>* GetHead() { return first->next; };

	const List<T>& operator=(const List<T>& l);
	bool operator==(const List<T>& l) const; 
	bool operator!=(const List<T>& l) const;

	friend std::ostream& operator<<(std::ostream& os, const List<T>& l)
	{
		List<T> list(l);
		list.Reset();
		Node<T>* tmp = list.Next();
		while (!list.isEnd())
		{
			cout << tmp->data;
			tmp = list.Next();
			if (!list.isEnd())
				cout << "+";
		}
		cout << endl;
		return os;
	};
};
template <class T>
List<T>::List()
{
	first = new Node<T>;
	first->next = first;
	curr = first;
}
template <class T>
List<T>::List(const List<T>& l)
{
	first = new Node<T>();
	Node<T>* tmp1 = l.first;
	Node<T>* tmp2 = first;
	if (tmp1->next == l.first)
	{
		first->next = first;
		return;
	}
	while (tmp1->next != l.first)
	{
		tmp1 = tmp1->next;
		tmp2->next = new Node<T>(tmp1->data);
		tmp2 = tmp2->next;
	}
	tmp2->next = first;
	curr = first->next;
}
template <class T>
List<T>::~List()
{
	Clean();
	delete first;
}
template <class T>
Node<T>* List<T>::Search(const T& elem)
{
	Node<T>* tmp = first->next;
	while (tmp != nullptr)
	{
		if (tmp->data == elem)
		{
			return tmp;
		}
		tmp = tmp->next;
	}
	return nullptr;
}
template <class T>
void List<T>::InsertToHead(const T& elem)
{
	Node<T>* node = new Node<T>(elem, first->next);
	first->next = node;
}
template <class T>
void List<T>::InsertInOrder(const T& elem)
{
	if (isEmpty())
	{
		first->next = new Node<T>(elem);
		first->next->next = first;
	}
	else
	{
		Node<T>* tmp = new Node<T>(elem);
		Node<T>* curr = first;

		while ((*(curr->next) < *tmp) && curr->next != first)
			curr = curr->next;
		Node<T>* tmp2 = curr->next;
		curr->next = tmp;
		curr->next->next = tmp2;
	}
}
template<class T>
inline void List<T>::InsertToTail(const T& elem)
{
	Reset();
	while (curr->next != first)
	{
		Next();
	}
	Node<T>* tmp = curr->next;
	curr->next = new Node<T>(elem);
	curr->next->next = tmp;
}
template <class T>
void List<T>::InsertAfter(T* const d, T* const after_d)
{
	Node<T>* elem = Search(d);
	if (elem != NULL)
	{
		Node<T>* new_elem = new Node<T>(after_d, elem->next);
		elem->next = new_elem;
	}
}
template <class T>
void List<T>::InsertBefore(T* const d, T* const before_d)
{
	Node<T>* elem = Search(d);
	if (elem != NULL)
	{
		Node<T>* tmp = curr;
		Node<T>* new_elem = new Node<T>(before_d, elem);
		tmp->next = new_elem;
	}
}
template <class T>
void List<T>::DeleteFirst()
{
	if (first->next != first)
	{
		Node<T>* tmp = first;
		first = tmp->next;
		delete tmp;
	}
}
template <class T>
void List<T>::Delete(const T& elem)
{
	Node<T>* del;
	Node<T>* tmp = first->next;
	if (tmp != nullptr)
	{
		if (tmp->data == elem)
		{
			del = tmp->next;
			delete first->next;
			first->next = del;
		}
		else
		{
			while (tmp->next)
			{
				if (tmp->next->data == elem)
				{
					del = tmp->next;
					break;
				}
				tmp = tmp->next;
			}
			if (tmp->next)
			{
				tmp->next = del->next;
				delete del;
			}
		}
	}
}
template <class T>
void List<T>::Clean()
{
	Node<T>* curr = first->next;
	while (curr != first)
	{
		Node<T>* tmp = curr->next;
		delete curr;
		curr = tmp;
	}
	first->next = first;
}
template <class T>
const List<T>& List<T>::operator=(const List<T>& l)
{
	Clean();
	Node<T>* tmp = l.first;
	Node<T>* tmp2 = first;
	while (tmp->next != l.first)
	{
		tmp = tmp->next;
		tmp2->next = new Node<T>(tmp->data);
		tmp2 = tmp2->next;
	}
	tmp2->next = first;
	curr = first->next;
	return *this;
}
template<class T>
bool List<T>::operator==(const List<T>& l) const
{
	bool k = true;
	if (this != &l)
	{
		Node<T>* tmp = l.first->next;
		Node<T>* tmp2 = first->next;
		while (tmp->data == tmp2->data && tmp2 != first && tmp != l.first)
		{
			tmp = tmp->next;
			tmp2 = tmp2->next;
		}
		if (tmp != l.first || tmp2 != first)
			k = false;
	}
	return k;
}
template<class T>
inline bool List<T>::operator!=(const List<T>& l) const
{
	return !(*this == l);
}