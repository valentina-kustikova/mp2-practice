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
	TList(const TList<T>& list);
	virtual ~TList();

	virtual TNode<T>* Search(const T& data);
	virtual void InsertFirst(const T& data);
	virtual void InsertLast(const T& data);
	virtual void InsertBefore(const T& data);
	virtual void InsertAfter(const T& data);
	virtual void InsertBefore(const T& data, const T& before);
	virtual void InsertAfter(const T& data, const T& after);
	virtual void Remove(const T& data);
	virtual void Clear();

	virtual size_t GetSize() const;
	bool IsFull() const;
	virtual bool IsEmpty() const;

	virtual void Reset();
	TNode<T>* GetCurrent() const;
	virtual void Next(const int count = 1);
	virtual bool IsEnded() const;
	bool IsLast() const;

	TNode<T>* first() const;
	TNode<T>* last() const;
};

template <typename T>
TList<T>::TList() {
	pStop = nullptr;
	pFirst = pStop;
	pLast = pStop;
	pCurr = pStop;

	Reset();
}

template <typename T>
TList<T>::TList(TNode<T>* _pFirst) {
	pStop = nullptr;
	pFirst = _pFirst;
	if (pFirst == pStop) {
		pLast = pStop;
		pCurr = pStop;

		Reset();
		return;
	}

	TNode<T>* tmp = pFirst;
	while (tmp->pNext != pStop)
		tmp = tmp->pNext;
	pLast = tmp;

	Reset();
}

template <typename T>
TList<T>::TList(const TList<T>& obj) {
	if (obj.pFirst == obj.pStop) {
		pStop = nullptr;
		pFirst = pStop;
		pLast = pStop;
		pCurr = pFirst;

		Reset();
		return;
	}

	pFirst = new TNode<T>(obj.pFirst->data);
	TNode<T>* tmp = obj.pFirst;
	TNode<T>* pNode = pFirst;

	while (tmp->pNext != obj.pStop) {
		pNode->pNext = new TNode<T>(tmp->pNext->data);
		pNode = pNode->pNext;
		tmp = tmp->pNext;
	}
	pLast = pNode;
	pStop = pLast->pNext;
	pCurr = pFirst;

	Reset();
}

template <typename T>
TList<T>::~TList() {
	Clear();
}



template <typename T>
TNode<T>* TList<T>::Search(const T& data) { 
	TNode<T>* tmp = pFirst;
	while (tmp != pStop && tmp->data != data)
		tmp = tmp->pNext;
	if (tmp == pStop) tmp = nullptr; 
	return tmp;
}

template <typename T>
void TList<T>::InsertFirst(const T& data) {
	TNode<T>* tmp = new TNode<T>(data, pFirst);
	if (pFirst == pStop) pLast = tmp;
	pFirst = tmp;

	Reset();
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

	Reset();
}

/////////////////////////////////
template <typename T>
void TList<T>::InsertBefore(const T& data) {
	if (pCurr == nullptr) {
		std::string exp = "Error: data not found";
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

	Reset();
}

template <typename T>
void TList<T>::InsertAfter(const T& data) {
	if (pCurr == nullptr) {
		std::string exp = "Error: data not found";
		throw exp;
	}

	if (IsEnded()) {
		InsertLast(data);
		return;
	}

	TNode<T>* tmp = new TNode<T>(data, pCurr->pNext);
	pCurr->pNext = tmp;

	Reset();
}
/////////////////////////////////

template <typename T>
void TList<T>::InsertBefore(const T& data, const T& before) {
	pCurr = Search(before);

	InsertBefore(data);

	Reset();
}

template <typename T>
void TList<T>::InsertAfter(const T& data, const T& after) {
	pCurr = Search(after);

	InsertAfter(data);

	Reset();
}

/////////////////////////////////


template <typename T>
void TList<T>::Remove(const T& data) {
	if (pFirst == pStop) {
		std::string exp = "Error: list is empty";
		throw exp;
	}

	TNode<T>* pNode = pFirst, * pPrev = nullptr;
	while (pNode->pNext != pStop && pNode->data != data) {
		pPrev = pNode;
		pNode = pNode->pNext;
	}

	if (pNode->pNext == pStop && pNode->data != data) {
		std::string exp = "Error: data not found";
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
	return (pFirst == pStop);
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
		std::string exp = "Error: count can't be less than 0";
		throw exp;
	}

	for (int i = 0; i < count; i++) {
		if (!IsEnded()) pCurr = pCurr->pNext;
		else Reset();
	}
}

template <typename T>
bool TList<T>::IsEnded() const {
	return (pCurr == pStop);
}

template <typename T>
bool TList<T>::IsLast() const {
	return (pCurr == pLast);
}

template <typename T>
TNode<T>* TList<T>::first() const {
	return pFirst;
}
template <typename T>
TNode<T>* TList<T>::last() const {
	return pLast;
}

#endif // !TLIST_H
