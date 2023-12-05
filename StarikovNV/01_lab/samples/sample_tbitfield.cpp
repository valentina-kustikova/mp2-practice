// БИТОВЫЕ ПОЛЯ
#include "tbitfield.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "TBitField" << endl;

    setlocale(LC_ALL, "RUSSIAN");
    int len; // длина битового поля
    cout << "Введите длину поля: ";
    cin >> len;


    TBitField bitField1(len); // Создание объекта TBitField с помощью конструктора


    cout << "Введите битовое поле (длиной " << len << " бит): "; // Считывание значения битового поля с помощью оператора ввода
    cin >> bitField1;


    cout << "Битовое поле 1: " << bitField1 << endl; // Вывод значений битового поля с помощью оператора вывода


    TBitField bitField2(bitField1);    // Создание второго объекта TBitField с помощью конструктора копирования


    cout << "Введите битовое поле (длиной " << len << " бит): "; // Считывание значения битового поля с помощью оператора ввода
    cin >> bitField2;


    cout << "Битовое поле 2: " << bitField2 << endl; // Вывод значений битового поля с помощью оператора вывода


    cout << "Длина второго битового поля: " << bitField2.GetLength() << " бит" << endl; // Получение длины битового поля


    int indexToSet = 4; // Установка бита
    bitField2.SetBit(indexToSet);
    cout << "Установлен бит во втором поле под индексом " << indexToSet << endl;
    cout << "Битовое поле 2: " << bitField2 << endl;


    int indexToGet = 5; // Получение значения бита
    int bitValue = bitField2.GetBit(indexToGet);
    cout << "Значение бита во втором поле под индексом " << indexToGet << ": " << bitValue << endl;
    cout << "Битовое поле 2: " << bitField2 << endl;


    int indexToClear = 2; // Очистка бита
    bitField2.ClrBit(indexToClear);
    cout << "Очищен бит во втором поле под индексом " << indexToClear << endl;
    cout << "Битовое поле 2: " << bitField2 << endl;


    if (bitField1 == bitField2) { // Проверка оператора сравнения
        cout << "Битовые поля равны" << endl;
    }
    else {
        cout << "Битовые поля не равны" << endl;
    }


    TBitField bitField3(len); // Проверка оператора присваивания
    bitField3 = bitField1;
    if (bitField3 == bitField1) {
        cout << "Битовое поле успешно скопировано" << endl;
        cout << "Битовое поле 1: " << bitField3 << endl;
    }


    TBitField bitField4(len); // Проверка оператора "или"
    bitField4 = bitField1 | bitField2;
    cout << "Результат 1 и 2 операции 'или': " << bitField4 << endl;


    TBitField bitField5(len); // Проверка оператора "и"
    bitField5 = bitField1 & bitField2;
    cout << "Результат 1 и 2 операции 'и': " << bitField5 << endl;


    TBitField bitField6(len); // Проверка оператора отрицания
    bitField6 = ~bitField1;
    cout << "Результат операции отрицания первого поля: " << bitField6 << endl;

    return 0;
}