#pragma once

#include <iostream>
#include "monom.h"
#include "list.h"
#include <string>
#include <vector>

class TPolinom : TList
{
private:
    TList polinom;
    std::vector<std::string> strpolinom;

public:
    TPolinom();
    TPolinom(TList polinom);
    TPolinom(const TPolinom &a);
    ~TPolinom();

    void Input(std::string& str); // ввод полинома
    void StrToList(); // преобразование из строки в список
    void Similar(); // привести подобные
    void ClearPol(); // очистить полином

    // операции с полиномами
    TPolinom operator+(const TPolinom& a);
    TPolinom operator-(const TPolinom& a);
    TPolinom operator-();
    TPolinom operator*(const TPolinom& a);
    TPolinom operator*(const double c);
    TPolinom& operator=(const TPolinom& a);
    int operator==(const TPolinom& a) const;
    double Values(int x, int y, int z); // значение полинома с заданными значениями

    // вывод
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
            monomf = P.polinom.GetMonom();
            if (monomf->data.coeff > 0)
                out << monomf->data.coeff << "x^" << monomf->data.degx << "y^" << monomf->data.degy << "z^" << monomf->data.degz;
            else 
                out << "-" << monomf->data.coeff * -1 << "x^" << monomf->data.degx << "y^" << monomf->data.degy << "z^" << monomf->data.degz;
            P.polinom.Next();
            for (int i = 1; i < P.polinom.GetLenght(); i++)
            {
                TMonom* monom = new TMonom;
                monom = P.polinom.GetMonom();
                if (monom->data.coeff > 0)
                out << " + " << monom->data.coeff << "x^" << monom->data.degx << "y^" << monom->data.degy << "z^" << monom->data.degz;
                else
                out << " - " << monom->data.coeff * -1 << "x^" << monom->data.degx << "y^" << monom->data.degy << "z^" << monom->data.degz;
                P.polinom.Next();
            }
        }
        return out;
    }

    // служебные методы
    std::vector<std::string> LookPolinom();
    TPolinom Razd(const double c);
};
