#include "arexp.h"



int main() {
	system("chcp 1251");
	cout << "������� �������������� ���������: ";
	ArithmeticExpression ae;
	try
	{
		cout << ae.InfixForm() << "  --->   " << ae.PostfixForm() << endl;
		cout << "���������� ���������: " << ae.Calculate();
	}
	catch (const char* ex)
	{
		cout << ex;
	}
	return 0;
}