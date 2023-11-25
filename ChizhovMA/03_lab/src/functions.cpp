#include "stack.h"
#include "structures.h"
#include <string>
//#include <map>

using namespace std;
ArithmeticSymbol symbols[] = {
	{"*", 3},
	{"/", 3},
	{"+", 2},
	{"-", 2},
	{"(", 1},
	{")", 1},
};

int Is_Symbol(const ArithmeticSymbol symbols[], string sm)
{
	for (int i = 0; i < 6; i++) 
		if (symbols[i].symbol == sm) 
			return i;
	return -1;
}

int Get_Priority(const string symbol)
{
	int ind = Is_Symbol(symbols, symbol);
	int priority = symbols[ind].priority;
	return priority;
}

void Add_to_Stack1(TStack<string>& st1, TStack<string>& st2, string s)
{
	st1.Push(s);
	st2.Pop();
}

bool Is_Number(const string& str)
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

bool isOperand(char c)
{
	return ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

bool isOperator(string s)
{
	return ((s == "-") || (s == "+") || (s == "/") || (s == "*"));
}

string FilteredExpression(const string& s)
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


bool isValidExpression(const string& expression) 
{
	int k1 = 0, k2 = 0;
	int l = expression.length();
	for (int i = 0; i < l; i++)
	{
		char c = expression[i];
		string s(1, c);
		if (i == 0)
			if (isOperator(s))
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
		else if ((Is_Symbol(symbols, s) != -1) || isOperand(c))
		{
			char c1 = expression[i + 1];
			string s1(1, c1);
			if (isOperator(s))
			{
				if (isOperator(s1))
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

map<string, double> GetVariables(TStack<string>& postfixExpression) {
	map<string, double> uniqueVariables;
	for (int i = 0; i < postfixExpression.Length(); i++) {
		string token = postfixExpression.GetElement(i);
		if (Is_Symbol(symbols,token) != -1 || Is_Number(token))
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

TStack<string> Postfix_Form(const string& s)
{
	string str = FilteredExpression(s);
	if (!isValidExpression(str))
	{
		string msg = "Input error";
		throw msg;
	}
	TStack<string> st1(20);
	TStack<string> st2(20);
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
			if (Is_Symbol(symbols, s) != -1)
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

double Calculate(TStack<string>& st, const map<string, double>& values)
{
	TStack<double> stack(20);
	double rightOp, leftOp, resOp;
	for (int i = 0; i < st.Length(); i++)
	{
		string c = st.GetElement(i);
		if (Is_Symbol(symbols, c) != -1)
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

