#ifndef _TPOLYNOM_
#define _TPOLYNOM_
#include <iostream>
#include "tringlist.h"
#include "tmonom.h"

using namespace std;

class TPolynom
{
private:
	TRingList<TMonom> monoms; // std::string name;
	void update();
public:
	TPolynom();
	TPolynom(const string& name);
	TPolynom(const TRingList<TMonom> monoms);
	TPolynom(const TPolynom& p);
	TPolynom operator+(const TPolynom& polynom);
	TPolynom operator-(const TPolynom& polynom);
	TPolynom operator*(const TPolynom& polynom);
	TPolynom operator*(const double c);
	const TPolynom& operator=(const TPolynom& polynom);
	TPolynom dif()const;
	TPolynom dif_x()const;
	TPolynom dif_y()const;
	TPolynom dif_z()const;
	double operator()(double x, double y, double z)const;
	friend ostream& operator<< (ostream& out, const TPolynom& polynom)
	{
		TPolynom tmppolynom(polynom);
		TMonom tmpmonom = tmppolynom.monoms.get_pCurr();
		int flag = 0;
		while (!tmppolynom.monoms.IsEnd())
		{
			out << tmpmonom;
			tmpmonom = tmppolynom.monoms.get_pCurr();/*
			if (tmpmonom.GetDegree() == 0)
				return out << tmpmonom.GetCoeff();
			if (tmpmonom.GetCoeff() > 0 && flag != 0)
				out << "+";
			out << tmpmonom.GetCoeff();
			if (tmpmonom.GetDegree() / 100 > 0)
			{
				out << "*x^" << tmpmonom.GetDegree() / 100;
			}
			if ((tmpmonom.GetDegree() % 100) / 10 > 0)
			{
				out << "*y^" << (tmpmonom.GetDegree() % 100) / 10;
			}
			if (tmpmonom.GetDegree() % 10 > 0)
			{
				out << "*z^" << tmpmonom.GetDegree() % 10;
			}
			flag++;*/
			tmppolynom.monoms.Next();
		}
		out << endl;
		return out;
	}
	friend istream& operator>> (istream& in, TPolynom& polynom)
	{
		string s;
		in >> s;
		polynom = TPolynom(s);
		return in;
	}
};

#endif