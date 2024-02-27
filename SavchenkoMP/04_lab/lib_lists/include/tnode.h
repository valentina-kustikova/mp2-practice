#ifndef TNODE_H
#define TNODE_H

#include <iostream>

using namespace std;

template <typename T>
struct TNode {
	T key;
	TNode<T>* pNext;

	TNode(const T& data, TNode<T>* _pNext = nullptr);
};

template <typename T>
TNode<T>::TNode(const T& data, TNode<T>* _pNext) {
	key = data;
	pNext = _pNext;
}


#endif // !TNODE_H
