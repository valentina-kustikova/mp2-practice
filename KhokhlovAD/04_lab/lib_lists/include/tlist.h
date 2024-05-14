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

	TNode<T>* search(const T& data);

	virtual ~TList();
	void clear(); // virtual

	void Next();
	void Reset();

	bool IsEmpty()const;
	bool IsFool()const;
	bool IsEnd()const;

	void Sort();

	TNode<T>* getpF()const { return pFirst; };
	TNode<T>* getpS()const { return pStop; };
	TNode<T>* getpC()const { return pCurr; };

	T get_pFirst()const { return pFirst->data; };
	T get_pLast()const { return pLast->data; };
	T get_pCurr()const { return pCurr->data; };
	T get_pPrev()const { return pPrev->data; };

	virtual void InsertFirst(const T& data);
	void InsertLast(const T& data);
	void InsertBefore(const T& data, const TNode<T>* before_node);
	void InsertAfter(const T& data, const TNode<T>* after_node);
	void InsertBeforeCurrent(const T& data);
	void InsertAfterCurrent(const T& data);

	virtual void DeleteFirst();
	void DeleteLast();
	void DeleteBefore(const TNode<T>* before_node);
	void DeleteAfter(const TNode<T>* after_node);
	void DeleteData(const T& data);
	void DeleteCurrent();

	virtual const TList<T>& operator=(const TList<T>& pList);

	friend std::ostream& operator<<(std::ostream& out, TList<T>& list) {
		int num = 1;
		while (!list.IsEnd()) {
			out << num << " node " << list.get_pCurr() << std::endl;
			list.Next();
			num++;
		}
		list.Reset();
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
		pFirst = nullptr;
		pLast = nullptr;
		pCurr = nullptr;
		pPrev = nullptr;
		pStop = nullptr;
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
	pPrev = nullptr;
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
	while (tmp1 ->pNext != TList.pStop) {
		tmp1 = tmp1->pNext;
		tmp2->pNext = new TNode<T>(tmp1->data);
		pPrev = tmp2;
		tmp2 = tmp2->pNext;
	}
	pStop = nullptr;
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
	return pFirst == pStop;
}

template <typename T>
bool TList<T>::IsFool()const // Full
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
TNode<T>* TList<T>::search(const T& data) // pCurr, pPrev
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
	if (IsEmpty())
	{
		TNode<T>* node = new TNode<T>(data);
		pFirst = node;
		pLast = pFirst;
		pCurr = pFirst;
		pLast->pNext = pStop;
	}
	else
	{
		TNode<T>* node = new TNode<T>(data);
		TNode<T>* tmp = pFirst;
		pFirst = node;
		pFirst->pNext = tmp;
		Reset();
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
	pLast->pNext = pStop;
}

template <typename T>
void TList<T>::InsertBefore(const T& data, const TNode<T>* before_node)
{
	if (IsFool())
		throw std::exception("out of memor(InsB)");
	TNode<T>* new_node = new TNode<T>(data);
	pCurr = pFirst;
	while ((pCurr->pNext != pStop) && (new_node->pNext != before_node)) // Search
	{
		Next();
	}
	if ((pCurr->pNext == pStop) && (pCurr != before_node)) // InsertBeforeCurrent
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
	TNode<T>* new_node = new TNode<T>(data); // InsertAfterCurrent
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
		return;
	}
	if (IsEnd()) {
		InsertLast(data);
		return;
	}
	TNode<T>* new_node = new TNode<T>(data);
	if (new_node == NULL) { // IsFull
		throw std::exception("out of memory(InsBC)");
	}
	else {
		pPrev->pNext = new_node;
		pPrev = pPrev->pNext;
		pPrev->pNext = pCurr;
	}
	pCurr = pFirst;
	pPrev = nullptr;
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
		*this = TList<T>(); ///!!!!!!!!!!!
		return;
	}
	TNode<T>* tmp = pFirst->pNext;
	delete pFirst;
	pFirst = tmp;
	pCurr = pFirst;
}


template <typename T>
void TList<T>::DeleteLast()
{
	if(IsEmpty())
		throw std::exception("empty list(DelL)");
	if (pLast == pFirst)
	{
		*this = TList<T>(); ///!!!!!!!!!!!
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
void TList<T>::DeleteCurrent()
{
	if (IsEmpty())
		throw std::exception("empty list(DelC)");
	if (pCurr != pStop) // IsEnded
	{
		if (pCurr == pFirst) {
			DeleteFirst();
		}
		else {
			TNode<T>* tmp = pCurr;
			pPrev->pNext = pCurr->pNext;
			pCurr = pCurr->pNext;
			if (pPrev->pNext == pStop)
				pLast = pPrev;
			delete tmp;
		}
	}
}

template <typename T>
void TList<T>::DeleteBefore(const TNode<T>* before_node)
{
	if (IsEmpty())
		throw std::exception("empty list(DelB)");
	pCurr = pFirst;
	while (pCurr->pNext != pStop && pCurr->pNext != before_node) // search
		Next();
	if (pCurr->pNext == pStop && pCurr->pNext != before_node)
		throw std::exception("node not found(DelB)");
	if (pPrev == pStop)
	{
		DeleteFirst(); //?????
		pCurr = pFirst;
		return;
	}
	else
	{
		pPrev->pNext = pCurr->pNext;
		delete pCurr;
		pCurr = pFirst;
		pPrev = nullptr;
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
	while (pCurr->pNext != pStop && pCurr != after_node) // search
		Next();
	if (pCurr->pNext == pStop && pCurr != after_node)
		throw std::exception("node not found(DelB)");
	Next();
	pPrev->pNext = pCurr->pNext;
	delete pCurr;
	pPrev = pStop;
	pCurr = pFirst;
}

template <typename T>
void TList<T>::DeleteData(const T& data)
{
	if (IsEmpty())
		throw std::exception("empty list(DelD)");
	pCurr = pFirst;
	while (pCurr->pNext != pStop || pCurr->data != data) // search
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
	while (elem1->pNext != pStop)
	{
		TNode<T>* elem2 = elem1->pNext;
		while (elem2 != pStop)
		{
			if (elem1->data > elem2->data)
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
const TList<T>& TList<T>::operator=(const TList<T>& pList)
{
	if (pList.pFirst == pList.pStop)
		throw std::exception("Invalid pList (=)");
	if (this == &pList)
		return *this;
	clear();
	TNode<T>* pNode = pList.pFirst;
	while (pNode != pList.pStop)
	{
		InsertLast(pNode->data);
		pNode = pNode->pNext;
	}
	return *this;
}

template <typename T>
void TList<T>::Reset()
{
	if (IsEmpty()) {
		pCurr = pStop;
	}
	else {
		pCurr = pFirst;
		pPrev = pStop;
	}
	return;
}
#endif