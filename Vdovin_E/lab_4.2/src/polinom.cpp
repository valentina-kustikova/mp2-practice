#include "polinom.h"

polinom polinom::converter_in_polinom(const string & s)
{
	polinom p;
	string c = s + '+';
	string mon;
	bool min = false;
	int len = c.length();
	for (int i = 0; i < len; i++)
	{
		if ((c[i] != '+') && (c[i] != '-'))
			mon = mon + c[i];
		else
		{
			if (mon != "")
			{
				if (min)
					mon = '-' + mon;
				monom m(mon);
				mon = "";
				node<monom>* t = p.pol.search(m);
				if (t == NULL)
					p.pol.insertup(m);
				else
					t->data.coeff += m.coeff;
			}
			if (c[i] == '-')
				min = true;
			else
				min = false;
		}
	}
	return p;
}

polinom::polinom(const polinom & p)
{
	pol = p.pol;
}

polinom::polinom(const string & s)
{
	*this = converter_in_polinom(s);
}

const polinom & polinom::operator=(const polinom & p)
{
	pol = p.pol;
	return *this;
}

polinom polinom::operator+(const polinom & p) const
{
	polinom p1(*this);
	polinom p2(p);
	p1.pol.gotohead();
	p2.pol.gotohead();
	p1.pol.gotonext();
	p2.pol.gotonext();
	polinom pp;
	while ((!p1.pol.nowhead()) && (!p2.pol.nowhead()))
	{
		if (p1.pol.getnowdata() > p2.pol.getnowdata())
		{
			pp.pol.insert_to_tail(p1.pol.getnowdata());
			p1.pol.gotonext();
		}
		else
		{
			if (p1.pol.getnowdata() < p2.pol.getnowdata())
			{
				pp.pol.insert_to_tail(p2.pol.getnowdata());
				p2.pol.gotonext();
			}
			else
			{
				monom m(p1.pol.getnowdata().coeff + p2.pol.getnowdata().coeff, p1.pol.getnowdata().xyz);
				if (m.coeff != 0.0)
					pp.pol.insert_to_tail(m);
				p1.pol.gotonext();
				p2.pol.gotonext();
			}
		}
	}
	while (!p1.pol.nowhead())
	{
		pp.pol.insert_to_tail(p1.pol.getnowdata());
		p1.pol.gotonext();
	}
	while (!p2.pol.nowhead())
	{
		pp.pol.insert_to_tail(p2.pol.getnowdata());
		p2.pol.gotonext();
	}
	return pp;
}

polinom polinom::operator*(const polinom & p) const
{
	polinom p1(*this);
	polinom p2(p);
	p1.pol.gotohead();
	p2.pol.gotohead();
	p1.pol.gotonext();
	p2.pol.gotonext();
	polinom pp;
	while (!p1.pol.nowhead())
	{
		while (!p2.pol.nowhead())
		{
			monom m(p1.pol.getnowdata() * p2.pol.getnowdata());
			if (m.coeff != 0.0)
			{
				node<monom>* t = pp.pol.search(m);
				if (t == NULL)
					pp.pol.insertup(m);
				else
				{
					t->data.coeff += m.coeff;
					if (t->data.coeff == 0.0)
						pp.pol.elemdelete(t);
				}
			}
			p2.pol.gotonext();
		}
		p1.pol.gotonext();
		p2.pol.gotohead();
		p2.pol.gotonext();
	}
	return pp;
}

polinom polinom::operator-(const polinom & p) const
{
	return (*this + (p * (-1.0)));
}

polinom polinom::operator*(const double d) const
{
	polinom p1(*this);
	polinom p;
	if (d != 0.0)
	{
		p1.pol.gotohead();
		p1.pol.gotonext();
		while (!p1.pol.nowhead())
		{
			p.pol.insert_to_tail(p1.pol.getnowdata() * d);
			p1.pol.gotonext();
		}
	}
	return p;
}

bool polinom::operator==(const polinom & p) const
{
	if (this != &p)
	{
		polinom p1(*this);
		polinom p2(p);
		bool f = true;
		p1.pol.gotohead();
		p1.pol.gotonext();
		p2.pol.gotohead();
		p2.pol.gotonext();
		while ((f) && (!p1.pol.nowhead()) && (!p2.pol.nowhead()))
		{
			monom a = p1.pol.getnowdata();
			monom b = p2.pol.getnowdata();
			if (a == b)
			{
				if (a.coeff != b.coeff)
					f = false;
			}
			else
				f = false;
			p1.pol.gotonext();
			p2.pol.gotonext();
		}
		if ((!p1.pol.nowhead()) || (!p2.pol.nowhead()))
			f = false;
		return f;
	}
	else
		return true;
}

bool polinom::operator!=(const polinom & p) const
{
	return !(*this == p);
}

ostream & operator<<(ostream & out, const monom & m)
{
	out << m.coeff << "x" << m.xyz / 100 << "y" << (m.xyz / 10) % 10 << "z" << m.xyz % 10;
	return out;
}

polinom operator*(const double d, const polinom & p)
{
	return (p * d);
}

ostream & operator<<(ostream & out, const polinom & p)
{
	out << p.pol;
	return out;
}