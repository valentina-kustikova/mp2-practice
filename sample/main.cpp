#include "polinom.h"
#include "list.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	bool flag = true;
	string s;
	int k;
	Polinom Res, Zero;
	int m = -1;

	cout << "Введите полином. Помните, вы можете использовать только буквы x,y,z, без пробелов и других посторонних символов:" << endl;
	getline(cin, s);
	Polinom P(s);
	cout << "Выберете действие:" << endl;
	cout << "1 - умножить на константу" << endl;
	cout << "2 - умножить на полином" << endl;
	cout << "3 - сложить с полиномом" << endl;
	cout << "4 - Вычитание полиномов" << endl;

	cin >> k;
	cin.ignore(2, '\n');

	if (k != 5)
	{
		cout << "f1=";
		cout << P << endl;

		switch (k)
		{
		case 1:
		{
			double d;
			cout << "Введите константное значение: " << endl;
			cin >> d;
			cout << "c=" << d << endl;
			cout << "c*f1=";
			Res = P * d;

			break;
		}
		case 2:
		{
			string s1;
			cout << "Введите второй полином: " << endl;
			getline(cin, s1);
			Polinom P1(s1);
			cout << "f2=" << P1 << endl;
			Res = P * P1;
			cout << "f1*f2=";
			break;
		}
		case 3:
		{
			string s2;
			cout << "Введите второй полином: " << endl;
			getline(cin, s2);
			Polinom P2(s2);
			cout << "f2=" << P2 << endl;
			Res = P + P2;
			cout << "f1+f2=";
			break;
		}
		case 4:
		{
			string s3;
			cout << "Введите второй полином: " << endl;
			getline(cin, s3);
			Polinom P3(s3);
			cout << "f2=" << P3 << endl;
			Res = P - P3;
			cout << "f2-f1=" << Res << endl;
			break;
		}
		}
		cout << Res << endl;

	}
	return 0;
}