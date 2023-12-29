#include <iostream>
#include <string>

#include "STack.h"
#include "TArithmeticExpression.h"

int main()
{


	string str;
	cout << "Enter expression : ";
	getline(cin, str);
	cout << endl;
	cout << str << endl;
	TArithmeticExpression expr(str);
	try {
		expr.ShowPostfix();
		/*//____________________________________________________
		cout << "kolichestvo alementov v vectore: " << expr.lexems.size() << endl;
		for (int i = 0; i < expr.lexems.size(); i++)
		{
			cout << expr.lexems[i] << endl;
		}

		cout << "Infix:" << expr.GetInfix() << endl;
		cout << "str_postfix: " << expr.str_postfix << endl;
		*/
		expr.SetValues();

		cout << "-----" << endl;
		cout << expr.Calculate() << endl;
		cout << expr.GetPostFix_str() << endl;
	}
	catch (const char* exp) {
		cout << exp;
		return -1;
	}
	return 0;
}


	