#include <iostream>
#include "vector.h"

int main()
{
	int len;
	cout << "Enter the vector lenght:";
	cin >> len;
	TVector<int> vect_1(len), vect_2(len);
	cout << "Enter the first vector:" << endl;;
	cin >> vect_1;
	cout << "Enter the second vector:" << endl;;
	cin >> vect_2;
	cout << "vector 1:" << vect_1 << endl;
	cout << "vector 2:" << vect_2 << endl;
	cout << "vector 1 + vector 2:" << vect_1 + vect_2 << endl;
	cout << "vector 1 - vector 2:" << vect_1 - vect_2 << endl;
	cout << "vector 1 * vector 2:" << vect_1 * vect_2 << endl;
	cout << "Lenght:" << vect_1.getSize() << endl;
	return 0;
}