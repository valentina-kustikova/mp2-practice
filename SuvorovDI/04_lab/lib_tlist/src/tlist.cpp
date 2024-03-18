#include "tlist.h"
#include "tpolynom.h"
#include <iostream>

TList::TList() {
  pFirst = nullptr;
  pLast = nullptr;
  pCurr = nullptr;
  pStop = nullptr;
}

bool TList::IsEmpty() const {
  return pFirst == nullptr;
}

TList::TList(const TList& l) {
  if (l.IsEmpty())
	{
		pFirst=nullptr;
		pLast=nullptr;
		pCurr=nullptr;
		pStop=nullptr;
	}

	pFirst = new TNode(l.pFirst->data);
	TNode* tmp = pFirst; 
  TNode* ltmp = l.pFirst->pNext;
	while(ltmp != l.pStop)
	{
		tmp->pNext = new TNode(ltmp->data);
		tmp = tmp->pNext;
		ltmp = ltmp->pNext;
	}
	pLast = tmp;
	pCurr = pFirst;
	pStop = nullptr;
}

TList::TList(TNode* pNode) {
  pFirst = pNode;
  TNode* tmp = pNode;
  while (tmp->pNext != nullptr)
    tmp = tmp->pNext;
  pLast = tmp;
  pCurr = pFirst;
  pStop = nullptr;
}

void TList::Clear() {
  if (pFirst == nullptr)
    return;
  TNode* curr = pFirst;
  TNode* next = pFirst->pNext;
  while (next != pStop) {
    delete curr;
    curr = next;
    next = curr->pNext;
  }
  delete curr;
  pCurr = pStop;
  pFirst = nullptr;
  pLast = nullptr;
}

TList::~TList() {
  Clear();
}

bool TList::IsFull() const {
  TNode* tmp = new TNode();//реализовать конструктор по умолчанию для TNode
  if (tmp == nullptr)
    return true;
  delete tmp;
  return false;
}

bool TList::IsEnded()const {
  return pCurr == pStop;
}

// В полиноме поиск по коэффициентам!
TNode* TList::Search(const TData& data) {
  TNode* curr = pFirst;
  while (curr != pStop && *(curr->data) != data) {
    curr = curr->pNext;
  }
  return curr;
}

void TList::InsertFirst(const TData& data) {
  TNode* new_first = new TNode(&data, pFirst);
  pFirst = new_first;
  if (pLast == nullptr) {
    pLast = pFirst;
  }
  pCurr = pFirst;
}

void TList::InsertLast(const TData& data) {
  if (IsEmpty()) {
    InsertFirst(data);
    return;
  }
  TNode* new_last = new TNode(&data, pStop);
  pLast->pNext = new_last;
  pLast = new_last;
  pCurr = new_last;
}

void TList::InsertBefore(const TData& who, const TData& where) {
  TNode* prev = nullptr;
  TNode* curr = pFirst;
  while (curr != pStop && *(curr->data) != where) {
    prev = curr;
    curr = curr->pNext;
  }
  if (curr == pStop) {
    throw std::exception("no elements");
  }
  if (prev == nullptr) {
    InsertFirst(who);
    return;
  }
  TNode* new_node = new TNode(&who, curr);
  prev->pNext = new_node;
}

void TList::InsertAfter(const TData& who, const TData& where) {
  TNode* pWhere = Search(where);
  if (pWhere == nullptr) {
    throw std::exception("no elements");
  }
  if (pWhere == pLast) {
    InsertLast(who);
    return;
  }
  TNode* new_node = new TNode(&who, pWhere->pNext);
  pWhere->pNext = new_node;
}

void TList::Remove(const TData& v)
{
	TNode* prev = nullptr;
	TNode* curr = pFirst;
	while (curr != pStop && *(curr->data) != v)
	{
		prev = curr;
		curr = curr->pNext;
	}
	if (curr == pStop)
		throw std::exception("NoSuchElement");
	if (curr == pFirst && curr->pNext == pStop)
	{
		Clear();
		return;
	}
	if (curr == pFirst)
	{
		pFirst = pFirst->pNext;
		delete curr;
		return;
	}
	if (curr == pLast)
	{
		prev->pNext = pStop;
		delete curr;
		return;
	}
	prev->pNext = curr->pNext;
	delete curr;
}

void TList::Reset() {
  pCurr = pFirst;
}

void TList::Next() {
  if (pCurr == pStop)
    throw std::exception("end of the list");
  pCurr = pCurr->pNext;
}

TNode* TList::GetCurr() const {
  return pCurr;
}

// ----------------------------------------------------------------------------
THeadRingList::THeadRingList() : TList() {
  pHead = nullptr;
}

THeadRingList::THeadRingList(const THeadRingList& ringL) : TList(ringL) {
  pHead = new TNode(ringL.pHead->data);
  if (ringL.IsEmpty()) {
    pHead->pNext = pHead;
  }
  else {
    pHead->pNext = pFirst;
  }
  pLast->pNext = pHead;
  pStop = pHead;
}

THeadRingList::~THeadRingList() {
    delete pHead;
}

void THeadRingList::InsertFirst(const TData& data) {
  if (pHead == nullptr) {
    TNode* new_head = new TNode(&data);
    pHead = new_head;
    pHead->pNext = pHead;
    pStop = pHead;
    return;
  }
  TList::InsertFirst(data);
  pHead->pNext = pFirst;
  pStop = pHead;
  pLast->pNext = pHead;
}

void THeadRingList::InsertLast(const TData& data) {
  if (IsEmpty()) {
    THeadRingList::InsertFirst(data);
    return;
  }
  TList::InsertLast(data);
}

void THeadRingList::InsertToSort(const TData& data) {
	if (IsEmpty() || *(pFirst->data) > data) {
		InsertFirst(data);
		return;
	}

	TNode* curr = pFirst;
	while (curr->pNext != pStop && *(curr->pNext->data) <= data) {
		curr = curr->pNext;
	}
	if (*(curr->data) == data) {
		TMonom* monomFromData = dynamic_cast<TMonom*>(curr->data);
		const TMonom* inputData = dynamic_cast<const TMonom*>(&data);
		monomFromData->SetCoeff(monomFromData->GetCoeff() + inputData->GetCoeff());
		return;
	}
	InsertAfter(data, *(curr->data));
}