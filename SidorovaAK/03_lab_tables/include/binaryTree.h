#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#include "tnode.h"

template<typename TKey, class TData>
class BinaryTree
{
private:
	TNode<TKey, TData>* root;

public:
	BinaryTreee();
	BinaryTree(TNode<TKey, TData>* root);
	BinaryTreee(const BinaryTree<TKey, TData>& _copy);
	~BinaryTree();

	TNode<TKey, TData>* SearchKey(const TKey _key) const;
	TNode<TKey, TData>* SearchMaxKey() const;
	TNode<TKey, TData>* SearchMinKey() const;
	TNode<TKey, TData>* SearchNext(const TKey _key) const;
	TNode<TKey, TData>* SearchPrev(const TKey _key) const;
	
	void Insert(const TKey _key, const TData _pData);
	void Remove(const TKey _key);
};
//----------------------------------------------------
#endif