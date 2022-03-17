#pragma once;
#include "node.h"

template <typename T>
class TList {
private:
	TNode <T> *head;
	TNode <T> *current;
public:
	TList();
	TList(const TList <T> &);
	~TList();
	void Insert(const T _data);
	void InsertInEnd(const T _data);
	void Reset();
	void Clean();
	void Delete(const T & d);
	bool IsEnded() const;
	
	bool operator==(const TList<T>& List) const;
	bool operator!=(const TList<T>& List) const { return !((*this) == List); }
	TList<T>& operator=(const TList<T>& List);
	TNode<T>* GetNext();
	TNode<T>* Search(const TNode<T>& d);
	TNode<T>* GetCurrent() { return current; }
};

template <typename T>
TList<T>::TList()
{
	head = new TNode<T>();
	head->pNext = head;
	current = head;
};

template <typename T>
TList<T>::TList(const TList <T>& List)
{
	if (List.head->pNext != List.head)
	{
		head = new TNode<T>(List.head->data);
		TNode<T>* temp = head;
		TNode<T>* temp2 = List.head->pNext;
		while (temp2 != List.head)
		{
			temp->pNext = new TNode<T>(temp2->data, head);
			temp = temp->pNext;
			temp2 = temp2->pNext;
		}
	}
	else {
		head = new TNode<T>(List.head->data);
		current = head;
		head->pNext = head;
	}
};

template<typename T>
TList<T>::~TList()
{
	Clean();
	delete head;
};

template <typename T>
void TList<T>::Insert(const T _data)
{
	if (head->pNext == head)
	{
		TNode<T>* tmp = new TNode<T>(_data, head);
		head->pNext = tmp;
	}
	else
	{
		TNode<T>* prev = head;
		TNode<T>* tmp = head->pNext;
		while ((tmp != head) && (_data < tmp->data))
		{
			prev = tmp;
			tmp = tmp->pNext;
		}
		prev->pNext = new TNode<T>(_data, tmp);
	}
};

template <typename T>
void TList<T>::InsertInEnd(const T _data)
{
	TNode<T>* tmp = head;
	while (tmp->pNext != head)
		tmp = tmp->pNext;
	tmp->pNext = new TNode<T>(_data, head);
};

template <typename T>
void TList<T>::Reset()
{
	current = head->pNext;
};

template<typename T>
void TList<T>::Clean()
{
	TNode<T>* temp = head->pNext;
	TNode<T>* temp2 = head;
	while (temp != head)
	{
		temp2 = temp->pNext;
		delete temp;
		temp = temp2;
	}

	head->pNext = head;
};

template<typename T>
void TList<T>::Delete(const T& d)
{
	TNode<T>* tmp = head;
	TNode<T>* tmp2 = head->pNext;
	if (tmp != tmp2)
	{
		while ((tmp2->pNext != head) && (tmp2->data != d))
		{
			tmp = tmp2;
			tmp2 = tmp2->pNext;
		}
		if (tmp2->data == d)
		{
			tmp->pNext = tmp2->pNext;
			delete tmp2;
		}
		else throw "element not in the list";
	}
	else throw "element not in the list";
};

template<typename T>
bool TList<T>::IsEnded() const
{
	return (current == head);
};

template<typename T>
bool TList<T>::operator==(const TList<T>& List) const
{
	TNode<T>* temp = head;
	TNode<T>* temp2 = List.head;
	bool f = true;
	if ((temp->pNext == head) && (temp2->pNext == List.head))
		f = true;
	else if (((temp->pNext != head) && (temp2->pNext == List.head)) || ((temp2->pNext != List.head) && (temp->pNext == head)))
		f = false;
	while ((temp->pNext != head) && (temp2->pNext != List.head) && (f))
	{
		if (temp->data != temp2->data)
			f = false;
		temp = temp->pNext;
		temp2 = temp2->pNext;
	}
	return f;
};

template<typename T>
TList<T>& TList<T>::operator=(const TList<T>& List)
{

	if ((*this) != List)
	{
		Clean();
		if (List.head->pNext != List.head)
		{
			head = new TNode<T>(List.head->data);
			TNode<T>* temp = head;
			TNode<T>* temp2 = List.head->pNext;
			while (temp2 != List.head)
			{
				temp->pNext = new TNode<T>(temp2->data, head);
				temp = temp->pNext;
				temp2 = temp2->pNext;
			}
		}
		else {
			head = new TNode<T>(List.head->data);
			current = head;
			head->pNext = head;
		}
	}
	return *this;
};

template <typename T>
TNode<T>* TList<T>::GetNext()
{
	current = current->pNext;
	return current;
};

template <typename T>
TNode<T>* TList<T>::Search(const TNode<T>& d)
{
	TNode<T>* tmp = head;
	while ((tmp->pNext != head) && (tmp->pNext->data != d.data))
	{
		tmp = tmp->pNext;
	}
	if (tmp->pNext == head)
	{
		return nullptr;
	}
	return tmp->pNext;
};