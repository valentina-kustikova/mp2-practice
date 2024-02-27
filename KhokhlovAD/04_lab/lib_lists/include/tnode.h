#ifndef _TNODE_
#define _TNODE_
#include "tdata.h"

template <typename T>
struct TNode
{
	T data;
	TNode* pNext;
	TNode(const T& data) : data(data), pNext(nullptr) {};
};
#endif