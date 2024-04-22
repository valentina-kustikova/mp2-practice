#ifndef TNODE_H
#define TNODE_H

#include <iostream>

using namespace std;

template <typename T>
struct TNode {
	T data;
	TNode<T>* pNext;

	TNode() : data(), pNext(nullptr) {};
	TNode(const T& _data) : data(_data), pNext(nullptr) {};
	TNode(TNode<T>* _pNext) : data(), pNext(_pNext) {};
	TNode(const T& _data, TNode<T>* _pNext) : data(_data), pNext(_pNext) {};
};

#endif // !TNODE_H
