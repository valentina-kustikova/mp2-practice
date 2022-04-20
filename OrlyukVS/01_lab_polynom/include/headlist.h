#pragma once

#include "list.h"

template<typename TData>
class THeadList : public TList<TData>
{
protected:
    TNode<TData>* pHead;
public:
    THeadList();
    ~THeadList();

     void InsertToHead(const TData& data1);
     void RemoveFirst();
};

template<typename TData>
THeadList<TData>::THeadList()
{
	pHead = new TNode<TData>;
	pHead->pNext = pHead;
	pFirst = pLast = pCurr = pPrev = 0;
	length = 0;
}

template<typename TData>
THeadList<TData>::~THeadList()
{
	TList<TData>::~TList();
	delete pHead;
}

template<typename TData>
void THeadList<TData>::InsertToHead(const TData& data1)//TData* const data1
{
	TList<TData>::InsertToHead(data1);
	pHead->pNext = pFirst;
}

template<typename TData>
void THeadList<TData>::RemoveFirst()
{
	TList<TData>::RemoveFirst();
	pHead->pNext = pFirst;
}