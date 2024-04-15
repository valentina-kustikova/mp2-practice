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

	virtual void Next();

	bool IsEmpty()const;
	bool IsFool()const;
	bool IsEnd()const;

	virtual void Sort();

	T get_pFirst()const { return pFirst->data; };
	T get_pLast()const { return pLast->data; };
	T get_pCurr()const { return pCurr->data; };
	T get_pPrev()const { return pPrev->data; };

	virtual void InsertFirst(const T& data);
	virtual void InsertLast(const T& data);
	virtual void InsertBefore(const T& data, const TNode<T>* before_node);
	virtual void InsertAfter(const T& data, const TNode<T>* after_node);
	virtual void InsertBeforeCurrent(const T& data);
	virtual void InsertAfterCurrent(const T& data);

	virtual void DeleteFirst();
	virtual void DeleteLast();
	virtual void DeleteBefore(const TNode<T>* before_node);
	virtual void DeleteAfter(const TNode<T>* after_node);
	virtual void DeleteData(const T& data);

	virtual TList<T>& operator=(const TList<T>& pList);

	friend std::ostream& operator<<(std::ostream& out, const TList<T>& list) {
		TNode<T>* tmp = list.GetPFirst();
		int num = 1;
		while (tmp != nullptr) {
			out << num << " node " << tmp->data << std::endl;
			tmp = tmp->pNext;
			num++;
		}
		return out;
	}
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
	this->pFirst = new TNode<T>(pFirst->data);
	this->pLast = this->pFirst;
	pCurr = this->pFirst;
	while (tmp != nullptr) {
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
bool TList<T>::IsEnd()const
{
	if (pCurr == pStop)
		return true;
	return false;
}


template <typename T>
TNode<T>* TList<T>::search(const T& data)
{
	TNode<T>* tmp = pFirst;
	while (tmp->pNext != pStop && tmp->data != data)
	{
		tmp = tmp->pNext;
	}
	if (tmp->pNext == pStop && tmp->data != data)
		throw std::exception("data not found(Search)");
	return tmp;
}

template <typename T>
void TList<T>::InsertFirst(const T& data)
{
	if (IsFool())
		throw std::exception("out of memory(InsF)");
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
		throw std::exception("out of memory(InsL)");
	if (IsEmpty())
	{
		InsertFirst(data);
		return;
	}
	pLast->pNext = new TNode<T>(data);
	pLast = pLast->pNext;
}

template <typename T>
void TList<T>::InsertBefore(const T& data, const TNode<T>* before_node)
{
	if (IsFool())
		throw std::exception("out of memor(InsB)");
	TNode<T>* new_node = new TNode<T>(data);
	pCurr = pFirst;
	while ((pCurr->pNext != pStop) && (new_node->pNext != before_node))
	{
		Next();
	}
	if ((pCurr->pNext == pStop) && (pCurr != before_node))
		throw std::exception("node not found(InsB)");
	if (pPrev == pStop)
		InsertFirst(data);
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
		throw std::exception("out of memory(InsA)");
	TNode<T>* tmp = search(after_node->data);
	TNode<T>* new_node = new TNode<T>(data);
	if (tmp == pStop)
		throw std::exception("node not found(InsA)");
	new_node->pNext = tmp->pNext;
	tmp->pNext = new_node;
	if (tmp == pLast)
		pLast = new_node;
}

template <typename T>
void TList<T>::InsertBeforeCurrent(const T& data)
{
	if (IsEmpty()) {
		InsertFirst(data);
	}
	else if (IsEnd()) {
		InsertLast(data);
	}
	else {
		TNode<T>* new_node = new TNode<T>(data);
		if (new_node == NULL) {
			throw std::exception("out of memory(InsBC)");
		}
		else {
			pPrev->pNext = new_node;
			pPrev = pPrev->pNext;
			pPrev->pNext = pCurr;
		};
	}
	pCurr = pFirst;
	pPrev = pStop;
}

template <typename T>
void TList<T>::InsertAfterCurrent(const T& data)
{
	if (IsEmpty()) {
		InsertFirst(data);
	}
	else if (IsEnd()) {
		InsertLast(data);
	}
	else {
		TNode<T>* new_node = new TNode<T>(data);
		if (new_node == NULL) {
			throw std::exception("out of memory(InsAC)");
		}
		else {
			Next();
			pPrev->pNext = new_node;
			pPrev = pPrev->pNext;
			pPrev->pNext = pCurr;
		};
	}
	pCurr = pFirst;
	pPrev = pStop;
}

template <typename T>
void TList<T>::DeleteFirst()
{
	if (IsEmpty())
		throw std::exception("empty list(DelF)");
	if (pFirst == pLast)
	{
		*this = TList<T>();
		return;
	}
	TNode<T>* tmp = pFirst->pNext;
	delete pFirst;
	pFirst = tmp;
}


template <typename T>
void TList<T>::DeleteLast()
{
	if(IsEmpty())
		throw std::exception("empty list(DelL)");
	if (pLast == pFirst)
	{
		*this = TList<T>();
		return;
	}
	pCurr = pFirst;
	while (pCurr->pNext != pStop)
		Next();
	delete pCurr;
	pPrev->pNext = pStop;
	pLast = pPrev;
	pCurr = pFirst;
	pPrev = pStop;
}
template <typename T>
void TList<T>::DeleteBefore(const TNode<T>* before_node)
{
	if (IsEmpty())
		throw std::exception("empty list(DelB)");
	pCurr = pFirst;
	while (pCurr->pNext != pStop || pCurr->pNext != before_node)
		Next();
	if (pCurr->pNext == pStop && pCurr->pNext != before_node)
		throw std::exception("node not found(DelB)");
	if (pPrev == pStop)
		return;
	else
	{
		pPrev->pNext = pCurr->pNext;
		delete pCurr;
		pCurr = pFirst;
		pPrev = pStop;
	}

}

template <typename T>
void TList<T>::DeleteAfter(const TNode<T>* after_node)
{
	if (IsEmpty())
		throw std::exception("empty list(DelA)");
	if (pLast == after_node)
		return;
	pCurr = pFirst;
	while (pCurr->pNext != pStop || pCurr != after_node)
		Next();
	if (pCurr->pNext == pStop && pCurr != after_node)
		throw std::exception("node not found(DelB)");
	if (pPrev == pStop)
		return;
	else 
	{
		Next();
		pPrev->pNext = pCurr->pNext;
		delete pCurr;
		pPrev = pStop;
		pCurr = pFirst;
	}
}

template <typename T>
void TList<T>::DeleteData(const T& data)
{
	if (IsEmpty())
		throw std::exception("empty list(DelD)");
	pCurr = pFirst;
	while (pCurr->pNext != pStop || pCurr->data != data)
		Next();
	if (pCurr->pNext != pStop && pCurr->data != data)
		throw std::exception("data not found(DelD)");
	if (pPrev == pStop)
		DeleteFirst();
	else
	{
		pPrev->pNext = pCurr->pNext;
		delete pCurr;
		pCurr = pFirst;
		pPrev = pStop;
	}
}

template <typename T>
void TList<T>::Sort() 
{
	TNode<T>* elem1 = pFirst;
	while (elem1->pNext != nullptr)
	{
		TNode<T>* elem2 = elem1->pNext;
		while (elem2 != nullptr)
		{
			if (elem1->data < elem2->data)
			{
				T tmp = elem1->data;
				elem1->data = elem2->data;
				elem2->data = tmp;
			}
			elem2 = elem2->pNext;
		}
		elem1 = elem1->pNext;
	}
}

template <typename T>
TList<T>& TList<T>::operator=(const TList<T>& pList)
{
	if (pList.pFirst == nullptr)
		throw std::exception("Invalid pList (=)");
	TNode<T>* oldCurrent = pList.pFirst;
	pFirst = new TNode<T>(*pList.pFirst);
	TNode<T>* newCurrent = pFirst;
	oldCurrent = oldCurrent->pNext;
	while (oldCurrent != pList.pStop)
	{
		newCurrent->pNext = new TNode<T>(oldCurrent->data);
		newCurrent = newCurrent->pNext;
		oldCurrent = oldCurrent->pNext;
	}
	pLast = newCurrent;
	pStop = pLast->pNext;
	pCurr = pFirst;
	pStop = nullptr;

	return *this;
}
#endif