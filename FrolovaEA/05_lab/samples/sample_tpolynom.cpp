
#include"tpolynom.h"

#include "tringlist.h"

#include<iostream>

#include<string>
#include <vector>

using namespace std;

int main()
{


	string polynom1=" ";
	cout << "Enter polynom1 : ";
	cin >> polynom1;
	cout << endl;
	TPolinom poly1(polynom1);
	
	string polynom2="";
	cout << "Enter polynom2 : ";
	cin >> polynom2;
	cout << endl;
	TPolinom poly2(polynom2);

	cout << " polynom 1 : " << poly1 << endl;
	cout << " polynom 2 : " << poly2 << endl;


	TPolinom dif_x1 = poly1.dif_x();
	TPolinom dif_x2 = poly2.dif_x();

	cout << " the x differential of the first polynomial : " << dif_x1 << endl;
	cout << " the x differential of the second polynomial : " << dif_x2 << endl;

	TPolinom dif_y1 = poly1.dif_y();
	TPolinom dif_y2 = poly2.dif_y();

	cout << " the y differential of the first polynomial : " << dif_y1 << endl;
	cout << " the y differential of the second polynomial : " << dif_y2 << endl;

	TPolinom dif_z1 = poly1.dif_z();
	TPolinom dif_z2 = poly2.dif_z();

	cout << " the z differential of the first polynomial : " << dif_z1 << endl;
	cout << " the z differential of the second polynomial : " << dif_z2 << endl;

	TPolinom SUM = poly1 + poly2;
	cout << "sum of polynoms: " << SUM << endl;

	TPolinom DIFFEREN = poly1 - poly2;
	cout << "poly1 - poly2= " << DIFFEREN << endl;

	TPolinom COMPOS = poly1 * poly2;
	cout << "poly1 * poly2= " << COMPOS << endl;

	double x, y, z;

	cout << "enter x:";
	cin >> x;
	cout << endl;

	cout << "enter y:";
	cin >> y;
	cout << endl;

	cout << "enter z:";
	cin >> z;
	cout << endl;

	double valpoly1 = poly1(x, y, z);
	double valpoly2 = poly2(x, y, z);
	
	cout << "x=" << x << " y=" << y << " z=" << z << endl;
	cout << "value of first polynom :" << valpoly1 << endl;
	cout << "value of second polynom :" << valpoly2 << endl;

	return 0;

}


