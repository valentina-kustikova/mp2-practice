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


bool TMonom::operator==(const TMonom & monom) const
{
    return ((this->degree == monom.degree) && (this->coeff == monom.coeff));
}


bool TMonom::operator!=(const TMonom & monom) const
{
    return ((this->degree != monom.degree) && (this->coeff != monom.coeff));
}


bool TMonom::operator<(const TMonom & monom) const
{
    return (this->degree < monom.degree);
}


bool TMonom::operator>(const TMonom & monom) const
{
    return (this->degree > monom.degree);
}
