#pragma once
#include <iostream>

template<class TData, class TKey>
class TNode
{
public:
	TData* pData;
	TKey key;
	TNode<TData, TKey>* pNext;//pointer of nextelement

	TNode();
	TNode(const TNode& node);
	TNode(TKey _key, TData* _pData, TNode* _pNext);
	TNode(TKey _key, TData* _data);
	TNode(TNode<TData, TKey>* node);
};

template<class TData, class TKey>
TNode<TData, TKey>::TNode() : pData(nullptr), key(0), pNext(nullptr) {}

template<class TData, class TKey>
TNode<TData, TKey>::TNode(const TNode<TData, TKey>& node) : pData(node.pData), key(node.key), pNext(node.pNext) {}

template<class TData, class TKey>
TNode<TData, TKey>::TNode(TKey _key, TData* _pData, TNode* _pNext)
{
	key = _key;
	pData = _pData;
	pNext = _pNext;
}

template<class TData, class TKey>
TNode<TData, TKey> ::TNode(TNode<TData, TKey>* node)
{
	key = node->key;
	pData = new TData;
	*pData = *node->pData;
	pNext = node->pNext;
}
template<class TData, class TKey>
TNode<TData, TKey> ::TNode(TKey _key, TData* _data)
{
	key = _key;
	pData = new TData;
	*pData = *_data;
	pNext = nullptr;
}
