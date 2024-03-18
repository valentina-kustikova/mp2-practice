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
		string tmp = "2*x^2*y^3*z^4";

		TPolynom p(tmp);

		cout << p.get_string();

		//TRingList<TMonom>* monoms = new TRingList<TMonom>;

		//delete monoms;
	}
	catch (...) {
		cout << "Error" << endl;
	}
	
	return 0;
}