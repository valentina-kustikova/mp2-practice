#pragma once
#ifndef _POLYNOM_H_
#define _POLYNOM_H_
#include <iostream>
#include <string>
#include "Tlist.h"

using namespace std;

class Polynom 
{
private:
	TList<unsigned int, double>* monoms;
	void Formatting();
	void Sorting();
public:
	Polynom();
	Polynom(const Polynom& a);
	Polynom(TList<unsigned int, double>* a);
	Polynom(const string& s);
	~Polynom();
	
	Polynom operator+(const Polynom& a) const;
	Polynom operator-(const Polynom& a) const;
	Polynom operator*(const Polynom& a) const;
	Polynom& operator+=(const Polynom& a);
	Polynom& operator-=(const Polynom& a);
	Polynom& operator*=(const Polynom& a);

	Polynom operator+(const Monom& a) const;
	Polynom operator-(const Monom& a) const;
	Polynom operator*(const Monom& a) const;
	Polynom& operator+=(const Monom& a);
	Polynom& operator-=(const Monom& a);
	Polynom& operator*=(const Monom& a);

	Polynom& operator=(const Polynom& a);
	Polynom operator-() const;
	bool operator ==(const Polynom& a) const;

	friend ostream& operator<<(ostream& out, const Polynom& a)
	{
		a.monoms->Reset();
		while (!a.monoms->IsEnded())
		{
			Monom tmp(a.monoms->GetCurrKey(), a.monoms->GetCurrData());
			out << tmp;
			a.monoms->Next();
		}
		return out;
	};
};
Polynom::Polynom()
{
	monoms = new TList<unsigned int, double>();
};
Polynom::Polynom(const Polynom& a)
{
	monoms = new TList<unsigned int, double>(*a.monoms);
};
Polynom::Polynom(TList<unsigned int, double>* a)
{
	while (!a->IsEnded())
	{
		if ((a->GetCurrKey() > 999) || (a->GetCurrKey() < 0))
			throw "Error: degree must be less than 10";
		a->Next();
	};
	monoms = new TList<unsigned int, double>(*a);
	Formatting();
	Sorting();
};
Polynom::Polynom(const string& s) 
{
	if (s.length() == 0)
		throw "Error: empty line";
	int i = 0;
	int length = s.length();
	monoms = new TList<unsigned int, double>();
	while (i < s.length() - 1)
	{
		unsigned int deg_x = 0, deg_y = 0, deg_z = 0;
		double coef = 0;
		if ((s[i] == '+') || (s[i] == '-') || (i == 0))
		{
			bool sign = 0;
			if (s[i] == '-')
				sign = 1;
			if ((s[i] == '+') || (s[i] == '-'))
				i++;
			string copy;
			while ((s[i] != 'x') && (s[i] != 'y') && (s[i] != 'z') && (s[i] != '+') && (s[i] != '-') && (i < s.length()))
				copy.push_back(s[i++]);
			if ((sign == 0) && (!copy.empty()))
				coef = stod(copy);
			else if (!copy.empty())
				coef = -stod(copy);
		}
		if (s[i] == 'x') 
		{
			if (s[i + 1] == '^')
			{
				deg_x = stoi(&s[i + 2]);
				i = i + 3;
			}
			else
			{
				deg_x = 1;
				i++;
			}
			if (s[i] == 'y') 
			{
				if (s[i + 1] == '^')
				{
					deg_y = stoi(&s[i + 2]);
					i = i + 3;
				}
				else
				{
					deg_y = 1;
					i++;
				}
				if (s[i] == 'z') 
				{
					if (s[i + 1] == '^')
					{
						deg_z = stoi(&s[i + 2]);
						i = i + 3;
					}
					else
					{
						deg_z = 1; 
						i++;
					}
				}
			}
			else if (s[i] == 'z') 
			{
				if (s[i + 1] == '^')
				{
					deg_z = stoi(&s[i + 2]);
					i = i + 3;
				}
				else
				{
					deg_z = 1;
					i++;
				}
				if (s[i] == 'y')
				{
					if (s[i + 1] == '^')
					{
						deg_y = stoi(&s[i + 2]);
						i = i + 3;
					}
					else
					{
						deg_y = 1;
						i++;
					}
				}
			}
		}
		else if (s[i] == 'y')
		{
			if (s[i + 1] == '^')
			{
				deg_y = stoi(&s[i + 2]);
				i = i + 3;
			}
			else
			{
				deg_y = 1;
				i++;
			}
			if (s[i] == 'x')
			{
				if (s[i + 1] == '^')
				{
					deg_x = stoi(&s[i + 2]);
					i = i + 3;
				}
				else
				{
					deg_x = 1;
					i++;
				}
				if (s[i] == 'z')
				{
					if (s[i + 1] == '^')
					{
						deg_z = stoi(&s[i + 2]);
						i = i + 3;
					}
					else
					{
						deg_z = 1;
						i++;
					}
				}
			}
			else if (s[i] == 'z')
			{
				if (s[i + 1] == '^')
				{
					deg_z = stoi(&s[i + 2]);
					i = i + 3;
				}
				else
				{
					deg_z = 1;
					i++;
				}
				if (s[i] == 'x')
				{
					if (s[i + 1] == '^')
					{
						deg_x = stoi(&s[i + 2]);
						i = i + 3;
					}
					else
					{
						deg_x = 1;
						i++;
					}
				}
			}
		}
		else if (s[i] == 'z')
		{
			if (s[i + 1] == '^')
			{
				deg_z = stoi(&s[i + 2]);
				i = i + 3;
			}
			else
			{
				deg_z = 1;
				i++;
			}
			if (s[i] == 'x')
			{
				if (s[i + 1] == '^')
				{
					deg_x = stoi(&s[i + 2]);
					i = i + 3;
				}
				else
				{
					deg_x = 1;
					i++;
				}
				if (s[i] == 'y')
				{
					if (s[i + 1] == '^')
					{
						deg_y = stoi(&s[i + 2]);
						i = i + 3;
					}
					else
					{
						deg_y = 1;
						i++;
					}
				}
			}
			else if (s[i] == 'y')
			{
				if (s[i + 1] == '^')
				{
					deg_y = stoi(&s[i + 2]);
					i = i + 3;
				}
				else
				{
					deg_y = 1;
					i++;
				}
				if (s[i] == 'x')
				{
					if (s[i + 1] == '^')
					{
						deg_x = stoi(&s[i + 2]);
						i = i + 3;
					}
					else
					{
						deg_x = 1;
						i++;
					}
				}
			}
		}
		if (((deg_x != 0) || (deg_y != 0) || (deg_z != 0)) && (coef == 0))
			coef = 1;
		if ((deg_x < 0) || (deg_x > 9) || (deg_y < 0) || (deg_y > 9) || (deg_z < 0) || (deg_z > 9))
			throw "Error: degrees must be less than 9";
		unsigned int conv = deg_x * 100 + deg_y * 10 + deg_z;
		Monom tmp(conv, coef);
		monoms->PushBack(tmp);
	}
	Formatting();
	Sorting();
};
Polynom::~Polynom()
{
	delete monoms;
};

