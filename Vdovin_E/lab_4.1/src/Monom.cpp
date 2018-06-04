#include "Monom.h"

double monom::rank_number(const double a, const int i)
{
	double b = 1;
	for (int j = 0; j < i; j++)
		b *= a;
	return b;
}

double monom::converter_in_number(const string & s)
{
	int len = s.length();
	double a = 0.0;
	int i = 0;
	for (i = 0; ((i < len) && (s[i] != '.')); i++)
		a = a * 10.0 + (s[i] - '0');
	int j = i;
	if (s[j] == '.')
		for (i = j + 1; i < len; i++)
			a = a + (s[i] - '0') / (rank_number(10.0, (i - j)));
	return a;
}

monom monom::converter_in_monom(const string & s)
{
	monom m;
	string c = s + ' ';
	string cof;
	bool f = true;
	int i, k = 1;
	if (c[0] == '-')
	{
		k = -1;
		c.erase(0, 1);
	}
	int len = c.length();
	for (i = 0; f; i++)
	{
		if (((c[i] >= '0') && (c[i] <= '9')) || (c[i] == '.'))
			cof = cof + c[i];
		else
		{
			f = false;
			if (cof != "")
				m.coeff = k * converter_in_number(cof);
			else
				m.coeff = k;
		}
	}
	for (int j = i - 1; j < len; j++)
	{
		if (c[j] == 'x')
		{
			if ((c[j + 1] >= '0') && (c[j + 1] <= '9'))
			{
				m.xyz += 100 * (c[j + 1] - '0');
				j++;
			}
			else
				m.xyz += 100;

		}
		else
			if (c[j] == 'y')
			{
				if ((c[j + 1] >= '0') && (c[j + 1] <= '9'))
				{
					m.xyz += 10 * (c[j + 1] - '0');
					j++;
				}
				else
					m.xyz += 10;
			}
			else
				if (c[j] == 'z')
					if ((c[j + 1] >= '0') && (c[j + 1] <= '9'))
					{
						m.xyz += (c[j + 1] - '0');
						j++;
					}
					else
						m.xyz += 1;
	}
	return m;
}

monom::monom(const double c, const unsigned int w)
{
	coeff = c;
	xyz = w;
}

monom::monom(const monom & m)
{
	coeff = m.coeff;
	xyz = m.xyz;
}

monom::monom(const string & s)
{
	*this = converter_in_monom(s);
}

const monom & monom::operator=(const monom & m)
{
	coeff = m.coeff;
	xyz = m.xyz;
	return *this;
}

bool monom::operator==(const monom & m) const
{
	return (xyz == m.xyz);
}

bool monom::operator!=(const monom & m) const
{
	return (xyz != m.xyz);
}

bool monom::operator<(const monom & m) const
{
	return (xyz < m.xyz);
}

bool monom::operator>(const monom & m) const
{
	return (xyz > m.xyz);
}

monom monom::operator*(const double d) const
{
	monom m(coeff * d, xyz);
	return m;
}

monom monom::operator*(const monom & m) const
{
	if (xyz + m.xyz > 999)
		throw "You can't multiply";
	else
	{
		monom mon(coeff * m.coeff, xyz + m.xyz);
		return mon;
	}
}