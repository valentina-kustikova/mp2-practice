#include <iostream>
#include <string>
#include <vector>
#include "tnode.h"
#include "tlist.h"
#include "tringlist.h"
#include "tmonom.h"
#include "tpolynom.h"

using namespace std;

int main() {
	try {
		string name1 = "2*x^3*y^5*z - 3*x^4*y*z + 5*x";
		string name2 = "7*x*y^3*z^5 + 3*x^4*y";


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
		int x = 1, y = 2, z = 3;

		cout << "p1(x, y, z) = " << p1(x, y, z) << endl;
		cout << "p2(x, y, z) = " << p2(x, y, z) << endl;

		/*
		TPolynom p1("3.3*x*y - 1.1*x^2");
		TPolynom p2("5.5*x*y - 3.3*x^2");
		TPolynom expP("-2.2*x*y + 2.2*x^2");

		TPolynom p3(p1 - p2);
		*/

		/*
		TPolynom p1("2*x^2 + 3*x*y + 4*y^2");
		TPolynom p2("3*x^3 + 2*x*y - 5*y^3");

		//p1 + p2;
		TPolynom exp_add = p1 + p2;
		TPolynom exp_sub = p1 - p2;
		TPolynom exp_mult = p1 * p2;

		TPolynom p3("x^3*y*z + x*y^3*z + x*y*z^3 + x + y + z");
		TPolynom exp_dX = p3.dif_x();
		TPolynom exp_dY = p3.dif_y();
		TPolynom exp_dZ = p3.dif_z();

		cout << p1 << endl;
		cout << p2 << endl << endl;

		cout << exp_add << endl;
		cout << exp_sub << endl;
		cout << exp_mult << endl << endl;

		cout << p3 << endl;
		cout << exp_dX << endl;
		cout << exp_dY << endl;
		cout << exp_dZ << endl << endl;
		*/
	}
	catch (string exp) {
		cout << exp << endl;
		//cout << "Error" << endl;
	}
	
	return 0;
}