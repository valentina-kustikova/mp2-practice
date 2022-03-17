#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include "HeadList.h"
#include "Monom.h"


class TPolinom : public THeadList<TMonom>
{
public:
	TPolinom()
	{
		TMonom m;
		pHead->data = m;
	}
	TPolinom(TMonom& m)
	{
		insCurrent(m);
	}
	TPolinom(TPolinom& p)
	{
		for (p.reset(); !(p.isEnd()); p.goNext())
		{
			insLast(p.pCurr->data);
		}
	}
	void addMonom(TMonom& m)
	{
		{
			for (reset(); !isEnd(); goNext()) {
				if (m == pCurr->data) {
					pCurr->data.coeff += m.coeff;
					if (pCurr->data.coeff == 0) {
						RemoveCurr();
					}
					break;
				}
				if (m > pCurr->data) {
					insCurrent(m);
					break;
				}
			}
			if (isEnd()) {
				insLast(m);
			}
		}
	}

	TPolinom operator*(const int& c)
	{
		TPolinom res(*this);
		res.reset();
		while (!res.isEnd())
		{
			if (c != 0)
			{
				res.pCurr->data.coeff *= c;
				res.goNext();
			}
			else {
				res.RemoveCurr();
			}
		}
		return res;
	}
	TPolinom operator*(const TMonom& m)
	{
		TPolinom res(*this);
		res.reset();
		while (!res.isEnd())
		{
			if (m.coeff != 0)
			{
				int x, y, z;
				x = res.pCurr->data.degree / 100;
				y = (res.pCurr->data.degree - x * 100) / 10;
				z = res.pCurr->data.degree - x * 100 - y * 10;
				res.pCurr->data.coeff *= m.coeff;
				x += m.degree / 100;
				y += (m.degree / 10) % 10;
				z += m.degree % 10;
				if (x >= 10 || y >= 10 || z >= 10)
				{
					throw("Выход за границу степени");
					break;
				}
				res.pCurr->data.degree = x * 100 + y * 10 + z;
			}
			else {
				res.RemoveCurr();
			}
			res.goNext();
		}
		return res;
	}
	TPolinom operator*(TPolinom& p)
	{
		TPolinom tmp1(*this);
		TPolinom res;
		p.reset();
		while (!p.isEnd())
		{
			tmp1.reset();
			res = res + tmp1 * p.pCurr->data;
			p.goNext();
			if (!tmp1.isEnd())
			{
				p.reset();
			}
		}
		return res;
	}
	TPolinom& operator=(TPolinom& p)
	{
		p.reset();
		reset();
		while (!isEnd())
		{
			RemoveCurr();
			goNext();
		}
		while (!p.isEnd())
		{
			addMonom(p.getCurrdata());
			p.goNext();
		}
		return *this;
	}
	bool operator==(TPolinom& p) //копии
	{
		p.reset();
		reset();
		while (!p.isEnd())
		{
			if ((getCurrdata() == p.getCurrdata()) == 0) return false;
			p.goNext();
			goNext();
		}
		return true;
	}/**/





	TPolinom operator-(TMonom& p) { return (*this + p * (-1.0)); }
	TPolinom operator-(TPolinom& p) { return (*this + p * (-1.0)); }
	TPolinom operator+(TPolinom& res)//копии
	{
		TPolinom p(*this);
		res.reset();
		p.reset();
		while (!p.isEnd())
		{
			if (res.pCurr->data.degree > p.pCurr->data.degree)
				res.goNext();
			else if (res.pCurr->data.degree < p.pCurr->data.degree)
			{
				res.insCurrent(p.pCurr->data);
				p.goNext();
			}
			else
			{
				res.pCurr->data.coeff += p.pCurr->data.coeff;
				if (res.pCurr->data.coeff != 0)
				{
					res.goNext();
					p.goNext();
				}
				else
				{
					res.RemoveCurr();
					p.goNext();
				}
			}
		}
		return res;
	}
	TPolinom operator+(TMonom& m)
	{
		TPolinom res;
		res.insCurrent(m);
		res = *this + res;
		return res;
	}
	friend ostream& operator<<(ostream& os, TPolinom& p)
	{
		for (p.reset(); !p.isEnd(); p.goNext()) {
			os << p.getCurrdata();
			if (p.pCurr->pNext != p.pStop)
			{
				os << "+ ";
			}
		}
		os << "\n";
		return os;
	}
	friend istream& operator>>(istream& in, TPolinom& P)
	{
		string str;
		in >> str;
		P = TPolinom(str);
		return in;
	}
	TPolinom(string str)
	{
		string p = str;
		int i = 0;

		while (i < str.length())
		{
			if (str[i] == ' ' || str[i] == '+') { i++; continue; }
			string coeff;
			for (; isdigit(str[i]) || str[i] == ' ' || str[i] == ',' || str[i] == '-'; i++)
			{
				if (str[i] == ' ') continue;
				coeff.push_back(str[i]);
			}
			string degX;
			if (str[i] == 'x')
			{
				i += 1;
				if (str[i] != '^')
				{
					degX = "1";
				}
				else {
					i += 1;
					while (isdigit(str[i]))
					{
						degX.push_back(str[i]);
						i++;
					}
				}
			}
			string degY;
			if (str[i] == 'y')
			{
				i += 1;
				if (str[i] != '^')
				{
					degY = "1";
				}
				else {
					i += 1;
					while (isdigit(str[i]))
					{
						degY.push_back(str[i]);
						i++;
					}
				}
			}
			string degZ;
			if (str[i] == 'z')
			{
				i += 1;
				if (str[i] != '^')
				{
					degZ = "1";
				}
				else {
					i += 1;
					while (isdigit(str[i]))
					{
						degZ.push_back(str[i]);
						i++;
					}
				}
			}
			double _coeff = 1; int _degX = 0, _degY = 0, _degZ = 0;
			if (!coeff.empty()) _coeff = stod(coeff);
			if (!degX.empty()) _degX = stoi(degX);
			if (!degY.empty()) _degY = stoi(degY);
			if (!degZ.empty()) _degZ = stoi(degZ);
			if ((_degX > 9) || (_degY > 9) || (_degZ > 9))
			{
				throw("Выход за границу степени");
				break;
			}
			int d = _degX * 100 + _degY * 10 + _degZ;
			TMonom m(_coeff, d);
			addMonom(m);
		}
	}


};

