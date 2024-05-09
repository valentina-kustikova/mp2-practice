#include "tpolynom.h"
#include <iostream>
#include <sstream>
using namespace std;


void TPolynom::del_zeros()
{
	int was = 0;
	monoms.start();
	TNode<TMonom>* t = monoms.get_curr();
	if (t == nullptr)
	{
		return;
	}
	while (t->value != TMonom())
	{
		if (t->value.get_coef() != 0)
		{
			was = 1;
			break;
		}
		t = t->next;
	}
	t = monoms.get_curr();
	if (was == 1)
	{
		while (t->value != TMonom())
		{
			if (t->value.get_coef() == 0)
			{
				TNode<TMonom>* t1 = t;
				t = t->next;
				monoms.remove(t1);
			}
			t = t->next;
		}
		return;
	}
	// if all of elements equal 0 we create new list with only 1 "0"
	monoms.clear();
	monoms.push_front(TMonom(0, 0, 0, 0));
	return;
	

}


string TPolynom::preparation(string polynom)
{
	string new_string, new_string1;

	int i = 0;
	while (i < polynom.size())
	{
		if (polynom[i] == ' ')
		{
			++i;
			continue;
		}
		new_string += polynom[i];
		++i;
	}
	i = 0;
	while (i < new_string.size())
	{
		if (new_string[i] == '+' || new_string[i] == '-')
		{
			new_string1 += " ";
			new_string1 += new_string[i];
			new_string1 += " ";
			++i;
			continue;
		}
		new_string1 += new_string[i];
		++i;
	}
	return new_string1;
}


void TPolynom::x(string token, char& stage, int& i, double& coef, int& degreex, int& degreey, int& degreez)
{
	// we here --> token[i] == 'x'
	string digit;
	stage = 'x';
	i++;
	if (token[i] == '^')
	{
		i++;
		if (i >= token.size() || token[i] < '0' || token[i] > '9')
		{
			// string like 2x^yz 
			throw "Wrong string\n";
		}
	}
	while (i < token.size() && ((token[i] >= '0' && token[i] <= '9') || token[i] == '.'))
	{
		digit += token[i];
		i++;
	}

	if (digit != "")
	{
		degreex += stod(digit);
	}
	else
	{
		degreex = 1;
	}
	if (i >= token.size())
	{
		return;
	}
	if (token[i] == 'x')
	{
		x(token, stage, i, coef,degreex, degreey, degreez);
	}
	else if (token[i] == 'y')
	{
		y(token, stage, i, coef, degreex, degreey, degreez);
	}
	else if (token[i] == 'z')
	{
		z(token, stage, i, coef, degreex, degreey, degreez);
	}
	else
	{
		throw "Wrong string";
	}

}


void TPolynom::y(string token, char& stage, int& i, double& coef, int& degreex, int& degreey, int& degreez)
{
	string digit;
	stage = 'y';
	i++;
	if (token[i] == '^')
	{
		i++;
		if (i >= token.size() || token[i] < '0' || token[i] > '9')
		{
			// string like 2x^yz 
			throw "Wrong string\n";
		}
	}
	while (i < token.size() && ((token[i] >= '0' && token[i] <= '9') || token[i] == '.'))
	{
		digit += token[i];
		i++;
	}

	if (digit != "")
	{
		degreey += stod(digit);
	}
	else
	{
		degreey = 1;
	}

	if (i >= token.size())
	{
		return;
	}
	if (token[i] == 'x')
	{
		x(token, stage, i, coef, degreex, degreey, degreez);
	}
	else if (token[i] == 'y')
	{
		y(token, stage, i, coef, degreex, degreey, degreez);
	}
	else if (token[i] == 'z')
	{
		z(token, stage, i, coef, degreex, degreey, degreez);
	}
	else
	{
		throw "Wrong string";
	}
}


