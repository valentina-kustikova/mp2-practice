#include <iostream>
#include "TVector.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    // Создание объекта TVector
    TVector<int> v1(5,0); // Создаем вектор размером 5

    // Ввод чисел через пробел и запись в вектор
    cout << "Введите 5 чисел через пробел: ";
    cin >> v1;

    TVector<int> v2(5, 0);
    cout << "Введите 5 чисел через пробел: ";
    cin >> v2;

    // Вывод содержимого вектора
    cout << "Содержимое вектора v1: ";
    for (int i = 0; i < v1.GetSize(); i++)
        cout << v1[i] << " "; // Обращение к элементам вектора через оператор []
    cout << endl;

    // Вывод содержимого вектора v2
    cout << "Содержимое вектора v2: ";
    for (int i = 0; i < v2.GetSize(); i++)
        cout << v2[i] << " ";

    cout << endl;
    //Создание второго объекта TVector
   
    //Копирование значений из v1 в v2
    
    v2 = v1;
    cout << "v1 = v2: " << v2 << endl;
    
    
    TVector<int> v3(5, 0);
    cout << "Содержимое вектора v3: ";
    cin >> v3;
    // Проверка операций сложения и умножения
    int scalar = 2;

    TVector<int> sum = v1 + v3; // Сумма двух векторов
    cout << "Сумма векторов v1 и v3: ";
    for (int i = 0; i < sum.GetSize(); i++)
        cout << sum[i] << " ";
    cout << endl;

    TVector<int> dif = v1 - v3;
    cout << "Разность векторов v1 и v3: ";
    for (int i = 0; i < dif.GetSize(); i++)
        cout << dif[i] << " ";
    cout << endl;

    int multiply = v1 * v3; 
    cout << "Умножение векторов v1 и v3: ";
    cout << multiply << endl;

    TVector<int> sum1 = v1 + scalar; // Сумма двух векторов
    cout << "Сумма v1 + 2: ";
    for (int i = 0; i < sum1.GetSize(); i++)
        cout << sum1[i] << " ";
    cout << endl;

    TVector<int> dif1 = v1 - scalar;
    cout << "Разность  v1 - 2: ";
    for (int i = 0; i < dif1.GetSize(); i++)
        cout << dif1[i] << " ";
    cout << endl;

    TVector<int> multiply1 = v1 * scalar;
    cout << "Умножение v1 * 2: ";
    for (int i = 0; i < multiply1.GetSize(); i++)
        cout << multiply1[i] << " ";
    cout << endl;
    

    if (v1 == v2)
    {
        cout << "Равенство" << endl;
        cout << "Векторы v1, v2 равны" << endl;
    }
    else
    {
        cout << "Равенство" << endl;
        cout << "Векторы v1, v2 не равны" << endl;
    }
    if (v1 == v3)
    {
        cout << "Равенство" << endl;
        cout << "Векторы v1, v3 равны" << endl;
    }
    else
    {
        cout << "Равенство" << endl;
        cout << "Векторы v1, v3 не равны" << endl;
    }

    if (v1 != v2)
    {
        cout << "Не Равенство" << endl;
        cout << "Векторы v1, v2 не равны" << endl;
    }
    else
    {
        cout << "Не Равенство" << endl;
        cout << "Векторы v1, v2 равны" << endl;
    }
    if (v1 != v3)
    {
        cout << "Не Равенство" << endl;
        cout << "Векторы v1, v3 не равны" << endl;
    }
    else
    {
        cout << "Равенство" << endl;
        cout << "Векторы v1, v3 равны" << endl;
    }
}