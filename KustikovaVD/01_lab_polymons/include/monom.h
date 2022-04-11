#pragma once

#include "data.h"

class TMonom: public TData
{
public:
    double coeff;
    int degree;
public:
    TMonom(double coeff, int degree);
    
    TMonom& operator=(const TMonom& monom);
    
    int operator==(const TMonom& monom) const;
    int operator!=(const TMonom& monom) const;
    int operator<(const TMonom& monom) const;
    int operator>(const TMonom& monom) const;
    
    virtual TData* Copy(); // создание копии
};
