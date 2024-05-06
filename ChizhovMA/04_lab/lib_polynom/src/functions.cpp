#include "Monom.h"
#include "Polynom.h"
#include "structures.h"
#include "stack.h"
#include <iostream>
#include <string>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;
map<string, double> TPolynom::symbolDict = {
	{"^", 4},
	{"*", 3},
	{"/", 3},
	{"+", 2},
	{"-", 2},
};


TMonom::TMonom()
{
	coef = 0.0;
	degree = -1;
};
TMonom::TMonom(double c, int d)
{
	coef = c;
	degree = d;
};
TMonom::TMonom(const TMonom& m)
{
	coef = m.coef;
	degree = m.degree;
};
bool TMonom::operator<(const TMonom& m) const
{
	if (degree < m.degree)
		return true;
	else
		return false;
};
bool TMonom::operator>(const TMonom& m) const
{
	if (degree > m.degree)
		return true;
	else
		return false;
};
bool TMonom::operator==(const TMonom& m) const
{
	if (degree == m.degree)
		return true;
	else
		return false;
};
bool TMonom::operator!=(const TMonom& m) const
{
	if (degree != m.degree)
		return true;
	else
		return false;
}

TPolynom::TPolynom()
{
	monoms = new TRingList<TMonom>();
	name = "";
}

TPolynom::TPolynom(const string& s)
{
	name = s;
	monoms = new TRingList<TMonom>();
	Parse_Polynom(name);
}

TPolynom::TPolynom(const TRingList<TMonom>& rlist)
{
	monoms = new TRingList<TMonom>(rlist);
	name = ToString();
}

TPolynom::TPolynom(const TPolynom& p)
{
	name = p.name;
	monoms = new TRingList<TMonom>(*p.monoms);
}

