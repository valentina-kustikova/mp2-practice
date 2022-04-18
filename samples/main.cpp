#include "polinom.h"

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	string s1;
	string s2;
	int q = 2;
	int k;
	while (q == 2)
	{
		cout << "Введите первый полином. Необходимо использовать только переменные x, y, z." << endl;
		cin >> s1;
		Polinom P1(s1);
		cout << "Выберите операцию." << endl;
		cout << "1) Сложение полиномов." << endl;
		cout << "2) Вычитание полиномов." << endl;
		cout << "3) Умножение полиномов." << endl;
		cout << "4) Умножение полинома на константу" << endl;
		cin >> k;
		switch (k)
		{
		case 1:
		{
			cout << "Введите второй полином." << endl;
			cin >> s2;
			Polinom P2(s2);
			cout << "Результат:" << P1 + P2;
			break;
		}
		case 2:
		{
			cout << "Введите второй полином." << endl;
			cin >> s2;
			Polinom P2(s2);
			cout << "Результат:" << P1 - P2;
			break;
		}
		case 3:
		{
			cout << "Введите второй полином." << endl;
			cin >> s2;
			Polinom P2(s2);
			cout << "Результат:" << P1 * P2;
			break;
		}
		case 4:
		{
			double d;
			cout << "Введите константу." << endl;
			cin >> d;
			cout << "Результат:" << P1 * d;
			break;
		}
		}

		cout << "\n Выйти? " << endl;
		cout << "1)Да. " << endl;
		cout << "2)Нет. " << endl;
		cin >> q;

	}
}