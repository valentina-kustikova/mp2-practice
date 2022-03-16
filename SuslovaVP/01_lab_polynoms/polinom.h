#pragma once

#include "list.h"
#include"monom.h"
#include <algorithm>
#include <iostream>
#include <string>

class Polinom
{
private:
	List<Monom> list;
	List<Monom> Bringing_Sim(List<Monom>& m);
public:
	Polinom(const Polinom& p);
	Polinom(const string s = "");
	Polinom operator+(const Polinom& p) const;
	Polinom operator*(const Polinom& p) const;
	Polinom operator*(const double k) const;
	Polinom operator-(const Polinom& p) const;
	Polinom operator-() const;
	const Polinom& operator=(const Polinom& p);
	friend Polinom operator*(const double k, const Polinom& p);
	bool operator==(const Polinom& p) const;
	bool operator!=(const Polinom& p) const;
	friend std::ostream& operator<<(std::ostream& out, const Polinom& pol);
};