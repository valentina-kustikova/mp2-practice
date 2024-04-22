#ifndef TRINGLIST_H
#define TRINGLIST_H

#include <iostream>
#include "tlist.h"

using namespace std;

template <typename T>
class TRingList : public TList<T> {
private:
	TNode<T>* pHead;
public:
	TRingList();
	TRingList(TNode<T>* _pFirst);
	TRingList(const TRingList<T>& rlist);
	virtual ~TRingList();

	void InsertFirst(const T& data);
	void InsertLast(const T& data);
};

template <typename T>
TRingList<T>::TRingList() {
	pHead = new TNode<T>();
	pHead->pNext = pHead;

	pStop = pHead;
	pLast = pHead;
	pLast->pNext = pHead;

	/*
	pStop = pHead;
	pFirst = pHead; // nullptr
	pLast = pHead; // nullptr
	pCurr = pHead; // nullptr
	*/
} // !!! IF pFirst = nullptr (etc.), THEN WHOLE PROJECT BREAKS DOWN !!! 

template <typename T>
TRingList<T>::TRingList(TNode<T>* _pFirst) : TRingList<T>() {
	if (_pFirst == nullptr) return;
	
	TNode<T>* tmp = _pFirst->pNext;
	pFirst = new TNode<T>(_pFirst->data);
	pLast = pFirst;
	pCurr = pFirst;

	while (tmp != nullptr) {
		if (tmp->data != T() && tmp->pNext == pFirst) break;
		pLast->pNext = new TNode<T>(tmp->data);
		pLast = pLast->pNext;
		tmp = tmp->pNext;
	}
	pLast->pNext = pHead;

	/*
	pHead = new TNode<T>();
	pHead->pNext = pHead;
	pStop = pHead;

	if (pFirst == nullptr) {
		pFirst = pHead; //nullptr
		pLast = pHead; // nullptr
		pCurr = pHead; // nullptr
	}
	else {
		TNode<T>* tmp = pFirst;
		pHead->pNext = pFirst;
		while (tmp->pNext != nullptr) {
			tmp = tmp->pNext;
		}
		tmp->pNext = pHead;
		pLast = tmp;
	}
	*/
}

template <typename T>
TRingList<T>::TRingList(const TRingList<T>& rlist) : TRingList<T>() {
	if (rlist.IsEmpty()) return;
	
	TNode<T>* tmp = rlist.pFirst->pNext;
	pFirst = new TNode<T>(rlist.pFirst->data);
	pLast = pFirst;
	pCurr = pFirst;

	while (tmp != rlist.pStop) {
		pLast->pNext = new TNode<T>(tmp->data);
		pLast = pLast->pNext;
		tmp = tmp->pNext;
	}
	pLast->pNext = pHead;

	/*
	pHead = new TNode<T>();
	pHead->pNext = pHead;
	pStop = pHead;

	if (rlist.pFirst == rlist.pStop) { //nullptr
		pFirst = pHead; // nullptr
		pLast = pHead; // nullptr
		pCurr = pHead; // nullptr
	}
	else {
		pFirst = new TNode<T>(rlist.pFirst->data);
		TNode<T>* tmp = rlist.pFirst;
		TNode<T>* pNode = pFirst;
		pHead->pNext = pFirst;

		while (tmp->pNext != rlist.pStop) {
			pNode->pNext = new TNode<T>(tmp->pNext->data);
			pNode = pNode->pNext;
			tmp = tmp->pNext;
		}
		pLast = pNode;
		pLast->pNext = pStop;
		pCurr = pFirst;
	}
	*/
}

template <typename T>
TRingList<T>::~TRingList() {
	if (pStop) delete pStop;
	if (pLast) pLast->pNext = nullptr;
	pStop = nullptr;
}

template <typename T>
void TRingList<T>::InsertFirst(const T& data) {
	if (pFirst == nullptr) {
		pFirst = new TNode<T>(data);
		pLast = pFirst;
		pLast->pNext = pHead;
		pHead->pNext = pFirst;
		return;
	}

	TNode<T>* tmp = new TNode<T>(data, pFirst);
	pFirst = tmp;
	pHead->pNext = pFirst;

	//Reset();

	/*
	TNode<T>* tmp = new TNode<T>(data, pFirst);
	if (pFirst == pStop) pLast = tmp;
	pFirst = tmp;

	pHead->pNext = pFirst;

	Reset();
	*/
}

template <typename T>
void TRingList<T>::InsertLast(const T& data) {
	if (pFirst == nullptr) {
		pFirst = new TNode<T>(data);
		pLast = pFirst;
		pLast->pNext = pHead;
		pHead->pNext = pFirst;
		return;
	}

	TNode<T>* tmp = new TNode<T>(data, pHead);
	pLast->pNext = tmp;
	pLast = pLast->pNext;
}


#endif