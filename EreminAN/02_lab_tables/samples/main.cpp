//main

#include "ScanTable.h"



void main()
{

	ScanTable<int> S(5);
	string K1 = "1";
	string K2 = "2";
	int* f = new int(5);
	int* f2 = new int(10);
	S.InsRecord(K1,f);
	S.InsRecord(K2, f2);
	cout << S;
}