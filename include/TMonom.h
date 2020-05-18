#pragma once
#include <iostream>
#include "TNode.h"

class TMonom : public TNode<unsigned, double>
{
public:

    TMonom(unsigned key, const double* data);
    TMonom(unsigned key, const double& data);
    TMonom(const TMonom& monom);//copying constructor
    TMonom(const TNode<unsigned, double>& monom);//copying constructor
    ~TMonom() {};

    TMonom operator*(const TMonom& tmp);

    friend std::ostream& operator<<(std::ostream& out, const TMonom& monom);

    TMonom operator-() const;
};

TMonom::TMonom(unsigned key, const double* data) : TNode<unsigned, double>(key, data)
{
    if ((key > 999) || (*pData == 0)) 
        throw "Too big degree or zero coefficient";
}

TMonom::TMonom(unsigned key, const double& data) : TNode<unsigned, double>(key, data)
{
    if (key > 999 || *pData == 0) 
        throw "Too big degree or zero coefficient";
}

TMonom::TMonom(const TMonom& monom) : TNode<unsigned, double>(monom)
{
    if (key > 999 || *pData == 0) 
        throw "Too big degree or zero coefficient";
}

TMonom::TMonom(const TNode<unsigned, double>& monom) : TNode<unsigned, double>(monom)
{
    if (key > 999 || *pData == 0) 
        throw "Too big degree or zero coefficient";
}


TMonom TMonom::operator*(const TMonom& tmp)
{
    int degX = tmp.key / 100;
    int degY = (tmp.key % 100) / 10;
    int degZ = tmp.key % 10;

    int _degX = key / 100;
    int _degY = (key % 100) / 10;
    int _degZ = key % 10;

    if ((degX + _degX > 9) || ((degY + _degY > 9) || (degZ + _degZ > 9)))
    {
        throw "Degree shouldn't be bigger than 9";
    }

    TMonom out(key + tmp.key, *pData * *(tmp.pData));
    return out;
}


std::ostream& operator<<(std::ostream& out, const TMonom& monom)
{
    if (*(monom.pData) > 0)
        out << "+";
    else
        out << "-";
    if ((*(monom.pData) != 1 && *(monom.pData) != -1) || monom.key == 0)
        out << abs(*(monom.pData));
    if (monom.key / 100 == 1)
        out << "x";
    if ((monom.key / 100 != 0) && (monom.key / 100 != 1))
        out << "x^" << (monom.key / 100);
    if (monom.key % 100 / 10 == 1)
        out << "y";
    if ((monom.key % 100 / 10 != 0) && (monom.key % 100 / 10 != 1))
        out << "y^" << (monom.key % 100 / 10);
    if (monom.key % 10 == 1)
        out << "z";
    if ((monom.key % 10 != 0) && (monom.key % 10 != 1))
        out << "z^" << (monom.key % 10);
    return out;
}

TMonom TMonom::operator-() const
{
    TMonom out(key, -*(pData));
    return out;
}

