#pragma once

#include "data.h"

struct TNode
{
    TData* data;
    TNode* pNext;

    TNode() { data = nullptr; pNext = nullptr; };
    TNode(TData* const data);
    TNode(TData* const data, TNode* const pNext);
    TNode(const TNode& node);
    ~TNode();
};
