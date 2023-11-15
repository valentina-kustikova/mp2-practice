#include <iostream>
#include "tstack.h"
#include "tarithmeticexpression.h"

using namespace std;

int main() {
	cout << "TArithmeticExpression\n" << endl;
	try {
		string example1 = "A+(B-C)*D-F/(G+H)";
		string e1Pef = "ABC-D*+FGH+/-";

		string example2 = "(A+B)*C-K+F*(D-A)/(K+A)";
		string e2Pref = "AB+C*K-FDA-*KA+/+";

		map<char, double> values = {
			{'A', 0},
			{'B', 1},
			{'C', 2},
			{'D', -1},
			{'F', 2},
			{'G', 0.5},
			{'H', 0.5}
		};

		cout << "Enter an arithmetic expression." << endl;
		cout << "It may contain operators : +, -, *, /." << endl;
		cout << "Operands are one - character words, e.g. \"A\", \"b\", \"2\"." << endl;
		cout << "It is considered that the entered arithmetic expression is written without errors.\n" << endl;
		cout << "a.e. example: \n" << example1  << "\n" << example2 << "\n" << endl;


		string inf;
		cin >> inf;

		TArithmeticExpression ae(inf);
		cout << ae.GetInfix() << endl;
		cout << ae.GetPostfix() << endl;

		ae.SetValues();
		cout << ae.Calculate(values) << endl;

		//TArithmeticExpression test(a);
		//cout << test.GetInfix() << endl;
		//cout << test.GetPostfix() << endl;
		
		//test.SetValues(values);
		//cout << test.Calculate() << endl;
	}
	catch (string exp) {
		cout << exp << endl;
	}
	return 0;
}