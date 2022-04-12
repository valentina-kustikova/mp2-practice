#pragma once
#include <iostream>
#include "node.h"

class TMonom:TNode
{
public:
    TData data;// данные

public:
    TMonom();
    TMonom(int Degx, int Degy, int Degz, double Coeff);
    TMonom(TData Data);
    TMonom(const TMonom& monom);
    ~TMonom();

    TMonom& operator=(const TMonom& monom);
    
    int operator==(const TMonom& monom) const;
    int operator!=(const TMonom& monom) const;
    int operator<(const TMonom& monom) const;
    int operator>(const TMonom& monom) const;
};
