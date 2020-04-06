#include "Polinom.h"
#include <iostream>
#include <string>

using namespace std;

Polinom::Polinom()
{
    pol = new TList<double, unsigned int>();
}

Polinom::Polinom(const string& str)
{
    pol = new TList<double, unsigned int>();
    int _key = 0;
    double pc = 1;
    int dx = 0, dy = 0, dz = 0;
    bool flag = false;
    char c = '+';
    for (int i = 0; i <= str.length(); i++)
    {
        int j = 0;
        char coef[10];
        if (((str[i] == '+') || (str[i] == '-')) && (flag == false))
        {
            flag = true;
            c = str[i];
            i++;
        }
        if (((str[i] == '+') || (str[i] == '-') || (i == str.length())) && (flag == true))
        {
            _key = dx * 100 + dy * 10 + dz;
            if (c == '-')
                pol->InsertEnd(_key, -pc);
            if (c == '+')
                pol->InsertEnd(_key, pc);
            if (!(i == str.length()))
                c = str[i];
            pc = 1;
            dx = 0, dy = 0, dz = 0;
        }
        if (isdigit(str[i]))
        {
            flag = true;
            while ((isdigit(str[i + j])) || (str[i + j] == '.'))
            {
                coef[j] = str[i + j];
                j++;
            }
            i += j;
            pc = (float)(atof(coef));
            memset(coef, 0, sizeof(coef));
        }
        if (str[i] == 'x')
        {
            flag = true;
            if (str[i + 1] == '^')
            {
                dx = static_cast<int>(str[i + 2]) - '0';
                i += 2;
            }
            else
                dx = 1;
        }
        if (str[i] == 'y')
        {
            flag = true;
            if (str[i + 1] == '^')
            {
                dy = static_cast<int>(str[i + 2]) - '0';
                i += 2;
            }
            else
                dy = 1;
        }
        if (str[i] == 'z')
        {
            flag = true;
            if (str[i + 1] == '^')
            {
                dz = static_cast<int>(str[i + 2]) - '0';
                i += 2;
            }
            else
                dz = 1;
        }
    }
    pol = StandartView();
}

Polinom::Polinom(TList<double, unsigned int>* tmp)
{
    pol = new TList<double, unsigned int>(*tmp);
    pol = StandartView();
}

Polinom::Polinom(const Polinom& tmp)
{
    pol = new TList<double, unsigned int>(*tmp.pol);
}

Polinom::~Polinom()
{
    delete pol;
}

TList<double, unsigned int>* Polinom::StandartView()
{
    if ((pol->pFirst == nullptr) || (pol->pFirst->pNext == nullptr))
        return pol;

    TList<double, unsigned int>* res = new TList<double, unsigned int>();
    bool flag = false;

    pol->Reset();
    res->InsertEnd(pol->pCur->key, pol->pCur->pData);
    pol->Next();
    while (!pol->IsEnded())
    {
        res->Reset();
        while ((!res->IsEnded()) && (flag == false))
        {
            if (pol->pCur->key > res->pCur->key)
            {
                res->InsertBefore(res->pCur->key, pol->pCur->pData, pol->pCur->key);
                flag = true;
            }
            res->Next();
        }
        if (pol->pCur->key < res->pPrev->key)
            res->InsertAfter(res->pPrev->key, pol->pCur->pData, pol->pCur->key);
        if (pol->pCur->key == res->pPrev->key)
            res->pPrev->pData += pol->pCur->pData;
        pol->Next();
        flag = false;
    }
    return res;
}

bool Polinom::operator==(const Polinom& tmp) const
{
    if (*this->pol == *tmp.pol)
        return true;
}

const Polinom& Polinom::operator=(const Polinom& tmp)
{
    if (*this == tmp)
        return *this;
    delete pol;
    pol = new TList<double, unsigned int>(*tmp.pol);
    return *this;
}

