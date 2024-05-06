#include "tpolynom.h"

TPolinom::TPolinom() {

}

TPolinom::TPolinom(const string& stringPolynom) {
	getListOfMonoms(stringPolynom);
	Sort();
	formula = getStringMonoms();
}
TPolinom::TPolinom(const TRingList<TMonom>& m) {
	monoms = m;
	Sort();
	formula = getStringMonoms();
	fillUniques(formula);
}

TPolinom::TPolinom(const TPolinom& p) {
	formula = p.formula;
	uniques = p.uniques;
	TRingList <TMonom> tmpPolynom = p.monoms;
	if (!p.monoms.is_Empty()) {
		while (!tmpPolynom.is_End()) {
			monoms.InsertLast(tmpPolynom.getCurrData());
			tmpPolynom.Next();
		}
	}
	monoms.Reset();
}
double TPolinom::getCoeff(const std::string& input, int& pos)
{
	std::string coeff = "";
	
	if (isSeparator(input[pos]))
	{
		coeff += input[pos++];
	}

	while (pos < input.size() && !isMonomOperator(input[pos]) && !isVariable(input[pos]) && !isSeparator(input[pos]))
	{
		coeff += input[pos];
		pos++;
	}

	if (coeff == "+" || coeff == "") {
		coeff = "1.0";
	}
	if (coeff == "-") {
		coeff = "-1.0";
	}
	return std::stod(coeff);
}

void TPolinom::updateDegree(int& degree, char variable, int degreeOfVar)
{
	switch (variable) {
	case 'x':
		degree += 100 * degreeOfVar;
		break;
	case 'y':
		degree += 10 * degreeOfVar;
		break;
	case 'z':
		degree += degreeOfVar;
		break;
	default:
		break;
	}
}

void TPolinom::getListOfMonoms(const std::string& input) {
	double currentCoef = 1.0;
	int currentDegree = 0;
	int index = 0;
	while (index < input.size()) {
		currentCoef = getCoeff(input, index);
		while (!isSeparator(input[index]) && index < input.size()) {
			if (isMonomOperator(input[index])) {
				if (input[index] == '*') {
					index++;
				}
				else {
					updateDegree(currentDegree, input[index - 1], input[index + 1] - '0');
					index += 2;
				}
			}
			else if (isVariable(input[index])) {
				if (index == input.size() - 1 || input[index + 1] != '^') {
					updateDegree(currentDegree, input[index], 1);
				}
				uniques[input[index]] = INFINITY;
				index++;
			}
			else {
				throw "Uncorrect polynom";
			}
			
		}
		TMonom monom(currentCoef, currentDegree);
		monoms.InsertLast(monom);
		currentDegree = 0;
	}
}

void TPolinom::fillUniques(const std::string& f)
{
	int index = 0;
	while (index < f.size())
	{
		if (isVariable(f[index]))
		{
			uniques[f[index]]++;
			uniques[f[index]] = INFINITY;
		}
		index++;
	}
}

void TPolinom::fillVariables() {
	for (auto& uniques : uniques)
	{
		if (uniques.second == INFINITY) {
			uniques.second = getValue(uniques.first);
		}
	}
}
double TPolinom::getValue(const char& variable) {
	std::cout << "Enter variable value for \"" << variable << "\"" << std::endl;
	double value = INFINITY;
	std::cin >> value;
	return value;
}
std::string TPolinom::getFormula() const {
	return formula;
}

double TPolinom::calculate()
{
	fillVariables();
	double result = 0.0;
	while( !monoms.is_Empty() && !monoms.is_End())
	{
		result += monoms.GetCurrent()->data.calculateMonom(uniques);
		monoms.Next();
	}
	return result;
}

bool TPolinom::isVariable(char var) const
{
	return (var == 'x' || var == 'y' || var == 'z');
}

bool TPolinom::isMonomOperator(char op)  const {
	return (op == '*' || op == '^');
}

bool TPolinom::isSeparator(char op) const {
	return (op == '+' || op == '-');
}

bool TPolinom::isOperator(char op) const {
	return (op == '+' || op == '-' || op == '*'  || op == '^');
}

TPolinom::~TPolinom()
{
	formula = "";
}

