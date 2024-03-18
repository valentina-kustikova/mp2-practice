#ifndef _RING_LIST_H
#define _RING_LIST_H
#include "ListHeader.h"

template <typename T>
class TRingList : public TList<T>
{
private:
	TNode<T>* pHead;
public:
	TRingList();
	TRingList(TNode<T>* _pFirst);
	TRingList(const TList<T>& list);
	TRingList(const TRingList<T>& rlist);
	virtual ~TRingList();

};

template <typename T>
TRingList<T>::TRingList() : TList<T>()
{
	pHead = new TNode<T>();
	pHead->pNext = pHead;
}
template <typename T>
TRingList<T>::TRingList(TNode<T>* _pFirst) : TList<T>(_pFirst)
{
	TNode<T>* pHead = new TNode<T>();
	pHead->pNext = pFirst;
	SetPStop(pHead);
	if (pFirst != nullptr)
	{
		TNode<T>* tmp = pFirst;
		while (tmp->pNext != nullptr) 
			tmp = tmp->pNext;

		tmp->pNext = pHead;
		SetPLast(tmp);
	}
	else
	{
		pFirst = pHead;
		pLast = pHead;
		pCurr = pHead;
	}
}
template <typename T>
TRingList<T>::TRingList(const TList<T>& list) : TList<T>(list)
{
	pHead = new TNode<T>();
	pHead->pNext = pFirst;
	pLast->pNext = pHead;
	pStop = pHead;
}
template <typename T>
TRingList<T>::TRingList(const TRingList<T>& rlist)
{
	if (rlist.pFirst == nullptr)
		return;
	pHead = new TNode<T>();
	pFirst = new TNode<T>(rlist.pFirst->data, rlist.pFirst->pNext);
	pHead->pNext = pFirst;
	TNode<T>* tmp = pFirst;
	TNode<T>* tmp2 = pFirst;
	tmp = tmp->pNext;

	while (tmp->data != pHead->data)
	{
		tmp2->pNext = new TNode<T>(tmp->data);
		tmp2 = tmp2->pNext;
		tmp = tmp->pNext;
	}
	SetPStop(pHead);
	SetPLast(tmp2);
	pLast->pNext = pHead;
	pCurr = pFirst;
}
template <typename T>
TRingList<T>::~TRingList()
{
	if (pHead)
		delete pHead;
}
#endif

