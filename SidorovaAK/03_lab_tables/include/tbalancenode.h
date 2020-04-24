#ifndef _BALANCETREENODE_H_
#define _BALANCETREENODE_H_

#include "tnode.h"

template<typename TKey, class TData>
class TBalanceNode : public TNode
{
private:
	int balance;

public:
	TBalanceNode(TKey _key, TData* _pData = nullptr, int _balance = 0, TNode<TKey, TData>* _pParent = nullptr,
		TNode<TKey, TData>* _pLeft = nullptr, TNode<TKey, TData>* _pRight = nullptr);
	~TBalanceNode();

	int GetBalance() const;
	void SetBalance(int _balance);
};
//----------------------------------

template<typename TKey, class TData>
TBalanceNode<TKey, TData>::TBalanceNode(TKey _key, TData* _pData, int _balance, TNode<TKey, TData>* _pParent,
	TNode<TKey, TData>* _pLeft, TNode<TKey, TData>* _pRight) : 
	TNode<TKey, TData>(_key, _pData, _pParent, _pLeft, _pRight), balance(_balance) {};

template<typename TKey, class TData>
TBalanceNode<TKey, TData>::~TBalanceNode()
{
	balance = 0;
};
//-----------------------------------

template<typename TKey, class TData>
int TBalanceNode<TKey, TData>::GetBalance() const
{
	return balance;
};


template<typename TKey, class TData>
void TBalanceNode<TKey, TData>::SetBalance(int _balance)
{
	balance = _balance;
};

#endif
