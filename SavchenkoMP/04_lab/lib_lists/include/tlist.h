#ifndef TLIST_H
#define TLIST_H

#include "tnode.h"

template <typename T>
class TList {
protected:
	TNode<T>* pFirst;
	TNode<T>* pLast;
	TNode<T>* pCurr;
	TNode<T>* pStop;

public:
	TList();
	TList(TNode<T>* _pFirst);
	TList(const TList<T>& obj);
	virtual ~TList();

	virtual TNode<T>* Search(const T& data);
	virtual void InsertFirst(const T& data);
	virtual void InsertLast(const T& data);
	virtual void InsertBefore(const T& data, const T& before);
	virtual void InsertAfter(const T& data, const T& after);
	virtual void InsertBefore(const T& data);
	virtual void InsertAfter(const T& data);
	virtual void Remove(const T& data);
	void Clear();

	size_t GetSize() const;
	bool IsFull() const;
	bool IsEmpty() const;

	void Reset();
	TNode<T>* GetCurrent() const;
	void Next(const int count = 1);
	bool IsEnded() const;

	TNode<T>* first() const;
	TNode<T>* last() const;
	TNode<T>* stop() const;
};

template <typename T>
TList<T>::TList() {
	pStop = nullptr;
	pFirst = pStop;
	pLast = pStop;
	pCurr = pStop;
}

template <typename T>
TList<T>::TList(TNode<T>* _pFirst) {
	pStop = nullptr;
	pFirst = _pFirst;
	if (pFirst == pStop) {
		pLast = pStop;
		pCurr = pStop;
		return;
	}

	TNode<T>* tmp = pFirst;
	while (tmp->pNext != pStop)
		tmp = tmp->pNext;
	pLast = tmp;
}

template <typename T>
TList<T>::TList(const TList<T>& obj) {
	if (obj.pFirst == obj.pStop) {
		pStop = nullptr;
		pFirst = pStop;
		pLast = pStop;
		pCurr = pFirst;
		return;
	}

	pFirst = new TNode<T>(obj.pFirst->key);
	TNode<T>* tmp = obj.pFirst;
	TNode<T>* pNode = pFirst;

	while (tmp->pNext != obj.pStop) {
		pNode->pNext = new TNode<T>(tmp->pNext->key);
		pNode = pNode->pNext;
		tmp = tmp->pNext;
	}
	pLast = pNode;
	pStop = pLast->pNext;
	pCurr = pFirst;
}

template <typename T>
TList<T>::~TList() {
	Clear();
}



template <typename T>
TNode<T>* TList<T>::Search(const T& data) { // if (obj.Search(data) == obj.stop) - NOT FOUND
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

	if (pCurr == pStop) Reset();
}

template <typename T>
void TList<T>::InsertLast(const T& data) {
	if (pFirst == pStop) {
		InsertFirst(data);
		return;
	}
	TNode<T>* tmp = new TNode<T>(data, pStop);
	pLast->pNext = tmp;
	pLast = pLast->pNext;

	if (pCurr == pStop) Reset();
}

template <typename T>
void TList<T>::InsertBefore(const T& data, const T& before) {
	TNode<T>* pBefore = nullptr;
	TNode<T>* pNode = pFirst;

	while (pNode != pStop && pNode->key != before) {
		pBefore = pNode;
		pNode = pNode->pNext;
	}

	if (pNode == pStop) {
		string exp = "Error: key not found";
		throw exp;
	}

	if (pNode == pFirst) {
		InsertFirst(data);
		return;
	}

	TNode<T>* tmp = new TNode<T>(data, pNode);
	pBefore->pNext = tmp;

	if (pCurr == pStop) Reset();
}

template <typename T>
void TList<T>::InsertAfter(const T& data, const T& after) {
	TNode<T>* pNode = Search(after);

	if (pNode == pStop) {
		string exp = "Error: key not found";
		throw exp;
	}

	if (pNode == pLast) {
		InsertLast(data);
		return;
	}

	TNode<T>* tmp = new TNode<T>(data, pNode->pNext);
	pNode->pNext = tmp;

	if (pCurr == pStop) Reset();
}


/////////////////////////////////
template <typename T>
void TList<T>::InsertBefore(const T& data) {
	if (pCurr == pStop) {
		string exp = "Error: pCurrent is not installed, use Reset() and Next()";
		throw exp;
	}
	
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
	if (pCurr == pStop) {
		string exp = "Error: pCurrent is not installed, use Reset() and Next()";
		throw exp;
	}

	if (IsEnded()) {
		InsertLast(data);
		return;
	}

	TNode<T>* tmp = new TNode<T>(data, pCurr->pNext);
	pCurr->pNext = tmp;
}
/////////////////////////////////

template <typename T>
void TList<T>::Remove(const T& data) {
	if (pFirst == pStop) {
		string exp = "Error: list is empty";
		throw exp;
	}

	TNode<T>* pNode = pFirst, *pPrev = nullptr;
	while (pNode->pNext != pStop && pNode->key != data) {
		pPrev = pNode;
		pNode = pNode->pNext;
	}

	if (pNode->pNext == pStop && pNode->key != data) {
		string exp = "Error: key not found";
		throw exp;
	}

	if (pCurr == pNode) Reset();

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
	pLast = pStop;
	pCurr = pStop;
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
	if (tmp != pStop) {
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
void TList<T>::Next(const int count) {
	if (count <= 0) {
		string exp = "Error: count can't be less than 0";
		throw exp;
	}

	for (int i = 0; i < count; i++) {
		if (!IsEnded() || pCurr != pStop) pCurr = pCurr->pNext;
		else Reset();
	}
}

template <typename T>
bool TList<T>::IsEnded() const {
	if (pCurr == pStop) return true;
	//if (pCurr->pNext == pStop) return true;
	else return false;
}

template <typename T>
TNode<T>* TList<T>::first() const {
	return pFirst;
}
template <typename T>
TNode<T>* TList<T>::last() const {
	return pLast;
}
template <typename T>
TNode<T>* TList<T>::stop() const {
	return pStop;
}

#endif // !TLIST_H
