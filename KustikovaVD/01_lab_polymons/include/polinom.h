#pragma once

#include "headlist.h"
#include "monom.h"
#include <string>

class TPolinom
{
private:
    THeadList* monoms;

    // ��������� ������
    // ...
public:
    TPolinom();
    TPolinom(const std::string& str);
    TPolinom(THeadList* const monoms);
    TPolinom(const TPolinom& polinom);
    ~TPolinom();

    // ��������
    TPolinom operator+(const TPolinom& a);
    TPolinom operator-(const TPolinom& a);
    TPolinom operator*(const TPolinom& a);
    
    TPolinom operator-();
    
    TPolinom operator+(const double c);
    TPolinom operator-(const double c);
    TPolinom operator*(const double c);    

    TPolinom& operator=(const TPolinom& a);
    
    double operator()(double x, double y, double z) const;

    // ����/�����
    friend std::ostream& operator<<(std::ostream &out, 
        const TPolinom& polinom);
    friend std::istream& operator>>(std::istream &in, 
        TPolinom& polinom);
};
