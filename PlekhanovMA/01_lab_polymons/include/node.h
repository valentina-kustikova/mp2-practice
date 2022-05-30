#pragma once
#include "data.h"

class TNode
{
public:
    TData* data;// данные
    TNode* pNext;// указатель на следующий элемент списка

public:
    TNode();
    TNode(TData* const data);
    TNode(TData* const data, TNode* const pNext);
    TNode(const TNode& node);
    TNode& operator=(const TNode& node);
    ~TNode() { };
};