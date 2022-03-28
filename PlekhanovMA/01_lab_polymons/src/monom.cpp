#include "monom.h"

TMonom::TMonom()
{
    data.degx = 0;
    data.degy = 0;
    data.degz = 0;
    data.coeff = 0;
    data.degree = 0;
    pNext = nullptr;
}

TMonom::TMonom(TData Data)
{
    data.degx = Data.degx;
    data.degy = Data.degy;
    data.degz = Data.degz;
    data.degree = Data.degree;
    data.coeff = Data.coeff;
    pNext = nullptr;
}

TMonom::TMonom(int Degx, int Degy, int Degz, double Coeff)
{
    data.degx = Degx;
    data.degy = Degy;
    data.degz = Degz;
    data.coeff = Coeff;
    data.degree = Degx * 100 + Degy * 10 + Degz;
    pNext = nullptr;
}

TMonom::TMonom(int Degx, int Degy, int Degz, double Coeff, TMonom* PNext)
{
    data.degx = Degx;
    data.degy = Degy;
    data.degz = Degz;
    data.coeff = Coeff;
    data.degree = Degx * 100 + Degy * 10 + Degz;
    pNext = PNext;
}

TMonom::TMonom(const TMonom& monom)
{
    data.degx = monom.data.degx;
    data.degy = monom.data.degy;
    data.degz = monom.data.degz;
    data.degree = monom.data.degree;
    data.coeff = monom.data.coeff;
    pNext = monom.pNext;
}

TMonom::~TMonom()
{

}

TMonom & TMonom::operator=(const TMonom & monom)
{
    if (*this != monom)
    {
        data.coeff = monom.data.coeff;
        data.degree = monom.data.degree;
        data.degx = monom.data.degx;
        data.degy = monom.data.degy;
        data.degz = monom.data.degz;
        pNext = monom.pNext;
    }
    return *this;
}

int TMonom::operator==(const TMonom & monom) const
{
    return (data.degree == monom.data.degree) && (data.coeff == monom.data.coeff);
}

int TMonom::operator!=(const TMonom & monom) const
{
    return (data.degree != monom.data.degree) && (data.coeff == monom.data.coeff);
}

int TMonom::operator<(const TMonom & monom) const
{
    return (data.degree < monom.data.degree);
}

int TMonom::operator>(const TMonom & monom) const
{
    return (data.degree > monom.data.degree);
}
