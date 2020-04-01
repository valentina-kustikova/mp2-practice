#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#include "tnode.h"

template<typename TKey, class TData>
class BinaryTree
{
private:
	TNode<TKey, TData>* root;

public:
	BinaryTree();
	BinaryTree(TNode<TKey, TData>* _root);
	BinaryTree(const BinaryTree<TKey, TData>& _copy);	// TODO
	~BinaryTree();	// TODO

	TNode<TKey, TData>* SearchKey(const TKey _key) const;
	TNode<TKey, TData>* SearchMaxKey(const TNode<TKey, TData>* _root = root) const;
	TNode<TKey, TData>* SearchMinKey(const TNode<TKey, TData>* _root = root) const;
	TNode<TKey, TData>* SearchNext(const TNode<TKey, TData>* _tnode) const;
	TNode<TKey, TData>* SearchNext(const TKey _key) const;
	TNode<TKey, TData>* SearchPrev(const TNode<TKey, TData>* _tnode) const;
	TNode<TKey, TData>* SearchPrev(const TKey _key) const;
	
	void Insert(const TNode<TKey, TData>* _tnode);
	void Insert(const TKey _key, const TData _pData);
	void Remove(const TNode<TKey, TData>* _tnode);
	void Remove(const TKey _key);
};
//---------------------------------------------------------

template<typename TKey, class TData>
BinaryTree<TKey, TData>::BinaryTree()
{
	root = new TNode<TKey, TData>;
};

template<typename TKey, class TData>
BinaryTree<TKey, TData>::BinaryTree(TNode<TKey, TData>* _root)
{
	root = _root;
};

template<typename TKey, class TData>
BinaryTree<TKey, TData>::BinaryTree(const BinaryTree<TKey, TData>& _copy)
{
	//TODO
};

template<typename TKey, class TData>
BinaryTree<TKey, TData>::~BinaryTree()
{
	//TODO
};
//---------------------------------------------------------

template<typename TKey, class TData>
TNode<TKey, TData>* BinaryTree<TKey, TData>::SearchKey(const TKey _key) const
{
	TNode<TKey, TData>* current = root;
	
	while ((current != nullptr) && (current->key != _key))
	{
		if (_key < current->key)
			current = current->pLeft;
		else current = current->pRight;
	}

	return current;
};

template<typename TKey, class TData>
TNode<TKey, TData>* BinaryTree<TKey, TData>::SearchMaxKey(const TNode<TKey, TData>* _root) const
{
	TNode<TKey, TData>* current = _root;

	while (current->pRight != nullptr)
		current = current->pRight;

	return current;
};

template<typename TKey, class TData>
TNode<TKey, TData>* BinaryTree<TKey, TData>::SearchMinKey(const TNode<TKey, TData>* _root) const
{
	TNode<TKey, TData>* current = _root;

	while (current->pLeft != nullptr)
		current = current->pLeft;

	return current;
};

template<typename TKey, class TData>
TNode<TKey, TData>* BinaryTree<TKey, TData>::SearchNext(const TNode<TKey, TData>* _tnode) const
{
	TNode<TKey, TData>* next = nullptr;

	if (_tnode->pRight != nullptr)
	{
		next = SearchMinKey(_tnode);
		return next;
	}

	next = _tnode->pParent;
	TNode<TKey, TData>* tmp = _tnode;

	while ((next != nullptr) && (tmp == next->pRight))
	{
		tmp = next;
		next = next->pParent;
	}

	return next;
};

template<typename TKey, class TData>
TNode<TKey, TData>* BinaryTree<TKey, TData>::SearchNext(const TKey _key) const
{
	TNode<TKey, TData>* current = SearchKey(_key);
	return SearchNext(current);
};

template<typename TKey, class TData>
TNode<TKey, TData>* BinaryTree<TKey, TData>::SearchPrev(const TNode<TKey, TData>* _tnode) const
{
	TNode<TKey, TData>* prev = nullptr;

	if (_tnode->pLeft != nullptr)
	{
		prev = SearchMaxKey(_tnode);
		return prev;
	}

	prev = _tnode->pParent;
	TNode<TKey, TData>* tmp = _tnode;

	while ((prev != nullptr) && (tmp == prev->pLeft))
	{
		tmp = prev;
		prev = prev->pParent;
	}

	return prev;
};

template<typename TKey, class TData>
TNode<TKey, TData>* BinaryTree<TKey, TData>::SearchPrev(const TKey _key) const
{
	TNode<TKey, TData>* current = SearchKey(_key);
	return SearchPrev(current);
};

template<typename TKey, class TData>
void BinaryTree<TKey, TData>::Insert(const TNode<TKey, TData>* _tnode)
{
	if (root == nullptr)
	{
		root = _tnode;
		return;
	}

	TNode<TKey, TData>* x = root;
	TNode<TKey, TData>* y;

	while (x != nullptr)
	{
		y = x;
		if (_tnode->key < x->key)
			x = x->pLeft;
		else x = x->pRight;
	}
	
	_tnode->pParent = y;
	
	if (_tnode->key < y->key)
		y->pLeft = _tnode;
	else y->pRight = _tnode;
};

template<typename TKey, class TData>
void BinaryTree<TKey, TData>::Insert(const TKey _key, const TData _pData)
{
	TNode<TKey, TData>* newTNode = new TNode<TKey, TData>(_key, nullptr, nullptr, nullptr, _pData);
	Insert(newTNode);
};

template<typename TKey, class TData>
void BinaryTree<TKey, TData>::Remove(const TNode<TKey, TData>* _tnode)
{
	TNode<TKey, TData>* y = nullptr;
	TNode<TKey, TData>* x = nullptr;

	if ((_tnode->pLeft != nullptr) && (_tnode->pRight != nullptr))
		y = SearchNext(_tnode);
	else
		y = _tnode;
	
	if (y->pLeft != nullptr)
		x = y->pLeft;
	else
		x = y->pRight;

	if (x != nullptr) 
		x->pParent = y->pParent;
	
	if (y->pParent != nullptr)
	{
		if (y == y->pParent->pLeft) 
			y->pParent->pLeft = x;
		else 
			y->pParent->pRight = x;
	}

	if (y != _tnode)
	{
		_tnode->key = y->key;
		delete _tnode->pData;
		_tnode->data = y->pData;
	}
};

template<typename TKey, class TData>
void BinaryTree<TKey, TData>::Remove(const TKey _key)
{
	TNode<TKey, TData>* newTNode = SearchKey(_key);
	Remove(newTNode);
};

#endif