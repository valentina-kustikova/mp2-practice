#pragma once

#include "Ringlist.h"
#include "Monom.h"

class polinom
{
   ringlist<monom> pol; //зацикленный список из мономов
   polinom converter_in_polinom(const string &s); //конвертация из стороки s в полином
public:
   polinom() {} //конструктор по умолчанию
   polinom(const polinom &p); //конструктор копирования
   polinom(const string &s); //конструктор от строки
   ~polinom() {} //деструктор
   const polinom& operator=(const polinom &p); //оператор присваивания
   polinom operator+(const polinom &p) const; //сложение полиномов
   polinom operator*(const polinom &p) const; //перемножение полиномов
   polinom operator-(const polinom &p) const; //вичитани полиномов
   polinom operator*(const double d) const; //умножение полинома на число справо
   friend polinom operator*(const double d, const polinom &p); //умножение полинома на число слева
   bool operator==(const polinom &p) const; //оператор сравнения равно
   bool operator!=(const polinom &p) const; //оператор сравнения не равно
   friend ostream & operator<<(ostream &out, const polinom &p); //оператор вывода
};