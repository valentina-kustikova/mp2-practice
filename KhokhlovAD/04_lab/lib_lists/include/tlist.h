#ifndef _TLIST_
#define _TLIST
#include "tnode.h"

template <typename T>
class TList
{
private:
	TNode<T>* pFirst;
	TNode<T>* pLast;
	TNode<T>* pStop;
	TNode<T>* pCurr; 
public:
	TList();
	TList(TNode<T>* pF);
	TList(const TList<T>& tL);

	~TList();
	void clear();

	bool isEmpty()const;
	bool isEnd()const;
};

template <typename T>
TList<T>::TList()
{
	pFirst = nullptr;
	pLast = nullptr;
	pStop = nullptr;
	pCurr = nullptr;
}

template <typename T>
TList<T>::TList(TNode<T>* pF)
{
	pFirst = pF;
	pCurr = pFirst;
	TNode<T>* tmp = pFirst;
	if (pF != nullptr) {
		while (tmp->pNext != nullptr) {
			tmp = tmp->pNext;
		}
	}
	pLast = tmp;
	pStop = nullptr;
}


template <typename T>
TList<T>::TList(const TList<T>& tL)
{
	if (tL.pFirst == nullptr)
	{
		pFirst = nullptr;
		pLast = nullptr;
		pStop = nullptr;
		pCurr = nullptr;
		return;
	}
	pFirst = new TNode<T>(tL.pFirst->data);
	TNode<T>* tmp1 = tL.pFirst;
	TNode<T>* tmp2 = pFirst;
	pCurr = tmp2;
	while (tmp1 != tL.pStop) {
		tmp1 = tmp1->pNext;
		tmp2->pNext = new TNode<T>(tmp1->data);
		tmp2 = tmp2->pNext;
	}
	pLast = tmp2;
	pStop = nullptr;
	pLast->pNext = pStop;
}

template <typename T>
TList<T>::~TList()
{
	clear();
}

template <typename T>
void TList<T>::clear()
{
	TNode<T>* tmp = pFirst;
	while (tmp != pStop) {
		pFirst = pFirst->pNext;
		tmp->pNext = nullptr;
		delete tmp;
		if (tmp->pNext == nullptr) {
			break;
		}
		tmp = pFirst;
	}
	pCurr = pStop;
	pLast = pStop;
}

template <typename T>
bool TList<T>::isEmpty()const
{
	return pFirst == nullptr;
}

template <typename T>
bool TList<T>::isEnd()const
{
	return pCurr->pNext == pStop;
}
#endif