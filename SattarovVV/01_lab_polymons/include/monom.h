#pragma once

#include "data.h"

class TMonom: public TData
{
public:
    double coeff;
    int degree;
public:
    TMonom(double coeff, int degree);

    virtual TMonom& operator=(const TMonom& monom);
    virtual int operator==(const TData& monom) const override;
    virtual int operator!=(const TData& monom) const override;
    virtual int operator<(const TData& monom) const override;
    virtual int operator>(const TData& monom) const override;

    virtual TData* Copy(); // создание копии
};
