#pragma once

#include "list.h"
#include"monom.h"
#include <algorithm>
#include <iostream>
#include <string>

class Polinom
{
private:
	List<Monom> list;//список мономов
	List<Monom> similar(List<Monom>& m);//приведение подобных
public:

	Polinom(const Polinom& p); //конструктор копирования
	Polinom(const string s = "");//конструктор преобразования строки в полином

	Polinom operator+(const Polinom& p) const; //сложение полиномов
	Polinom operator*(const Polinom& p) const; //умножение полиномов
	Polinom operator*(const double k) const; //умножение полинома на константу
	Polinom operator-(const Polinom& p) const;// вычитание полиномов
	Polinom operator-() const;//унарный минус
	friend Polinom operator*(const double k, const Polinom& p); //умножение полинома на константу с другой стороны

	const Polinom& operator=(const Polinom& p);//присваивание
	bool operator==(const Polinom& p) const;//==
	bool operator!=(const Polinom& p) const;//!=
	double operator() (double x, double y, double z);//()

	friend ostream& operator<<(ostream& out, const Polinom& pol);//вывод
	friend istream& operator>>(istream& in, Polinom& p);//ввод
};
