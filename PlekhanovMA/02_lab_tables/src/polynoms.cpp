#include "polinom.h"

TPolinom::TPolinom(){}

TPolinom::TPolinom(const std::string& string)
{
	int x, y, z, l;
	double coef;
	std::string str;
	std::string buffstr;
	std::string buffstr2;
	for (int i = 0; i < string.length(); i++)
	{
		if (string[i] != ' ')
		{
			str.push_back(string[i]);
		}
	}
	l = 0;
	if (str[0] == '-')
	{
		buffstr = str[0];
		strpolinom.push_back(buffstr);
		buffstr.clear();
		l++;
	}

	while (l < str.length())
	{
		while (isdigit(str[l]))
		{
			buffstr.push_back(str[l]);
			l++;
		}
		if (buffstr.empty() == 0)
		{
			strpolinom.push_back(buffstr);
			buffstr.clear();
		}
		if (l < str.length())
		{
			buffstr.push_back(str[l]);
			strpolinom.push_back(buffstr);
			buffstr.clear();
			l++;
		}
	}

	for (int i = 0; i < strpolinom.size(); i++)
	{
		x = 0;
		y = 0;
		z = 0;
		coef = 1;
		while (i < strpolinom.size() && strpolinom[i] != "-" && strpolinom[i] != "+")
		{
			if (i == 0 && isdigit(strpolinom[i][0]))
			{
				coef = stod(strpolinom[i]);
				i++;
			}
			if (i > 0 && i < strpolinom.size() && isdigit(strpolinom[i][0]) && isalpha(strpolinom[i - 1][0]) == 0)
			{
				coef = stod(strpolinom[i]);
				if (strpolinom[i - 1][0] == '-')
					coef = coef * (-1);
				i++;
			}
			if (i > 0 && strpolinom[i - 1][0] == '-')
				coef = coef * (-1);
			if (i < strpolinom.size() && i + 1 <= strpolinom.size() && strpolinom[i][0] == 'x')
			{
				if (i + 1 < strpolinom.size() && isdigit(strpolinom[i + 1][0]))
				{
					x = stoi(strpolinom[i + 1]);
					i = i + 2;
				}
				else
				{
					x = 1;
					i++;
				}
			}
			if (i < strpolinom.size() && i + 1 <= strpolinom.size() && strpolinom[i][0] == 'y')
			{
				if (i + 1 < strpolinom.size() && isdigit(strpolinom[i + 1][0]))
				{
					y = stoi(strpolinom[i + 1]);
					i = i + 2;
				}
				else
				{
					y = 1;
					i++;
				}
			}
			if (i < strpolinom.size() && i + 1 <= strpolinom.size() && strpolinom[i][0] == 'z')
			{
				if (i + 1 < strpolinom.size() && isdigit(strpolinom[i + 1][0]))
				{
					z = stoi(strpolinom[i + 1]);
					i = i + 2;
				}
				else
				{

					z = 1;
					i++;
				}
			}
			if (i < strpolinom.size() && strpolinom[i][0] == 'x')
			{
				x = 1;
				i++;
			}
			if (i < strpolinom.size() && strpolinom[i][0] == 'y')
			{
				y = 1;
				i++;
			}
			if (i < strpolinom.size() && strpolinom[i][0] == 'z')
			{
				z = 1;
				i++;
			}
			TMonom* monom = new TMonom(x, y, z, coef);
			polinom.InsertToTail(monom->data);
		}
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
				t->data->coeff = t->data->coeff + polinom.GetNext()->data->coeff;
				polinom.Remove(polinom.GetNext()->data);
			}
			polinom.Next();
		}
		polinom.Reset();
		for (int j = 0; j < i; j++)
		{
			polinom.Next();
		}
		if (c->data->coeff != t->data->coeff && c->data->degree == t->data->degree)
			polinom.GetCurr()->data->coeff = t->data->coeff;
		polinom.Next();
	}
	Sort();
	Similar();
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
	polinom.Reset();
	for (int i = 0; i < size - 1; i++)
	{
		tempcurr->data = polinom.GetCurr()->data;
		for (int j = i + 1; j < size; j++)
		{
			tempsearch->data = polinom.GetNext()->data;
			if (tempsearch->data->degree >= tempcurr->data->degree)
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
		if (polinom.GetNext()->data->degree == polinom.GetCurr()->data->degree)
		{
			while (polinom.GetNext()->data->degree == polinom.GetCurr()->data->degree)
			{
				polinom.GetCurr()->data->coeff = polinom.GetCurr()->data->coeff + polinom.GetNext()->data->coeff;
				polinom.Remove(polinom.GetNext()->data);
			}
		}
		polinom.Reset();
		for (int j = 0; j < i; j++)
			polinom.Next();
		polinom.Next();
	}
	int size = polinom.GetLenght();
	for (int i = 0; i < size - 1; i++)
	{
		TMonom* t = new TMonom();
		TMonom* c = new TMonom();
		t->data = polinom.GetCurr()->data;
		c->data = polinom.GetCurr()->data;
		for (int j = i + 1; j < size; j++)
		{
			if (t->data->degree == polinom.GetNext()->data->degree && t->data->coeff == polinom.GetNext()->data->coeff)
			{
				t->data->coeff = t->data->coeff + polinom.GetNext()->data->coeff;
				polinom.Remove(polinom.GetNext()->data);
			}
			polinom.Next();
		}
		polinom.Reset();
		for (int j = 0; j < i; j++)
		{
			polinom.Next();
		}
		if (c->data->coeff != t->data->coeff && c->data->degree == t->data->degree)
			polinom.GetCurr()->data->coeff = t->data->coeff;
		polinom.Next();
	}
	polinom.Reset();
	for (int i = 0; i < polinom.GetLenght(); i++)
	{
		if (polinom.GetCurr()->data->coeff == 0.0f)
		{
			polinom.Remove(polinom.GetCurr()->data);
			i--;
		}
		else
		{
			polinom.Next();
		}
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
		TData* temp = new TData;
		temp->coeff = P.polinom.GetCurr()->data->coeff;
		temp->degree = P.polinom.GetCurr()->data->degree;
		temp->degx = P.polinom.GetCurr()->data->degx;
		temp->degy = P.polinom.GetCurr()->data->degy;
		temp->degz = P.polinom.GetCurr()->data->degz;
		this->polinom.InsertToTail(temp);
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
		TData* temp = new TData;
		temp->coeff = (-1) * P.polinom.GetCurr()->data->coeff;
		temp->degree = P.polinom.GetCurr()->data->degree;
		temp->degx = P.polinom.GetCurr()->data->degx;
		temp->degy = P.polinom.GetCurr()->data->degy;
		temp->degz = P.polinom.GetCurr()->data->degz;
		this->polinom.InsertToTail(temp);
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
		polinom.GetCurr()->data->coeff = polinom.GetCurr()->data->coeff * (-1);
		polinom.Next();
	}
	return *this;
}

