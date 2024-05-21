#ifndef TMONOM_H
#define TMONOM_H

#include <iostream>
#include <string>

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
	
	int get_degX() const;
	int get_degY() const;
	int get_degZ() const;
	
	void set_coeff(double _coeff);
	void set_degree(int _degree);
	void set_degree(int degX, int degY, int degZ);

	double operator()(double x, double y, double z) const;

	
	virtual bool operator<(const TMonom& monom) const;
	virtual bool operator>(const TMonom& monom) const;
	virtual bool operator<=(const TMonom& monom) const;
	virtual bool operator>=(const TMonom& monom) const;
	virtual bool operator==(const TMonom& monom) const;
	virtual bool operator!=(const TMonom& monom) const;

	const TMonom& operator=(const TMonom& data);
	TMonom operator*(const TMonom& monom) const;

	TMonom dif_x() const;
	TMonom dif_y() const;
	TMonom dif_z() const;

	std::string get_string() const;
	friend std::ostream& operator<<(std::ostream& out, const TMonom& monom);
};

#endif // !TMONOM_H
