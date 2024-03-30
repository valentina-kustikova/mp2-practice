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
	TNode(TNode<T>* pNext_) : data(), pNext(pNext_) {};
	TNode(const T& data_, TNode<T>* pNext_) : data(data_), pNext(pNext_) {};
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
	TList(TNode<T>* _pFirst);
	TList(const TList<T>& list);
	~TList();

	virtual TNode<T>* Search(const T& data);
	virtual void InsertFirst(const T& data);
	virtual void InsertEnd(const T& data);
	virtual void InsertAfter(const T& data, const T& beforedata);
	virtual void InsertBefore(const T& data, const T& nextdata);
	virtual void InsertBeforeCurr(const T& data);
	virtual void InsertAfterCurr(const T& data);
	virtual void Remove(const T& data);
	virtual void Clear();
	virtual int GetSize() const;
	virtual bool IsEmpty() const;
	virtual bool IsFull() const;
	virtual bool IsEnded() const;
	virtual TNode<T>* GetCurrent();
	virtual TNode<T>* GetStop();
	virtual void Next();  //переход к следующему эл
	virtual void Reset(); //текущий становится первым
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
TList<T>::TList(TNode<T>* _pFirst)
{
	pFirst = _pFirst;
	pStop = nullptr;
	pPrev = nullptr;
	if (pFirst == pStop)
	{
		pLast = pStop;
		pCurr = pStop;
		return;
	}
	pCurr = pFirst;
	TNode<T>* tmp = pFirst;
	while (tmp->pNext != pStop)
		tmp = tmp->pNext;
	pLast = tmp;
	pStop = pLast->pNext;
}
template <typename T>
TList<T>::TList(const TList<T>& list)
{
	if (list.pFirst == nullptr)
		return;
	pFirst = new TNode<T>(list.pFirst->data);
	TNode<T>* tmp = list.pFirst->pNext;
	TNode<T>* tmp2 = pFirst;
	while (tmp != list.pStop)
	{
		tmp2->pNext = new TNode<T>(tmp->data);
		tmp2 = tmp2->pNext;
		tmp = tmp->pNext;
	}
	pPrev = nullptr;
	pCurr = pFirst;
	pLast = tmp2;
	pStop = nullptr;
}
template <typename T>
void TList<T>::Clear()
{
	TNode<T>* tmp = pFirst;
	while (tmp != pStop)
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
	if (pFirst == pStop)
		pLast = pNode;
	pNode->pNext = pFirst;
	pFirst = pNode;
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
	TNode<T>* pNode = new TNode<T>(data, pStop);
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
TNode<T>* TList<T>::GetStop()
{
	return pStop;
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
