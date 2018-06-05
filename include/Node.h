#pragma once
template <typename T>
class Node
{
public:
	T key;
	Node<T> *pleft;
	Node<T> *pright;
	Node<T> *pparent;
	Node() { left = nullptr; right = nullptr; parent = nullptr; };
	Node(const T& k) { key = k; left = nullptr; right = nullptr; parent = nullptr; };
};