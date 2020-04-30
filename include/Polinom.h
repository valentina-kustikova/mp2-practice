#ifndef POLINOM_H
#define POLINOM_H
#include "TSList.h"
#include <iostream>

using namespace std;

class Polinom
{
private:
    TList<double, unsigned int>* pol;
public:
    Polinom();
    Polinom(const string&);
    Polinom(TList<double, unsigned int>*);
    Polinom(const Polinom&);
    ~Polinom();

    TList<double, unsigned int>* StandartView();
    bool operator==(const Polinom&) const;
    const Polinom& operator=(const Polinom&);

    Polinom operator+(const Polinom&);
    Polinom& operator+=(const Polinom&);
    Polinom operator-(const Polinom&);
    Polinom& operator-=(const Polinom&);
    Polinom operator*(const Polinom&);

    Polinom operator+(const TNode<double, unsigned int>&);
    Polinom operator-(const TNode<double, unsigned int>&);
    Polinom operator*(const TNode<double, unsigned int>&);
    Polinom& operator+=(const TNode<double, unsigned int>&);
    Polinom& operator-=(const TNode<double, unsigned int>&);
    Polinom& operator*=(const TNode<double, unsigned int>&);

    Polinom operator-();

    friend ostream& operator<<(ostream& out, Polinom& tmp)
    {
        out << *tmp.pol;
        return out;
    }
};

#endif