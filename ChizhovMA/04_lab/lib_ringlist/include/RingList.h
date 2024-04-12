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

	TNode<T>* Search(const T& data);
	void InsertFirst(const T& data);
	void InsertEnd(const T& data);
	TNode<T>* GetCurrent();
	void Remove(const T& data);
	void Next();
	void Reset();
	bool IsEmpty() const;
	bool IsEnded() const;
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
	pFirst = pHead;
	pStop = pHead;
}
template <typename T>
TRingList<T>::TRingList(TNode<T>* _pFirst) : TList<T>(_pFirst)
{
	pHead = new TNode<T>();
	pHead->pNext = pFirst;
	pStop = pHead;
	if (pFirst != nullptr)
	{
		TNode<T>* tmp = pFirst;
		while (tmp->pNext != nullptr) 
			tmp = tmp->pNext;

		tmp->pNext = pHead;
		pLast = tmp;
	}
	else
	{
		pHead->pNext = pHead;
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
	pFirst = new TNode<T>(rlist.pFirst->data);
	pHead->pNext = pFirst;
	TNode<T>* tmp = rlist.pFirst->pNext;;
	TNode<T>* tmp2 = pFirst;

	while (tmp->data != pHead->data)
	{
		tmp2->pNext = new TNode<T>(tmp->data);
		tmp2 = tmp2->pNext;
		tmp = tmp->pNext;
	}
	pStop = pHead;
	pLast = tmp2;
	pLast->pNext = pHead;
	pCurr = pFirst;
}
template <typename T>
TRingList<T>::~TRingList()
{
	if (pStop)
		delete pStop;
}
template <typename T>
TNode<T>* TRingList<T>::Search(const T& data)
{
	TNode<T>* tmp = pFirst;
	while (tmp != pHead && tmp->data != data)
		tmp = tmp->pNext;
	if (tmp == pHead)
		return nullptr;
	return tmp;
}
template <typename T>
void TRingList<T>::InsertFirst(const T& data)
{
	TNode<T>* pNode = new TNode<T>(data);
	if (pFirst == pHead)
	{
		pLast = pNode;
		pLast->pNext = pHead;
	}
	pNode->pNext = pFirst;
	pFirst = pNode;
	pCurr = pFirst;
	pHead->pNext = pFirst;

}
template <typename T>
void TRingList<T>::InsertEnd(const T& data)
{
	if (pFirst == pStop)
	{
		InsertFirst(data);
		return;
	}
	TNode<T>* pNode = new TNode<T>(data, pHead);
	pLast->pNext = pNode;
	pLast = pNode;
}
template <typename T>
TNode<T>* TRingList<T>::GetCurrent()
{
	return pCurr;
}
template <typename T>
void TRingList<T>::Remove(const T& data)
{
	if (pFirst == pStop)
	{
		string msg = "Element not found!";
		throw msg;
	}

	TNode<T>* pNode = pFirst;
	TNode<T>* pPrev = pHead;

	while (pNode != pHead && pNode->data != data)
	{
		pPrev = pNode;
		pNode = pNode->pNext;
	}
	if (pNode != pHead)
	{
		pPrev->pNext = pNode->pNext;
		if (pNode == pLast)
			pLast = pPrev;
		if (pNode == pFirst)
		{
			pFirst = pNode->pNext;
			pCurr = pFirst;
		}
		delete pNode;
	}
	else
	{
		string msg = "Element not found!";
		throw msg;
	}
}
template <typename T>
void TRingList<T>::Next()
{
	if (pCurr != pHead)
		pCurr = pCurr->pNext;
}
template <typename T>
void TRingList<T>::Reset()
{
	pCurr = pFirst;
}
template <typename T>
bool TRingList<T>::IsEmpty() const
{
	return pFirst == pHead;
}
template <typename T>
bool TRingList<T>::IsEnded() const
{
	return pCurr == pHead;
}
#endif

