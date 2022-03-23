#include "polinom.h"
#include "monom.h"
#include "list.h"
#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	TPolinom res;
	int flag = 1, k = 0;
	while (flag == 1)
	{
		cout << "Введите первый полином" << endl;
		string s1;
		cin >> s1;
		TPolinom S1(s1);
		cout << "Введите второй полином" << endl;
		string s2;
		cin >> s2;
		TPolinom S2(s2);
		cout << "Выберите операцию" << endl;
		cout << "1) Операция сложения" << endl;
		cout << "2) Операция вычитания" << endl;
		cout << "3) Операция умножения" << endl;
		cout << "4) Операция умножения на константу" << endl;
		cout << "5) Вычисление полинома" << endl;
		cin >> k;
		switch(k)
		{
		case 1:
		{
			res = S1 + S1;
			cout << res;
			break;
		}
		case 2:
		{
			res = S1 - S2;
			cout << res;
			break;
		}
		case 3:
		{
			res = S1 * S2;
			cout << res;
			break;
		}
		case 4:
		{
			double con;
			cout << "Введите значение константы" << endl;
			cin >> con;
			res = S1 * con;
			cout << res;
			break;
		}
		case 5:
		{
			res.calculation();
			break;
		}
		default:
			break;
		}
	}
}