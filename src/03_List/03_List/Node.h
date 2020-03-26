#pragma once
#include <iostream>
using namespace std;
template <class TKey, class TData>
class TNode
{
public:
	TKey key;
	TData *pData;
	TNode *pNext;
public:
	TNode();
	TNode(TKey, TData*, TNode* = nullptr);
	TNode(const TNode<TKey, TData>&);
	~TNode();
};

template<class TKey, class TData>
TNode<TKey, TData>::TNode()
{
	pData = nullptr;
	pNext = nullptr;
}
template <class TKey, class TData>
TNode<TKey, TData>::TNode(const TNode<TKey, TData>& _node)
{
	key = _node.key;
	if (_node.pData != nullptr)
	{
		pData = new TData;
		*pData = *_node.pData;
	}
	else pData = nullptr;
	pNext = _node.pNext;
}
template<class TKey, class TData>
TNode<TKey, TData>::TNode(TKey _key, TData* _data, TNode* node)
{
	key = _key;
	if (_data != nullptr)
	{
		pData = new TData;
		*pData = *_data;
	}
	else
		pData = nullptr;
	pNext = node;
}
template<class TKey, class TData>
TNode<TKey, TData>::~TNode()
{
	key = 0;
	if (pData != nullptr)
		delete pData;
}



