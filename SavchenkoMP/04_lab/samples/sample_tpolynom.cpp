#include <iostream>
#include "tpolynom.h"

using namespace std;

int main() {
	try {
		string name = "2*x^2*y^2*z^2+1*x^1*y^1*z^1+3*x^3*y^3*z^3";
		string exp_str = "1.000000*x^1*y^1*z^1+2.000000*x^2*y^2*z^2+3.000000*x^3*y^3*z^3";
		
		TPolynom p(name);

		cout << p.get_string() << endl;


		system("pause");
	}
	catch (string exp) {
		cout << exp << endl;
		system("pause");
	}
	return 0;
}