void TPolinom::Sort() {
	monoms.Sort();
	deleteZero();
	sumEqual();
	monoms.Reset();
	formula = getStringMonoms();
	fillUniques(formula);
}

void TPolinom::sumEqual() {
	monoms.Sort();

	while (!monoms.is_Empty() && !monoms.is_End())
	{
		TNode<TMonom>* i = monoms.GetCurrent();
			TNode<TMonom>* j = i->pNext;
			if (j != monoms.GetPStop() && i->data.GetDegree() == j->data.GetDegree())
			{
				double coef1 = i->data.GetCoeff();
				double coef2 = j->data.GetCoeff();

				i->data.SetCoeff(coef1 + coef2);
				i->pNext = j->pNext;
				delete j;
			}
			else
			{
				monoms.Next(); 
			}
	}
	deleteZero();
	formula = getStringMonoms();
}
void TPolinom::deleteZero() {
	monoms.Reset();
	TNode<TMonom>* current = monoms.GetCurrent();
	while (!monoms.is_Empty() && !monoms.is_End())
	{
		if (monoms.GetCurrent()->data.GetCoeff() == 0.0)
		{
			monoms.RemoveCurrent();
		}
		else {
			monoms.Next();
		}
	}
	monoms.Reset();
}

std::string TPolinom::getStringMonoms() const {
	std::string stringMonoms = "";
	TRingList<TMonom> tmp(monoms);
	while (!tmp.is_Empty() && !tmp.is_End())
	{
		stringMonoms += tmp.getCurrData().getStringMonom();
		tmp.Next();
	}
	return stringMonoms;
}

TPolinom TPolinom::operator+(const TPolinom& p) {
	
	TPolinom copy(p);
	TPolinom resultPolynom;
	monoms.Reset();
	if (copy.monoms.is_Empty() && monoms.is_Empty())
	{
		return resultPolynom;
	}
	while (!copy.monoms.is_End() && !monoms.is_End())
	{
		if (copy.monoms.GetCurrent()->data.GetDegree() < monoms.GetCurrent()->data.GetDegree())
		{
			resultPolynom.monoms.InsertLast(monoms.GetCurrent()->data);
			monoms.Next();
		}
		else if (copy.monoms.GetCurrent()->data.GetDegree() > monoms.GetCurrent()->data.GetDegree())
		{
			resultPolynom.monoms.InsertLast(copy.monoms.GetCurrent()->data);
			copy.monoms.Next();
		}
		else
		{
			if (copy.monoms.GetCurrent()->data.GetDegree() == monoms.GetCurrent()->data.GetDegree())
			{
				if (copy.monoms.GetCurrent()->data.GetCoeff() + monoms.GetCurrent()->data.GetCoeff() != 0)
				{
					resultPolynom.monoms.InsertLast(copy.monoms.GetCurrent()->data + monoms.GetCurrent()->data);
				}
				
			}
			copy.monoms.Next();
			monoms.Next();
		}
	}
	
	while (!copy.monoms.is_End())
	{
		resultPolynom.monoms.InsertLast(copy.monoms.GetCurrent()->data);
		copy.monoms.Next();
	}
	while (!monoms.is_End())
	{
		resultPolynom.monoms.InsertLast(monoms.GetCurrent()->data);
		monoms.Next();
	}
	resultPolynom.Sort();
	resultPolynom.formula = resultPolynom.getStringMonoms();
	return resultPolynom;
}

const TPolinom& TPolinom::operator=(const TPolinom& p) {
	if (this == &p)
	{
		return *this;
	}
	formula = p.formula;
	uniques = p.uniques;

	TPolinom copy(p);
	copy.monoms.Reset();
	monoms.Clear();
	monoms.Reset();
	while (!copy.monoms.is_End())
	{
		monoms.InsertLast(copy.monoms.GetCurrent()->data);
		copy.monoms.Next();
	}
	monoms.Reset();
	return *this;
}

TPolinom TPolinom::operator-(const TPolinom& p) {
	TPolinom copy(p);
	TPolinom result = (*this) + copy * (-1.0);
	result.formula = result.getStringMonoms();
	return result;
}

