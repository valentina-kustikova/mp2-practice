#include <iostream>

#include "tset.h"

int main()
{
	setlocale(LC_ALL, "rus");
	//создание множеств
	TSet A(10 + 1);
	TSet B(20 + 1);
	TSet C(15 + 1);
	TSet copy_B(B);



	//мощности множеств
	cout << "Мощность множества A = " << A.GetMaxPower() << endl;
	cout << "Мощность множества B = " << B.GetMaxPower() << endl;
	cout << "Мощность множества копии B = " << copy_B.GetMaxPower() << endl;
	cout << "Мощность множества C = " << C.GetMaxPower() << endl;

	int choice = 1;

	//заполнение множеств
	cout << "Введите элементы множества A" << endl;
	while (choice == 1) {
		cin >> A;
		cout << "Continue?(1/0)";
		cin >> choice;
	}
	choice = 1;
	cout << "Введите элементы множества B" << endl;
	while (choice == 1) {
		cin >> B;
		cout << "Continue?(1/0)";
		cin >> choice;
	}
	choice = 1;
	cout << "Введите элементы множества C" << endl;
	while (choice == 1) {
		cin >> C;
		cout << "Continue?(1/0)";
		cin >> choice;
	}
	//проверка тройного присваивания
	/*A = B = copy_B;*/
	/*A = copy_B = B;*/

	//проверка на равенство множеств
	if (A == B) {
		cout << "Множества A и B равной мощности" << endl;
	}
	else {
		cout << "Множества A и B разной мощности" << endl;
	}

	//проверка на неравенство множеств

	if (A != B) {
		cout << "Множества A и B разной мощности" << endl;
	}
	else {
		cout << "Множества A и B равной мощности" << endl;
	}

	//теоретико-множественные операции над множествами
	A = A + 9;
	cout << "A= " << A << endl;
	B = B - 14;
	cout << "B= " << B << endl;

	A = A + B;
	B = A * C;
	C = ~C;
	cout << "C= " << C << endl;
	A = A - C;

	cout << "A= " << A << endl;
	cout << "B= " << B << endl;
	cout << "C= " << C << endl;
    return 0;
}
