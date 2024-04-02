#pragma once

#include "tlist.h"

template <typename TData>
class THeadRingList : public TList<TData> {
protected:
  TNode<TData>* pHead;

public:
  THeadRingList();
  THeadRingList(const THeadRingList<TData>& ringL);
  ~THeadRingList();

  const THeadRingList<TData>& operator=(const THeadRingList<TData>& l);

  void RemoveFirst();
  void InsertFirst(const TData& data);
  void InsertLast(const TData& data);
};

template <typename TData>
THeadRingList<TData>::THeadRingList() : TList<TData>() {
  pHead = new TNode<TData>();
  pStop = pHead;
}

template <typename TData>
THeadRingList<TData>::THeadRingList(const THeadRingList<TData>& ringL) : TList<TData>(ringL) {
  pHead = new TNode<TData>(ringL.pHead->data, pFirst);
  if (!ringL.IsEmpty())
    pLast->pNext = pHead;
  pStop = pHead;
}

template <typename TData>
THeadRingList<TData>::~THeadRingList() {
  delete pHead;
}

template <typename TData>
void THeadRingList<TData>::InsertFirst(const TData& data) {
  TList<TData>::InsertFirst(data);
  pHead->pNext = pFirst;
  pStop = pHead;
  pLast->pNext = pHead;
}

template <typename TData>
void THeadRingList<TData>::InsertLast(const TData& data) {
  if (IsEmpty()) {
    THeadRingList<TData>::InsertFirst(data);
    return;
  }
  TList<TData>::InsertLast(data);
}

template <typename TData>
void THeadRingList<TData>::RemoveFirst() {
  TNode<TData>* first = pFirst;
  pFirst = pFirst->pNext;
  pHead->pNext = pFirst;
  delete first;
}

template <typename TData>
const THeadRingList<TData>& THeadRingList<TData>::operator=(const THeadRingList<TData>& l) {
  if (l.IsEmpty())
	{
		pFirst=nullptr;
		pLast=nullptr;
		pCurr=nullptr;
    pPrev=nullptr;
		pStop=nullptr;
    return *(this);
	}
	
	Clear();

	pFirst = new TNode<TData>(l.pFirst->data);
	TNode<TData>* tmp = pFirst; 
  TNode<TData>* ltmp = l.pFirst->pNext;
	while(ltmp != l.pStop)
	{
		tmp->pNext = new TNode<TData>(ltmp->data);
		tmp = tmp->pNext;
		ltmp = ltmp->pNext;
	}
	pLast = tmp;
	pCurr = pFirst;
  pPrev = nullptr;
	pStop = nullptr;

  return *(this);
}