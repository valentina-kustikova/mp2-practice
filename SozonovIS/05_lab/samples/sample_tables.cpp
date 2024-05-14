#include "scan_table.h"
#include "sorted_table.h"
#include "array_hash_table.h"
#include "tpolynom.h"

#include <iostream>

using namespace std;
 
int main() { 
	ScanTable<string, TPolynom> sct(100);
	SortedTable<string, TPolynom> srt(100);
	ArrayHashTable<string, TPolynom> hst(100, 10);

	string str = "6*x^3*y^2*z";
	TPolynom p(str);

	sct.Insert(str, &p);
	srt.Insert(str, &p);
	hst.Insert(str, &p);

	cout << sct;
	cout << endl;
	cout << srt;
	cout << endl;
	cout << hst;

	return 0;
}
