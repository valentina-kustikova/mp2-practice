#include <iostream>
#include "tmatrix.h"

using namespace std;

int main() {
	cout << "TMatrix\n" << endl;
	
	try {
		int size = 3;

		cout << "Enter the values of the elements of two " << size << "x" << size << " upper triangular vectors." << endl;
		cout << "input example:\n1 2 3 4 5 6 6 5 4 3 2 1\n" << endl;
		// 1 2 3 4 5 6 6 5 4 3 2 1
		// 2 2 2 2 2 2 3 3 3 3 3 3

		TMatrix<int> m1(size);
		TMatrix<int> m2(size);
		cin >> m1;
		cin >> m2;
		
		cout << endl;
		cout << "m1 = \n" << m1 << endl;
		cout << "m2 = \n" << m2 << endl;
		
		cout << "m1[1] = " << m1[1] << endl;
		cout << "m1[1][1] = " << m1[1][1] << endl;

		cout << "\nm1 + m2 = \n" << m1 + m2 << endl;
		cout << "m1 - m2 = \n" << m1 - m2 << endl;
		cout << "m1 * m2 = \n" << m1 * m2 << '\n' << endl;

		cout << "(m1 == m2) = " << (m1 == m2) << endl;
		cout << "(m1 != m2) = " << (m1 != m2) << '\n' << endl;
	}
	catch (string exp) {
		cout << exp << endl;
	}

	return 0;
}