#ifndef _BALANCETREETABLE_H_
#define _BALANCETREETABLE_H_

#include "binarytreetable.h"
#include "tbalancenode.h"

template<typename TKey, class TData>
class TBalanceTreeTable : public TBinaryTreeTable<TKey, TData>
{
public:
	void InsertRecord(const TKey _key, TData* _data = nullptr) override;
	void RemoveRecord(const TKey _key) override;

	int InsBalanceTree(TBalanceNode<TKey, TData>** _node, const TKey _key, TData* _data = nullptr);
	int LeftTreeBalancing(TBalanceNode<TKey, TData>** _node);
	int RightTreeBalancing(TBalanceNode<TKey, TData>** _node);
	int Remove(TBalanceNode<TKey, TData>** _node, const TKey _key);
};
//-----------------------------------------------

template<typename TKey, class TData>
void TBalanceTreeTable<TKey, TData>::InsertRecord(const TKey _key, TData* _data)
{
	if (this->IsFull())
		throw Exception("Balance Binary Tree Table is full!");
	else 
		InsBalanceTree((TBalanceNode<TKey, TData>**)(&(this->root)), _key, _data);
};

template<typename TKey, class TData>
void TBalanceTreeTable<TKey, TData>::RemoveRecord(const TKey _key)
{
	if (this->IsEmpty())
		throw Exception("Balance Binary Tree Table is empty!");
	else
		Remove((TBalanceNode<TKey, TData>**)(&(this->root)), _key);
};

template<typename TKey, class TData>
int TBalanceTreeTable<TKey, TData>::InsBalanceTree(TBalanceNode<TKey, TData>** _node, const TKey _key, TData* _data)
{
	int height = 0;

	if (!(*_node))
	{
		*_node = new TBalanceNode<TKey, TData>(_key, _data);
		height = 1;
		this->dataCount++;
	}
	else if (_key < (*_node)->GetKey())
    {
		if (InsBalanceTree((TBalanceNode<TKey, TData>**)(&((*_node)->pLeft)), _key, _data) == 1)
		{
			(*_node)->pLeft->pParent = (*_node);
			height = LeftTreeBalancing(_node);
		}
		else (*_node)->pLeft->pParent = (*_node);
    }
	else
	{
		if (InsBalanceTree((TBalanceNode<TKey, TData>**)(&((*_node)->pRight)), _key, _data) == 1)
		{
			(*_node)->pRight->pParent = (*_node);
			height = RightTreeBalancing(_node);
		}
		else (*_node)->pRight->pParent = (*_node);
    }

	return height;
};

template<typename TKey, class TData>
int TBalanceTreeTable<TKey, TData>::LeftTreeBalancing(TBalanceNode<TKey, TData>** _node)
{
	int height = 0;

	switch ((*_node)->GetBalance())
	{
	case 0:
		(*_node)->SetBalance(-1);
		height = 1;
		break;
	case 1:
		(*_node)->SetBalance(0);
		height = 0;
		break;
	case -1:
		TBalanceNode<TKey, TData>* left = (TBalanceNode<TKey, TData>*)((*_node)->pLeft);

		if (left->GetBalance() == -1)
		{
			(*_node)->pLeft = left->pRight;
			if(left->pRight)
				left->pRight->pParent = (*_node);
			left->pRight = (*_node);
			left->pParent = (*_node)->pParent;
			(*_node)->pParent = left;
			(*_node)->SetBalance(0);
			(*_node) = left;
		}
		else
		{
			TBalanceNode<TKey, TData>* right = (TBalanceNode<TKey, TData>*)(left->pRight);
			left->pRight = right->pLeft;
			if(right->pLeft)
				right->pLeft->pParent = left;
			right->pLeft = left;
			left->pParent = right;
			(*_node)->pLeft = right->pRight;
			if(right->pRight)
				right->pRight->pParent = (*_node);
			right->pRight = (*_node);
			right->pParent = (*_node)->pParent;
			(*_node)->pParent = right;
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
	}

	return height;
};

template<typename TKey, class TData>
int TBalanceTreeTable<TKey, TData>::RightTreeBalancing(TBalanceNode<TKey, TData>** _node)
{
	int height = 0;

	switch ((*_node)->GetBalance())
	{
	case -1:
		(*_node)->SetBalance(0);
		height = 0;
		break;
	case 0:
		(*_node)->SetBalance(1);
		height = 1;
		break;
	case 1:
		TBalanceNode<TKey, TData> * right = (TBalanceNode<TKey, TData>*)((*_node)->pRight);

		if (right->GetBalance() == -1)
		{
			TBalanceNode<TKey, TData>* left = (TBalanceNode<TKey, TData>*)(right->pLeft);
			right->pLeft = left->pRight;
			if(left->pRight)
				left->pRight->pParent = right;
			left->pRight = right;
			right->pParent = left;
			(*_node)->pRight = left->pLeft;
			if(left->pLeft)
				left->pLeft->pParent = (*_node);
			left->pLeft = (*_node);
			left->pParent = (*_node);
			(*_node)->pParent = left;
			if (left->GetBalance() == -1)
				(*_node)->SetBalance(1);
			else
				(*_node)->SetBalance(0);
			if (right->GetBalance() == 1)
				(*_node)->SetBalance(-1);
			else
				(*_node)->SetBalance(0);
			(*_node) = left;
			(*_node)->SetBalance(0);
		}
		else
		{
			(*_node)->pRight = right->pLeft;
			if (right->pLeft)
				right->pLeft->pParent = (*_node);
			right->pLeft = (*_node);
			right->pParent = (*_node)->pParent;
			(*_node)->pParent = right;
			(*_node)->SetBalance(1);
			(*_node) = right;
		}
		height = 0;
		break;
	}

	return height;
};

template<typename TKey, class TData>
int TBalanceTreeTable<TKey, TData>::Remove(TBalanceNode<TKey, TData>** _node, const TKey _key)
{
	int height = 0;

	if (_key > (*_node)->GetKey())
	{
		if (Remove((TBalanceNode<TKey, TData>**)((*_node)->pRight), _key) == 1)
			height = RightTreeBalancing(_node);
	}
	else if (_key < (*_node)->GetKey())
	{
		if (Remove((TBalanceNode<TKey, TData>**)((*_node)->pLeft), _key) == 1)
			height = LeftTreeBalancing(_node);
	}
	else
	{
		if (!((*_node)->pLeft) && !((*_node)->pRight))
		{
			if ((*_node) == ((*_node)->pParent->pLeft))
				(*_node)->pParent->pLeft = nullptr;
			else (*_node)->pParent->pRight = nullptr;
		}
		//else if (((*_node)->pLeft) && !((*_node)->pRight))
		//{

		//}
	}

	return height;
};

#endif