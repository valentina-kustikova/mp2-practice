#pragma once
#include "node.h"
#include "ostream"

template <typename T>
class TList {
protected:
	TNode<T>* first;
	TNode<T>* current;
public:
	TList();
	explicit TList(TNode<T>* _node);
	TList(const TList&);
	~TList();
	bool IsEmpty();
	virtual void InsFirst(const T& _data);
	void InsLast(const T& _data);
	void InsAfter(const T& _data);
	void InsertInEnd(const T& _data);
	void Insert(const T& _data);
	void Reset();
	void Clean();
	void Delete(const T& d);
	virtual void DelFirst();
	void DelLast();
	void DelAfter();
	bool IsEnded() const;
	TNode<T>* get_current() const;

	bool operator==(const TList& List) const;
	bool operator!=(const TList& List) const { return !((*this) == List); }
	TList& operator=(const TList& List);
	TNode<T>* GetNext();
	TNode<T>* Search(const TNode<T>& d);
	TNode<T>* GetCurrent() { return current; };
	friend std::ostream& operator<<(std::ostream& os, TList<T>& l)
	{
		os << "[ ";
		TNode<T>* temp = l.first;

		while (temp != nullptr)
		{
			os << temp->data << " ";
			temp = temp->pNext;
		}
		os << "]";
		return os;
	};
};

template <typename T>
TList<T>::TList()
{
	first = nullptr;
	current = nullptr;
};

template<typename T>
TList<T>::TList(TNode<T>* _node) {
	if (_node) {
		first = new TNode<T>(_node->data, _node->pNext);
		current = first;
	}
}

template <typename T>
TList<T>::TList(const TList<T>& List)
{
	TNode<T>* temp1 = first;
	TNode<T>* temp2 = List.first;

	if (temp2 != nullptr)
	{
		temp1 = new TNode<T>(temp2->data);
		temp2 = temp2->pNext;
		while (temp2 != nullptr) {
			temp1->pNext = new TNode<T>(temp2->data);
			temp1 = temp1->pNext;
			temp2 = temp2->pNext;
		}
	}
};

template<typename T>
TList<T>::~TList()
{
	Clean();
};

template <class T>
bool TList<T>::IsEmpty()
{
	return first == nullptr;
}

template <typename T>
void TList<T>::InsFirst(const T& _data) {
	if (first == nullptr) {
		TNode<T>* tmp = new TNode<T>(_data, first);
		first = tmp;
	}
	else {
		first = new TNode<T>(_data, first);
	}
}

template <typename T>
void TList<T>::InsLast(const T& _data) {
	TNode<T>* tmp = first;
	if (tmp == current)
	{
		InsFirst(_data);
	}
	else {
		while (tmp->pNext != current) {
			tmp = tmp->pNext;
		}
		tmp->pNext = new TNode<T>(_data, tmp->pNext);
	}
}

template <typename T>
void TList<T>::InsAfter(const T& _data) {
	TNode<T>* tmp = first;
	while (tmp != current) {
		tmp = tmp->pNext;
	}
	tmp->pNext = new TNode<T>(_data, tmp->pNext);
}

template <typename T>
void TList<T>::Insert(const T& _data)
{
	if (first == nullptr || _data >= first->data)
	{
		TNode<T>* tmp2 = new TNode<T>(_data, first);
		first = tmp2;
	}
	else
	{
		TNode<T>* tmp = first;
		while (tmp->pNext != nullptr && _data < tmp->pNext->data)
			tmp = tmp->pNext;

		TNode<T>* tmp2 = new TNode<T>(_data, tmp->pNext);
		tmp->pNext = tmp2;
	}
};

template <typename T>
void TList<T>::InsertInEnd(const T& _data)
{
	if (first == nullptr)
	{
		TNode<T>* tmp = new TNode<T>(_data, first);
		first = tmp;
	}
	else {
		TNode<T>* tmp = first;
		while (tmp->pNext != nullptr)
			tmp = tmp->pNext;
		tmp->pNext = new TNode<T>(_data, nullptr);
	}
};

template <typename T>
void TList<T>::Reset()
{
	current = first;
};

template<typename T>
void TList<T>::Clean()
{
	if (first != nullptr) {
		TNode<T>* tmp;
		while (first->pNext != nullptr) {
			tmp = first->pNext;
			first->pNext = tmp->pNext; // head->next->next;
			delete tmp;
		}
		delete first;
		first = nullptr;
	}
};

template<typename T>
void TList<T>::Delete(const T& d)
{
	if (first != nullptr) {
		TNode<T>* prev = first;
		TNode<T>* tmp;
		bool find = false;

		if (first->data == d) {
			first = first->pNext;
			delete prev;
			find = true;
		}

		while (!find && (prev->pNext != nullptr)) {
			if (prev->pNext->data == d) {
				tmp = prev->pNext;
				prev->pNext = prev->pNext->pNext; // tmp->next
				delete tmp;
				find = true;
			}
			else
				prev = prev->pNext;
		}
	}
};

template <typename T>
void TList<T>::DelFirst()
{
	if (first == nullptr)
		throw "element not in the list";
	TNode<T>* tmp = first;
	first = first->pNext;
	delete tmp;
}

template <typename T>
void TList<T>::DelLast()
{
	if (current == nullptr)
		throw "element not in the list";
	if (current == first)
	{
		DelFirst();
		current = first;
	}
	else
	{
		TNode<T>* tmp = current;
		current = current->pNext;
		delete tmp;
	}
}

template <typename T>
void TList<T>::DelAfter()
{
	if (current == nullptr)
		throw "element not in the list";
	if (current == first)
	{
		DelFirst();
		current = first;
	}
	else
	{
		TNode<T>* tmp = current->pNext;
		current->pNext = tmp->pNext;
		delete tmp;
	}
}

template<typename T>
bool TList<T>::IsEnded() const
{
	return (current == nullptr);
};

template<typename T>
bool TList<T>::operator==(const TList<T>& List) const
{
	TNode<T>* temp = first;
	TNode<T>* temp2 = List.first;

	while (temp != nullptr && temp2 != nullptr)
	{
		if (temp->data != temp2->data)
			return false;
		temp = temp->pNext;
		temp2 = temp2->pNext;
	}

	if (temp != nullptr || temp2 != nullptr)
		return false;

	return true;
};

template<typename T>
TList<T>& TList<T>::operator=(const TList<T>& List)
{
	if ((*this) != List)
	{
		if (List.first == nullptr)
			return *this;

		if (first == nullptr)
			first = new TNode<T>();

		TNode<T>* tmp1 = first;
		TNode<T>* tmp2 = List.first;

		tmp1->data = tmp2->data;
		while (tmp1->pNext != nullptr && tmp2->pNext != nullptr)
		{
			tmp1 = tmp1->pNext;
			tmp2 = tmp2->pNext;
			tmp1->data = tmp2->data;
		}

		if (tmp1->pNext == nullptr)
		{
			while (tmp2->pNext != nullptr)
			{
				tmp2 = tmp2->pNext;
				tmp1->pNext = new TNode<T>(tmp2->data, nullptr);
				tmp1 = tmp1->pNext;
			}
		}

		else if (tmp2->pNext == nullptr)
		{
			while (tmp1->pNext != nullptr)
			{
				tmp2 = tmp1->pNext;
				tmp1->pNext = tmp2->pNext;
				delete tmp2;
			}
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
	TNode<T>* tmp = first;
	while (tmp != nullptr && tmp->data != d.data)
		tmp = tmp->pNext;

	return tmp;
};

template<typename T>
TNode<T>* TList<T>::get_current() const {
	return current;
}