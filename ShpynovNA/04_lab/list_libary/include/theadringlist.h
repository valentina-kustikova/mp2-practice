#ifndef _THRL
#define _THRL

#include "tlist.h"

template <typename TData> class THeadRingList : public TList<TData> {
public:
	TNode<TData>* pHead;

	THeadRingList() :TList<TData>() {
		pHead = new TNode<TData>();
		pHead->pNext = pHead;
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
	void clear();

	const THeadRingList<TData>& operator=(const THeadRingList<TData>& l);
};

template <typename TData> void THeadRingList<TData>::InsertFirst(const TData& d){
	TList<TData>::InsertFirst(d);
	pLast->pNext = pHead;
	pHead->pNext = pFirst;
}

template <typename TData>
const THeadRingList<TData>& THeadRingList<TData>::operator=(const THeadRingList<TData>& l) {
	if (this == &l)
		return *this;
	pFirst = new TNode<TData>(*l.pFirst);
	pHead = new TNode<TData>();
	pHead->pNext = pFirst;
	pStop = pHead;
	pCurrent = pFirst;
	TNode<TData>* tmp = l.pFirst->pNext;
	while (tmp != l.pStop) {
		pCurrent->pNext = new TNode<TData>(*tmp);
		pCurrent = pCurrent->pNext;
		tmp = tmp->pNext;
	}
	pCurrent->pNext = pStop;
	pLast = pCurrent;
	pCurrent = pFirst;

	return (*this);
}

template <typename TData> void THeadRingList<TData>::clear() {
	TList<TData>::clear();
	pHead->pNext = pHead;
	pStop = pHead;
}
#endif