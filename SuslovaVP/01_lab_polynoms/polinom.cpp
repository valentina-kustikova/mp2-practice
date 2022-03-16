#include "polinom.h"

using namespace std;

Polinom::Polinom(const Polinom& p)
{
	list = p.list;
}

List<Monom> Polinom::Bringing_Sim(List<Monom>& m)
{
	List<Monom> l;
	l.First();
	m.First();
	Node<Monom> monom(m.GetCurr().cf);
	List<Monom> y(m);
	while (!m.End())
	{
		monom.data.pw = m.GetCurr().pw;
		y.Change();
		if (m.GetCurr().pw == y.GetCurr().pw && (y.GetCurr().cf || y.GetCurr().pw))
			monom.data.cf += y.GetCurr().cf;
		else
		{
			if (monom.data.cf)
			{
				l.InsertToTail(monom.data);
				l.Change();
			}
			monom.data.cf = y.GetCurr().cf;
		}
		m.Change();
	}
	return l;
}

Polinom::Polinom(string s)
{
	List<Monom> res;
	while (s.length())
	{
		string str;
		Monom m;
		int p = 1;
		while (p < s.length() && s[p] != '+' && s[p] != '-')
			p++;
		str = s.substr(0, p);
		s.erase(0, p);
		p = 0;
		while (str[p] != 'x' && str[p] != 'y' && str[p] != 'z' && p < str.length())
			p++;

		string c = str.substr(0, p);
		if (c == "+" || c.length() == 0)
			m.cf = 1;
		else
			if (c == "-")
				m.cf = -1;
			else
				m.cf = stod(c);

		str.erase(0, p);
		str += ' ';
		int a[3] = { 100,10,1 };
		for (int i = 0; i < 3; i++)
		{
			p = str.find((char)(120 + i));
			if (p > -1)
			{
				if (str[p + 1] != '^')
					str.insert(p + 1, "^1");
				m.pw += a[i] * stoi(str.substr(p + 2, 1));
				str.erase(p, 3);
			}
		}
		list.InsertCList(m);
	}
	list = Bringing_Sim(list);
}

Polinom Polinom::operator+(const Polinom& p) const
{
	Polinom res;
	Polinom pol1 = *this;
	Polinom pol2 = p;
	res.list.First();
	pol1.list.First();
	pol2.list.First();
	while (!pol1.list.End() && !pol2.list.End())
	{
		if (pol1.list.GetCurr() < pol2.list.GetCurr())
		{
			res.list.InsertToTail(pol1.list.GetCurr());
			pol1.list.Change();
			res.list.Change();
		}
		else if (pol1.list.GetCurr() > pol2.list.GetCurr())
		{
			res.list.InsertToTail(pol2.list.GetCurr());
			pol2.list.Change();
			res.list.Change();
		}
		else
		{
			double c = pol1.list.GetCurr().cf + pol2.list.GetCurr().cf;
			if (c)
			{
				res.list.InsertToTail(Monom(c, pol1.list.GetCurr().pw));
				res.list.Change();
			}
			pol1.list.Change();
			pol2.list.Change();
		}
	}
	while (!pol1.list.End())
	{
		res.list.InsertToTail(pol1.list.GetCurr());
		pol1.list.Change();
		res.list.Change();
	}
	while (!pol2.list.End())
	{
		res.list.InsertToTail(pol2.list.GetCurr());
		pol2.list.Change();
		res.list.Change();
	}
	return res;
}

Polinom Polinom::operator*(const double k) const
{
	Polinom res;
	res = *this;
	res.list.First();
	while (!res.list.End())
	{
		res.list.GetCurr().cf *= k;
		res.list.Change();
	}
	return res;
}

Polinom Polinom::operator-(const Polinom& p) const
{
	return *this + p * (-1);
}

Polinom Polinom::operator-() const
{
	return (-1) * (*this);
}

const Polinom& Polinom::operator=(const Polinom& p)
{
	list = p.list;
	return *this;
}

bool Polinom::operator==(const Polinom& p) const
{
	return list == p.list;
}

bool Polinom::operator!=(const Polinom& p) const
{
	return list != p.list;
}

Polinom Polinom::operator*(const Polinom& p) const
{
	Polinom res;
	Polinom pol = *this;
	Polinom pol2 = p;
	pol.list.First();
	pol2.list.First();
	while (!pol.list.End())
	{
		double pol_cf = pol.list.GetCurr().cf;
		int pol_pw = pol.list.GetCurr().pw;
		Polinom pol3(p);
		pol3.list.First();
		while (!pol3.list.End())
		{
			int pol3_pw = pol3.list.GetCurr().pw;
			if ((pol3_pw % 10 + pol_pw % 10) < 10 && (pol3_pw / 10 % 10 + pol_pw / 10 % 10) < 10 && (pol3_pw / 100 + pol_pw / 100) < 10)
			{
				pol3.list.GetCurr().pw += pol_pw;
				pol3.list.GetCurr().cf *= pol_cf;
			}
			else
				throw "Error.";
			pol3.list.Change();
		}
		res = res + pol3;
		pol.list.Change();
	}
	return res;
}

Polinom operator*(const double k, const Polinom& p)
{
	return p * k;
}

ostream& operator<<(ostream& out, const Polinom& pol)
{
	Polinom p = pol;
	p.list.First();
	while (!p.list.End())
	{
		Monom temp = p.list.GetCurr();
		if (temp.cf > 0)
		{
			out << "+";
			if (temp.cf == 1 && temp.pw == 0)
				out << "1";
			else
				if (temp.cf != 1)
					out << temp.cf;
		}
		else
			out << temp.cf;
		int a = temp.pw / 100;
		if (a > 1)
			out << "x^" << a;
		else
			if (a == 1)
				out << "x";
		a = temp.pw / 10 % 10;
		if (a > 1)
			out << "y^" << a;
		else
			if (a == 1)
				out << "y";
		a = temp.pw % 10;
		if (a > 1)
			out << "z^" << a;
		else
			if (a == 1)
				out << "z";
		p.list.Change();
	}
	return out;
}