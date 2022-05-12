#include "monom.h" 

monom::monom()
{
    cf = 0.0;
    stx = 0;
    sty = 0;
    stz = 0;
}

monom::monom(double cf1, int stx1, int sty1, int stz1)
{
    cf = cf1;
    stx = stx1;
    sty = sty1;
    stz = stz1;
}

bool monom::operator==(const monom& m) const 
{
    return ((stx == m.stx) && (sty == m.sty) && (stz == m.stz));
}

bool monom::operator!=(const monom& m) const
{
    return ((stx != m.stx) || (sty != m.sty) || (stz != m.stz));
}

const monom& monom::operator=(const monom& m)
{
    cf = m.cf;
    stx = m.stx;
    sty = m.sty;
    stz = m.stz;
    return *this;
}

monom monom::operator*(const monom& m)
{
    monom m1;
    m1.cf = cf * m.cf;
    m1.stx = stx + m.stx;
    m1.sty = sty + m.sty;
    m1.stz = stz + m.stz;
    return m1;
}

monom monom::operator*(const double a)
{
    monom m1;
    m1.cf = cf * a;
    m1.stx = stx;
    m1.sty = sty;
    m1.stz = stz;
    return m1;
}

monom monom::operator+(const monom& m)
{
    if ((stx == m.stx) && (sty == m.sty) && (stz == m.stz)){
    monom m1;
    m1.cf = cf + m.cf;
    m1.stx = m.stx;
    m1.sty = m.sty;
    m1.stz = m.stz;
    return m1;}
}

bool monom::operator>(const monom& m)
{
    return (!operator<(m)) && (!operator==(m));
}