#pragma once

#include "CList.h"
#include"Monom.h"
#include <algorithm>
#include <iostream>
#include <string>
#include<cmath>
#include<sstream>

class Polynom
{
private:
	CList<Monom> list;
	CList<Monom> Bringing_Sim(CList<Monom>& m);
public:
	Polynom(const Polynom& p);
	Polynom(const string s = "");

	Polynom operator+(const Polynom& p) const;
	Polynom operator*(const Polynom& p) const;
	Polynom operator*(const double k) const;
	Polynom operator-(const Polynom& p) const;
	Polynom operator-() const;
	double operator()(double x, double y, double z);
	const Polynom& operator=(const Polynom& p);
	friend Polynom operator*(const double k, const Polynom& p);
	bool operator==(const Polynom& p) const;
	bool operator!=(const Polynom& p) const;
	friend std::ostream& operator<<(std::ostream& out, const Polynom& pol);
	friend std::istream& operator>>(std::istream& in, Polynom& pol)
	{
		string s;
		cout << "¬ведите строку";
		cin >> s;
		pol.Parser(s);
		return in;
	}
	void Parser(string& s);

};
