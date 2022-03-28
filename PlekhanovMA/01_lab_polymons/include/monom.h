#pragma once
#include <iostream>

struct TData
{
    double coeff; // ���������� ����� �������
    int degree;   // ������� �������
    int degx, degy, degz;// ������� x, y, z
    int operator==(const TData data) const
    {
        return (degree == data.degree) && (coeff == data.coeff);
    }
    int operator!=(const TData data) const
    {
        return (degree != data.degree) || (coeff != data.coeff);
    }
};

class TMonom
{
public:
    TData data;// ������
    TMonom* pNext;// ��������� �� ��������� ������� ������

public:
    TMonom();
    TMonom(int Degx, int Degy, int Degz, double Coeff, TMonom* PNext);
    TMonom(int Degx, int Degy, int Degz, double Coeff);
    TMonom(TData Data);
    TMonom(const TMonom& monom);
    ~TMonom();

    TMonom& operator=(const TMonom& monom);
    
    int operator==(const TMonom& monom) const;
    int operator!=(const TMonom& monom) const;
    int operator<(const TMonom& monom) const;
    int operator>(const TMonom& monom) const;
};
