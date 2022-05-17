#pragma once

#include "Node.h"
#include "Clist.h"

template<class DataType>

class HeadList : public CList
{
private:
    Node* pHead;
public:
    THeadList();
    ~THeadList();

    virtual void InsertToHead(TData* const data);
    virtual void RemoveFirst();
};