TPolynom::~TPolynom()
{
	delete monoms;
	name = "";
}
TPolynom TPolynom::operator-() const
{
	TRingList<TMonom> list;
	monoms->Reset(); 
	while (!monoms->IsEnded())
	{
		TMonom m = monoms->GetCurrent()->data;
		m.coef *= -1;
		list.InsertEnd(m);
		monoms->Next(); 
	}
	return TPolynom(list);
}
TPolynom TPolynom::operator+(const TPolynom& p)
{
	TRingList<TMonom> list; 
	monoms->Reset();
	p.monoms->Reset();

	while (!monoms->IsEnded() && !p.monoms->IsEnded())
	{
		TMonom m1 = monoms->GetCurrent()->data;
		TMonom m2 = p.monoms->GetCurrent()->data;

		if (m1 == m2)
		{
			double k = m1.coef;
			double k2 = m2.coef;
			double k3 = k + k2;

			if (k3 != 0)
			{
				m2.coef = k3;
				list.InsertEnd(m2);
			}

			monoms->Next();
			p.monoms->Next();
		}
		else if (m1 > m2)
		{
			list.InsertEnd(m2);
			p.monoms->Next();
		}
		else
		{
			list.InsertEnd(m1);
			monoms->Next();
		}
	}
	while (!monoms->IsEnded())
	{
		list.InsertEnd(monoms->GetCurrent()->data);
		monoms->Next();
	}
	while (!p.monoms->IsEnded())
	{
		list.InsertEnd(p.monoms->GetCurrent()->data);
		p.monoms->Next();
	}
	if (list.IsEmpty())
	{
		TMonom m(0, 0);
		list.InsertEnd(m);
	}
	return TPolynom(list);
}
TPolynom TPolynom::operator-(const TPolynom& p) 
{
	return *this + (-p);
}
TPolynom TPolynom::operator*(const TPolynom& p)
{
	TRingList<TMonom> list; 
	int flag = 0;
	monoms->Reset();
	p.monoms->Reset();
	while (!monoms->IsEnded())
	{
		TMonom m = monoms->GetCurrent()->data;
		p.monoms->Reset();
		while (!p.monoms->IsEnded())
		{
			TMonom m2 = p.monoms->GetCurrent()->data;
			double k = m.coef;
			double k2 = m2.coef;
			double k3 = k * k2;
			int d = m.degree;
			int d2 = m2.degree;
			int deg = d + d2;
			TMonom mon(k3, deg);
			bool inserted = false;
			list.Reset();

			while (!list.IsEnded())
			{
				if (deg == list.GetCurrent()->data.degree)
				{
					TMonom m_curr = list.GetCurrent()->data;
					double k_curr = m_curr.coef;
					k3 = k_curr + k3;
					if (k3 != 0)
						flag = 1;
					else
					{
						list.Remove(m_curr);
						inserted = true;
						break;
					}
				}
				if (deg < list.GetCurrent()->data.degree)
				{
					if (flag == 1)
					{
						TMonom mon_new(k3, deg);
						list.InsertBeforeCurr(mon_new);
					}
					else
						list.InsertBeforeCurr(mon); 
					inserted = true;
					break;
				}
				list.Next();
			}
			if (!inserted)
				list.InsertEnd(mon);

			p.monoms->Next();
		}
		monoms->Next();
	}
	return TPolynom(list);
}
const TPolynom& TPolynom::operator=(const TPolynom& p)
{
	if (this == &p)
		return *this;
	name = p.name;
	TRingList<TMonom>* list = new TRingList<TMonom>();
	p.monoms->Reset();
	while (!p.monoms->IsEnded())
	{
		list->InsertEnd(p.monoms->GetCurrent()->data);
		p.monoms->Next();
	}
	delete monoms;
	this->monoms = list;
	return *this;
}
TPolynom TPolynom::difx() const
{
	TRingList<TMonom> list; 
	monoms->Reset();
	while (!monoms->IsEnded())
	{
		TMonom m = monoms->GetCurrent()->data;
		double k = m.coef;
		int d = m.degree;
		if (d >= 100)
		{
			int d0 = d / 100;
			d -= 100;
			k *= d0;
			TMonom newM(k, d);
			list.InsertEnd(newM);
		}
		monoms->Next();
	}
	if (list.IsEmpty())
	{
		TMonom m(0, 0);
		list.InsertEnd(m);
	}
	return TPolynom(list);
}
TPolynom TPolynom::dify() const
{
	TRingList<TMonom> list;
	monoms->Reset();
	while (!monoms->IsEnded())
	{
		TMonom m = monoms->GetCurrent()->data;
		double k = m.coef;
		int d = m.degree;
		int intdeg = d / 100;
		d = d % 100;
		if (d >= 10)
		{
			int d0 = d / 10;
			d -= 10;
			k *= d0;
			d += intdeg * 100;
			TMonom newM(k, d);
			list.InsertEnd(newM);
		}
		monoms->Next();
	}
	if (list.IsEmpty())
	{
		TMonom m(0, 0);
		list.InsertEnd(m);
	}
	return TPolynom(list);
}
TPolynom TPolynom::difz() const
{
	TRingList<TMonom> list;
	monoms->Reset();
	while (!monoms->IsEnded())
	{
		TMonom m = monoms->GetCurrent()->data;
		double k = m.coef;
		int d = m.degree;
		int intdeg = d / 10;
		d = d % 10;
		if (d >= 1)
		{
			int d0 = d;
			d -= 1;
			k *= d0;
			d += intdeg * 10;
			TMonom newM(k, d);
			list.InsertEnd(newM);
		}
		monoms->Next();
	}
	if (list.IsEmpty())
	{
		TMonom m(0, 0);
		list.InsertEnd(m);
	}
	return TPolynom(list);
}
double TPolynom::operator()(double _x, double _y, double _z)
{
	string pol_name = name;
	map<string, double> variableDict = {
		{"x", _x},
		{"y", _y},
		{"z", _z},
	};
	TStack<string> st = ArithmeticExpression::Postfix_Form(pol_name);
	return ArithmeticExpression::Calculate(st, variableDict);
}
string TPolynom::FilteredExpression(const string& s)
{
	string filteredExpression = "";
	int l = s.length();
	for (int i = 0; i < l; i++)
	{
		char c = s[i];
		if (c != ' ')
		{
			filteredExpression += c;
		}
	}
	return filteredExpression;
}
bool TPolynom::isOperand(char c)
{
	return ((c >= 'x' && c <= 'z') || (c >= '0' && c <= '9'));
}
bool TPolynom::Is_Number(const string& str)
{
	for (int i = 0; i < str.length(); i++)
	{
		char c = str[i];
		if (!isdigit(c)) {
			return false; // если встречен не цифровой символ, возвращаем false
		}
	}
	return true;
}
int TPolynom::Is_Symbol(string sm)
{
	if (TPolynom::symbolDict.find(sm) != TPolynom::symbolDict.end())
		return 1;
	else if (sm == "(" || sm == ")")
		return 2;
	return 0;
}
bool TPolynom::isValidExpression(const string& expression)
{
	int k1 = 0, k2 = 0;
	int l = expression.length();
	for (int i = 0; i < l; i++)
	{
		char c = expression[i];
		string s(1, c);
		if (i == 0)
		{
			if (s == "-")
			{
				string num = "";
				char c1 = expression[i + 1];
				if (isOperand(c1))
					continue;
				else
					return false;
			}
			else if (s == "+" || s == "*" || s == "/")
				return false;
		}
		if (s == "^")
		{
			char c2 = expression[i + 1];
			string s2(1, c2);
			if (c2 == 'x' || c2 == 'y' || c2 == 'z' || Is_Symbol(s2))
				return false;
		}
		if (s == "(" || s == ")")
		{
			if (s == "(")
				k1++;
			else
			{
				k2++;
				char c1 = expression[i + 1];
				string s1(1, c);
				if (isOperand(c1) || c1 == '(')
					return false;
			}
		}
		if (s == ".")
		{
			char c2 = expression[i + 1];
			string s2(1, c2);
			if (!Is_Number(s2))
				return false;
		}
		else if ((Is_Symbol(s) != 0) || isOperand(c))
		{
			char c1 = expression[i + 1];
			string s1(1, c1);
			if (Is_Symbol(s) == 1)
			{
				if (Is_Symbol(s1) == 1)
					return false;
				if (i == l - 1)
					return false;
			}
			if ((isOperand(c)) && (s1 == "("))
				return false;
			continue;
		}
		else
			return false; // обнаружен недопустимый символ
	}
	if (k1 != k2)
		return false;
	return true;
}
void TPolynom::HandleX(const string& str, int& i, string& deg)
{
	i++;
	if (str[i] == '^')
	{
		i++;
		char k = str[i];
		int n = k - '0';
		n = n * 100;
		string x = to_string(n);
		deg += x;
		i++;
	}
	else
		deg = "100";
}
void TPolynom::HandleY(const string& str, int& i, string& deg) 
{
	i++;
	if (str[i] == '^')
	{
		i++;
		char k = str[i];
		int n = k - '0';
		int N = stoi(deg);
		N += n * 10;
		string y = to_string(N);
		deg = y;
		i++;
	}
	else
	{
		int N = stoi(deg);
		N += 10;
		string y = to_string(N);
		deg = y;
	}
}
void TPolynom::HandleZ(const string& str, int& i, string& deg)
{
	i++;
	if (str[i] == '^')
	{
		i++;
		char k = str[i];
		int n = k - '0';
		int N = stoi(deg);
		N += n;
		string z = to_string(N);
		deg = z;
		i++;
	}
	else
	{
		int N = stoi(deg);
		N += 1;
		string z = to_string(N);
		deg = z;
	}
}
void TPolynom::CreateAndInsertMonom(double koef, int degree, TRingList<TMonom>* monomList) {
	TMonom monom(koef, degree);
	if (monomList->IsEmpty())
		monomList->InsertFirst(monom);
	else
	{
		monomList->Reset();
		while (!monomList->IsEnded())
		{
			TMonom m = monomList->GetCurrent()->data;
			int deg = m.degree;
			int deg2 = monom.degree;
			if (deg2 < deg)
			{
				monomList->InsertBeforeCurr(monom);
				break;
			}
			else if (deg2 == deg)
			{
				double k = m.coef;
				double k2 = monom.coef;
				if (k2 < k)
				{
					monomList->InsertBeforeCurr(monom);
					break;
				}
				else
				{
					monomList->InsertAfterCurr(monom);
					break;
				}
			}
			monomList->Next();
		}
		if (monomList->IsEnded())
			monomList->InsertEnd(monom);
	}
}
void TPolynom::ProcessMonom(const string& numStr, const string& str, int& i, const string& deg, int& flag, TRingList<TMonom>* monomList) 
{
	int degree = stoi(deg);
	double koef = 0.0;
	if (numStr == "")
		koef = 1.0;
	else
		koef = stod(numStr);
	if (flag == 0)
		koef = -koef;
	if (koef != 0.0)
		CreateAndInsertMonom(koef, degree, monomList);
	if (str[i] == '-')
		flag = 0;
	else
		flag = 1;
}
void TPolynom::Parse_Polynom(const string& s) // ??? разбить на функции
{
	string str = FilteredExpression(s);
	if (!isValidExpression(str))
	{
		string msg = "Input error";
		throw msg;
	}
	TRingList<TMonom>* monomList = new TRingList<TMonom>();
	int flag = 1;
	for (int i = 0; i < str.length(); i++)
	{
		string numStr = "";
		string deg = "0";
		if (str[i] == '-')
		{
			flag = 0;
			i++;
		}
		while (str[i] != '+' && str[i] != '-' && i != str.length())
		{
			char s1 = str[i];
			string s(1, s1);
			if (isdigit(s1) || s == ".")
			{
				numStr += s;
				i++;
			}
			else
			{
				if (isOperand(str[i]))
				{
					if (str[i] == 'x')
						HandleX(str, i, deg);
					else if (str[i] == 'y')
						HandleY(str, i, deg);
					else
						HandleZ(str, i, deg);
				}
				if (str[i] == '*' || str[i] == '/')
					i++;
			}
		}
		ProcessMonom(numStr, str, i, deg, flag, monomList);
	}
	this->monoms = monomList;
}
string TPolynom::ProcessDegreeZero(const string& str, const string& coef_str, double& k)
{
	string st = str;
	if (st == "")
		st += coef_str;
	else
		if (k > 0)
			st += "+" + coef_str;
		else
			st += coef_str;
	return st;
}
string TPolynom::ProcessDegreeNonZero(const string& str, const string& coef_str, double& k, int& f)
{
	string st = str;
	if (coef_str == "1" || coef_str == "-1")
		f = 1;
	if (k > 0)
	{
		if (coef_str == "1")
		{
			if (st != "")
				st += "+";
		}
		else
		{
			if (st != "")
				st += "+" + coef_str;
			else
				st += coef_str;
		}
	}
	else
	{
		if (coef_str == "-1")
			st += "-";
		else
			st += coef_str;
	}
	return st;
}
string TPolynom::ProcessDegreeX(const string& str, const string& coef_str, double& k, int& d, int& flag)
{
	int f = 0;
	string st = ProcessDegreeNonZero(str,coef_str,k, f);

	int deg_x = d / 100;
	if (f == 0)
	{
		if (deg_x == 1)
			st += "*x";
		else
			st += "*x^" + to_string(deg_x);
	}
	else
	{
		if (deg_x == 1)
			st += "x";
		else
			st += "x^" + to_string(deg_x);
	}
	d = d % 100;
	flag++;
	return st;
}
string TPolynom::ProcessDegreeY(const string& str, const string& coef_str, double& k, int& d, int& flag)
{
	string st = str;
	int f = 0;
	if (flag == 0)
		st = ProcessDegreeNonZero(str, coef_str, k, f);
	

	int deg_y = d / 10;
	if (f == 0)
	{
		if (deg_y == 1)
			st += "*y";
		else
			st += "*y^" + to_string(deg_y);
	}
	else
	{
		if (deg_y == 1)
			st += "y";
		else
			st += "y^" + to_string(deg_y);
	}
	d = d % 10;
	flag++;
	return st;
}
string TPolynom::ProcessDegreeZ(const string& str, const string& coef_str, double& k, int& d, int& flag)
{
	string st = str;
	int f = 0;
	if (flag == 0)
		st = ProcessDegreeNonZero(str, coef_str, k, f);
	

	int deg_z = d;
	if (f == 0)
	{
		if (deg_z == 1)
			st += "*z";
		else
			st += "*z^" + to_string(deg_z);
	}
	else
	{
		if (deg_z == 1)
			st += "z";
		else
			st += "z^" + to_string(deg_z);
	}
	d = 0;
	return st;
}
string TPolynom::ToString()
{
	string st = "";
	monoms->Reset();
	while (!monoms->IsEnded())
	{
		TMonom m = monoms->GetCurrent()->data;
		double k = m.coef;
		int d = m.degree;
		int flag = 0;

		ostringstream oss;
		oss << fixed << setprecision(8) << k; // Устанавливаем точность вывода

		string coef_str = oss.str();
		coef_str.erase(coef_str.find_last_not_of('0') + 1, string::npos); // Удаляем конечные нули
		if (coef_str.back() == '.') {
			coef_str.pop_back(); // Удаляем десятичную точку, если она осталась в конце
		}
		

		if (d == 0)
		{
			st = ProcessDegreeZero(st, coef_str, k);
		}
		if (d >= 100)
		{
			st = ProcessDegreeX(st, coef_str, k, d, flag);
		}
		if (d >= 10)
		{
			st = ProcessDegreeY(st, coef_str, k, d, flag);
		}
		if (d >= 1)
		{
			st = ProcessDegreeZ(st, coef_str, k, d, flag);
		}
		
		monoms->Next();
	}
	return st;
}