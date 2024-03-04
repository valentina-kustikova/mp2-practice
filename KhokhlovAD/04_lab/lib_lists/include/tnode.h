#ifndef _TNODE_
#define _TNODE_


template <typename T>
struct TNode
{
	T data;
	TNode* pNext;
	TNode(const T& data) : data(data), pNext(nullptr) {};
};
#endif