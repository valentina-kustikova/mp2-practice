#include "polinom.h"
#include "list.h"

Polinom::Polinom(const string& str)
{
	s = str;
	int f = 0, v = 0;
	unsigned int i = 0;//итерация
	int j = 0, st = 0;
	unsigned int k;
	double x = 1; //коэффициент
	Monom tmp;

	while (i < s.size())
	{
		string s1;

		if (s[i] == '-')
		{
			x = -1;
			i++;
		}
		char a[20];
		j = 0;
		while ((i < s.size()) && (s[i] != '+') && (s[i] != '-'))
		{
			a[j] = s[i];
			j++;
			i++;
			v++;
		}
		if (v != 0)
		{
			i--;
			s1 = a;
			s1.erase(j);
			k = 0;
			while (k < s1.length())
			{
				if (isdigit(s1[k]) != 0)
				{
					char c[10];
					string cs;
					while (((isdigit(s1[k]) != 0) || (s1[k] == '.')) && (k < s1.length()))
					{
						c[k] = s1[k];
						k++;
						if (k >= s1.size()) break;
					}
					cs = c;
					cs.erase(k);
					x *= stod(cs);
				}
				if (k >= s1.size()) break;
				char p[1];

				if (s1[k] == 'x')
				{
					if ((k + 1) >= s1.size()) 
					{
						st += 100;
						k++;
						if (k >= s1.size()) break;
					}
					if (s1[k + 1] == '^')
					{
						p[0] = s1[k + 2];
						st += atoi(p) * 100;
						k += 3;
						if (k >= s1.size()) break;
					}
					else
					{
						st += 100;
						k++;
						if (k >= s1.size()) break;
					}
				}

				if (s1[k] == 'y')
				{
					if ((k + 1) >= s1.size()) 
					{
						st += 10;
						k++;
						if (k >= s1.size()) break;
					}
					if (s1[k + 1] == '^')
					{
						p[0] = s1[k + 2];
						st += atoi(p) * 10;
						k += 3;
						if (k >= s1.size()) break;
					}
					else
					{
						st += 10;
						k++;
						if (k >= s1.size()) break;
					}
				}

				if (s1[k] == 'z')
				{
					if ((k + 1) >= s1.size()) 
					{
						st += 1;
						k++;
						if (k >= s1.size()) break;
					}
					if (s1[k + 1] == '^')
					{
						p[0] = s1[k + 2];
						st += atoi(p);
						k += 3;
						if (k >= s1.size()) break;
					}
					else
					{
						st += 1;
						k++;
						if (k >= s1.size()) break;
					}
				}
			}
			tmp.SetCoeff(x);
			tmp.SetDegree(st);
			monoms.InsertToTail(tmp);
			st = 0;
			x = 1;
		}
		v = 0;
		i++;
	}
}
Polinom::Polinom(const Polinom& p1)
{
	s = p1.s;
	monoms = p1.monoms;
}
Polinom Polinom::operator+(const Polinom& p1)
{
	Polinom tmp(p1);
	Polinom Res;
	Node<Monom>* m1;
	Node<Monom>* m2;
	Monom val;
	monoms.Reset();
	m1 = monoms.GetNext();
	while (!monoms.IsEnded()) 
	{
		val = monoms.GetValue();
		Res.monoms.Insert(val);
		m1 = monoms.GetNext();
	}
	tmp.monoms.Reset();
	m2 = tmp.monoms.GetNext();
	while (!tmp.monoms.IsEnded()) 
	{
		val = tmp.monoms.GetValue();
		Res.monoms.Insert(val);
		m2 = tmp.monoms.GetNext();
	}
	return Res;
}
Polinom Polinom::operator-(const Polinom& p1)
{
	Polinom res;

	Polinom tmp(p1);
	tmp = tmp * (-1);
	res = *this + tmp;

	return res;
}
Polinom Polinom::operator*(const Polinom& p1)
{
	Polinom tmp(p1);
	Polinom Res;
	Monom MAX(1, 999);
	Node<Monom>* m1;
	Node<Monom>* m2;
	monoms.Reset();
	m1 = monoms.GetNext();
	tmp.monoms.Reset();
	m2 = tmp.monoms.GetNext();
	while (!monoms.IsEnded()) 
	{
		while (!tmp.monoms.IsEnded()) 
		{
			Monom rm = monoms.GetValue() * tmp.monoms.GetValue();
			if (rm < MAX) 
			{
				Res.monoms.Insert(rm);
			}
			m2 = tmp.monoms.GetNext();
		}
		m1 = monoms.GetNext();
		m2 = tmp.monoms.GetNext();
	}
	return Res;
}

Polinom Polinom::operator*(const double d)
{
	Node<Monom>* tmp;
	monoms.Reset();
	tmp = monoms.GetNext();
	while (!monoms.IsEnded())
	{
		tmp->data = tmp->data * d;
		tmp = monoms.GetNext();
	}
	return *this;
}
const Polinom& Polinom::operator=(const Polinom& p1)
{
	if (this != &p1) {
		s = p1.s;
		monoms = p1.monoms;
	}
	return *this;
}

ostream& operator<<(ostream& ostr, const Polinom& pm)
{
	cout << pm.monoms << endl;
	return ostr;
}