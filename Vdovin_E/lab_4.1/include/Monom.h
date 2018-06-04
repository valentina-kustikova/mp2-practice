#pragma once

#include "Ringlist.h"

class monom
{
	double rank_number(const double a, const int i); //возведение числа a в степень i
	double converter_in_number(const string &s); //конвертация строки s в число
	monom converter_in_monom(const string &s); //конвертация строки s в моном
public:
	double coeff; //коэффициент монома
	unsigned int xyz; //степень монома
	monom(const double c = 0.0, const unsigned int w = 0); //конструктор от данных
	monom(const monom &m); //конструктор копирования
	monom(const string &s); //конструктор от строки
	~monom() {} //деструктор
	const monom& operator=(const monom &m); //оператор присваивания
	bool operator==(const monom &m) const; //оператор сравнения равно
	bool operator!=(const monom &m) const; //оператор сравнения не равно
	bool operator<(const monom &m) const; //оператор сравнения меньше
	bool operator>(const monom &m) const; //оператор сравнения больше
	monom operator*(const double d) const; //умножение монома на число
	monom operator*(const monom &m) const; //перемножение двух мономов
	friend ostream & operator<<(ostream &out, const monom &m); //оператор вывода
};