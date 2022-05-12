#include "node.h"
#include "monom.h"
#include "polinom.h"
#include <iostream>
#include <string>

using namespace std;

void Calculation(TPolinom& a, TPolinom& b) {
    int calc = -1;
    double x, y, z;
    cout << "1. Вычислить для первого полинома\n";
    cout << "2. Вычислить для второго полинома\n";
    cout << "0. Выход\n";
    cout << ">";
    cin >> calc;
    cout << std::endl;
    cout << "Введите значения x, y, z:" << std::endl;
    cin >> x;
    cout << "\t";
    cin >> y;
    cout << "\t";
    cin >> z;
    cout << std::endl;
    switch (calc) {
    case 1:
        cout << "Вычисление.." << std::endl;
        cout << a(x, y, z) << std::endl;
        break;
    case 2:
        cout << "Вычисление.." << std::endl;
        cout << b(x, y, z) << std::endl;
        break;
    case 0:
        break;
    default:
        cout << "Error, bad input\n";
        break;
    }
}


void Change(TPolinom& a, TPolinom& b) {
    string str1;
    string str2;
    
    int change = -1;
    while (change != 0)
    {
        cout << "1. Изменить только первый полином\n";
        cout << "2. Изменить только второй полином\n";
        cout << "3. Изменить оба полинома\n";
        cout << "0. Выход\n";
        cout << ">";
        cin >> change;
        switch (change) {
        case 1:
            cout << "Введите первый полином:";
            cin >> str1;
            cout << std::endl;
            a = str1;
            cout << "Введенный полином: \n";
            cout << a << std::endl;

            break;
        case 2:
            cout << "Введите второй полином:";
            cin >> str2;
            cout << std::endl;
            b = str2;
            cout << "Введенный полином: \n";
            cout << b << std::endl;
            break;
        case 3:
            cout << "Введите первый полином:";
            cin >> str1;
            cout << std::endl;
            a = str1;
            cout << "Введите второй полином:";
            cin >> str2;
            cout << std::endl;
            b = str2;
            cout << "Введенные полиномы: \n";
            cout << a << std::endl;
            cout << b << std::endl;
            break;
        case 0:
            break;
        default:
            cout << "Error, bad input\n";
            break;
        }
    }
}

int main()
{
    int input = -1;

    setlocale(LC_ALL, "Russian");
    cout << "START" << std::endl;
    TPolinom p1;
    TPolinom p2;
    while (input != 0)
    {
        cout << "\t ===MENU=== \t" << std::endl;
        cout << "Полином 1 = " << p1 << "\t" << "Полином 2 = " << p2 << std::endl;
        cout << "1. Изменить полиномы\n";
        cout << "2. Сложение\n";
        cout << "3. Вычитание из первого полинома второго\n";
        cout << "4. Умножение\n";
        cout << "5. Вычислить значение полинома 1 или 2 при заданных значениях\n";
        cout << "0. Выход\n";
        cout << "Выбор: ";
        cin >> input;
        cout << std::endl;
        while (!(-1 < input < 6)) {
            cout << "Неправильный ввод. Попробуйте еще раз: ";
            cin >> input;
            cout << std::endl;
        }
        switch (input) {
          case 1:
              Change(p1, p2);
              break;
          case 2:
              cout << "Сложение.." << std::endl;
              cout << p1 + p2 << std::endl;
              break;
          case 3:
              cout << "Вычитание.." << std::endl;
              cout << p1 - p2 << std::endl;
              break;
          case 4:
              cout << "Умножение.." << std::endl;
              cout << p1 * p2 << std::endl;
              break;
          case 5:
              Calculation(p1, p2);
              break;
          case 0:
              break;
          default:
              cout << "Ошибка, неправильный ввод\n";
              break;
    }
    }
    cout << "FINISH" << std::endl;
	return 0;
}
