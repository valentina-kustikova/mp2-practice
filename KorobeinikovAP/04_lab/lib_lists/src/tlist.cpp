#include "tlist.h"


template<typename T>
TList<T>::TList() {
	pFirst = nullptr;
	pCurr = nullptr;
	pLast = nullptr;
	pStop = nullptr;
}


template<typename T>
TList<T>::TList(const TNode<T>* pFirst_) {
	pFirst = pFirst_;
	pStop = nullptr;
	TNode* tmp = pFirst;
	while (tmp->pNext != pStop) {
		tmp = tmp->pNext;
	}
	pLast = tmp;
	pCurr = pFirst;
}


template<typename T>
TList<T>::TList(const TList<T>& obj) {
	if (obj.pFirst == nullptr) { return; }
	TNode* tmp = obj.pFirst;
	pFirst = new TNode<T>(obj.pFirst);
	TNode<T>* tmp2 = pFirst;
	tmp = tmp->pNext;
	while (tmp != obj.stop) {
		tmp2->pNext = new TNode<T>(tmp->data);
		tmp2 = tmp2->pNext;
		tmp = tmp->pNext;
	}
	pLast = tmp2;
	pStop = pLast->pNext;
	pCurr = pFirst;
}