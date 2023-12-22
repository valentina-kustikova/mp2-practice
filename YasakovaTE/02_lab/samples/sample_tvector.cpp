#include "tvector.h"


void test_tvector()
{
	TVector<int> v1(4), v2(4);
	cout << "Input the 2 vectors with length 4:\n";
	cin >> v1 >> v2;
	cout << "First vector:\n" << v1 << endl;
	cout << "Second vector:\n" << v2 << "\n\n";
	cout << "v1+v2: " << v1 + v2 << endl;
	cout << "v1-v2: " << v1 - v2 << endl;
	cout << "v1*v2: " << v1 * v2 << endl;
	cout << "v1-2: " << v1 - 2 << endl;
	cout << "v2 + 2: " << v2 + 2 << endl;
	cout << "v1*2: " << v1 * 2 << endl;
	cout << "v1.size(): " << v1.GetSize() << endl;
	cout << "v1 == v2: " << (v1 == v2) << endl;
	v1 = v2;
	cout << "v1 == v2 after v1 = v2: " << (v1 == v2) << endl;
	cout << "v1[1]: " << v1[1] << endl;
	cout << "v2[0]: " << v2[0] << endl;
	cout << "v1 != v2: " << (v1 != v2) << endl;

	cout << "OK" << endl;
	return;
}

int  main()
{
	test_tvector();
	return 0;
}