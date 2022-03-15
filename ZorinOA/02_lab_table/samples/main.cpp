#include <iostream>
#include <string>
#include "ScanTable.h"
#include "SortTable.h"

using namespace std;



unsigned long HashFunc(const string& s, unsigned long p)
{
	unsigned long Res = s[0];
	for (int i = 1; i < s.length(); i++)
	{
		Res += s[i] * p;
		p *= p;
	}
	return Res;
}

int main()
{
	unsigned long tmp = HashFunc("5x^2y^7 + 4x^3 + 5y", 17);
	tmp %= 25;
	cout << tmp << endl;


	return 0;
}
