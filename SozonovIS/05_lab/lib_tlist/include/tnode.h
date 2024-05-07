#ifndef __NODE_H__
#define __NODE_H__

template <typename ValueType>
struct TNode {
	ValueType data;
	TNode* pNext;
	TNode();
	TNode(const ValueType& d, TNode<ValueType>* Next = nullptr);
};

template <typename ValueType>
TNode<ValueType>::TNode() {
	data = {};
	pNext = nullptr;
};

template <typename ValueType>
TNode<ValueType>::TNode(const ValueType& d, TNode<ValueType>* Next) {
	data = d;
	pNext = Next;
};

#endif