#ifndef _TNode_H
#define _TNode_H

#include <iostream>

using namespace std;

template<typename T> class TNode {
public:
	T data;
	TNode* pNext;

	TNode();
	TNode(const T& data_);
	TNode(const TNode& TNode_);
	~TNode();
};

template<typename T>
TNode<T>::TNode() {
	data = {};
	pNext = nullptr;
}

template<typename T>
TNode<T>::TNode(const T& data_) {
	data = data_;
	pNext = nullptr;
}

template<typename T>
TNode<T>::TNode(const TNode& TNode_) {
	data = TNode_.data;
	pNext = TNode_.pNext;
}

template<typename T>
TNode<T>::~TNode() {
	delete pNext;
	data = {};

}


#endif
