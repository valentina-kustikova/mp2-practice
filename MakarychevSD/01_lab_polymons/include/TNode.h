#ifndef TNODE_H    
#define TNODE_H  

using namespace std;

template<class TKey, class TData>
class TNode
{
public:
	TKey key;
	TData pData;
	TNode<TKey, TData>* pNext;
	TNode();
	TNode(TKey, TData, TNode<TKey, TData>* pNext = 0);
	TNode(const TNode<TKey, TData>&);
	~TNode();
};

template<class TKey, class TData>
TNode<TKey, TData>::TNode()
{
	key = 0;
	pNext = nullptr;
}

template<class TKey, class TData>
TNode<TKey, TData>::TNode(TKey key, TData pData, TNode<TKey, TData>* pNext)
{
	this->key = key;
	this->pData = pData;
	this->pNext = pNext;
}

template<class TKey, class TData>
TNode<TKey, TData>::TNode(const TNode<TKey, TData>& node)
{
	this->key = node.key;
	this->pData = node.pData;
	pNext = nullptr;
}

template<class TKey, class TData>
TNode<TKey, TData>::~TNode()
{
	pNext = nullptr;
}

#endif 
