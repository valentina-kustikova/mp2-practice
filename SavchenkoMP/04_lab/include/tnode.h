#ifndef TNODE_H
#define TNODE_H

#include <iostream>

using namespace std;

template <typename T>
struct TNode {
	T key;
	TNode<T>* pNext;

	TNode() : key(), pNext(nullptr) {};
	TNode(const T& data) : key(data), pNext(nullptr) {};
	TNode(const T& data, TNode<T>* node) : key(data), pNext(node) {};
	//TNode(const TNode<T>& node) : key(node.key), pNext(node.pNext) {};
};


#endif // !TNODE_H
