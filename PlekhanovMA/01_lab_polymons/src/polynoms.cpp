#include "polinom.h"

TPolinom::TPolinom(){}

TPolinom::TPolinom(std::string str)
{
	int x, y, z, l;
	double coef;
	std::string buffstr;
	std::string buffstr2;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != ' ')
		{
			buffstr.push_back(str[i]);
		}
	}
	str = buffstr;
	buffstr.clear();
	for (int i = 0; i < str.length(); i++)
	{
		if (isdigit(str[i]) && isdigit(str[i + 1]))
		{
			while (str[i] != 'x')
			{
				buffstr2.push_back(str[i]);
				buffstr.append(buffstr2);
				buffstr2.clear();
				i++;
			}
			strpolinom.push_back(buffstr);
			buffstr.clear();
		}
		if (isalpha(str[i]) && isalpha(str[i + 1]))
		{
			buffstr.push_back(str[i]);
			strpolinom.push_back(buffstr);
			strpolinom.push_back("1");
			buffstr.clear();
			i++;
		}
		if (str[i] == 'z' && isdigit(str[i + 1]) == 0)
		{
			buffstr.push_back(str[i]);
			strpolinom.push_back(buffstr);
			strpolinom.push_back("1");
			buffstr.clear();
			i++;
		}
		buffstr.push_back(str[i]);
		strpolinom.push_back(buffstr);
		buffstr.clear();
	}
	for (int i = 0; i < strpolinom.size(); i++)
	{
		buffstr = strpolinom[i];
		if (buffstr[0] == '\0')
			strpolinom.pop_back();
	}
	l = 0;
	buffstr = strpolinom[0];
	if (buffstr[0] != '-')
	{
		coef = stod(buffstr);
		l = 1;
	}
	buffstr.clear();
	for (int i = 0 + l; i < strpolinom.size(); i++)
	{
		if (strpolinom[i] == "-" || strpolinom[i] == "+")
		{
			if (strpolinom[i] == "-")
			{
				buffstr = "-";
				buffstr.insert(1, strpolinom[i + 1]);
			}
			else
				buffstr.insert(0, strpolinom[i + 1]);
			coef = stod(buffstr);
			buffstr.clear();
			i = i + 2;
		}
		if (strpolinom[i] == "x")
		{
			buffstr = strpolinom[i + 1];
			x = stoi(buffstr);
			buffstr.clear();
			i = i + 2;
		}
		if (strpolinom[i] == "y")
		{
			buffstr = strpolinom[i + 1];
			y = stoi(buffstr);
			buffstr.clear();
			i = i + 2;
		}
		if (strpolinom[i] == "z")
		{
			buffstr = strpolinom[i + 1];
			z = stoi(buffstr);
			buffstr.clear();
			i = i + 1;
		}
		TMonom* monom = new TMonom(x, y, z, coef);
		polinom.InsertToTail(monom->data);
	}
	TMonom* t = new TMonom();
	TMonom* c = new TMonom();
	int size = polinom.GetLenght();
	for (int i = 0; i < size - 1; i++)
	{
		t->data = polinom.GetCurr()->data;
		c->data = polinom.GetCurr()->data;
		for (int j = i + 1; j < size; j++)
		{
			if (t->data == polinom.GetNext()->data)
			{
				t->data.coeff = t->data.coeff + polinom.GetNext()->data.coeff;
				polinom.Remove(polinom.GetNext()->data);
			}
			polinom.Next();
		}
		polinom.Reset();
		for (int j = 0; j < i; j++)
		{
			polinom.Next();
		}
		if(c->data.coeff != t->data.coeff && c->data.degree == t->data.degree)
		    polinom.GetCurr()->data.coeff = t->data.coeff;
		polinom.Next();
	}
}

TPolinom::TPolinom(const TPolinom& a)
{
	polinom = a.polinom;
	strpolinom = a.strpolinom;
}

TPolinom::~TPolinom(){}

void TPolinom::Sort()
{
	TMonom* tempsearch = new TMonom();
	TMonom* temp = new TMonom(polinom.pHead->data);
	TMonom* tempcurr = new TMonom();
	int size = polinom.GetLenght();
	for (int i = 0; i < size - 1; i++)
	{
		tempcurr->data = polinom.GetCurr()->data;
		for (int j = i + 1; j < size; j++)
		{
			tempsearch->data = polinom.GetNext()->data;
			if (tempsearch->data.degree >= tempcurr->data.degree)
			{
				tempcurr->data = tempsearch->data;
			}
			polinom.Next();
		}
		polinom.Remove(tempcurr->data);
		polinom.InsertAfter(temp->data, tempcurr->data);
		temp->data = tempcurr->data;
		polinom.Reset();
		for(int m = 0; m < i; m++)
		{
			polinom.Next();
		}
		polinom.Next();
	}
}

