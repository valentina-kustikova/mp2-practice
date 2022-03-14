#include <iostream>
#include <string>
#include "ScanTable.h"
#include "SortTable.h"

using namespace std;

int main()
{
	ScanTable<string, int> T(5);
    int s = 6;
    int f = 5;


	T.Insert("six", s);
	T.Insert("six", s);
	T.Insert("six", s);
	T.Insert("six", s);
	T.Insert("six", s);
    T.Delete("six");
    T.Insert("five", f);
    int* tmp = T.Find("five");

    cout << *tmp << endl;

    SortTable<string, int> S(5);
    S.Insert("b", 2);
    S.Insert("z", 10);
    S.Insert("e", 5);
    S.Insert("f", 9);
    S.Delete("b");
    tmp = S.Find("f");
    cout << *tmp << endl;

	return 0;
}
