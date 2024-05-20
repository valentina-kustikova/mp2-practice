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
	std::string::iterator end_pos = std::remove(tmpstr.begin(), tmpstr.end(), ' ');
	tmpstr.erase(end_pos, tmpstr.end());
	string strmonom = "";
	TMonom tmpmonom;
	int flag = 0;
	double tmpcoeff = 1;
	int tmpdegree = 0;
	for (int i = 0; i < tmpstr.length(); i++)
	{
		if (i == 0 && tmpstr[i] == '+')
			continue;
		if (strmonom == "" && tmpstr[i] == '-')
		{
			flag++;
			continue;
		}
		if(i != 0)
			if (tmpstr[i-1] == '-')
				flag++;
		if (tmpstr[i] != '+' && tmpstr[i] != '-' )
		{
			strmonom += tmpstr[i];
			if(i != tmpstr.length()-1)
				continue;
		}
		tmpmonom = TMonom(strmonom);
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
	updatenull();
	updatename();
}

void TPolynom::updatenull()
{
	monoms.Reset();
	int flag = 0;
	while (!monoms.IsEmpty() && !monoms.IsEnd())
	{
		flag = 0;
		if (monoms.get_pCurr().GetCoeff() == 0.0)
		{
			monoms.DeleteCurrent();
			flag++;
		}
		if (flag == 0)
			monoms.Next();
	}
	monoms.Reset();
}

void TPolynom::updatename()
{
	string tmpname = "";
	TMonom tmpmonom;
	int flag = 0;
	while (!monoms.IsEnd())
	{
		tmpmonom = monoms.get_pCurr();
		if (tmpmonom.GetDegree() == 0)
		{
			name = to_string(tmpmonom.GetCoeff());
			return;
		}
		if (tmpmonom.GetCoeff() > 0 && flag != 0)
			tmpname +=  "+";
		tmpname += to_string(tmpmonom.GetCoeff());
		if (tmpmonom.GetDegree() / 100 > 0)
		{
			tmpname+=  "*x^" + to_string(tmpmonom.GetDegree() / 100);
		}
		if ((tmpmonom.GetDegree() % 100) / 10 > 0)
		{
			tmpname +=  "*y^" + to_string((tmpmonom.GetDegree() % 100) / 10);
		}
		if (tmpmonom.GetDegree() % 10 > 0)
		{
			tmpname += "*z^" + to_string(tmpmonom.GetDegree() % 10);
		}
		flag++;
		monoms.Next();
	}
	name = tmpname;
	monoms.Reset();
}

const TPolynom& TPolynom::operator=(const TPolynom& polynom)
{
	this->monoms = polynom.monoms;
	this->name = polynom.name;
	return *this;
}

void TPolynom::InsertSort(const TMonom& m)
{
	monoms.Reset();
	while (monoms.get_pCurr() < m && !monoms.IsEnd())
		monoms.Next();
	if (monoms.get_pCurr().GetDegree() == m.GetDegree())
	{
		monoms.getpC()->data.SetCoeff(monoms.get_pCurr().GetCoeff() + m.GetCoeff());
		return;
	}
	monoms.InsertBeforeCurrent(m);
	monoms.Reset();
}

TPolynom TPolynom::operator+(const TPolynom& polynom)
{
	TPolynom tmp(polynom);
	while (!tmp.monoms.IsEnd() && !tmp.monoms.IsEmpty())
	{
		if(tmp.monoms.get_pCurr().GetCoeff() != 0)
			InsertSort(tmp.monoms.get_pCurr());
		tmp.monoms.Next();
	}
	monoms.Reset();
	updatenull();
	return *this;
}

TPolynom TPolynom::operator-(const TPolynom& polynom)
{
	TPolynom tmp(polynom);
	*this = *this + tmp * (-1);
	return *this;
}

TPolynom TPolynom::operator*(const double c)
{
	if (c == 0)
	{
		return TPolynom();
	}
	monoms.Reset();
	while (!monoms.IsEnd())
	{
		monoms.getpC()->data.SetCoeff(monoms.getpC()->data.GetCoeff() * c);
		monoms.Next();
	}
	monoms.Reset();
	updatename();
	return *this;
}

TPolynom TPolynom::operator*(const TPolynom& polynom)
{
	if (polynom.monoms.IsEmpty())
		return polynom;
	TPolynom tmp(polynom);
	TRingList<TMonom> tmplist;
	monoms.Reset();
	while (!monoms.IsEnd())
	{
		tmp.monoms.Reset();
		while (!tmp.monoms.IsEnd())
		{
			tmplist.InsertLast(monoms.getpC()->data * tmp.monoms.getpC()->data);
			tmp.monoms.Next();
		}
		monoms.Next();
	}
	monoms = tmplist;
	updatename();
	return *this;
}

TPolynom TPolynom::dif()const
{
	TPolynom tmp(*this);
	tmp = tmp.dif_x();
	tmp = tmp.dif_y();
	tmp =tmp.dif_z();
	tmp.updatenull();
	tmp.updatename();
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
		res += tmp.monoms.getpC()->data(x, y, z);
		tmp.monoms.Next();
	}
	return res;
}