TPolinom TPolinom::operator*(const double c)
{
	polinom.Reset();
	for (int i = 0; i < polinom.GetLenght(); i++)
	{
		polinom.GetCurr()->data->coeff = polinom.GetCurr()->data->coeff * c;
		polinom.Next();
	}
	return *this;
}

TPolinom TPolinom::operator/(const double c)
{
	polinom.Reset();
	for (int i = 0; i < polinom.GetLenght(); i++)
	{
		polinom.GetCurr()->data->coeff = polinom.GetCurr()->data->coeff / c;
		polinom.Next();
	}
	return *this;
}

TPolinom TPolinom::operator*(const TPolinom& a)
{
	TPolinom P(a);
	TPolinom M;
	P.polinom.Reset();
	polinom.Reset();
	int s = polinom.GetLenght();
	for (int i = 0; i < P.polinom.GetLenght(); i++)
	{
		TData* temp = new TData;
		temp->coeff = P.polinom.GetCurr()->data->coeff;
		temp->degree = P.polinom.GetCurr()->data->degree;
		temp->degx = P.polinom.GetCurr()->data->degx;
		temp->degy = P.polinom.GetCurr()->data->degy;
		temp->degz = P.polinom.GetCurr()->data->degz;
		for (int j = 0; j < s; j++)
		{
			TData* temp2 = new TData();
			temp2->coeff = polinom.GetCurr()->data->coeff;
			temp2->degree = polinom.GetCurr()->data->degree;
			temp2->degx = polinom.GetCurr()->data->degx;
			temp2->degy = polinom.GetCurr()->data->degy;
			temp2->degz = polinom.GetCurr()->data->degz;
			temp2->coeff = temp2->coeff * temp->coeff;
			temp2->degx = temp2->degx + temp->degx;
			temp2->degy = temp2->degy + temp->degy;
			temp2->degz = temp2->degz + temp->degz;
			temp2->degree = temp2->degx * 100 + temp2->degy * 10 + temp2->degz;
			M.polinom.InsertToTail(temp2);
			polinom.Next();
		}
		polinom.Reset();
		P.polinom.Next();
	}
	M.Sort();
	M.Similar();
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

const double TPolinom::operator()(double x, double y, double z)
{
	double res, m;
	res = 0;
	polinom.Reset();
	for (int i = 0; i < polinom.GetLenght(); i++)
	{
		TData* temp = new TData;
		temp->coeff = polinom.GetCurr()->data->coeff;
		temp->degree = polinom.GetCurr()->data->degree;
		temp->degx = polinom.GetCurr()->data->degx;
		temp->degy = polinom.GetCurr()->data->degy;
		temp->degz = polinom.GetCurr()->data->degz;
		m = temp->coeff * pow(x, temp->degx) * pow(y, temp->degy) * pow(z, temp->degz);
		res = res + m;
		polinom.Next();
	}
	return res;
}

std::ostream& operator<<(std::ostream& out,
	const TPolinom& polinom)
{
	{
		TPolinom P(polinom);
		P.polinom.Reset();
		if (P.polinom.IsEmpty() == 1)
			out << 0;
		else
		{
			TMonom* monomf = new TMonom;
			monomf->data = P.polinom.GetCurr()->data;
			if (monomf->data->coeff < 0)
				out << "-" << monomf->data->coeff * -1;
			else
				out << monomf->data->coeff;
			if (monomf->data->degx != 0)
			    out << "x^" << monomf->data->degx;
			if (monomf->data->degy != 0)
			    out << "y^" << monomf->data->degy;
			if (monomf->data->degz != 0)
			    out << "z^" << monomf->data->degz;
			P.polinom.Next();
			for (int i = 1; i < P.polinom.GetLenght(); i++)
			{
				TMonom* monom = new TMonom;
				monom->data = P.polinom.GetCurr()->data;
				if (monom->data->coeff > 0)
					out << " + " << monom->data->coeff;
				else
					out << " - " << monom->data->coeff * -1;
				if(monom->data->degx != 0)
				    out << "x^" << monom->data->degx;
				if (monom->data->degy != 0)
				    out << "y^" << monom->data->degy;
				if (monom->data->degz != 0)
				    out << "z^" << monom->data->degz;
				P.polinom.Next();
			}
		}
		return out;
	}
}