#include "tmonom.h"

TMonom::TMonom()
{
	degree = -1;
	coeff = 0;
}

TMonom::TMonom(double coeff, int degree)
{
	this->coeff = coeff;
	this->degree = degree;
}

TMonom::TMonom(const TMonom& monom)
{
	coeff = monom.coeff;
	degree = monom.degree;
}

TMonom::TMonom(const string& monom)
{
	string str = monom;
	string strcoeff = "";
	degree = 0;
	coeff = 1;
	int tmpdegree = 0;
	int i = 0;
	while (isdigit(str[i]))
	{
		strcoeff += str[i];
		i++;
	}
	while (i < str.length())
	{
		if (str[i] == 'x')
		{
			if (i == str.length() - 1)
			{
				tmpdegree += 100;
				break;
			}
			if (str[i + 1] == '*')
			{
				tmpdegree += 100;
				i++;
				continue;
			}
			if (str[i + 1] == '^')
			{
				i++;
				continue;
			}
			i++;
			continue;
		}
		if (str[i] == 'y')
		{
			if (i == str.length() - 1)
			{
				tmpdegree += 10;
				break;
			}
			if (str[i + 1] == '*')
			{
				tmpdegree += 10;
				i++;
				continue;
			}
			if (str[i + 1] == '^')
			{
				i++;
				continue;
			}
			i++;
			continue;
		}
		if (str[i] == 'z')
		{
			if (i == str.length() - 1)
			{
				tmpdegree += 1;
				break;
			}
			if (str[i + 1] == '*')
			{
				tmpdegree += 1;
				i++;
				continue;
			}
			if (str[i + 1] == '^')
			{
				i++;
				continue;
			}
			i++;
			continue;
		}
		else if (str[i] == '^')
		{
			i++;
			continue;
		}
		else if (str[i] == '*')
		{
			i++;
			continue;
		}
		else if (isdigit(str[i]))
		{
			if (str[i - 2] == 'x' && str[i - 1] == '^')
				tmpdegree += (str[i] -48) * 100;
			if (str[i - 2] == 'y' && str[i - 1] == '^')
				tmpdegree += (str[i]-48) * 10;
			if (str[i - 2] == 'z' && str[i - 1] == '^')
				tmpdegree += (str[i]-48);
			i++;
		}
		else 
			throw std::exception("invalid string");
	}
	if (strcoeff.length() != 0)
		coeff = stod(strcoeff);
	else
		coeff = 1;
	if (tmpdegree > 999)
		throw std::exception("invalid string");
	degree = tmpdegree;
}


bool TMonom::operator==(const TMonom& data)const
{
	if (degree == data.degree && coeff == data.coeff)
		return true;
	return false;
}

bool TMonom::operator!=(const TMonom& data)const
{
	return !(*this == data);
}


bool TMonom::operator<(const TMonom& data) const
{
	if (degree < data.degree)
		return true;
	if (degree == data.degree)
		if (coeff < data.coeff)
			return true;
	return false;
}

bool TMonom::operator>(const TMonom& data) const
{
	if (degree > data.degree)
		return true;
	if (degree == data.degree)
		if (coeff > data.coeff)
			return true;
	return false;
}

TMonom TMonom::operator+(const TMonom& data)
{
	if (degree != data.degree)
		throw std::exception("Invalid monoms(op+)");
	return TMonom(coeff + data.coeff, degree);
}

TMonom TMonom::operator-(const TMonom& data)
{
	if (degree != data.degree)
		throw std::exception("Invalid monoms(op-)");
	return TMonom(coeff - data.coeff, degree);
}

TMonom TMonom::operator*(const TMonom& data)
{
	if (degree != data.degree)
		throw std::exception("Invalid monoms(op*)");
	return TMonom(coeff * data.coeff, degree);
}


TMonom TMonom::def_X()
{
	if ((int)(degree/100) == 0)
		return TMonom(0, 0);
	return TMonom(coeff * (degree / 100), degree - 100);
}

TMonom TMonom::def_Y()
{
	if ((int)(degree % 100) / 10 == 0)
		return TMonom(0,0);
	return TMonom(coeff * ((degree % 100) / 10), degree - 10);
}

TMonom TMonom::def_Z()
{
	if((int)(degree%10) == 0)
		return TMonom(0, 0);
	return TMonom(coeff * (degree % 10), degree - 1);
}

double TMonom::calculate(double x, double y, double z)
{
	double res = coeff;
	if (degree / 100 != 0)
		for (int i = 0; i < degree / 100; i++)
			res *= x;
	if ((degree % 100) / 10 != 0)
		for (int i = 0; i < (degree % 100) / 10; i++)
			res *= y;
	if (degree % 10 != 0)
		for (int i = 0; i < degree % 10; i++)
			res *= z;
	return res;
}

const TMonom& TMonom::operator=(const TMonom& monom)
{
	if (*this == monom)
		return *this;
	coeff = monom.coeff;
	degree = monom.degree;
	return *this;
}

std::istream& operator>>(std::istream in, TMonom& monom)
{
	int x, y, z;
	std::cout << "coeff = ";
	std::cin >> monom.coeff;
	std::cout << std::endl;
	if (monom.coeff == 0)
		return in;
A:	std::cout << "x = ";
	std::cin >> x;
	std::cout << std::endl;
	if (x > 9)
		goto A;
B:	std::cout << "y = ";
	std::cin >> y;
	std::cout << std::endl;
	if (y > 9)
		goto B;
C:	std::cout << "z = ";
	std::cin >> z;
	std::cout << std::endl;
	if (z > 9)
		goto C;
	monom.degree = x * 100 + y * 10 + z;
	return in;
}

std::ostream& operator<<(std::ostream out, TMonom& monom)
{
	int x, y, z;
	x = monom.degree / 100;
	y = (monom.degree % 100) / 10;
	z = monom.degree % 10;
	if (monom.coeff == 0)
		return out << "0";
	if (monom.coeff > 0)
		out << "+";
	out << monom.coeff;
	if (x == 1)
		out << "*x";
	else  if (x > 0)
		out << "*x^" << x;
	if (y == 1)
		out << "*y";
	else  if (y > 0)
		out << "*y^" << y;
	if (z == 1)
		out << "*z";
	else  if (z > 0)
		out << "*z^" << z;
	return out;

}


void TMonom::SetCoeff(const double cf)
{
	coeff = cf;
}
void TMonom::SetDegree(const int dgr)
{
	degree = dgr;
}