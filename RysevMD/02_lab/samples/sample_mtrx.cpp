#include <iostream>
#include "TMatrix.h"

using namespace std;

int main() {
	TMatrix<int> mtr1(3), mtr2(3);
	cout << "matrix input format (size = n):\n";
	cout << "a11 a12 a13 ... a1n\n";
	cout << "    a22 a23 ... a2n\n";
	cout << "        a33 ... a3n\n";
	cout << "...................\n";
	cout << "                ann\n\n";

	cout << "Enter mtr1 (size = 3):\n";
	cin >> mtr1;
	cout << "Enter mtr2 (size = 3):\n";
	cin >> mtr2;

	TMatrix<int> mtr_sum(3), mtr_dif(3), mtr_mul(3);
	cout << "\nmatr-matr operation";
 	mtr_sum = mtr1 + mtr2;
	mtr_dif = mtr1 - mtr2;
	mtr_mul = mtr1 * mtr2;
	cout << "\nmtr1 + mtr2\n" << mtr_sum << "\nmtr1 - mtr2\n" << mtr_dif << "\nmtr1 * mtr2\n" << mtr_mul << endl;

	cout << "\nbool operation";
	cout << "\nmtr1 == mtr2? - " << (mtr1 == mtr2) << "\nmtr1 != mtr2? - " << (mtr1 != mtr2);
	return 0;
}