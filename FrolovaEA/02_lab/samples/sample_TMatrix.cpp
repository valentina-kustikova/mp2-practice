#include <iostream>
#include "TVector.h"
#include "TMatrix.h"

using namespace std;

int main()
{
	

	setlocale(LC_ALL, "Russian");
	cout << "Testing of triangular matrix support programs" << endl;
	int size;
	cout << "enter size of upper triangular matrix :";
	cin >> size;
	cout << endl;
	cout << "enter the elements into the upper triangular length matrix " << size << endl;
	TMatrix<int> a(size), b(size), c(size);

	cout << "enter matrix 1 : ";
	cin >> a;
	cout << endl;

	cout << "enter matrix 2: ";
	cin >> b;
	cout << endl;

	
	c = a + b;
	cout << "Matrix a = " << endl << a << endl;
	cout << "Matrix b = " << endl << b << endl;
	cout << "a[0] :" << a[0] << endl;
	cout << "a[0][1] :" << a[0][1] << endl;
	cout << "Matrix c = a + b" << endl << c << endl;
	cout << "equality check " << endl;
	cout << "a == b  ? :" << (a == b)<<endl;
	cout << "Matrix c = a - b" << endl << a-b << endl;
	cout << "a * b = " <<endl<< (a * b) << endl;
//	cout << "a*b" << endl << a * b;

	return 0;
}
