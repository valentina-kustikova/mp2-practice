#ifndef TRINGLIST_H
#define TRINGLIST_H

#include <iostream>
#include "tlist.h"

using namespace std;

template <typename T>
class TRingList : public TList<T> {
private:
	TNode<T>* pHead;
public:
	TRingList();
	TRingList(TNode<T>* _pFirst);
	TRingList(const TList<T>& obj);
	TRingList(const TRingList<T>& obj);
	virtual ~TRingList();
};

template <typename T>
TRingList<T>::TRingList() : TList() {
	pHead = new TNode<T>(pFirst); // ??? бнглнфмн ме пюанрюер я TMONOM !!!
	pStop = pHead;
}

template <typename T>
TRingList<T>::TRingList(TNode<T>* _pFirst) : TList(_pFirst) {
	pHead = new TNode<T>(pFirst); // !!! бнглнфмн ме пюанрюер я TMONOM !!!
	pStop = pHead;
}

template <typename T>
TRingList<T>::TRingList(const TList<T>& obj) : TList(obj) {
	pHead = new TNode<T>(pFirst); // !!! бнглнфмн ме пюанрюер я TMONOM !!!
	pStop = pHead;
}

template <typename T>
TRingList<T>::TRingList(const TRingList<T>& obj) {
	if (obj.pFirst == nullptr) return;					// бнглнфмн опнбепхрэ мю йнппейрмнярэ

	pFirst = new TNode<T>(obj.pFirst->key);
	TNode<T>* tmp = pFirst;
	TNode<T>* tmp2 = pFirst;

	while (tmp->pNext != obj.pStop) {
		tmp2->pNext = new TNode<T>(tmp->key);
		tmp2 = tmp2->pNext;
		tmp = tmp->pNext;
	}
	pLast = tmp2;
	
	pHead = new TNode<T>(pFirst);
	pStop = pHead;
}

template <typename T>
TRingList<T>::~TRingList() {
	if (pHead) delete pHead;
}

#endif // !TRINGLIST_H
