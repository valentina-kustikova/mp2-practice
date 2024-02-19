#ifndef _NODE_H
#define _NODE_H

#include <iostream>

using namespace std;

template<typename T> class Node {
public:
	T data;
	Node* pNext;

	Node();
	Node(const T& data_);
	Node(const Node& Node_);
	~Node();
};

template<typename T>
Node<T>::Node() {
	data = {};
	pNext = nullptr;
}

template<typename T>
Node<T>::Node(const T& data_) {
	data = data_;
	pNext = nullptr;
}

template<typename T>
Node<T>::Node(const Node& Node_) {
	data = Node_.data;
	pNext = Node_.pNext;
}

template<typename T>
Node<T>::~Node() {
	delete pNext;
	data = {};
}



#endif
