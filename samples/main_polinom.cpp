
#include "monom.h"
#include "polinom.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define RANDOM 100
void menu() {
	cout << "МЕНЮ:\n" << endl;
	cout << "1.Ввести полиномы..." << endl;
	cout << "2.Вывести полиномы..." << endl;
	cout << "3.Сложить введённые полиномы..." << endl;
	cout << "4.Вычесть введённые полиномы..." << endl;
	cout << "5.Умножить введённые полиномы..." << endl;
	cout << "6.Сохранить результат вычислений" << endl;
	cout << "7.Сосчитать полином с заданными x,y,z" << endl;
	cout << "-------------------------------------" << endl;
	cout << "Доп.опции:" << endl;
	cout << "8.Найти частную производную по х" << endl;
	cout << "9.Найти частную производную по y" << endl;
	cout << "10.Найти частную производную по z" << endl;
	cout << "11.Продифференцировать полиномы" << endl;
	cout << "__________________________________________________WARNING____________________________________________________________" << endl;
	cout << "1)Если вы не ввели полиномы, то пункты 2-5 будут задействовать заготовленные полиномы" << endl;
	cout << "2)Ввод полинома подразумевает правильное написание вида 2x^4y^5z^6,где важно отсутсвие посторонних " << endl;
	cout << "  символов, а связь между мономами обязательно выстраивается через написанные знаки '+','-'." << endl;
	cout << "3)Вычитание необходимо проводить из полинома с большим количеством мономов Прим: (5x^2y^2z^3+123x^4) - (69x^3y^4z^9)." << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "0.Exit " << endl;
	cout << ">>";
}

