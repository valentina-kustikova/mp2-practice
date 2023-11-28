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
		cin >> infix;
		cout << "Input a number of operands" << endl;
		int count; cin >> count;
		cout << "Input a pair <key value> where key is operand \
		and value is operand`s value\n";

		map<string, double> operands;
		for (int i = 0; i < count; i++)
		{
			string key; cin >> key;
			double value; cin >> value;
			operands[key] = value;
		}

		Expression exp(infix, operands);
		cout << exp.GetInfix() << endl;
		cout << exp.GetPostfix() << endl;
		cout << exp.Get_res() << endl;
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