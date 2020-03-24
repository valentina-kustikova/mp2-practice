#pragma once
#include <string>
#include <cstring>
#include <iostream>

#include "TList.h"
#include "TMonom.h"
using namespace std;
class TPolynom
{
public:
    TList<unsigned, double>* polynoms;

public:
    TPolynom();
    TPolynom(const TList<unsigned, double>& _polynoms);
    TPolynom(const string& str);
    TPolynom(const TPolynom& copy_polynoms);
    ~TPolynom();

    TPolynom& operator=(const TPolynom& tmp);// делала сама!!!!
    TPolynom operator+(const TPolynom& tmp);//на потом
    TPolynom operator-(const TPolynom& tmp);//проверить
    TPolynom operator*(const TPolynom& tmp);//
    TPolynom operator*(double a);

    TPolynom& operator+=(const TPolynom& tmp);// попробовала сама сделать!!!!!
    TPolynom& operator-=(const TPolynom& tmp);//сделала сама

    TPolynom operator+(const TMonom& monom);// на потом
    TPolynom operator-(const TMonom& monom);//не меняла
    TPolynom operator*(const TMonom& node);//

    TPolynom& operator+=(const TMonom& node);//делала сама
    TPolynom& operator-=(const TMonom& node);//согласна не меняла
    TPolynom& operator*=(const TMonom& node);//

    bool operator==(const TPolynom& temp) const;

    friend std::ostream& operator<<(std::ostream& out, const TPolynom& polynom);
    friend std::istream& operator >> (std::istream& in, TPolynom& polynom);

    TPolynom operator-() const;//согласна
};

TPolynom::TPolynom()
{
    polynoms = new TList<unsigned, double>;
}

TPolynom::TPolynom(const TList<unsigned, double>& _polynoms)
{
    polynoms = new TList<unsigned, double>(_polynoms);
}

TPolynom::TPolynom(const TPolynom& copy_polynoms)
{
    polynoms = new TList<unsigned, double>(*(copy_polynoms.polynoms));
}

TPolynom::~TPolynom()
{
    delete polynoms;
}

TPolynom& TPolynom::operator=(const TPolynom& _polynoms)
{
    if (*this == _polynoms) 
        return *this;
    if (polynoms->pFirst)
        delete polynoms;
    polynoms = new TList<unsigned, double>(*(_polynoms.polynoms));
    return *this;
}

TPolynom TPolynom::operator+(const TPolynom& temp)
{
    TPolynom out;
    TNode<unsigned, double>* first = polynoms->pFirst;
    TNode<unsigned, double>* second = temp.polynoms->pFirst;
    while ((first != nullptr) && (second != nullptr))
    {

        if (first->key > second->key)
        {
            out.polynoms->InsertToEnd(first->key, first->pData);
            first = first->pNext;
        }
        else if (first->key < second->key)
        {
            out.polynoms->InsertToEnd(second->key, second->pData);
            second = second->pNext;
        }
        else
        {
            if (*(first->pData) != -*(second->pData))
            {
                out.polynoms->InsertToEnd(first->key, *(first->pData) + *(second->pData));
            }
            first = first->pNext;
            second = second->pNext;
        }

        if (first == nullptr)
        {
            while (second != nullptr)
            {
                out.polynoms->InsertToEnd(second->key, second->pData);
                second = second->pNext;
            }

        }
        else if (second == nullptr)
        {
            while (first != nullptr)
            {
                out.polynoms->InsertToEnd(first->key, first->pData);
                first = first->pNext;
            }

        }
    }

    return out;
}

TPolynom& TPolynom::operator+=(const TPolynom& tmp)
{
    //TPolynom  = *this;
    *this = (*this) + tmp;
    return *this;


   /* TPolynom tmp = (*this) + tm;
    *this = tmp;
    return *this;*/
}

TPolynom TPolynom::operator+(const TMonom& monom)
{
    TPolynom result;

    TNode<unsigned, double>* first = polynoms->pFirst;
    bool isInserted = false;
    while ((first != nullptr) && (!isInserted))
    {
        if (first->key > monom.key)
        {
            result.polynoms->InsertToEnd(first->key, first->pData);
            first = first->pNext;
        }
        else if (first->key < monom.key)
        {
            result.polynoms->InsertToEnd(monom.key, monom.pData);
            isInserted = true;
        }
    }

    if (first == nullptr)
    {
        result.polynoms->InsertToEnd(monom.key, monom.pData);
    }

    if (isInserted)
    {
        while (first != nullptr)
        {
            result.polynoms->InsertToEnd(first->key, first->pData);
            first = first->pNext;
        }

    }

    return result;
}

TPolynom& TPolynom::operator+=(const TMonom& monom)
{

    //TPolynom copy = *this;
    *this = *this + monom;
    return *this;
}

TPolynom TPolynom::operator-(const TPolynom& tmp)
{
    //TPolynom res(tmp);
   // res = -res;
    return (*this + (-tmp));
}

TPolynom& TPolynom::operator-=(const TPolynom& tmp)
{
    //TPolynom pol = (*this) - tmp;
    *this = *this + (-tmp);
    return *this;
}

TPolynom TPolynom::operator-(const TMonom& monom)
{
    return *this + (-monom);
}

TPolynom& TPolynom::operator-=(const TMonom& monom)
{
    return *this += (-monom);
}

