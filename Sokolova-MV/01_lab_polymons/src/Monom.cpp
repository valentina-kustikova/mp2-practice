#include "Monom.h"

TMonom::TMonom(double _coeff, int _degree)
{
    if (_degree > 999) { throw 1; }
    this->coeff = _coeff;
    this->degree = _degree;
}
TMonom & TMonom::operator=(const TMonom & m)
{
    if (*this != m)
    {
        this->coeff = m.coeff;
        this->degree = m.degree;
    }
    return *this;
}
bool TMonom::operator==(const TMonom& m) const
{
    return this->degree == m.degree && this->coeff == m.coeff;
}
bool TMonom::operator!=(const TMonom & m) const
{
    return this->degree != m.degree || this->coeff != m.coeff;
}
bool TMonom::operator<(const TMonom & m) const
{
    if (this->degree < m.degree)
        return true;
    if (this->degree == m.degree)
    {
        if (this->coeff < m.coeff) return true;
        else return false;
    }
    else return false;
}
bool TMonom::operator>(const TMonom & m) const
{
    if (this->degree > m.degree)
        return true;
    if (this->degree == m.degree)
    {
        if (coeff > m.coeff) return true;
        else return false;
    }
    else return false;
}
/*TData * TMonom::Copy()
{
    TData* data = new TMonom(this->coeff, this->degree);
    return data;
}
/**/
TMonom TMonom::operator*(const int& c)
{
    coeff *= c;
    return *this;
}
