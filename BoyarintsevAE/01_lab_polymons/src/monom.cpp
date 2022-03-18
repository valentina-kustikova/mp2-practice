#include "monom.h"

TMonom::TMonom(double coeff, int degree)
{
    this->coeff = coeff;
    this->degree = degree;
}

TMonom & TMonom::operator=(const TMonom & monom)
{
    if (*this != monom)
    {
        this->coeff = monom.coeff;
        this->degree = monom.degree;
    }
    return *this;
}

int TMonom::operator==(const TMonom & monom) const
{
    return (this->degree == monom.degree);
}

int TMonom::operator!=(const TMonom & monom) const
{
    return (this->degree != monom.degree);
}

int TMonom::operator<(const TMonom & monom) const
{
    return (this->degree < monom.degree);
}

int TMonom::operator>(const TMonom & monom) const
{
    return (this->degree > monom.degree);
}

TData * TMonom::Copy()
{
    TData* data = new TMonom(this->coeff, this->degree);
    return data;
}
