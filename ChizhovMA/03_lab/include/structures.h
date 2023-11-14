#ifndef Value_H
#define Value_H

#include "stack.h"

struct ArithmeticSymbol 
{
    char symbol;
    int priority;

};

TStack<char> Postfix_Form(string str);
int Is_Symbol(const ArithmeticSymbol symbols[], char s);
int Get_Priority(char symbol);
void Add_to_Stack1(TStack<char>& st1, TStack<char>& st2, char s);
#endif