Polynom Polynom::operator+(const Polynom& a) const
{
	Polynom result;
	monoms->Reset();
	a.monoms->Reset();
	while (!monoms->IsEnded() && !a.monoms->IsEnded())
	{
		Monom tmp1(monoms->GetCurrKey(), monoms->GetCurrData());
		Monom tmp2(a.monoms->GetCurrKey(), a.monoms->GetCurrData());
		if (tmp1.conv > tmp2.conv)
		{
			result.monoms->PushBack(tmp1);
			monoms->Next();
		}
		else if (tmp1.conv < tmp2.conv)
		{
			result.monoms->PushBack(tmp2);
			a.monoms->Next();
		}
		else
		{
			if ((tmp1.coef + tmp2.coef) != 0)
				result.monoms->PushBack(tmp1 + tmp2);
			monoms->Next();
			a.monoms->Next();
		}
	}
	while (!monoms->IsEnded())
	{
		Monom tmp(monoms->GetCurrKey(), monoms->GetCurrData());
		result.monoms->PushBack(tmp);
		monoms->Next();
	}
	while (!a.monoms->IsEnded())
	{
		Monom tmp(a.monoms->GetCurrKey(), a.monoms->GetCurrData());
		result.monoms->PushBack(tmp);
		a.monoms->Next();
	}
	monoms->Reset();
	a.monoms->Reset();
	return result;
};
Polynom Polynom::operator-(const Polynom& a) const
{
	Polynom result(a);
	result = -result;
	return (*this + (result));
};
Polynom Polynom::operator*(const Polynom& a) const
{
	Polynom result;
	monoms->Reset();
	while (!monoms->IsEnded())
	{
		a.monoms->Reset();
		while (!a.monoms->IsEnded())
		{
			Monom tmp1(monoms->GetCurrKey(), monoms->GetCurrData());
			Monom tmp2(a.monoms->GetCurrKey(), a.monoms->GetCurrData());
			result.monoms->PushBack(tmp1 * tmp2);
			a.monoms->Next();
		}
		monoms->Next();
	}
	result.Formatting();
	result.Sorting();
	return result;
};
Polynom& Polynom::operator+=(const Polynom& a)
{
	Polynom tmp = *this + a;
	*this = tmp;
	return *this;
};
Polynom& Polynom::operator-=(const Polynom& a)
{
	Polynom tmp = *this - a;
	*this = tmp;
	return *this;
};
Polynom& Polynom::operator*=(const Polynom& a)
{
	Polynom tmp = *this * a;
	*this = tmp;
	return *this;
};

