#include <iostream>
#include "polinom.h"
#include <string>
#include <cmath>

using namespace std;

TPolinom::TPolinom()
{
	TMonom temp(0.0, -1);
	monoms.InsertToHead(temp.Copy());
}

TPolinom::TPolinom(const std::string& str)
{
	if (str.length() == 0) return;
	char lastsmb = '+';
	TMonom temp(0, -1);

	monoms.InsertToHead(temp.Copy());

	TMonom tmp(0, 0);

	bool wascoeff = false;

	for (int i = 0, firsti = i; i < str.size(); i++)
	{
			if (!wascoeff)
			{
				double digit = 0;
				if (str[i] == '-')
				{
					i++;
					lastsmb = '-';
				}
				if (str[i] == '+')
				{
					i++;
					lastsmb = '+';
				}
				if (isdigit(str[i]))
				{
					firsti = i;
					while (isdigit(str[i]))
					{
						i++;
					}
				}
				if (firsti != i)
					digit = stod(str.substr(firsti, i));
				else
					digit = 1.0;
				tmp.coeff = digit;
				wascoeff = true;
			}
			if (str[i] == 'x' || str[i] == 'X')
			{

				if (i + 1 == str.size())
				{
					tmp.degree += 100;
				}
				else if (isdigit(str[i + 1]))
				{
					int digit1 = stod(&str[i + 1]);
					tmp.degree += digit1 * 100;
				}
				else
				{
					tmp.degree += 100;
				}
			}
			else if (str[i] == 'y' || str[i] == 'Y')
			{
				if (i + 1 == str.size())
				{
					tmp.degree += 10;
				}
				else if (isdigit(str[i + 1]))
				{
					int digit1 = stod(&str[i + 1]);
					tmp.degree += digit1 * 10;
				}
				else
				{
					tmp.degree += 10;
				}
			}
			else if (str[i] == 'z' || str[i] == 'Z')
			{
				if (i + 1 == str.size())
				{
					tmp.degree += 1;
				}
				else if (isdigit(str[i + 1]))
				{
					int digit1 = stod(&str[i + 1]);
					tmp.degree += digit1 * 1;
				}
				else
				{
					tmp.degree += 1;
				}
			}
			else if (str[i] == '+' || str[i] == '-')
			{
				if (lastsmb == '-') tmp.coeff *= (-1);
				if (!monoms.IsEmpty()) {
					while (!monoms.NextIsEnded() && tmp < *(monoms.GetCur()->data))
					{
						monoms.Next();
					}
					if (monoms.NextIsEnded() && tmp < *(monoms.GetCur()->data))
					{
						monoms.InsertToTail(tmp.Copy());
						monoms.Reset();
					}
					else
					{
						monoms.InsertBefore(tmp.Copy(), monoms.GetCur()->data);
						monoms.Reset();
					}
				}
				else
					monoms.InsertToTail(tmp.Copy());
				tmp.coeff = 1;
				tmp.degree = 0;
				lastsmb = str[i];
				wascoeff = false;
				firsti = i + 1;
			}
		
	}
	if (lastsmb == '-') tmp.coeff *= (-1);
	if (!monoms.IsEmpty()) {
		while (!monoms.NextIsEnded() && tmp < *(monoms.GetCur()->data))
		{
			monoms.Next();
		}
		if (monoms.NextIsEnded() && tmp < *(monoms.GetCur()->data))
		{
			monoms.InsertToTail(tmp.Copy());
			monoms.Reset();
		}
		else
		{
			monoms.InsertBefore(tmp.Copy(), monoms.GetCur()->data);
			monoms.Reset();
		}
	}
	else
		monoms.InsertToTail(tmp.Copy());
	this->Bringing();
}

TPolinom::TPolinom(THeadList* const monoms)
{
	THeadList tmp(*monoms);
	this->monoms = tmp;
	this->Bringing();
}

TPolinom::TPolinom(const TPolinom& polinom)
{
	TMonom m(0, -1);
	monoms.InsertToHead(m.Copy());
	for (TNode* tmp = polinom.monoms.GetFirst(); tmp; tmp = tmp->pNext)
		monoms.InsertToTail(tmp->data->Copy());
	monoms.Reset();
}

