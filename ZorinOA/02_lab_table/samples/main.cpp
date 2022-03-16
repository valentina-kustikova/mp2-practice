#include <iostream>
#include "HashTable.h"
#include "ScanTable.h"
#include "SortTable.h"

using namespace std;

int main()
{
	HashTable<string, int> H(10);
	H.Insert("first", 1);
	H.Insert("second", 2);
	H.Insert("third", 3);
	H.Insert("fourth", 4);
	H.Insert("fifth", 5);
	H.Insert("sixth", 6);
	H.Insert("seventh", 7);
	cout << H << endl;
	/*List<string> L;
	L.InsertToHead("first");
	L.InsertToHead("second");
	L.InsertToHead("third");
	L.InsertToHead("fourth");
	cout << L << endl;*/

	

	return 0;
}
