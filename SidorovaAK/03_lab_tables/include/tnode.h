#ifndef _TNODE_H_
#define _TNODE_H_

template<typename TKey, class TData>
class TNode
{
public:
	TKey key;
	TNode<TKey, TData>* pParent;
	TNode<TKey, TData>* pLeft;
	TNode<TKey, TData>* pRight;
	TData* pData;

	TNode(TKey _key, TData* _pData = nullptr, TNode<TKey, TData>* _pParent = nullptr, 
		TNode<TKey, TData>* _pLeft = nullptr, TNode<TKey, TData>* _pRight = nullptr);
	TNode(const TNode<TKey, TData>& _copy);
	~TNode();

	TKey GetKey() const;
	TNode<TKey, TData>* GetLeft() const;
	TNode<TKey, TData>* GetRight() const;
};
//---------------------------------------------------------

template<typename TKey, class TData>
TNode<TKey, TData>::TNode(TKey _key, TData* _pData, TNode<TKey, TData>* _pParent, 
	TNode<TKey, TData>* _pLeft, TNode<TKey, TData>* _pRight)
{
	key = _key;
	pData = _pData;
	pParent = _pParent;
	pLeft = _pLeft;
	pRight = _pRight;
};

template<typename TKey, class TData>
TNode<TKey, TData>::TNode(const TNode<TKey, TData>& _copy)
{
	key = _copy.key;
	pData = _copy.pData;
	pParent = _copy.pParent;
	pLeft = _copy.pLeft;
	pRight = _copy.pRight;
};

template<typename TKey, class TData>
TNode<TKey, TData>::~TNode()
{
	key = 0;
	pData = nullptr;
	pParent = nullptr;
	pLeft = nullptr;
	pRight = nullptr;
};
//---------------------------------------------------------

template<typename TKey, class TData>
TKey TNode<TKey, TData>::GetKey() const
{
	return key;
};

template<typename TKey, class TData>
TNode<TKey, TData>* TNode<TKey, TData>::GetLeft() const
{
	return pLeft;
};

template<typename TKey, class TData>
TNode<TKey, TData>* TNode<TKey, TData>::GetRight() const
{
	return pRight;
};

#endif