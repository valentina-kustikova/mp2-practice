#ifndef _TLIST_
#define _TLIST
#include "tnode.h"
#include <iostream>

template <typename T>
class TList
{
private:
	TNode<T>* pFirst;
	TNode<T>* pLast;
	TNode<T>* pCurr; 
	TNode<T>* pStop; //nujen dlya nasled ringlist
public:
	TList();
	TList(const TNode<T>* pF);
	TList(const TList<T>& tL);

	void pop_first();
	void pop_last();
	void pop_curr();
	void remove(const TNode<T>* nd);
	void remove(const T& data);

	void push_first();
	void push_last();
	void push_curr();
	void add_before();
	void add_after();

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
	pStop = nullptr;
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
	pStop = nullptr;
}


template <typename T>
TList<T>::TList(const TList<T>& tL)
{
	if (tL.pFirst == nullptr)
	{
		pFirst = nullptr;
		pLast = nullptr;
		pCurr = nullptr;
		pStop = nullptr;
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
	pStop = tL.pStop;
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
	pStop = nullptr;
}

template <typename T>
bool TList<T>::IsEmpty()const
{
	return pFirst == nullptr;
}

template <typename T>
void TList<T>::pop_first()
{
	if (this->IsEmpty())
		throw std::exception("empty list");
	if (pLast == pFirst)
	{
		*this = TList<T>();
		return;
	}
	if (pCurr == pFirst)
		pCurr = pFirst->pNext;
	TNode<T>* tmp = pFirst->pNext;
	delete pFirst;
	pFirst = tmp;
}

template <typename T>
void TList<T>::pop_last()
{
	if (this->IsEmpty())
		throw std::exception("empty list");
	if (pLast == pFirst)
	{
		*this = TList<T>();
		return;
	}
	TNode<T>* tmp = pFirst;
	while (tmp->pNext != pLast)
		tmp = tmp->pNext;
	if (pCurr == pLast)
		pCurr = tmp;
	delete tmp->pNext;
	tmp->pNext = nullptr;
	pLast = tmp;
}

template <typename T>
void TList<T>::pop_curr()
{
	if(this->IsEmpty())
		throw std::exception("empty list");
	if (pCurr == pFirst)
	{
		this->pop_first(); return;
	}
	if (pCurr == pLast)
	{
		this->pop_last(); return;
	}
	TNode<T>* tmp1 = pFirst, *tmp2 = pCurr;
	while (tmp1->pNext != pCurr)
		tmp1 = tmp1->pNext;
	pCurr = pCurr->pNext;
	tmp1->pNext = pCurr;
	delete tmp2;
}



template <typename T>
void TList<T>::remove(const TNode<T>* nd)
{
	if (this->IsEmpty())
		throw std::exception("empty list");
	if (nd == nullptr)
		return;
	if (nd == pFirst)
		this->pop_first();
	if (nd == pLast)
		this->pop_last();
	TNode<T>* tmp = pFirst;
	while (tmp->pNext != nd && tmp->pNext != nullptr)
		tmp = tmp->pNext;
	if (tmp->pNext == nullptr)
		return;
	TNode<T>* tmp1 = tmp->pNext->pNext;
	if (pCurr == nd)
		pCurr = tmp1;
	delete tmp->pNext;
	tmp->pNext = tmp1;
}

template <typename T>
void TList<T>::remove(const T& data)
{

}
#endif