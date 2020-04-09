#pragma once
#include "TNode.h"
#include <string>
 
template<>
class TNode<double, unsigned int> {
public:
	unsigned int key;
	double pData;
	TNode<double, unsigned int>* pNext;

	TNode(const TNode<double, unsigned int>&);
	TNode(unsigned int, double, TNode<double, unsigned int>* _monom = 0);
	TNode(const string&);
	~TNode();

	TNode<double, unsigned int> operator*(double);

	TNode<double, unsigned int> operator+(const TNode<double, unsigned int>&);
	TNode<double, unsigned int> operator-(const TNode<double, unsigned int>&);
	TNode<double, unsigned int> operator*(const TNode<double, unsigned int>&);

	TNode<double, unsigned int> operator-() const;

	TNode<double, unsigned int>& operator=(const TNode<double, unsigned int>&);

	bool operator>(const TNode<double, unsigned int>&) const;
	bool operator<(const TNode<double, unsigned int>&) const;
	bool operator==(const TNode<double, unsigned int>&) const;
	bool operator!=(const TNode<double, unsigned int>&) const;
};

typedef TNode<double, unsigned int> Monom;