void TPolynom::z(string token, char& stage, int& i, double& coef, int& degreex, int& degreey, int& degreez)
{
	string digit;
	stage = 'z';
	i++;
	if (token[i] == '^')
	{
		i++;
		if (i >= token.size() || token[i] < '0' || token[i] > '9')
		{
			// string like 2x^yz 
			throw "Wrong string\n";
		}
	}
	

	while (i < token.size() && ((token[i] >= '0' && token[i] <= '9') || token[i] == '.'))
	{
		digit += token[i];
		i++;
	}

	if (digit != "")
	{
		degreez += stod(digit);
	}
	else
	{
		degreez += 1;
	}

	if (i >= token.size())
	{
		return;
	}
	if (token[i] == 'x')
	{
		x(token, stage, i, coef, degreex, degreey, degreez);
	}
	else if (token[i] == 'y')
	{
		y(token, stage, i, coef, degreex, degreey, degreez);
	}
	else if (token[i] == 'z')
	{
		z(token, stage, i, coef, degreex, degreey, degreez);
	}
	else
	{
		throw "Wrong string";
	}
}


void TPolynom::c(string token, char& stage, int& i, double& coef, int& degreex, int& degreey, int& degreez)
{
	string digit;
	stage = 'c';
	while (i < token.size() && ((token[i] >= '0' && token[i] <= '9') || token[i] == '.'))
	{
		digit += token[i];
		i++;
	}

	if (digit != "")
	{
		coef *= stod(digit);
	}
	if (i >= token.size())
	{
		return;
	}
	if (token[i] == 'x')
	{
		x(token, stage, i, coef, degreex, degreey, degreez);
	}
	else if (token[i] == 'y')
	{
		y(token, stage, i, coef, degreex, degreey, degreez);
	}
	else if (token[i] == 'z')
	{
		z(token, stage, i, coef, degreex, degreey, degreez);
	}
	else
	{
		throw "Wrong string";
	}

}


void TPolynom::parse(string polynom)
{

	polynom = preparation(polynom); // пробелы добавить при +-
	

	string token;
	double curr_coef = 1;
	int degreex = 0, degreey = 0, degreez = 0;
	char stage = 's';
	if (polynom.size() >= 3)
	{
		string t; 
		t += (char)polynom[0];
		t += (char)polynom[1]; 
		t += (char)polynom[2];
		if (t == " - ")
		{
			curr_coef = -1;
			string tmp;
			for (int i = 3; i < polynom.size(); ++i) tmp += polynom[i];
			polynom = tmp;
		}

		if (t == " + ")
		{
			string tmp;
			for (int i = 3; i < polynom.size(); ++i) tmp += polynom[i];
			polynom = tmp;
		}
	}

	stringstream stream(polynom);
	while (stream >> token)
	{

		if (token == "-" || token == "+")
		{

			TMonom tmp(curr_coef, degreex, degreey, degreez);
			TNode<TMonom>* t = monoms.find(tmp);
			if (t != nullptr)
			{	
				t->value.inc_coef(curr_coef);
			}
			else
			{
				monoms.push_back(tmp);
			}
			curr_coef = 1;
			degreex = 0; degreey = 0; degreez = 0;
			stage = 's';
			if (token == "-")
			{
				curr_coef = -1;
			}
			continue;

		}
		int i = 0;
		while (i < token.size())
		{
			if (token[i] == 'x' || token[i] == 'y' || token[i] == 'z')
			{
				if (token[i] == 'x')
				{
					x(token, stage, i, curr_coef, degreex, degreey, degreez);
				}
				else if(token[i] == 'y')
				{
					y(token, stage, i, curr_coef, degreex, degreey, degreez);
				}
				else
				{
					z(token, stage, i, curr_coef, degreex, degreey, degreez);
				}
			}
			else if (token[i] >= '0' && token[i] <= '9')
			{
				c(token, stage, i, curr_coef, degreex, degreey, degreez);
			}
			else
			{
				throw "Wrong string";
			}
		}
		
	}
	if (stage != 's')
	{
		TMonom tmp(curr_coef, degreex, degreey, degreez);
		TNode<TMonom>* t = monoms.find(tmp);
		if (t != nullptr)
		{
			t->value.inc_coef(curr_coef);
		}
		else
		{
			monoms.push_back(tmp);
		}		
	}
	monoms.sort();
}


