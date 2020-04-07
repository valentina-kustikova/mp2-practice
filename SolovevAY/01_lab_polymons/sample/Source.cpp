#include "Polynom.h"
#include "stdlib.h"
#include "string"
using namespace std;


int main()
{
	char a;
	Monom monom;
	Monom testmono1;
	Polynom testpoly1;
	Monom testmono2;
	Polynom testpoly2;
	Polynom result;
	int choose = 0;
	int choosemonom = 0;
	int choosepolynom = 0;
	try
	{

		cout << "Polynom testing" << endl;
		cout << "vvedite polynom 1" << endl;//-2+5x^2y+z-yz+x^2yz
		cin >> testpoly1;
		cout << "vvedite polynom 2" << endl;// 2 + y - 2z + x ^ 2y
		cin >> testpoly2;
		cout << "summa polynomov" << endl;
		result = testpoly1 + testpoly2;
		cout << result << endl;
		cout << "raznost polynomov" << endl;
		result = testpoly1 - testpoly2;
		cout << result << endl;
		cout << "proizvedenie polynomov" << endl;
		result = testpoly1 * testpoly2;
		cout << result << endl;
	}
	catch (const char *k)
	{
		cout << k;
	}
	system("pause");
	return 0;
}