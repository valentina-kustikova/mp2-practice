#include <iostream>
#include "tpolynom.h"

int main()
{
	TPolinom z1("x^4+3*x+yz+3*y^3z+x^2yz^5");
	TPolinom z2("3*x^2+2*x^3+xyz+4*x");
	std::cout << z1.defZ().getFormula() << std::endl;

	std::string sp1, sp2;
	std::cout << "Input your polynoms" << std::endl;
	getline(std::cin, sp1);
	getline(std::cin, sp2);
	TPolinom polynom1(sp1);
	TPolinom polynom2(sp2);

	std::cout << "Your first polynom: " << polynom1.getFormula() << std::endl;
	std::cout << "Your second polynom: " << polynom2.getFormula() << std::endl;
	std::cout << "Let's calculate first polynom" << std::endl;
	double ans = polynom1.calculate();
	std::cout << "Answer is " << ans << '\n';
	std::cout << "Now let's calculate second polynom" << std::endl;
	ans = polynom2.calculate();
	std::cout << "Answer is " << ans << '\n';


	std::cout << "Ready polynoms: " << std::endl;

	TPolinom p1("3.5*x^2*y-2yz");
	TPolinom p2("+10.57*x^0*y^5*z+0.1*yz^9-4.8");
	std::cout << "p1: " << p1.getFormula() << std::endl;
	ans = p1.calculate();
	std::cout << "Answer for p1 = " << ans << '\n';
	std::cout << "p2: " << p2.getFormula() << std::endl;
	ans = p2.calculate();
	std::cout << "Answer for p2 = " << ans << '\n';


	TPolinom m1("2*x^2-yz-x+0*z+0*y");
	std::cout << m1.getFormula() << std::endl;
	TPolinom m2("3*x^2+2*x^3+xyz+4*x");
	
	TPolinom res = m1 + m2;
	std::cout << "m1 + m2 = " << res.getFormula() << std::endl;
	ans = res.calculate();
	std::cout << "Answer for m1 + m2= " << ans << '\n';

	TPolinom p3("x^4+3*x+yz+3*y^3z+x^2yz^5");
	TPolinom p4("x^3+2x-yz");
	
	res = p3 - p4;
	std::cout << "p3 - p4 = " << res.getFormula() << std::endl;
	
	res = p3 * p4;
	std::cout << "p3 * p4 = " << res.getFormula() << std::endl;

	res = p3.defX();
	std::cout << "p3 dif x" << res.getFormula() << std::endl;
	
	res = p3.defY();
	std::cout << "p3 dif y" << res.getFormula() << std::endl;

	res = p3.defZ();
	std::cout << "p3 dif z" << res.getFormula() << std::endl;

	return 0;
}
