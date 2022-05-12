#include "monom.h"
#include "list.h"
#include <iostream>
#include <cstdio>
#include <string>
#include <math.h>


using namespace std;
#pragma once

class polinom
{
public:
    headlist<monom> mon;
    void vod(const string& s);
    polinom();
    ~polinom(){};
    polinom(const string& s);
    polinom(const polinom& p);
    void privpodob();
    void ochered();
    bool operator==(const polinom& other) const;
    polinom operator+(const polinom& p) const; 
    polinom operator-(const polinom& p) const;
    polinom operator*(const polinom& p) const;
    polinom operator*(const monom& m) const;
	polinom operator*(const double a) const;
    double operator() (double x, double y, double z) const; 

    friend std::ostream& operator<<(std::ostream& os, polinom& p)
    {
        if (p.mon.size == 0)
        {
            os << "0";
            return os;
        }
        for (int i = 0; i < p.mon.getsize(); i++)
        { 
            if ((p.mon[i].cf > 0) && (i != 0)) 
            {os << "+";}
            os << p.mon[i];
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, polinom& p)
	{
		string str;
		is >> str;
		p.vod(str);
		return is;
	}
};