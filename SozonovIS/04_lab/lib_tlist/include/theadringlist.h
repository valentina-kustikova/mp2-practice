#ifndef __HEADRINGLIST_H__
#define __HEADRINGLIST_H__

#include "tlist.h"						
#include "tnode.h"	

#include <iostream>

using namespace std;

template <typename ValueType>
class THeadRingList : public TList<ValueType> {
protected:
	TNode<ValueType>* pHead;
public:
	THeadRingList();
	THeadRingList(const THeadRingList<ValueType>& ringlist);
	~THeadRingList();
	void InsertFirst(const ValueType& data);
	void InsertLast(const ValueType& data);
	void Remove(const ValueType& data);
	void Clear();
	bool IsEnded() const;
};

template <typename ValueType>
THeadRingList<ValueType>::THeadRingList() : TList<ValueType>() {
	pHead = new TNode<ValueType>();
	pHead->pNext = pHead;
	pStop = pHead;
};

template <typename ValueType>
THeadRingList<ValueType>::THeadRingList(const THeadRingList<ValueType>& ringlist) : TList<ValueType>(ringlist) {
	pHead = new TNode<ValueType>();
	pHead->pNext = pFirst;
	if (!ringlist.IsEmpty())
		pLast->pNext = pHead;
	pStop = pHead;
};

template <typename ValueType>
THeadRingList<ValueType>::~THeadRingList() {
	delete pHead;
};

template <typename ValueType>
void THeadRingList<ValueType>::InsertFirst(const ValueType& data) {
	TList<ValueType>::InsertFirst(data);
	pHead->pNext = pFirst;
	pLast->pNext = pHead;
};

template <typename ValueType>
void THeadRingList<ValueType>::InsertLast(const ValueType& data) {
	TList<ValueType>::InsertLast(data);
	pLast->pNext = pHead;
	if (pFirst == pLast)
	{
		pHead->pNext = pFirst;
	}
};

template <typename ValueType>
void THeadRingList<ValueType>::Remove(const ValueType& data) {
	TList<ValueType>::Remove(data);
	pHead->pNext = pFirst;
	pLast->pNext = pHead;
}

template <typename ValueType>
void THeadRingList<ValueType>::Clear() {
	TList<ValueType>::Clear();
	pHead->pNext = pHead;
}

template <typename TData>
bool THeadRingList<TData>::IsEnded() const {
	if (IsEmpty())
		return true;
	return pCurr == pStop;
}

#endif
