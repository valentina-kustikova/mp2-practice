#include <iostream>
#include "HashTable.h"
#include "ScanTable.h"
#include "SortTable.h"
#include "polinom.h"

using namespace std;

int main()
{
	HashTable<string, Polinom> H(10);
	H.Insert("first", Polinom("3x"));
	H.Insert("second", Polinom("2y^5"));
	H.Insert("third", Polinom("12.3z^3"));
	H.Insert("fourth", Polinom("1.2"));
	H.Insert("fifth", Polinom("3x + 4y + 5"));
	H.Insert("sixth", Polinom("1.2 + 45 - 3.4y^1x^5"));
	H.Insert("seventh", Polinom("2.3x^2y^3z^7 + 3.2"));
	cout << H << endl;
	/*List<string> L;
	L.InsertToHead("first");
	L.InsertToHead("second");
	L.InsertToHead("third");
	L.InsertToHead("fourth");
	cout << L << endl;*/
	//Polinom A("3.1x^5y^4z^2 - 3z^5 + 6.333y^2 - 2x + 2x");
	//cout << A << endl;
	SortTable<string, Polinom> T(10);
	T.Insert("first", Polinom("3x"));
	T.Insert("second", Polinom("2y^5"));
	T.Insert("third", Polinom("12.3z^3"));
	T.Insert("fourth", Polinom("1.2"));
	T.Insert("fifth", Polinom("3x + 4y + 5"));
	T.Insert("sixth", Polinom("1.2 + 45 - 3.4y^1x^5"));
	T.Insert("seventh", Polinom("2.3x^2y^3z^7 + 3.2"));
	cout << T << endl;
	return 0;
}
