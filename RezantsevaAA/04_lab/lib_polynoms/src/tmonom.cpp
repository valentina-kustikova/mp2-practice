#include "tmonom.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
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

bool TMonom::operator!=(const TMonom& m) const { 
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

TMonom TMonom::operator*(const TMonom& m)const {
	if ((Degree + m.Degree) <= 999 && (Degree + m.Degree) >= 0) {
		return TMonom(Coeff * m.Coeff, Degree + m.Degree);
	}
	else {
		throw "Degree limit!";
	}
}

TMonom TMonom::operator+(const TMonom& m)const {
	TMonom result;
	if ((*this) == m) {
		result.SetCoeff((*this).Coeff + m.Coeff);
		result.Degree = m.Degree;
	}
	else {
		throw "Error. Can't sum monoms";
	}
	return result;
}
TMonom TMonom::monom_defX() {
	if (Degree - 100 == 0)
	{
		return TMonom(Coeff, 0);
	}
	Coeff = Coeff * (Degree / 100);
	Degree = Degree - 100;
	return TMonom(Coeff, Degree);
}
TMonom TMonom::monom_defY() {
	int y = (Degree % 100) / 10;
	if (y == 0) {
		return TMonom(0, 0);
	}
	if (y == 1) 
	{
		return TMonom(Coeff, Degree - 10);
	}
	Coeff = Coeff * y;
	Degree = Degree - 10;
	return TMonom(Coeff, Degree);
}

TMonom TMonom::monom_defZ() {
	int z = Degree % 10;
	if (z == 1)
	{
		return TMonom(Coeff, Degree - 1);
	}
	if (z == 0)
	{
		return TMonom(0, 0);
	}
	Coeff = Coeff * z;
	Degree = Degree - 1;
	return TMonom(Coeff, Degree);
}

void TMonom::ChangeCoeff() {
	Coeff = -Coeff;
}

std::ostream& operator<<(std::ostream& out, TMonom& m) {
	int x, y, z;

	x = m.Degree / 100;
	y = (m.Degree % 100) / 10;
	z = m.Degree % 10;
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

std::string TMonom::getStringMonom() const {
	//форматирование цифр после запятой коэффициента	
	std::ostringstream oss;
	oss << std::fixed << std::setprecision(1) << Coeff; //выводит без запятой либо сделать 1-2 знака после запятой и + "*"
	std::string stringMonom;
	if (Coeff >= 0) {
		if (Coeff == 1.0) {
			stringMonom += "+";
		}
		else {
			stringMonom = "+" + oss.str();
		}
	}
	else {
		if (Coeff == -1.0) {
			stringMonom += "-";
		}
		else {
			stringMonom = oss.str();
		}
	}

	if (Degree > 0 && Coeff != 1.0 && Coeff != -1.0) {
		stringMonom += "*";
	}

	int x, y, z;
	x = Degree / 100;
	y = (Degree % 100) / 10;
	z = Degree % 10;
	if (x > 1)
		stringMonom += "x^" + std::to_string(x);
	else if (x == 1) {
		stringMonom += "x";
	}
	if (y > 1 )
		stringMonom += "y^" + std::to_string(y);
	else if (y == 1) {
		stringMonom += "y";
	}
	if (z > 1)
		stringMonom += "z^" + std::to_string(z);
	else if (z == 1) {
		stringMonom += "z";
	}
	return stringMonom;
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