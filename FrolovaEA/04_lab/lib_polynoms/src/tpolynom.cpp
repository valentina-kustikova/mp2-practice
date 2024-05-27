
#include "tpolynom.h"
#include"tmonom.h"
#include <iostream>
#include <string>

using namespace std;

TPolinom::TPolinom()
{
	name = " ";
	IntoList(name);
}

TPolinom::TPolinom(const string& n)
{
	if (checkPolynomial(n))
	{
		IntoList(n);
		NormalView();
		name = To_string();
	}
	else
	{
		throw"Error";
	}
}


void TPolinom::NormalView()
{
	TRingList<TMonom> poly = monoms;
	monoms.Clear();
	poly.sort();
	while (!poly.IsEmpty())
	{
		poly.Reset();
		TMonom cur = poly.GetCurrent()->key;
		double coef = poly.GetCurrent()->key.GetCoef();
		while (!poly.Is_End())
		{
			poly.Next();
			if (poly.GetCurrent()->key == cur)
			{
				coef += poly.GetCurrent()->key.GetCoef();
			}
			if (poly.GetCurrent()->key != cur)
			{
				break;
			}
		}
		if (coef != 0)
		{
			cur.SetCoef(coef);
			monoms.InsertLast(cur);
		}
		poly.Reset();
		while (!poly.Is_End())
		{
			if (poly.GetCurrent()->key == cur)
			{
				poly.removeCurrentNode();
			}
			if (poly.GetCurrent()->key != cur)
			{
				break;
			}
		}
	}
	if (monoms.IsEmpty())
	{
		TMonom res(0, 0);
		monoms.InsertLast(res);
	}
}

void TPolinom::DeleteZero()
{
	monoms.Reset();
	while (!monoms.Is_End())
	{
		if (monoms.GetCurrent()->key.GetCoef() == 0.0)
		{
			TMonom obj(monoms.GetCurrent()->key.GetCoef(), monoms.GetCurrent()->key.GetDegree());
			monoms.Next();
			monoms.Remove(obj);
		}
		else
		{
			monoms.Next();
		}
	}
	if (monoms.IsEmpty())
	{
		TMonom monom(0, 0);
		monoms.InsertLast(monom);
	}
	name = To_string();
}

void TPolinom::ProcessVariable(const string& variable, int& degree, int& i, const vector<string>& elements)
{
	if (i + 1 < elements.size())
	{
		if (elements[i + 1] == "^")
		{
			degree = stoi(elements[i + 2]);
			if (i + 2 < elements.size())
				i += 2;
		}
		else
		{
			degree = 1;
		}
	}
	else
	{
		degree = 1;
	}
}

void TPolinom::ProcessCoefficient(const string& element, double& coef, int& nextSign)
{
	if (IsConst(element))
	{
		coef = stod(element);
	}
	else if (element == "+")
	{
		nextSign = 1;
	}
	else if (element == "-")
	{
		nextSign = -1;
	}
}

void TPolinom::IntoList(const string& n)
{
	vector<string> elements = Parse(n);
	double coef = 1;
	int degX = 0;
	int degY = 0;
	int degZ = 0;
	int tmp_next_znak = 1;

	for (int i = 0; i < elements.size(); i++)
	{
		if (i == 0 && (elements[0] == "-" || elements[0] == "+"))
		{
			tmp_next_znak = (elements[0] == "-") ? -1 : 1;
			continue;
		}

		if (elements[i] == "x")
		{
			ProcessVariable("x", degX, i, elements);
			continue;
		}

		if (elements[i] == "y")
		{
			ProcessVariable("y", degY, i, elements);
			continue;
		}

		if (elements[i] == "z")
		{
			ProcessVariable("z", degZ, i, elements);
			continue;
		}

//		ProcessCoefficient(elements[i], coef, tmp_next_znak);
		if (IsConst(elements[i]))
		{
			coef = stod(elements[i]);
			continue;
		}

		if (elements[i] == "+" || elements[i] == "-")
		{
			TMonom monom(tmp_next_znak * coef, degX, degY, degZ);
			monoms.InsertLast(monom);

			coef = 1;
			degX = 0;
			degY = 0;
			degZ = 0;
			tmp_next_znak = (elements[i] == "-") ? -1 : 1;
		}
	}

	TMonom monom(tmp_next_znak * coef, degX, degY, degZ);
	monoms.InsertLast(monom);
}


