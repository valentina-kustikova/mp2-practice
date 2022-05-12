#include "headlist.h"

THeadList::THeadList() : TList()
{
	pHead = nullptr;
}

THeadList::THeadList(TNode* Head)
{
	if (!Head)
		return;
	pHead = new TNode(*Head);
	pFirst = Head->pNext; 
	TNode* prev = pFirst;
	TNode* node = pFirst->pNext;
	while (node)
	{
		TNode* tmp = new TNode(*node);
		prev->pNext = tmp;
		prev = tmp;
		node = node->pNext;
	}
	Reset();
}

THeadList::THeadList(const THeadList& hlist)
{
	if (!hlist.pHead)
		return;
	if (pHead)
		delete pHead;
	pHead = new TNode(*hlist.pHead);
	pFirst = pHead->pNext;
	TNode* node = hlist.pFirst->pNext, * prev = pFirst;
	while (node)
	{
		TNode* tmp = new TNode(*node);
		prev->pNext = tmp;
		prev = tmp;
		node = node->pNext;
	}
	Reset();
}

THeadList::~THeadList()
{
	delete pHead;
}

void THeadList::InsertToHead(TData* const data) // !pHead -> pHead, иначе в pFirst
{
	if (!pHead)
	{
		pHead = new TNode(data);
		pHead->pNext = pFirst;
		return;
	}
	TList::InsertToHead(data);
}
void THeadList::RemoveFirst()
{
	if (!pFirst)
	{
		if (!pHead)
			throw "List is empty";
		delete pHead;
		pHead = nullptr;
		return;
	}
	else
		TList::RemoveFirst();
}