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
		this->pCurr = this->pPrev = this->pLast = this->pFirst = this->pStop = pHead;
		this->len = 0;
	}
	~THeadList()
	{
		while (this->pFirst != this->pStop) {
			TNode<TData>* node = this->pFirst;
			this->pFirst = this->pFirst->pNext;
			delete node;
		}
		delete pHead;
	}

	virtual void InsertToHead(const TData& data)
	{
		TList<TData>::InsertToHead(data);
		pHead->pNext = this->pFirst;
	}
	virtual void RemoveFirst()
	{
		TList<TData>::RemoveFirst();
		pHead->pNext = this->pFirst;
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