int  main()
{
	Polinom A;
	string STR;
	A.str_to_poly("0.5x^2z^7+20x^4");
	//A.showList2();
	Polinom B;
	B.str_to_poly("0.5x^2z^7");
	Polinom RES;
	Polinom SAVE;
	bool N1 = 0;
	bool N2 = 0;
	bool S1 = 0;
	bool S2 = 0;
	setlocale(LC_ALL, "Russian");
	int t = 999;
	cout << "Добро пожаловать в крутую программу расчётов полиномов!\n" << endl;

	while (t != 0)
	{
		setlocale(LC_ALL, "Russian");
		menu();
		cin >> t;
		cout << "_____________________________________________________________________________________________________________________" << endl;
		switch (t)
		{
		case 1:
		{
			int d = 0;
			do {
				cout << "Выберите вводимый полином:" << endl;
				cout << "Для выбора А, введите 1" << endl;
				cout << "Для выбора B, введите 2" << endl;
				cout << "Для замены А на SAVE, введите 3" << endl;
				cout << "Для замены B на SAVE, введите 4" << endl;
				cin >> d;
				if ((d > 4) || (d < 1))  cout << ("ОШИБКА НЕПРАВИЛЬНЫЙ ВВОД") << endl;
			} while ((d > 4) || (d < 1));
			if (d == 1) {
				cout << "Введите полином А:";
				cin >> STR;
				A *= 0;
				A.podobnyi();
				setlocale(LC_ALL, "English");
				A.str_to_poly(STR);
				setlocale(LC_ALL, "Rus");
				N1 = 1;
			}
			if (d == 2) {
				cout << "Введите полином B:";
				cin >> STR;
				B *= 0;
				B.podobnyi();
				setlocale(LC_ALL, "English");
				B.str_to_poly(STR);
				setlocale(LC_ALL, "Rus");
				N2 = 1;
			}
			if (d == 3) {
				if (S2 == 0) cout << "SAVE пустой, сначала посчитайте что-нибудь и сохраните!" << endl;
				else {
					cout << "Теперь A=SAVE";
					A = SAVE;
				}
			}
			if (d == 4) {
				if (S2 == 0) cout << "SAVE пустой, сначала посчитайте что-нибудь и сохраните!" << endl;
				else {
					cout << "Теперь B=SAVE";
					B = SAVE;
				}
			}
			break;
		}
		case 2:
		{
			int d1;
			do {
				cout << "Выберите выводимый полином:" << endl;
				cout << "Для выбора А, введите 1" << endl;
				cout << "Для выбора B, введите 2" << endl;
				cout << "Для выбора SAVE, введите 3" << endl;

				cin >> d1;
				if ((d1 > 3) || (d1 < 1))  cout << ("ОШИБКА НЕПРАВИЛЬНЫЙ ВВОД") << endl;
			} while ((d1 > 3) || (d1 < 1));
			if (d1 == 1) {
				cout << "Полином А:";
				A.showList();
			}
			if (d1 == 2) {
				cout << "Полином B:";
				B.showList();
			}
			if (d1 == 3) {
				if (S1 == 0) cout << "Нечего выводить, сначала посчитайте что-нибудь!" << endl;
				else {
					cout << "Полином SAVE:";
					SAVE.showList();
				}
			}
			break;
		}
		case 3:
		{
			if (N1 == 0) {
				cout << "____________________WARNING___________________" << endl;
				cout << "Полином A задан готовым примером" << endl;
				cout << "A="; A.showList();
				cout << "______________________________________________" << endl;

			}
			if (N2 == 0) {
				cout << "____________________WARNING___________________" << endl;
				cout << "Полином B задан готовым примером" << endl;
				cout << "B="; B.showList();
				cout << "______________________________________________" << endl;

			}
			int d2;
			do {
				cout << "Сложить введённые полиномы:" << endl;
				cout << "1.Друг с другом (A+B)" << endl;
				cout << "2.Полином A с введённым мономом" << endl;
				cout << "3.Полином B с введённым мономом" << endl;
				cout << "4.Полином A с введённым скаляром" << endl;
				cout << "5.Полином B с введённым скаляром" << endl;
				cin >> d2;
				if ((d2 > 5) || (d2 < 1))  cout << ("ОШИБКА НЕПРАВИЛЬНЫЙ ВВОД") << endl;
			} while ((d2 > 5) || (d2 < 1));

			if (d2 == 1)
			{
				cout << "Сумма полиномов A и B:";
				RES = A + B;
				RES.podobnyi();
				S1 = 1;
				cout << "A+B="; A.showList3(); B.showList3(); cout << "="; RES.showList3(); cout << "\n";
				//A.showList();
			}
			if (d2 == 2)
			{
				double koef = 0;
				int x, y, z;
				cout << "Введите условия монома a:";
				cin >> koef >> x >> y >> z;
				Node ptr(koef, x, y, z);
				RES = A + ptr;
				RES.podobnyi();
				S1 = 1;

				cout << "A+a="; RES.showList3(); cout << "\n";
			}
			if (d2 == 3)
			{
				double koef = 0;
				int x, y, z;
				cout << "Введите условия монома a:";
				cin >> koef >> x >> y >> z;
				Node ptr(koef, x, y, z);
				RES = B + ptr;
				RES.podobnyi();
				S1 = 1;

				cout << "B+a="; RES.showList3(); cout << "\n";
			}
			if (d2 == 4)
			{
				double scalar = 0;
				cout << "Введите скаляр:";
				cin >> scalar;
				RES = A + scalar;
				RES.podobnyi();
				S1 = 1;

				cout << "A+scalar="; RES.showList3(); cout << "\n";
			}
			if (d2 == 5)
			{
				double scalar = 0;
				cout << "Введите скаляр:";
				cin >> scalar;
				RES = B + scalar;
				RES.podobnyi();
				S1 = 1;

				cout << "B+scalar="; RES.showList3(); cout << "\n";
			}
			break;
		}
		case 4:
		{
			if (N1 == 0) {
				cout << "____________________WARNING___________________" << endl;
				cout << "Полином A задан готовым примером" << endl;
				cout << "A="; A.showList();
				cout << "______________________________________________" << endl;

			}
			if (N2 == 0) {
				cout << "____________________WARNING___________________" << endl;
				cout << "Полином B задан готовым примером" << endl;
				cout << "B="; B.showList();
				cout << "______________________________________________" << endl;

			}
			int d2;
			do {
				cout << "Вычесть введённые полиномы:" << endl;
				cout << "1.Один из другого (A-B)" << endl;
				cout << "2.Один из другого (B-A)" << endl;
				cout << "3.Полином A с введённым мономом" << endl;
				cout << "4.Полином B с введённым мономом" << endl;
				cout << "5.Полином A с введённым скаляром" << endl;
				cout << "6.Полином B с введённым скаляром" << endl;
				cin >> d2;
				if ((d2 > 5) || (d2 < 1))  cout << ("ОШИБКА НЕПРАВИЛЬНЫЙ ВВОД") << endl;
			} while ((d2 > 5) || (d2 < 1));
			cout << "_____________________________________WARNING___________________________________" << endl;
			cout << "Учитывайте количество мономов в полиномах" << endl;
			cout << "Количество мономов в уменьшаемом должно быть >= Количеству мономов в вычитаемом" << endl;
			cout << "A="; A.showList();
			cout << "B="; A.showList();
			cout << "_______________________________________________________________________________" << endl;
			if (d2 == 1)
			{
				cout << "Разность полиномов A и B:";
				RES = A - B;
				RES.podobnyi();
				S1 = 1;

				cout << "A-B="; A.showList3(); cout << "-("; B.showList3(); cout << ")="; RES.showList3(); cout << "\n";
				//A.showList();
			}
			if (d2 == 2)
			{
				cout << "Разность полиномов B и A:";
				RES = B - A;
				RES.podobnyi();
				S1 = 1;

				cout << "B-A="; B.showList3(); cout << "-("; A.showList3(); cout << ")="; RES.showList3(); cout << "\n";
				//A.showList();
			}
			if (d2 == 3)
			{
				double koef = 0;
				int x, y, z;
				cout << "Введите условия монома a:";
				cin >> koef >> x >> y >> z;
				Node ptr(koef, x, y, z);
				RES = A - ptr;
				RES.podobnyi();
				S1 = 1;

				cout << "A-a="; RES.showList3(); cout << "\n";
			}
			if (d2 == 4)
			{
				double koef = 0;
				int x, y, z;
				cout << "Введите условия монома a:";
				cin >> koef >> x >> y >> z;
				Node ptr(koef, x, y, z);
				RES = B - ptr;
				RES.podobnyi();
				S1 = 1;

				cout << "B-a="; RES.showList3(); cout << "\n";
			}
			if (d2 == 5)
			{
				double scalar = 0;
				cout << "Введите скаляр:";
				cin >> scalar;
				RES = A - scalar;
				RES.podobnyi();
				S1 = 1;

				cout << "A-scalar="; RES.showList3(); cout << "\n";
			}
			if (d2 == 6)
			{
				double scalar = 0;
				cout << "Введите скаляр:";
				cin >> scalar;
				RES = B - scalar;
				RES.podobnyi();
				S1 = 1;

				cout << "B-scalar="; RES.showList3(); cout << "\n";
			}
			break;
		}
		case 5:
		{
			if (N1 == 0) {
				cout << "____________________WARNING___________________" << endl;
				cout << "Полином A задан готовым примером" << endl;
				cout << "A="; A.showList();
				cout << "______________________________________________" << endl;

			}
			if (N2 == 0) {
				cout << "____________________WARNING___________________" << endl;
				cout << "Полином B задан готовым примером" << endl;
				cout << "B="; B.showList();
				cout << "______________________________________________" << endl;

			}
			int d2;
			do {
				cout << "Умножить введенные полиномы:" << endl;
				cout << "1.Один на другой A*B" << endl;
				cout << "2.Полином A на введённый мономом" << endl;
				cout << "3.Полином B на введённый мономом" << endl;
				cout << "4.Полином A на введённый скаляр" << endl;
				cout << "5.Полином B на введённый скаляр" << endl;
				cin >> d2;
				if ((d2 > 5) || (d2 < 1))  cout << ("ОШИБКА НЕПРАВИЛЬНЫЙ ВВОД") << endl;
			} while ((d2 > 5) || (d2 < 1));

			if (d2 == 1)
			{
				cout << "Один на другой A*B";
				RES = A * B;
				RES.podobnyi();
				S1 = 1;

				cout << "A*B="; A.showList3(); cout << "*("; B.showList3(); cout << ")="; RES.showList3(); cout << "\n";
				//A.showList();
			}
			if (d2 == 2)
			{
				double koef = 0;
				int x, y, z;
				cout << "Введите условия монома a:";
				cin >> koef >> x >> y >> z;
				Node ptr(koef, x, y, z);
				RES = A * ptr;
				RES.podobnyi();
				S1 = 1;

				cout << "A*a="; RES.showList3(); cout << "\n";
			}
			if (d2 == 3)
			{
				double koef = 0;
				int x, y, z;
				cout << "Введите условия монома a:";
				cin >> koef >> x >> y >> z;
				Node ptr(koef, x, y, z);
				RES = B * ptr;
				RES.podobnyi();
				S1 = 1;

				cout << "B*a="; RES.showList3(); cout << "\n";
			}
			if (d2 == 4)
			{
				double scalar = 0;
				cout << "Введите скаляр:";
				cin >> scalar;
				RES = A * scalar;
				RES.podobnyi();
				S1 = 1;

				cout << "A*scalar="; RES.showList3(); cout << "\n";
			}
			if (d2 == 5)
			{
				double scalar = 0;
				cout << "Введите скаляр:";
				cin >> scalar;
				RES = B * scalar;
				RES.podobnyi();
				S1 = 1;

				cout << "B*scalar="; RES.showList3(); cout << "\n";
			}
			break;
		}
		case 6:
		{
			if (S1 == 0) cout << "Нечего сохранять, сначала посчитайте что-нибудь!" << endl;
			else {
				SAVE = RES;
				cout << "Результат вычислений сохранён!0" << endl;
				S2 = 1;
			}
			break;
		}
		case 7:
		{
			double x = 0, y = 0, z = 0;
			double res = 0;
			cout << "Введите через пробел значения x,y,z:" << endl;
			cin >> x;
			cin >> y;
			cin >> z;
			int d3 = 0;
			do {
				cout << "Выберите считаемый полином:" << endl;
				cout << "Для выбора А, введите 1" << endl;
				cout << "Для выбора B, введите 2" << endl;
				cout << "Для выбора SAVE, введите 3" << endl;

				cin >> d3;
				if ((d3 > 3) || (d3 < 1))  cout << ("ОШИБКА НЕПРАВИЛЬНЫЙ ВВОД") << endl;
			} while ((d3 > 3) || (d3 < 1));

			if (d3 == 1) {
				auto ita = A.begin();
				do {
					ita++;
					res += ((*ita).data.coef) * (pow(x, ((*ita).data.degx))) * (pow(y, ((*ita).data.degy))) * (pow(z, ((*ita).data.degz)));
				} while ((*ita).next != NULL);
				cout << "Результат res=" << res << endl;
				res = 0;
			}
			if (d3 == 2) {
				auto itb = B.begin();
				do {
					itb++;
					res += ((*itb).data.coef) * (pow(x, ((*itb).data.degx))) * (pow(y, ((*itb).data.degy))) * (pow(z, ((*itb).data.degz)));
				} while ((*itb).next != NULL);
				cout << "Результат res=" << res << endl;
				res = 0;

			}
			if (d3 == 3) {
				if (S2 == 0) cout << "SAVE пустой, сначала посчитайте что-нибудь и сохраните!" << endl;
				else {
					auto its = SAVE.begin();
					do {
						its++;
						res += ((*its).data.coef) * (pow(x, ((*its).data.degx))) * (pow(y, ((*its).data.degy))) * (pow(z, ((*its).data.degz)));
					} while ((*its).next != NULL);
					cout << "Результат res=" << res << endl;
					res = 0;
				}
			}

			break;
		}
		//system("Pause");
		}
	}
	return 0;
}