TPolinom TPolinom::operator*(const double c) {
	TPolinom copy(*this);
	TPolinom resultPolymom;
	if (copy.monoms.is_Empty())
	{
		return resultPolymom;
	}
	copy.monoms.Reset();
	while (!copy.monoms.is_End())
	{
		copy.monoms.GetCurrent()->data.SetCoeff(copy.monoms.GetCurrent()->data.GetCoeff() * c);
		if (copy.monoms.GetCurrent()->data.GetCoeff() != 0)
		{
			resultPolymom.monoms.InsertLast(copy.monoms.GetCurrent()->data);
		}
		copy.monoms.Next();
	}
	resultPolymom.monoms.Reset();
	resultPolymom.formula = resultPolymom.getStringMonoms();
	return resultPolymom;
}

TPolinom TPolinom::operator*(const TPolinom& p) {
	TPolinom multiplyP(p);
	TRingList<TMonom> resultMonoms;
	monoms.Reset();
	multiplyP.monoms.Reset();
	if (multiplyP.monoms.is_Empty() && monoms.is_Empty())
	{
		return TPolinom(resultMonoms);
	}
	while (!multiplyP.monoms.is_End())
	{
		while (!monoms.is_End())
		{
			if (multiplyP.monoms.GetCurrent()->data.GetCoeff() * monoms.GetCurrent()->data.GetCoeff() != 0)

			{
				resultMonoms.InsertLast(multiplyP.monoms.getCurrData() * monoms.getCurrData());
			}
		
			monoms.Next();
		}
		monoms.Reset();
		multiplyP.monoms.Next();
	}
	monoms.Reset();
	resultMonoms.Reset();
	TPolinom resultPolynom(resultMonoms);
	resultPolynom.formula = resultPolynom.getStringMonoms();
	return resultPolynom;
}

TPolinom TPolinom::defX() const {
	TRingList<TMonom> copy(monoms);
	TRingList<TMonom> resultMonoms;
	TRingList<TMonom> tmpMonoms;
	if (copy.is_Empty())
	{
		return TPolinom(resultMonoms);
	}
	while (!copy.is_End())
	{
		if (copy.GetCurrent()->data.GetDegree() / 100 > 0)
		{
			tmpMonoms.InsertLast(copy.GetCurrent()->data.monom_defX());

			if (tmpMonoms.GetCurrent() != 0)
			{
				resultMonoms.InsertLast(tmpMonoms.GetCurrent()->data);
				resultMonoms.Next();
			}
			tmpMonoms.Next();
		}
		copy.Next();
	}
	resultMonoms.Reset();
	return TPolinom(resultMonoms);
}


TPolinom TPolinom::defY() const {
	TRingList<TMonom> copy(monoms);
	TRingList<TMonom> resultMonoms;
	TRingList<TMonom> tmpMonoms;
	if (copy.is_Empty())
	{
		return TPolinom(resultMonoms);
	}
	while (!copy.is_End())
	{
		if (copy.GetCurrent()->data.GetDegree() % 100 / 10  > 0)
		{
			tmpMonoms.InsertLast(copy.GetCurrent()->data.monom_defY());

			if (tmpMonoms.GetCurrent() != 0)
			{
				resultMonoms.InsertLast(tmpMonoms.GetCurrent()->data);
				resultMonoms.Next();
			}
			tmpMonoms.Next();
		}
		copy.Next();
	}
	resultMonoms.Reset();
	return TPolinom(resultMonoms);
}

TPolinom TPolinom::defZ() const {
	TRingList<TMonom> copy(monoms);
	TRingList<TMonom> resultMonoms;
	TRingList<TMonom> tmpMonoms;
	if (copy.is_Empty())
	{
		return TPolinom(resultMonoms);
	}
	while (!copy.is_End())
	{
		if (copy.GetCurrent()->data.GetDegree() % 10 > 0)
		{
			tmpMonoms.InsertLast(copy.GetCurrent()->data.monom_defZ());

			if (tmpMonoms.GetCurrent() != 0)
			{
				resultMonoms.InsertLast(tmpMonoms.GetCurrent()->data);
				resultMonoms.Next();
			}
			tmpMonoms.Next();
		}
		copy.Next();
	}
	resultMonoms.Reset();
	return TPolinom(resultMonoms);
}

std::ostream& operator<<(std::ostream& out, TPolinom& p) {
	if (p.monoms.is_Empty())
		return	out << "0" << std::endl;
	p.getFormula();
	out << p.getFormula();
	return out;
}