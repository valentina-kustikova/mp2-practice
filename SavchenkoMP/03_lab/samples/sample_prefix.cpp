#include <iostream>
#include "tstack.h"
#include "tarithmeticexpression.h"

using namespace std;

int main() {
	cout << "TArithmeticExpression\n" << endl;
	try {
		string example1 = "A+(B-C)*D-F/(G+H)";
		string example2 = "Ax+(B-C)*D + 2 -Fy/(G+H)+yy -1.5";
		string example3 = "-2.5 + 2(3 - 1.4)(1+1) + 1 / 2 - X1 + 2x2";

		cout << "Enter an arithmetic expression." << endl;
		cout << "It may contain operators : +, -, -(unary), *, /." << endl;
		cout << "Operands are multicharacter words, e.g. \"A\", \"b\", \"X2\", \"aBc\", etc." << endl;
		cout << "Supports integer and fractional constant entries." << endl;
		cout << "Supports abbreviations such as: 2(A+B), (C-D)3, (A+B)(C+D), .1, 3., etc.\n" << endl;
		cout << "Arithmetic expression examples: \n" << example1  << "\n" << example2 << "\n"<< example3 << "\n" << endl;


		string inf;
		getline(cin, inf);

		TArithmeticExpression ae(inf);
		cout << "\n" << ae.GetInfix() << endl;
		cout << ae.GetStringPostfix() << endl;

		ae.SetValues();
		cout << ae.Calculate() << endl;
	}
	catch (string exp) {
		cout << exp << endl;
	}
	return 0;
}