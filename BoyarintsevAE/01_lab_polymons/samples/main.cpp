#include <iostream>
#include <conio.h>
#include "polinom.h"
#include "monom.h"

void menu()
{
	cout << "Main menu: " << endl;
	cout << "----------------------" << endl;
	cout << "1. Enter polinom " << endl;
	cout << "2. Print polinom " << endl;
	cout << "3. Addition " << endl;
	cout << "4. Subtraction " << endl;
	cout << "5. Multiplication " << endl;
	cout << "6. Substitute x,y,z" << endl;
	cout << "----------------------" << endl;

	cout << "0. Exit " << endl;




}


int main()
{
	//menu();

	string st;
	string st1;
	char key = 0;

	while (key != 13)
	{

	
		cout << "Enter first polinom: " << endl;
		cin >> st;
		TPolinom a(st);
		cout << "First = " << a << endl;


		cout << "Enter second polinom: " << endl;
		cin >> st1;
		TPolinom b(st1);
		cout << "Second = " << b << endl;


		TPolinom result;

		cout << "----------------------" << endl;
		result = a + b;
		cout << "Addition: " << result <<endl;
	
		result = a - b;
		cout << "Subtraction: " << result << endl;

		result = a * b;
		cout << "Multiplication:" << result << endl;

		cout << "----------------------" << endl;



		key = _getch();
	}






	return 0;
	 
}
