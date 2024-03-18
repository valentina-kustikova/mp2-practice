#ifndef TMONOM_H
#define TMONOM_H

#include <iostream>

using namespace std;

class TMonom{
private:
	double coeff;
	int degree;
public:
	TMonom();
	TMonom(const TMonom& monom);
	TMonom(double _coeff, int _degree);
	TMonom(double _coeff, int degX, int degY, int degZ);

	double get_coeff() const;
	int get_degree() const;
	void set_coeff(double _coeff);
	void set_degree(int _degree);
	void set_degree(int degX, int degY, int degZ);

	double value(int x, int y, int z);

	
	virtual bool operator<(const TMonom& monom) const;
	virtual bool operator>(const TMonom& monom) const;
	virtual bool operator<=(const TMonom& monom) const;
	virtual bool operator>=(const TMonom& monom) const;
	virtual bool operator==(const TMonom& monom) const;
	virtual bool operator!=(const TMonom& monom) const;

	const TMonom& operator=(const TMonom& data) const; // опнбепхрэ CONST
	TMonom operator*(const TMonom& monom) const;

	TMonom dif_x() const;
	TMonom dif_y() const;
	TMonom dif_z() const;
};

#endif // !TMONOM_H
