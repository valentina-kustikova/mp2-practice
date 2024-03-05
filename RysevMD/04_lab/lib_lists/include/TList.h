#pragma once
#include "TNode.h"

template <typename T>
class TList {
private:
	TNode<T>* pFirst;
	TNode<T>* pCurrent;
	TNode<T>* pLast;
	TNode<T>* pStop;
public:
	TList();
	TList(const TNode<T>* _pFirst);
	TList(const TList<T>& lst);
	~TList();

	TNode<T>* Search(const T& key);
	void insertFirst(const T& key);
	void insertLast(const T& key);
	void insertBefore(const T& old_key, const T& new_key);
	void insertAfter(const T& old_key, const T& new_key);
	void Remove(const T& key);
	void Clear();

	size_t getSize() const;
	bool isFull() const;
	bool isEmpty() const;
};

template <typename T>
TList<T>::TList() {
	pFirst = nullptr;
	pCurrent = nullptr;
	pLast = nullptr;
	pStop = nullptr;
}

template <typename T>
TList<T>::TList(const TNode<T>* _pFirst) {
	pFirst = _pFirst;
	pCurrent = pFirst;
	pStop = nullptr;
	TNode<T>* tmp = _pFirst;
	while (tmp->pNext != pStop) tmp = tmp->pNext;
	pLast = tmp;
}