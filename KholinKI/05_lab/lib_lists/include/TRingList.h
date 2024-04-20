#ifndef _TRINGLIST_H
#define _TRINGLIST_H

#include "TList.h"

template <typename T>
class TRingList : public TList<T> {
protected:
	Node<T>* pHead;
public:
	TRingList();
	TRingList(Node<T>* pFirst_);
	TRingList(const TRingList<T>& rList);
	virtual ~TRingList();

	void insert_first(const T& data_) override;
	void remove(const T& data_) override;
	void Sort();
	bool Is_Sorted();
};

template<typename T>		
TRingList<T>::TRingList(){ 
	pHead = new Node<T>();
	pHead->pNext = pHead;
	pStop = pHead;
}

template <typename T>
TRingList<T>::TRingList(Node<T>* pFirst_):TRingList<T>(){
	if (pFirst_ == nullptr)
	{
		return;
	}
	pFirst = new Node<T>(pFirst_->data);
	pHead->pNext = pFirst;
	Node<T>* tmp = pFirst_->pNext;
	pCurr = pFirst;
	while (tmp != nullptr) {
		pCurr->pNext = new Node<T>(tmp->data);
		pCurr = pCurr->pNext;
		tmp = tmp->pNext;
	}
	pCurr->pNext = pHead;
	pLast = pCurr;
	pCurr = pFirst;
	pPrev = nullptr;
	pStop = pHead;
}

template <typename T>
TRingList<T>::TRingList(const TRingList<T>& rList){
	if (rList.pFirst == nullptr) {
		return;
	}
	pHead = new Node<T>();
	pFirst = new Node<T>(rList.pFirst->data);
	pHead->pNext = pFirst;
	Node<T>* tmp = rList.pFirst->pNext;
	pCurr = pFirst;
	while (tmp != rList.pStop) {
		pCurr->pNext = new Node<T>(tmp->data);
		pCurr = pCurr->pNext;
		tmp = tmp->pNext;
	}
	pCurr->pNext = pHead;
	pLast = pCurr;
	pCurr = pFirst;
	pPrev = nullptr;
	pStop = pHead;
}

template<typename T>
TRingList<T>::~TRingList() {
	pHead->pNext = nullptr;
	delete pHead;
}

template<typename T>
void TRingList<T>::insert_first(const T& data_) {
	Node<T>* tmp = new Node<T>(data_);
	tmp->pNext = pFirst;
	if (pFirst == nullptr) {
		pFirst = tmp;
		pFirst->pNext = pHead;
		pHead->pNext = pFirst;
		pLast = pFirst;
		pCurr = pFirst;
	}
	else {
		pFirst = tmp;
		pHead->pNext = pFirst;
		pCurr = pFirst;
	}
}


template<typename T>
void TRingList<T>::remove(const T& data_) {
	Node<T>* tmp = search(data_);
	if (tmp == pFirst) {
		pFirst = pFirst->pNext;
		pHead->pNext = pFirst;
		pCurr = pFirst;
		tmp->pNext = nullptr;
		delete tmp;
	}
	else {
		if (tmp->pNext == pStop) {
			pLast = pPrev;
		}
		pCurr = pCurr->pNext;
		pPrev->pNext = tmp->pNext;
		tmp->pNext = nullptr;
		delete tmp;
	}
}

template<typename T>
bool TRingList<T>::Is_Sorted() {
	next();
	while (!Is_Ended()) {
		if (pPrev->data <= pCurr->data) {
			next();
		}
		else {
			reset();
			return false;
		}
	}
	reset();
	return true;
}

template<typename T>
void TRingList<T>::Sort() {
	int size = GetSize();
	while(pCurr != pStop){
		Node<T>* min = getCurrent();
		Node<T>* pJ = getCurrent()->pNext;
		while(pJ != pStop){
			if (pJ->data <= min->data) {
				min = pJ;
			}
			pJ = pJ->pNext;
		}
		swap(pCurr, min);//указатели
		next();
	}
	reset();
}

#endif