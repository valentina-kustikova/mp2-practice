#include <iostream>
#include "stack.h"
#include "arithmetic.h"

using namespace std;

int main() {
	try {
		cout << "Enter expression:";
		string s;
		double n;
		getline(cin, s);
		TArithmeticExpession arithmetic(s);
		arithmetic.SetValues();
		cout << arithmetic.Calculate() << endl;
	}
	catch (string exp) {
		cout << exp << endl;
	}
	return 0;
}