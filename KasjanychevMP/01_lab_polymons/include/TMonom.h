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

    friend ostream& operator<<(ostream& out, TNode<unsigned int, double>& node)
    {
        if (node.pData > 0)
            out << "+";
        out << node.pData;
        if (node.key / 100 != 0)
            out << "x^" << node.key / 100;
        if ((node.key / 10) % 10 != 0)
            out << "y^" << (node.key / 10) % 10;
        if (node.key % 10 != 0)
            out << "z^" << node.key % 10;
        out << " ";
        return out;
    }
};
