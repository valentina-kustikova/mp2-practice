#pragma once
#include <iostream>
#include "Polynom.h"
using namespace std;
void Create()
{
	cout << "Test 1: Create" << endl;
	string s = "5.32x^2z^3y^6-0.1y^5x^4+5z+0.3x^4y^5-2+y";
	Polynom A(s);
	cout << "String: " << s << endl;
	cout << "Polynom: " << A << endl;
	cout << endl;
};
void Copy()
{
	cout << "Test 2: Copy" << endl;
	string s = "5.32x^2z^3y^6-0.1y^5x^4+5z+0.3x^4y^5-2+y";
	Polynom A(s);
	Polynom B(A);
	cout << "Polynom A: " << A << endl;
	cout << "Polynom B(A): " << B << endl;
	cout << endl;
};
void Add_Polynom()
{
	cout << "Test 3: Addition of polynomials" << endl;
	string s1 = "5yz+2xy-3z^3";
	string s2 = "8z^3-5yx+7xyz";
	Polynom A(s1);
	Polynom B(s2);
	cout << "Polynom A: " << A << endl;
	cout << "Polynom B: " << B << endl;
	cout << "A + B = " << A + B << endl;
	A += B;
	cout << "A += B: " << A << endl;
	cout << endl;
};
void Sub_Polynom()
{

	cout << "Test 4: Subtraction of polynomials" << endl;
	string s1 = "5yz+2xy-3z^3";
	string s2 = "8z^3-5yx+7xyz";
	Polynom A(s1);
	Polynom B(s2);
	cout << "Polynom A: " << A << endl;
	cout << "Polynom B: " << B << endl;
	cout << "A - B = " << A - B << endl;
	A -= B;
	cout << "A -= B: " << A << endl;
	cout << endl;
};
void Multi_Polynom()
{
	cout << "Test 5: Polynomial multiplication" << endl;
	string s1 = "5x^3y^2z+2z^4y";
	string s2 = "3y^5x^2-z";
	Polynom A(s1);
	Polynom B(s2);
	cout << "Polynom A: " << A << endl;
	cout << "Polynom B: " << B << endl;
	cout << "A * B = " << A * B << endl;
	A *= B;
	cout << "A *= B: " << A << endl;
	cout << endl;
};
void Add_Monom()
{
	cout << "Test 6: Adding monom" << endl;
	string s1 = "5yz+2xy-3z^3";
	Polynom A(s1);
	Monom B(523, 6.35);
	cout << "Polynom A: " << A << endl;
	cout << "Monom B: " << B << endl;
	cout << "A + B = " << A + B << endl;
	A += B;
	cout << "A += B: " << A << endl;
	cout << endl;
};
void Sub_Monom()
{
	cout << "Test 7: Monom subtraction" << endl;
	string s1 = "5yz+2xy-3z^3";
	Polynom A(s1);
	Monom B(110, 6.35);
	cout << "Polynom A: " << A << endl;
	cout << "Monom B: " << B << endl;
	cout << "A - B = " << A - B << endl;
	A -= B;
	cout << "A -= B: " << A << endl;
	cout << endl;
};
void Multi_Monom()
{
	cout << "Test 8: Monomial Multiplication" << endl;
	string s1 = "5x^3y^2z+2z^4y";
	Polynom A(s1);
	Monom B(110, 6.35);
	cout << "Polynom A: " << A << endl;
	cout << "Polynom B: " << B << endl;
	cout << "A * B = " << A * B << endl;
	A *= B;
	cout << "A *= B: " << A << endl;
	cout << endl;
};
void Assign()
{
	cout << "Test 9: Assign" << endl;
	string s1 = "5x^3y^2z+2z^4y";
	string s2 = "8z^3-5yx+7xyz";
	Polynom A(s1);
	Polynom B(s2);
	A = B;
	cout << "Polynom A: " << A << endl;
	cout << "Polynom B: " << B << endl;
	cout << "A = B: " << A << endl;
	cout << endl;
};