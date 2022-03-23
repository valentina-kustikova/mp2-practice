#include <iostream>
#include "list.h"

//звено
template<typename TData>
TNode<TData>::TNode(const TData& data)
{
	this->data = data;
	this->pNext = nullptr;
}

template<typename TData>
TNode<TData>::TNode(const TNode& copy)
{
	this->data = copy.data;
	this->pNext = nullptr;
}

template<typename TData>
bool TNode<TData>::operator==(const TNode<TData> n)const
{
	return(data == n.data && pNext == n.pNext);
}

template<typename TData>
bool TNode<TData>::operator!=(const TNode<TData> n)const
{
	return !(*this == n);
}


//список
template<typename TData>
TList<TData>::TList()
{
	pHead = new TNode<TData>;
	pHead->pNext = pHead;
	pCurr = pHead;
}

template<typename TData>
TList<TData>::TList(const TList<TData>& list2)
{
	TNode<TData>* pCurr2 = list2.pHead;
	pHead = new TNode<TData>(pCurr2->data);
	pHead->pnext = pHead;
	pCurr = pHead;
	while (pCurr2->pNext != list2.pHead)
	{
		pCurr2 = pCurr2->pNext;
		pCurr->pNext = new TNode<TData>(pCurr2->data);
		Next();
	}
	pCurr->pNext = pHead;
}

template<typename TData>
TList<TData>::~TList()
{
	Clean();
	delete pHead;
}

template<typename TData>
void TList<TData>::Clean()
{
	TNode <TData>* pCurr = pHead->pNext;
	TNode<TData>* tmp;
	while (pCurr != pHead)
	{
		tmp = pCurr->pNext;
		delete pCurr;
		pCurr = tmp;
	}
	pHead->pNext = pHead;
}

template<typename TData>
TNode<TData>* TList<TData>::Search(const TData& data1)
{
	pCurr = pHead;
	while (pCurr->pNext != pHead || pCurr->pNext->data != data1)
	{
		Next();
	}
	if (pCurr->data == data1)
	{
		teturn pCurr;
	}
	else
		return nullptr;
}

template<typename TData>
void TList<TData>::InsertToHead(const TData& data1)
{
	pCurr = pHead;
	TNode<TData>* pFirst;
	while (pCurr->pNext != pHead)
	{
		Next();
	}
	pFirst = pCurr->pNext;
	pCurr->pNext = new TNode<TData>(data1);
	pCurr->pNext->pNext = pFirst;
}

template<typename TData>
void TList<TData>::InsertToTail(const TData& data1)
{
	Reset();
	while (pCurr->pNext != pHead)
	{
		Next();
	}
	TNode<TData>* pLast = pCurr->pNext;
	pCurr->pNext = new TNode<TData>(data1);
	pCurr->pNext->pNext = pLast;
}

template<typename TData>
void TList<TData>::Insert(TData data1, TNode<TData>* after)
{
	TNode<TData> tmp = after->pNext;
	after->pNext = new TNode<TData>(data1);
	after->pNext->pNext = tmp;
}

template<typename TData>
void TList<TData>::Remove(TNode<TData>* pFirst, TNode<TData>* pLast)
{
	pCurr = pHead;
	while (pCurr->pNext !=pFirst)
	{
		Next();
	}
	while (pCurr->pNext != pLast)
	{
		delete (pCurr->pNext);
	}
}

template<typename TData>
void TList<TData>::Next()
{
	pCurr = pCurr->pNext;
}

template<typename TData>
void TList<TData>::Reset()
{
	pCurr = pHead->pNext;
}

template<typename TData>
bool TList<TData>::IsEnded() const
{
	return (pCurr == pHead);
}

template<typename TData>
TNode<TData>* TList<TData>::GetCur() const
{
	return pCurr;
}
