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

	void InsertFirst(const T& data);
	void InsertEnd(const T& data);
	void Remove(const T& data);
	friend ostream& operator<<(ostream& os, const TRingList<T>& rl)
	{
		TNode<T>* cur = rl.pFirst;
		while (cur != rl.pHead)
		{
			os << cur->data << endl;
			cur = cur->pNext;
		}

		return os;
	}
};

template <typename T>
TRingList<T>::TRingList() : TList<T>()
{
	pHead = new TNode<T>();
	pHead->pNext = pHead;
	pFirst = nullptr;
	pStop = nullptr;
}
template <typename T>
TRingList<T>::TRingList(TNode<T>* _pFirst) : TList<T>(_pFirst)
{
	pHead = new TNode<T>();
	pHead->pNext = pFirst; // todo: вызов конструктора есть
	pStop = pHead;
	pLast->pNext = pStop;
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
TRingList<T>::TRingList(const TRingList<T>& rlist)  : TList<T>(rlist)
{
	if (rlist.pFirst == nullptr)
		return;
	pHead = new TNode<T>();
	pHead->pNext = pFirst;
	pLast->pNext = pHead;
	pStop = pHead;
}
template <typename T>
TRingList<T>::~TRingList()
{
	if (pStop)
		delete pStop;
}
template <typename T>
void TRingList<T>::InsertFirst(const T& data)
{
	TList<T>::InsertFirst(data);
	pHead->pNext = pFirst;
	pStop = pHead;
	pLast->pNext = pStop;
	
}
template <typename T>
void TRingList<T>::InsertEnd(const T& data)
{
	if (pFirst == pStop)
	{
		InsertFirst(data);
		return;
	}
	pLast->pNext = new TNode<T>(data, pHead);
	pLast = pLast->pNext;
}
template <typename T>
void TRingList<T>::Remove(const T& data)
{
	TList<T>::Remove(data);
	if (pFirst != pStop && pFirst != nullptr)
	{
		pLast->pNext = pHead;
	}
}
#endif

