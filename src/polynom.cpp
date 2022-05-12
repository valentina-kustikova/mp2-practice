#include "polynom.h"

using namespace std;

Polynom::Polynom(const Polynom& p)
{
	list = p.list;
}

List<Monom> Polynom::similar(List<Monom>& m)
{
	List<Monom> l;
	l.Reset();
	m.Reset();
	Node<Monom> monom(m.GetCurr().coeff);
	List<Monom> y(m);
	while (!m.isEnd())
	{
		monom.data.degree = m.GetCurr().degree;
		y.Next();
		if (m.GetCurr().degree == y.GetCurr().degree)
			monom.data.coeff += y.GetCurr().coeff;
		else
		{
			if (monom.data.coeff)
			{
				l.InsertToTail(monom.data);
				l.Next();
			}
			monom.data.coeff = y.GetCurr().coeff;
		}
		m.Next();
	}
	return l;
}

Polynom::Polynom(string s)
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
			m.coeff = 1;
		else
			if (c == "-")
				m.coeff = -1;
			else
				m.coeff = stod(c);

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
				m.degree += a[i] * stoi(str.substr(p + 2, 1));
				str.erase(p, 3);
			}
		}
		list.InsertInOrder(m);
	}
	list = similar(list);
}

Polynom Polynom::operator+(const Polynom& p) const
{
	Polynom res;
	Polynom pol1 = *this;
	Polynom pol2 = p;
	res.list.Reset();
	pol1.list.Reset();
	pol2.list.Reset();
	while (!pol1.list.isEnd() && !pol2.list.isEnd())
	{
		if (pol1.list.GetCurr() < pol2.list.GetCurr())
		{
			res.list.InsertToTail(pol1.list.GetCurr());
			pol1.list.Next();
			res.list.Next();
		}
		else if (pol1.list.GetCurr() > pol2.list.GetCurr())
		{
			res.list.InsertToTail(pol2.list.GetCurr());
			pol2.list.Next();
			res.list.Next();
		}
		else
		{
			double c = pol1.list.GetCurr().coeff + pol2.list.GetCurr().coeff;
			if (c)
			{
				res.list.InsertToTail(Monom(c, pol1.list.GetCurr().degree));
				res.list.Next();
			}
			pol1.list.Next();
			pol2.list.Next();
		}
	}
	while (!pol1.list.isEnd())
	{
		res.list.InsertToTail(pol1.list.GetCurr());
		pol1.list.Next();
		res.list.Next();
	}
	while (!pol2.list.isEnd())
	{
		res.list.InsertToTail(pol2.list.GetCurr());
		pol2.list.Next();
		res.list.Next();
	}
	return res;
}

Polynom Polynom::operator*(const double k) const
{
	Polynom res;
	res = *this;
	res.list.Reset();
	while (!res.list.isEnd())
	{
		res.list.GetCurr().coeff *= k;
		res.list.Next();
	}
	return res;
}

Polynom Polynom::operator*(const Polynom& p) const
{
	Polynom res;
	Polynom pol = *this;
	Polynom pol2 = p;
	pol.list.Reset();
	pol2.list.Reset();
	while (!pol.list.isEnd())
	{
		double pol_coeff = pol.list.GetCurr().coeff;
		int pol_degree = pol.list.GetCurr().degree;
		Polynom pol3(p);
		pol3.list.Reset();
		while (!pol3.list.isEnd())
		{
			int pol3_degree = pol3.list.GetCurr().degree;
			if ((pol3_degree % 10 + pol_degree % 10) < 10 && (pol3_degree / 10 % 10 + pol_degree / 10 % 10) < 10 && (pol3_degree / 100 + pol_degree / 100) < 10)
			{
				pol3.list.GetCurr().degree += pol_degree;
				pol3.list.GetCurr().coeff *= pol_coeff;
			}
			else
				throw "Error.";
			pol3.list.Next();
		}
		res = res + pol3;
		pol.list.Next();
	}
	return res;
}

Polynom operator*(const double k, const Polynom& p)
{
	return p * k;
}

Polynom Polynom::operator-(const Polynom& p) const
{
	return *this + p * (-1);
}

Polynom Polynom::operator-() const
{
	return (-1) * (*this);
}

const Polynom& Polynom::operator=(const Polynom& p)
{
	list = p.list;
	return *this;
}

bool Polynom::operator==(const Polynom& p) const
{
	return list == p.list;
}

bool Polynom::operator!=(const Polynom& p) const
{
	return list != p.list;
}

inline double Polynom::operator()(double x, double y, double z)
{
	double res = 0.0;
	this->list.Reset();
	while (!this->list.isEnd())
	{
		res += this->list.GetCurr().coeff * pow(x, this->list.GetCurr().degree / 100) * pow(y, this->list.GetCurr().degree / 10 % 10) * pow(z, this->list.GetCurr().degree % 10);
		this->list.Next();
	}
	return res;
}

ostream& operator<<(ostream& out, const Polynom& pol)
{
	Polynom p = pol;
	p.list.Reset();
	while (!p.list.isEnd())
	{
		Monom temp = p.list.GetCurr();
		if (temp.coeff > 0)
		{
			out << "+";
			if (temp.coeff == 1 && temp.degree == 0)
				out << "1";
			else
				if (temp.coeff != 1)
					out << temp.coeff;
		}
		else
			out << temp.coeff;
		int a = temp.degree / 100;
		if (a > 1)
			out << "x^" << a;
		else
			if (a == 1)
				out << "x";
		a = temp.degree / 10 % 10;
		if (a > 1)
			out << "y^" << a;
		else
			if (a == 1)
				out << "y";
		a = temp.degree % 10;
		if (a > 1)
			out << "z^" << a;
		else
			if (a == 1)
				out << "z";
		p.list.Next();
	}
	return out;
}

istream& operator>>(istream& in, Polynom& pol)
{
	string s;
	in >> s;
	pol = Polynom(s);

	return in;
};