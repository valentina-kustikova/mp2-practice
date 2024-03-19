#ifndef __TRINGLIST_H__
#define __TRINGLIST_H__

#include "tlist.h""


template <typename T>
class TRingList : public TList<T> {
protected:
	TNode<T>* pHead;
public:
	TRingList();
	TRingList(TNode<T>* pFirst_);
	TRingList(const TList<T>& obj);
	TRingList(const TRingList<T>& obj);
	virtual ~TRingList();
};

template <typename T>
TRingList<T>::TRingList() {
	pHead = new TNode<T>();
	pStop = pHead;
	pFirst = pHead;
	pCurr = pHead;
	pLast = pHead;
}

template <typename T>
 TRingList<T>::TRingList(TNode<T>* pFirst_) : TList(pFirst_) {
	pHead = new TNode<T>();
	pHead->pNext = pFirst;
	pStop = pHead;
	pLast->pNext = pHead;

	if (pFirst == nullptr) {
		pFirst = pHead;
		pLast = pHead;
		pCurr = pHead;
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
	pHead->pNext = pFirst;
	pStop = pHead;
	pLast->pNext = pHead;
}



template <typename T>
TRingList<T>::TRingList(const TRingList<T>& obj){
	pHead = new TNode<T>();
	pStop = pHead;

	if	(obj.pFirst == obj.pStop) {
		pFirst = pHead;
		pLast = pHead;
		pCurr = pHead;
	}
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
}



template <typename T>
TRingList<T>::~TRingList() {
	if (pStop) delete pStop;
}

#endif 