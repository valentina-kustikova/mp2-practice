#include <iostream>
#include "tstack.h"
#include "tarithmeticexpression.h"

using namespace std;

int main() {
	try {
		string a = "A+(B-C)*D-F/(G+H)";
		string refP = "ABC-D*+FGH+/-";
		map<char, double> values = {
			{'A', 0},
			{'B', 1},
			{'C', 2},
			{'D', -1},
			{'F', 2},
			{'G', 0.5},
			{'H', 0.5}
		};

		TArithmeticExpression test(a);
		cout << test.GetInfix() << endl;
		cout << test.GetPostfix() << endl;
		
		test.SetValues(values);
		cout << test.Calculate() << endl;
	}
	catch (string exp) {
		cout << exp << endl;
	}
	return 0;
}