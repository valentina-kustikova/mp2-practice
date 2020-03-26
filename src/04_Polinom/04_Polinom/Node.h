#pragma once
#include <iostream>
using namespace std;
template <class TKey, class TData>
class TNode
{
public:
	TKey key;
	TData pData;
	TNode *pNext;
public:
	TNode();
	TNode(TKey, TData, TNode* = nullptr);
	TNode(const TNode<TKey, TData>&);
	~TNode();
};

template<class TKey, class TData>
TNode<TKey, TData>::TNode()
{
	key = 0;
	pData = 0;
	pNext = nullptr;
}
template <class TKey, class TData>
TNode<TKey, TData>::TNode(const TNode<TKey, TData>& _node)
{
	key = _node.key;
	pData = _node.pData;
	pNext = _node.pNext;
}
template<class TKey, class TData>
TNode<TKey, TData>::TNode(TKey _key, TData _data, TNode* node)
{
	key = _key;
	pData = _data;
	pNext = node;
}
template<class TKey, class TData>
TNode<TKey, TData>::~TNode()
{}
