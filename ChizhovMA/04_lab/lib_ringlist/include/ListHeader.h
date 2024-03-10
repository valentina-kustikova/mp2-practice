#ifndef _LIST_HEADER_H
#define _LIST_HEADER_H

#include <iostream>

using namespace std;

template <typename T>
struct TNode
{
	T data;
	TNode<T>* pNext;
	TNode() : data(), pNext(nullptr) {};
	TNode(const T& data_) : data(data_), pNext(nullptr) {};
	TNode(const T& data_, TNode<T>* pNext_) : data(data_), pNext(pNext_) {};
	TNode(const TNode& other) : data(other.data), pNext(other.pNext) {};
	~TNode() {};
};

template <typename T>
class TList
{
protected:
	TNode<T>* pFirst;
	TNode<T>* pPrev;
	TNode<T>* pCurr;
	TNode<T>* pStop;
	TNode<T>* pLast;
public:
	TList();
	TList(const TNode<T>* _pFirst);
	TList(const TList<T>& list);
	~TList();

	TNode<T>* Search(const T& data);
	void InsertFirst(const T& data);
	void InsertEnd(const T& data);
	void InsertAfter(const T& data, const T& beforedata);
	void InsertBefore(const T& data, const T& nextdata);
	void InsertBeforeCurr(const T& data);
	void InsertAfterCurr(const T& data);
	void Remove(const T& data);
	void Clear();
	int GetSize() const;
	bool IsEmpty() const;
	bool IsFull() const;
	bool IsEnded() const;
	TNode<T>* GetCurrent();
	void Next();  //переход к следующему эл
	void Reset(); //текущий становится первым
};


template <typename T>
TList<T>::TList()
{
	pFirst = nullptr;
	pPrev = nullptr;
	pCurr = nullptr;
	pStop = nullptr;
	pLast = nullptr;
}
template <typename T>
TList<T>::TList(const TNode<T>* _pFirst)
{
	pFirst = _pFirst;
	pPrev = nullptr;
	pCurr = pFirst;
	pStop = nullptr;
	TNode<T>* tmp = pFirst;
	while (tmp->pNext != pStop)
		tmp = tmp->pNext;
	pLast = tmp;
}
template <typename T>
TList<T>::TList(const TList<T>& list)
{
	if (list.pFirst == nullptr)
		return;
	pFirst = new TNode<T>(list.pFirst->data, list.pFirst->pNext);
	TNode<T>* tmp = pFirst;
	TNode<T>* tmp2 = pFirst;
	tmp = tmp->pNext;
	while (tmp != list.pStop)
	{
		tmp2->pNext = new TNode<T>(tmp->data);
		tmp2 = tmp2->pNext;
		tmp = tmp->pNext;
	}
	pPrev = nullptr;
	pCurr = pFirst;
	pStop = tmp2->pNext;
	pLast = tmp2;
}
template <typename T>
void TList<T>::Clear()
{
	TNode<T>* tmp = pFirst;
	while (pFirst != nullptr)
	{
		pFirst = pFirst->pNext;
		delete tmp;
		tmp = pFirst;
	}
	pCurr = pPrev = pStop = pLast = nullptr;
}
template <typename T>
TList<T>::~TList()
{
	Clear();
}
template <typename T>
TNode<T>* TList<T>::Search(const T& data)
{
	TNode<T>* tmp = pFirst;
	while (tmp != pStop && tmp->data != data)
		tmp = tmp->pNext;
	return tmp;
}
template <typename T>
void TList<T>::InsertFirst(const T& data)
{
	TNode<T>* pNode = new TNode<T>(data);
	if (pFirst != pStop)
		pNode->pNext = pFirst;
	pFirst = pNode;
	pLast = pNode;
	pCurr = pFirst;
}
template <typename T>
void TList<T>::InsertEnd(const T& data)
{
	if (pFirst == pStop)
	{
		InsertFirst(data);
		return;
	}
	TNode<T>* pNode = new TNode<T>(data);
	pLast->pNext = pNode;
	pLast = pNode;
}

template <typename T>
void TList<T>::InsertAfter(const T& data, const T& beforedata)
{
	TNode<T>* pPrev = Search(beforedata);
	if (pPrev != pStop)
	{
		if (pPrev->pNext == pStop)
		{
			InsertEnd(data);
			return;
		}
		TNode<T>* pNode = new TNode<T>(data);
		pNode->pNext = pPrev->pNext;
		pPrev->pNext = pNode;
	}
	else
	{
		string msg = "Element not found!";
		throw msg;
	}
}
template <typename T>
void TList<T>::InsertBefore(const T& data, const T& nextdata)
{
	if (pFirst != pStop && pFirst->data == nextdata)
		InsertFirst(data);
	else
	{
		TNode<T>* tmp = pFirst;
		pPrev = nullptr;
		while (tmp != pStop && tmp->data != nextdata)
		{
			pPrev = tmp;
			tmp = tmp->pNext;
		}
		if (tmp != pStop)
		{
			TNode<T>* pNode = new TNode<T>(data);
			pNode->pNext = tmp;
			pPrev->pNext = pNode;
		}
		else
		{
			string msg = "Element not found!";
			throw msg;
		}
	}
}
template <typename T>
void TList<T>::InsertBeforeCurr(const T& data)
{
	InsertBefore(data, pCurr->data);
}
template <typename T>
void TList<T>::InsertAfterCurr(const T& data)
{
	InsertAfter(data, pCurr->data);
}
template <typename T>
void TList<T>::Remove(const T& data)
{
	if (IsEmpty())
	{
		string msg = "Error";
		throw msg;
	}
	TNode<T>* pNode = pFirst;
	pPrev = nullptr;
	while (pNode->pNext != pStop && pNode->data != data)
	{
		pPrev = pNode;
		pNode = pNode->pNext;
	}
	if (pNode->pNext == pStop && pNode->data != data)
	{
		string msg = "Error";
		throw msg;
	}
	if (pPrev == nullptr)
	{
		pFirst = pFirst->pNext;
		pCurr = pFirst;
		delete pNode;
		return;
	}
	pPrev->pNext = pNode->pNext;
	delete pNode;
}
template <typename T>
int TList<T>::GetSize() const
{
	int count = 0;
	TNode<T>* tmp = pFirst;
	while (tmp != pStop)
	{
		count++;
		tmp = tmp->pNext;
	}
	return count;
}
template <typename T>
bool TList<T>::IsEmpty() const
{
	return pFirst == nullptr;
}
template <typename T>
bool TList<T>::IsFull() const
{
	return !IsEmpty();
}
template <typename T>
bool TList<T>::IsEnded() const
{
	return pCurr == pStop;
}
template <typename T>
TNode<T>* TList<T>::GetCurrent()
{
	return pCurr;
}
template <typename T>
void TList<T>::Next()
{
	if (pCurr != pStop)
		pCurr = pCurr->pNext;
}
template <typename T>
void TList<T>::Reset()
{
	pCurr = pFirst;
}
#endif
