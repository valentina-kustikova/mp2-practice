#include <iostream>
#include "tpolynom.h"

//не работает 1+x 1-x проверять на них

int main()
{
	//TPolinom t1("2*x^2-yz-x+0*z+0*y");
	//TPolinom t2("3*x^2+2*x^3+xyz+4*x");
	std::string sp1, sp2;
	double c;
	std::cout << "Let's create two polynoms. Please input your polynoms" << std::endl;
	std::cin >> sp1;
	std::cin >> sp2;
	TPolinom polynom1(sp1);
	TPolinom polynom2(sp2);
	TPolinom res;
	std::cout << "Your first polynom: " << polynom1 << std::endl;
	std::cout << "Your second polynom: " << polynom2 << std::endl;

	std::cout << "Let's add our polynoms: p1 + p2 = " << polynom1 + polynom2 << std::endl;
	std::cout << "Let's sabstruct our polynoms: p1 - p2 = " << polynom1 - polynom2 << std::endl;
	std::cout << "Let's multiply our polynoms: p1 * p2 = " << polynom1 * polynom2 << std::endl;

	std::cout << "Let's multiply first polynom and constant. Please input constant" << std::endl;
	std::cin >> c;
	res = polynom1 * c;
	std::cout << "Let's multiply our polynoms: p1 * const = " << res << std::endl;
	std::cout << "Let's multiply second polynom and constant. Please input constant" << std::endl;
	std::cin >> c;
	res = polynom2 * c;
	std::cout << "Let's multiply our polynoms: p2 * const = " << res  << std::endl;

	std::cout << "Derivatives with respect to x, y, z for the first polynom: " << std::endl;

	std::cout << "p1 dif x = " << polynom1.defX() << std::endl;
	std::cout << "p1 dif y = " << polynom1.defY() << "\n";
	std::cout << "p1 dif z = " << polynom1.defZ() << std::endl;

	std::cout << "Derivatives with respect to x, y, z for the second polynom: " << std::endl;
	std::cout << "p2 dif x = " << polynom2.defX() << std::endl;
	std::cout << "p2 dif y = " << polynom2.defY() << "\n";
	std::cout << "p2 dif z = " << polynom2.defZ() << std::endl;

	std::cout << "Let's calculate our first polynom:  " <<  polynom1 << std::endl;
	std::cout << "Answer = " << polynom1.calculate() << std::endl;
	std::cout << "Let's calculate our second polynom:  " << polynom2 << std::endl;
	std::cout << "Answer = " << polynom2.calculate() << std::endl;
	/*
	TPolinom t1("2*x^2-yz-x+0*z+0*y");
	TPolinom t2("3*x^2+2*x^3+xyz+4*x");
	std::cout << t1 << std::endl;
	std::cout << t2 << std::endl;
	TPolinom res1 = t1 + t2;
	std::cout << "t1 + t2 = " << res1 << std::endl;
	double ans1 = res1.calculate();
	std::cout << "Answer for m1 + m2 = " << ans1 << '\n';

	std::string sp1, sp2;
	std::cout << "Input your polynoms" << std::endl;
	std::cin >> sp1;
	std::cin >> sp2;
	
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
	std::cout << "p1: " << p1 << std::endl;
	ans = p1.calculate();
	std::cout << "Answer for p1 = " << ans << '\n';
	std::cout << "p2: " << p2 << std::endl;
	ans = p2.calculate();
	std::cout << "Answer for p2 = " << ans << '\n';

	TPolinom m1("2*x^2-yz-x+0*z+0*y");
	std::cout << m1 << std::endl;
	TPolinom m2("3*x^2+2*x^3+xyz+4*x");
	std::cout << m2 << std::endl;
	TPolinom res = m1 + m2;
	std::cout << "m1 + m2 = " << res << std::endl;
	ans = res.calculate();
	std::cout << "Answer for m1 + m2 = " << ans << '\n';

	TPolinom p3("x^4+3*x+yz+3*y^3z+x^2yz^5");
	TPolinom p4("x^3+2x-yz");
	std::cout << "p3: " << p3 << std::endl;
	std::cout << "p4: " << p4 << std::endl;
	res = p3 - p4;
	std::cout << "p3 - p4 = " << res << std::endl;
	
	res = p3 * p4;
	std::cout << "p3 * p4 = " << res << std::endl;

	res = p3.defX();
	std::cout << "p3 dif x: " << res << std::endl;
	
	res = p3.defY();
	std::cout << "p3 dif y: " << res<< std::endl;

	res = p3.defZ();
	std::cout << "p3 dif z: " << res << std::endl;
	*/
	return 0;
}
