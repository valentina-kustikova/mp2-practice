#include "stack.h"
#include "structures.h"
#include <iostream>
#include <string>

int main()
{
	string ar_ex;
	double res;
	cout << "Enter arithmetic expression: ";
	getline(cin, ar_ex);

	TStack<string> st(5);
	try {
		st = ArithmeticExpression::Postfix_Form(ar_ex);
		cout << st << endl;
	}
	catch (string msg) {
		cout << msg << endl;
	}
	map<string, double> variableDict = ArithmeticExpression::GetVariables(st);
	res = ArithmeticExpression::Calculate(st, variableDict);
	if (res != -1)
		cout << res;
	return 0;
}