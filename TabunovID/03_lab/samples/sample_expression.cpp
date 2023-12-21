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
		/*cout << "Input a number of operands" << endl;
		int count; cin >> count;

		if (count > 0)
		{
			cout << "Input a pair <key value> where key is operand and value is operand`s value\n";
		}
		
		map<string, double> operands;
		for (int i = 0; i < count; i++)
		{
			string key; cin >> key;
			double value; cin >> value;
			operands[key] = value;
		}*/

		Expression exp(infix);
		cout << "Infix form:   " << exp.GetInfix() << endl;
		cout << "Postfix form:   " << exp.GetPostFix_str() << endl;
		cout << "Result:   "  << exp.Calculate() << endl;
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