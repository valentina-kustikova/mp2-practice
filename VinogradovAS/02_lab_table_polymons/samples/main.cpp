#include "scanTable.h"
#include "hashTable.h"
#include "sortTable.h"
#include "node.h"
#include "monom.h"
#include "polinom.h"
#include <iostream>
#include <headlist.h>


using namespace std;
int main() {
	string str = "x";
	TPolynom p(str);
	string str1 = "y";
	TPolynom p1(str1);
	string str2 = "1";
	TPolynom p2(str2);
	string str3 = "x2";
	TPolynom p3(str3);
	string str4 = "y2";
	TPolynom p4(str4);
	////cout << p;
	ScanTable<TPolynom, string> T1(5);
	
	T1.Insert(p4, str4);
	T1.Insert(p1, str1);
	T1.Insert(p2, str2);
	T1.Insert(p3, str3);
	T1.Insert(p, str);
	
	//T1.Delete(str1);
	//ScanTable<TPolynom, string> T2(T1);
	//cout << T2;
	//cout << T1 << endl << endl;
	////T1.Delete(str);
	////cout << T1;
	///*ScanTable<TPolynom, string> b(2);
	//SortTable<TPolynom, string> T2(T1);*/
	//
	//cout << T1 << endl << endl;
	/*ScanTable<int, int> T1(3);
	T1.Insert(1, 11);
	T1.Insert(2, 22);
	T1.Insert(3, 33);
	cout << T1 << endl << endl;*/
	SortTable<TPolynom, string> S(T1);
	/*S.Insert(p1, str1);
	S.Insert(p2, str2);
	S.Insert(p3, str3);
	S.Insert(p, str);
	S.Insert(p4, str4);*/
	cout << S << endl;
	S.Delete("y");
	cout << S;
	return 0;
}
