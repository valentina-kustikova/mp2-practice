#pragma once
#include "TNode.h"
#include <iostream>

template <typename T>
class TList {
protected:
	TNode<T>* pFirst;
	TNode<T>* pCurrent;
	TNode<T>* pLast;
	TNode<T>* pStop;
public:
	TList();
	TList(TNode<T>* _pFirst);
	TList(const TList<T>& lst);
	virtual ~TList();

	TNode<T>* Search(const T& key) const;
	virtual void insertFirst(const T& key);
	void insertLast(const T& key);
	void insertBefore(const T& key);
	void insertBefore(const T& old_key, const T& new_key);
	void insertAfter(const T& key);
	void insertAfter(const T& old_key, const T& new_key);
	virtual void Remove(const T& key);
	virtual void Clear();

	size_t getSize() const;
	TNode<T>* getCurrent() const;
	TNode<T>* getFirst() const;
	TNode<T>* getLast() const;
	TNode<T>* getStop() const;
	bool isFull() const;
	bool isEmpty() const;

	virtual void Next();
	void Reset();

	friend std::ostream& operator << (std::ostream& out, TList<T>& lst) {
		lst.Reset();
		while (lst.getCurrent() != lst.getStop()) {
			out << lst.getCurrent()->key << " ";
			lst.Next();
		}
		return out;
	}
};

template <typename T>
TList<T>::TList() {
	pFirst = nullptr;
	pCurrent = nullptr;
	pLast = nullptr;
	pStop = nullptr;
}

template <typename T>
TList<T>::TList(TNode<T>* _pFirst) {
	if (_pFirst == nullptr) return;
	pFirst = new TNode<T>(_pFirst);
	TNode<T>* tmp1 = _pFirst;
	TNode<T>* tmp2 = pFirst;
	while (tmp1->pNext != nullptr) {
		tmp2->pNext = new TNode<T>(tmp1->pNext->key);
		tmp1 = tmp1->pNext;
		tmp2 = tmp2->pNext;
	}
	pLast = tmp2;
	pCurrent = pFirst;
	pStop = pLast->pNext;
}

template <typename T>
TList<T>::TList(const TList<T>& lst) {
	if (lst.pFirst == nullptr) return;
	pFirst = new TNode<T>(lst.getFirst());
	TNode<T>* tmp1 = lst.getFirst();
	TNode<T>* tmp2 = pFirst;
	while (tmp1->pNext != lst.getStop()) {
		tmp2->pNext = new TNode<T>(tmp1->pNext->key);
		tmp1 = tmp1->pNext;
		tmp2 = tmp2->pNext;
	}
	pLast = tmp2;
	pCurrent = pFirst;
	pStop = pLast->pNext;
}

template <typename T>
TList<T>::~TList() {
	if (pStop != pFirst) Clear();
}

template <typename T>
TNode<T>* TList<T>::Search(const T& key) const{
	TNode<T>* tmp = pFirst;
	while (tmp != pStop && tmp->key != key) tmp = tmp->pNext;
	if (tmp == pStop) tmp = nullptr;
	return tmp;
}

template <typename T>
void TList<T>::insertFirst(const T& key) {
	TNode<T>* tmp = new TNode<T>(key, pFirst);
	if (pFirst == pStop) pLast = tmp;
	pFirst = tmp;
	pCurrent = pFirst;
}

template <typename T>
void TList<T>::insertLast(const T& key) {
	if (pFirst == pStop) {
		insertFirst(key);
		return;
	}
	TNode<T>* tmp = new TNode<T>(key, pStop);
	pLast->pNext = tmp;
	pLast = pLast->pNext;
	pCurrent = pLast;
}

template <typename T>
void TList<T>::insertBefore(const T& key) {
	if (pCurrent == pFirst) {
		insertFirst(key);
		return;
	}
	TNode<T>* tmp = pFirst;
	while (tmp->pNext != pCurrent) tmp = tmp->pNext;
	tmp->pNext = new TNode<T>(key, pCurrent);
	pCurrent = tmp->pNext;
}

template <typename T>
void TList<T>::insertBefore(const T& old_key, const T& new_key) {
	TNode<T>* tmp = pCurrent;
	pCurrent = Search(old_key);
	if (pCurrent == nullptr) throw "ERROR: element not exist";
	insertBefore(new_key);
}

template <typename T>
void TList<T>::insertAfter(const T& old_key, const T& new_key) {
	TNode<T>* tmp = pCurrent;
	pCurrent = Search(old_key);
	if (pCurrent == nullptr) throw "ERROR: element not exist";
	insertAfter(new_key);
}

template <typename T>
void TList<T>::insertAfter(const T& key) {
	if (pCurrent->pNext == pStop) {
		insertLast(key);
		return;
	}
	pCurrent->pNext = new TNode<T>(key, pCurrent->pNext);
	pCurrent = pCurrent->pNext;
}

template <typename T>
void TList<T>::Remove(const T& key) {
	if (pFirst == pStop) throw "ERROR: list is empty";
	TNode<T>* tmp = pFirst, *prev = nullptr;
	while (tmp->pNext != pStop && tmp->key != key) {
		prev = tmp;
		tmp = tmp->pNext;
	}
	if (tmp->pNext == pStop && tmp->key != key) throw "ERROR: element not exist";
	if (prev == nullptr) {
		pFirst = tmp->pNext;
		pCurrent = pFirst;
		delete tmp;
		return;
	}
	if (tmp->pNext == pStop && tmp->key == key) {
		pLast = prev;
	}
	prev->pNext = tmp->pNext;
	pCurrent = prev;
	delete tmp;
	
}

template <typename T>
void TList<T>::Clear() {
	if (pFirst == pStop) throw "ERROR: list already empty";
	TNode<T>* tmp = pFirst;
	while (pFirst != pStop) {
		pFirst = pFirst->pNext;
		delete tmp;
		tmp = pFirst;
	}
	pFirst = nullptr;
	pCurrent = nullptr;
	pStop = nullptr;
}

template <typename T>
size_t TList<T>::getSize() const{
	size_t count = 0;
	TNode<T>* tmp = pFirst;
	while (tmp != pStop) {
		tmp = tmp->pNext;
		count += 1;
	}
	return count;
}

template <typename T>
TNode<T>* TList<T>::getCurrent() const {
	return pCurrent;
}

template <typename T>
TNode<T>* TList<T>::getFirst() const {
	return pFirst;
}

template <typename T>
TNode<T>* TList<T>::getLast() const {
	return pLast;
}

template <typename T>
TNode<T>* TList<T>::getStop() const {
	return pStop;
}

template <typename T>
bool TList<T>::isFull() const {
	TNode<T>* tmp = new TNode<T>();
	return tmp == nullptr;
}

template <typename T>
bool TList<T>::isEmpty() const {
	return pFirst == pStop;
}

template <typename T>
void TList<T>::Next() {
	//if (pCurrent == pLast) return;
	pCurrent = pCurrent->pNext;
}

template <typename T>
void TList<T>::Reset() {
	pCurrent = pFirst;
}