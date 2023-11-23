#include <iostream>
#include "vector.h"

int main()
{
	int len;
	cout << "Specify the length of the vector:"<<"\t";
	cin >> len;
	TVector<int> vector1(len), vector2(len);
	cout << "Enter the coordinates of the first vector:" << endl;
	cin >> vector1;
	cout << "Enter the coordinates of the second vector:" << endl;
	cin >> vector2;
	cout << "Vector 1:" << "\t" << vector1;
	cout << "Vector 2:" << "\t" << vector2;
	cout << "Lenght Vector`s 1: " << vector1.getSize() << endl;
	cout << "Lenght Vector`s 2: " << vector2.getSize() << endl;
	cout << "Vector 1 + vector 2:" << "\t" << vector1 + vector2;
	cout << "Vector 1 - vector 2:" << "\t" << vector1 - vector2;
	cout << "Vector 1 * vector 2:" << "\t" << vector1 * vector2 << endl;
	cout << "Vector 1 - one:" << "\t" << vector1 - 1;
	cout << "Vector 2 * three:" << "\t" << vector2 * 3;
	cout << "Vector 1 == vector 2" << "\t" << (vector1 == vector2) << endl;
	cout << "Vector 1 != vector 2" << "\t" << (vector1 != vector2) << endl;
	return 0;
}