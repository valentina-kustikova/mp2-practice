#include <iostream>
#include <string>

#include "STack.h"
#include "TArithmeticExpression.h"

int main()
{


	string exprStr;
	cout << "Enter expression : ";
	cin >> exprStr;
	cout << endl;
	TArithmeticExpression expr(exprStr);
	
	expr.SetValues();


	cout << expr.Calculate() << endl;
	cout << expr.GetPostFix_str() << endl;
	
	return 0;
}


	