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

	virtual void InsrtFirst(const TData& data_); //вставить после pHead
	virtual void DeleteFirst();

	friend std::ostream& operator<<(std::ostream& out, TRingList<TData>& ringList) {
		TNode<TData>* tmp = ringList.GetPFirst();
		int num = 1;
		while (tmp != nullptr) {
			out << num << " node " << tmp->data << std::endl;
			tmp = tmp->pNext;
			num++;
		}
		return out;
	}
};

template <class TData> TRingList<TData>::TRingList() {
	TNode<TData>* pHead = new TNode<TData>();
	pHead->pNext = pHead;
	this->pCurr = this->pPrev = this->pLast = this->pFirst = this->pStop = this->pHead;
	this->ListLen = 0;
	TList<TData>::Reset();
}

template <class TData> TRingList<TData>::TRingList(const TNode<TData>* pFirst) {
	if (pFirst != nullptr) {
		TNode<TData>* pHead = new TNode<TData>();
		pHead->pNext = (TNode<TData>*)pFirst;
		TList<TData>::SetPStop(pHead);
		TNode<TData>* tmp = (TNode<TData>*)pFirst;

		while (tmp->pNext != nullptr) {
			tmp = tmp->pNext;
		}

		tmp->pNext = pHead;
		TList<TData>::SetPLast(tmp);
	}
}
template <class TData> TRingList<TData>::TRingList(const TRingList<TData>& ringList) {
	TNode<TData>* pPrev = nullptr;

	TNode<TData>* tmp = ringList.GetCurrent();
	while (tmp->pNext != nullptr) {
		pPrev = tmp;
		tmp = tmp->pNext;
	}
	tmp->pNext = TList<TData>::GetPFirst();
	TList<TData>::SetPStop(tmp);
	TList<TData>::SetPLast(pPrev);
}

template <class TData> void TRingList<TData>::InsrtFirst(const TData& data_) {
	TNode<TData>* pHead = new TNode<TData>(0);
	TList<TData>::InsertFirst(data_);
	pHead->pNext = this->pFirst;
}

template <class TData> void TRingList<TData>::DeleteFirst() {
	TNode<TData>* pHead = new TNode<TData>(0);
	TList<TData>::RemoveFirst();
	pHead->pNext = this->pFirst;
}




/*
template <class TData> std::ostream& operator<<(std::ostream& out, TRingList<TData>& ringList)
{
	
}

   friend std::ostream& operator<<(std::ostream& out, const TList<TData>& list) {
		TNode<TData>* tmp = list.GetPFirst();
		int num = 1;
		while (tmp != nullptr) {
			out << num << " node "<<tmp->data << std::endl;
			tmp = tmp->pNext;
			num++;
		}
		return out;
	}


	for (ringList.Reset(); !ringList.is_End(); ringList.Next()) {
		out << ringList.getCurrdata() << " ";
	}
	ringList.Reset();
	out << "\n";
	return out;
*/
#endif