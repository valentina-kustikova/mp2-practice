#include "tablesort.h"
#include "tablehash.h"

using namespace std;

void Menut()
{
	system("cls"); // clear
   cout << "1 - Найти полином с заданным ключом"
		<< endl << "2 - Добавить полином с заданным ключом"
		<< endl << "3 - Удалить полином с заданным ключом"
		<< endl << "4 - Очистить таблицу"
	    << endl << "5 - Операции над полиномами"
		<< endl << "6 - Показать текущую таблицу"
		<< endl << "7 - Выход"
		<< endl << "8 - Clear console."
		<< endl;
}

void Menut1()
{
   cout << "1 - Просматриваемая таблица"
		<< endl << "2 - Упорядоченная таблица"
		<< endl << "3 - Хеш таблица"
		<< endl << "4 - Все таблицы"
		<< endl << "5 - Выход"
		<< endl;
}

void Menu()
{
	system("cls"); // clear
	cout << "1 - Сложить полиномы"
		 << endl << "2 - Вычесть полиномы"
		 << endl << "3 - Умножить полином на константу"
		 << endl << "4 - Умножить полиномы"
		 << endl << "5 - Ввести значения x, y, z"
		 << endl;
}

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	int sw, sw2, ch, x, y, z, res;
	double c;
	TTableScan<TPolinom, string> Tscan(200);
	TTableSort<TPolinom, string> Tsort(Tscan);
	TTableHash<TPolinom, string> Thash(200, 1);
	sw = 1;
	while (sw != 7)
	{
		Menut();
		cout << "ВВедите номер: ";
		cin >> sw;
		cin.ignore(32767, '\n');
		switch (sw)
		{
		case 1:
		{
			sw2 = 1;
			string strkey2;
			cout << "ВВедите ключ: ";
			getline(cin, strkey2, '\n');
			while (sw2 != 5)
			{
				Menut1();
				cout << "ВВедите номер: ";
				cin >> sw2;
				cin.ignore(32767, '\n');
				switch (sw2)
				{
				case 1:
				{
					cout << Tscan.FindRecord(strkey2);
					break;
				}
				case 2:
				{
					cout << Tsort.FindRecord(strkey2);
					break;
				}
				case 3:
				{
					cout << Thash.FindRecord(strkey2);
					break;
				}
				default:
					break;
				}
			}
			break;
		}
		case 2:
		{
			sw2 = 1;
			string str;
			cout << "ВВедите полином: ";
			getline(cin, str, '\n');
			TPolinom P(str);
			string strkey;
			cout << "ВВедите ключ: ";
			getline(cin, strkey, '\n');
			Menut1();
			cout << "ВВедите номер: ";
			cin >> sw2;
			cin.ignore(32767, '\n');
			switch (sw2)
			{
			case 1:
			{
				Tscan.InsertRecord(strkey, P);
				break;
			}
			case 2:
			{
				Tsort.InsertRecord(strkey, P);
				break;
			}
			case 3:
			{
				Thash.InsertRecord(strkey, P);
				break;
			}
			case 4:
			{
				Tscan.InsertRecord(strkey, P);
		    	Tsort.InsertRecord(strkey, P);
				Thash.InsertRecord(strkey, P);
				break;
			}
			default:
				break;
			}
			break;
		}
		case 3:
		{
			sw2 = 1;
			string strkey3;
			cout << "ВВедите ключ: ";
			getline(cin, strkey3, '\n');
			Menut1();
			cout << "ВВедите номер: ";
			cin >> sw2;
			cin.ignore(32767, '\n');
			switch (sw2)
			{
			case 1:
			{
				Tscan.RemoveRecord(strkey3);
				break;
			}
			case 2:
			{
				Tsort.RemoveRecord(strkey3);
				break;
			}
		    case 3:
			{
				Thash.RemoveRecord(strkey3);
				break;
			}
			case 4:
			{
				Tscan.RemoveRecord(strkey3);
				Tsort.RemoveRecord(strkey3);
				Thash.RemoveRecord(strkey3);
				break;
			}
			default:
				break;
			}
			break;
		}
		case 4:
		{
			sw2 = 1;
			Menut1();
			cout << "ВВедите номер: ";
			cin >> sw2;
			cin.ignore(32767, '\n');
			switch (sw2)
			{
			case 1:
			{
				Tscan.Clear();
				break;
				}
			case 2:
			{
				Tsort.Clear();
				break;
			}
			case 3:
			{
				Thash.Clear();
				break;
			}
			case 4:
			{
				cout << "ScanT:\n" << Tscan;
				cout << "SortT:\n" << Tsort;
				cout << "HashT:\n" << Thash;
				break;
			}
			default:
				break;
			}
			break;
		}
		case 5:
		{
			sw2 = 1;
			Menut1();
			cout << "Выберите таблицу: ";
			cin >> ch;
			cin.ignore(32767, '\n');
			Menu();
			cout << "Выберите операцию: ";
			cin >> sw2;
			cin.ignore(32767, '\n');
			string strkey10;
			cout << "Введите ключ полинома: ";
			cin >> strkey10;
			cin.ignore(32767, '\n');
			string strkey11;
			TPolinom C;
			TPolinom S;
			TPolinom K;
			switch (sw2)
			{
			case 1:
			{
				cout << "Введите ключ 2 полинома: ";
				cin >> strkey11;
				cin.ignore(32767, '\n');
				if (ch == 1)
				{
					S = *Tscan.FindRecord(strkey10)->GetData();
					K = *Tscan.FindRecord(strkey11)->GetData();
					C = C + S;
					C = C + K;
					Tscan.RemoveRecord(strkey10);
					Tscan.RemoveRecord(strkey11);
					Tscan.InsertRecord(strkey10, C);
				}
				else if (ch == 2)
				{
					S = *Tsort.FindRecord(strkey10)->GetData();
					K = *Tsort.FindRecord(strkey11)->GetData();
					C = C + S;
					C = C + K;
					Tsort.RemoveRecord(strkey10);
					Tsort.RemoveRecord(strkey11);
					Tsort.InsertRecord(strkey10, C);
				}
				else if (ch == 3)
				{
					S = *Thash.FindRecord(strkey10)->GetData();
					K = *Thash.FindRecord(strkey11)->GetData();
					C = C + S;
					C = C + K;
					Thash.RemoveRecord(strkey10);
					Thash.RemoveRecord(strkey11);
					Thash.InsertRecord(strkey10, C);
				}
				break;
			}
			case 2:
			{
				cout << "Введите ключ 2 полинома: ";
				cin >> strkey11;
				cin.ignore(32767, '\n');
				if (ch == 1)
				{
					S = *Tscan.FindRecord(strkey10)->GetData();
					K = *Tscan.FindRecord(strkey11)->GetData();
					C = C + S;
					C = C - K;
					Tscan.RemoveRecord(strkey10);
					Tscan.RemoveRecord(strkey11);
					Tscan.InsertRecord(strkey10, C);
				}
				else if (ch == 2)
				{
					S = *Tsort.FindRecord(strkey10)->GetData();
					K = *Tsort.FindRecord(strkey11)->GetData();
					C = C + S;
					C = C - K;
					Tsort.RemoveRecord(strkey10);
					Tsort.RemoveRecord(strkey11);
					Tsort.InsertRecord(strkey10, C);
				}
				else if (ch == 3)
				{
					S = *Thash.FindRecord(strkey10)->GetData();
					K = *Thash.FindRecord(strkey11)->GetData();
					C = C + S;
					C = C - K;
					Thash.RemoveRecord(strkey10);
					Thash.RemoveRecord(strkey11);
					Thash.InsertRecord(strkey10, C);
				}
				break;
			}
		    case 3:
			{
				cout << "Введите константу: ";
				cin >> c;
				cin.ignore(32767, '\n');
				if (ch == 1)
				{
					S = *Tscan.FindRecord(strkey10)->GetData();
					C = C + S;
					C = C * c;
					Tscan.RemoveRecord(strkey10);
					Tscan.InsertRecord(strkey10, C);
				}
				else if (ch == 2)
				{
					S = *Tsort.FindRecord(strkey10)->GetData();
					C = C + S;
					C = C * c;
					Tsort.RemoveRecord(strkey10);
					Tsort.InsertRecord(strkey10, C);
				}
				else if (ch == 3)
				{
					S = *Thash.FindRecord(strkey10)->GetData();
					C = C + S;
					C = C * c;
					Thash.RemoveRecord(strkey10);
					Thash.InsertRecord(strkey10, C);
				}
				break;
			}
			case 4:
			{
				cout << "Введите ключ 2 полинома: ";
				cin >> strkey11;
				cin.ignore(32767, '\n');
				if (ch == 1)
				{
					S = *Tscan.FindRecord(strkey10)->GetData();
					K = *Tscan.FindRecord(strkey11)->GetData();
					C = C + S;
					C = C * K;
					Tscan.RemoveRecord(strkey10);
					Tscan.RemoveRecord(strkey11);
					Tscan.InsertRecord(strkey10, C);
				}
				else if (ch == 2)
				{
					S = *Tsort.FindRecord(strkey10)->GetData();
					K = *Tsort.FindRecord(strkey11)->GetData();
					C = C + S;
					C = C * K;
					Tsort.RemoveRecord(strkey10);
					Tsort.RemoveRecord(strkey11);
					Tsort.InsertRecord(strkey10, C);
				}
				else if (ch == 3)
				{
					S = *Thash.FindRecord(strkey10)->GetData();
					K = *Thash.FindRecord(strkey11)->GetData();
					C = C + S;
					C = C * K;
					Thash.RemoveRecord(strkey10);
					Thash.RemoveRecord(strkey11);
					Thash.InsertRecord(strkey10, C);
				}
				break;
			}
			case 5:
			{
				cout << "Введите x, y, z: ";
				cin >> x; cin.ignore(32767, '\n'); cin >> y; cin.ignore(32767, '\n'); cin >> z; cin.ignore(32767, '\n');
				if (ch == 1)
				{
					S = *Tscan.FindRecord(strkey10)->GetData();
					res = S(x, y, z);
					string y = to_string(res);
					TPolinom L(y);
					Tscan.RemoveRecord(strkey10);
					Tscan.InsertRecord(strkey10, L);
				}
				else if (ch == 2)
				{
					S = *Tsort.FindRecord(strkey10)->GetData();
					res = S(x, y, z);
					string y = to_string(res);
					TPolinom L(y);
					Tsort.RemoveRecord(strkey10);
					Tsort.InsertRecord(strkey10, L);
				}
				else if (ch == 3)
				{
					S = *Thash.FindRecord(strkey10)->GetData();
					res = S(x, y, z);
					string y = to_string(res);
					TPolinom L(y);
					Thash.RemoveRecord(strkey10);
					Thash.InsertRecord(strkey10, L);
				}
				break;
			}
			}
			break;
		}
		case 6:
		{
			sw2 = 1;
			while (sw2 != 5)
			{
				Menut1();
				cout << "ВВедите номер: ";
				cin >> sw2;
				cin.ignore(32767, '\n');
				switch (sw2)
				{
				case 1:
				{
					cout << "ScanT:\n" << Tscan;
					break;
				}
				case 2:
				{
					cout << "SortT:\n" << Tsort;
					break;
				}
				case 3:
				{
					cout << "HashT:\n" << Thash;
					break;
				}
				case 4:
				{
					cout << "ScanT:\n" << Tscan;
					cout << "SortT:\n" << Tsort;
					cout << "HashT:\n" << Thash;
					break;
				}
				default:
					break;
				}
			}
			break;
		}
		case 8:
		{
			Menut();
			break;
		}
		default:
			break;
		}
		}
	return 0;
}