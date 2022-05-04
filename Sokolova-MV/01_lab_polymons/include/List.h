#pragma once

#include <cstddef>
#include <iostream>


using namespace std;

template<class TData>//разбить
class TNode
{
public:
	TData data;
	TNode* pNext;
	TNode(TData _data = nullptr, TNode* _pNext = nullptr)//NULL убрать
	{
		data = _data;
		pNext = _pNext;
	}
	TNode(const TNode& node)
	{
		data = node.data;
		pNext = nullptr;
	}
};


template<class TData>
class TList
{
protected:
	TNode<TData>* pFirst, * pLast, * pCurr, * pPrev, * pStop;
	int len;
public:
	TList()
	{
		pFirst = pLast = pCurr = pPrev = pStop = NULL;
		len = 0;
	}
	~TList()
	{
		while (pFirst != pStop)
		{
			TNode<TData>* del = pFirst;
			pFirst = pFirst->pNext;
			delete del;
		}
	}

	int getLen() const { return len; }

	TData getCurrdata() const
	{
		if (pCurr != pStop)
			return pCurr->data;
		else
			throw ("Список пустой");
	}

	void setCurrdata(const TData& _data)
	{
		pCurr->data = _data;/**/
	}


	void InsertToHead(const TData& data)
	{
		TNode<TData>* newFirst = new TNode<TData>(data, pFirst);
		pCurr = newFirst;
		pFirst = newFirst;
		len++;
		if (len == 1)
		{
			pLast = newFirst;
			pLast->pNext = pStop;
		}/**/
	}

	void insCurrent(const TData& data)
	{
		if (pCurr == pFirst) {
			InsertToHead(data);
		}
		else if (pPrev == pLast) {
			insLast(data);
		}
		else {
			TNode<TData>* node = new TNode<TData>(data, pCurr);
			pPrev->pNext = node;
			pCurr = node;
			len++;
		}

	}
	void insLast(const TData& data)
	{
		TNode<TData>* node = new TNode<TData>(data, pStop);
		if (pLast != pStop) {
			pLast->pNext = node;
			pLast = node;
		}
		else {
			pFirst = node;
			pLast = node;
		}
		len++;
	}

	void RemoveFirst()
	{
		if (pFirst != pStop) {
			TNode<TData>* delNode = pFirst;
			pFirst = pFirst->pNext;
			pCurr = pFirst;
			delete delNode;
			len--;
			if (len == 0) {
				pLast = pStop;
			}
		}
	}
	void RemoveCurr()
	{
		if (pCurr != pStop)
			if (pCurr == pFirst) {
				RemoveFirst();
			}
			else {
				TNode<TData>* delNode = pCurr;
				pCurr = pCurr->pNext;
				if (pPrev->pNext == pLast)
					pLast = pPrev;
				pPrev->pNext = pCurr;
				delete delNode;
				len--;
			}
	}

	bool isEmpty()
	{
		return (len == 0);
	}

	void reset()
	{
		pCurr = pFirst;
		pPrev = pStop;
	}

	void goNext()
	{
		pPrev = pCurr;
		pCurr = pCurr->pNext;
	}


	bool isEnd()
	{
		return pCurr == pStop;
	}

	friend ostream& operator<<(ostream& os, TList<TData>& list)
	{
		for (list.reset(); !list.isEnd(); list.goNext())
		{
			//os << list.check();
			os << list.getCurrdata() << " ";
		}
		list.reset();
		os << "\n";
		return os;
	}
};
