#include "scanTable.h"
#include "hashTable.h"
#include "sortTable.h"
#include "node.h"
#include "monom.h"
#include "polinom.h"
#include <iostream>
#include <headlist.h>
using namespace std;



TPolynom ResultOutput(char op, TPolynom& p1, TPolynom& p2) {
	TPolynom res;
	if (op == '+') {
		res = p1 + p2;;
	}
	else if (op == '-') {
		res = p1 - p2;
	}
	else res = p1*p2;
	return res;
}




void main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Введите полином" << endl;
	cout << "Вы можете делать вставку, удаление и поиск в таблице" << endl;
	char c = 0, str;
	char typeTable;
	ScanTable<TPolynom, string> Tab1;
	SortTable<TPolynom, string> Tab2;
	HashTable<TPolynom, string> Tab3;
	string key;
	TPolynom P;

	while (!c || (c == ' '))
	{
		cout << "ScanTable: " << endl << Tab1 << endl;
		cout << "-------------------------" << endl;
		cout << "SortedTable:" << endl << Tab2 << endl;
		cout << "-------------------------" << endl;
		cout << "HashTable:" << endl << Tab3 << endl << endl;
		cout << "-------------------------" << endl;
		cout << "1. Вставка   2. Удаление   3. Поиск   4. Операция над полиномами" << endl;
		cin >> str;
		switch (str)
		{
		case '1':
		{
			cout << "Введите полином:" << endl;
			getline(cin, key);
			if (key == "")
				getline(cin, key);
			P = TPolynom(key);
			Tab1.Insert(P, key);
			Tab2.Insert(P, key);
			Tab3.Insert(P, key);
			cout << "ScanTable: " << endl << Tab1 << endl;
			cout << "-------------------------" << endl;
			cout << "SortedTable:" << endl << Tab2 << endl;
			cout << "-------------------------" << endl;
			cout << "HashTable:" << endl << Tab3 << endl << endl;
			cout << "-------------------------" << endl;
			break;
		}
		case '2':
		{
			cout << "Введите полином:" << endl;
			getline(cin, key);
			if (key == "")
				getline(cin, key);
			Tab1.Delete(key);
			Tab2.Delete(key);
			Tab3.Delete(key);
			cout << "ScanTable: " << endl << Tab1 << endl;
			cout << "-------------------------" << endl;
			cout << "SortedTable:" << endl << Tab2 << endl;
			cout << "-------------------------" << endl;
			cout << "HashTable:" << endl << Tab3 << endl << endl;
			cout << "-------------------------" << endl;
			break;
		}
		case '3':
		{
			cout << "Введите полином:" << endl;
			getline(cin, key);
			if (key == "")
				getline(cin, key);

			if (Tab1.Search(key) != nullptr) {
				cout << "ScanTable - найден" << endl;
			}
			else {
				cout << "ScanTable - не найден" << endl;
			}
			if (Tab2.Search(key) != nullptr) {
				cout << "SortTable - найден" << endl;
			}
			else {
				cout << "SortTable - не найден" << endl;
			}
			if (Tab3.Search(key) != nullptr) {
				cout << "HashTable - найден" << endl << endl;
			}
			else {
				cout << "HashTable - не найден" << endl << endl;
			}

			//Tab1.Search(key);
			//Tab2.Search(key);
			//Tab3.Search(key);
			//cout << "ScanTable: " << endl << Tab1 << endl;
			//cout << "-------------------------" << endl;
			//cout << "Search in ScanTable: " << Tab1.Search(key) << endl;
			//cout << "-------------------------" << endl;
			//cout << "SortedTable:" << endl << Tab2 << endl;
			//cout << "-------------------------" << endl;
			//cout << "Search in SortedTable: " << Tab2.Search(key) << endl;
			//cout << "-------------------------" << endl;
			//cout << "HashTable:" << endl << Tab3 << endl << endl;
			//cout << "-------------------------" << endl;
			//cout << "Search in HashTable: " << Tab3.Search(key) << endl;
			//cout << "-------------------------" << endl;
			break;
		}
		case '4':
		{
			cout << "Выберите таблицу" << endl;
			cout << "1. ScanTable   2. SortTable   3. HashTable" << endl;
			cin >> typeTable;
			cout << "Выберите полиномы из таблицы, над которыми хотите выполнить арифметические операции:" << endl;
			string strPol1, strPol2;
			char op;
			int tmp;
			TPolynom res;
			cin >> strPol1;
			cin >> strPol2;
			switch (typeTable)
			{

			case '1': // Scan
			{
				TPolynom p1, p2;
				if (Tab1.Search(strPol1) != nullptr) {
					p1 = *Tab1.rec[Tab1.GetIndex()]->GetData();
				}
				else {
					cout << "Такого полинома нет в таблице";
					break;
				}
				if (Tab1.Search(strPol2) != nullptr) {
					p2 = *Tab1.rec[Tab1.GetIndex()]->GetData();
				}
				else {
					cout << "Такого полинома нет в таблице";
					break;
				}
				cout << "Введите операцию, которую вы хотите применить к ним(+,-,*): ";
				cin >> op;
				res = ResultOutput(op, p1, p2);
				cout << endl << "Результат: " << res << endl;
				cout << "В какую таблицу вы хотите внести новый полином?" << endl;
				cout << "1. ScanTable   2. SortTable   3. HashTable" << endl;
				cin >> tmp;
				if (tmp == 1) {
					Tab1.Insert(res, res.PolStr(res));
				}
				else if (tmp == 2) {
					Tab2.Insert(res, res.PolStr(res));
				}
				else {
					Tab3.Insert(res, res.PolStr(res));
				}
				break;

			}
			case'2':  //Sort
			{
				TPolynom p1, p2;
				if (Tab2.Search(strPol1) != nullptr) {
					p1 = *Tab2.rec[Tab2.GetIndex()]->GetData();
				}
				else {
					cout << "Такого полинома нет в таблице";
					break;
				}
				if (Tab2.Search(strPol2) != nullptr) {
					p2 = *Tab2.rec[Tab2.GetIndex()]->GetData();
				}
				else {
					cout << "Такого полинома нет в таблице";
					break;
				}
				cout << "Введите операцию, которую вы хотите применить к ним(+,-,*): ";
				cin >> op;
				res = ResultOutput(op, p1, p2);
				cout << endl << "Результат: " << res << endl;
				cout << "В какую таблицу вы хотите внести новый полином?" << endl;
				cout << "1. ScanTable   2. SortTable   3. HashTable" << endl;
				cin >> tmp;
				if (tmp == 1) {
					Tab1.Insert(res, res.PolStr(res));
				}
				else if (tmp == 2) {
					Tab2.Insert(res, res.PolStr(res));
				}
				else {
					Tab3.Insert(res, res.PolStr(res));
				}
				break;

			}
			case'3': //Hash
			{
				TPolynom p1, p2;
				if (Tab3.Search(strPol1) != nullptr) {
					p1 = *Tab3.rec[Tab3.GetIndex()]->GetData();
				}
				else {
					cout << "Такого полинома нет в таблице";
					break;
				}
				if (Tab3.Search(strPol2) != nullptr) {
					p2 = *Tab3.rec[Tab3.GetIndex()]->GetData();
				}
				else {
					cout << "Такого полинома нет в таблице";
					break;
				}
				cout << "Введите операцию, которую вы хотите применить к ним(+,-,*): ";
				cin >> op;
				res = ResultOutput(op, p1, p2);
				cout << endl << "Результат: " << res << endl;
				cout << "В какую таблицу вы хотите внести новый полином?" << endl;
				cout << "1. ScanTable   2. SortTable   3. HashTable" << endl;
				cin >> tmp;
				if (tmp == 1) {
					Tab1.Insert(res, res.PolStr(res));
				}
				else if (tmp == 2) {
					Tab2.Insert(res, res.PolStr(res));
				}
				else {
					Tab3.Insert(res, res.PolStr(res));
				}
				break;
			}
			default:
				break;
			}



		}
		}
	}

}



