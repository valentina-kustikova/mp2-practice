#ifndef __NODE_H__
#define __NODE_H__

#include <iostream>


template <typename T>
class TNode {
public:
	T data;
	TNode<T>* pNext;
	TNode(const T& data_, TNode* pNext_ = nullptr) : data(data_), pNext(pNext_) { return; };
	TNode(const TNode<T>& obj);
};

template <typename T>
TNode<T>::TNode<T>(const TNode<T>& obj) {
	this->data = obj.data;
	this->pNext = new TNode<T>(obj.pNext);
}

#endif // !__NODE_H__