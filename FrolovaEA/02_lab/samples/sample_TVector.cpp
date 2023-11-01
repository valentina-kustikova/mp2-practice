
#include <clocale>
#include <iomanip>
#include <iostream>
//#include <cmath>
#include<math.h>

#include "TVector.h"

using namespace std;

int main()
{
	int a, size = 5, b;
	TVector<int> IntVec1(size);
	TVector<int> IntVec2(size);
	TVector<int> IntVec3(size);
	

	cout << "enter int vector 1 with lengh = "<< size<<" :" << endl;
	cin >> IntVec1;
	cout << "enter int vector 2 with lengh = " << size << " :" << endl;
	cin >> IntVec2;
	cout << "enter int vector 3 with lengh = " << size << " :" << endl;
	cin >> IntVec3;
	cout << "vector 1 :" << IntVec1 << endl;
	cout << "vector 2 :" << IntVec2 << endl;
	cout << "vector 3 :" << IntVec3 << endl;

	cout << "vector 1 + 3 = " << IntVec1 + 3 << endl;
	cout << "vector 2 - 3 = " << IntVec2 - 3 << endl;
	cout << "vector 3 * 3 = " << IntVec3 * 3 << endl;

	a = (IntVec1 == IntVec2);

	cout << "(IntVec1 == IntVec2) :" << a << endl;

	cout << "vector 1  +  vector 2 = " << IntVec1 + IntVec2 << endl;
	cout << "vector 1  -  vector 2 = " << IntVec1 - IntVec2 << endl;
	cout << "vector 1  *  vector 2 = " << IntVec1 * IntVec2 << endl;
	IntVec3 = IntVec2;
	cout << "vector 3  =  vector 2 = " << IntVec3 << endl;

	b = (IntVec1 != IntVec3);
	cout << "(IntVector1 != IntVector3):" << b << endl;

	return 0;
}
