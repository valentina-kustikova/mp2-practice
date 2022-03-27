#pragma once

#include <iostream>
#include "monom.h"
#include "list.h"

using namespace std;

class Polinom 
{
	string s;//исходная строка
	List<Monom> monoms;//список мономов
public:
	Polinom() {};//конструктор по умолчанию
	~Polinom() {};//деструктор
	Polinom(const string& str);//конструктор преобразования в полином из строки
	Polinom(const Polinom& p1);//конструктор копирования

	//перегрузка операторов
	Polinom operator+(const Polinom& p1);
	Polinom operator*(const Polinom& p1);
	Polinom operator*(const double d);
	Polinom operator-(const Polinom& p1);
	const Polinom& operator=(const Polinom& p1);

	friend std::ostream& operator<<(std::ostream& ostr, const Polinom& pm);
};
