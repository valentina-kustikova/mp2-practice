#include <iostream>
#include "TVector.h"

using namespace std;

int main()
{
    cout << "TVector" << endl;


    setlocale(LC_ALL, "Russian");
    // Создание объекта TVector
    int size;
    cout << "Ведите размер вектора: ";
    cin >> size;
    TVector<int> v1(size,0); // Создаем вектор размером 5

    // Ввод чисел через пробел и запись в вектор
    cout << "Введите " << size << " элемента(ов) через пробел для первого вектора(v1): ";
    cin >> v1;

    TVector<int> v2(size, 0);
    cout << "Введите " << size << " элемента(ов) через пробел для второго вектора(v2): ";
    cin >> v2;

    // Вывод содержимого вектора
    cout << "Содержимое вектора v1: ";
    cout << v1 << endl; // Обращение к элементам вектора через оператор []

    // Вывод содержимого вектора v2
    cout << "Содержимое вектора v2: ";
    cout << v2 << endl;
   
    //Копирование значений из v1 в v2
    
    v2 = v1;
    cout << "v2 = v1: " << v2 << endl;

    TVector<int> v3(size, 0);
    cout << "Введите " << size << " элемента(ов) через пробел для третьего вектора(v3): ";
    cin >> v3;
    cout << "Содержимое вектора v3: " << v3 << endl;
    // Проверка операций сложения и умножения
    int scalar = 2;

    TVector<int> sum = v1 + v3; // Сумма двух векторов
    cout << "Сумма векторов v1 и v3: ";
    cout << sum << endl;

    TVector<int> dif = v1 - v3;
    cout << "Разность векторов v1 и v3: ";
    cout << dif << endl;

    int multiply = v1 * v3; 
    cout << "Умножение векторов v1 и v3: ";
    cout << multiply << endl;

    TVector<int> sum1 = v1 + scalar; // Сумма двух векторов
    cout << "Сумма v1 + 2: ";
    cout << sum1 << endl;

    TVector<int> dif1 = v1 - scalar;
    cout << "Разность  v1 - 2: ";
    cout << dif1 << endl;

    TVector<int> multiply1 = v1 * scalar;
    cout << "Умножение v1 * 2: ";
    cout << multiply1 << endl;
    

    if (v1 == v2)
        cout << "Векторы v1, v2 равны" << endl;
    else
        cout << "Векторы v1, v2 не равны" << endl;
    if (v1 != v3)
        cout << "Векторы v1, v3 не равны" << endl;
    else
        cout << "Векторы v1, v3 равны" << endl;
}