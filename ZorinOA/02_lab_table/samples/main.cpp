#include <iostream>
#include <string>
#include "ScanTable.h"

using namespace std;

int main()
{
	ScanTable<string, int> T(5);
	int* f = new int;
	*f = 5;
	int* s = new int;
	*s = 6;


	T.Insert("six", s);
	T.Insert("six", s);
	T.Insert("six", s);
	T.Insert("six", s);
	T.Insert("six", s);
	//T.Delete("six");
	int* tmp = T.Find("five");
	cout << (tmp == nullptr) << endl;

    delete f;
    delete s;
	return 0;
}
