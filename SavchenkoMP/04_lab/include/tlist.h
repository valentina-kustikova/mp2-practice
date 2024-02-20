#ifndef TLIST_H
#define TLIST_H

#include "tnode.h"

template <typename T>
class TList {
protected:
	TNode<T>* pFirst;
	TNode<T>* pLast;
	TNode<T>* pCurr;
	//TNode<T>* pPrev;
	TNode<T>* pStop;

public:
	TList();
	TList(const TNode<T>* _pFirst);
	TList(const TList<T>& obj);
	virtual ~TList();

	TNode<T>* Search(const T& data);
	//TNode<T>* Search(const T& data, const TNode<T>* _pPrev);
	void InsertFirst(const T& data);
	void InsertLast(const T& data);
	void InsertBefore(const T& data, const T& before);
	void InsertAfter(const T& data, const T& after);
	void InsertBefore(const T& data);
	void InsertAfter(const T& data);
	void Remove(const T& data);
	void Clear();

	size_t GetSize() const;
	bool IsFull() const;
	bool IsEmpty() const;

	void Reset();
	TNode<T>* GetCurrent() const;
	void Next();
	bool IsEnded() const;
};

template <typename T>
TList<T>::TList() {
	pFirst = nullptr;
	pLast = nullptr;
	pCurr = nullptr;
	pStop = nullptr;
}

template <typename T>
TList<T>::TList(const TNode<T>* _pFirst) {
	pStop = nullptr;
	pFirst = _pFirst;
	pCurr = pFirst;

	TNode<T>* tmp = pFirst;
	while (tmp->pNext != nullptr)
		tmp = tmp->pNext;
	pLast = tmp;
}

template <typename T>
TList<T>::TList(const TList<T>& obj) {
	if (obj.pFirst == nullptr) return; // œ–Œ¬≈–»“‹ Õ¿  Œ––≈ “ÕŒ—“‹

	pFirst = new TNode<T>(obj.pFirst);
	TNode<T>* tmp = pFirst;
	TNode<T>* tmp2 = pFirst;

	while (tmp->pNext != obj.pStop) {
		tmp2->pNext = new TNode<T>(tmp->key);
		tmp2 = tmp2->pNext;
		tmp = tmp->pNext;
	}
	pLast = tmp2;
	pCurr = pFirst;
	pStop = pLast->pNext;
}

template <typename T>
TList<T>::~TList() {
	Clear();
}



template <typename T>
TNode<T>* TList<T>::Search(const T& data) {
	TNode<T>* tmp = pFirst;
	while (tmp != pStop && tmp->key != data)
		tmp = tmp->pNext;
	return tmp;
}

template <typename T>
void TList<T>::InsertFirst(const T& data) {
	TNode<T>* tmp = new TNode<T>(data, pFirst);
	if (pFirst == pStop) pLast = tmp;
	pFirst = tmp;
}

template <typename T>
void TList<T>::InsertLast(const T& data) {
	if (pFirst == pStop) {
		InsertFirst(data);
		return;
	}
	TNode<T>* tmp = new TNode<T>(data);
	pLast->pNext = tmp;
	pLast = pLast->pNext;
}

template <typename T>
void TList<T>::InsertBefore(const T& data, const T& before) {
	TNode<T>* tmpCurr = pCurr;
	pCurr = Search(before);
	InsertBefore(data);
	pCurr = tmpCurr;
}

template <typename T>
void TList<T>::InsertAfter(const T& data, const T& after) {
	TNode<T>* tmpCurr = pCurr;
	pCurr = Search(after);
	InsertAfter(data);
	pCurr = tmpCurr;
}

template <typename T>
void TList<T>::InsertBefore(const T& data) {
	if (pCurr == pFirst) {
		InsertFirst(data);
		return;
	}

	TNode<T>* before = pFirst;
	while (before->pNext != pCurr)
		before = before->pNext;

	TNode<T>* tmp = new TNode<T>(data, pCurr);
	before->pNext = tmp;
}

template <typename T>
void TList<T>::InsertAfter(const T& data) {
	if (IsEnded()) {
		InsertLast(data);
		return;
	}

	TNode<T>* tmp = new TNode<T>(data, pCurr->pNext);
	pCurr->pNext = tmp;
}

template <typename T>
void TList<T>::Remove(const T& data) {
	if (pFirst == pStop) {
		string exp = "Error: list is empty";
		throw exp;
	}

	TNode<T>* pNode = pFirst, pPrev = nullptr;
	while (pNode->pNext != pStop && pNode->key != data) {
		pPrev = pNode;
		pNode = pNode->pNext;
	}

	if (pNode->pNext == pStop && pNode->key != data) {
		string exp = "Error: key not found";
		throw exp;
	}

	if (pPrev == nullptr) {
		pFirst = pNode->pNext;
		delete pNode;
		return;
	}

	pPrev->pNext = pNode->pNext;
	delete pNode;
}

template <typename T>
void TList<T>::Clear() {
	TNode<T>* tmp = pFirst;
	while (pFirst != pStop) {
		pFirst = tmp->pNext;
		delete tmp;
		tmp = pFirst;
	}
	pCurr = pStop;
	pLast = pStop;
}



template <typename T>
size_t TList<T>::GetSize() const {
	size_t size = 0;
	TNode<T>* tmp = pFirst;
	while (tmp != pStop) {
		tmp = tmp->pNext;
		++size;
	}
	return size;
}

template <typename T>
bool TList<T>::IsFull() const {
	TNode<T>* tmp = new TNode<T>;
	if (tmp != nullptr) {
		return false;
	}
	else {
		return true;
	}
}

template <typename T>
bool TList<T>::IsEmpty() const {
	if (pFirst == pStop) return true;
	else return false;
}



template <typename T>
void TList<T>::Reset() {
	pCurr = pFirst;
}

template <typename T>
TNode<T>* TList<T>::GetCurrent() const {
	return pCurr;
}

template <typename T>
void TList<T>::Next() {
	if (!IsEnded()) pCurr = pCurr->pNext;
	else Reset();
}

template <typename T>
bool TList<T>::IsEnded() const {
	if (pCurr->pNext == pStop) return true;
	else return false;
}

#endif // !TLIST_H
