#ifndef _TNODE_H_
#define _TNODE_H_

#include <iostream>

#include "tabrecord.h"

using namespace std;

template<typename TKey, class TData> class TBinaryTreeTable;

template<typename TKey, class TData>
class TNode : public TTabRecord<TKey, TData>
{
public:
	TNode<TKey, TData>* pParent;
	TNode<TKey, TData>* pLeft;
	TNode<TKey, TData>* pRight;

	TNode(TKey _key = {}, TData* _pData = nullptr, TNode<TKey, TData>* _pParent = nullptr,
		TNode<TKey, TData>* _pLeft = nullptr, TNode<TKey, TData>* _pRight = nullptr);
	TNode(const TNode<TKey, TData>& _copy);
	~TNode();

	TNode<TKey, TData>* GetParent() const { return pParent; };
	TNode<TKey, TData>* GetLeft() const { return pLeft; };
	TNode<TKey, TData>* GetRight() const { return pRight; };

	void SetpLeft(const TNode* _pLeft) { pLeft = _pLeft; };
	void SetpRight(const TNode* _pRight) { pRight = _pRight; };

	friend TBinaryTreeTable<TKey, TData>;
};
//---------------------------------------------------------

template<typename TKey, class TData>
TNode<TKey, TData>::TNode(TKey _key, TData* _pData, TNode<TKey, TData>* _pParent, 
	TNode<TKey, TData>* _pLeft, TNode<TKey, TData>* _pRight) : TTabRecord<TKey, TData>(_key, _pData)
{
	pParent = _pParent;
	pLeft = _pLeft;
	pRight = _pRight;
};

template<typename TKey, class TData>
TNode<TKey, TData>::TNode(const TNode<TKey, TData>& _copy)
{
	this->key = _copy.key;
	this->data = _copy.data;
	pParent = _copy.pParent;
	pLeft = _copy.pLeft;
	pRight = _copy.pRight;
};

template<typename TKey, class TData>
TNode<TKey, TData>::~TNode()
{
	pParent = nullptr;
	pLeft = nullptr;
	pRight = nullptr;
};
//----------------------------------------------------

#endif