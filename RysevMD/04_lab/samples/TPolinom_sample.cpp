#include <iostream>
#include "TPolynom.h"

using namespace std;

int main() { 
	TPolynom polynom1;
	TPolynom polynom2;
	double x, y, z;

	cout << endl << "--------- Creating polynoms ----------" << endl;
	cout << "Enter the first polynom: "; cin >> polynom1;
	cout << "Enter the second polynom: "; cin >> polynom2;
	cout << endl << "First polynom: " << polynom1 << endl;
	cout << "Second polynom: " << polynom2 << endl;

	cout << endl << "---------- Math operations with polynoms ----------" << endl;
	cout << ">>> Sum of two polynom <<<" << endl;
	cout << polynom1 + polynom2 << endl;
	cout << ">>> Difference of two polynom <<<" << endl;
	cout << polynom1 - polynom2 << endl;
	cout << ">>> Mul of two polynom <<<" << endl;
	polynom2 *= -1;
	cout << polynom1 * polynom2 << endl;
	cout << ">>> Mul of polynom and number <<<" << endl;
	polynom1 *= 10;
	cout << polynom1 << endl;
	cout << ">>> Differentiation by X <<<" << endl;
	cout << polynom1.dif_x() << endl;
	cout << ">>> Differentiation by Y <<<" << endl;
	cout << polynom1.dif_y() << endl;
	cout << ">>> Differentiation by Z <<<" << endl;
	cout << polynom1.dif_z() << endl;
	cout << ">>> Calculating <<<" << endl;
	cout << "Enter X: "; cin >> x;
	cout << "Enter Y: "; cin >> y;
	cout << "Enter Z: "; cin >> z;
	cout << "First polynom in dot x: " << x << " y: " << y << " z: " << z << ": " << polynom1(x, y, z) << endl;

	cout << endl << "---------- The end ----------" << endl;
	return 0; 
}