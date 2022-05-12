#pragma once

#include "list.h"
#include "headlist.h"
#include "monom.h"
#include <string>

class TPolinom
{
private:
    THeadList monoms;

    // служебные методы
    //void TPolinom::SortMonoms();// упорядочивание
    void TPolinom::Bringing();// ПРИВЕДЕНИЕ ПОДОБНЫХ
public:
    TPolinom();
    TPolinom(const std::string &str);
    TPolinom(THeadList* const monoms);
    TPolinom(const TPolinom& polinom);

    // операции
    TPolinom operator+(const TPolinom& a) const;
    TPolinom operator-(const TPolinom& a);
    TPolinom operator*(const TPolinom& a) const;
    
    TPolinom operator-();
    
    TPolinom operator+(const double c);
    TPolinom operator-(const double c);
    TPolinom operator*(const double c); 

    bool TPolinom::operator==(const TPolinom& a) const; // Для тестов

    TPolinom& operator=(const TPolinom& a);
    
    double operator()(double x, double y, double z) const; 

    // ввод/вывод
    friend std::ostream& operator<<(std::ostream &out, 
         TPolinom& polinom);
    friend std::istream& operator>>(std::istream &in, 
        TPolinom& polinom);
};
