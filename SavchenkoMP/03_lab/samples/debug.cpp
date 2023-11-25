#include <iostream>
#include <vector>
#include <map>
#include "tstack.h"
#include "tarithmeticexpression.h"

using namespace std;


void test_ae() {
	string example1 = "A+(B-C)*D-F/(G+H)";
	string e1Pef = "A B C - D * + F G H + / -";

	string example2 = "Ax+(B-C)*D + 2 -Fy/(G+H)+yy -1.5";
	string e2Pref = "Ax B C - D * + 2 + Fy G H + / - yy + 1.5 -";

	string example = "(A+B)*C-K+F*(D-A)/(K+A)";
	string ePref = "AB+C*K-FDA-*KA+/+";

	map<string, double> values1 = {
		{"A", 0},
		{"B", 1},
		{"C", 2},
		{"D", -1},
		{"F", 2},
		{"G", 0.5},
		{"H", 0.5}
	};
	map<string, double> values2 = {
		{"Ax", 0},
		{"B", 1},
		{"C", 2},
		{"D", -1},
		{"Fy", 2},
		{"G", 0.5},
		{"H", 0.5},
		{"yy", 1}
	};
	string test = "2.5+1.4-A*2";
	string test1 = "2.5 + 2 * (3 - 1.4) + 1 / 2";
	
	string a;
	cin >> a;
	cout << a;
	TArithmeticExpression ae(test1);
	cout << "\n" << ae.GetInfix() << endl;
	cout << ae.GetStringPostfix() << endl;
	//cout << (e2Pref == ae.GetStringPostfix()) << endl;

	//ae.SetValues();
	cout << ae.Calculate() << endl;
}

int main() {
	/*string a = "A+(B-C)*D-F/(G+H)";
	string b = "AB+C-D";
	
	string str = "ABC";
	str.insert(3, ".");
	cout << str << endl;*/

	//string a = "ABC";
	//string b = "ABC";
	//a = '0' + a;
	//b.insert(0, "0");

	//cout << (a == b) << endl;
	//string a;
	//cin >> a;
	//cout << a;
	try {
		//test_ae();
		//test_IsConst();

		string str = "5(A+B)";
		string prefix = "0.5(A+B)";

		TArithmeticExpression ae(str);

	

	}
	catch (string exp) {
		cout << exp << endl;
	}
	return 0;
}