#include <iostream>
#include "Complex.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    Complex a(3, 4);
    Complex b(1, -2);
    Complex c;
    Complex d(5);

    cout << "Исходные числа:\n";
    cout << "a = " << a << "\n";
    cout << "b = " << b << "\n";
    cout << "c = " << c << " (по умолчанию)\n";
    cout << "d = " << d << " (из double)\n\n";

    cout << "Модуль:\n";
    cout << "|a| = " << a.modulus() << "\n";
    cout << "|b| = " << b.modulus() << "\n\n";

    cout << "Перегруженные операторы:\n";
    cout << "a + b = " << (a + b) << "\n";
    cout << "a - b = " << (a - b) << "\n";
    cout << "a * b = " << (a * b) << "\n";
    cout << "a / b = " << (a / b) << "\n\n";

    cout << "Сравнение:\n";
    Complex x(3, 4);
    cout << "x = " << x << "\n";
    cout << "x == a ? " << (x == a ? "true" : "false") << "\n";
    cout << "x != b ? " << (x != b ? "true" : "false") << "\n\n";

    cout << "Введите комплексное число с клавиатуры:\n";
    Complex userInput;
    cin >> userInput;
    cout << "Вы ввели: " << userInput << "\n";
    cout << "Его модуль: " << userInput.modulus() << "\n\n";

    return 0;
}