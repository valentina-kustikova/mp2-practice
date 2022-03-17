#pragma once

#include <cstddef>
#include <iostream>
#include "List.h"


using namespace std;

template <class TData>
class THeadList : public TList<TData>
{
protected:
	TNode<TData>* pHead;
public:
	THeadList()
	{
		pHead = new TNode<TData>(NULL);
		pHead->pNext = pHead;
		pCurr = pPrev = pLast = pFirst = pStop = pHead;
		len = 0;
	}
	~THeadList()
	{
		while (pFirst != pStop) {
			TNode<TData>* node = pFirst;
			pFirst = pFirst->pNext;
			delete node;
		}
		delete pHead;
	}

	virtual void InsertToHead(const TData& data)
	{
		TList::InsertToHead(data);
		pHead->pNext = pFirst;
	}
	virtual void RemoveFirst()
	{
		TList::RemoveFirst();
		pHead->pNext = pFirst;
	}

	friend ostream& operator <<(ostream& os, THeadList<TData>& headList)
	{
		for (headList.reset(); !headList.isEnd(); headList.goNext()) {
			os << headList.getCurrdataue() << " ";
		}
		headList.reset();
		os << "\n";
		return os;
	}
};

