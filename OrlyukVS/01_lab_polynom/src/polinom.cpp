#include <iostream>
#include "polinom.h"
#include "monom.h"
#include "list.h"
#include <string>
#include <cmath>

using namespace std;

TPolinom::TPolinom()//создание фиктивного звена
{
	TMonom temp;
	temp.coef = 0.0;
	temp.deg = -1;
	listmonoms.InsertToTail(temp);
}

TPolinom::TPolinom(const TPolinom& pol)
{
	listmonoms = pol.listmonoms;
}

TList<TMonom> TPolinom::unions(TList<TMonom>& m)
{
	TList<TMonom> res;//результат
	res.Reset();
	m.Reset();
	TNode<TMonom> mon(m.GetCur()->data.coef);
	while (!m.IsEnded())
	{
		mon.data.deg = m.GetCur()->data.deg;//копируем свернутую степень
		if (m.GetCur()->data.deg == m.GetCur()->pNext->data.deg && (m.GetCur()->pNext->data.coef || m.GetCur()->pNext->data.deg))
			mon.data.coef += m.GetCur()->pNext->data.coef;
		else
		{
			if (mon.data.coef)
			{
				res.InsertToTail(mon.data);
				res.Next();
			}
			mon.data.coef = m.GetCur()->pNext->data.coef;
		}
		m.Next();
	}
	return res;
}

TPolinom::TPolinom(string str)
{
	char a[] = { 'x', 'y', 'z' };
	int d[3] = { 100,10,1 };
	while (str.length())
	{
		string part;
		TMonom temp;
		int pos = 1;
		while (pos < str.length() && str[pos] != '+' && str[pos] != '-')
			pos++;
		part = str.substr(0, pos);//берем с нулевой позиции pos эл-тов
		str.erase(0, pos);//”дал€ем элементы в диапазоне
		pos = 0;
		while (part[pos] != 'x' && part[pos] != 'y' && part[pos] != 'z' && pos < part.length())
			pos++;

		string coef = part.substr(0, pos);
		if (coef == "+" || coef.length() == 0)
			temp.coef = 1;
		else if (coef == "-")
			temp.coef = -1;
		else temp.coef = stod(coef);//преобразование строки в число


		part.erase(0, pos);
		part += ' ';

		for (int i = 0; i < 3; i++)
		{
			pos = part.find(a[i]);
			if (pos > -1)
			{
				if (part[pos + 1] != '^')
					part.insert(pos + 1, "^1");
				temp.deg += d[i] * stoi(part.substr(pos + 2, 1));// преобразуем последовательность элементов  в целое число.
				part.erase(pos, 3);
			}
		}

		listmonoms.InsertToTail(temp);
	}

	listmonoms = unions(listmonoms);
}

double TPolinom::calculation()
{
	setlocale(LC_ALL, "Russian");
	double res = 0.0, x, y, z;
	int a;
	cout << "¬ведите значени€ переменных x y z" << endl;
	cin >> x >> y >> z;
	TList<TMonom> p = listmonoms;
	p.Reset();
	p.Next();
	while (!p.IsEnded())
	{
		a = p.GetCur()->data.deg;
		res += (p.GetCur()->data.coef) * pow(x, a / 100) * pow(y, a % 100 / 10) * pow(z, a % 10);
		p.Next();
	}
	return res;
}

TPolinom& TPolinom::operator=(const TPolinom& pol)
{
	listmonoms = pol.listmonoms;
	return *this;
}

TPolinom TPolinom::operator-(const TPolinom& pol) const
{
	return (*this + pol * (-1));
}

TPolinom TPolinom::operator-() const
{
	return ((*this) * (-1));
}

