#include "Polinom.h"
void main()
{
	//string str1 = "x*y*z-3x^3*y^3*z^3+5x^5*y^5*z^5";
	//string str2 = "-2x^2*y^2*z^2+4x^4*y^4*z^4-6x^6*y^6*z*6";
	Polinom pol1;
	Polinom pol2;
	Polinom pol3;
	try
	{
		cout << "Enter polinom 1" << endl;
		cin >> pol1;
		cout << "Enter polinom 2" << endl;
		cin >> pol2;
		cout << "Polinom 1:" << endl;
		cout << pol1 << endl;
		cout << "Polinom 2:" << endl;
		cout << pol2 << endl;
		cout << "Polinom 1 + Polinom 2" << endl;
		pol3 = pol1 + pol2;
		cout << pol3 << endl;
		cout << "Polinom 1 - Polinom 2" << endl;
		pol3 = pol1 - pol2;
		cout << pol3 << endl;
		cout << "Polinom 1 * Polinom 2" << endl;
		pol3 = pol1 * pol2;
		cout << pol3 << endl;
	}
	catch (const char* str)
	{
	cout << str;
	}
	system("pause");
}