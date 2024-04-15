#ifndef _TNODE_
#define _TNODE_


template <typename T>
struct TNode
{
	T data;
	TNode<T>* pNext;
	TNode() { pNext = nullptr; };
	TNode(const T& dat) : data(dat), pNext(nullptr) {};

	bool operator<(const TNode<T>& nd)const;
	bool operator>(const TNode<T>& nd)const;
	bool operator==(const TNode<T>& nd)const;
	bool operator!=(const TNode<T>& nd)const;
};

template <typename T>
bool TNode<T>::operator<(const TNode<T>& nd) const
{
	return this->data < nd.data;
}


template <typename T>
bool TNode<T>::operator>(const TNode<T>& nd) const
{
	return this->data > nd.data;
}


template <typename T>
bool TNode<T>::operator==(const TNode<T>& nd) const
{
	return this->data == nd.data;
}


template <typename T>
bool TNode<T>::operator!=(const TNode<T>& nd) const
{
	return this->data != nd.data;
}

#endif