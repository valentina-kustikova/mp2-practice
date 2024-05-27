#ifndef TMONOM_H
#define TMONOM_H

#include <iostream>
#include <string>

using namespace std;

class TMonom
{
protected:

	double coef;
	int degree;

public:

	TMonom();
	TMonom(const TMonom& m);
	TMonom(double _coef, int _degree);
	TMonom(double _coef, int DegreeX, int DegreeY, int DegreeZ);

	bool operator>(const TMonom& m) const;
	bool operator<(const TMonom& m) const;
	bool operator==(const TMonom& m) const;
	bool operator!=(const TMonom& m) const;
	TMonom& operator=(const TMonom& m);
	TMonom operator+(const TMonom& m)const;
	TMonom operator-(const TMonom& m)const;
	TMonom operator*(const TMonom& m) const;

	double GetValue(double x, double y, double z);
	double GetCoef() { return coef; };
	int GetDegree() { return degree; };
	int GetDegreeX() const;
	int GetDegreeY() const;
	int GetDegreeZ() const;

	TMonom dif_x();
	TMonom dif_y();
	TMonom dif_z();


	void SetCoef(double _coef) { coef = _coef; };
	void SetDegree(int _degree);
	void SetDegreeXYZ(int DegreeX, int DegreeY, int DegreeZ);
	string GetStr() const;

	bool TheSameCoefANDDegree(const TMonom& m);


	friend ostream& operator<<(ostream& out, const TMonom& monom)
	{
		out << monom.coef;
		if (monom.GetDegreeX() > 0)
		{
			out << "x";
			if (monom.GetDegreeX() > 1)
			{
				out << "^" << monom.GetDegreeX();
			}
		}

		if (monom.GetDegreeY() > 0)
		{
			out << "y";
			if (monom.GetDegreeY() > 1)
			{
				out << "^" << monom.GetDegreeY();
			}
		}

		if (monom.GetDegreeZ() > 0)
		{
			out << "z";
			if (monom.GetDegreeZ() > 1)
			{
				out << "^" << monom.GetDegreeZ();
			}
		}


		return out;
	}
};





#endif