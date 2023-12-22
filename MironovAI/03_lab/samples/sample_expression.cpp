#include <iostream>
#include "tstack.h"
#include "expression.h"

using namespace std;


void test_expression()
{
	cout << "Input a expression\n" << endl;
	try 
	{
		string infix;
		std::getline(cin, infix);

		Expression exp(infix);
		cout << "Infix form:   " << exp.GetInfix() << endl;
		cout << "Postfix form:   " << exp.GetPostfix() << endl;
		cout << "Result:   "  << exp.Get_res() << endl;
	}
	catch (string exp) 
	{
		cout << exp << endl;
	}
}



int main() 
{
	
	test_expression(); 
	
	return 0;
}