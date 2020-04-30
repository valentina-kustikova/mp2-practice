#ifndef TMONOM_H
#define TMONOM_H
#include "TNode.h"
#include <iostream>

using namespace std;

template<>
class TNode<double, unsigned int>
{
public:
    double pData;
    unsigned int key;
    TNode* pNext;

    TNode();
    TNode(unsigned int, double, TNode* _pNext = nullptr);
    TNode(const TNode&);

    TNode& operator=(const TNode&);
    TNode operator+(const TNode&);
    TNode operator-(const TNode&);
    TNode operator*(const TNode&);
    TNode& operator+=(const TNode&);
    TNode& operator-=(const TNode&);
    TNode& operator*=(const TNode&);
    TNode& operator*=(double);
    TNode operator*(double);
    TNode operator-() const;

    bool operator==(const TNode&) const;
    bool operator!=(const TNode&) const;

    friend ostream& operator<<(ostream& out, TNode& node)
    {
        if (node.pData > 0)
            out << " +";
        else
            out << " ";
        out << node.pData;
        if (node.key / 100 != 0)
            out << "x^" << node.key / 100;
        if ((node.key / 10) % 10 != 0)
            out << "y^" << (node.key / 10) % 10;
        if (node.key % 10 != 0)
            out << "z^" << node.key % 10;
        return out;
    }
};

#endif