//int main5() {
//	string str1 = "2xy2";
//	string str2 = "2";
//	TPolynom p1(str1);
//	TPolynom p2(str2);
//	TPolynom p3;
//	p3 = p1 + p2;
//	p3 = ResultOutput('+', p1, p2);
//	cout << p3;
//	return 0;
//}
//int main2() {
//	string str = "1";
//	TPolynom p(str);
//	string str1 = "x+1";
//	TPolynom p1(str1);
//	string str2 = "1";
//	TPolynom p2(str2);
//	string str3 = "x2";
//	TPolynom p3(str3);
//	string str4 = "y2";
//	TPolynom p4(str4);
//	//cout << p;
//	HashTable<TPolynom, string> T1(5);
//
//	T1.Insert(p, str);
//	T1.Insert(p1, str1);
//	T1.Clear();
//
//	T1.Delete(str);
//
//	cout << T1;
//
//	T1.Delete(str1);
//	ScanTable<TPolynom, string> T2(T1);
//	cout << T2;
//	cout << T1 << endl << endl;
//	//T1.Delete(str);
//	//cout << T1;
//	/*ScanTable<TPolynom, string> b(2);
//	SortTable<TPolynom, string> T2(T1);*/
//	
//	cout << T1 << endl << endl;
//	/*ScanTable<int, int> T1(3);
//	T1.Insert(1, 11);
//	T1.Insert(2, 22);
//	T1.Insert(3, 33);
//	cout << T1 << endl << endl;*/
//	SortTable<TPolynom, string> S(T1);
//	/*S.Insert(p1, str1);
//	S.Insert(p2, str2);
//	S.Insert(p3, str3);
//	S.Insert(p, str);
//	S.Insert(p4, str4);*/
//	cout << S << endl;
//	S.Delete("y");
//	cout << S;
//	return 0;
//}