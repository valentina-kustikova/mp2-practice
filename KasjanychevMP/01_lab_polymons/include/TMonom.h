#pragma once
#include "List.h"
#include <string>

template<>
class TNode<unsigned int, double> {
public:
    unsigned int key;
    double pData;
    TNode* pNext;

    TNode();
    TNode(unsigned int, double, TNode* = nullptr);
    TNode(const TNode<unsigned int, double>&);
    TNode(const string&);
    ~TNode();

    TNode<unsigned int, double>& operator=(const TNode<unsigned int, double>&);
    TNode<unsigned int, double> operator+(const TNode<unsigned int, double>&);
    TNode<unsigned int, double> operator-(const TNode<unsigned int, double>&);
    TNode<unsigned int, double> operator*(const TNode<unsigned int, double>&);
    TNode<unsigned int, double> operator-() const;

    TNode<unsigned int, double> operator*(double);

    TNode<unsigned int, double>& operator+=(const TNode<unsigned int, double>&);
    TNode<unsigned int, double>& operator-=(const TNode<unsigned int, double>&);
    TNode<unsigned int, double>& operator*=(const TNode<unsigned int, double>&);
    TNode<unsigned int, double>& operator*=(double);

    bool operator==(const TNode<unsigned int, double>&) const;
    bool operator>(const TNode<unsigned int, double>&) const;
    bool operator<(const TNode<unsigned int, double>&) const;
    bool operator!=(const TNode<unsigned int, double>&) const;
};
