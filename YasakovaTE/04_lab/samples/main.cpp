/*#include<iostream>
#include<locale>
#include "List.h"
#include "Monom.h"
#include "Polinom.h"

using namespace std;

void menu()
{
	cout << "\n\t\t\t\t\t\t1. Сложить два многочлена\n\t\t\t\t\t\t2. Вычесть второй многочлен из первого\n\t\t\t\t\t\t3. Умножить многочлен на константу\n\t\t\t\t\t\t4. Перемножить два многочлена\n\t\t\t\t\t\t5. Вычислить многочлен\n\t\t\t\t\t\t0. Выход\n\n\t\t\t\t\t\tВвод: ";
}

int main() {
	setlocale(LC_ALL, "Russian");
	TList<int> list;
	THeadList<int> headList;
	TPolinom p1, p2, p3;
	int entry = 1;
	double c;


	while (entry != 0)
	{

		system("cls");
		cout << "\t\t\t\t\t\t\tОперации над полиномами\n";
		menu();
		entry = 5;
		cin >> entry;
        fflush(stdin);
        int o = 0;
		while (((entry < 0) || (entry > 5)) && (o < 5))
		{
			cout << "\t\t\t\t\t\t\tВВЕДИТЕ ОТ 0 ДО 5\n\n\t\t\t\t\t\tВвод: ";
			cin >> entry;
			o++;
		}
		if (o == 5) { cout << "\t\t\t\t\t\t\tПрощай, дурак "; entry = 0; }
		if (entry != 0)
		{
			system("cls");
			cout << "\n\t\t\t\t\tВвод аргументов для вычисления выражения";
			cout << "\n\t\t\t\t\t\tВвод первого аргумента.\n" << "\t\t\t\t\t";
			cin >> p1;
			if ((entry != 5) && (entry != 3)) { cout << "\n\t\t\t\t\t\tВвод второго аргумента.\n" << "\t\t\t\t\t"; cin >> p2; }
			if (entry != 5)
			{
				system("cls");
				cout << "\n\t\t\t\t\t\t\t Вы ввели:\n\n\t\t\t\t\t\t1.  " << p1;
			}
			TPolinom m;
			switch (entry)
			{
                case 1:
                    cout << "\t\t\t\t\t\t2.  " << p2 << "\n\t\t\t\tСумма двух полиномов: ";
                    p3 = p1 + p2;
                    cout << p3;
                    break;
			case 2: cout << "\t\t\t\t\t\t2.  " << p2 << "\n\t\t\t\tРазность полиномов: ";  p3 = p1 - p2; if (p1 == p2) p3=p3+m; cout << p3;
				break;
			case 3: cout << "\n\t\t\t\t\t\t\tВведите константу\n\t\t\t\t\t\t\tВвод: ";
				cin >> c;
				cout << "\n\t\t\t\tДомножение полинома на константу: ";  p3 = p1 * c; cout << p3;
				break;
			case 4: cout << "\n\t\t\t\t\t\t2.  " << p2 << "\n\t\t\t\tПроизведение полиномов: "; p3 = p1 * p2; cout << p3;
				break;
			case 5: cout << "\n\t\t\t\t\t\tОтвет:" << p1;
				break;
			}
			cout << "\n\t\t\t\t\t\t1. Выход в меню\n\t\t\t\t\t\t0. Выход из программы\n\t\t\t\t\t\tВвод: ";
			cin >> entry;
			o = 0;
			while (((entry < 0) || (entry > 1)) &&
				(o < 5))
			{
				cout << "\t\t\t\t\t\t\tВВЕДИТЕ ЛИБО 1, ЛИБО 0\n\n\t\t\t\t\t\tВвод: ";
				cin >> entry;
				o++;
			}
			if ((entry != 0) && (o == 5)) { cout << "\t\t\t\t\t\t\tПрощай, дурак "; entry = 0; }
		}
	}
	return 0;
}

*/