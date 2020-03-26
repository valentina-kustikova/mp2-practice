#ifndef _TMONOM_H_
#define _TMONOM_H_
#include <iostream>
#include "TNode.h"
#include "Exception.h"

class TMonom
{
public:
    unsigned int key;
    double data;
    TMonom* next;

    TMonom();
    TMonom(const TMonom&);
    TMonom(unsigned int, double, TMonom*);
    ~TMonom();

    TMonom operator+(const TMonom&);
    TMonom operator-(const TMonom&);
    TMonom operator*(const TMonom&);
    TMonom& operator=(const TMonom&);

    bool operator>(const TMonom&) const;
    bool operator<(const TMonom&) const;
    bool operator==(const TMonom&) const;

    TMonom(const string&); // необходима для ввода

    friend ostream& operator<<(ostream& out, TMonom& mon)
    {
        if (mon.data > 0)
            out << "+";
        else
            out << "-";
        out << mon.data;

        if (mon.key / 100 != 0) 
            out << "x^" << (mon.key / 100);


        if (mon.key % 100 / 10 != 0) 
            out << "y^" << (mon.key % 100 / 10);

        if (mon.key % 10 != 0)
            out << "z^" << (mon.key % 10);
        return out;
    }
};

TMonom::TMonom()
{
    key = 0;
    data = 0;
    next = 0;
}

TMonom::~TMonom()
{}

TMonom::TMonom(const TMonom& tmp)
{
    key = tmp.key;
    data = tmp.data;
    next = tmp.next;
}

TMonom::TMonom(unsigned int k, double d, TMonom* node = 0)
{
    key = k;
    data = d;
    next = next;
}

TMonom::TMonom(const string& str)
{
    string coeff, deg;
    string degX = "0";
    string degY = "0";
    string degZ = "0";

    int i = 0;

   
    if (str[0] == 'x' || str[0] == 'y' || str[0] == 'z')
        coeff = '1';
    while (str[i] != 'x' && str[i] != 'z' && str[i] != 'y' 
        && i < str.length() && str[i] != '*' && str[i] != '^')
    {
        coeff += str[i];
        i++;
    }
    while (i < str.length())
    {
        if (str[i] == 'x')
        {
            
            
            i += 2;
            //if (str[i] == '*' && str[i] == '^')
            //    i++;
            if (str[i] == 'y' || str[i] == 'z' || i == str.length())
                degX = "1";
            else degX = str[i];
            
        }
        if (str[i] == 'y')
        {
            i += 2;
            if (str[i] == 'x' || str[i] == 'z' || i == str.length())
                degY = "1";
            else degY = str[i];
        }
        if (str[i] == 'z')
        {
            i += 2;
            if (str[i] == 'x' || str[i] == 'y' || i == str.length())
                degZ = "1";
            else degZ = str[i];
        }
        i++;
    }

    deg += degX + degY + degZ;
    key = stoi(deg); //функция переводит строку в число
    data = stod(coeff); //функция преобразует строку в число с плавающей точкой

    next = 0;
}

TMonom& TMonom::operator=(const TMonom& m)
{
    if (this != &m)
    {
        key = m.key;
        data = m.data;
    }
    return *this;
}

TMonom TMonom::operator+(const TMonom& m)
{
    if (key != m.key)
        throw Exception ("Different Degrees of monoms");
    TMonom rez(m);
    rez.data += m.data;
    return rez;
}

TMonom TMonom::operator-(const TMonom& m)
{
    if (key != m.key)
        throw Exception("Different Degrees of monoms");
    TMonom rez(m);
    rez.data -= data;
    return rez;
}

TMonom TMonom::operator*(const TMonom& m)
{
    if (((key / 100) + (m.key / 100) > 9)
        || (((key % 100) / 10) + ((m.key % 100) / 10) > 9)
        || (key % 10 + (m.key % 10) > 9))
        throw Exception ("Monom not exist");
    TMonom res(m);
    res.data = data * m.data;
    res.key = key + m.key;
    return res;

}

bool TMonom::operator<(const TMonom& m) const
{
    if (key < m.key) 
        return true;
    return false;
}

bool TMonom::operator>(const TMonom& m) const
{
    if (key > m.key)
        return true;
    return false;
}

bool TMonom::operator==(const TMonom& m) const
{
    if (key == m.key)
        return true;
    return false;
}





#endif
