#pragma once
#include <iostream>
using namespace std;

template <class T>
struct TNode
{
	T value;
	TNode<T>* pNext;
	
};