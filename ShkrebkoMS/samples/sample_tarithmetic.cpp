#include <iostream>
#include "tstack.h"
#include "tarithmetic.h"

using namespace std;

int main() {
	cout << "TArithmeticExpression\n" << endl;
	try {
		string example1 = "A+(B-C)*D-F/(G+H)";



		cout << "Enter an arithmetic expression." << endl;
		cout << "Arithmetic expression examples: \n" << example1 << "\n" << endl;


		string infix;
		getline(cin, infix);

		TArithmeticExpression ae(infix);

		ae.SetValues();
		cout << ae.Calculate() << endl;
	}
	catch (string exp) {
		cout << exp << endl;
	}
	return 0;
}