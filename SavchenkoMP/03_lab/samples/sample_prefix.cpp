#include <iostream>
#include "tstack.h"
#include "tarithmeticexpression.h"

using namespace std;

int main() {
	cout << "TArithmeticExpression\n" << endl;
	try {
		string example1 = "A+(B-C)*D-F/(G+H)";
		string example2 = "Ax+(B-C)*D + 2 -Fy/(G+H)+yy -1.5";
		string example3 = "-2.5 + 2(3 - 1.4)(1+1) + 1 / 2 - X1 + 2x2"; //4.4


		map<string, double> values = {
			{"A", 0},
			{"B", 1},
			{"C", 2},
			{"D", -1},
			{"F", 2},
			{"G", 0.5},
			{"H", 0.5}
		};

		cout << "Enter an arithmetic expression." << endl;
		cout << "It may contain operators : +, -, -(unary), *, /." << endl;
		cout << "Operands are multicharacter words, e.g. \"A\", \"b\", \"X2\", \"aBc\", etc." << endl;
		cout << "Supports integer and fractional constant entries." << endl;
		cout << "Supports abbreviations such as: 2(A+B), (A+B)(C+D), .1, 3., etc." << endl;
		cout << "It is considered that the entered arithmetic expression is written without errors.\n" << endl;
		cout << "a.e. example: \n" << example1  << "\n" << example2 << "\n"<< example3 << "\n" << endl;


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