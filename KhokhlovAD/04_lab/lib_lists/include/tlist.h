#ifndef _TLIST_
#define _TLIST
#include "tnode.h"

template <typename T>
class TList
{
private:
	TNode<T>* pFirst;
	TNode<T>* pLast;
	TNode<T>* pCurr; 
public:
	TList();
	TList(const TNode<T>* pF);
	TList(const TList<T>& tL);

	void pop_first();
	void pop_last();
	void pop_curr();
	void remove(const TNode<T>* nd);
	void remove(const T& data);

	~TList();
	void clear();

	bool IsEmpty()const;
};

template <typename T>
TList<T>::TList()
{
	pFirst = nullptr;
	pLast = nullptr;
	pCurr = nullptr;
}

template <typename T>
TList<T>::TList(const TNode<T>* pF)
{
	if (pF == nullptr)
	{
		*this = TList<T>();
		return;
	}
	TNode<T>* tmp = pF->pNext;
	pFirst = new TNode<T>(pF->data);
	pCurr = pFirst;
	while (tmp!= nullptr) {
		pLast->pNext = new TNode<T>(tmp->data);
		pLast = pLast->pNext;
		tmp = tmp->pNext;
	}
}


template <typename T>
TList<T>::TList(const TList<T>& tL)
{
	if (tL.pFirst == nullptr)
	{
		pFirst = nullptr;
		pLast = nullptr;
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
	while (pFirst != nullptr) {
		TNode<T>* tmp = pFirst;
		pFirst = pFirst->pNext;
		tmp = tmp->pNext;
		delete tmp;
	}
	pCurr = nullptr;
	pLast = nullptr;
}

template <typename T>
bool TList<T>::IsEmpty()const
{
	return pFirst == nullptr;
}

template <typename T>
void TList<T>::pop_first()
{

}

template <typename T>
void TList<T>::pop_last()
{

}

template <typename T>
void TList<T>::pop_curr()
{

}



template <typename T>
void TList<T>::remove(const TNode<T>* nd)
{

}

template <typename T>
void TList<T>::remove(const T& data)
{

}
#endif