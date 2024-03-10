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
	TRingList(const TNode<T>* _pFirst);
	TRingList(const TList<T>& list);
	TRingList(const TRingList<T>& rlist);
	virtual ~TRingList();

};

template <typename T>
TRingList<T>::TRingList() : TList<T>()
{
	pHead = new TNode<T>;
	this->pStop = pHead;
	pHead->pNext = this->pFirst;
}
template <typename T>
TRingList<T>::TRingList(const TNode<T>* _pFirst) : TList<T>(_pFirst)
{
	pHead = new TNode<T>();
	this->pStop = pHead;
	pHead->pNext = this->pFirst;
}
template <typename T>
TRingList<T>::TRingList(const TList<T>& list) : TList<T>(list)
{
	pHead = new TNode<T>();
	this->pStop = pHead;
	pHead->pNext = this->pFirst;
}
template <typename T>
TRingList<T>::TRingList(const TRingList<T>& rlist)
{
	if (rlist.pFirst == nullptr)
		return;

	this->pFirst = new TNode<T>(rlist.pFirst->data);
	TNode<T>* tmp = this->pFirst;
	TNode<T>* tmp2 = this->pFirst;

	while (tmp->pNext != rlist.pStop)
	{
		tmp2->pNext = new TNode<T>(tmp->data);
		tmp2 = tmp2->pNext;
		tmp = tmp->pNext;
	}
	this->pCurr = this->pFirst;
	pHead = new TNode<T>();
	this->pStop = pHead;
	pHead->pNext = this->pFirst;
}
template <typename T>
TRingList<T>::~TRingList()
{
	if (pHead)
		delete pHead;
}
#endif

