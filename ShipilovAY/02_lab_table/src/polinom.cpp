#include "polinom.h"

TPolinom::TPolinom(const std::string& s)
{
	string str = s;
	if (str[0] != '\0')
	{
		while (str.length() > 0)
		{
			string monom = "";
			Monom temp;
			string coeff = "";
			double number = 0;
			int i = 0, j = 1;
			while (j < str.length() && str[j] != '+' && str[j] != '-')
				j++;
			monom = str.substr(0, j);
			str.erase(0, j);
			j = 0;
			while (j < monom.length() && !isalpha(monom[j]))
				j++;
			coeff = monom.substr(0, j);
			if (coeff == "" || coeff == "+")
				temp.coeff = 1;
			else if (coeff == "-")
				temp.coeff = -1;
			else temp.coeff = atof(coeff.c_str());
			monom.erase(0, j);
			j = 0;
			while (j < monom.length())
			{
				if (isalpha(monom[j]) && monom[j + 1] == '\0')
				{
					switch (monom[j])
					{
					case 'x':
						temp.stmonom += 1 * 100;
						break;
					case 'y':

						temp.stmonom += 1 * 10;
						break;
					case 'z':
						temp.stmonom += 1;
						break;
					default:
						throw "Input error:end of string";
						break;
					}
					j++;
				}
				else if (isalpha(monom[j]) && isalpha(monom[j + 1]))
				{
					switch (monom[j])
					{
					case 'x':
						temp.stmonom += 1 * 100;
						break;
					case 'y':

						temp.stmonom += 1 * 10;
						break;
					case 'z':
						temp.stmonom += 1;
						break;
					default:
						throw "Input error:end of string";
						break;
					}
					j++;
				}
				else if (isalpha(monom[j]) && monom[j + 1] == '^' && monom[j + 2] != '\0' && isdigit(monom[j + 2]))
				{
					switch (monom[j])
					{
					case 'x':
						temp.stmonom += atoi(&monom[j + 2]) * 100;
						j += 3;
						break;
					case 'y':
						temp.stmonom += atoi(&monom[j + 2]) * 10;
						j += 3;
						break;
					case 'z':
						temp.stmonom += atoi(&monom[j + 2]) * 1;
						j += 3;
						break;
					}
				}
			}
			if ((temp.stmonom != 0 || temp.stmonom == 0) && temp.coeff != 0) {
				TNode<Monom>* node = curmon.Search(temp);
				if (node != nullptr)
				{
					if (node->data.coeff + temp.coeff != 0)
					{
						node->data.coeff += temp.coeff;
					}
					else curmon.Delete(node->data);
				}
				else
					curmon.Insert(temp);
			}
		}
	}
}

TPolinom::TPolinom(const TPolinom& _polinom)
{
	curmon = _polinom.curmon;
}

TPolinom::~TPolinom()
{
}

TPolinom TPolinom::operator+ (const TPolinom& _polinom)
{
	(*this).curmon.Reset();
	TPolinom copy_polinom(_polinom);
	copy_polinom.curmon.Reset();
	TPolinom res;

	while (!copy_polinom.curmon.IsEnded() && !(*this).curmon.IsEnded())
	{
		if (copy_polinom.curmon.GetCurrent()->data < (*this).curmon.GetCurrent()->data)
		{
			res.curmon.InsertInEnd((*this).curmon.GetCurrent()->data);
			(*this).curmon.GetNext();
		}
		else if (copy_polinom.curmon.GetCurrent()->data > (*this).curmon.GetCurrent()->data)
		{
			res.curmon.InsertInEnd(copy_polinom.curmon.GetCurrent()->data);
			copy_polinom.curmon.GetNext();
		}
		else
		{
			if ((*this).curmon.GetCurrent()->data.coeff + copy_polinom.curmon.GetCurrent()->data.coeff != 0.0)
			{
				res.curmon.InsertInEnd((*this).curmon.GetCurrent()->data + copy_polinom.curmon.GetCurrent()->data);
			}
			(*this).curmon.GetNext();
			copy_polinom.curmon.GetNext();
		}
	}
	while (!copy_polinom.curmon.IsEnded())
	{
		res.curmon.InsertInEnd(copy_polinom.curmon.GetCurrent()->data);
		copy_polinom.curmon.GetNext();
	}
	while (!(*this).curmon.IsEnded())
	{
		res.curmon.InsertInEnd((*this).curmon.GetCurrent()->data);
		(*this).curmon.GetNext();
	}
	return res;
}

TPolinom TPolinom::operator* (const TPolinom& _polinom)
{
	(*this).curmon.Reset();
	TPolinom copy_polinom(_polinom);
	copy_polinom.curmon.Reset();
	TPolinom res;
	res.curmon.Reset();
	for ((*this).curmon.GetCurrent(); !(*this).curmon.IsEnded(); (*this).curmon.GetNext())
	{
		for (copy_polinom.curmon.GetCurrent(); !copy_polinom.curmon.IsEnded(); copy_polinom.curmon.GetNext())
		{
			if (((*this).curmon.GetCurrent()->data.stmonom + copy_polinom.curmon.GetCurrent()->data.stmonom < 1000) &&
				(((*this).curmon.GetCurrent()->data.stmonom / 10 % 10 + copy_polinom.curmon.GetCurrent()->data.stmonom / 10 % 10) < 10) &&
				(((*this).curmon.GetCurrent()->data.stmonom % 10 + copy_polinom.curmon.GetCurrent()->data.stmonom % 10) < 10))
			{
				unsigned int tmpabc = (*this).curmon.GetCurrent()->data.stmonom + copy_polinom.curmon.GetCurrent()->data.stmonom;
				Monom tmp((*this).curmon.GetCurrent()->data.coeff * copy_polinom.curmon.GetCurrent()->data.coeff, tmpabc);
				TNode<Monom>* tmp2 = res.curmon.Search(tmp);
				if (tmp2 != NULL)//если такой моном есть
					if ((tmp2->data.coeff += (*this).curmon.GetCurrent()->data.coeff * copy_polinom.curmon.GetCurrent()->data.coeff) == 0)
					{
						res.curmon.Delete(tmp2->data);
					}
					else tmp2->data.coeff += (*this).curmon.GetCurrent()->data.coeff * copy_polinom.curmon.GetCurrent()->data.coeff;
				else
					res.curmon.Insert(tmp);
			}
			else throw "Power is more then expected";
		}
		copy_polinom.curmon.Reset();
	}
	return res;
}

