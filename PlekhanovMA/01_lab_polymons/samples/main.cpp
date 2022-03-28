#include <iostream>
#include <string>
#include "monom.h"
#include "list.h"
#include "polinom.h"

using namespace std;

void Menu()
{
	system("cls"); // clear
	cout << "1 - Add polinom"
		 << endl << "2 - Subtruct polinom"
		 << endl << "3 - Multiply on constanta"
		 << endl << "4 - Multiply on polinom"
		 << endl << "5 - Input values"
		 << endl << "6 - Output polinoms"
		 << endl << "7 - Exit"
		 << endl << "8 - Clear console."
		 << endl;
}

int main()
{
	string str;
	string str2;
	TPolinom P;
	TPolinom Q;
	TPolinom C;
	cout << "Input first polinom: ";
	getline(cin, str, '\n');
	P.Input(str);
	P.StrToList();
	P.Similar();
	cout << "Input second polinom: ";
	getline(cin, str2, '\n');
	Q.Input(str2);
	Q.StrToList();
	Q.Similar();
	Menu();
	int sw, ch, x, y, z;
	double c, res1, res2;
	sw = 1;
	while (sw != 7)
	{
		cout << "Input number: ";
		cin >> sw;
		cin.ignore(32767, '\n');
		switch (sw)
		{
		case 1:
		{
			C = C + P;
			C = C + Q;
			C.Similar();
			cout << "First + second: " << C << endl;
			C.ClearPol();
			break;
		}
		case 2:
		{
			C = C + P;
			C = C - Q;
			C.Similar();
			cout << "First - second: " << C << endl;
			-Q;
			C.ClearPol();
			break;
		}
		case 3:
		{
			cout << "Input const: ";
			cin >> c;
			cin.ignore(32767, '\n');
			C = C + P;
			C = C * c;
			C.Similar();
			cout << "First * const: " << C << endl;
			C.ClearPol();
			C = C + Q;
			C = C * c;
			C.Similar();
			cout << "Second * const: " << C << endl;
			C.ClearPol();
			break;
		}
		case 4:
		{
			C = C + P;
			C = C * Q;
			C.Similar();
			cout << "First * second: " << C << endl;
			C.ClearPol();
			break;
		}
		case 5:
		{
			cout << "Input x: ";
			cin >> x;
			cin.ignore(32767, '\n');
			cout << "Input y: ";
			cin >> y;
			cin.ignore(32767, '\n'); 
			cout << "Input z: ";
			cin >> z;
			cin.ignore(32767, '\n');
			res1 = P.Values(x, y, z);
			res2 = Q.Values(x, y, z);
			cout << "First polinom result: " << res1 << endl;
			cout << "Second polinom result: " << res2 << endl;
			break;
		}
		case 6:
		{
			cout << "First polinom: " << P << endl;
			cout << "Second polinom: " << Q << endl;
			break;
		}
		case 8:
		{
			Menu();
			break;
		}
		default:
			break;
		}
	}
	return 0;
}
