#include "tnode.h"


template <typename T>
TNode<T>::TNode<T>(const T& data_, TNode* pNext_ = nullptr) {
	this->data = data_;
	this->pNext = pNext_;
}


template <typename T>
TNode<T>::TNode<T>(const TNode<T>& obj) {
	this->data = obj.data;
	this->pNext = obj.pNext;
}


