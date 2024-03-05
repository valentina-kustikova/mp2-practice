#pragma once

template <typename T>
struct TNode
{
	T key;
	TNode<T>* pNext;

	TNode(): ket(), pNext(nullptr);
	TNode(const T& _key): key(_key), pNext(nullptr);
	TNode(const T& _key, const TNode<T>* _pNext): key(_key), pNext(_pNext);
};