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
	TNode(TNode<T>* _pNext) : key(), pNext(_pNext) {}; // –”√¿≈“—ﬂ  Œ√ƒ¿ (const TNode<T>* _pNext)
	TNode(const T& data, const TNode<T>* _pNext) : key(data), pNext(_pNext) {};
};

#endif // !TNODE_H
