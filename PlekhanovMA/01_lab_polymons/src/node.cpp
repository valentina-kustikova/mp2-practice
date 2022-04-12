#include "node.h"

TNode::TNode()
{
    pNext = nullptr;
}

TNode::TNode(TData const data)
{
    this->data = data;
}

TNode::TNode(TData const data, TNode* const pNext)
{
    this->data = data;
    this->pNext = pNext;
}

TNode::TNode(const TNode& node)
{
    this->data = node.data;
}

TNode& TNode::operator=(const TNode& node)
{
    this->data = node.data;
    this->pNext = node.pNext;
    return *this;
}