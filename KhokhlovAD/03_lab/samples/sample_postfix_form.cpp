#include "postfix.h"


int main() {
	string infix;
	char q = 0;
	cout << "enter example: ";
	while (q != ';')
	{
		cin >> q;
		if (q != ';')
			infix += q;
	}
	TPostfix a(infix);
	string tmp = a.GetInfix();
	cout << "infix:" << endl << tmp << endl;
	cout << "Is Correct Example = " << a.IsCorrect() << endl;
	tmp = a.GetPostfix();
	cout << "postfix:" << endl << tmp << endl;
	cout << "result = " << a.Calculate() << endl;
	return 0;
}