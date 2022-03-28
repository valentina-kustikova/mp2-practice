#include "polinom.h"

TPolinom::TPolinom(){}

TPolinom::TPolinom(TList polinom)
{
	this->polinom = polinom;
}

TPolinom::TPolinom(const TPolinom& a)
{
	polinom = a.polinom;
}

TPolinom::~TPolinom(){}

void TPolinom::Input(std::string& str)
{
	std::string buffstr;
	std::string buffstr2;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != ' ')
		{
			if (i + 1 <= str.length())
			{
				if (isdigit(str[i]) && isalpha(str[i + 1]) == 0)
				{
					while (isdigit(str[i]) && isalpha(str[i + 1]) == 0)
					{
						buffstr2.push_back(str[i]);
						i = i + 1;
					}
					if (i + 1 <= str.length())
					{
						buffstr2.push_back(str[i]);
						i = i + 1;
						strpolinom.push_back(buffstr2);
					}
				}
				buffstr2.clear();
			}
			buffstr = str[i];
		    strpolinom.push_back(buffstr);
			buffstr.clear();
		}
	}
	buffstr2.clear();
	strpolinom.pop_back();
	int m = str.length() - 1;
	buffstr2 = str[m];
 	strpolinom.push_back(buffstr2);
}

void TPolinom::StrToList()
{
	int degx, degy, degz;
	double firstcoeff, coeff;

	std::string temp;
	temp = strpolinom[0];
	char buff = temp[0];
	temp.clear();
	if (buff == '-')
	{
		temp = "-";
		temp.insert(1, strpolinom[1]);
		firstcoeff = stod(temp);
		temp.clear();
	}
	else
	{
		temp.insert(0, strpolinom[0]);
		firstcoeff = stod(temp);
		temp.clear();
	}
	for (int i = 1; i < 7; i++)
	{
		if (strpolinom[i] == "x")
		{
			degx = stoi(strpolinom[i + 1]);
			i = i + 2;
		}
		if (strpolinom[i] == "y")
		{
			degy = stoi(strpolinom[i + 1]);
			i = i + 2;
		}
		if (strpolinom[i] == "z")
		{
			degz = stoi(strpolinom[i + 1]);
			i = i + 1;
		}
	}
	TMonom* monomfirst = new TMonom(degx, degy, degz, firstcoeff);
	polinom.InsertToTail(monomfirst->data);
	for (int i = 3; i < strpolinom.size(); i++)
	{
		if (strpolinom[i] == "+" || strpolinom[i] == "-")
		{
			if (strpolinom[i] == "+")
			{
				coeff = stod(strpolinom[i + 1]);
				i = i + 2;
			}
			if (strpolinom[i] == "-")
			{
				coeff = -1 * stod(strpolinom[i + 1]);
				i = i + 2;
			}
			if (strpolinom[i] == "x")
			{
				degx = stoi(strpolinom[i + 1]);
				i = i + 2;
			}
			if (strpolinom[i] == "y")
			{
				degy = stoi(strpolinom[i + 1]);
				i = i + 2;
			}
			if (strpolinom[i] == "z")
			{
				degz = stoi(strpolinom[i + 1]);
				i = i + 1;
			}
			TMonom* monom = new TMonom(degx, degy, degz, coeff);
			polinom.InsertToTail(monom->data);
		}
	}
}

void TPolinom::Similar()
{
	TMonom* nullmonom = new TMonom(-2, -2, -2, 0);
	polinom.Reset();
	TMonom* tempcurr = new TMonom;
	tempcurr = polinom.GetMonom();
	TMonom* tempcomp = new TMonom;
	TMonom* tempsum = new TMonom;
	for (int i = 0; i < polinom.GetLenght(); i++)
	{
		tempsum = polinom.GetMonom();
		while (tempcomp->data.degree != nullmonom->data.degree)
		{
			tempcomp = polinom.SearchSimilar(tempsum->data);
			if (tempcomp->data.degree != nullmonom->data.degree)
			{
				tempsum->data.coeff = tempsum->data.coeff + tempcomp->data.coeff;
				polinom.Remove(tempcomp);
				tempcomp = tempcurr;
			}
		}
		tempcomp = tempcurr;
		polinom.Next();
	}
	polinom.Reset();
	for (int j = 0; j < polinom.GetLenght(); j++)
	{
		TMonom* monom = new TMonom;
		monom = polinom.GetMonom();
		TMonom* monomnext = new TMonom;
		monomnext = polinom.GetNextMonom();
		if (monom->data.coeff == 0.0f)
		{
			polinom.Remove(monom);
		}
		if (polinom.GetMonom()->data != monomnext->data)
		{
			polinom.Next();
		}
	}
	polinom.Reset();
	if (polinom.GetMonom()->data.coeff == 0.0f)
	{
		polinom.Next();
		polinom.RemoveFirst();
	}
}

