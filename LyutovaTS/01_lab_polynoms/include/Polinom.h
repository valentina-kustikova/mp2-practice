#ifndef _TPOLINOM_H_
#define _TPOLINOM_H_

#include <specstrings.h>
#include <iostream>
#include "TList.h"
#include "TMonom.h"
#include "Exception.h"

class TPolinom
{
private:
    TList<unsigned int, double> *mon;

public:
    TPolinom();
    TPolinom(const TList<unsigned, double> );
    TPolinom(const TPolinom& );
    TPolinom(const string&);
    ~TPolinom();

    TPolinom& operator=(const TPolinom&);
    TPolinom operator+(const TPolinom&);
    TPolinom operator+(const TMonom&)const;
    TPolinom operator-(const TPolinom&) const ;
    TPolinom operator-(const TMonom&);
    TPolinom operator*(const TPolinom&);
    TPolinom operator*(const TMonom&);
    TPolinom& operator+=(const TPolinom&);
    TPolinom& operator+=(const TMonom&);
    TPolinom& operator-=(const TPolinom&);
    TPolinom& operator-=(const TMonom&);

    bool operator==(const TPolinom&);

    friend ostream& operator<<(ostream& out, const TPolinom& pol);
    friend istream& operator>> (istream& in, TPolinom& pol);

};

TPolinom::TPolinom()
{
    mon = new TList<unsigned int, double>;
}

TPolinom::TPolinom(const TPolinom& p)
{
    mon = new TList<unsigned int, double>(*p.mon);
}

TPolinom::~TPolinom()
{
    delete mon;
}

TPolinom::TPolinom(const string& str) 
{
    mon = new TList<unsigned int, double>();
    int i = 0;
    string m;
    while (i < str.length()) 
    {
        if (str[i] == '-') 
        {
            m = str[i];
            i++;
        }
        if (str[i] == '+') 
            i++;
        while (str[i] != '+' && str[i] != '-' && i < str.length()) 
        {
            m += str[i];
            i++;
        }
        TMonom mono(m);
        if (mono.data != 0)
            *this += mono;
        mon->Reset();
    }
}


TPolinom::TPolinom(const TList<unsigned int, double> list)
{
    mon = new TList<unsigned int, double>();
    TList<unsigned int, double> *tmplist = new TList<unsigned int, double>(list);
    tmplist->Reset();
    while (!tmplist->IsFull())
    {
        if (tmplist->pCurr->key > 999)
            throw Exception ("bid degree");
        //*this = *this + Monom(tmp_list->getCurrentNodeKey(), tmp_list->getCurrentNodeData());
        tmplist->Next();
    }
    tmplist->Reset();
    delete tmplist;
}

TPolinom & TPolinom::operator=(const TPolinom& pol)
{
    if (*this == pol)
        return *this;
    delete mon;
    mon = new TList<unsigned int, double>(*pol.mon);
    return *this;
}

TPolinom TPolinom::operator+(const TMonom& m)const
{
    TPolinom res;
    this->mon->Reset();
   

    while (!this->mon->IsFull())
    {
        TMonom CurrM(this->mon->pCurr->key, this->mon->pCurr->pData);
        if (CurrM < m)
            res.mon->InsertE(CurrM.data, CurrM.key);
        else if (this->mon->pCurr->key == m.key)
        {
            TMonom SumM(m.key, m.data + this->mon->pCurr->pData);
            res.mon->InsertE(SumM.data, SumM.key);
        }
        this->mon->Next();
    }
    this->mon->Reset();
    return res;
};

TPolinom TPolinom::operator+(const TPolinom& tmp)
{

    TPolinom res;
    TPolinom P1(*this);
    TPolinom P2(tmp);
    P1.mon->Reset();
    P2.mon->Reset();


    while (!P1.mon->IsFull() && !P2.mon->IsFull())
    {
        TMonom M1 = TMonom(P1.mon->pCurr->key, P1.mon->pCurr->pData);
        TMonom M2 = TMonom(P2.mon->pCurr->key, P2.mon->pCurr->pData);
        if (M1 < M2)
        {
            res += M1;
            P2.mon->pNext;
        }
        else if (M1 == M2)
        {
            res += M1 + M2;
            P2.mon->pNext;
            P1.mon->pNext;
        }
        else  if (M1 > M2)
        {
            res += M2;
            P1.mon->pNext;
        }
    }
    this->mon->Next();

    while (!mon->IsFull())
    {
        res.mon->InsertE(mon->pCurr->pData, mon->pCurr->key);
        mon->Next();
    }
    this->mon->Reset();
    return res;

}

