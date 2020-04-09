#include "Polynom.h"

void main() {
	try {
		Polynom polynom_1;
		Polynom polynom_2;
		cout << "Enter first polynom" << endl;
		cin >> polynom_1;
		cout << "Enter second polynom" << endl;
		cin >> polynom_2;
		cout << "Polynom_1" << endl;
		cout << polynom_1 << endl;
		cout << "Polynom_2" << endl;
		cout << polynom_2 << endl;
		Polynom polynom_o;
		polynom_o = polynom_1 + polynom_2;
		cout << "Polynom_1 + Polynom_2" << endl;
		cout << polynom_o << endl;
		polynom_o = polynom_1 - polynom_2;
		cout << "Polynom_1 - Polynom_2" << endl;
		cout << polynom_o << endl;
		polynom_o = polynom_1 * polynom_2;
		cout << "Polynom_1 * Polynom_2" << endl;
		cout << polynom_o << endl;
	}
	catch (const exception & e) {
		cout << e.what() << endl;
	}
}