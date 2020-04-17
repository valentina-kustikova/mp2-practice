#pragma once
#include "Node.h"
#include <string>
template <>
class TNode<unsigned int, double>
{
public:
	unsigned int key;
	double pData;
	TNode *pNext;
public:
	TNode(unsigned int, double, TNode* = nullptr);
	TNode(const TNode<unsigned int, double>&);
	TNode(const string&);
	~TNode();
	TNode operator*(double);
	TNode operator+(const TNode&);
	TNode operator-(const TNode&);
	TNode operator*(const TNode&);
	TNode operator-() const;
	TNode& operator=(const TNode&);
	bool operator>(const TNode&) const;
	bool operator<(const TNode&) const;
	bool operator==(const TNode&) const;
	bool operator!=(const TNode&) const;
};

typedef TNode<unsigned int, double> Monom;
