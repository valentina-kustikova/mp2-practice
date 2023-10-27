#include <iostream>
#include "TMatrix.h"

#define dim 4

int main()
{
	setlocale(LC_ALL, "rus");
	
	TMatrix<double> matrix1(dim), matrix2(dim),matrix3(matrix1), res1(1),res2(1),res3(1);
	cout << "Создание матриц " << matrix1.GetSize() << " - ого порядка..." << endl;
	cout << endl;
	
	cout << "Заполните матрицу 1: " << endl;
	cin >> matrix1;
	cout << endl;

	cout << "Заполните матрицу 2: " << endl;
	cin >> matrix2;
	cout << endl;

	cout << "Заполнение матриц завершено!" << endl;
	for(int i =0; i < (matrix1.GetSize()/2)+1;i++){ cout << "   "; }
	cout << "matrix1";
	cout << endl;
	cout << matrix1 << endl;
	for (int i = 0; i < (matrix2.GetSize() / 2)+1; i++) { cout << "   "; }
	cout << "matrix2";
	cout << endl;
	cout << matrix2 << endl;

	cout << "Проверка присваивания матриц matrix2 и matrix3 - копия matrix1:" << endl;
	matrix3 = matrix2;
	for (int i = 0; i < (matrix3.GetSize() / 2) + 1; i++) { cout << "   "; }
	cout << "matrix3";
	cout << endl;
	cout << matrix3 << endl;

	cout << "Проверка на равенство матриц matrix1 и matrix2:" << endl;
	if (matrix1 == matrix2) {
		cout << "Сработала операция ==" << endl;
		cout << "matrix1 и matrix2 - идентичны" << endl;
	}
	else if (matrix1 != matrix2){
		cout << "Сработала операция !=" << endl;
		cout << "matrix1 и matrix2 - не идентичны" << endl;
	}
	cout << endl;

	cout << "Матрично-матричные операции:" << endl;
	cout << "operator+" << endl;
	res1 = matrix1 + matrix2;
	for (int i = 0; i < (res1.GetSize() / 2) + 1; i++) { cout << "   "; }
	cout << "res1";
	cout << endl;
	cout << res1 << endl;
	cout << endl;

	cout << "operator-" << endl;
	res2 = matrix1 - matrix2;
	for (int i = 0; i < (res2.GetSize() / 2) + 1; i++) { cout << "   "; }
	cout << "res2";
	cout << endl;
	cout << res2 << endl;

	cout << "operator*" << endl;
	res3 = matrix1 * matrix2;
	for (int i = 0; i < (res3.GetSize() / 2) + 1; i++) { cout << "   "; }
	cout << "res3";
	cout << endl;
	cout << res3 << endl;
	cout << endl;

	cout << "В ролях матриц принимали участие: " << endl;
	for (int i = 0; i < (matrix1.GetSize() / 2) + 1; i++) { cout << "   "; }
	cout << "matrix1";
	cout << endl;
	cout << matrix1 << endl;
	for (int i = 0; i < (matrix2.GetSize() / 2) + 1; i++) { cout << "   "; }
	cout << "matrix2";
	cout << endl;
	cout << matrix2 << endl;
	cout << endl;
	cout << "До скорых встреч!" << endl;

    return 0;
}
