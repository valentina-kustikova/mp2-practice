#include <tpolynom.h>


TPolynom::TPolynom()
{
	;
}

TPolynom::TPolynom(const string& name)
{
	if (name[0] == '\0')
		throw std::exception("invalid string");
	string tmpstr = name;
	string strmonom = "";
	TMonom tmpmonom;
	int flag = 0;
	double tmpcoeff = 1;
	int tmpdegree = 0;
	for (int i = 0; i < tmpstr.length(); i++)
	{
		if (i == 0 && tmpstr[i] == '+')
			continue;
		if (i == 0 && tmpstr[i] == '-')
		{
			flag++;
			continue;
		}
		if (tmpstr[i] != '+' && tmpstr[i] != '-' )
		{
			strmonom += tmpstr[i];
			if(i != tmpstr.length()-1)
				continue;
		}
		tmpmonom = TMonom(strmonom);
		if (tmpstr[i] == '-')
			flag++;
		if (flag > 0)
		{
			tmpmonom.SetCoeff((-1) * tmpmonom.GetCoeff());
		}
		strmonom = "";
		flag = 0;
		monoms.InsertLast(tmpmonom);
	}
	update();
}

TPolynom::TPolynom(const TRingList<TMonom> monoms)
{
	this->monoms = monoms;
	update();
}

TPolynom::TPolynom(const TPolynom& p)
{
	*this = p;
}

void TPolynom::update()
{
	monoms.Sort();
	monoms.Reset();
	while (!monoms.IsEmpty() && !monoms.IsEnd())
	{
		TNode<TMonom>* i = monoms.getpC();
		TNode<TMonom>* j = i->pNext;
		if (j != monoms.getpS() && i->data.GetDegree() == j->data.GetDegree())
		{

			i->data = i->data + j->data;
			i->pNext = j->pNext;
			delete j;
		}
		else
		{
			monoms.Next();
		}
	}
	monoms.Reset();
	TNode<TMonom>* current = monoms.getpC();
	while (!monoms.IsEmpty() && !monoms.IsEnd())
	{
		if (monoms.getpC()->data.GetCoeff() == 0.0)
		{
			monoms.DeleteCurrent();
		}
		else {
			monoms.Next();
		}
	}
	monoms.Reset();
}

const TPolynom& TPolynom::operator=(const TPolynom& polynom)
{
	this->monoms = polynom.monoms;
	return *this;
}

TPolynom TPolynom::operator+(const TPolynom& polynom)
{
	TPolynom tmp(polynom);
	while (!tmp.monoms.IsEnd() && !tmp.monoms.IsEmpty())
	{
		monoms.InsertLast(tmp.monoms.getpC()->data);
		tmp.monoms.Next();
	}
	update();
	return *this;
}

TPolynom TPolynom::operator-(const TPolynom& polynom)
{
	TPolynom tmp(polynom);
	*this = *this + tmp * (-1);
	update();
	return *this;
}

TPolynom TPolynom::operator*(const double c)
{
	monoms.Reset();
	while (!monoms.IsEnd())
	{
		monoms.getpC()->data.SetCoeff(monoms.getpC()->data.GetCoeff() * c);
		monoms.Next();
	}
	monoms.Reset();
	return *this;
}

TPolynom TPolynom::operator*(const TPolynom& polynom)
{
	if (polynom.monoms.IsEmpty())
		return polynom;
	TPolynom tmp(polynom);
	monoms.Reset();
	while (!monoms.IsEnd())
	{
		while (!tmp.monoms.IsEnd())
		{
			if (monoms.get_pCurr().GetDegree() == tmp.monoms.get_pCurr().GetDegree())
			{
				monoms.getpC()->data = monoms.getpC()->data * tmp.monoms.getpC()->data;
			}
			tmp.monoms.Next();
		}
		monoms.Next();
	}
	update();
	return *this;
}

TPolynom TPolynom::dif()const
{
	TPolynom tmp(*this);
	tmp = tmp.dif_x();
	tmp = tmp.dif_y();
	tmp =tmp.dif_z();
	tmp.update();
	return tmp;
}


TPolynom TPolynom::dif_x()const
{
	TPolynom tmp(monoms);
	TPolynom newp;
	TMonom tp;
	while (!tmp.monoms.IsEnd())
	{
		tp = tmp.monoms.getpC()->data.def_X();
		newp.monoms.InsertLast(tp);
		tmp.monoms.Next();
	}
	return newp;
}
TPolynom TPolynom::dif_y()const
{
	TPolynom tmp(monoms);
	TPolynom newp;
	TMonom tp;
	while (!tmp.monoms.IsEnd())
	{
		tp = tmp.monoms.getpC()->data.def_Y();
		newp.monoms.InsertLast(tp);
		tmp.monoms.Next();
	}
	return newp;
}
TPolynom TPolynom::dif_z()const
{
	TPolynom tmp(monoms);
	TPolynom newp;
	TMonom tp;
	while (!tmp.monoms.IsEnd())
	{
		tp = tmp.monoms.getpC()->data.def_Z();
		newp.monoms.InsertLast(tp);
		tmp.monoms.Next();
	}
	return newp;
}

double TPolynom::operator()(double x, double y, double z)const
{
	TPolynom tmp(*this);
	double res = 0;
	while (!tmp.monoms.IsEnd())
	{
		res += tmp.monoms.getpC()->data.calculate(x, y, z);
		tmp.monoms.Next();
	}
	return res;
}
ostream& operator<< (ostream& out, const TPolynom& polynom)
{
	TPolynom tmppolynom(polynom);
	tmppolynom.update();
	TMonom tmpmonom;
	int flag = 0;
	while (!tmppolynom.monoms.IsEnd())
	{
		tmpmonom = tmppolynom.monoms.get_pCurr();
		if (tmpmonom.GetDegree() == 0)
			return out << tmpmonom.GetCoeff();
		if (tmpmonom.GetCoeff() > 0 && flag != 0)
			out << "+";
		out << tmpmonom.GetCoeff();
		if (tmpmonom.GetDegree() / 100 > 0)
		{
			out << "*x^" << tmpmonom.GetDegree() / 100;
		}
		if ((tmpmonom.GetDegree() % 100) / 10 > 0)
		{
			out << "*y^" << (tmpmonom.GetDegree() % 100) / 10;
		}
		if (tmpmonom.GetDegree() % 10 > 0)
		{
			out << "*z^" << tmpmonom.GetDegree() % 10;
		}
		flag++;
		tmppolynom.monoms.Next();
	}
	out << endl;
	return out;
}