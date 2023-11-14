#include "stack.h"
#include "structures.h"
#include <iostream>
#include <string>

int main()
{
	string ar_ex;
	cout << "Enter arithmetic expression: ";
	cin >> ar_ex;

	TStack<char> st(5);
	st = Postfix_Form(ar_ex);
	cout << st;
	return 0;
}
/*
int Get_Priority(char symbol)
{
	int ind = Is_Symbol(symbols, symbol);
	int priority = symbols[ind].priority;
	return priority;
}

void Add_to_Stack1(TStack<char> st1, TStack<char> st2)
{
	char sm1 = st2.Top();
	st1.Push(sm1);
	st2.Pop();
}*/