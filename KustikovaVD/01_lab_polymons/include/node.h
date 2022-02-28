#pragma once

#include "data.h"

class TNode
{
public:
    TData* data;
    TNode* pNext;

public:
    TNode() { };
    TNode(TData* const data);
    TNode(TData* const data, TNode* const pNext);
    TNode(const TNode& node);
    ~TNode();;
};
