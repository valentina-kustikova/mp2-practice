#include <Stack.h>
#include <string>
#include <locale>
#include<iostream>
#include<funcs.h>

using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	string string;
	try {
		getline(cin, string);
		while (!funcs::checkcorrectness(string))
		{
			cout << "��������� ����";
			getline(cin, string);
		}
		string=funcs::postfixform(string);
		cout << "����������� �����:" << string << endl;
		funcs::calculate(string);
	}
	catch (const char* ex)
	{
		cout << ex << endl;
	}

}