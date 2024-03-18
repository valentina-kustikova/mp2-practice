#include "tmonom.h"

TMonom::TMonom(const TMonom& m) {
	Coeff = m.Coeff;
	Degree = m.Degree;
}

TMonom::TMonom( double c, int d) {
	if ((d > 999) || (d < 0))
		throw "Wrong degree";
	Coeff = c;
	Degree = d;
}
TMonom& TMonom::operator=(const TMonom& m) {
	Coeff = m.Coeff;
	Degree = m.Degree;
	return *this;
}

bool TMonom::operator<(const TMonom& m) const {
	if (Degree < m.Degree)
		return true;
	if (Degree == m.Degree)
	{
		if (Coeff < m.Coeff) 
			return true;
		else 
			return false;
	}
	else
		return false;
}

bool TMonom::operator>(const TMonom& m) const {
	if (Degree > m.Degree)
		return true;
	if (Degree == m.Degree)
	{
		if (Coeff > m.Coeff) 
			return true;
		else 
			return false;
	}
	else
		return false;
}

bool TMonom::operator==(const TMonom& m) const {
	return (Coeff == m.Coeff) && (Degree == m.Degree);
}

bool TMonom::operator!=(const TMonom& m) const { //
	return !(*this == m);
}

void TMonom::SetCoeff(double cm) {
	Coeff = cm;
}
void TMonom::SetDegree(int d){
	if ((d > 999) || (d < 0))
		throw "Wrong degree";
	Degree = d;
}

double TMonom::GetCoeff() {
	return Coeff;
}
int TMonom::GetDegree() {
	return Degree;
}

TMonom TMonom:: operator*(const TMonom& m)const {
	if ((Degree + m.Degree) <= 999 && (Degree + m.Degree) >= 0) {
		return TMonom(Coeff * m.Coeff, Degree + m.Degree);
	}
	else {
		throw "Degree limit!";
	}
}
std::ostream& operator<<(std::ostream& out, TMonom& m) {
	int x, y, z;
	x = m.Degree / 100;
	y = (m.Degree - x * 100) / 10;
	z = m.Degree - x * 100 - y * 10;
	if (m.Coeff != 1 || m.Degree == 0)
		out << m.Coeff;
	if (x > 0)
		out << "x^" << x;
	if (y > 0)
		out << "y^" << y;
	if (z > 0)
		out << "z^" << z;
	return out;
}
std::istream& operator>>(std::istream& istr, TMonom& m) {
	int x, y, z;
	std::cout << "Enter coeff\n";
	istr >> m.Coeff;
	std::cout << "Enter degries x, y, z \n";
	istr >> x >> y >> z;
	m.Degree = x * 100 + y * 10 + z;
	return istr;
}
double TMonom::Pow(double a, double degree) {
	double result = 1.0;

	for (int i = 0; i < degree; i++)
	{
		result *= a;
	}
	return result;

}

double TMonom::calculateMonom(std::map<char, double>& variables) {
	double result =  Coeff;
	int st = 100;
	if (Degree / 100 != 0)
	{
		result *= Pow(variables['x'], Degree / 100);
	}
	if ((Degree % 100) / 10 != 0)
	{
		result *= Pow(variables['y'], (Degree % 100) / 10);
	}
	if (Degree % 10 != 0) {
		result *= Pow(variables['z'], Degree % 10);
	}
	return result;
}