#pragma once

#include "node.h"
#include "list.h"

class THeadList : public TList
{
private:
    TNode* pHead;

public:
    THeadList();
    ~THeadList();

    virtual void InsertToHead(TData* const data);
    virtual void RemoveFirst();
};

THeadList::THeadList()
{
    pHead = new TNode; 
    pHead->pNext = nullptr;
}
THeadList::~THeadList()
{
    Clear();
    delete pHead; 
}

void THeadList::InsertToHead(TData* const data)
{
    TNode* p = new TNode(*data);
    pHead->pNext = p;
}
void THeadList::RemoveFirst()
{
    TNode* p = pHead->pNext;
    pHead->pNext = p->pNext;
    delete p;
}