TPolinom::TPolinom(const TRingList<TMonom>& m)
{
	TRingList<TMonom> tmp = m;
	tmp.Reset();
	while (!tmp.Is_End())
	{
		monoms.InsertLast(tmp.GetCurrent()->key);
		tmp.Next();
	}
	NormalView();
	name = To_string();
}

TPolinom::TPolinom(const TPolinom& p)
{
	name = p.name;

	TRingList<TMonom> tmp = p.monoms;
	tmp.Reset();
	while (!tmp.Is_End())
	{
		monoms.InsertLast(tmp.GetCurrent()->key);
		tmp.Next();
	}
}



TPolinom::~TPolinom()
{
	name = "";
}

TPolinom TPolinom::operator-() const 
{
	TPolinom res(monoms);
	res.monoms.Reset();

	while (!res.monoms.Is_End())
	{
		res.monoms.GetCurrent()->key.SetCoef(res.monoms.GetCurrent()->key.GetCoef() * (-1));
		res.monoms.Next();
	}
	return res;
}

TPolinom TPolinom::operator+(TPolinom& p)
{
	TPolinom res(monoms);
	TRingList<TMonom> copy = p.monoms;
	res.monoms.Reset();
	copy.Reset();
	while (!res.monoms.Is_End())
	{
		while (!copy.Is_End())
		{
			if (res.monoms.GetCurrent()->key.GetDegree() == copy.GetCurrent()->key.GetDegree())
			{
				double coef;
				coef = res.monoms.GetCurrent()->key.GetCoef() + copy.GetCurrent()->key.GetCoef();
				if (coef == 0)
				{
					res.monoms.removeCurrentNode();
				}
				else res.monoms.GetCurrent()->key.SetCoef(coef);
				copy.removeCurrentNode();
			}
			else copy.Next();
		}
		res.monoms.Next();
		copy.Reset();
	}
	if (!copy.Is_End())
	{
		copy.Reset();
		while (!copy.Is_End())
		{
			res.monoms.InsertLast(copy.GetCurrent()->key);
			copy.Next();
		}
	}
	if (res.monoms.IsEmpty())
	{
		TMonom monom(0, 0);
		res.monoms.InsertLast(monom);
	}
	res.monoms.sort();
	res.To_string();
	return res;
}

TPolinom TPolinom::operator-(TPolinom& p)
{
	TPolinom poly = -(p);
	return (*this + poly);
}



TPolinom TPolinom::operator*(TPolinom& p)
{
	TRingList<TMonom> copy_p = p.monoms;
	TRingList<TMonom> copy = monoms;
	TRingList<TMonom> res_list;
	copy_p.Reset();
	copy.Reset();
	while (!copy_p.Is_End())
	{
		while (!copy.Is_End())
		{
			res_list.InsertLast(copy_p.GetCurrent()->key * copy.GetCurrent()->key);
			copy.Next();
		}
		copy.Reset();
		copy_p.Next();
	}
	TPolinom res(res_list);
	return res;
}

const TPolinom& TPolinom::operator=(const TPolinom& p)
{
	if (this == &p) return(*this);

	if (!monoms.IsEmpty())
	{
		monoms.Clear();
	}

	monoms = p.monoms;

	return(*this);

}

double TPolinom::operator()(double _x, double _y, double _z) const
{
	double res = 0;

	TRingList<TMonom> copy = this->monoms;
	copy.Reset();
	while (!copy.Is_End())
	{
		res += copy.GetCurrent()->key.GetValue(_x, _y, _z);
		copy.Next();
	}
	return res;
}

void TPolinom::Sort()
{
	monoms.sort();
	name = To_string();
}

TPolinom TPolinom::dif_x() const
{
	TRingList<TMonom> copy = this->monoms;
	TRingList<TMonom> res_list;
	copy.Reset();
	while (!copy.Is_End())
	{
		if (copy.GetCurrent()->key.GetDegreeX() > 0)
		{
			res_list.InsertLast(copy.GetCurrent()->key.dif_x());
		}
		copy.Next();
	}
	if (res_list.IsEmpty())
	{
		TMonom monom(0, 0);
		res_list.InsertLast(monom);
	}
	TPolinom result(res_list);
	return result;

}

TPolinom TPolinom::dif_y() const
{
	TRingList<TMonom> copy = this->monoms;
	TRingList<TMonom> res_list;
	copy.Reset();
	while (!copy.Is_End())
	{
		if (copy.GetCurrent()->key.GetDegreeY() > 0)
		{
			res_list.InsertLast(copy.GetCurrent()->key.dif_y());
		}
		copy.Next();
	}
	if (res_list.IsEmpty())
	{
		TMonom monom(0, 0);
		res_list.InsertLast(monom);
	}
	TPolinom result(res_list);
	return result;
}

