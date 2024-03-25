#include "tpolynom.h"

TPolinom::TPolinom() {
	monoms = nullptr;
	formula = "";
}

TPolinom::TPolinom(const string& stringPolynom) {
	getListOfMonoms(stringPolynom);
	deleteZero();
	formula = getStringMonoms();

}

double TPolinom::getCoeff(const std::string& input, int& pos)
{

	std::string coeff = "";

	while (pos < input.size() && !isMonomOperator(input[pos]) && !isVariable(input[pos]))
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
		currentDegree = 0.0;
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
	while(monoms.GetCurrent() != monoms.GetPStop())
	{
		result += monoms.GetCurrent()->data.calculateMonom(uniques);
		monoms.Next();
	}
	return result;
}

bool TPolinom::isVariable(char var)
{
	return (var == 'x' || var == 'y' || var == 'z');
}

bool TPolinom::isMonomOperator(char op) {
	return (op == '*' || op == '^');
}

bool TPolinom::isSeparator(char op) {
	return (op == '+' || op == '-');
}

bool TPolinom::isOperator(char op) {
	return (op == '+' || op == '-' || op == '*'  || op == '^');
}

TPolinom::~TPolinom()
{
	formula = "";
}

void TPolinom::Sort() {
	monoms.Sort();
	deleteZero();
	formula = getStringMonoms();
}

void TPolinom::sumEqual() {
	monoms.Sort();
	TNode<TMonom>* i = monoms.GetPFirst();
	if (i == nullptr) return;

	while (i->pNext != monoms.GetPStop())
	{
		TNode<TMonom>* j = i->pNext;
		if (i->data.GetDegree() == j->data.GetDegree())
		{
			double coef1 = i->data.GetCoeff();
			double coef2 = j->data.GetCoeff();

			i->data.SetCoeff(coef1 + coef2);
			i->pNext = j->pNext;
			delete j;
		}
		else
		{
			i = j;
		}
	}
	deleteZero();
	formula = getStringMonoms();
}
void TPolinom::deleteZero() {
	if (monoms.GetPFirst() == nullptr)
		return;
	TNode<TMonom>* current = monoms.GetCurrent();
	while (!monoms.is_End())
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
	while (!tmp.is_End())
	{
		stringMonoms += tmp.getCurrData().getStringMonom();
		tmp.Next();
	}
	return stringMonoms;
}

TPolinom::TPolinom(const TRingList<TMonom>& m) {
	monoms = m;
	deleteZero();
	formula = getStringMonoms();
}

TPolinom::TPolinom(const TPolinom& p) {
	formula = p.formula;
	uniques = p.uniques;
	TRingList <TMonom> tmpPolynom = p.monoms;
	while(!tmpPolynom.is_End()){
		monoms.InsertLast(tmpPolynom.getCurrData());
		tmpPolynom.Next();
	}
}

TPolinom TPolinom::operator+(const TPolinom& p) {

	std::string resultFormula = formula + p.getFormula();
	TPolinom resultPolynom(resultFormula);
	resultPolynom.GetNormalView();
	return resultPolynom;
}

TPolinom TPolinom::operator-(const TPolinom& p) {
	TPolinom subtrahendPolynom(p);
	while (!subtrahendPolynom.monoms.is_End()) {
		subtrahendPolynom.monoms.GetCurrent()->data.ChangeCoeff();
		subtrahendPolynom.monoms.Next();
	}
	subtrahendPolynom.monoms.Reset();
	subtrahendPolynom.formula = subtrahendPolynom.getStringMonoms();

	std::string resultFormula = formula + subtrahendPolynom.getFormula();
	TPolinom resultPolynom(resultFormula);
	resultPolynom.GetNormalView();
	/*
	resultPolynom.Sort();
	resultPolynom.deleteZero();
	resultPolynom.sumEqual();
	resultPolynom.getStringMonoms();
	*/
	return resultPolynom;
}
TPolinom TPolinom::operator*(const TPolinom& p) {
	TPolinom multiplyP(p);
	TRingList<TMonom> resultMonoms;
	while (!multiplyP.monoms.is_End())
	{
		while (!monoms.is_End())
		{
			resultMonoms.InsertLast(multiplyP.monoms.getCurrData() * monoms.getCurrData());
			monoms.Next();
		}
		monoms.Reset();
		multiplyP.monoms.Next();
	}
	monoms.Reset();
	TPolinom resultPolynom(resultMonoms);
	resultPolynom.GetNormalView();
	return resultPolynom;
}
void TPolinom::GetNormalView() {
	Sort();
	deleteZero();
	sumEqual();
	getStringMonoms();
}
TPolinom TPolinom::defX() const {
	TRingList<TMonom> copy(monoms);
	TRingList<TMonom> resultMonoms;
	while (!copy.is_End())
	{
		if (copy.GetCurrent()->data.GetDegree() / 100 > 0)
		{
			resultMonoms.InsertLast(copy.GetCurrent()->data.monom_defX());
			resultMonoms.Next();
		}
		copy.Next();
	}
	resultMonoms.Reset();
	TPolinom resultPolynom(resultMonoms);
	resultPolynom.GetNormalView();
	return resultPolynom;
}
TPolinom TPolinom::defY() const {
	TRingList<TMonom> copy(monoms);
	TRingList<TMonom> resultMonoms;
	while (!copy.is_End())
	{
		if (copy.GetCurrent()->data.GetDegree() % 100 / 10  > 0)
		{
			resultMonoms.InsertLast(copy.GetCurrent()->data.monom_defY());
			resultMonoms.Next();
		}
		copy.Next();
	}
	resultMonoms.Reset();
	TPolinom resultPolynom(resultMonoms);
	resultPolynom.GetNormalView();
	return resultPolynom;
}

TPolinom TPolinom::defZ() const {
	TRingList<TMonom> copy(monoms);
	TRingList<TMonom> resultMonoms;
	while (!copy.is_End())
	{
		if (copy.GetCurrent()->data.GetDegree() % 10 > 0)
		{
			resultMonoms.InsertLast(copy.GetCurrent()->data.monom_defZ());
			resultMonoms.Next();
		}
		copy.Next();
	}
	resultMonoms.Reset();
	TPolinom resultPolynom(resultMonoms);
	resultPolynom.GetNormalView();
	return resultPolynom;
}