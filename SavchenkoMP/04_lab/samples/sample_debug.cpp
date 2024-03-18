#include <iostream>
#include <string>
#include "tnode.h"
#include "tlist.h"
#include "tringlist.h"
#include "tmonom.h"
#include "tpolynom.h"

using namespace std;

int main() {
	try {
		/*string tmp = "2*x^2*y^3*z^4+3*x^1*y^2*z^3";

		TPolynom p(tmp);

		cout << p.get_string();*/

		TMonom m(2, 244);
		TMonom exp(8, 234);

		TMonom tmp = m.dif_y();
		cout << tmp.get_coeff() << endl;
		cout << tmp.get_degree() << endl;
		cout << m.get_coeff() << endl;
		cout << m.get_degree() << endl;
		cout << exp.get_coeff() << endl;
		cout << exp.get_degree() << endl;
		
	}
	catch (...) {
		cout << "Error" << endl;
	}
	
	return 0;
}