#ifndef _BALANCETREENODE_H_
#define _BALANCETREENODE_H_

#include "tnode.h"

template<typename TKey, class TData>
class TBalanceNode : public TNode
{
private:
	int balance;

public:
	TBalanceNode();
	~TBalanceNode();

	int GetBalance() const;
	void SetBalance(int _balance);
};
//----------------------------------

template<typename TKey, class TData>
TBalanceNode<TKey, TData>::TBalanceNode()
{
	balance = 0;
};

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
