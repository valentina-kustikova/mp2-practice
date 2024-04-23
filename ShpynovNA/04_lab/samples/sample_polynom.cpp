#include "tpolynomial.h"

int main() {
	try {
		cout << "enter 1st polynomial: \n";
		string s1;
		//cin >> s1;  5x^2*y^3*z^4 + 11*x^3 + 7 + 0 - 2x^3 
		s1 = " 5x^2*y^3*z^4 + 11*x^3 + 7 + 0 2 11x^3 - 2x + 3 - 0 -2 +x";
		TPolynomial P1 = TPolynomial(s1);
		cout << "got " << P1 << "\n";

		cout << "enter 2nd polynomial: \n";
		//cin >> s1;
		s1 = "-3x^2*y^3*z^4";
		TPolynomial P2 = TPolynomial(s1);
		cout << "got " << P2 << "\n\n";
		cout << "their sum: " << P1+P2 << "\n";
		cout << "their difference: " << P1 - P2 << "\n";
		cout << "their multiplication: " << P1*P2 << "\n";
		cout << "1st Derivarive of X in the 1st polynomial: " << P1.DerivativeX() << "\n";
		cout << "1st Derivarive of Y in the 1st polynomial: " << P1.DerivativeY() << "\n";
		cout << "1st Derivarive of Z in the 1st polynomial: " << P1.DerivativeZ() << "\n\n";
		cout << "enter variables' values in the first polynomial: ";
		int x, y, z;
		cin >> x >> y >> z;
		cout << "first polynomial value at (" << x << "," << y << "," << z << ") is " << P1(x, y, z) << "\n";
	}
	catch (...) {
		cout << "got error";
		return 1;
	}
	return 0;
}