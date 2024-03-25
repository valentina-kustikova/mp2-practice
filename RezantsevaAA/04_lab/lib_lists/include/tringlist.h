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
	virtual void InsertFirst(const TData& data_) override; //вставить после pHead
	virtual void InsertLast(const TData& data_) override;
	virtual void DeleteFirst();
	TRingList<TData>& operator=(const TRingList<TData>& ringList);
	virtual void Sort() override;
	friend std::ostream& operator<<(std::ostream& out, TRingList<TData>& ringList) {
		TNode<TData>* tmp = ringList.GetPFirst();
		int num = 1;
		while (tmp != ringList.GetPStop()) {
			out << num << " node " << tmp->data << std::endl;
			tmp = tmp->pNext;
			num++;
		}
		return out;
	}
};
//убрать setPStop & getpStop тк у нас pstop = phead  plast.pNext = pHead
template <class TData> TRingList<TData>::TRingList() {
	this->pHead = new TNode<TData>();
	this->pHead->pNext = pFirst;
	this->pCurr = this->pPrev = this->pLast = this->pFirst;
	this->pStop = this->pHead;
	//this->pStop->pNext = pHead;
	this->ListLen = 0;
	TList<TData>::Reset();
}

template <class TData> TRingList<TData>::TRingList(const TNode<TData>* _pFirst) {
	/*pHead = new TNode<TData>();
	if (_pFirst != nullptr) {
		pFirst = (TNode<TData>*)_pFirst;
		pHead->pNext = pFirst;
		pCurr = pFirst;
		TList<TData>::SetPStop(pHead);
		TNode<TData>* tmp = pCurr;
		while (tmp->pNext != nullptr) {
			tmp = tmp->pNext;
		}
		tmp->pNext = pHead;
		TList<TData>::SetPLast(tmp);
	}*/
	pHead = new TNode<TData>();
	pCurr = nullptr;
	if (_pFirst != nullptr) {
		pFirst = new TNode<TData>(_pFirst->data, nullptr);
		pHead->pNext = pFirst;
		pCurr = pFirst;
		TList<TData>::SetPStop(pHead);
		TNode<TData>* tmp = pFirst;
		while (tmp->pNext != nullptr && tmp->pNext != pFirst) {
			tmp = new TNode<TData>(tmp->pNext->data, nullptr);
			pCurr->pNext = tmp;
			pCurr = tmp;
		}
		if (tmp->pNext == nullptr) {
			tmp->pNext = pHead;
			TList<TData>::SetPLast(tmp);
		}
	}
}
template <class TData> TRingList<TData>::TRingList(const TRingList<TData>& ringList) {
	pHead = new TNode<TData>();
	pFirst = new TNode<TData>(*ringList.GetPFirst());
	pHead->pNext = pFirst;
	// Set new pStop
	TList<TData>::SetPStop(pHead);
	pCurr = pFirst;
	TNode<TData>* tmp = ringList.GetCurrent();
	while (tmp->pNext != ringList.GetPStop()) {
		pCurr->pNext = new TNode<TData>(*tmp->pNext);
		pCurr = pCurr->pNext;
		tmp = tmp->pNext;
	}
	pCurr->pNext = pStop;
	TList<TData>::SetPLast(pCurr);
	ListLen = ringList.ListLen;
	TList<TData>::Reset();
}

template <class TData> TRingList<TData>& TRingList<TData>::operator=(const TRingList<TData>& ringList)  {
	pHead = new TNode<TData>();
	pFirst = new TNode<TData>(*ringList.GetPFirst());
	pHead->pNext = pFirst;
	// Set new pStop
	TList<TData>::SetPStop(pHead);
	pCurr = pFirst;
	TNode<TData>* tmp = ringList.GetCurrent();
	while (tmp->pNext != ringList.GetPStop()) {
		pCurr->pNext = new TNode<TData>(*tmp->pNext);
		pCurr = pCurr->pNext;
		tmp = tmp->pNext;
	}
	pCurr->pNext = pStop;
	TList<TData>::SetPLast(pCurr);
	ListLen = ringList.ListLen;
	TList<TData>::Reset();
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
	ListLen++;;
	pHead->pNext = pFirst;
}
template <class TData> void TRingList<TData>::InsertLast(const TData& data_) {
	if (is_Empty())
	{
		InsertFirst(data_);
		pLast = pFirst;
		pLast->pNext = pStop;
		return;
	}
	TNode<TData>* newNode = new TNode<TData>(data_, nullptr);
	pLast->pNext = newNode;
	pLast = newNode;
	pLast->pNext = pStop;
	ListLen++;
}

template <class TData> void TRingList<TData>::DeleteFirst() {
	TList<TData>::RemoveFirst();
	pHead->pNext = this->pFirst;
}


template <class TData> void TRingList<TData>::Sort() {
	TNode<TData>* elem1 = pFirst;
	while (elem1->pNext != pStop)
	{
		TNode<TData>* elem2 = elem1->pNext;
		while (elem2 != pStop)
		{
			if (elem1->data < elem2->data)
			{
				TData tmp = elem1->data;
				elem1->data = elem2->data;
				elem2->data = tmp;
			}
			elem2 = elem2->pNext;
		}
		elem1 = elem1->pNext;
	}
}

#endif