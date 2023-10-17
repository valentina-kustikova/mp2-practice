#include "tbitfield.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "TBitField" << endl;

    setlocale(LC_ALL, "RUSSIAN");
    int len; // длина битового поля
    cout << "Введит длину поля: ";
    cin >> len;
    // Создание объекта TBitField с помощью конструктора
    TBitField bitField1(len);

    // Считывание значения битового поля с помощью оператора ввода
    cout << "Введите битовое поле (длиной " << len << " бит): ";
    cin >> bitField1;

    // Вывод значений битового поля с помощью оператора вывода
    cout << "Битовое поле: " << bitField1 << endl;

    // Создание второго объекта TBitField с помощью конструктора копирования
    TBitField bitField2(bitField1);

    // Считывание значения битового поля с помощью оператора ввода
    cout << "Введите битовое поле (длиной " << len << " бит): ";
    cin >> bitField2;

    // Вывод значений битового поля с помощью оператора вывода
    cout << "Битовое поле: " << bitField2 << endl;

    // Получение длины битового поля
    cout << "Длина второго битового поля: " << bitField2.GetLength() << " бит" << endl;

    // Установка бита
    int indexToSet = 4;
    bitField2.SetBit(indexToSet);
    cout << "Установлен бит во втором поле под индексом " << indexToSet << endl;
    cout << "Битовое поле: " << bitField2 << endl;

    // Получение значения бита
    int indexToGet = 5;
    int bitValue = bitField2.GetBit(indexToGet);
    cout << "Значение бита во втором поле под индексом " << indexToGet << ": " << bitValue << endl;
    cout << "Битовое поле: " << bitField2 << endl;

    // Очистка бита
    int indexToClear = 2;
    bitField2.ClrBit(indexToClear);
    cout << "Очищен бит во втором поле под индексом " << indexToClear << endl;
    cout << "Битовое поле: " << bitField2 << endl;

    // Проверка оператора сравнения
    if (bitField1 == bitField2) {
        cout << "Битовые поля равны" << endl;
    }
    else {
        cout << "Битовые поля не равны" << endl;
    }

    // Проверка оператора присваивания
    TBitField bitField3(len);
    bitField3 = bitField1;
    if (bitField3 == bitField1) {
        cout << "Битовое поле успешно скопировано" << endl;
        cout << "Битовое поле: " << bitField3 << endl;
    }

    // Проверка оператора "или"
    TBitField bitField4(len);
    bitField4 = bitField1 | bitField2;
    cout << "Результат 1 и 2 операции 'или': " << bitField4 << endl;

    // Проверка оператора "и"
    TBitField bitField5(len);
    bitField5 = bitField1 & bitField2;
    cout << "Результат 1 и 2 операции 'и': " << bitField5 << endl;

    // Проверка оператора отрицания
    TBitField bitField6(len);
    bitField6 = ~bitField1;
    cout << "Результат операции отрицания первого поля: " << bitField6 << endl;

    return 0;
}
