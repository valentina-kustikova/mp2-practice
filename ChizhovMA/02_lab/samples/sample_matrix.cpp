#include "TMatrix.h"
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    TMatrix<int> matrix1(3);

    // Ввод элементов матрицы
    cout << "Введите элементы матрицы:\n";
    cin >> matrix1;

    // Вывод матрицы
    cout << "Матрица:\n" << matrix1 << endl;

    TMatrix<int> matrix2(3);

    // Ввод элементов матрицы
    cout << "Введите элементы матрицы:\n";
    cin >> matrix2;

    // Вывод матрицы
    cout << "Матрица:\n" << matrix2 << endl;
    TMatrix<int> matrix3(3);
    matrix3 = matrix1 + matrix2;
    cout << "m1+m2:" << endl << matrix3 << endl;
    TMatrix<int> matrix4(3);
    matrix4 = matrix1 - matrix2;
    cout << "m1-m2:" << endl << matrix4 << endl;
    TMatrix<int> matrix5(3);
    matrix5 = matrix1 * matrix2;
    cout << "m1*m2:"<< endl << matrix5 << endl;

    if (matrix1 == matrix2)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    if (matrix1 != matrix2)
        cout << "true" << endl;
    else
        cout << "false" << endl;
	return 0;
 }