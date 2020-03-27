#include "TNode.h"

#include "iostream"
#include "string"
using namespace std;
#define MAX_KEY 999
#define MAX_DEGREE 9
#define UINT unsigned int
#define Monom TNode<UINT, double>

template<>
struct Monom
{
	UINT key;//degree
	double koef;//koef
	Monom* pNext;

	TNode();
	TNode(UINT _key, double _koef);
	TNode(double _koef);
	TNode(const Monom& _monom);
	~TNode();
	bool operator==(const Monom& _monom) const;
	bool operator!=(const Monom& _monom) const;
	const Monom& operator=(const Monom& _monom);
	Monom operator-() const;
	Monom operator+(const Monom& _monom);
	Monom operator-(const Monom& _monom);
	Monom operator*(const Monom& _monom);
	bool operator>(const Monom& _monom) const;
	bool operator<(const Monom& _monom) const;

	char znakmonoma();

	friend istream& operator>>(istream& in, Monom& _monom);
	friend ostream& operator<<(ostream& out, const Monom& _monom);

	static Monom convert(const string& _monom);
};


Monom::TNode()
{
	pNext = nullptr;
	key = 0;
	koef = 0.0;
}

Monom::TNode(UINT _key, double _koef)
{
	if (_key > MAX_KEY)
		throw "bad";
	key = _key;
	koef = _koef;
	pNext = nullptr;
}

Monom::TNode(double _koef)
{
	key = 0;
	koef = _koef;
	pNext = nullptr;
}

Monom::TNode(const Monom& _monom)
{
	if (&_monom != nullptr)
	{
		key = _monom.key;
		koef = _monom.koef;
		pNext = nullptr;
	}
	else
	{
		key = 0;
		koef = 0.0;
		pNext = nullptr;
	}
}

Monom::~TNode()
{
	pNext = nullptr;
}

bool Monom::operator==(const Monom & _monom) const
{
	if ((this->key == _monom.key) || (this->koef == _monom.koef))
		return true;
	return false;
}
bool Monom::operator!=(const Monom & _monom) const
{
	if ((this->key != _monom.key) || (this->koef != _monom.koef))
		return true;
	return false;
}
const Monom& Monom::operator=(const Monom& _monom)
{
	if (*this != _monom) // operator!= ==
	{
		key = _monom.key;
		koef = _monom.koef;
	}
	return *this;
}
Monom Monom::operator-() const
{
	return Monom(this->key, this->koef*(-1));
}



Monom Monom::operator+(const Monom& _monom)
{
	if (key != _monom.key)
		throw "ne te stepeni";
	return Monom(key, koef + _monom.koef);
}

Monom Monom::operator-(const Monom& _monom)
{
	if (key != _monom.key)
		throw "Ne sovpadayut stepeni";
	return Monom(key, koef - _monom.koef);
}

Monom Monom::operator*(const Monom& _monom)
{
	if ((key / 100 + _monom.key / 100 > MAX_DEGREE)
		|| ((key % 100) / 10 + (_monom.key % 100) / 10 > MAX_DEGREE)
		|| (key % 10 + _monom.key % 10 > MAX_DEGREE))
		throw "Nevernaya stepen";
	return Monom(key + _monom.key, koef * _monom.koef);
}
inline bool Monom::operator>(const Monom & _monom) const
{
	if (key > _monom.key)
		return true;
	return false;
}

inline bool Monom::operator<(const Monom & _monom) const
{
	if (key < _monom.key)
		return true;
	return false;
}



inline char Monom::znakmonoma()//remove
{
	if (koef > 0)
		return '+';
	if (koef < 0)
		return '-';
}

