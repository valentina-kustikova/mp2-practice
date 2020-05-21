#include "TPolynom.h"
#include <iostream>
#include <string>

using namespace std;

TPolynom::TPolynom() {
    pol = new TList<unsigned int, double>();
}

TPolynom::TPolynom(const TList<unsigned int, double>* tmp) {
    TList<unsigned int, double>* tmp1 = new TList<unsigned int, double>(*tmp);
    pol = new TList<unsigned int, double>(tmp1->pFirst);
    CheckP(tmp1);
    tmp1->Reset();
    tmp1->Next();
    int conv = tmp1->pFirst->key;
    while (!tmp1->IsEnded())
    {
        if (tmp1->pCurr->key < conv)
        {
            pol->InsertBefore(*tmp1->pCurr, conv);
        }
        else
        {
            pol->InsertAfter(*tmp1->pCurr, conv);
        }
        conv = tmp1->pCurr->key;
    }
}

TPolynom::TPolynom(const string& str) {
    pol = new TList<unsigned int, double>();
    string _str;
    int i = 0;

    while (i < str.length())
    {
        if (str[i] == '-')
        {
            _str += str[i];
            i++;
        }
        if (str[i] == '+')
            i++;
        while (str[i] != '+' && str[i] != '-' && i < str.length())
        {
            _str += str[i];
            i++;
        }
        TMonom monom(_str);
        if (monom.pData != 0)
            * this = *this + monom;
        _str = "";
    }
}

TPolynom::TPolynom(const TPolynom& tmp) {
    pol = new TList<unsigned int, double>(*tmp.pol);
}

TPolynom::~TPolynom() {
    delete pol;
}

TPolynom TPolynom::operator+(const TPolynom& _tmp) {
    TPolynom tmp(_tmp);
    tmp.pol->Reset();
    TPolynom rez(*this);
    rez.pol->Reset();
    while (tmp.pol->pCurr != NULL)
    {
        rez = rez + *tmp.pol->pCurr;
        tmp.pol->Next();
    }
    return rez;
}

TPolynom TPolynom::operator-(const TPolynom& _tmp) {
    TPolynom rez = (*this) + (-_tmp);
    return rez;
}

TPolynom TPolynom::operator*(const TPolynom& _tmp) {
    TPolynom tmp(_tmp);
    TPolynom tmp1(*this);
    tmp1.pol->Reset();
    tmp.pol->Reset();
    TPolynom rez;
    while (!tmp1.pol->IsEnded())
    {
        rez += tmp * *tmp1.pol->pCurr;
        tmp1.pol->Next();
    }
    return rez;
}

TPolynom TPolynom::operator+(const TMonom& tmp) {
    TPolynom rez(*this);
    rez.pol->Reset();
    while (!rez.pol->IsEnded() && *rez.pol->GetpCur() < tmp && *rez.pol->GetpCur() != tmp)
        rez.pol->Next();
    if (rez.pol->IsEnded())
        rez.pol->Back(tmp);
    else
        if (*rez.pol->GetpCur() > tmp)
        {
            int k = rez.pol->GetpCur()->key;
            rez.pol->InsertBefore(tmp, k);
        }
        else
            if (*rez.pol->GetpCur() == tmp)
                * rez.pol->GetpCur() = *rez.pol->GetpCur() + tmp;
    rez.pol->Reset();
    return rez;
}

TPolynom TPolynom::operator-(const TMonom& tmp) {
    return *this + (-tmp);
}

TPolynom TPolynom::operator*(const TMonom& tmp) {
    TPolynom rez(*this);
    rez.pol->Reset();
    while (!rez.pol->IsEnded())
    {
        *rez.pol->GetpCur() = *rez.pol->GetpCur() * tmp;
        rez.pol->Next();
    }
    return rez;
}

TPolynom& TPolynom::operator+=(const TMonom& tmp) {
    TPolynom rez(*this);
    *this = rez + tmp;
    return (*this);
}

TPolynom& TPolynom::operator-=(const TMonom& tmp) {
    TPolynom rez(*this);
    *this = rez - tmp;
    return *this;
}

TPolynom& TPolynom::operator*=(const TMonom& tmp) {
    TPolynom rez(*this);
    *this = rez * tmp;
    return *this;
}

TPolynom TPolynom::operator*(double c) {
    TPolynom rez;
    if (c == 0)
        return rez;
    rez = *this;
    rez.pol->Reset();
    while (!rez.pol->IsEnded())
    {
        *rez.pol->pCurr *= c;
        rez.pol->Next();
    }
    return rez;
}

TPolynom& TPolynom::operator+=(const TPolynom& tmp) {
    TPolynom rez = (*this) + tmp;
    *this = rez;
    return *this;
}

TPolynom& TPolynom::operator-=(const TPolynom& tmp) {
    TPolynom rez = (*this) - tmp;
    *this = rez;
    return *this;
}

TPolynom& TPolynom::operator*=(const TPolynom& tmp) {
    TPolynom rez = (*this) * tmp;
    *this = rez;
    return *this;
}

TPolynom& TPolynom::operator*=(double c) {
    TPolynom rez = (*this) * c;
    *this = rez;
    return *this;
}

TPolynom TPolynom::operator-() const {
    TPolynom rez(*this);
    rez *= (-1);
    return rez;
}

TPolynom& TPolynom::operator=(const TPolynom& tmp) {
    if (*this == tmp)
        return *this;
    delete pol;
    pol = new TList<unsigned int, double>(*tmp.pol);
    return *this;
}

bool TPolynom::operator==(const TPolynom& tmp) const
{
    pol->Reset();
    tmp.pol->Reset();
    while (!pol->IsEnded() && !tmp.pol->IsEnded())
    {
        if (pol->GetpCur() != tmp.pol->GetpCur())
            return false;
        pol->Next();
        tmp.pol->Next();
    }
    if (!pol->IsEnded() || !tmp.pol->IsEnded())
        return false;
    return true;
}

void TPolynom::CheckP(const TList<unsigned int, double>* tmp) const {
    TList<unsigned int, double> rez(*tmp);
    rez.Reset();
    while (!rez.IsEnded())
    {
        if (rez.pCurr->key > 999)
        {
            throw "limit!";
        }
        rez.Next();
    }
}