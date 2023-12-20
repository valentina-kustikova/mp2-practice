#include "stack.h"
#include "structures.h"
#include <string>
//#include <map>

using namespace std;
map<string, double> ArithmeticSymbol::symbolDict = {
	{"*", 3},
	{"/", 3},
	{"+", 2},
	{"-", 2},
}; 

int ArithmeticExpression::Is_Symbol(string sm)
{
	if (ArithmeticSymbol::symbolDict.find(sm) != ArithmeticSymbol::symbolDict.end())
		return 1;
	else if (sm == "(" || sm == ")")
		return 2;
	return 0;
}

int ArithmeticExpression::Get_Priority(const string symbol)
{
	int priority = ArithmeticSymbol::symbolDict[symbol];
	if (symbol == "(" || symbol == ")")
		priority = 1;
	return priority;
}

void ArithmeticExpression::Add_to_Stack1(TStack<string>& st1, TStack<string>& st2, string s)
{
	st1.Push(s);
	st2.Pop();
}

bool ArithmeticExpression::Is_Number(const string& str)
{
	for (int i = 0; i< str.length(); i++)
	{
		char c = str[i];
		if (!isdigit(c)) {
			return false; // если встречен не цифровой символ, возвращаем false
		}
	}
	return true;
}

bool ArithmeticExpression::isOperand(char c)
{
	return ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}


string ArithmeticExpression::FilteredExpression(const string& s)
{
	string filteredExpression = "";
	int l = s.length();
	for (int i = 0; i<l; i++)
	{
		char c = s[i];
		if (c != ' ')
		{
			filteredExpression += c;
		}
	}
	return filteredExpression;
}


bool ArithmeticExpression::isValidExpression(const string& expression)
{
	int k1 = 0, k2 = 0;
	int l = expression.length();
	for (int i = 0; i < l; i++)
	{
		char c = expression[i];
		string s(1, c);
		if (i == 0)
			if (Is_Symbol(s)==1)
				return false;
		if (s == "(" || s == ")")
		{
			if (s == "(")
				k1++;
			else
			{
				k2++;
				char c1 = expression[i + 1];
				string s1(1, c);
				if (isOperand(c1) || c1=='(')
					return false;
			}
		}
		else if ((Is_Symbol(s) != 0) || isOperand(c))
		{
			char c1 = expression[i + 1];
			string s1(1, c1);
			if (Is_Symbol(s) == 1)
			{
				if (Is_Symbol(s1) == 1)
					return false;
				if (i == l - 1)
					return false;
			}
			if ((isOperand(c)) && (s1 == "("))
				return false;
			continue;
		}
		else 
			return false; // обнаружен недопустимый символ
	}
	if (k1 != k2)
		return false;
	return true; 
}

map<string, double> ArithmeticExpression::GetVariables(TStack<string>& postfixExpression) {
	map<string, double> uniqueVariables;
	TStack<string> tmpSt = postfixExpression;
	tmpSt.ReverseStack();
	while (!tmpSt.IsEmpty())
	{
		string token = tmpSt.Top();
		tmpSt.Pop();
		if ((Is_Symbol(token) != 0) || Is_Number(token))
			continue;
		else
		{
			if (uniqueVariables.find(token) == uniqueVariables.end()) {
				double value;
				cout << "Enter the value for variable " << token << ": ";
				cin >> value;
				uniqueVariables[token] = value;
			}
		}
	}
	return uniqueVariables;
}

TStack<string> ArithmeticExpression::Postfix_Form(const string& s)
{
	string str = FilteredExpression(s);
	if (!isValidExpression(str))
	{
		string msg = "Input error";
		throw msg;
	}
	TStack<string> st1(5);
	TStack<string> st2(5);
	string numStr;
	string varStr;
	for (int i = 0; i < str.length(); i++)
	{
		char s1 = str[i];
		string s(1,s1);
		if (isdigit(s1))
			if (!varStr.empty())
				varStr += s;
			else
				numStr += s;
		else
		{
			if (!numStr.empty())
			{
				st1.Push(numStr);  // Преобразование строки в число и добавление в стек
				numStr.clear();
			}
			if (!varStr.empty())
			{
				st1.Push(varStr);  
				varStr.clear();
			}
			if (Is_Symbol(s) != 0)
			{
				if (!st2.IsEmpty())
				{
					if (s == ")")
					{
						string sm = st2.Top();
						while (sm != "(")
						{
							Add_to_Stack1(st1, st2, sm);
							sm = st2.Top();
						}
						st2.Pop();
					}
					else if (s == "(")
						st2.Push(s);
					else
					{
						string priveous = st2.Top();
						int pr1 = Get_Priority(priveous);

						int pr2 = Get_Priority(s);
						if (pr2 != 1)
						{
							while (pr1 >= pr2)
							{
								string sm1 = st2.Top();
								Add_to_Stack1(st1, st2, sm1);
								if (st2.IsEmpty())
									break;
								else
								{
									priveous = st2.Top();
									pr1 = Get_Priority(priveous);
								}
							}
						}
						st2.Push(s);
					}
				}
				else
					st2.Push(s);
			}
			else
				varStr += s;
		}
	}
	if (!numStr.empty())
	{
		st1.Push(numStr); 
		numStr.clear();
	}
	if (!varStr.empty())
	{
		st1.Push(varStr);
		varStr.clear();
	}
	while (!st2.IsEmpty())
	{
		string a = st2.Top();
		Add_to_Stack1(st1, st2, a);
	}
	return st1;
}

double ArithmeticExpression::Calculate(TStack<string>& st, const map<string, double>& values)
{
	TStack<double> stack(20);
	TStack<string> tempStack = st;
	tempStack.ReverseStack();
	double rightOp, leftOp, resOp;
	while (!tempStack.IsEmpty())
	{
		string c = tempStack.Top();
		tempStack.Pop();
		if (Is_Symbol(c) == 1)
		{
			if (c == "+")
			{
				rightOp = stack.Top();
				stack.Pop();
				leftOp = stack.Top();
				stack.Pop();
				resOp = leftOp + rightOp;
				stack.Push(resOp);
			}
			if (c == "-")
			{
				rightOp = stack.Top();
				stack.Pop();
				leftOp = stack.Top();
				stack.Pop();
				resOp = leftOp - rightOp;
				stack.Push(resOp);
			}
			if (c == "*")
			{
				rightOp = stack.Top();
				stack.Pop();
				leftOp = stack.Top();
				stack.Pop();
				resOp = leftOp * rightOp;
				stack.Push(resOp);
			}
			if (c == "/")
			{
				rightOp = stack.Top();
				stack.Pop();
				leftOp = stack.Top();
				stack.Pop();
				if (rightOp == 0)
					throw "Error";
				resOp = leftOp / rightOp;
				stack.Push(resOp);
			}
		}
		else
		{
			if (Is_Number(c))
				stack.Push(stod(c));
			else
				stack.Push(values.at(c));
		}
			
	}
	double r = stack.Top();
	stack.Pop();
	return r;
}

