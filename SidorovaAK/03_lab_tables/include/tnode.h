#ifndef _TNODE_H_
#define _TNODE_H_

template<typename TKey, class TData>
class TNode
{
private:
	TKey key;
	TNode<TKey, TData>* pParent;
	TNode<TKey, TData>* pLeft;
	TNode<TKey, TData>* pRight;
	TData* pData;

public:
	TNode();
	TNode(TKey _key, TNode<TKey, TData>* _pParent = nullptr, TNode<TKey, TData>* _pLeft = nullptr,
		TNode<TKey, TData>* _pRight = nullptr, TData* _pData = nullptr);
	TNode(const TNode<TKey, TData>& _copy);
	~TNode();

	TNode<TKey, TData>* GetLeft() const;
	TNode<TKey, TData>* GetRight() const;
};
//---------------------------------------------------------

template<typename TKey, class TData>
TNode<TKey, TData>::TNode()
{
	key = 0;
	pParent = nullptr;
	pLeft = nullptr;
	pRight = nullptr;
	pData = nullptr;
};

template<typename TKey, class TData>
TNode<TKey, TData>::TNode(TKey _key, TNode<TKey, TData>* _pParent, TNode<TKey, TData>* _pLeft,
	TNode<TKey, TData>* _pRight, TData* _pData)
{
	key = _key;
	pParent = _pParent;
	pLeft = _pLeft;
	pRight = _pRight;
	pData = _pData;
};

template<typename TKey, class TData>
TNode<TKey, TData>::TNode(const TNode<TKey, TData>& _copy)
{
	key = _copy.key;
	pParent = _copy.pParent;
	pLeft = _copy.pLeft;
	pRight = _copy.pRight;
	pData = _copy.pData;
};

template<typename TKey, class TData>
TNode<TKey, TData>::~TNode()
{
	key = 0;
	pParent = nullptr;
	pLeft = nullptr;
	pRight = nullptr;
	pData = nullptr;
};
//---------------------------------------------------------

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