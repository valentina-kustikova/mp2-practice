#include "stack.h"
#include "structures.h"
#include <iostream>
#include <string>

int main()
{
	string ar_ex;
	double res;
	cout << "Enter arithmetic expression: ";
	cin >> ar_ex;

	TStack<string> st(5);
	st = Postfix_Form(ar_ex);
	cout << st << endl;

	map<string, double> variableDict = GetVariables(st);
	res = Calculate(st, variableDict);
	cout << res;
	return 0;
}