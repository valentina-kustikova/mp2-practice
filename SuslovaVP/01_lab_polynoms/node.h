#pragma once

#include <cstddef>

template<class DataType>

class Node
{
public:
	DataType data;
	Node<DataType>* next;
	Node() { next = NULL; };
	Node(DataType d, Node<DataType>* _next = NULL) { data = d; next = _next; };
	bool operator< (const Node& n)const { return (data < n.data); };
	bool operator> (const Node& n)const { return (data > n.data); };
};