TPolynom::TPolynom() : monoms(TRingList<TMonom>())
{
	name = "*";
}


TPolynom::TPolynom(const string& polynom_string): monoms(TRingList<TMonom>()), name(polynom_string)
{
	parse(polynom_string);
	this->del_zeros(); this->monoms.sort(); this->monoms.start();
	set_string();
}


TPolynom::TPolynom(const TRingList<TMonom>& list): monoms(list), name(string())
{
	this->del_zeros(); this->monoms.sort(); this->monoms.start();
	set_string();
}

void TPolynom::set_string()
{
	string new_name = "";
	monoms.start();
	TNode<TMonom>* t = monoms.get_curr();
	bool f = false;
	while (t->value != TMonom())
	{
		if (t->value.get_coef() >= 0)
		{
			if (f)
				new_name += " + ";
			new_name += t->value.to_str();
		}
		else
		{
			if (f)
				new_name += "-";
			else new_name += " - ";
			new_name += t->value.to_str();
		}
		t = t->next;
		f = true;
	}
	name = new_name;
}

TPolynom::TPolynom(const TPolynom& polynom) : monoms(polynom.monoms), name(polynom.name)
{
}

const TPolynom& TPolynom::operator=(const TPolynom& polynom) 
{
	if (this == &polynom) return *this;

	TRingList<TMonom> new_monom(polynom.monoms);
	this->monoms = new_monom;
	this->name = polynom.name;
	
	return *this;
}


TPolynom TPolynom::operator+(const TPolynom& polynom) {

	TPolynom sum(*this);
	sum.monoms.start();
	TRingList<TMonom> tmp(polynom.monoms);
	tmp.start();

	TNode<TMonom>* tmp1 = tmp.get_curr();

	if (tmp1 == nullptr)
	{
		return *this;
	}

	while (tmp1->value != TMonom())
	{
		TNode<TMonom>* t = sum.monoms.find(tmp1->value);
		
		if (t == nullptr)
		{
			sum.monoms.push_back(tmp1->value);
		}
		else 
		{
			t->value.inc_coef(tmp1->value.get_coef());
		}
		tmp1 = tmp1->next;
	}
	sum.del_zeros(); sum.monoms.sort();
	sum.set_string();
	return sum;
}


TPolynom TPolynom::operator-(const TPolynom& polynom) {

	TPolynom sum(*this);
	sum.monoms.start();
	TRingList<TMonom> tmp(polynom.monoms);
	tmp.start();

	TNode<TMonom>* tmp1 = tmp.get_curr();

	if (tmp1 == nullptr)
	{
		return *this;
	}

	while (tmp1->value != TMonom())
	{
		TNode<TMonom>* t = sum.monoms.find(tmp1->value);
		tmp1->value.set_coef(-(tmp1->value.get_coef()));
		if (t == nullptr)
		{
			sum.monoms.push_back(tmp1->value);
		}
		else
		{
			t->value.inc_coef(tmp1->value.get_coef());
		}
		tmp1 = tmp1->next;
	}
	sum.del_zeros(); sum.monoms.sort();
	sum.set_string();
	return sum;
	
}