TPolinom TPolinom::dif_z() const
{
	TRingList<TMonom> copy = this->monoms;
	TRingList<TMonom> res_list;
	copy.Reset();
	while (!copy.Is_End())
	{
		if (copy.GetCurrent()->key.GetDegreeZ() > 0)
		{
			res_list.InsertLast(copy.GetCurrent()->key.dif_z());
		}
		copy.Next();
	}
	if (res_list.IsEmpty())
	{
		TMonom monom(0, 0);
		res_list.InsertLast(monom);
	}
	TPolinom result(res_list);
	return result;
}


string TPolinom::To_string() const 
{
	string str = "";
	TRingList<TMonom> tmp=monoms;
	tmp.Reset();
	while (!tmp.Is_End())
	{
		if (tmp.GetCurrent()->key.GetCoef() < 0)
		{
			str += " ";
		}
		if (tmp.GetCurrent()->key.GetCoef() > 0)
		{
			str += "+";
		}
		str += tmp.GetCurrent()->key.GetStr();
		tmp.Next();
	}
	return str;
}

vector<string> TPolinom::Parse(string name)
{
	vector<string> tokens;
	string current_token;

	for (char c : name) {
		if (std::isdigit(c) || c == '.') {
			current_token += c;
		}
		else if (std::isalpha(c)) {
			if (!current_token.empty()) {
				tokens.push_back(current_token);
				current_token.clear();
			}
			current_token += c;
			tokens.push_back(current_token);
			current_token.clear();
		}
		else {
			if (!current_token.empty()) {
				tokens.push_back(current_token);
				current_token.clear();
			}
			current_token += c;
			tokens.push_back(current_token);
			current_token.clear();
		}
	}

	if (!current_token.empty()) {
		tokens.push_back(current_token);
	}
	return tokens;
}

bool TPolinom::IsConst(const string& lecsem)
{
	bool hasDot = false;
	bool flag = true;
	for (char c : lecsem) {
		if (!std::isdigit(c)) {
			if (c == '.' && !hasDot) {
				hasDot = true;
			}
			else {
				flag = false;
				break;
			}
		}
	}
	return flag;
}

bool TPolinom::isValidMonomial(const string& monomial)
{
	if (monomial.empty()) {
		return false;
	}

	int i = 0;
	if (isdigit(monomial[0]))
	{
		if (!isValidCoefficient(monomial, i)) {
			return false;
		}
	}

	for (; i < monomial.size(); i++)
	{
		if (isalpha(monomial[i]))
		{
			if (!isValidVariable(monomial, i)) {
				return false;
			}
		}
		else if (isdigit(monomial[i]) || monomial[i] == '*')
		{
			return false;
		}
	}

	return true;
}

bool TPolinom::isValidCoefficient(const string& monomial, int& i)
{
	int findpoint = 0;
	while (monomial[i] != 'x' && monomial[i] != 'y' && monomial[i] != 'z' && i < monomial.size() && monomial[i] != '*' && (!isalpha(monomial[i])))
	{
		if (isdigit(monomial[i]))
		{
			i++;
			continue;
		}
		if (monomial[i] == '.')
		{
			findpoint++;
			i++;
			continue;
		}
		if (findpoint > 1)
		{
			return false;
		}
	}

	return true;
}

bool TPolinom::isValidVariable(const string& monomial, int& i)
{
	if (monomial[i] == 'x' || monomial[i] == 'y' || monomial[i] == 'z')
	{
		char variable = monomial[i];
		if (i + 1 < monomial.size() && monomial[i + 1] == '^')
		{
			if (i + 2 < monomial.size() && isdigit(monomial[i + 2]))
			{
				i += 2;
				return true;
			}
			else
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

bool TPolinom::checkPolynomial(const string& polyStr)
{
	size_t start = 0;
	size_t end = polyStr.find_first_of("+-", start);

	while (end != string::npos) {
		string monomial;
		if (start != end) {
			monomial = polyStr.substr(start, end - start);
			if (!isValidMonomial(monomial)) {
				return false;
			}
		}

		start = end + 1;
		end = polyStr.find_first_of("+-", start);
	}

	// ѕроверка последнего монома в полиноме
	string lastMonomial = polyStr.substr(start);
	return isValidMonomial(lastMonomial);
}