TPolinom TPolinom::operator+(const TPolinom& pol) const
{
	TPolinom res;
	TPolinom pthis = *this;
	TPolinom p = pol;

	pthis.listmonoms.Reset();
	res.listmonoms.Reset();
	p.listmonoms.Reset();
	p.listmonoms.Next();

	while (!pthis.listmonoms.IsEnded() && !p.listmonoms.IsEnded())
	{
		if (pthis.listmonoms.GetCur()->data > p.listmonoms.GetCur()->data)//дл€ упор€дочивани€
		{
			res.listmonoms.InsertToTail(p.listmonoms.GetCur()->data);
			p.listmonoms.Next();
			res.listmonoms.Next();
		}
		else if (pthis.listmonoms.GetCur()->data < p.listmonoms.GetCur()->data)
		{
			res.listmonoms.InsertToTail(pthis.listmonoms.GetCur()->data);
			pthis.listmonoms.Next();
			res.listmonoms.Next();
		}
		else
		{
			double new_coef = pthis.listmonoms.GetCur()->data.coef + p.listmonoms.GetCur()->data.coef;
			if (new_coef)
			{
				TMonom temp(new_coef, pthis.listmonoms.GetCur()->data.deg);
				res.listmonoms.InsertToTail(temp);
				res.listmonoms.Next();
			}
			pthis.listmonoms.Next();
			p.listmonoms.Next();
		}
	}
	while (!pthis.listmonoms.IsEnded())
	{
		res.listmonoms.InsertToTail(pthis.listmonoms.GetCur()->data);
		pthis.listmonoms.Next();
		res.listmonoms.Next();
	}
	while (!p.listmonoms.IsEnded())
	{
		res.listmonoms.InsertToTail(p.listmonoms.GetCur()->data);
		p.listmonoms.Next();
		res.listmonoms.Next();
	}

	return res;
}

TPolinom TPolinom::operator*(const TPolinom& pol) const
{
	TPolinom res;
	TPolinom pthis = *this;
	TPolinom p = pol;

	pthis.listmonoms.Reset();
	p.listmonoms.Reset();
	p.listmonoms.Next();

	while (!pthis.listmonoms.IsEnded())
	{
		double pthis_coef = pthis.listmonoms.GetCur()->data.coef;
		int pthis_deg = pthis.listmonoms.GetCur()->data.deg;
		TPolinom temp(pol);
		temp.listmonoms.Reset();
		while (!temp.listmonoms.IsEnded())
		{
			int temp_deg = temp.listmonoms.GetCur()->data.deg;
			if ((temp_deg % 10 + pthis_deg % 10) < 10 && (temp_deg / 10 % 10 + pthis_deg / 10 % 10) < 10 && (temp_deg / 100 + pthis_deg / 100) < 10)//остаток от делени€
			{
				temp.listmonoms.GetCur()->data.deg += pthis_deg;
				temp.listmonoms.GetCur()->data.coef *= pthis_coef;
			}
			else
				throw "large degree";
			temp.listmonoms.Next();
		}
		res = res + temp;
		pthis.listmonoms.Next();
	}
	return res;
}

TPolinom TPolinom::operator*(const double con) const
{
	TPolinom res;
	if (con)
	{
		res = *this;
		res.listmonoms.Reset();
		while (!res.listmonoms.IsEnded())
		{
			res.listmonoms.GetCur()->data.coef *= con;
			res.listmonoms.Next();
		}
	}
	return res;
}

ostream& operator<<(ostream& ostr, const TPolinom& pm)
{
	TPolinom p = pm;
	p.listmonoms.Reset();
	p.listmonoms.Next();

	while (!p.listmonoms.IsEnded())
	{

		TMonom temp = p.listmonoms.GetCur()->data;

		if (temp.coef > 0)
		{
			ostr << "+";
			if (temp.coef == 1 && temp.deg == 0)
				ostr << "1";
			else
				if (temp.coef != 1)
					ostr << temp.coef;
		}
		else
			ostr << temp.coef;

		int a = temp.deg / 100;
		if (a > 1)
			ostr << "x^" << a;
		else
			if (a == 1)
				ostr << "x";
		a = temp.deg / 10 % 10;
		if (a > 1)
			ostr << "y^" << a;
		else
			if (a == 1)
				ostr << "y";
		a = temp.deg % 10;
		if (a > 1)
			ostr << "z^" << a;
		else
			if (a == 1)
				ostr << "z";
		p.listmonoms.Next();
	}
	return ostr;
}

istream& operator>>(istream& in, TPolinom& pm)
{
	string pm;
	cout << "\t";
	in >> pm;
	pm = TPolinom(pm);
	return in;
}












