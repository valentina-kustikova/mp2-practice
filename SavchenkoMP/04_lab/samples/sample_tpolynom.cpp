#include <iostream>
#include <string>
#include "tpolynom.h"

using namespace std;

int main() {
	cout << "TPolynom\n" << endl;
	try {
		/*
		samples:

		2*x^3*y^5*z-3*x^4*y+5*x
		7*x*y^3*z^5+3*x^4*y
		5.000000*x+2.000000*x^3*y^5*z+7.000000*x*y^3*z^5
		5.000000*x+2.000000*x^3*y^5*z-6.000000*x^4*y-7.000000*x*y^3*z^5
		6.000000*x^2*y^5*z-12.000000*x^3*y
		21.000000*x*y^2*z^5+3.000000*x^4
		35.000000*x*y^3*z^4
		35.000000*x^2*y^3*z^5+15.000000*x^5*y+14.000000*x^4*y^8*z^6+6.000000*x^7*y^6*z-21.000000*x^5*y^4*z^5-9.000000*x^8*y^2

		*/
		
		cout << "2*x^3*y^5*z - 3*x^4*y*z + 5*x" << endl;
		cout << "7*x*y^3*z^5 + 3*x^4*y\n" << endl;

		string name1;
		string name2;
		
		cout << "name1 = ";
		getline(cin, name1);
		cout << "name2 = ";
		getline(cin, name2);
		system("cls");


		TPolynom p1(name1);
		TPolynom p2(name2);
		cout << "p1 = " << p1 << endl;
		cout << "p2 = " << p2 << endl << endl;

		cout << "Operators (Addition, Subtraction, Multiplication):" << endl;
		cout << "p1 + p2 = " << p1 + p2 << endl;
		cout << "p1 - p2 = " << p1 - p2 << endl;
		cout << "p1 * p2 = " << p1 * p2 << endl << endl;

		cout << "Assignmention:" << endl;
		TPolynom p3;
		p3 = p1;
		cout << "p3 = p1;" << endl;
		cout << "p3 = " << p3 << endl << endl;

		cout << "Differentiation:" << endl;
		cout << "p1.dif_x() = " << p1.dif_x() << endl;
		cout << "p1.dif_y() = " << p1.dif_y() << endl;
		cout << "p1.dif_z() = " << p1.dif_z() << endl << endl;

		cout << "Set values of x, y, z:" << endl;
		int x, y, z;
		cout << "x = ";
		cin >> x;
		cout << "y = ";
		cin >> y;
		cout << "z = ";
		cin >> z;

		cout << "p1(x, y, z) = " << p1(x, y, z) << endl;
		cout << "p2(x, y, z) = " << p2(x, y, z) << endl;


		system("pause");
	}
	catch (string exp) {
		cout << exp << endl;
	}
	return 0;
}