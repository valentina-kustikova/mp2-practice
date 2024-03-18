#include <iostream>
#include "tpolynom.h"

int main()
{
	TPolinom p1("3.5*x^2*y-2yz");
	TPolinom p2("+10.57*x^0*y^5*z+0.1*yz^9-4.8");
	//double ans = p1.calculate();
	//std::cout << "Answer for p1 = " << ans << '\n';
	double ans = p2.calculate();
	std::cout << "Answer for p2 = " << ans << '\n';
	return 0;
}
