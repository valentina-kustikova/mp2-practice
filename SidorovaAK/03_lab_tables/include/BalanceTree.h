#ifndef _BALANCETREE_H_
#define _BALANCETREE_H_

#include "binarytree.h"
#include "tbalancenode.h"

template<typename TKey, class TData>
class BalanceTree : public BinaryTree
{
public:
	BalanceTree();
	~BalanceTree();

	int Insert(TBalanceNode<TKey, TData>** _node, int _key, TData* _data);
	int LeftTreeBalancing(TBalanceNode<TKey, TData>** _node);
	int RightTreeBalancing(TBalanceNode<TKey, TData>** _node);
	int Remove(TBalanceNode<TKey, TData>** _node, int _key);
};
//-------------------------------

template<typename TKey, class TData>
BalanceTree<TKey, TData>::BalanceTree() : BinaryTree() {};

template<typename TKey, class TData>
BalanceTree<TKey, TData>::~BalanceTree()
{
	// todo
};
//---------------------------------

template<typename TKey, class TData>
int BalanceTree<TKey, TData>::Insert(TBalanceNode<TKey, TData>** _node, int _key, TData* _data)
{
	if (!root)
	{
		tnode = new TBalanceNode(_key, _data);
		return 1;
	}

	int height = 0;

	if (_key < _node->GetKey())
	{
		if (Insert(TBalanceNode<TKey, TData>(*_node->pLeft), _key, _data) == 1)
			height = LeftTreeBalancing(*_node);
	}
	else
	{
		if (Insert(TBalanceNode<TKey, TData>(*_node->pRight), _key, _data) == 1)
			height = RightTreeBalancing(*_node);
	}

	return height;
};

template<typename TKey, class TData>
int BalanceTree<TKey, TData>::LeftTreeBalancing(TBalanceNode<TKey, TData>** _node)
{
	// todo
};

template<typename TKey, class TData>
int BalanceTree<TKey, TData>::RightTreeBalancing(TBalanceNode<TKey, TData>** _node)
{
	int height = 0;

	switch ((*_node)->GetBalance())
	{
	case -1:
		TBalanceNode<TKey, TData> * left = (TBalanceNode<TKey, TData>*)((*_node)->left);

		if (left->GetBalance() == -1)
		{
			(*_node)->pLeft = left->pRight;
			left->pRight = (_node);
			(*_node)->GetBalance(0);
			(*_node) = left;
		}
		else
		{
			TBalanceNode<TKey, TData>* right = (TBalanceNode<TKey, TData>*)(left->pRight);
			left->pRight = right->pLeft;
			right->pLeft = left;
			(*_node)->pLeft = right->pRight;
			right->pRight = (*_node);
			if (right->GetBalance() == -1)
				(*_node)->SetBalance(1);
			else
				(*_node)->SetBalance(0);
			if (right->GetBalance() == 1)
				(*_node)->SetBalance(-1);
			else
				(*_node)->SetBalance(0);
			(*_node) = right;
			(*_node)->SetBalance(0);
		}
		height = 0;
		break;
	case 0:
		(*_node)->SetBalance(-1);
		height = 1;
		break;
	case 1:
		(*_node)->SetBalance(0);
		height = 0;
		break;
	}

	return height;
};

#endif