#include <iostream>
#include "sortedtable.h"
#include"HashTable.h"
#include"tpolynom.h"
#include<Windows.h>


void func(ScanTable<string, TPolynom>& scan_t, SortedTable<string, TPolynom>& sort_t, HashTable<string, TPolynom>& hash_t);
void op(ScanTable<string, TPolynom>& scan_t, SortedTable<string, TPolynom>& sort_t, HashTable<string, TPolynom>& hash_t, int n);



int main()
{
	setlocale(LC_ALL, "Russian");


	ScanTable<string, TPolynom> scan_t;
	SortedTable<string, TPolynom> sort_t;
	HashTable<string, TPolynom> hash_t;
	

	try {
		func(scan_t, sort_t, hash_t);
	}
	catch (string exp){
		cout << exp << endl;
		return -1;
	}

    return 0;
}


void func(ScanTable<string, TPolynom>& scan_t, SortedTable<string, TPolynom>& sort_t, HashTable<string, TPolynom>& hash_t) {
	while (1) {
		cout << "Выберите действие с таблицами: \n1.Вставить новый полином \n" <<
			"2.Удалить полином из таблицы \n3.Произвести операцию над полиномами \n" <<
			"4.Вывести на экран таблицы \n5.Закончить работу" << endl;
		int action;
		string tmp;
		cin >> tmp;
		if (tmp == "1" || tmp == "2" || tmp == "3" || tmp == "4" || tmp == "5") {
			action = tmp[0] - '0';
		}
		else {
			action = 6;
		}

		switch (action) {
		case 1:
		{
			cout << "Введите полином, который хотите добавить: ";
			try {
				string polynom_str = " ";
				cin >> polynom_str;
				TPolynom* polynom = new TPolynom(polynom_str);
				polynom_str = polynom->GetString();
				scan_t.insert(polynom_str, polynom);
				sort_t.insert(polynom_str, polynom);
				hash_t.insert(polynom_str, polynom);
				cout << "Вставка выполнена успешно!\n";
			}
			catch (string exp) {
				cout << exp << endl;
				cout << "Упс, ошибка :( \nПопробуйте снова!";
			}
			break;
		}
		case 2:
		{
			cout << "Введите полином, который хотите удалить: ";
			try {
				string polynom_str = " ";
				cin >> polynom_str;
				TPolynom* polynom = new TPolynom(polynom_str);
				polynom_str = polynom->GetString();
				scan_t.remove(polynom_str);
				sort_t.remove(polynom_str);
				hash_t.remove(polynom_str);
				cout << "Удаление выполнено успешно! \n";
			}
			catch (string exp) {
				cout << exp << endl;
				cout << "Упс, ошибка :( \nПопробуйте снова!";
			}
			break;
		}
		case 3:
		{
			cout << "Выберите какую операцию вы хотите произвести: \n1.Сложение \n" <<
			"2.Вычитание \n3.Произведение \n" <<
			"4.Дифференцировать по x \n5.Дифференцировать по y\n" << 
			"6.Дифференцировать по z" <<endl;
			int n;
			string tmp;
			cin >> tmp;
			if (tmp == "1" || tmp == "2" || tmp == "3" || tmp == "4" || tmp == "5" || tmp == "6") {
				n = tmp[0] - '0';
			}
			else {
				n = 7;
			}
			op(scan_t, sort_t, hash_t, n);


			break;
		}
		case 4:
		{
			try {
				cout << scan_t;
				cout << sort_t;
				cout << hash_t;
			}
			catch (string exp) {
				cout << exp << endl;
				cout << "Упс, ошибка :( \nПопробуйте снова!";
			}
			break;
		}		
		case 5:
		{
			cout << "Заходите ещё! :)\n";
			return;
			break;
		}
		default:
			cout << "Такого варианта выбора нет :(  \nGопробуйте ещё раз!\n";
			break;
		}

	}
}


void op(ScanTable<string, TPolynom>& scan_t, SortedTable<string, TPolynom>& sort_t, HashTable<string, TPolynom>& hash_t, int n) {
	if (n < 4 && n>0) {
		cout << "Введите первый полином: ";
		string polynom_str1 = " ";
		cin >> polynom_str1;
		TPolynom* polynom1 = new TPolynom(polynom_str1);
		polynom_str1 = polynom1->GetString();
		if (scan_t.find(polynom_str1) == nullptr || sort_t.find(polynom_str1) == nullptr ||
			hash_t.find(polynom_str1) == nullptr) 
		{
			cout << "Упс, такого полинома в таблицах нет :(\n Попробуйте снова\n";
			return;
		}

		cout << "Введите второй полином: ";
		string polynom_str2 = " ";
		cin >> polynom_str2;
		TPolynom* polynom2 = new TPolynom(polynom_str2);
		polynom_str2 = polynom2->GetString();
		if (scan_t.find(polynom_str2) == nullptr || sort_t.find(polynom_str2) == nullptr ||
			hash_t.find(polynom_str2) == nullptr)
		{
			cout << "Упс, такого полинома в таблицах нет :(\n Попробуйте снова\n";
			return;
		}

		TPolynom* res = new TPolynom();
		 
		switch (n) {
		case 1:
			*res = *polynom1 + *polynom2;
			break;
		case 2:
			*res = *polynom1 - *polynom2;
			break;
		case 3:
			*res = (*polynom1) * (*polynom2);
			break;
		}

		cout << "Получили такой полином: " << *res << endl;
		cout << "Хотите вставить его, как новый полином? y/n" << endl;
		string ins_bool;
		cin >> ins_bool;
		if (ins_bool == "y") {
			string res_str = res->GetString();
			scan_t.insert(res_str, res);
			sort_t.insert(res_str, res);
			hash_t.insert(res_str, res);
			cout << "Вставка выполнена успешно!\n";
		}
		return;
	}

	if (n < 7 && n >3) {
		cout << "Введите полином, который хотите дифференцировать: ";
		string polynom_str = " ";
		cin >> polynom_str;
		TPolynom* polynom = new TPolynom(polynom_str);
		polynom_str = polynom->GetString();
		if (scan_t.find(polynom_str) == nullptr || sort_t.find(polynom_str) == nullptr ||
			hash_t.find(polynom_str) == nullptr)
		{
			cout << "Упс, такого полинома в таблицах нет :(\n Попробуйте снова\n";
			return;
		}

		TPolynom* res = new TPolynom();

		switch (n) {
		case 4:
			*res = polynom->dif_x();
			break;
		case 5:
			*res = polynom->dif_y();
			break;
		case 6:
			*res = polynom->dif_z();
			break;
		}

		cout << "Получили такой полином: " << *res << endl;
		cout << "Хотите вставить его, как новый полином? y/n" << endl;
		string ins_bool;
		cin >> ins_bool;
		if (ins_bool == "y") {
			string res_str = res->GetString();
			scan_t.insert(res_str, res);
			sort_t.insert(res_str, res);
			hash_t.insert(res_str, res);
			cout << "Вставка выполнена успешно!\n";
		}
		return;
	}

	cout << "Такого варианта выбора нет :(  \nGопробуйте ещё раз!\n";
}