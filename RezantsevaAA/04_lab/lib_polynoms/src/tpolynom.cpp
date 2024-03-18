#include "tpolynom.h"

TPolinom::TPolinom() {
	monoms = nullptr;
	formula = "";
}

TPolinom::TPolinom(const string& stringPolynom) {
	formula = stringPolynom;
	getListOfMonoms(stringPolynom);
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
		coeff = "- 1.0";
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
}

void TPolinom::sumEqual() {
	monoms.Sort();
	TNode<TMonom>* i = monoms.GetPFirst();
	if (i == nullptr) return;

	while (i->pNext != nullptr)
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
}
void TPolinom::deleteZero() {
	if (monoms.GetPFirst() == nullptr)
		return;
	TNode<TMonom>* i = monoms.GetPFirst();;
	while (i->pNext != nullptr)
	{
		TNode<TMonom>* j = i->pNext;
		if (j->data.GetCoeff() == 0)
		{
			i->pNext = j->pNext;
			delete j;
		}
		else
		{
			i = j;
		}
	}
	if (i->data.GetCoeff() == 0)
	{
		monoms.RemoveCurrent();
	}
	else
	{
		monoms.SetPLast(i);
	}
}



TPolinom::TPolinom(const TRingList<TMonom>& m) {
	monoms = TRingList<TMonom>(m);
	// TODO create string polynom

}

TPolinom::TPolinom(const TPolinom& p) {
	TMonom* pMonom = new TMonom(0, -1);

	
}


/*
TPolinom TPolinom ::operator+(const TPolinom& p) {

}

*/