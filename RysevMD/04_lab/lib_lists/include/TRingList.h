#pragma once
#include "TList.h"

template <typename T>
class TRingList : public TList<T> {
private:
	TNode<T>* pHead;
public:
	TRingList();
	TRingList(const TList<T>& lst);
	TRingList(const TRingList<T>& lst);
	TRingList(TNode<T>* _pFirst);
	virtual ~TRingList();
};

template <typename T>
TRingList<T>::TRingList() {
	pHead = nullptr;
}

template <typename T>
TRingList<T>::TRingList(const TList<T>& lst) {
	pHead->pNext = lst.pFirst;
	lst.pLast->pNext = lst.pFirst;
}

template <typename T>
TRingList<T>::TRingList(const TRingList<T>& lst) {
	pHead = lst.pHead;
	if (lst.pFirst == nullptr) return;
	pFirst = new TNode<T>(lst.pFirst->key);
	TNode<T>* tmp1 = pFirst;
	TNode<T>* tmp2 = pFirst;
	while (tmp1->pNext != lst.pStop) {
		tmp2->pNext = new TNode<T>(tmp1->pNext->key);
		tmp1 = tmp1->pNext;
		tmp2 = tmp2->pNext;
	}
	pLast = tmp2;
	pLast->pNext = pFirst;
	pCurrent = pFirst;
	pStop = pHead;
}

template <typename T>
TRingList<T>::TRingList(TNode<T>* _pFirst) : TList<T>(_pFirst) {
	pHead = new TNode<T>(pFirst->key, pFirst);
	pLast->pNext = pFirst;
}

template <typename T>
TRingList<T>::~TRingList() {
	if (pFirst == nullptr) throw "ERROR: list already empty";
	TNode<T>* tmp = pFirst;
	while (pFirst != pLast) {
		pFirst = pFirst->pNext;
		delete tmp;
		tmp = pFirst;
	}
	delete tmp;
	delete pHead;
	pFirst = nullptr;
	pCurrent = nullptr;
	pStop = nullptr;
}
