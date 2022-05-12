#pragma once

#include "list.h"
#include "headlist.h"
#include"monom.h"
#include <algorithm>
#include <iostream>
#include <string>

class Polynom
{
private:
	List<Monom> list;//список мономов
	List<Monom> similar(List<Monom>& m);//приведение подобных
public:

	Polynom(const Polynom& p); //конструктор копирования
	Polynom(const string s = "");//конструктор преобразования строки в полином

	Polynom operator+(const Polynom& p) const; //сложение полиномов
	Polynom operator*(const Polynom& p) const; //умножение полиномов
	Polynom operator*(const double k) const; //умножение полинома на константу
	Polynom operator-(const Polynom& p) const;// вычитание полиномов
	Polynom operator-() const;//унарный минус
	friend Polynom operator*(const double k, const Polynom& p); //умножение полинома на константу с другой стороны

	const Polynom& operator=(const Polynom& p);//присваивание
	bool operator==(const Polynom& p) const;//==
	bool operator!=(const Polynom& p) const;//!=
	double operator() (double x, double y, double z);//()

	friend ostream& operator<<(ostream& out, const Polynom& pol);//вывод
	friend istream& operator>>(istream& in, Polynom& p);//ввод
};