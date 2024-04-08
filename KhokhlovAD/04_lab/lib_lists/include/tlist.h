#ifndef _TLIST_
#define _TLIST
#include "tnode.h"
#include <iostream>

template <typename T>
class TList
{
protected:
	TNode<T>* pFirst;
	TNode<T>* pLast;
	TNode<T>* pCurr; 
	TNode<T>* pPrev;
	TNode<T>* pStop; 
public:
	TList();
	TList(const TNode<T>* pFirst);
	TList(const TList<T>& TList);

	virtual TNode<T>* search(const T& data);

	~TList();
	virtual void clear();

	void Next();

	bool IsEmpty()const;
	bool IsFool()const;

	virtual void InsertFirst(const T& data);
	virtual void InsertLast(const T& data);
	virtual void InsertBefore(const T& data, const TNode<T>* before_node);
	virtual void InsertAfter(const T& data, const TNode<T>* after_node);

	virtual void DeleteFirst();
	virtual void DeleteLast();
	virtual void DeleteBefore(const TNode<T>* before_node);
	virtual void DeleteAfter(const TNode<T>* after_node);
	virtual void DeleteData(const T& data);
};

template <typename T>
TList<T>::TList()
{
	pFirst = nullptr;
	pLast = nullptr;
	pCurr = nullptr;
	pPrev = nullptr;
	pStop = nullptr;
}

template <typename T>
TList<T>::TList(const TNode<T>* pFirst)
{
	if (pFirst == nullptr)
	{
		*this = TList<T>();
		return;
	}
	TNode<T>* tmp = pFirst->pNext;
	this->pFirst = new TNode<T>(pF->data);
	pCurr = this->pFirst;
	while (tmp!= nullptr) {
		pLast->pNext = new TNode<T>(tmp->data);
		pLast = pLast->pNext;
		tmp = tmp->pNext;
	}
	pStop = nullptr;
	pPrev = pStop;
}


template <typename T>
TList<T>::TList(const TList<T>& TList)
{
	if (TList.pFirst == nullptr)
	{
		pFirst = nullptr;
		pLast = nullptr;
		pCurr = nullptr;
		pPrev = nullptr;
		pStop = nullptr;
		return;
	}
	pFirst = new TNode<T>(TList.pFirst->data);
	TNode<T>* tmp1 = TList.pFirst;
	TNode<T>* tmp2 = pFirst;
	pCurr = tmp2;
	while (tmp1 != TList.pStop) {
		tmp1 = tmp1->pNext;
		tmp2->pNext = new TNode<T>(tmp1->data);
		pPrev = tmp2;
		tmp2 = tmp2->pNext;
	}
	pLast = tmp2;
	pLast->pNext = pStop;
	pStop = TList.pStop;
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
	pPrev = nullptr;
	pLast = nullptr;
	pStop = nullptr;
}

template <typename T>
void TList<T>::Next()
{
	if (pCurr == pStop)
		return;
	pPrev = pCurr;
	pCurr = pCurr->pNext;
}

template <typename T>
bool TList<T>::IsEmpty()const
{
	return pFirst == nullptr;
}

template <typename T>
bool TList<T>::IsFool()const
{
	TNode<T>* tmp = new (std::nothrow) TNode<T>();
	if (tmp)
		return false;
	else
		return true;
	
}


template <typename T>
TNode<T>* TList<T>::search(const T& data)
{
	TNode<T>* tmp = pFirst;
	while (tmp->pNext != pStop || tmp->data != data)
	{
		tmp = tmp->pNext;
	}
	if (tmp == pStop)
		throw std::exception("data not found");
	return tmp;
}

template <typename T>
void TList<T>::InsertFirst(const T& data)
{
	if (IsFool())
		throw std::exception("out of memory while insert first");
	if (pFirst == pStop)
	{
		TNode<T>* node = new TNode<T>(data);
		pFirst = node;
		pLast = pFirst;
		pCurr = pFirst;
	}
	else
	{
		TNode<T>* node = new TNode<T>(data);
		TNode<T>* tmp = pFirst;
		pFirst = node;
		pFirst->pNext = tmp;
	}
}

template <typename T>
void TList<T>::InsertLast(const T& data)
{
	if (IsFool())
		throw std::exception("out of memory while insert last");
	if (IsEmpty())
	{
		InsertFirst(data);
		return;
	}
	TNode<T>* node = new TNode<T>(data);
	pLast->pNext = node;
	pLast = pLast->pNext;
	pLast->pNext =pStop;
}

template <typename T>
void TList<T>::InsertBefore(const T& data, const TNode<T>* before_node)
{
	if (IsFool())
		throw std::exception("out of memory while insert before");
	TNode<T>* new_node = new TNode<T>(data);
	pCurr = pFirst;
	while (pCurr->pNext != pStop || tmp->pNext != before_node)
	{
		Next();
	}
	if (pCurr->pNext == pStop && pCurr != new_node)
		throw std::exception("data not found");
	if (pPrev == pStop)
		InsertFirst(new_node);
	else
	{
		pPrev->pNext = new_node;
		pPrev = pPrev->pNext;
		pPrev->pNext = pCurr;
	}
	pCurr = pFirst;
	pPrev = pStop;
}

template <typename T>
void TList<T>::InsertAfter(const T& data, const TNode<T>* after_node)
{
	if (IsFool())
		throw std::exception("out of memory while insert after");
	TNode<T>* tmp = search(after_node);
	TNode<T>* new_node = new TNode<T>(data);
	if (tmp == pStop)
		throw std::exception("after_node not exist");
	new_node->pNext = tmp->pNext;
	tmp->pNext = new_node;
	if (tmp == pLast)
		pLast = new_node;
}

template <typename T>
void TList<T>::DeleteFirst()
{
	if (IsEmpty())
		throw std::exception("empty list");

}


template <typename T>
void TList<T>::DeleteLast();
template <typename T>
void TList<T>::DeleteBefore(const TNode<T>* before_node);
template <typename T>
void TList<T>::DeleteAfter(const TNode<T>* after_node);
template <typename T>
void TList<T>::DeleteData(const T& data);
#endif