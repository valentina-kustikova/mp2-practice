#include "list.h"
#include <iostream>
TList::TList() 
{
	pCurr = nullptr;
	pFirst = nullptr;
	pPrev = nullptr;
	pNext = nullptr;
	//pStop = nullptr;
}

TList::TList(TNode* temp)
{
	if (!temp)
		return;
	pFirst = new TNode(*temp);
	TNode* node = temp->pNext, * prev = pFirst;
	while (node)
	{
		TNode* tmp = new TNode(*node);
		prev->pNext = tmp;
		prev = tmp;
		node = node->pNext;
	}
	Reset();
}

TList::TList(const TList& temp)
{
	if (!temp.pFirst)
		return;
	if (pFirst)
		delete pFirst;
	pFirst = new TNode(*temp.pFirst);
	TNode* node = temp.pFirst->pNext, * prev = pFirst;
	while (node)
	{
		TNode* tmp = new TNode(*node);
		prev->pNext = tmp;
		prev = tmp;
		node = node->pNext;
	}
	Reset();
}

TList::~TList()
{
	TNode* tmp;
	//while (pFirst != nullptr)
	//{	
	//	tmp = pFirst;
	//	pFirst = pFirst->pNext;
	//	delete tmp;
	//}
	while (!IsEnded())
	{
		Next();
		tmp = pPrev;
		pPrev = nullptr;
		if (tmp == nullptr)
			std::cout << "error";
		else
		delete tmp;
	}

}

TNode* TList::Search(TData* const data)
{
	if (!pFirst)
		throw "List is empty";
	Reset();
	while (pCurr)
	{
		if (pCurr->data == data)
			return pCurr;
		pCurr = pNext;
	}
	return nullptr;
}

void TList::InsertToHead(TData* const data)
{
	if (pCurr != pFirst)
		Reset();
	TNode* node = new TNode(data, pCurr);
	pFirst = node;
	Reset();
}

void TList::InsertToTail(TData* const data) // IsEnded??? 
{
	if (pCurr != pFirst)
		Reset();
	TNode* node = new TNode(data);
	if (pFirst == nullptr)
	{
		pCurr = node;
		pFirst = node;
		pPrev = nullptr;
		pNext = nullptr;
		return;
	}
	while (!NextIsEnded())
	{
		Next();
	}
	pNext = node; // было pCurr
	pCurr->pNext = node;
	Reset();
}

void TList::InsertBefore(TData* const data, TData* const before_data)
{
	if (pCurr != pFirst)
		Reset();
	while (!NextIsEnded() && (pCurr->data != before_data))
		Next();
	if (pNext == nullptr && pCurr->data != before_data)
		throw "The node is not found";
	TNode* node = new TNode(data);
	if (pFirst == pCurr)
	{
		pFirst = node;
		node->pNext = pCurr;
		Reset();
		return;
	}
	pPrev->pNext = node;
	node->pNext = pCurr;
	Reset();
}

void TList::InsertAfter(TData* const data, TData* const after_data)
{
	if (pCurr != pFirst)
		Reset();
	while (!NextIsEnded() && (pCurr->data != after_data))
		Next();
	if ((pNext == nullptr) && (pCurr->data != after_data))
		throw "The node is not found";
	TNode* node = new TNode(data, pNext);
	pCurr->pNext = node;
	pNext = node;
	Reset();
}

void TList::RemoveFirst()
{
	if (!pFirst)
		return;
	TNode* tmp = pFirst;
	pFirst = pNext;
	if (pNext != nullptr)
		pNext = pNext->pNext;
	else
	{
		pPrev = nullptr;
	}
	Reset();
	delete tmp; 
}

void TList::RemoveLast()
{
	if (!pFirst)
		return;
	while (!NextIsEnded())
		Next();
	TNode* tmp = pCurr;
	pNext = nullptr;
	delete tmp;
	pCurr = pPrev;
}

void TList::Remove(TData* const data)
{
	Reset();
	if (!pFirst)
		throw "List is empty";
	while (!IsEnded() && (pCurr->data != data))
		Next();
	if (pCurr == nullptr)
		throw "The node is not found";
	TNode* tmp = pCurr;
	if (pFirst->data == data)
	{
		RemoveFirst();
	}
	else
	{
		pPrev->pNext = pNext;
		pCurr = pPrev;
		delete tmp;
	}
	Reset();
}

void TList::Clear()
{
	if (!pFirst)
		return;
	if (pCurr != pFirst)
		Reset();
	while (!IsEnded())
	{
		Next();
		delete pPrev;
	}
	delete pCurr;
	pFirst = nullptr;
	pPrev = nullptr;
	pCurr = nullptr;
	pNext = nullptr;
}

void TList::Sort()
{
	if (!pFirst)
		throw "List is empty";
	TNode* tmp = pFirst;
	for (TNode* i = tmp; i; i = i->pNext) {
		for (TNode* j = i->pNext; j; j = j->pNext) {
			if (*(i->data) < *(j->data)) {
				TData* tmp = i->data;
				i->data = j->data;
				j->data = tmp;
			}
		}
	}
}

int TList::GetLenght() const
{
	if (!pFirst)
		return 0;
	int i = 1;
	TNode* tmp = pFirst->pNext;
	while (tmp)
	{
		tmp = tmp->pNext;
		i++;
	}
	return i;
}

void TList::Next()
{
	pPrev = pCurr;
	pCurr = pNext;
	if (IsEnded())
		pNext = NULL;
	else
		pNext = pCurr->pNext;
}

void TList::Reset()
{
	pCurr = pFirst;
	pPrev = nullptr;
	if (pFirst)
		pNext = pFirst->pNext;
	else
		pNext = nullptr;
}

bool TList::NextIsEnded() const
{
	return pNext == nullptr; 
}

bool TList::IsEnded() const
{
	return pCurr == nullptr; // было pCurr
}

bool TList::IsEmpty() const
{
	return pFirst == nullptr;
}