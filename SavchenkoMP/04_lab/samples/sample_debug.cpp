#include <iostream>
#include <string>
#include <vector>
#include "tnode.h"
#include "tlist.h"
#include "tringlist.h"
#include "tmonom.h"
#include "tpolynom.h"

using namespace std;

int main() {
	try {
		//string name = "x*y^2 - 2*x^3*y^2*z - 3*x*z^3";
		string name = "-y*z+x^1*y^1*z^1+2*x^2*y^2*z^2+3*x^3*y^3*z^3-x*z";

		//cout << "name = ";
		//getline(cin, name);

		TPolynom p(name);

		cout << p;

		//vector<string> v;
		//v.push_back("abc");

		//cout << (1 < v.size() && v[1] == "*") << endl;

	}
	catch (string exp) {
		cout << exp << endl;
		//cout << "Error" << endl;
	}
	
	return 0;
}