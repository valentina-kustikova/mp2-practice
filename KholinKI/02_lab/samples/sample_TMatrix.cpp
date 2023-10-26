#include <iostream>
#include "TMatrix.h"

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Создание матриц 4-ого порядка..." << endl;
	TMatrix<double> matrix1(4), matrix2(4),res1(1);
	cout << endl;
	
	cout << "Заполните матрицу 1: " << endl;
	cin >> matrix1;
	cout << endl;

	cout << "Заполните матрицу 2: " << endl;
	cin >> matrix2;
	cout << endl;

	cout << "Заполнение матриц завершено!" << endl;
	cout << "matrix1" << endl;
	cout << matrix1 << endl;
	cout << "matrix2" <<endl;
	cout << matrix2 << endl;

	res1 = matrix1 * matrix2;
	cout << "Результат умножения матриц matrix1 и matrix2:" << endl;
	cout << res1 << endl;

    return 0;
}
