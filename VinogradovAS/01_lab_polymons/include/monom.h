#pragma once
#include <iostream>
#include <cmath>

struct TMonom
{
	double coeff;

	int x;
	int y;
	int z;
	TMonom();
	TMonom(double _coeff, int _x, int _y, int _z);
	TMonom(int _x, int _y, int _z);

	
	bool operator==(const TMonom& other) const;
	bool operator!=(const TMonom& other) const;
	bool operator<(const TMonom& other) const;
	bool operator>(const TMonom& other) const;

	
	bool IsConst() const;

	TMonom operator*(const TMonom& other);

	//Выводит текущий моном без коэффициента и знака
	friend std::ostream& operator<<(std::ostream& os, TMonom& monom)
	{
		if (monom.x != 0)
		{
			os << "x";
			if (monom.x != 1)
				os << monom.x;
		}
		if (monom.y != 0)
		{
			os << "y";
			if (monom.y != 1)
				os << monom.y;
		}
		if (monom.z != 0)
		{
			os << "z";
			if (monom.z != 1)
				os << monom.z;
		}
		return os;
	}
};


















//#pragma once
//
//#include "data.h"
//
//class TMonom: public TData
//{
//public:
//    double coeff;
//    int degree;
//public:
//    TMonom(double coeff, int degree);
//    
//    TMonom& operator=(const TMonom& monom);
//    
//    int operator==(const TMonom& monom) const;
//    int operator!=(const TMonom& monom) const;
//    int operator<(const TMonom& monom) const;
//    int operator>(const TMonom& monom) const;
//    
//    virtual TData* Copy(); // создание копии
//};
