#include <iostream>
#include "tvector.h"

using namespace std;

int main() {
	cout << "TVector\n" << endl;

	try {
		int size = 4;
		int startind = 2;
		int scalar = 2;

		TVector<int> v1(size);
		TVector<int> v2(size);

		cout << "input example:\n1 2 3 4 4 3 2 1\n" << endl;
		// 1 2 3 4 4 3 2 1

		cin >> v1 >> v2;
		cout << endl;
		cout << "v1 = " << v1 << endl;
		cout << "v2 = " << v2 << '\n' << endl;

		/*// copy and operator= test
		TVector<int> v3(v1);
		cout << v3 << endl;
		v3 = v2;
		cout << v3 << endl;
		*/

		cout << "v1 * scalar = " << v1 * scalar << endl;
		cout << "v1 + scalar = " << v1 * scalar << endl;
		cout << "v1 - scalar = " << v1 * scalar << '\n' << endl;

		cout << "v1 + v2 = " << v1 + v2 << endl;
		cout << "v1 - v2 = " << v1 - v2 << endl;
		cout << "v1 * v2 = " << v1 * v2 << '\n' << endl;

		cout << "(v1 == v2) = " << (v1 == v2) << endl;
		cout << "(v1 != v2) = " << (v1 != v2) << '\n' << endl;

		cout << "v1[3] = " << v1[3] << endl;
		cout << "v1.GetSize() = " << v1.GetSize() << endl;
		cout << "v1.GetStartIndex() = " << v1.GetStartIndex() << '\n' << endl;

		TVector<int> v3(size, startind);
		v3[0 + startind] = 1;
		v3[1 + startind] = 2;
		v3[2 + startind] = 3;
		v3[3 + startind] = 4;
		cout << "v3.GetStartIndex() = " << v3.GetStartIndex() << endl;
		cout << "v3 = " << v3 << endl;
		cout << "v3[2] = " << v3[2] << endl;
		//cout << "v3[0] = " << v3[0] << endl;
	}
	catch (string exp) {
		cout << exp;
	}
	
	return 0;
}