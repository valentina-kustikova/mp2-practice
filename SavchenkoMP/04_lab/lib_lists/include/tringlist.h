#ifndef TRINGLIST_H
#define TRINGLIST_H

#include <iostream>
#include "tlist.h"
#include "tdata.h"

using namespace std;

template <typename T>
class TRingList : public TList<T> {
private:
	TNode<T>* pHead;
public:
	TRingList();
	TRingList(const TNode<T>* _pFirst, const TNode<T>* _pHead = nullptr);
	TRingList(const TRingList<T>& obj);
	//TRingList(const TList<T>& obj, const TNode<T>* _pHead = nullptr);
};

template <typename T>
TRingList<T>::TRingList() {
	pFirst = nullptr;
	pLast = nullptr;
	pCurr = nullptr;
	pStop = nullptr;
	pHead = nullptr;
}

template <typename T>
TRingList<T>::TRingList(const TNode<T>* _pFirst, const TNode<T>* _pHead) {
	pHead = _pHead
	pStop = pHead;
	pFirst = _pFirst;
	pCurr = pFirst;

	TNode<T>* tmp = pFirst;
	while (tmp->pNext != pStop)
		tmp = tmp->pNext;
	pLast = tmp;
}

template <typename T>
TRingList<T>::TRingList(const TRingList<T>& obj) {
	if (obj.pFirst == nullptr) return; // œ–Œ¬≈–»“‹ Õ¿  Œ––≈ “ÕŒ—“‹

	pFirst = new TNode<T>(obj.pFirst);
	TNode<T>* tmp = pFirst;
	TNode<T>* tmp2 = pFirst;

	while (tmp->pNext != obj.pStop) {
		tmp2->pNext = new TNode<T>(tmp->key);
		tmp2 = tmp2->pNext;
		tmp = tmp->pNext;
	}
	pLast = tmp2;
	pCurr = pFirst;
	pStop = pLast->pNext;
	pHead = pLast->pNext;
}

#endif // !TRINGLIST_H
