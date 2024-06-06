
#include "tlist.h"
#include "tringlist.h"
#include "tmonom.h"
#include<iostream>
#include<string>

using namespace std;

int main()
{
	TMonom fst(-2, 123);

	cout << fst << endl;

	cout <<"dif_x:"<< fst.dif_x() << endl;

	cout << "value: " << fst.GetValue(1, 3, 1) << endl;

	return 0;
}


