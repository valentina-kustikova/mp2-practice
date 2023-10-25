#include <iostream>

#include "tset.h"

int main()
{
	
	setlocale(LC_ALL, "rus");
	cout << "Создание множеств..." << endl;
	//создание множеств
	TSet A(10 + 1);
	TSet B(20 + 1);
	TSet C(15 + 1);
	TSet copy_B(B);
	TSet res1(1), res2(1), res3(1),res4(1);
	cout << endl;
	cout << "Представление мощностей множеств:" << endl;
	//мощности множеств
	cout << "Мощность множества A = " << A.GetMaxPower() << endl;
	cout << "Мощность множества B = " << B.GetMaxPower() << endl;
	cout << "Мощность множества копии B = " << copy_B.GetMaxPower() << endl;
	cout << "Мощность множества C = " << C.GetMaxPower() << endl;
	cout << endl;
	int choice = 1;

	//заполнение множеств
	cout << "Ввод элементов множества A:" << endl;
	cout << "Введите элементы множества A" << endl;
	while (choice == 1) {
		cin >> A;
		cout << "Continue?(1/0)";
		cin >> choice;
	}
	choice = 1;
	cout << endl;
	cout << "Ввод элементов множества B:" << endl;
	cout << "Введите элементы множества B" << endl;
	while (choice == 1) {
		cin >> B;
		cout << "Continue?(1/0)";
		cin >> choice;
	}
	choice = 1;
	cout << endl;
	cout << "Ввод элементов множества C:" << endl;
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
	cout << endl;
	cout << "Сравнение множеств A и  B: " << endl;
	cout << endl;
	cout << "Проверка на равенство:" << endl;
	if (A == B) {
		cout << "Множества A и B равной мощности" << endl;
	}
	else {
		cout << "Множества A и B разной мощности" << endl;
	}
	cout << endl;
	//проверка на неравенство множеств
	cout << "Проверка на неравенство:" << endl;
	if (A != B) {
		cout << "Множества A и B разной мощности" << endl;
	}
	else {
		cout << "Множества A и B равной мощности" << endl;
	}
	cout << endl;
	//теоретико-множественные операции над множествами
	cout << "Выполнение теоретико-множественных операций над множествами: " << endl;
	cout << endl;
	cout << "Объединение множества A с элементом 9" << endl;
	A = A + 9;
	cout << "A= " << A << endl;
	cout << endl;
	cout << "Разность множества B с элементом 14" << endl;
	B = B - 14;
	cout << "B= " << B << endl;
	cout << endl;

	cout << "Объединение множества A с множеством B" << endl;  
	res1 = A + B;
	cout << "res1= " << res1 << endl;
	cout << endl;

	cout << "Пересечение множества A с множеством C" << endl;
	res2 = A * C;
	cout << "res2= " << res2 << endl;
	cout << endl;

	cout << "Дополнение к множеству C" << endl;
	res3 = ~C;
	cout << "res3= " << res3 << endl;
	cout << endl;

	cout << "Разность множеств A и C" << endl;
	res4 = A - C;
	cout << "res4= " << res4 << endl;
	cout << endl;

	//Множества A,B,C
	cout << "Множества A,B,C" << endl;
	cout << "A= " << A << endl;
	cout << "B= " << B << endl;
	cout << "C= " << res3 << endl;

    return 0;
}
