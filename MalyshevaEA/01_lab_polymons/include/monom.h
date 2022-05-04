#include <iostream>
//using namespace std;
#pragma once



struct monom
{
    int stx, sty, stz;
    double cf;
    monom();
    monom(double cf1, int stx1, int sty1, int stz1);
    bool operator==(const monom& m) const;
    bool operator!=(const monom& m) const;
    const monom& operator=(const monom& m); 
    monom operator*(const monom& m);
    monom operator*(const double a);
    monom operator+(const monom& m);
    bool operator<(const monom& m)
    {
    if (stx < m.stx) {return true;}
    else if (stx == m.stx)
    {
        if (sty < m.sty) {return true;}
        else if (sty == m.sty) 
        {
            if (stz < m.stz) {return true;}
        }
    }
    else {return false;}
    }
    bool operator>(const monom& m);

    friend std::ostream& operator<<(std::ostream& os, monom& m)
    {
        if (abs(m.cf) < 0.0000001) {return os;}
        if (((abs(m.cf - 1) < 0.0000001) || (abs(m.cf + 1) < 0.0000001)) && (m.stx == 0) &&  (m.sty == 0) && (m.stz == 0))
        {
            os << m.cf;
            return os;
        }
        if (abs(m.cf + 1) < 0.0000001) {os << "-";}
        else if ((abs(m.cf - 1) > 0.0000001) || ((m.stx == 0) && (m.sty == 0) && (m.stz == 0)))
        {os << m.cf;}
        if (m.stx != 0)
        {
            os << "x";
            if (m.stx != 1)
            {
                os << "^";
                os << m.stx;
            }
        }
        if (m.sty != 0)
        {
            os << "y";
            if (m.sty != 1)
            {
                os << "^";
                os << m.sty;
            }
        }
        if (m.stz != 0)
        {
            os << "z";
            if (m.stz != 1)
            {
                os << "^";
                os << m.stz;
            }
        }
        return os;
    }
}; 