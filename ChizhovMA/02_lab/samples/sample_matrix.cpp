#include "TMatrix.h"
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "TMarix" << endl;

    cout << "Введите размер матрицы: ";
    int size;
    cin >> size;
    TMatrix<int> matrix1(size);
    cout << "Введите элементы первой верхнетреугольной матрицы(m1) размером " << size << endl;
    cin >> matrix1;
    cout << "Матрица m1\n" << matrix1 << endl;

    TMatrix<int> matrix2(size);
    cout << "Введите элементы второй верхнетреугольной матрицы(m2) размером " << size << endl;
    cin >> matrix2;

    // Вывод матрицы
    cout << "Матрица m2\n" << matrix2 << endl;

    TMatrix<int> matrix3(3);
    matrix3 = matrix1 + matrix2;
    cout << "m3 = m1+m2:" << endl << matrix3 << endl;
    TMatrix<int> matrix4(3);
    matrix4 = matrix1 - matrix2;
    cout << "m4 = m1-m2:" << endl << matrix4 << endl;
    TMatrix<int> matrix5(3);
    matrix5 = matrix1 * matrix2;
    cout << "m5 = m1*m2:"<< endl << matrix5 << endl;

    matrix1 = matrix2;
    cout << "m1 = m2: " << endl << matrix1 << endl;
    if (matrix1 == matrix2)
        cout << "Матрицы m1 и m2 равны" << endl;
    else
        cout << "Матрицы m1 и m2 не равны" << endl;

    if (matrix1 != matrix3)
        cout << "Матрицы m1 и m3 не равны" << endl;
    else
        cout << "Матрицы m1 и m3 равны" << endl;
	return 0;
 }