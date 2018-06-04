
#include <iostream>
#include <funñ.h>
#include <string>
using namespace std;


void main() {
	string s;

	cout << "Write your expression:" << endl;
	cin >> s;
	try {
		s = funcs::postfix_form(s);
		cout << "Postfix: " << s << endl;
		cout << "Result:" << funcs::compute(s) << endl;
	}
	catch (const char* e) {
		cout << "Error: " << e << endl;
	}
}
