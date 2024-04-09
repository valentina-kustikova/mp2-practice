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
};

template <typename T>
TRingList<T>::TRingList() {
	pHead = new TNode<T>();
	pHead->pNext = pHead;
	
	pStop = pHead;
	pFirst = pHead; // nullptr
	pLast = pHead; // nullptr
	pCurr = pHead; // nullptr
} // !!! IF pFirst = nullptr (etc.), THEN WHOLE PROJECT BREAKS DOWN !!! 

template <typename T>
TRingList<T>::TRingList(TNode<T>* _pFirst) : TList(_pFirst) {
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
}

template <typename T>
TRingList<T>::TRingList(const TRingList<T>& rlist) {
	pHead = new TNode<T>();
	pHead->pNext = pHead;
	pStop = pHead;
	
	if (rlist.pFirst == rlist.pStop) { //nullptr
		pFirst = pHead; // nullptr
		pLast = pHead; // nullptr
		pCurr = pHead; // nullptr
	}
	else {
		pFirst = new TNode<T>(rlist.pFirst->key);
		TNode<T>* tmp = rlist.pFirst;
		TNode<T>* pNode = pFirst;
		pHead->pNext = pFirst;

		while (tmp->pNext != rlist.pStop) {
			pNode->pNext = new TNode<T>(tmp->pNext->key);
			pNode = pNode->pNext;
			tmp = tmp->pNext;
		}
		pLast = pNode;
		pLast->pNext = pStop;
		pCurr = pFirst;
	}
}

template <typename T>
TRingList<T>::~TRingList() {
	if (pStop) delete pStop;
}

template <typename T>
void TRingList<T>::InsertFirst(const T& data) {
	TNode<T>* tmp = new TNode<T>(data, pFirst);
	if (pFirst == pStop) pLast = tmp;
	pFirst = tmp;

	pHead->pNext = pFirst;

	if (pCurr == pStop) Reset();
}


#endif