TPolinom TPolinom::operator+(const TPolinom& a) const
{
	TPolinom res(a);
	TPolinom pthis(*this);
	pthis.monoms.Reset();
	res.monoms.Reset();

	while (!pthis.monoms.IsEnded())
	{
		if (*(res.monoms.GetCur()->data) > *(pthis.monoms.GetCur()->data))
		{
			if (res.monoms.NextIsEnded())
			{
				res.monoms.InsertToTail(pthis.monoms.GetCur()->data);
				pthis.monoms.Next();
			}else
			res.monoms.Next();
		}
		else if (*(res.monoms.GetCur()->data) < *(pthis.monoms.GetCur()->data))
		{
			res.monoms.InsertBefore(pthis.monoms.GetCur()->data, res.monoms.GetCur()->data);
			pthis.monoms.Next();
		}
		else
		{
			((TMonom*)res.monoms.GetCur()->data)->coeff += ((TMonom*)pthis.monoms.GetCur()->data)->coeff;
			if (((TMonom*)res.monoms.GetCur()->data)->coeff == 0)
			{
				res.monoms.Remove(res.monoms.GetCur()->data);
				pthis.monoms.Next();
			}
			else
			{
				pthis.monoms.Next();
			}
		}
	}

	//if (!res.monoms.IsEmpty())
	//	while (!monoms.IsEnded())
	//	{
	//		if (((TMonom*)res.monoms.GetCur()->data)->degree > ((TMonom*)monoms.GetCur()->data)->degree)
	//		{
	//			res.monoms.InsertAfter(monoms.GetCur()->data->Copy(), res.monoms.GetCur()->data);
	//			monoms.Next();
	//		}
	//		else if (((TMonom*)res.monoms.GetCur()->data)->degree < ((TMonom*)monoms.GetCur()->data)->degree)
	//		{
	//			res.monoms.InsertBefore(monoms.GetCur()->data->Copy(), res.monoms.GetCur()->data);
	//			monoms.Next();
	//		}
	//		else
	//		{
	//			((TMonom*)res.monoms.GetCur()->data)->coeff += ((TMonom*)monoms.GetCur()->data)->coeff;
	//			if (((TMonom*)res.monoms.GetCur()->data)->coeff == 0)
	//			{
	//				res.monoms.Remove(res.monoms.GetCur()->data);
	//				monoms.Next();
	//			}
	//			else
	//			{
	//				res.monoms.Next();
	//				monoms.Next();
	//			}
	//		}
	//	}
	//else
	//	return *this;
	return res;
}

TPolinom TPolinom::operator*(const TPolinom& a) const
{
	TPolinom res;
	TPolinom pthis = *this;
	TPolinom p(a);
	pthis.monoms.Reset();
	res.monoms.Reset();
	p.monoms.Reset();

	while (!pthis.monoms.IsEnded())
	{
		double pthis_coef = ((TMonom*)pthis.monoms.GetCur()->data)->coeff;
		int pthis_deg = ((TMonom*)pthis.monoms.GetCur()->data)->degree;

		while (!p.monoms.IsEnded())
		{
			int temp_deg = ((TMonom*)p.monoms.GetCur()->data)->degree;
			double temp_coef = ((TMonom*)p.monoms.GetCur()->data)->coeff;
			if ((temp_deg % 10 + pthis_deg % 10) < 10 && (temp_deg / 10 % 10 + pthis_deg / 10 % 10) < 10 && (temp_deg / 100 + pthis_deg / 100) < 10)
			{
			TMonom tmp(((TMonom*)pthis.monoms.GetCur()->data)->coeff * ((TMonom*)p.monoms.GetCur()->data)->coeff, ((TMonom*)pthis.monoms.GetCur()->data)->degree + ((TMonom*)p.monoms.GetCur()->data)->degree);
			res.monoms.InsertToTail(tmp.Copy());
			}
			else
			{
				cout << "Large degree";
				throw "Large degree";
			}
			p.monoms.Next();
		}
		pthis.monoms.Next();
		p.monoms.Reset();
	}
	res.Bringing();
	res.monoms.Sort();
	return res;
}

TPolinom TPolinom::operator+(const double c)
{
	if (c)
	{
		TMonom tmp(c, 0);
		monoms.InsertToTail(tmp.Copy());
	}
	Bringing();
	return *this;
}

TPolinom TPolinom::operator-(const double c)
{
	if (c)
	{
		TMonom tmp(-c, 0);
		monoms.InsertToTail(tmp.Copy());
	}
	Bringing();
	return *this;
}

TPolinom TPolinom::operator*(const double c)
{
	if (c)
	{
		this->monoms.Reset();
		while (!this->monoms.IsEnded())
		{
			((TMonom*)this->monoms.GetCur()->data)->coeff *= c;
			this->monoms.Next();
		}
	}
	else {
		this->monoms.Clear();
	}
	return *this;
}
TPolinom TPolinom::operator-(const TPolinom& a)
{
	TPolinom tmp(a);
	return ((*this) + tmp * (-1));
}

TPolinom TPolinom::operator-()
{
	return ((*this) * (-1));
}

TPolinom& TPolinom::operator=(const TPolinom& a)
{
	monoms.Clear();
	for (TNode* tmp = a.monoms.GetFirst(); tmp; tmp = tmp->pNext)
		monoms.InsertToTail(tmp->data->Copy());
	monoms.Reset();
	return *this;
}

