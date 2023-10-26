#include <iostream>
#include "TVector.h"

int main()
{
 
    setlocale(LC_ALL, "rus");
    cout << "Создание векторов vec1 и vec2,vec3:" << endl;
    TVector<TVector<double>> vector_vectors;
    TVector<double> vec1(4), vec2(4),vec3(4), res1(1), res2(1);
    double scalar = 0.0;
    cout << endl;

    cout << "Заполните вектора vec1,vec2,vec3: " << endl;
    cout << "vec1 = ";
    cin >> vec1;
    cout << endl;

    cout << "vec2 = ";
    cin >> vec2;
    cout << endl;

    cout << "vec3 = ";
    cin >> vec3;
    cout << endl;
 
    cout << "Получение размеров векторов..." << endl;
    cout << "Размер вектора vec1: " << vec1.GetSize() << endl;
    cout << "Размер вектора vec2: " << vec2.GetSize() << endl;
    cout << "Размер вектора vec3: " << vec3.GetSize() << endl;
    cout << endl;

    cout << "Получение стартовых индексов..." << endl;
    cout << "Стартовый индекс вектора vec1: " << vec1.GetStart() << endl;
    cout << "Стартовый индекс вектора vec2: " << vec2.GetStart() << endl;
    cout << "Стартовый индекс вектора vec3: " << vec3.GetStart() << endl;
    cout << endl;

    cout << "Векторы" << endl;
    cout << "vec1 = " << vec1 << endl << "vec2 = " << vec2 << endl << "vec3 = " << vec3 << endl;

    cout << "Проверка на равенство векторов vec1,vec2" << endl;
    if (vec1 == vec2) {
        cout << "Векторы vec1 и vec2 одинаковые!" << endl;
        cout << "Сработала операция ==" << endl;
    }
    else if (vec1 != vec2) {
        cout << "Векторы vec1 и vec2 различны!" << endl;
        cout << "Сработала операция !=" << endl;
    }
    cout << endl;

    cout << "Проверка присваивания векторов vec3 и vec2: " << endl;
    vec3 = vec2;
    cout << "vec3= " <<vec3 << endl;

    cout << "Векторно-скалярные операции: " << endl;
    cout << "сложение вектора vec1 со скаляром" << endl;
    vec1 = vec1 + 6;
    cout << "vec1= " << vec1 << endl;

    cout << "вычитание из вектора vec2 скаляра" << endl;
    vec2 = vec2 - 4;
    cout << "vec2= " << vec2 << endl;

    cout << "умножение вектора vec3 на скаляр" << endl;
    vec3 = vec3 * 5;
    cout << "vec3= " << vec3 << endl;

    cout << "Векторно-векторные операции: " << endl;
    cout << "сложение векторов vec1 и vec2" << endl;
    res1 = vec1 + vec2;
    cout << "Результат сложения: " << res1 << endl;

    cout << "вычитание векторов vec1 и vec3" << endl;
    res2 = vec1 - vec3;
    cout << "Результат вычитания: " << res2 << endl;

    cout << "умножения векторов vec2 и vec3" << endl;
    scalar = vec2 * vec3;
    cout << "Результат умножения: " << scalar << endl;
    cout << endl;

    cout << "В ролях принимали участие векторы: " << endl;
    cout << "vec1 = " << vec1 << endl << "vec2 = " << vec2 << endl << "vec3 = " << vec3 << endl;
    cout << "До скорых встреч!" << endl;
    

    return 0;
}