Polynom Polynom::operator+(const Monom& a) const
{
	Polynom result;
	monoms->Reset();
	bool flag = 0;
	while (!monoms->IsEnded())
	{
		Monom tmp(monoms->GetCurrKey(), monoms->GetCurrData());
		if (tmp.conv > a.conv)
			result.monoms->PushBack(tmp);
		else if (tmp.conv == a.conv)
		{
			if ((tmp.coef + a.coef) != 0)
				result.monoms->PushBack(tmp + a);
			flag = 1;
		}
		else if (tmp.conv < a.conv)
		{
			if (flag == 1)
				result.monoms->PushBack(tmp);
			else
			{
				result.monoms->PushBack(a);
				flag = 1;
				result.monoms->PushBack(tmp);
			}
		}
		monoms->Next();
	}
	if (flag == 0)
		result.monoms->PushBack(a);
	monoms->Reset();
	return result;
};
Polynom Polynom::operator-(const Monom& a) const
{
	Monom result(a);
	result = -result;
	return (*this + (result));
};
Polynom Polynom::operator*(const Monom& a) const
{
	Polynom result;
	if (a.coef == 0)
		return result;
	monoms->Reset();
	while (!monoms->IsEnded())
	{
		Monom tmp(monoms->GetCurrKey(), monoms->GetCurrData());
		result.monoms->PushBack(tmp * a);
		monoms->Next();
	}
	return result;
};
Polynom& Polynom::operator+=(const Monom& a)
{
	Polynom tmp = *this + a;
	*this = tmp;
	return *this;
};
Polynom& Polynom::operator-=(const Monom& a)
{
	Polynom tmp = *this - a;
	*this = tmp;
	return *this;
};
Polynom& Polynom::operator*=(const Monom& a)
{
	Polynom tmp = *this * a;
	*this = tmp;
	return *this;
};

Polynom& Polynom::operator=(const Polynom& a)
{
	if (*this == a)
		return *this;
	delete monoms;
	monoms = new TList<unsigned int, double>(*a.monoms);
	return *this;
};
Polynom Polynom::operator-() const
{
	Polynom result;
	monoms->Reset();
	while (!monoms->IsEnded())
	{
		Monom tmp(monoms->GetCurrKey(), -monoms->GetCurrData());
		result.monoms->PushBack(tmp);
		monoms->Next();
	}
	return result;
};
bool Polynom::operator==(const Polynom& a) const
{
	Polynom tmp1(*this);
	Polynom tmp2(a);
	while ((!tmp1.monoms->IsEnded()) && (!tmp2.monoms->IsEnded()))
	{
		if ((tmp1.monoms->GetCurrKey() != tmp2.monoms->GetCurrKey()) ||
			(tmp1.monoms->GetCurrData() != tmp2.monoms->GetCurrData()))
			return false;
		tmp1.monoms->Next();
		tmp2.monoms->Next();
	}
	if ((!tmp1.monoms->IsEnded()) || (!tmp2.monoms->IsEnded()))
		return false;
	return true;
};

void Polynom::Formatting()
{
	monoms->Reset();
	Polynom copy(*this);
	Polynom result;
	while (!monoms->IsEnded())
	{
		double coef = 0;
		while (!copy.monoms->IsEnded())
		{
			if (monoms->GetCurrKey() == copy.monoms->GetCurrKey())
			{
				coef += copy.monoms->GetCurrData();
				copy.monoms->Remove(monoms->GetCurrKey());
			}
			else
				copy.monoms->Next();
		}
		if (coef != 0)
		{
			Monom tmp(monoms->GetCurrKey(), coef);
			result.monoms->PushBack(tmp);
		}
		copy.monoms->Reset();
		monoms->Next();
	};
	*this = result;
};
void Polynom::Sorting()
{
	monoms->Reset();
	if (monoms->GetCurrpNext() == NULL)
		return;
	if (monoms->GetCurrpNext()->pNext == NULL)
		return;
	Polynom copy(*this);
	Polynom result;
	while (!monoms->IsEnded())
	{
		unsigned int max = monoms->GetCurrKey();
		double coef = monoms->GetCurrData();
		while (!copy.monoms->IsEnded())
		{
			if (max < copy.monoms->GetCurrKey())
			{
				max = copy.monoms->GetCurrKey();
				coef = copy.monoms->GetCurrData();
			}
			copy.monoms->Next();
		}
		Monom tmp(max, coef);
		result.monoms->PushBack(tmp);
		copy.monoms->Remove(max);
		monoms->Remove(max);
		copy.monoms->Reset();
		monoms->Reset();
	};
	*this = result;
};
#endif