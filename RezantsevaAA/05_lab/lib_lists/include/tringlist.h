#ifndef __TRINGLIST_H__
#define __TRINGLIST_H__
#include <iostream>
#include "tlist.h"

using namespace std;

template <class TData> 
class TRingList : public TList<TData> {
protected:
	TNode<TData>* pHead = nullptr;
public:
	TRingList();
	TRingList(const TNode<TData>* pFirst);
	TRingList(const TRingList<TData>& ringList);
	
	TNode<TData>* GetPStop() const
	{
		return pStop;
	}

	void InsertFirst(const TData& data_) override; //вставить после pHead
	void RemoveFirst() override;
	void Clear() override;
	bool is_Empty() const override;
	const TRingList<TData>& operator=(const TRingList<TData>& ringList);

	friend std::ostream& operator<<(std::ostream& out, TRingList<TData>& ringList) {
		TNode<TData>* tmp = ringList.pFirst;
		int num = 1;
		while (tmp != ringList.pHead) {
			out << num << " node " << tmp->data << std::endl;
			tmp = tmp->pNext;
			num++;
		}
		return out;
	}
	
};
template <class TData> void TRingList<TData>::Clear() {
	if (pFirst == nullptr)
	{
		return;
	}
	pCurr = pFirst;
	while (pCurr != pHead) {
		TNode<TData>* tmp = pCurr;
		pCurr = pCurr->pNext;
		delete tmp;
	}
	pCurr = pStop;
	pLast = pStop;
	pFirst = pStop;
	pPrev = pStop;
	pHead->pNext = pHead;
}
template <class TData> bool TRingList<TData>::is_Empty() const {
	return (pHead->pNext == pHead);
}

template <class TData> TRingList<TData>::TRingList() {
	this->pHead = new TNode<TData>();
	this->pHead->pNext = pHead;
	this->pCurr = this->pPrev = this->pLast = this->pFirst = nullptr;
	this->pStop = this->pHead;
}

template <class TData> TRingList<TData>::TRingList(const TNode<TData>* _pFirst) {
	pHead = new TNode<TData>();
	pHead->pNext = pHead;

	if (_pFirst != nullptr) {
		pFirst = (TNode<TData>*)_pFirst;
		pHead->pNext = pFirst;
		pCurr = pFirst;
		pStop= pHead;
		TNode<TData>* tmp = pCurr;
		while (tmp->pNext != nullptr) { 
			tmp = tmp->pNext;
		}
		tmp->pNext = pHead;
		pLast = tmp;

	}
}
template <class TData> TRingList<TData>::TRingList(const TRingList<TData>& ringList) {
	pHead = new TNode<TData>();
	if (ringList.pFirst != nullptr)
	{
		pFirst = new TNode<TData>(*ringList.pFirst);
		pHead->pNext = pFirst;
		// Set new pStop
		pStop = pHead;
		pCurr = pFirst;
		TNode<TData>* tmp(ringList.GetCurrent());
		while (tmp->pNext != ringList.pStop) {
			pCurr->pNext = new TNode<TData>(*tmp->pNext);
			pCurr = pCurr->pNext;
			tmp = tmp->pNext;
		}
		pCurr->pNext = pStop;
		pLast = pCurr;
		TList<TData>::Reset();
	}
	else
	{
		pFirst = pCurr = pLast = pStop = pPrev = pHead;
		pHead->pNext = pHead;
	}


}

template <class TData> const TRingList<TData>& TRingList<TData>::operator=(const TRingList<TData>& ringList)  {
	if (this == &ringList)
	{
		return *this;
	}
	pHead = new TNode<TData>();
	if (ringList.pFirst != nullptr)
	{
		pFirst = new TNode<TData>(*ringList.pFirst);
		pHead->pNext = pFirst;
		// Set new pStop
		pStop = pHead;
		pCurr = pFirst;
		TNode<TData>* tmp = ringList.GetCurrent();
		while (tmp->pNext != ringList.pStop) {
			pCurr->pNext = new TNode<TData>(*tmp->pNext);
			pCurr = pCurr->pNext;
			tmp = tmp->pNext;
		}
		pCurr->pNext = pStop;
		pLast = pCurr;
		TList<TData>::Reset();
	}
	else {
		pFirst = pCurr = pLast = pStop = pPrev = pHead;
		pHead->pNext = pHead;
	}
	return *this;
}

template <class TData> void TRingList<TData>::InsertFirst(const TData& data_) {
	if (is_Full()) {
		throw "Error. Memory is not enough";
	}
	TNode<TData>* newNode = new TNode<TData>(data_, nullptr);

	if (pFirst != nullptr)
	{
		TNode<TData>* oldPFirst = pFirst;
		pFirst = newNode;
		pFirst->pNext = oldPFirst;

	}
	else {
		pFirst = newNode;
		pFirst->pNext = pStop;
		pLast = pFirst;
	}
	pCurr = pFirst;
	pHead->pNext = pFirst;
}

template <class TData> void TRingList<TData>::RemoveFirst() {
	TList<TData>::RemoveFirst();
	pHead->pNext = this->pFirst;
}

#endif