double TPolinom::operator()(double x, double y, double z) const
{
		double res = 0.0;
		TPolinom p(*this);
		p.monoms.Reset();
		while (!p.monoms.IsEnded())
		{
			res += ((TMonom*)p.monoms.GetCur()->data)->coeff * pow(x, ((TMonom*)p.monoms.GetCur()->data)->degree / 100) * pow(y, ((TMonom*)p.monoms.GetCur()->data)->degree / 10 % 10) * pow(z, ((TMonom*)p.monoms.GetCur()->data)->degree % 10);
			p.monoms.Next();
		}
		return res;
}

std::ostream& operator<<(std::ostream& out, TPolinom& polinom)
{
	TPolinom p(polinom);
	p.monoms.Reset();
	bool firstmonom = false;
	if (p.monoms.IsEmpty())
	{
		out << "0";
	}
	else
	{
		do
		{

			if (((TMonom*)p.monoms.GetCur()->data)->coeff > 0)
			{
				if (firstmonom != false)
					out << "+";
				if (((TMonom*)p.monoms.GetCur()->data)->coeff == 1 && ((TMonom*)p.monoms.GetCur()->data)->degree == 0)
					out << "1";
				else
					if (((TMonom*)p.monoms.GetCur()->data)->coeff != 1)
						out << ((TMonom*)p.monoms.GetCur()->data)->coeff;
			}
			else
				out << ((TMonom*)p.monoms.GetCur()->data)->coeff;

			int a = ((TMonom*)p.monoms.GetCur()->data)->degree / 100;
			if (a > 1)
				out << "x" << a;
			else
				if (a == 1)
					out << "x";
			a = ((TMonom*)p.monoms.GetCur()->data)->degree / 10 % 10;
			if (a > 1)
				out << "y" << a;
			else
				if (a == 1)
					out << "y";
			a = ((TMonom*)p.monoms.GetCur()->data)->degree % 10;
			if (a > 1)
				out << "z" << a;
			else
				if (a == 1)
					out << "z";
			p.monoms.Next();
			firstmonom = true;
		} while (!p.monoms.IsEnded());
	}
	return out;
}

void TPolinom::Bringing()
{
	TPolinom p(*this);
	TList MonomsToRemove;
	monoms.Reset();
	int j = 1;
	while (!monoms.IsEnded())
	{
		p.monoms.Reset();
		for(int i = 0; i < j; i++)
			p.monoms.Next();
		while (!p.monoms.IsEnded())
		{
			if (((TMonom*)p.monoms.GetCur()->data)->degree == ((TMonom*)monoms.GetCur()->data)->degree)
			{
				((TMonom*)monoms.GetCur()->data)->coeff += ((TMonom*)p.monoms.GetCur()->data)->coeff;
				MonomsToRemove.InsertToTail(p.monoms.GetCur()->data->Copy());
			}
			p.monoms.Next();
		}
		monoms.Next(); j++;
		while (!MonomsToRemove.IsEnded())
		{
			if (((TMonom*)MonomsToRemove.GetCur()->data)->coeff == ((TMonom*)monoms.GetCur()->data)->coeff && ((TMonom*)MonomsToRemove.GetCur()->data)->degree == ((TMonom*)monoms.GetCur()->data)->degree)
			{
				monoms.Next(); j++;
			}
			MonomsToRemove.Next();
		}
	}
	monoms.Reset();
	while (!monoms.IsEnded())
	{
		if (((TMonom*)monoms.GetCur()->data)->coeff == 0)
		{
			MonomsToRemove.InsertToTail(monoms.GetCur()->data->Copy());
		}
		monoms.Next();
	}
	monoms.Reset();
	MonomsToRemove.Reset();
	while (!MonomsToRemove.IsEnded())
	{
		while (!monoms.IsEnded())
		{
			if (((TMonom*)MonomsToRemove.GetCur()->data)->coeff == ((TMonom*)monoms.GetCur()->data)->coeff && ((TMonom*)MonomsToRemove.GetCur()->data)->degree == ((TMonom*)monoms.GetCur()->data)->degree)
			{
				monoms.Remove(monoms.GetCur()->data);
				break;
			}
			monoms.Next();
		}
		MonomsToRemove.Next();
		monoms.Reset();
	}
}

std::istream& operator>>(std::istream& in, TPolinom& polinom)
{
	string p;
	cout << "\t";
	in >> p;
	polinom = p;
	return in;
}

bool TPolinom::operator==(const TPolinom& a) const
{
	if (this->monoms.IsEmpty() != a.monoms.IsEmpty())
		return false;
		TNode* tmp1 = monoms.GetFirst();
		TNode* tmp2 = a.monoms.GetFirst();
		while (tmp1 && tmp2)
		{
			if (*(tmp1->data) == *(tmp2->data)) {
				tmp1 = tmp1->pNext;
				tmp2 = tmp2->pNext;
			}
			else return false;
		}
		return true;
}