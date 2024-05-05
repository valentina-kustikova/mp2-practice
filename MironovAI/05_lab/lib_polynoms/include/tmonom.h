#ifndef _TMONOM_H_
#define _TMONOM_H_

#include <iostream>

using namespace std;

class TMonom
{
private:
	
	double coef;
	int degree_x;
	int degree_y;
	int degree_z;

public:
	TMonom(const TMonom& monom);
	TMonom(const double coef = 0.0, const int degreex = -1, const int degreey = -1, const int degreez = -1);

	bool operator<(const TMonom& monom) const;
	bool operator>(const TMonom& monom) const;
	bool operator==(const TMonom& monom) const;
	bool operator!=(const TMonom& monom) const;
	TMonom operator*(const TMonom& monom) const;
	bool greater(const TMonom& monom) const;
	bool equal(const TMonom& monom) const;

	double get_coef() const;
	void set_coef(double num);
	void inc_coef(double digit);
	string to_str();
	double eval(double x, double y, double z);
	TMonom dif_x() const;
	TMonom dif_y() const;
	TMonom dif_z() const;

	friend ostream& operator<<(ostream& buf, TMonom& monom)
	{
		buf << monom.coef;
		if (monom.degree_x > 0)
		{
			buf << "x";
			if (monom.degree_x != 1) buf << "^" << monom.degree_x;
		}
		if (monom.degree_y > 0)
		{
			buf << "y";
			if (monom.degree_y != 1) buf << "^" << monom.degree_y;
		}
		if (monom.degree_z > 0)
		{
			buf << "z";
			if (monom.degree_z != 1) buf << "^" << monom.degree_z;
		}
		return buf;
	}
};

#endif //