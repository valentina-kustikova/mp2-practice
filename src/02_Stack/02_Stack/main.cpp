#include "Stack.h"
#include "Calculating.h"
#include <iostream>
void main()
{
	string s;
	string postfixform;
	double postfixformvolue = 0;
	int size = 0;
	cout << "Enter string" << endl;
	cin >> s;
	try
	{
		postfixform = Calculating::create_postfix(s);
	}
	catch (const char* str)
	{
		cout << str << endl;
		system("pause");
		return;
	}
	cout << "postfix_form:" << endl;
	cout << postfixform << endl;
	double *exchange = nullptr;
	char *operands = nullptr;
	try
	{
		Calculating::get_operands(postfixform, exchange, operands, size);
	}
	catch (const char* str)
	{
		cout << str << endl;
		system("pause");
		return;
	}
	try
	{
		postfixformvolue = Calculating::calculate(postfixform, exchange, operands, size);
		cout << "postfixform volue:" << endl;
		cout << postfixformvolue;
	}
	catch (const char* str)
	{
		cout << str << endl;
	}
	delete[] exchange;
	delete[] operands;

	system("pause");
}