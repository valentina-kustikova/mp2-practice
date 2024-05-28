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
	TNode<T>* search(const TNode<T>* node);

	virtual ~TList();
	virtual void clear(); 

	void Next();
	void Reset();

	bool IsEmpty()const;
	bool IsFull()const;
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
			out << num << " node = " << list.get_pCurr() << std::endl;
			list.Next();
			num++;
		}
		list.Reset();
		return out;
	}
	friend std::istream& operator>>(std::istream& in, TList<T>& list) {
		T data;
		int N;
		std::cout << "enter length of list = ";
		in >> N;
		for (int i = 0; i < N; i++)
		{
			std::cout << "enter data = ";
			in >> data;
			list.InsertFirst(data);
		}
		return in;
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
TList<T>::TList(const TNode<T>* pF)
{
	if (pF == nullptr)
	{
		pFirst = nullptr;
		pLast = nullptr;
		pCurr = nullptr;
		pPrev = nullptr;
		pStop = nullptr;
		return;
	}
	TNode<T>* tmp = pF->pNext;
	pFirst = new TNode<T>(pF->data);
	pLast = pFirst;
	pCurr = pFirst;
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
	if (TList.pFirst == TList.pStop)
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
	while (!IsEmpty()) {
		TNode<T>* tmp = pFirst;
		pFirst = pFirst->pNext;
		delete tmp;
	}
	pCurr = nullptr;
	pPrev = nullptr;
	pLast = nullptr;
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
bool TList<T>::IsFull()const 
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
	Reset();
	while (pCurr->pNext != pStop && pCurr->data != data)
	{
		Next();
	}
	if (pCurr->pNext == pStop && pCurr->data != data)
		throw std::exception("data not found(Search)");
	return pCurr;
}

template <typename T>
TNode<T>* TList<T>::search(const TNode<T>* node) 
{
	Reset();
	while (pCurr->pNext != pStop && pCurr->data != node->data)
	{
		Next();
	}
	if (pCurr->pNext == pStop && pCurr->data != node->data)
		throw std::exception("data not found(Search)");
	return pCurr;
}

template <typename T>
void TList<T>::InsertFirst(const T& data)
{
	if (IsFull())
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
	if (IsFull())
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
	if (IsFull())
		throw std::exception("out of memor(InsB)");
	TNode<T>* new_node = new TNode<T>(data);
	pCurr = pFirst;
	search(before_node);
	if ((pCurr->pNext == pStop) && (pCurr != before_node))
		throw std::exception("node not found(InsB)");
	InsertBeforeCurrent(data);
	Reset();
}

template <typename T>
void TList<T>::InsertAfter(const T& data, const TNode<T>* after_node)
{
	if (IsFull())
		throw std::exception("out of memory(InsA)");
	Reset();
	search(after_node);
	InsertAfterCurrent(data);
	Reset();
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
	if (IsFull()) { 
		throw std::exception("out of memory(InsBC)");
	}
	TNode<T>* new_node = new TNode<T>(data);
	pPrev->pNext = new_node;
	pPrev = pPrev->pNext;
	pPrev->pNext = pCurr;
	pCurr = pFirst;
	pPrev = pStop;
}

template <typename T>
void TList<T>::InsertAfterCurrent(const T& data)
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
	if (new_node == NULL) {
		throw std::exception("out of memory(InsAC)");
	}
	Next();
	pPrev->pNext = new_node;
	pPrev = pPrev->pNext;
	pPrev->pNext = pCurr;
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
		delete pFirst;
		pFirst = pStop; 
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
		delete pFirst;
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
	if (!IsEnd()) 
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
	else {
		DeleteLast();
	}
}

template <typename T>
void TList<T>::DeleteBefore(const TNode<T>* before_node)
{
	if (IsEmpty())
		throw std::exception("empty list(DelB)");
	Reset();
	search(before_node);
	if (pCurr->pNext == pStop && pCurr != before_node)
		throw std::exception("node not found(DelB)");
	if (pCurr == pFirst)
	{
		DeleteFirst(); 
		pCurr = pFirst;
		return;
	}
	else
	{
		pPrev->pNext = pCurr->pNext;
		delete pCurr;
		pCurr = pFirst;
		pPrev = pStop;
	}
	Reset();
}

template <typename T>
void TList<T>::DeleteAfter(const TNode<T>* after_node)
{
	if (IsEmpty())
		throw std::exception("empty list(DelA)");
	if (pLast == after_node)
		return;
	Reset();
	search(after_node);
	if (pCurr->pNext == pStop && pCurr != after_node)
		throw std::exception("node not found(DelB)");
	Next();
	pPrev->pNext = pCurr->pNext;
	delete pCurr;
	pPrev = pStop;
	pCurr = pFirst;
	Reset();
}

template <typename T>
void TList<T>::DeleteData(const T& data)
{
	if (IsEmpty())
		throw std::exception("empty list(DelD)");
	Reset();
	search(data);
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
	Reset();
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