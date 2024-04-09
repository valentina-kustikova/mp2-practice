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
				

		/*
		TPolynom p1("3.3*x*y - 1.1*x^2");
		TPolynom p2("5.5*x*y - 3.3*x^2");
		TPolynom expP("-2.2*x*y + 2.2*x^2");

		TPolynom p3(p1 - p2);
		*/

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
	}
	catch (string exp) {
		cout << exp << endl;
		//cout << "Error" << endl;
	}
	
	return 0;
}