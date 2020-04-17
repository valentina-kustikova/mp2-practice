#pragma once
#include "List.h"
#include "Monom.h"
class Polinom
{
private:
	TList<unsigned int, double, Monom>* poli;
public:
	Polinom();
	Polinom(const Polinom&);
	Polinom(const string&);
	~Polinom();
	Polinom operator+(const Monom&);
	Polinom operator-(const Monom&);
	Polinom operator*(const Monom&);
	Polinom& operator+=(const Monom&);
	//Polinom& operator-=(const Monom&);
	//Polinom& operator*=(const Monom&);
	Polinom operator+(const Polinom&);
	Polinom operator-(const Polinom&);
	Polinom operator*(const Polinom&);
	//Polinom& operator+=(const Polinom&);
	//Polinom& operator-=(const Polinom&);
	//Polinom& operator*=(const Polinom&);
	Polinom operator-() const;
	Polinom& operator=(const Polinom&);
	bool operator==(const Polinom&) const;
	friend ostream& operator <<(ostream&, const Polinom&);
	friend istream& operator >>(istream&, Polinom&);
};