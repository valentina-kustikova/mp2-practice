#include "stack.h"
#include "structures.h"
#include <string>

ArithmeticSymbol symbols[] = {
	{'*', 3},
	{'/', 3},
	{'+', 2},
	{'-', 2},
	{'(', 1},
	{')', 1},
};

int Is_Symbol(const ArithmeticSymbol symbols[], char sm) {
	for (int i = 0; i < 6; i++) 
		if (symbols[i].symbol == sm) 
			return i;
	return -1;
}

int Get_Priority(char symbol)
{
	int ind = Is_Symbol(symbols, symbol);
	int priority = symbols[ind].priority;
	return priority;
}

void Add_to_Stack1(TStack<char>& st1, TStack<char>& st2, char s)
{
	st1.Push(s);
	st2.Pop();
}

TStack<char> Postfix_Form(string str)
{
	TStack<char> st1(20);
	TStack<char> st2(20);

	for (int i = 0; i < str.length(); i++)
	{
		char s = str[i];
		if (Is_Symbol(symbols, s) != -1)
		{
			if (!st2.IsEmpty())
			{
				if (s == ')')
				{
					char sm = st2.Top();
					while (sm != '(')
					{
						Add_to_Stack1(st1, st2, sm);
						sm = st2.Top();
					}
					st2.Pop();
				}
				else
				{
					char priveous = st2.Top();
					int pr1 = Get_Priority(priveous);

					int pr2 = Get_Priority(s);
					if (pr2 != 1)
					{
						while (pr1 >= pr2)
						{
							char sm1 = st2.Top();
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
			st1.Push(s);
	}
	while (!st2.IsEmpty())
	{
		char a = st2.Top();
		Add_to_Stack1(st1, st2, a);
	}
	return st1;
}