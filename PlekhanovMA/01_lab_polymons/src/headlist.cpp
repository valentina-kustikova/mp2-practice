#include "headlist.h"
#include "list.h"

THeadList::THeadList()
{
	TData datahead;
	datahead.coeff = 1000;
	datahead.degree = -111;
	datahead.degx = -1;
	datahead.degy = -1;
	datahead.degz = -1;
	TNode* temp = new TNode(datahead);
	pHead = temp;
	pStop = pHead;
}

THeadList::~THeadList()
{

}

void THeadList::InsertToTail(TData const data)
{
	TNode* tempcurr = new TNode;
	tempcurr = pCurr;
	if (IsEmpty() == 1)
	{
		TNode* newend = new TNode(data);
		this->pFirst = newend;
		this->pFirst->pNext = this->pHead;
		this->pHead->pNext = this->pFirst;
		this->pCurr = this->pFirst;
		this->pNext = this->pHead;
		this->Size++;
		tempcurr = pCurr;
	}
	else
	{
		if (IsEnded() == 0)
		{
			while (IsEnded() == 0)
				Next();
		}
		TNode* newend = new TNode(data);
		newend->pNext = this->pStop;
		this->pCurr->pNext = newend;
		this->pCurr = newend;
		this->pNext = this->pStop;
		this->Size++;
	}
	pCurr = tempcurr;
	pNext = pCurr->pNext;
}

void THeadList::InsertToHead(TData const data)
{
	TNode* tempcurr = new TNode;
	tempcurr = pCurr;
	if (IsEmpty() == 1)
	{
		TNode* newfirst = new TNode(data);
		this->pFirst = newfirst;
		this->pFirst->pNext = this->pHead;
		this->pHead->pNext = this->pFirst;
		this->pCurr = this->pFirst;
		this->pNext = this->pHead;
		this->Size++;
		tempcurr = pCurr;
	}
	else
	{
		Reset();
		TNode* newfirst = new TNode(data);
		this->pHead->pNext = newfirst;
		newfirst->pNext = this->pFirst;
		this->pFirst = newfirst;
		this->pCurr = this->pFirst;
		this->pNext = this->pFirst->pNext;
		this->Size++;
	}
	pCurr = tempcurr;
	pNext = pCurr->pNext;
}

void THeadList::InsertAfter(TData const data, TData const after_data)
{
	TNode* tempcurr = new TNode;
	tempcurr = pCurr;
	TNode* el = new TNode(after_data);
	if (data != pHead->data)
	{
		if (pCurr->data != data)
		{
			while (pCurr->data != data)
			{
				Next();
			}
		}
		this->pCurr->pNext = el;
		el->pNext = this->pNext;
		this->pNext = el;
		this->Size++;
	}
	else
	{
		InsertToHead(el->data);
	}
	pCurr = tempcurr;
	pNext = pCurr->pNext;
}

void THeadList::RemoveFirst()
{
	TNode* tempcurr = new TNode;
	tempcurr = pCurr;
	if (GetLenght() > 1)
	{
		if (pFirst->data != pCurr->data)
		{
			Reset();
			this->pHead->pNext = this->pNext;
			this->pCurr = this->pNext;
			delete pFirst;
			this->pFirst = this->pCurr;
			this->pNext = this->pCurr->pNext;
			this->Size--;
		}
		else
		{
			Reset();
			this->pHead->pNext = this->pNext;
			this->pCurr = this->pNext;
			delete pFirst;
			this->pFirst = this->pCurr;
			this->pNext = this->pCurr->pNext;
			this->Size--;
			tempcurr = pCurr;
		}
	}
	else
	{
		delete pFirst;
		pCurr = pHead;
		pNext = pHead;
		pFirst = nullptr;
		Size--;
	}
	pCurr = tempcurr;
	pNext = pCurr->pNext;
}

void THeadList::RemoveLast()
{
	TNode* tempcurr = new TNode;
	tempcurr = pCurr;
	if (GetLenght() > 1)
	{
		while (this->pCurr->pNext->pNext != this->pHead)
			Next();
		this->pCurr->pNext = this->pHead;
		delete pNext;
	}
	else
	{
		delete pCurr;
		tempcurr = pHead;
	}
	this->Size--;
	pCurr = tempcurr;
	pNext = pCurr->pNext;
}

void THeadList::Remove(TData curr_data)
{
	TNode* tempcurr = new TNode;
	tempcurr = pCurr;
	if (Size > 1 && curr_data != pFirst->data)
	{
		if (pCurr->data != curr_data)
		{
			while (pNext->data != curr_data)
				Next();
			pCurr->pNext = pNext->pNext;
			delete pNext;
			pNext = pCurr->pNext;
			Next();
			Size--;
		}
		else
		{
			while (this->pNext->data != curr_data)
				Next();
			pCurr->pNext = pNext->pNext;
			delete pNext;
			pNext = pCurr->pNext;
			Next();
			tempcurr = pCurr;
			Size--;
		}
		pCurr = tempcurr;
		pNext = pCurr->pNext;
	}
	else
	{
		RemoveFirst();
	}
}

void THeadList::Clear()
{
	Reset();
	for (int i = 0; i < GetLenght(); i++)
	{
		RemoveLast();
	}
	delete pFirst;
	pFirst = nullptr;
	pCurr = pHead;
	Size = 0;
}