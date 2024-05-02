#ifndef __LIST_H__
#define __LIST_H__

#include "tnode.h"

#include <iostream>

using namespace std;

template <typename ValueType>
class TList {
protected:
	TNode<ValueType>* pFirst;
	TNode<ValueType>* pLast;
	TNode<ValueType>* pCurr;
	TNode<ValueType>* pStop;
public:
	TList();
	TList(const TList<ValueType>& list);
	TList(TNode<ValueType>* pNode);
	virtual ~TList();
	TNode<ValueType>* Search(const ValueType& data);
	TNode<ValueType>* GetCurrent() const;
	virtual void InsertFirst(const ValueType& data);
	virtual void InsertLast(const ValueType& data);
	void InsertBefore(const ValueType& who, const ValueType& before_whom);
	void InsertAfter(const ValueType& who, const ValueType& after_whom);
	virtual void Remove(const ValueType& data);
	virtual void Clear();
	void Next();
	void Reset();
	void Sort();
	virtual bool IsEnded() const;
	bool IsEmpty() const;
	bool IsFull() const;
	friend istream& operator>>(istream& in, TList<ValueType>& list) {
		int count;
		cout << "Enter the number of list elements: ";
		in >> count;
		ValueType elem;
		cout << "Enter list items: ";
		for (int i = 0; i < count; i++) {
			in >> elem;
			list.InsertLast(elem);
		}
		return in;
	};
	friend ostream& operator<<(ostream& out, const TList<ValueType>& list) {
		TNode<ValueType>* pNode = list.pFirst;
		if (list.IsEmpty()) {
			throw exception("List is empty");
		}
		while (pNode != list.pStop) {
			out << pNode->data << " ";
			pNode = pNode->pNext;
		}
		return out;
	};
};

template <typename ValueType>
TList<ValueType>::TList() {
	pFirst = nullptr;
	pLast = nullptr;
	pCurr = nullptr;
	pStop = nullptr;
};

template <typename ValueType>
TList<ValueType>::TList(const TList<ValueType>& list) {
	if (list.IsEmpty()) {
		pFirst = nullptr;
		pLast = nullptr;
		pCurr = nullptr;
		pStop = nullptr;
		return;
	}
	pFirst = new TNode<ValueType>(list.pFirst->data);
	TNode<ValueType>* tmp = pFirst;
	TNode<ValueType>* ltmp = list.pFirst->pNext;
	while (ltmp != list.pStop) {
		tmp->pNext = new TNode<ValueType>(ltmp->data);
		tmp = tmp->pNext;
		ltmp = ltmp->pNext;
	}
	pLast = tmp;
	pCurr = pFirst;
	pStop = nullptr;
};

template <typename ValueType>
TList<ValueType>::TList(TNode<ValueType>* pNode) {
	pFirst = pNode;
	TNode<ValueType>* tmp = pNode;
	while (tmp->pNext != nullptr)
		tmp = tmp->pNext;
	pLast = tmp;
	pCurr = pFirst;
	pStop = nullptr;
};

template <typename ValueType>
TList<ValueType>::~TList() {
	Clear();
};

template <typename ValueType>
TNode<ValueType>* TList<ValueType>::Search(const ValueType& data) {
	TNode<ValueType>* curr = pFirst;
	while (curr->pNext != pStop && curr->data != data) {
		curr = curr->pNext;
	}
	if (curr->pNext == pStop && curr->data != data)
		return nullptr;
	return curr;
};

template <typename ValueType>
TNode<ValueType>* TList<ValueType>::GetCurrent() const {
	return pCurr;
};

template <typename ValueType>
void TList<ValueType>::InsertFirst(const ValueType& data) {
	TNode<ValueType>* new_first = new TNode<ValueType>(data, pFirst);
	pFirst = new_first;
	if (pLast == nullptr) {
		pLast = pFirst;
	}
	pCurr = pFirst;
};

template <typename ValueType>
void TList<ValueType>::InsertLast(const ValueType& data) {
	if (IsEmpty()) {
		InsertFirst(data);
		return;
	}
	TNode<ValueType>* new_last = new TNode<ValueType>(data, pStop);
	pLast->pNext = new_last;
	pLast = new_last;
	pCurr = new_last;
};

template <typename ValueType>
void TList<ValueType>::InsertBefore(const ValueType& who, const ValueType& before_whom) {
	TNode<ValueType>* prev = nullptr;
	TNode<ValueType>* curr = pFirst;
	while (curr != pStop && curr->data != before_whom) {
		prev = curr;
		curr = curr->pNext;
	}
	if (curr == pStop) {
		throw exception("no such element");
	}
	if (prev == nullptr) {
		InsertFirst(who);
		return;
	}
	TNode<ValueType>* new_node = new TNode<ValueType>(who, curr);
	prev->pNext = new_node;
};

template <typename ValueType>
void TList<ValueType>::InsertAfter(const ValueType& who, const ValueType& after_whom) {
	TNode<ValueType>* pWhere = Search(after_whom);
	if (pWhere == nullptr) {
		throw exception("no such element");
	}
	if (pWhere == pLast) {
		InsertLast(who);
		return;
	}
	TNode<ValueType>* new_node = new TNode<ValueType>(who, pWhere->pNext);
	pWhere->pNext = new_node;
};

template <typename ValueType>
void TList<ValueType>::Remove(const ValueType& data) {
	TNode<ValueType>* prev = pStop;
	TNode<ValueType>* curr = pFirst;
	while (curr != pStop && curr->data != data) {
		prev = curr;
		curr = curr->pNext;
	}
	if (curr == pStop) {
		throw exception("no such element");
	}
	if (curr == pFirst) {
		pFirst = pFirst->pNext;
		delete curr;
		return;
	}
	if (curr == pLast) {
		prev->pNext = pStop;
		delete curr;
		return;
	}
	prev->pNext = curr->pNext;
	curr->pNext = nullptr;
	delete curr;
};

template <typename ValueType>
void TList<ValueType>::Clear() {
	if (pFirst == nullptr)
		return;
	TNode<ValueType>* curr = pFirst;
	TNode<ValueType>* next = pFirst->pNext;
	while (next != pStop) {
		delete curr;
		curr = next;
		next = curr->pNext;
	}
	delete curr;
	pCurr = pStop;
	pFirst = nullptr;
	pLast = nullptr;
};

template <typename ValueType>
void TList<ValueType>::Next() {
	if (pCurr == pStop)
		throw exception("end of the list");
	pCurr = pCurr->pNext;
};

template <typename ValueType>
void TList< ValueType>::Reset() {
	pCurr = pFirst;
};

template <typename ValueType>
void TList< ValueType>::Sort() {
	TNode<ValueType>* node1 = pFirst;
	while (node1->pNext != pStop) {
		TNode<ValueType>* node2 = node1->pNext;
		while (node2 != pStop) {
			if (node1->data < node2->data) {
				ValueType tmp = node1->data;
				node1->data = node2->data;
				node2->data = tmp;
			}
			node2 = node2->pNext;
		}
		node1 = node1->pNext;
	}
}

template <typename ValueType>
bool TList<ValueType>::IsEmpty()const {
	return pFirst == nullptr;
};

template <typename ValueType>
bool TList<ValueType>::IsFull()const {
	TNode<ValueType>* tmp = new TNode<ValueType>();
	if (tmp == nullptr)
		return true;
	delete tmp;
	return false;
};

template <typename ValueType>
bool TList<ValueType>::IsEnded()const {
	return pCurr == pStop;
};

#endif