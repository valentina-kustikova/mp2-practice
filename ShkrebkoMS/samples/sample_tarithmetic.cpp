#include <iostream>
#include "tstack.h"
#include "tarithmetic.h"

using namespace std;

int main() {
	cout << "TArithmeticExpression\n" << endl;
	cout << "Enter an arithmetic expression." << endl;
	string infix;
	getline(cin, infix);

	TArithmeticExpression ae(infix);

	ae.SetValues();
	ae.ShowPostfix();
	try {
		cout << ae.Calculate() << endl;
	}
	catch (std::exception exp) {
		cout << exp.what() << endl;
	}
	return 0;
}