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

	void insertFirst(const T& key);
	void Remove(const T& key);
	void Clear();
};

template <typename T>
TRingList<T>::TRingList() : TList<T>() {
	pHead = nullptr;
	pStop = pHead;
}

template <typename T>
TRingList<T>::TRingList(const TList<T>& lst) : TList<T>(lst)
{
	pHead = new TNode<T>(0, lst.getFirst());
	if (pLast != nullptr) pLast->pNext = pHead;
	pStop = pHead;
}

template <typename T>
TRingList<T>::TRingList(const TRingList<T>& lst) : TList<T>(lst)
{
	pHead = new TNode<T>(0, lst.getFirst());
	if (pLast != nullptr) pLast->pNext = pHead;
	pStop = pHead;
}

template <typename T>
TRingList<T>::TRingList(TNode<T>* _pFirst) : TList<T>(_pFirst) {
	pHead = new TNode<T>(pFirst->key, pFirst);
	pLast->pNext = pHead;
	pStop = pHead;
}

template <typename T>
TRingList<T>::~TRingList() {
	if (pFirst == nullptr) return; 	
	delete pHead;
}

template <typename T>
void TRingList<T>::insertFirst(const T& key) {
	TList<T>::insertFirst(key);
	pHead = new TNode<T>(-1, pFirst);
	pLast->pNext = pHead;
	pStop = pHead;
}

//template <typename T>
//void TRingList<T>::Next() {
//	pCurrent = pCurrent->pNext;
//}

template <typename T>
void TRingList<T>::Remove(const T& key) {
	TList<T>::Remove(key);
	pHead->pNext = pFirst;
	TNode<T>* tmp = pFirst;
	while (tmp->pNext != pStop) tmp = tmp->pNext;
	pLast = tmp;
}

template <typename T>
void TRingList<T>::Clear() {
	TList<T>::Clear();
	if (pFirst != nullptr) delete pFirst;
	pFirst = nullptr;
	pHead = nullptr;
}