void TPolinom::Similar()
{
	TMonom* tempcurr = new TMonom;
	TMonom* tempsim = new TMonom;
	polinom.Reset();
	for (int i = 0; i < polinom.GetLenght(); i++)
	{
		if (polinom.GetNext()->data.degree == polinom.GetCurr()->data.degree)
		{
			while (polinom.GetNext()->data.degree == polinom.GetCurr()->data.degree)
			{
				polinom.GetCurr()->data.coeff = polinom.GetCurr()->data.coeff + polinom.GetNext()->data.coeff;
				polinom.Remove(polinom.GetNext()->data);
			}
		}
		polinom.Reset();
		for (int j = 0; j < i; j++)
			polinom.Next();
		polinom.Next();
	}
	TMonom* t = new TMonom();
	TMonom* c = new TMonom();
	int size = polinom.GetLenght();
	for (int i = 0; i < size - 1; i++)
	{
		t->data = polinom.GetCurr()->data;
		c->data = polinom.GetCurr()->data;
		for (int j = i + 1; j < size; j++)
		{
			if (t->data == polinom.GetNext()->data)
			{
				t->data.coeff = t->data.coeff + polinom.GetNext()->data.coeff;
				polinom.Remove(polinom.GetNext()->data);
			}
			polinom.Next();
		}
		polinom.Reset();
		for (int j = 0; j < i; j++)
		{
			polinom.Next();
		}
		if (c->data.coeff != t->data.coeff && c->data.degree == t->data.degree)
			polinom.GetCurr()->data.coeff = t->data.coeff;
		polinom.Next();
	}
	polinom.Reset();
	for (int i = 0; i < polinom.GetLenght(); i++)
	{
		if (polinom.GetCurr()->data.coeff == 0.0f)
		{
			TMonom* temp = new TMonom(polinom.GetCurr()->data);
			polinom.Remove(temp->data);
		}
		polinom.Next();
	}
}

void TPolinom::ClearPol()
{
	polinom.Clear();
}

bool TPolinom::Check()
{
	return(polinom.IsEmpty());
}

 //операции
TPolinom TPolinom::operator+(const TPolinom& a)
{
	TPolinom P(a);
	P.polinom.Reset();
	for (int i = 0; i < P.polinom.GetLenght(); i++)
	{
		TMonom* temp = new TMonom;
		temp->data = P.polinom.GetCurr()->data;
		this->polinom.InsertToTail(temp->data);
		P.polinom.Next();
	}
	Sort();
	Similar();
	return *this;
}

TPolinom TPolinom::operator-(const TPolinom& a)
{
	TPolinom P(a);
	P.polinom.Reset();
	for (int i = 0; i < P.polinom.GetLenght(); i++)
	{
		TMonom* temp = new TMonom;
		temp->data = P.polinom.GetCurr()->data;
		temp->data.coeff = temp->data.coeff * (-1);
		this->polinom.InsertToTail(temp->data);
		P.polinom.Next();
	}
	Sort();
	Similar();
	return *this;
}

TPolinom TPolinom::operator-()
{
	polinom.Reset();
	for (int i = 0; i < polinom.GetLenght(); i++)
	{
		polinom.GetCurr()->data.coeff = polinom.GetCurr()->data.coeff * (-1);
		polinom.Next();
	}
	return *this;
}

TPolinom TPolinom::operator*(const double c)
{
	polinom.Reset();
	for (int i = 0; i < polinom.GetLenght(); i++)
	{
		polinom.GetCurr()->data.coeff = polinom.GetCurr()->data.coeff * c;
		polinom.Next();
	}
	return *this;
}

TPolinom TPolinom::operator/(const double c)
{
	polinom.Reset();
	for (int i = 0; i < polinom.GetLenght(); i++)
	{
		polinom.GetCurr()->data.coeff = polinom.GetCurr()->data.coeff / c;
		polinom.Next();
	}
	return *this;
}

TPolinom TPolinom::operator*(const TPolinom& a)
{
	TPolinom P(a);
	TPolinom M;
	TMonom* temp = new TMonom;
	TMonom* temp2 = new TMonom();
	P.polinom.Reset();
	polinom.Reset();
	int s = polinom.GetLenght();
	for (int i = 0; i < P.polinom.GetLenght(); i++)
	{
		temp->data = P.polinom.GetCurr()->data;
		for (int j = 0; j < s; j++)
		{
			temp2->data = polinom.GetCurr()->data;
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
	TPolinom P(a);
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

double TPolinom::operator()(int x, int y, int z)
{
	double res, m;
	res = 0;
	polinom.Reset();
	for (int i = 0; i < polinom.GetLenght(); i++)
	{
		m = polinom.GetCurr()->data.coeff * pow(x, polinom.GetCurr()->data.degx) * pow(y, polinom.GetCurr()->data.degy) * pow(z, polinom.GetCurr()->data.degz);
		res = res + m;
		polinom.Next();
	}
	return res;
}