TPolinom TPolinom::operator-(const TPolinom& tmp) const
{

    TPolinom res;
    TPolinom P1(*this);
    TPolinom P2(tmp);
    P1.mon->Reset();
    P2.mon->Reset();


    while (!P1.mon->IsFull() && !P2.mon->IsFull())
    {
        TMonom M1 = TMonom(P1.mon->pCurr->key, P1.mon->pCurr->pData);
        TMonom M2 = TMonom(P2.mon->pCurr->key, P2.mon->pCurr->pData);
        if (M1 < M2)
        {
            res -= M1;
            P2.mon->pNext;
        }
        else if (M1 == M2)
        {
            res -= M1 - M2;
            P2.mon->pNext;
            P1.mon->pNext;
        }
        else  if (M1 > M2)
        {
            res -= M2;
            P1.mon->pNext;
        }
    }
    this->mon->Next();

    while (!mon->IsFull())
    {
        res.mon->InsertE(mon->pCurr->pData, mon->pCurr->key);
        mon->Next();
    }
    this->mon->Reset();
    return res;

}

TPolinom TPolinom::operator-(const TMonom& tmp2)
{
    return (TPolinom(*this) + TMonom(tmp2.key, tmp2.data));
}

TPolinom& TPolinom::operator-=(const TMonom& tmp2)
{
    return (TPolinom(*this) -= TMonom(tmp2.key, tmp2.data));
}

TPolinom& TPolinom::operator+=(const TPolinom& tmp)
{
    return (TPolinom(*this) += tmp);
}

TPolinom& TPolinom::operator +=(const TMonom& tmp2)
{
    TPolinom a(*this);
    *this = a + tmp2;
    return (*this);
}

TPolinom& TPolinom::operator-=(const TPolinom& tmp)
{
    return (TPolinom(*this) -= tmp);
}

bool TPolinom::operator==(const TPolinom& tmp)
{
    tmp.mon->Reset();
    mon->Reset();

    while (!tmp.mon->IsFull())
    {
        if ((tmp.mon->pCurr->key != mon->pCurr->key) ||
            (tmp.mon->pCurr->pData != mon->pCurr->pData))
        {
            mon->Reset();
            tmp.mon->Reset();
            return false;
        }
        tmp.mon->Next();
        mon->Next();
    }
   
    if (!mon->IsFull())
        return false;

    mon->Reset();
    tmp.mon->Reset();
    return true;
}

TPolinom TPolinom::operator*(const TPolinom & pol1)
{
    TPolinom res;
    TPolinom pol(pol1);
    pol.mon->Reset();
    while (!pol.mon->IsFull())
    {
        
        TPolinom tmp(TPolinom(*this) *
            TMonom(pol.mon->pCurr->key, pol.mon->pCurr->pData));
        res += tmp;
        pol.mon->Next();
    }
    return res;
}

TPolinom TPolinom::operator*(const TMonom& m)
    {
        TPolinom res;
        TPolinom pol(*this);
        pol.mon->Reset();
        while (!res.mon->IsFull())
        {
            TMonom M(pol.mon->pCurr->key, pol.mon->pCurr->pData);
            M = M * m;
            if (M.data != 0)
                res += M;
            pol.mon->Next();
        }
        return res;
    }

ostream& operator<<(ostream& out, const TPolinom& pol)
{
    pol.mon->Reset();
    if (pol.mon->IsFull())
        out << " 0 ";
    else
    {
       if (pol.mon->pCurr->key / 100 == 1)
           out << " * x" ;
       else if (pol.mon->pCurr->key / 100 != 0)
           out <<  " * x^" << pol.mon->pCurr->key / 100;
       if ((pol.mon->pCurr->key % 100) / 10 == 1)
           out <<" * y" ;
       else if ((pol.mon->pCurr->key % 100) / 10 != 0)
           out << " * y^"  << pol.mon->pCurr->key % 100 / 10;
       if (pol.mon->pCurr->key % 10 == 1)
           out << " * z";
       else if (pol.mon->pCurr->key % 10 != 0)
           out << " * z^" << pol.mon->pCurr->key % 10;

            pol.mon->Next();
            while (!pol.mon->IsFull())
            {
                if (pol.mon->pCurr->pData > 0)
                    out << " +" << pol.mon->pCurr->pData;
            }
        
       return out;
    }
}

istream& operator>>(istream& in, TPolinom& pol)
{
    delete pol.mon;
    pol.mon = new TList<unsigned int, double>;

    string str;
    getline(in, str);
   
    string monom;
    TPolinom result;
    int i = 0;

        for (size_t i = 0; i < str.length(); i++)
        {

            if (str[i] == ' ')
            throw Exception("Polynomial error");

            if (str[i] == '+')
                i++;
            if (str[i] == '-')
            {
                monom = str[i];
                i++;
            }

            while ((str[i] != '+') && (str[i] != '-') && (i < str.length()))
            {
                monom += str[i];
                i++;
            }
            TMonom mono(monom);
            if (mono.data != 0)
                pol += mono;
            pol.mon->Reset();

        }

    return in;
}

#endif
