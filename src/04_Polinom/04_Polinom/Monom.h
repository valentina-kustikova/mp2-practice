#pragma once
#include "Node.h"
#include <string>
class Monom : public TNode<unsigned int, double>
{
public:
	Monom(unsigned int, double, Monom* = nullptr);
	Monom(const Monom&);
	Monom(const string&);
	~Monom();
	Monom operator*(double);
	Monom operator+(const Monom&);
	Monom operator-(const Monom&);
	Monom operator*(const Monom&);
	Monom operator-() const;
	Monom& operator=(const Monom&);
	bool operator>(const Monom&) const;
	bool operator<(const Monom&) const;
	bool operator==(const Monom&) const;
	bool operator!=(const Monom&) const;
};
Monom::Monom(const Monom& _node)
{
	key = _node.key;
	pData = _node.pData;
	pNext = _node.pNext;
}
Monom::Monom(unsigned int _key, double _data, Monom* node)
{
	if (_key < 0 || _key > 999 || _data == 0.0)
		throw "incorrect monom";
	key = _key;
	pData = _data;
	pNext = node;
}
Monom::Monom(const string& monom)
{
	string simbols;
	string coef;
	string degree;
	string degree1;
	string degree2;
	string degree3;
	for (int i = 0; i < monom.length(); i++)
		if (monom[i] != '*' && monom[i] != '^')
			simbols += monom[i];
	if (simbols[0] == 'x' || simbols[0] == 'y' || simbols[0] == 'z')
		coef = 1;
	int i = 0;
	while (simbols[i] != 'x' && simbols[i] != 'y' && simbols[i] != 'z' && i < simbols.length())
	{
		coef += simbols[i];
		i++;
	}
	for (int i = 0; i < simbols.length(); i++)
	{
		if (simbols[i] == 'x')
		{
			i++;
			if (simbols[i] == 'y' || simbols[i] == 'z' || i == simbols.length())
				degree1 = 1;
			else degree1 = simbols[i];
		}
		if (simbols[i] == 'y')
		{
			i++;
			if (simbols[i] == 'x' || simbols[i] == 'z' || i == simbols.length())
				degree2 = 1;
			else degree2 = simbols[i];
		}
		if (simbols[i] == 'z')
		{
			i++;
			if (simbols[i] == 'x' || simbols[i] == 'y' || i == simbols.length())
				degree3 = 1;
			else degree3 = simbols[i];
		}
	}
	degree = degree1 + degree2 + degree3;
	pData = stod(coef);
	key = stoi(degree);
	pNext = nullptr;
}
Monom::~Monom()
{}
Monom Monom::operator*(double number)
{
	Monom result(*this);
	result.pData = result.pData * number;
	return result;
}
Monom Monom::operator+(const Monom& slog)
{
	if (key != slog.key)
		throw "additiion can`t be performed";
	Monom result(*this);
	result.pData = result.pData + slog.pData;
	return result;
}
Monom Monom::operator-(const Monom& slog)
{
	if (key != slog.key)
		throw "additiion can`t be performed";
	Monom result(*this);
	result.pData = result.pData - slog.pData;
	return result;
}
Monom Monom::operator*(const Monom& slog)
{
	Monom result(*this);
	result.pData = result.pData * slog.pData;
	result.key = result.key + slog.key;
	return result;
}
Monom Monom::operator-() const
{
	Monom result(*this);
	result.pData = result.pData * -1;
	return result;
}
Monom& Monom::operator=(const Monom& slog)
{
	if (*this == slog)
		return *this;
	pData = slog.pData;
	key = slog.key;
	pNext = slog.pNext;
	return *this;
}
bool Monom::operator>(const Monom& slog) const
{
	return (key > slog.key);
}
bool Monom::operator<(const Monom& slog) const
{
	return (key < slog.key);
}
bool Monom::operator==(const Monom& slog) const
{
	if (key == slog.key && pData == slog.pData)
		return true;
	return false;
}
bool Monom::operator!=(const Monom& slog) const
{
	return !(*this == slog);
}



