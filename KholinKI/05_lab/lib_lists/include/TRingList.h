#ifndef _TRINGLIST_H
#define _TRINGLIST_H

#include "TList.h"

template <typename TKey,typename TData>
class TRingList : public TList<T> {
protected:
	Node<TKey,TData>* pHead;
public:
	TRingList();
	TRingList(Node<TKey,TData>* pFirst_);
	TRingList(const TRingList<TKey,TData>& rList);
	virtual ~TRingList();

	void insert_first(const TKey& hey_,const TData* data_) override;
	void remove(const TKey& key_) override;
	void Clear()override;
};

template <typename TKey, typename TData>
TRingList<TKey,TData>::TRingList(){ 
	pHead = new Node<TKey,TData>();
	pHead->pNext = pHead;
	pStop = pHead;
}

template <typename TKey, typename TData>
TRingList<TKey,TData>::TRingList(Node<TKey,TData>* pFirst_):TRingList<TKey,TData>(){
	if (pFirst_ == nullptr)
	{
		return;
	}
	pFirst = new Node<TKey,TData>(pFirst_->key,pFirst_->data);
	pHead->pNext = pFirst;
	Node<T>* tmp = pFirst_->pNext;
	pCurr = pFirst;
	while (tmp != nullptr) {
		pCurr->pNext = new Node<TKey,TData>(tmp->key,tmp->data);
		pCurr = pCurr->pNext;
		tmp = tmp->pNext;
	}
	pCurr->pNext = pHead;
	pLast = pCurr;
	pCurr = pFirst;
	pPrev = nullptr;
	pStop = pHead;
}

template <typename TKey, typename TData>
TRingList<TKey,TData>::TRingList(const TRingList<TKey,TData>& rList){
	if (rList.pFirst == nullptr) {
		return;
	}
	pHead = new Node<TKey,TData>();
	pFirst = new Node<TKey,TData>(rList.pFirst->key,rList.pFirst->data);
	pHead->pNext = pFirst;
	Node<TKey,TData>* tmp = rList.pFirst->pNext;
	pCurr = pFirst;
	while (tmp != rList.pStop) {
		pCurr->pNext = new Node<TKey,TData>(tmp->key,tmp->data);
		pCurr = pCurr->pNext;
		tmp = tmp->pNext;
	}
	pCurr->pNext = pHead;
	pLast = pCurr;
	pCurr = pFirst;
	pPrev = nullptr;
	pStop = pHead;
}

template <typename TKey, typename TData>
TRingList<TKey,TData>::~TRingList() {
	pHead->pNext = nullptr;
	delete pHead;
}

template <typename TKey, typename TData>
void TRingList<TKey,TData>::insert_first(const TKey& key_,const TData* data_) {
	Node<TKey,TData>* tmp = new Node<TKey,TData>(key_,data_);
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


template <typename TKey, typename TData>
void TRingList<TKey,TData>::remove(const TKey& key_) {
	Node<TKey,TData>* tmp = search(key_);
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

template<typename TKey,typename TData>
void TRingList<TKey,TData>::Clear(){
	if (IsEmpty()) {
		return;
	}
	Node<TKey,TData>* tmp = pFirst;
	while (tmp != pStop) {
		pFirst = pFirst->pNext;
		pHead->pNext = pFirst;
		tmp->pNext = nullptr;
		delete tmp;
		tmp = pFirst;
	}
	pFirst = nullptr;
	pCurr = nullptr;
	pPrev = nullptr;
	pLast = nullptr;
}

#endif