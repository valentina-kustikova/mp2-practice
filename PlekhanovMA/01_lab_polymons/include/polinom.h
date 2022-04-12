#pragma once

#include <iostream>
#include "monom.h"
#include "headlist.h"
#include <string>
#include <vector>

class TPolinom
{
private:
    THeadList polinom;
    std::vector<std::string> strpolinom;
public:
    TPolinom();
    TPolinom(std::string str);
    TPolinom(const TPolinom &a);
    ~TPolinom();

    void Sort(); // сортировать полином
    void Similar(); // привести подобные
    void ClearPol(); // очистить полином
    bool Check();

    // операции с полиномами
    TPolinom operator+(const TPolinom& a);
    TPolinom operator-(const TPolinom& a);
    TPolinom operator-();
    TPolinom operator*(const TPolinom& a);
    TPolinom operator*(const double c);
    TPolinom operator/(const double c);
    TPolinom& operator=(const TPolinom& a);
    int operator==(const TPolinom& a) const;
    double operator()(int x, int y, int z);

    // ввод/вывод
    friend std::ostream& operator<<(std::ostream& out,
        const TPolinom& polinom)
    {
        TPolinom P(polinom);
        P.polinom.Reset();
        if (P.polinom.IsEmpty() == 1)
            out << 0;
        else
        {
            TMonom* monomf = new TMonom;
            monomf->data = P.polinom.GetCurr()->data;
            if (monomf->data.coeff > 0)
                out << monomf->data.coeff << "x^" << monomf->data.degx << "y^" << monomf->data.degy << "z^" << monomf->data.degz;
            else 
                out << "-" << monomf->data.coeff * -1 << "x^" << monomf->data.degx << "y^" << monomf->data.degy << "z^" << monomf->data.degz;
            P.polinom.Next();
            for (int i = 1; i < P.polinom.GetLenght(); i++)
            {
                TMonom* monom = new TMonom;
                monom->data = P.polinom.GetCurr()->data;
                if (monom->data.coeff > 0)
                out << " + " << monom->data.coeff << "x^" << monom->data.degx << "y^" << monom->data.degy << "z^" << monom->data.degz;
                else
                out << " - " << monom->data.coeff * -1 << "x^" << monom->data.degx << "y^" << monom->data.degy << "z^" << monom->data.degz;
                P.polinom.Next();
            }
        }
        return out;
    }
};
