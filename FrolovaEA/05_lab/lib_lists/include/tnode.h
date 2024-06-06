#ifndef TNODE_H
#define TNODE_H

#include <iostream>


using namespace std;

template<typename T>
struct TNode
{
	T key;
	TNode* pNext;

	TNode() : key(), pNext(nullptr) {};
	TNode(const T& data) : key(data), pNext(nullptr) {};
	TNode(TNode<T>* _pNext) : key(), pNext(_pNext) {};
	TNode(const T& data, TNode<T>* _pNext) : key(data), pNext(_pNext) {};

	//TNode(T _key = T (), TNode* _pNext = nullptr)
	/*{
		key = _key;
		pNext = _pNext;
	}*/
	friend ostream& operator<<(ostream& out, TNode<T>& list)
	{
		out << list.key << endl;
		return out;
	}
};

#endif