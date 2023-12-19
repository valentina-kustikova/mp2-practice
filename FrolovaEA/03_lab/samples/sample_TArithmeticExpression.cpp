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
	bool res=expr.isCorrectInfixExpression();
	cout << res << endl;
	if (expr.isCorrectInfixExpression())
	{
		/*
		cout << "kolichestvo alementov v vectore: " << expr.lexems.size() << endl;
		for (int i = 0; i < expr.lexems.size(); i++)
		{
			cout << expr.lexems[i] << endl;
		}
		cout << expr.GetInfix() << endl;
		cout << "_______________" << endl;
		cout << "kolichestvo alementov v vectore: " << expr.postfix.size() << endl;
		for (int i = 0; i < expr.postfix.size(); i++)
		{
			cout << expr.postfix[i];
		}
		cout << endl;
		*/
		expr.SetValues();
		/*
		for (auto& op : expr.operands)
		{
			cout << "Value of " << op.first << ":";
			cout << op.second << "" << endl;
		}
		cout << endl;
		*/

		cout << expr.Calculate() << endl;
		cout << expr.GetPostFix_str() << endl;
	}
	return 0;
}


	