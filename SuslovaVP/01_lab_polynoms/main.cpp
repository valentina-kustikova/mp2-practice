#pragma once
#include "polinom.h"

using namespace std;

void main()
{
	string s1;
	string s2;
	int q = 2;
	int k;
	while (q == 2)
	{
		cout << "Write one Polinom." << endl;
		cin >> s1;
		Polinom P1(s1);
		cout << "Choose." << endl;
		cout << "1)  +" << endl;
		cout << "2)  -" << endl;
		cout << "3)  *" << endl;
		cout << "4)  * d" << endl;
		cin >> k;
		switch (k)
		{
		case 1:
		{
			cout << "Write second Polinom." << endl;
			cin >> s2;
			Polinom P2(s2);
			cout << "Result:" << P1 + P2;
			break;
		}
		case 2:
		{
			cout << "Write second Polinom." << endl;
			cin >> s2;
			Polinom P2(s2);
			cout << "Result:" << P1 - P2;
			break;
		}
		case 3:
		{
			cout << "Write second Polinom." << endl;
			cin >> s2;
			Polinom P2(s2);
			cout << "Result:" << P1 * P2;
			break;
		}
		case 4:
		{
			double d;
			cout << " Write d" << endl;
			cin >> d;
			cout << "Result:" << P1 * d;
			break;
		}
		}

		cout << "\n Exit: " << endl;
		cout << " 1)Yes. " << endl;
		cout << " 2)No. " << endl;
		cin >> q;

	}
}