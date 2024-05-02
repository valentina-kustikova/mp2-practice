#include "tpolynom.h"
#include <iostream>

using namespace std;

int main() {
	string expr1, expr2;
	std::cout << "Enter first polynom p1 = ";
	std::cin >> expr1;
	std::cout << std::endl;
	std::cout << "Enter second polynom p2 = ";
	std::cin >> expr2;
	std::cout << std::endl;

	TPolynom p1(expr1), p2(expr2);
	double x = 1, y = 1, z = 1;
	if (expr1.find('x') != string::npos || expr2.find('x') != string::npos) {
		std::cout << "Enter value of x = ";
		std::cin >> x;
	}
	if (expr1.find('y') != string::npos || expr2.find('y') != string::npos) {
		std::cout << "Enter value of y = ";
		std::cin >> y;
	}
	if (expr1.find('z') != string::npos || expr2.find('z') != string::npos) {
		std::cout << "Enter value of z = ";
		std::cin >> z;
	}
	std::cout << std::endl;

	std::cout << "p1 = " << p1 << " = " << p1(x, y, z) << std::endl;
	std::cout << "p2 = " << p2 << " = " << p2(x, y, z) << std::endl;
	std::cout << std::endl;

	TPolynom sum = p1 + p2;
	std::cout << "p1 + p2 = " << p1 + p2 << " = " << sum(x, y, z) << std::endl;
	TPolynom dif = p1 - p2;
	std::cout << "p1 - p2 = " << p1 - p2 << " = " << dif(x, y, z) << std::endl;
	TPolynom prd = p1 * p2;
	std::cout << "p1 * p2 = " << p1 * p2 << " = " << prd(x, y, z) << std::endl;
	TPolynom pdx = p1.dx();
	std::cout << "dx(p1) = " << p1.dx() << " = " << pdx(x, y, z) << std::endl;
	TPolynom pdy = p1.dy();
	std::cout << "dy(p1) = " << p1.dy() << " = " << pdy(x, y, z) << std::endl;
	TPolynom pdz = p1.dz();
	std::cout << "dz(p1) = " << p1.dz() << " = " << pdz(x, y, z) << std::endl;

	return 0;
}