TPolinom TPolinom::operator* (double d)
{
	TPolinom res = (*this);
	res.curmon.Reset();
	if (d == 0)
		res.curmon.Clean();
	else {
		while (!res.curmon.IsEnded())
		{
			res.curmon.GetCurrent()->data.coeff *= d;
			res.curmon.GetNext();
		}
	}
	return res;
}

TPolinom operator* (double d, const TPolinom& p)
{
	TPolinom res(p);
	res.curmon.Reset();
	if (d == 0)
		res.curmon.Clean();
	else {
		for (res.curmon.GetCurrent(); !res.curmon.IsEnded(); res.curmon.GetNext())
		{
			res.curmon.GetCurrent()->data.coeff *= d;
		}
	}
	return res;
};

TPolinom& TPolinom::operator=(const TPolinom& _polinom)
{
	curmon = _polinom.curmon;
	return *this;
}

ostream& operator<< (ostream& out, const TPolinom& _pol)
{
	TPolinom copy_polinom(_pol);
	copy_polinom.curmon.Reset();
	cout << copy_polinom.curmon.GetCurrent()->data.coeff;
	if ((copy_polinom.curmon.GetCurrent()->data.coeff == 1) && (copy_polinom.curmon.GetCurrent()->data.stmonom / 100 != 0) &&
		(copy_polinom.curmon.GetCurrent()->data.stmonom / 10) % 10 != 0 && (copy_polinom.curmon.GetCurrent()->data.stmonom) % 10 != 0)
		out << copy_polinom.curmon.GetCurrent()->data.coeff;
	if ((copy_polinom.curmon.GetCurrent()->data.stmonom / 100) != 0) {
		if ((copy_polinom.curmon.GetCurrent()->data.stmonom / 100) == 1)
			out << "x";
		else
			out << "x^" << (copy_polinom.curmon.GetCurrent()->data.stmonom / 100);
	}

	if ((copy_polinom.curmon.GetCurrent()->data.stmonom / 10) % 10 != 0) {
		if ((copy_polinom.curmon.GetCurrent()->data.stmonom / 10) % 10 == 1)
			out << "y";
		else out << "y^" << (copy_polinom.curmon.GetCurrent()->data.stmonom / 10) % 10;
	}
	if ((copy_polinom.curmon.GetCurrent()->data.stmonom) % 10 != 0) {
		if ((copy_polinom.curmon.GetCurrent()->data.stmonom % 10) == 1)
			out << "z";
		else out << "z^" << (copy_polinom.curmon.GetCurrent()->data.stmonom) % 10;
	}
	TNode<Monom>* cur = copy_polinom.curmon.GetNext();
	for (cur; !copy_polinom.curmon.IsEnded(); copy_polinom.curmon.GetNext())
	{
		if (copy_polinom.curmon.GetCurrent()->data.coeff > 0)
		{
			out << " + " << copy_polinom.curmon.GetCurrent()->data.coeff;
		}
		else out << " " << copy_polinom.curmon.GetCurrent()->data.coeff;
		if ((copy_polinom.curmon.GetCurrent()->data.stmonom / 100) != 0) {
			if ((copy_polinom.curmon.GetCurrent()->data.stmonom / 100) == 1)
				out << "x";
			else
				out << "x^" << (copy_polinom.curmon.GetCurrent()->data.stmonom / 100);
		}

		if ((copy_polinom.curmon.GetCurrent()->data.stmonom / 10) % 10 != 0)
		{
			if ((copy_polinom.curmon.GetCurrent()->data.stmonom / 10) % 10 == 1)
				out << "y";
			else out << "y^" << (copy_polinom.curmon.GetCurrent()->data.stmonom / 10) % 10;
		}
		if ((copy_polinom.curmon.GetCurrent()->data.stmonom) % 10 != 0) {
			if ((copy_polinom.curmon.GetCurrent()->data.stmonom % 10) == 1)
				out << "z";
			else out << "z^" << (copy_polinom.curmon.GetCurrent()->data.stmonom) % 10;
		}
	}
	out << endl;
	return out;
}

double TPolinom::operator()(double x, double y, double z)
{
	double res = 0;

	for (this->curmon.GetNext(); !this->curmon.IsEnded(); this->curmon.GetNext())
	{
		if (this->curmon.GetCurrent()->data.coeff > 0)
		{
			res = res + (this->curmon.GetCurrent()->data.coeff) *
				(pow(x, (this->curmon.GetCurrent()->data.stmonom / 100))) *
				(pow(y, ((this->curmon.GetCurrent()->data.stmonom / 10) % 10))) *
				(pow(z, ((this->curmon.GetCurrent()->data.stmonom) % 10)));
		}
	}
	return res;
}