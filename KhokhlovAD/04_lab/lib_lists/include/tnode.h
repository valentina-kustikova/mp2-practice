#ifndef _TNODE_
#define _TNODE_


template <typename T>
struct TNode
{
	T data;
	TNode* pNext;
	TNode(const T& dat) : data(dat), pNext(nullptr) {};
	TNode();
	TNode(const TNode& nd);
	~TNode();
};

template <typename T>
TNode<T>::TNode()
{
	pNext = nullptr;
}

template <typename T>
TNode<T>::TNode(const TNode& nd)
{
	data = nd.data;
	pNext = nd.pNext;
}

template <typename T>
TNode<T>::~TNode()
{
	delete pNext;
}
#endif