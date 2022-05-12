#pragma once

#include "node.h"
#include "list.h"

class THeadList : public TList
{
private:
    TNode* pHead;
public:
    THeadList();
    THeadList(TNode* pHead);
    THeadList(const THeadList& hlist);
    ~THeadList();

    virtual void InsertToHead(TData* const data);
    virtual void RemoveFirst();
};