void TPolinom::ClearPol()
{
	polinom.Clear();
}

 //операции
TPolinom TPolinom::operator+(const TPolinom& a)
{
	TPolinom P(a);
	P.polinom.Reset();
	for (int i = 0; i < P.polinom.GetLenght(); i++)
	{
		TMonom* temp = new TMonom;
		temp = P.polinom.GetMonom();
		this->polinom.InsertToTail(temp->data);
		P.polinom.Next();
	}
	return *this;
}

TPolinom TPolinom::operator-(const TPolinom& a)
{
	TPolinom P(a);
	P.polinom.Reset();
	for (int i = 0; i < P.polinom.GetLenght(); i++)
	{
		TMonom* temp = new TMonom;
		temp = P.polinom.GetMonom();
		temp->data.coeff = temp->data.coeff * (-1);
		this->polinom.InsertToTail(temp->data);
		P.polinom.Next();
	}
	return *this;
}

TPolinom TPolinom::operator-()
{
	polinom.Reset();
	for (int i = 0; i < polinom.GetLenght(); i++)
	{
		TMonom* temp = new TMonom;
		temp = polinom.GetMonom();
		temp->data.coeff = temp->data.coeff * (-1);
		polinom.Next();
	}
	return *this;
}

TPolinom TPolinom::operator*(const double c)
{
	polinom.Reset();
	for (int i = 0; i < polinom.GetLenght(); i++)
	{
		TMonom* temp = new TMonom;
		temp = polinom.GetMonom();
		temp->data.coeff = temp->data.coeff * c;
		polinom.Next();
	}
	return *this;
}

TPolinom TPolinom::operator*(const TPolinom& a)
{
	TPolinom P(a.polinom);
	TPolinom M;
	TMonom* temp = new TMonom;
	P.polinom.Reset();
	int s = polinom.GetLenght();
	for (int i = 0; i < P.polinom.GetLenght(); i++)
	{
		temp = P.polinom.GetMonom();
		for (int j = 0; j < s; j++)
		{
			TMonom* temp2 = new TMonom(polinom.GetMonom()->data);
			temp2->data.coeff = temp2->data.coeff * temp->data.coeff;
			temp2->data.degx = temp2->data.degx * temp->data.degx;
			temp2->data.degy = temp2->data.degy * temp->data.degy;
			temp2->data.degz = temp2->data.degz * temp->data.degz;
			temp2->data.degree = temp2->data.degx * 100 + temp2->data.degy * 10 + temp2->data.degz;
			M.polinom.InsertToTail(temp2->data);
			polinom.Next();
		}
		polinom.Reset();
		P.polinom.Next();
	}
	return M;
}

TPolinom& TPolinom::operator=(const TPolinom& a)
{
	TPolinom P(a.polinom);
	if (a.polinom.GetLenght() > 1)
	{
		this->polinom = P.polinom;
		return *this;
	}
	else
		return *this;
}

int TPolinom::operator==(const TPolinom& a) const
{
	return(polinom == a.polinom);
}

double TPolinom::Values(int x, int y, int z)
{
	double res, m;
	res = 0;
	polinom.Reset();
	for (int i = 0; i < polinom.GetLenght(); i++)
	{
		m = polinom.GetMonom()->data.coeff * pow(x, polinom.GetMonom()->data.degx) * pow(y, polinom.GetMonom()->data.degy) * pow(z, polinom.GetMonom()->data.degz);
		res = res + m;
		polinom.Next();
	}
	return res;
}

// служебные методы
std::vector<std::string> TPolinom::LookPolinom()
{
	return strpolinom;
}

TPolinom TPolinom::Razd(const double c)
{
	polinom.Reset();
	for (int i = 0; i < polinom.GetLenght(); i++)
	{
		TMonom* temp = new TMonom;
		temp = polinom.GetMonom();
		temp->data.coeff = temp->data.coeff / c;
		polinom.Next();
	}
	return *this;
}