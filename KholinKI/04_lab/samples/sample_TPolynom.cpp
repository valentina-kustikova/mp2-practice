#include "TPolynom.h"

int main() {//разработать меню
	TPolynom P("4*x^2*y*z^4+x*y^2*z^3-780+30*y^2-2*x^2*z^4");
	cin >> P;
	cout << P;
	return 0;
}