Monom Monom::convert(const string & _monom)
{
	UINT key;
	double koef;

	string new_monom;
	for (int i = 0; i < _monom.length(); i++)
		if ((_monom[i] != ' ') && (_monom[i] != '*') && (_monom[i] != '+') && (_monom[i] != '-'))
			new_monom.push_back(_monom[i]);
	string coef;
	UINT x_degree = 0;
	UINT y_degree = 0;
	UINT z_degree = 0;

	int j = 0;
	if ((new_monom[j] == 'x') || (new_monom[j] == 'y') || (new_monom[j] == 'z'))
		coef.push_back('1');
	else
		while ((new_monom[j] != 'x') && (new_monom[j] != 'y')
			&& (new_monom[j] != 'z') && (new_monom.length() - j))
			coef.push_back(new_monom[j++]);

	if ((!coef.empty()) && (coef.find_first_not_of("0123456789.") == coef.npos))
		koef = stod(coef);
	else throw "bad1";

	for (int i = j; i < new_monom.length(); i++)
	{
		switch (new_monom[i])
		{
		case 'x':
		{
			if (new_monom[i + 1] == '^')
				if (('0' <= new_monom[i + 2]) && (new_monom[i + 2] <= '9'))
					if (x_degree + new_monom[i + 2] - '0' > MAX_DEGREE)
						throw "bad2";
					else
					{
						x_degree += new_monom[i + 2] - '0';
						i += 2;
					}
				else throw "bad3";
			else if ((new_monom[i + 1] == 'y') || (new_monom[i + 1] == 'z') || (new_monom[i + 1] == 0))
				if (x_degree + 1 > MAX_DEGREE)
					throw "bad4";
				else x_degree++;
			else if ((i + 1 >= new_monom.length()) || (new_monom[i + 1] == ' ')
				|| (new_monom[i + 1] == '+') || (new_monom[i + 1] == '*'))
				x_degree++;
			else
				throw "bad5";
			break;
		}
		case 'y':
		{
			if (new_monom[i + 1] == '^')
				if (('0' <= new_monom[i + 2]) && (new_monom[i + 2] <= '9'))
					if (y_degree + new_monom[i + 2] - '0' > MAX_DEGREE)
						throw "bad6";
					else
					{
						y_degree += new_monom[i + 2] - '0';
						i += 2;
					}
				else throw "bad7";
			else if ((new_monom[i + 1] == 'x') || (new_monom[i + 1] == 'z') || (new_monom[i + 1] == 0))
				if (y_degree + 1 > MAX_DEGREE)
					throw "bad8";
				else y_degree++;
			else if ((i + 1 >= new_monom.length()) || (new_monom[i + 1] == ' ')
				|| (new_monom[i + 1] == '+') || (new_monom[i + 1] == '*'))
				y_degree++;
			else throw "bad9";
			break;
		}
		case 'z':
		{
			if (new_monom[i + 1] == '^')
				if (('0' <= new_monom[i + 2]) && (new_monom[i + 2] <= '9'))
					if (z_degree + new_monom[i + 2] - '0' > MAX_DEGREE)
						throw "bad10";
					else
					{
						z_degree += new_monom[i + 2] - '0';
						i += 2;
					}
				else throw "bad11";
			else if ((new_monom[i + 1] == 'x') || (new_monom[i + 1] == 'y') || (new_monom[i + 1] == 0))
				if (z_degree + 1 > MAX_DEGREE)
					throw "bad12";
				else z_degree++;
			else if ((i + 1 >= new_monom.length()) || (new_monom[i + 1] == ' ')
				|| (new_monom[i + 1] == '+') || (new_monom[i + 1] == '*'))
				z_degree++;
			else throw "bad13";
			break;
		}
		default: throw "bad14";
			break;
		}
	}
	key = x_degree * 100 + y_degree * 10 + z_degree;
	return Monom(key, koef);
}

istream & operator>>(istream & in, Monom & _monom) // convert
{
	in.ignore(in.rdbuf()->in_avail());

	string line;
	getline(in, line);
	int lengthOfExpression = int(line.length());

	while (lengthOfExpression)
	{
		char _sign = '+';
		int start;
		int end;
		string s_monom;
		int p;

		p = 2;

		for (int i = 0; i < lengthOfExpression; i++)
		{
			if (line[i] == ' ');
			else if ((line[i] == '+') || (line[i] == '-'))
			{
				if (p == 0)
					throw "bad";
				p = 0;
				_sign = line[i];
			}
			else if ((line[i] == 'x') || (line[i] == 'y') || (line[i] == 'z')
				|| (('0' <= line[i]) && (line[i] <= '9')))
			{
				if (p == 1)
					throw "bad";
				p = 1;
				start = i;
				for (end = i; ((line[end] != '+') && (line[end] != '-') && (end < lengthOfExpression)); end++);
				break;
			}
			else throw "bad";
		}
		s_monom = line.substr(start, end - start + 1);
		_monom = Monom().convert(s_monom) * (44 - _sign);
		break;
	}

	return in;
}

ostream& operator<<(ostream& out, const Monom& _monom)
{
	if (_monom.koef < 0)
		out << " -";
	if ((_monom.key == 0) || (abs(_monom.koef) != 1))
		out << " " << abs(_monom.koef);

	if (_monom.key / 100 == 1)
		out << (abs(_monom.koef) != 1 ? " * x" : " x");
	else if (_monom.key / 100 != 0)
		out << (abs(_monom.koef) != 1 ? " * x^" : " x^") << _monom.key / 100;

	if ((_monom.key % 100) / 10 == 1)
		out << (abs(_monom.koef) != 1 || (_monom.key / 100) ? " * y" : " y");
	else if ((_monom.key % 100) / 10 != 0)
		out << (abs(_monom.koef) != 1 || (_monom.key / 100) ? " * y^" : " y^") << _monom.key % 100 / 10;

	if (_monom.key % 10 == 1)
		out << (abs(_monom.koef) != 1 || (_monom.key / 100) || ((_monom.key % 100) / 10) ? " * z" : " z");
	else if (_monom.key % 10 != 0)
		out << (abs(_monom.koef) != 1 || (_monom.key / 100) || ((_monom.key % 100) / 10) ? " * z^" : " z^") << _monom.key % 10;

	return out;
};
