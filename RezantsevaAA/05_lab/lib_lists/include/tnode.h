#ifndef __TNODE_H__
#define __TNODE_H__
#include <iostream>

using namespace std;

template<class TData>
class TNode {
public:
	TData data;
	TNode* pNext;
	TNode();
	TNode(const TData& data_, const TNode* pNext_ = nullptr);
	TNode(const TNode& Node);
};
template<class TData>
TNode<TData>::TNode() {
	data = NULL;
	pNext = nullptr;
}
template<class TData>
TNode<TData>::TNode(const TData& data_, const TNode* pNext_) {
	data = data_;
	pNext = (TNode*)pNext_;
}

template<class TData>
TNode<TData>::TNode(const TNode& Node) {
	data = Node.data;
	pNext = Node.pNext;
}

#endif