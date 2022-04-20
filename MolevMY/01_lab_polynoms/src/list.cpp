#include <list.h>

TList::TList(TNode* pFirst)
{
	this -> pFirst = pFirst;
	pStop = nullptr;
	pCurr = pFirst;
	pPrev = pFirst;
	pNext = pFirst->pNext;
}

TNode* TList::Search(TData* const data)
{
	TNode* elem = pFirst;
	while (elem != pStop)
	{
		if (*(elem->data)==*data)
		{
			return elem;
		}
		elem = elem->pNext;
	}
	return nullptr;
}

void TList::InsertAfter(TData* const data, TData* const after_data)
{
	TNode* elem = Search(data);
	if (elem != nullptr)
	{
		TNode* newelement = new TNode(after_data, elem->pNext);
		elem->pNext = newelement;
	}
}

void TList::InsertBefore(TData* const data, TData* const before_data)
{
	TNode* elem = Search(data);
	if (elem != nullptr)
	{
		TNode* newelement = new TNode(before_data, elem);
		pPrev->pNext = newelement;
	}
}

TList::~TList()
{
	TNode* elem = pFirst;
	TNode* elem1;
	while (elem != pStop)
	{
		elem1 = elem->pNext;
		delete elem;
		elem = elem1;
	}
}

void TList::Sort()
{
	TNode* elem = pFirst;
	while (elem != pStop)
	{
		TNode* elem1 = elem->pNext;
		while (elem1 != pStop)
		{
			if (*(elem1->data) > *(elem->data))
			{
				TNode* elem2 = elem1;
				elem1->data = elem->data;
				elem->data = elem2->data;
			}
			elem1 = elem1->pNext;
		}
		elem = elem->pNext;
	}
}

TNode* TList::GetEmpty()
{
	return nullptr;
}

void TList::InsertToHead(TData* const data)
{
	pCurr = new TNode(data, pFirst);
	pFirst = pCurr;
}

void TList::InsertToTail(TData* const data)
{
	if (pFirst == GetEmpty())
	{
		InsertToHead(data);
	}
	else
	{
		pCurr = this->pFirst;
		while (pCurr->pNext != GetEmpty())
		{
			pCurr = pCurr->pNext;
		}
		pCurr->pNext = new TNode(data);
	}
}