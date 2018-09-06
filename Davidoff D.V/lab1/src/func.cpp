#include "TLink.h"
#include "TList.h"
#include "TStack.h"
#include "Fnc.h"
#include <iostream>
#include <string>
#include <map>
using namespace std;

int Fnc::prioretet(char a)
{
	switch (a)
	{
	case '(':
		return 1;
		break;
	case '+':
		return 2;
		break;
	case '-':
		return 2;
		break;
	case '*':
		return 3;
		break;
	case '/':
		return 3;
		break;
	}
}

string Fnc::correct(string s)
{
	int count1 = 0;
	int count2 = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ')
		{
			s.erase(i, 1);
		}
		if (islower(s[i]))
		{
			s[i] = toupper(s[i]);
		}
		if (s[i] == '(')
			count1++;
		if (s[i] == ')')
			count2++;
	}
	if (count1 != count2)
	{
		throw "Check the number of parentheses";
	}
	return s;
}

string Fnc::postfix_form(string s)
{
	TStack<char> stack1;
	TStack<char> stack2;
	char a;
	int m = s.length();
	cout << s << endl;
	for (int i = 0; i < m; i++)
	{
		if ((s[i] >= 'A') && (s[i] <= 'Z'))
		{
			stack1.Push(s[i]);
		}
		if (s[i] == '(')
		{
			stack2.Push(s[i]);
		}
		if (s[i] == ')')
		{
			while ((a = stack2.Pop()) != '(')
			{
				stack1.Push(a);
			}
		}
		if ((s[i] == '+') || (s[i] == '-') || (s[i] == '*') || (s[i] == '/'))
		{
			if (!stack2.IsEmpty())
			{
				a = stack2.Pop();
				if (prioretet(s[i]) > prioretet(a))
				{
					stack2.Push(a);
					stack2.Push(s[i]);

				}
				else
				{
					stack2.Push(a);
					a = stack2.Pop();
					stack2.Push(a);
					while ((prioretet(a) >= prioretet(s[i])) && (!stack2.IsEmpty()))
					{
						stack2.Pop();
						stack1.Push(a);
						if (stack2.IsEmpty()) break;
						a = stack2.Pop();
						stack2.Push(a);
					}
					stack2.Push(s[i]);
				}
			}
			else
			{
				stack2.Push(s[i]);
			}
		}

	}

		while (!stack2.IsEmpty())
		{
			char a = stack2.Pop();
			stack1.Push(a);
		}
		s = "";
		while (!stack1.IsEmpty())
		{
			char a = stack1.Pop();
			s = a + s;
		}
		cout << "Postfix form: " << s << endl;
		return s;
	}


float Fnc::calculations(string s)
{   
	map<char, float> token = readtoken(s);
	TStack<float> operandStack;
	int m = s.length();
	float  x, y, Result;
	for (int i = 0; i < m; i++)
	{

		if ((s[i] >= 'A') && (s[i] <= 'Z'))
		{

			operandStack.Push(token[s[i]]);
		}
		if (s[i] == '+')
		{
			x = operandStack.Pop();
			y = operandStack.Pop();
			Result = y + x;
			operandStack.Push(Result);
		}
		if (s[i] == '-')
		{
			x = operandStack.Pop();
			y = operandStack.Pop();
			Result = y - x;
			operandStack.Push(Result);
		}
		if (s[i] == '*')
		{
			x = operandStack.Pop();
			y = operandStack.Pop();
			Result = y * x;
			operandStack.Push(Result);
		}
		if (s[i] == '/')
		{
			x = operandStack.Pop();
			y = operandStack.Pop();
			if (x == 0) { throw "Devision by zero"; }
			Result = y / x;
			operandStack.Push(Result);
		}
			
	}
	Result = operandStack.Pop();
	return Result;
}

map<char, float> Fnc::readtoken(const string&s)
{
	map<char, float> val;
	float value;
	for (const char& c : s)
	{
		if ((c >= 'A') && (c <= 'Z'))
		{
			if (val.count(c) == 0)
			{
				cout << "operand:" << c << "=";
				cin >> value;
				val[c] = value;
			}
		}
	}
	return val;
}