TPolynom TPolynom::operator*(const TPolynom& polynom) {

	
	TPolynom prod;

	TRingList<TMonom> l1(this->monoms), l2(polynom.monoms);
	l1.start();
	l2.start();
	TNode<TMonom>* t1 = l1.get_curr(), * t2 = l2.get_curr();
	if (t1 == nullptr || t2 == nullptr)
	{
		throw "Cant multiply empty polynom";
	}
	
	while (t1->value != TMonom())
	{
		t2 = l2.get_curr();
		while (t2->value != TMonom())
		{
			// find list1[i] * list2[j] in prod
			// if it is in list, we need sum coeff
			// else we need add new monom
			TMonom monom = t1->value * t2->value;
			TNode<TMonom>* t = prod.monoms.find(monom);
			if (t == nullptr)
			{
				prod.monoms.push_back(monom);
			}
			else
			{
				t->value.inc_coef(monom.get_coef());
			}
			
			t2 = t2->next;
		}
		
		t1 = t1->next;
	}
	prod.del_zeros(); prod.monoms.sort();
	prod.set_string();
	return prod;

}


double TPolynom::operator()(double x, double y, double z) {

	double res = 0;
	monoms.start();
	TNode<TMonom>* t = monoms.get_curr();
	while (t->value != TMonom())
	{
		res += t->value.eval(x, y, z);
		t = t->next;
	}
	return res;
}


bool TPolynom::operator==(const TPolynom& polynom) const
{
	return name == polynom.name;
}


bool TPolynom::operator<(const TPolynom& polynom) const
{
	int l2 = polynom.monoms.get_size(), l1 = monoms.get_size();
	TRingList<TMonom> fl = monoms, fr = polynom.monoms;
	fl.start(); fr.start();
	TNode<TMonom>* t = fl.get_curr(), *c = fr.get_curr();
	while (t->value != TMonom() && c->value != TMonom())
	{
		if (!(t->value.equal(c->value)))
		{
			return t->value.greater(c->value);
		}
		t = t->next; c = c->next;
	}
	return t->value == TMonom();
}

TPolynom TPolynom::dif_x() const {

	TPolynom polynom(*this);
	polynom.monoms.start();
	TPolynom res;
	TNode<TMonom>* t = polynom.monoms.get_curr();
	if (t == nullptr)
	{
		throw "Your polynom is empty!";
	}
	while(t->value != TMonom())
	{
		TMonom diff_x = t->value.dif_x();
		TNode<TMonom>* tmp = res.monoms.find(diff_x);
		if (tmp == nullptr)
		{
			res.monoms.push_back(diff_x);
		}
		else
		{
			
			tmp->value.inc_coef(diff_x.get_coef());
			
		}
		t = t->next;
	}
	res.del_zeros(); res.monoms.sort(); res.set_string();
	return res;
}


TPolynom TPolynom::dif_y() const {

	TPolynom polynom(*this);
	polynom.monoms.start();
	TPolynom res;
	TNode<TMonom>* t = polynom.monoms.get_curr();
	if (t == nullptr)
	{
		throw "Your polynom is empty!";
	}
	while(t->value != TMonom())
	{
		TMonom diff_y = t->value.dif_y();
		TNode<TMonom>* tmp = res.monoms.find(diff_y);
		if (tmp == nullptr)
		{
			res.monoms.push_back(diff_y);
		}
		else
		{
			tmp->value.inc_coef(diff_y.get_coef());
		}
		t = t->next;
	}
	res.del_zeros(); res.monoms.sort(); res.set_string();
	return res;
}


TPolynom TPolynom::dif_z() const {

	TPolynom polynom(*this);
	polynom.monoms.start();
	TPolynom res;
	TNode<TMonom>* t = polynom.monoms.get_curr();
	if (t == nullptr)
	{
		throw "Your polynom is empty!";
	}

	while(t->value != TMonom())
	{
		TMonom diff_z = t->value.dif_z();

		TNode<TMonom>* tmp = res.monoms.find(diff_z);
		if (tmp == nullptr)
		{
			res.monoms.push_back(diff_z);
		}
		else
		{
			tmp->value.inc_coef(diff_z.get_coef());
			
		}
		t = t->next;
	}
	res.del_zeros(); res.monoms.sort(); res.set_string();
	return res;
}

