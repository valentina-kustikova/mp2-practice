#ifndef _THRL
#define _THRL

#include "tlist.h"

template <typename TData> class THeadRingList : public TList<TData> {
public:
	TNode<TData>* pHead;

	THeadRingList() :TList<TData>() {
		pHead = new TNode<TData>();
		pStop = pHead;
	}
	THeadRingList(const THeadRingList<TData>& l) :TList<TData>(l) {
		pHead = new TNode<TData>(l.pHead->data, pFirst);
		if (!l.IsEmpty())
			pLast->pNext = pHead;
		pStop = pHead;
	}

	~THeadRingList() { delete pHead;}

	void InsertFirst(const TData& d);
	void InsertLast(const TData& d);
	void DeleteNode(TNode<TData>* node);
	void DeleteCurrentNode() { DeleteNode(pCurrent); }

	THeadRingList<TData>& operator=(const THeadRingList<TData>& l);
};

template <typename TData> void THeadRingList<TData>::InsertFirst(const TData& d){
	TList<TData>::InsertFirst(d);
	pHead->pNext = pFirst;
	pStop = pHead;
	pLast->pNext = pHead;
}

template <typename TData> void THeadRingList<TData>::InsertLast(const TData& d){
	if (IsEmpty()) {
		THeadRingList<TData>::InsertFirst(d);
		return;
	}
	TList<TData>::InsertLast(d);
}

template <typename TData> THeadRingList<TData>& THeadRingList<TData>::operator=(const THeadRingList<TData>& l) {
	if (this == &l)
		return *this;
	pFirst = new TNode<TData>(*l.pFirst);
	pHead = new TNode<TData>();
	pStop = pHead;
	(*this).reset();
	TNode<TData>* tmp = l.pFirst;
	while (tmp->pNext != l.pStop) {
		pCurrent->pNext = new TNode<TData>(*tmp->pNext);
		pCurrent = pCurrent->pNext;
		tmp = tmp->pNext;
	}
	pCurrent->pNext = pStop;
	pLast = pCurrent;
	pCurrent = pFirst;

	return (*this);
}

template <typename TData> void THeadRingList<TData>::DeleteNode(TNode<TData>* node) {
	if (pFirst == nullptr)
		return;
	if (pFirst == node)
	{
		pHead ->pNext = pFirst->pNext;
		pFirst = pFirst->pNext;
		return;
	}
	this->reset();
	TNode<TData>* TNow = pFirst;
	TNode<TData>* TNext = pFirst->pNext;

	while (TNext != node) {
		if (TNext == nullptr)
			return;
		TNow = TNext;
		TNext = TNext->pNext;
	}
	TNow->pNext = TNext->pNext;
	TNow = nullptr;
	TNext = nullptr;
	return;
}

#endif