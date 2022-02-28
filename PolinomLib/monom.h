// класс или структура Монома (double коэффициент, целая свернутая степень)
#pragma once
#include <iostream>

struct Monom
{
	int degx; //Показатели степени при x,y,z
	int degy;
	int degz;
	double coef; //коэффициент при мономе
	Monom* next;

	Monom(double _coef = 0.0, int _degx = 0, int _degy = 0, int _degz = 0, Monom* _next = nullptr);
	Monom(const Monom& monom2);
	Monom& operator=(const Monom& m)
	{
		
			degx = m.degx;
			degy = m.degy;
			degz = m.degz;
			coef = m.coef;
			next = m.next;
			return *this;
	}
	
	Monom& operator=(double scalar)
	{
		degx = 0;
		degy = 0;
		degz = 0;
		coef = scalar;
		next = nullptr;
		return *this;
	}
	bool operator==(const Monom& m) const;
	bool operator!=(const Monom& m) const;	
	friend std::ostream& operator<<(std::ostream& os, const Monom& m);

};
