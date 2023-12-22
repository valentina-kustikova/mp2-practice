#include "arexp.h"



int main() {
	system("chcp 1251");
	cout << "¬ведите арифметическое выражение: ";
	ArithmeticExpression ae;
	cout << ae.InfixForm() << "  --->   " << ae.PostfixForm() << endl;
	cout << "вычисление выражени€: " << ae.Calculate();
	return 0;
}