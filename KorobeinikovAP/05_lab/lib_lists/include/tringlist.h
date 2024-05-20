#ifndef __TRINGLIST_H__
#define __TRINGLIST_H__

#include "tlist.h"


template <typename T>
class TRingList : public TList<T> {
protected:
	TNode<T>* pHead;
public:
	TRingList();
	TRingList(TNode<T>* pFirst_);
	TRingList(const TList<T>& obj);
	TRingList(const TRingList<T>& obj);

	virtual void InsertFirst(const T& data_);
	virtual ~TRingList();
	virtual void Remove(const T& data_);
};

template <typename T>
TRingList<T>::TRingList() {
	pFirst = nullptr;
	pCurr = nullptr;
	pLast = nullptr;
	pHead = new TNode<T>(T());
	pHead->pNext = pHead;
	pStop = pHead;
	
}

template <typename T>
 TRingList<T>::TRingList(TNode<T>* pFirst_) : TList(pFirst_) {
	pHead = new TNode<T>();
	pHead->pNext = pFirst;
	pStop = pHead;
	pLast->pNext = pHead;

	if (pFirst == nullptr) {
		pHead->pNext = pHead;
	}
	/*
	else {
		TNode<T>* tmp = pFirst;
		pHead->pNext = pFirst;
		while (tmp->pNext != pStop) {
			tmp = tmp->pNext;
		}
		tmp->pNext = pHead;
		pLast = tmp;
	}
	*/
}


template <typename T>
TRingList<T>::TRingList(const TList<T>& obj) : TList<T>(obj) {
	pHead = new TNode<T>();
	pStop = pHead;

	if (pFirst == nullptr) {
		pHead->pNext = pHead;
	}
	else {
		pHead->pNext = pFirst;
		pLast->pNext = pHead;
	}


} 



template <typename T>
TRingList<T>::TRingList(const TRingList<T>& obj) : TList(obj) { //??
	pHead = new TNode<T>();
	pStop = pHead;
	
	if	(obj.pFirst == obj.pStop) {
		pHead->pNext = pHead;
	}
	
	else {
		pHead->pNext = pFirst;
		pLast->pNext = pHead;
	}
	/*
	else {
		pFirst = new TNode<T>(obj.pFirst->data);
		TNode<T>* tmp = obj.pFirst;
		TNode<T>* pNode = pFirst;
		pHead->pNext = pFirst;

		while (tmp->pNext != obj.pStop) {
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
	TList<T>::Clear();
	if (pStop) delete pStop;
}
template <typename T>
void TRingList<T>::InsertFirst(const T& data_) {
	TList<T>::InsertFirst(data_);
	pHead->pNext = pFirst;
}

template<typename T>
void TRingList<T>::Remove(const T& data_) {
	if (pFirst == nullptr) {
		throw "Node is empty";
	}
	TNode<T>* tmp = pFirst, * pPrev = nullptr;
	while ((tmp->pNext != pStop) && (tmp->data != data_)) {
		pPrev = tmp;
		tmp = tmp->pNext;
	}
	if ((tmp->pNext == pStop) && (tmp->data != data_)) {
		throw "Node with this data not is find";
	}
	if (tmp == pFirst) {
		if (IsLast()) {
			delete pFirst;
			pFirst = nullptr;
			pCurr = nullptr;
			pLast = nullptr;
			pHead->pNext = pHead;
			return;
		}
		else {
			pFirst = tmp->pNext;
			delete tmp;
			pCurr = pFirst;
			return;
		}
	}
	if (tmp == pLast) {
		pPrev->pNext = pStop;
		delete tmp;
		pLast = pPrev;
		return;
	}
	pPrev->pNext = tmp->pNext;
	delete tmp;
}

#endif 