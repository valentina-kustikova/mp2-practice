#include "Monom.h"
#include "ListHeader.h"
#include <string>

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
	degree = 0;
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

TPolynom::TPolynom(const string s)
{
	monoms = new TRingList<TMonom>();
	name = s;
}

TPolynom::TPolynom(const TRingList<TMonom>& rlist)
{
	name = "";
	monoms = new TRingList<TMonom>(rlist);
}

TPolynom::TPolynom(const TPolynom& p)
{
	name = p.name;
	monoms = new TRingList<TMonom>(*p.monoms);
}

TPolynom::~TPolynom()
{
	delete monoms;
}
TPolynom TPolynom::operator+(const TPolynom& p)
{
	TList<TMonom>* list = new TList<TMonom>();
	monoms->Reset();
	p.monoms->Reset();
	while (monoms->GetCurrent() != nullptr)
	{
		list->InsertEnd(monoms->GetCurrent()->data);
		monoms->Next();
	}
	while (p.monoms->GetCurrent() != nullptr)
	{
		monoms->Reset();
		int flag = 1;
		TMonom m2 = p.monoms->GetCurrent()->data;

		while (monoms->GetCurrent() != nullptr)
		{
			TMonom m1 = monoms->GetCurrent()->data;
			if (m1 == m2)
			{
				double k = m1.GetCoef();
				double k2 = m2.GetCoef();
				double k3 = k + k2;
				if (k3 == 0)
					flag = 3;
				else
				{
					m2.SetCoef(k3);
					flag = 2;
				}
				break;
			}
			monoms->Next();
		}
		if (flag == 1)
			list->InsertEnd(p.monoms->GetCurrent()->data);
		else if (flag == 2)
		{
			TMonom search = list->Search(monoms->GetCurrent()->data)->data;
			list->InsertAfter(m2, search);
			list->Remove(monoms->GetCurrent()->data);
		}
		else if (flag == 3)
			list->Remove(monoms->GetCurrent()->data);
		p.monoms->Next();
	}
	TRingList<TMonom>* res = new TRingList<TMonom>(*list);
	TPolynom result;
	result.monoms = res;
	return result;
}
TPolynom TPolynom::operator-(const TPolynom& p)
{
	TList<TMonom>* list = new TList<TMonom>();
	monoms->Reset();
	p.monoms->Reset();
	while (monoms->GetCurrent() != nullptr)
	{
		list->InsertEnd(monoms->GetCurrent()->data);
		monoms->Next();
	}
	while (p.monoms->GetCurrent() != nullptr)
	{
		monoms->Reset();
		int flag = 1;
		TMonom m2 = p.monoms->GetCurrent()->data;

		while (monoms->GetCurrent() != nullptr)
		{
			TMonom m1 = monoms->GetCurrent()->data;
			if (m1 == m2)
			{
				double k = m1.GetCoef();
				double k2 = m2.GetCoef();
				double k3 = k - k2;
				if (k3 == 0)
					flag = 3;
				else
				{
					m2.SetCoef(k3);
					flag = 2;
				}
				break;
			}
			monoms->Next();
		}
		if (flag == 1)
		{
			double t = m2.GetCoef();
			int deg = m2.GetDegree();
			double t2 = -t;
			TMonom mon(t2, deg);
			list->InsertEnd(mon);
		}
		else if (flag == 2)
		{
			TMonom search = list->Search(monoms->GetCurrent()->data)->data;
			list->InsertAfter(m2, search);
			list->Remove(monoms->GetCurrent()->data);
		}
		else
			list->Remove(monoms->GetCurrent()->data);
		p.monoms->Next();
	}
	TRingList<TMonom>* res = new TRingList<TMonom>(*list);
	TPolynom result;
	result.monoms = res;
	return result;
}
TPolynom TPolynom::operator*(const TPolynom& p)
{
	throw "Error";
}
const TPolynom& TPolynom::operator=(const TPolynom& p)
{
	name = p.name;
	TList<TMonom>* list = new TList<TMonom>();
	p.monoms->Reset();
	while (p.monoms->GetCurrent() != nullptr)
	{
		list->InsertEnd(p.monoms->GetCurrent()->data);
		p.monoms->Next();
	}
	TRingList<TMonom>* res = new TRingList<TMonom>(*list);
	delete monoms;
	this->monoms = res;
	return *this;
}
TPolynom TPolynom::difx() const
{
	TList<TMonom>* list = new TList<TMonom>();
	monoms->Reset();
	while (monoms->GetCurrent() != nullptr)
	{
		TMonom m = monoms->GetCurrent()->data;
		double k = m.GetCoef();
		int d = m.GetDegree();
		if (d >= 100)
		{
			int d0 = d / 100;
			d -= 100;
			k *= d0;
			TMonom newM(k, d);
			list->InsertEnd(newM);
		}
		monoms->Next();
	}
	TRingList<TMonom>* res = new TRingList<TMonom>(*list);
	TPolynom result;
	result.monoms = res;
	return result;
}
TPolynom TPolynom::dify() const
{
	TList<TMonom>* list = new TList<TMonom>();
	monoms->Reset();
	while (monoms->GetCurrent() != nullptr)
	{
		TMonom m = monoms->GetCurrent()->data;
		double k = m.GetCoef();
		int d = m.GetDegree();
		int intdeg = d / 100;
		d = d % 100;
		if (d >= 10)
		{
			int d0 = d / 10;
			d -= 10;
			k *= d0;
			d += intdeg * 100;
			TMonom newM(k, d);
			list->InsertEnd(newM);
		}
		monoms->Next();
	}
	TRingList<TMonom>* res = new TRingList<TMonom>(*list);
	TPolynom result;
	result.monoms = res;
	return result;
}
TPolynom TPolynom::difz() const
{
	throw "Error";
}
double TPolynom::operator()(double _x, double _y, double _z)
{
	throw "Error";
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
void TPolynom::Parse_Polynom(const string& s)
{
	string str = FilteredExpression(s);
	if (!isValidExpression(str))
	{
		string msg = "Input error";
		throw msg;
	}
	else
	{
		TList<TMonom>* monomList = new TList<TMonom>();
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
				if (isdigit(s1))
				{
					numStr += s;
					i++;
				}
				else
				{
					if (isOperand(str[i]))
					{
						if (str[i] == 'x')
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
						else if (str[i] == 'y')
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
						else
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
					}
					if (str[i] == '*' || str[i] == '/')
						i++;


				}
			}
			int degree = stoi(deg);
			double koef = 0.0;
			if (numStr == "")
				koef = 1.0;
			else
				koef = stod(numStr);
			if (flag == 0)
				koef = -koef;
			TMonom monom(koef, degree);
			monomList->InsertEnd(monom);
			if (str[i] == '-')
				flag = 0;
			else
				flag = 1;
		}
		TRingList<TMonom>* polynomList = new TRingList<TMonom>(*monomList);
		this->monoms = polynomList;
	}
}

void TPolynom::Print_Polynom()
{
	cout << "Monoms:" << endl;
	while (monoms->GetCurrent() != nullptr)
	{
		cout << monoms->GetCurrent()->data << endl;
		monoms->Next();
	}
}