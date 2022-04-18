#pragma once

using namespace std;

class Monom
{
public:
	double coeff;//коэффициент перед мономом
	int degree;//свернутая степень

	Monom(const double c = 0.0, const int d = 0); //конструктор с параметрами
	Monom(const Monom& m);//конструктор копирования

	Monom& operator+(const Monom& m); //+
	Monom& operator*(const double& d); //*const
	Monom& operator*(const Monom& m); //*
	bool operator<(const Monom& m)const; //<
	bool operator>(const Monom& m)const;  //>
	const Monom& operator=(const Monom& m); //присваивание
	bool operator==(const Monom& m)const;//==
	bool operator!=(const Monom& m)const;//!=
};