Polinom Polinom::operator+(const Polinom& p)
{
    Polinom res;
    TNode<double, unsigned int>* tmp1 = pol->pFirst;
    TNode<double, unsigned int>* tmp2 = p.pol->pFirst;
    while ((tmp1 != nullptr) && (tmp2 != nullptr))
    {
        if (tmp1->key > tmp2->key)
        {
            res.pol->InsertEnd(tmp1->key, tmp1->pData);
            tmp1 = tmp1->pNext;
        }
        else if (tmp1->key < tmp2->key)
        {
            res.pol->InsertEnd(tmp2->key, tmp2->pData);
            tmp2 = tmp2->pNext;
        }
        else
        {
            double t = tmp1->pData + tmp2->pData;
            if (t != 0)
            {
                res.pol->InsertEnd(tmp1->key, t);
            }
            tmp1 = tmp1->pNext;
            tmp2 = tmp2->pNext;
        }
    }
    if (tmp1 == nullptr)
    {
        while (tmp2 != nullptr)
        {
            res.pol->InsertEnd(tmp2->key, tmp2->pData);
            tmp2 = tmp2->pNext;
        }

    }
    else if (tmp2 == nullptr)
    {
        while (tmp2 != nullptr)
        {
            res.pol->InsertEnd(tmp1->key, tmp1->pData);
            tmp1 = tmp1->pNext;
        }

    }
    return res;
}

Polinom& Polinom::operator+=(const Polinom& tmp)
{
    Polinom p = *this;
    *this = p + tmp;
    return *this;
}

Polinom Polinom::operator-(const Polinom& tmp)
{
    Polinom res(tmp);
    res = -res;
    return (*this + (res));
}

Polinom& Polinom::operator-=(const Polinom& tmp)
{
    Polinom p = *this;
    *this = p - tmp;
    return *this;
}
Polinom Polinom::operator*(const Polinom& p)
{

    if ((pol->pFirst == nullptr) || (p.pol->pFirst == nullptr))
        return 0;
    Polinom tmp1(p);
    Polinom tmp2(*this);
    tmp1.pol->Reset();
    tmp2.pol->Reset();
    Polinom res;
    while (!tmp1.pol->IsEnded())
    {
        res += tmp2 * *tmp1.pol->pCur;
        tmp1.pol->Next();
    }
    return res;
}

Polinom Polinom::operator+(const TNode<double, unsigned int>& node)
{

    if (node.pData == 0)
        return *this;

    Polinom res(*this);
    TNode<double, unsigned int>* tmp = res.pol->pFirst;
    while ((tmp != nullptr) && (node.key < tmp->key))
        tmp = tmp->pNext;
    if (tmp == nullptr)
    {
        res.pol->InsertEnd(node.key, node.pData);
        return res;
    }

    if (tmp->key == node.key)
    {
        if (tmp->pData + node.pData != 0)
        {
            tmp->pData += node.pData;
            return res;
        }
        res.pol->Remove(tmp->key);
    }

    res.pol->InsertBefore(tmp->key, node.pData, node.key);
    return res;
}

Polinom Polinom::operator-(const TNode<double, unsigned int>& node)
{
    Polinom res = *this + (-node);
    return res;
}

Polinom Polinom::operator*(const TNode<double, unsigned int>& node)
{
    if (node.pData == 0)
        return 0;
    Polinom res(*this);
    res.pol->Reset();
    while (!res.pol->IsEnded())
    {
        *res.pol->pCur *= node;
        res.pol->Next();
    }
    return res;
}

Polinom& Polinom::operator+=(const TNode<double, unsigned int>& node)
{
    Polinom tmp = (*this) + node;
    *this = tmp;
    return *this;
}

Polinom& Polinom::operator-=(const TNode<double, unsigned int>& node)
{
    Polinom tmp = (*this) - node;
    *this = tmp;
    return *this;
}

Polinom& Polinom::operator*=(const TNode<double, unsigned int>& node)
{
    Polinom tmp = (*this) * node;
    *this = tmp;
    return *this;
}

Polinom Polinom::operator-()
{
    Polinom tmp(*this);

    while (!tmp.pol->IsEnded())
    {
        tmp.pol->pCur->pData *= (-1);
        tmp.pol->Next();
    }

    tmp.pol->Reset();
    return tmp;
}