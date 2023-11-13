#include <iostream>
#include "tstack.h"
#include "tarithmeticexpression.h"

using namespace std;

int main() {
	//string a = "A+(B-C)*D-F/(G+H)";
	//char token = a[1];
	//cout << OperatorPriority[token];

	try {
		string a = "A+B";
		string b = "A+(B-C)*D-F/(G+H)";

		string refPF = "ABC-D*+FGH+/-";
		string refPF1 = "ABC++";
		map<char, double> values = {
			{'A', 0},
			{'B', 1},
			{'C', 2},
			{'D', -1},
			{'F', 2},
			{'G', 0.5},
			{'H', 0.5}
		};

		//TStack<char> test = ConvertToPostfixForm(b);
		//test.DUBUG_Print();
		cout << Calculate(refPF, values) << endl;
		
		/*test.PrintInfixForm();
		cout << endl;
		test.PrintPostfixForm();
		cout << endl;*/
	}
	catch (string exp) {
		cout << exp << endl;
	}


	return 0;
}