TPolynom TPolynom::operator*(const TPolynom& tmp)
{
    TPolynom out, tmpres;
    TNode<unsigned, double>* second = tmp.polynoms->pFirst;
    if (second == nullptr)
    {
        return out;
    }
    tmpres = *this * *second;
    out = tmpres;
    second = second->pNext;

    while (second != nullptr)
    {
        tmpres = *this * *second;
        out += tmpres;
        second = second->pNext;
    }
    return out;
}

TPolynom TPolynom::operator*(const TMonom& node)
{
    TPolynom result(*this);
    TNode<unsigned, double>* first = result.polynoms->pFirst;
    while (first != nullptr)
    {
        *first = (TMonom)(*first) * node;
        first = first->pNext;
    }
    return result;
}

TPolynom& TPolynom::operator*=(const TMonom& node)
{
    TNode<unsigned, double>* first = polynoms->pFirst;
    while (first != nullptr)
    {
        *first = (TMonom)*first * node;
        first = first->pNext;
    }
    return *this;
}

bool TPolynom::operator==(const TPolynom& tmp) const
{
    bool result = true;
    TNode<unsigned, double>* polynom1 = polynoms->pFirst;
    TNode<unsigned, double>* polynom2 = tmp.polynoms->pFirst;
    while ((polynom1 != nullptr) && (polynom2 != nullptr))
    {
        if ((polynom1->key != polynom2->key) || (*(polynom1->pData) != *(polynom2->pData)))
            result = false;
        polynom1 = polynom1->pNext;
        polynom2 = polynom2->pNext;
    }
    if ((polynom1 != nullptr) || (polynom2 != nullptr))
        result = false;

    return result;
}

ostream& operator<<(ostream& out, const TPolynom& polynom)
{
    TNode<unsigned, double>* element = polynom.polynoms->pFirst;
    if (element == nullptr)
    {
        out << "0";
        return out;
    }
    while (element != nullptr)
    {
        out << (TMonom)*element << ' ';

        element = element->pNext;
    }
    return out;
}

istream& operator >> (istream& in, TPolynom& polynom)
{
    delete polynom.polynoms;
    polynom.polynoms = new TList<unsigned, double>;
    string line, buffer;
    getline(in, line);
    int coef = 0, mul = 1, mode = 0;
    for (int i = 0; i < line.size(); i++)
    {
        if (line[i] == ' ' && !buffer.empty())
        {
            if (mul == 0) throw exception("Incorrect input 1");
            if (stof(buffer) != 0)
            {
                polynom += TMonom(coef, mul * stof(buffer));
            }
            buffer.clear();
            mul = 0;
            coef = 0;
            mode = 0;
        }
        else if (line[i] == '+')
        {
            if (mode == 1) throw exception("Incorrect input 2");
            mul = 1;
        }
        else if (line[i] == '-')
        {
            if (mode == 1) throw exception("Incorrect input 3");
            mul = -1;
        }
        else if ((line[i] > 47 && line[i] < 58) || line[i] == '.')
        {
            buffer.push_back(line[i]);
            if (mode == 1) throw exception("Incorrect input 4");
        }
        else if (line[i] == 'x')
        {
            mode = 1;
            if (buffer.empty()) buffer = "1";
            if (line[i + 1] == '^')
            {
                if (line[i + 2] < 48 || line[i + 2] > 57)
                    throw exception("Incorrect input 5");
                if ((line[i + 2] - 48) + (coef / 100) > 9)
                    throw exception("Incorrect degree");
                coef += 100 * (line[i + 2] - 48);
                i = i + 2;
                continue;
            }
            else
            {
                if (coef / 100 == 9) throw exception("Incorrect degree");
                coef += 100;
                continue;
            }
        }
        else if (line[i] == 'y')
        {
            mode = 1;
            if (buffer.empty()) buffer = "1";
            if (line[i + 1] == '^')
            {
                if (line[i + 2] < 48 || line[i + 2] > 57) throw exception("Incorrect input");
                if ((line[i + 2] - 48) + ((coef % 100) / 10) > 9) throw exception("Incorrect degree");
                coef += 10 * (line[i + 2] - 48);
                i = i + 2;
                continue;
            }
            else
            {
                if ((coef % 100) / 10 == 9) throw exception("Incorrect degree");
                coef += 10;
                continue;
            }
        }
        else if (line[i] == 'z')
        {
            mode = 1;
            if (buffer.empty()) buffer = "1";
            if (line[i + 1] == '^')
            {
                if (line[i + 2] < 48 || line[i + 2] > 57) throw exception("Incorrect input");
                if ((line[i + 2] - 48) + (coef % 10) > 9) throw exception("Incorrect degree");
                coef += (line[i + 2] - 48);
                i = i + 2;
                continue;
            }
            else
            {
                if (coef % 10 == 9) throw exception("Incorrect degree");
                coef += 1;
                continue;
            }
        }
        else if (line[i] != ' ')
        {
            throw exception("Incorrect input");
        }
    }
    if (!buffer.empty())
    {
        polynom += TMonom(coef, mul * stof(buffer));
        buffer.clear();
        coef = 0;
    }
    return in;
}

TPolynom TPolynom::operator-() const
{
    TPolynom result(*this);
    TNode<unsigned, double>* polynom_element = result.polynoms->pFirst;
    while (polynom_element != nullptr)
    {
        *(polynom_element->pData) *= -1;
        polynom_element = polynom_element->pNext;
    }
    return result;
}
