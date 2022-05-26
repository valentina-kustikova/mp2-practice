#pragma once
#include <iostream>
#include "monom.h"
#include "headlist.h"
#include <string>
#include <vector>

class TPolinom
{
private:
    THeadList polinom;
    std::vector<std::string> strpolinom;

private:
    void Sort(); // ����������� �������
    void Similar(); // �������� ��������

public:
    TPolinom();
    TPolinom(const std::string &str);
    TPolinom(const TPolinom &a);
    ~TPolinom();


    // �������� � ����������
    TPolinom operator+(const TPolinom& a);
    TPolinom operator-(const TPolinom& a);
    TPolinom operator-();
    TPolinom operator*(const TPolinom& a);
    TPolinom operator*(const double c);
    TPolinom operator/(const double c);
    TPolinom& operator=(const TPolinom& a);
    int operator==(const TPolinom& a) const;
    const double operator()(double x, double y, double z);

    bool Check();
    void ClearPol(); // �������� �������

    // ����/�����
    friend std::ostream& operator<<(std::ostream& out,
        const TPolinom& polinom);
    
};
