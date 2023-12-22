#include "arexp.h"



int main() {
	system("chcp 1251");
	cout << "¬ведите арифметическое выражение: ";
	ArithmeticExpression ae;
	try
	{
		cout << ae.InfixForm() << "  --->   " << ae.PostfixForm() << endl;
		cout << "вычисление выражени€: " << ae.Calculate();
	}
	catch (const char* ex)
	{
		cout << ex;
	}
	return 0;
}