#include "node.h"

TNode::TNode(TData * const data)
{
    this->data = data;
    this->pNext = nullptr;
}

TNode::TNode(TData * const data, TNode * const pNext)
{
    this->data = data;
    this->pNext = pNext;
}

TNode::TNode(const TNode & node)
{
    this->data = node.data->Copy();
    this->pNext = nullptr;
}

TNode::~TNode()
{
    delete data;
}
