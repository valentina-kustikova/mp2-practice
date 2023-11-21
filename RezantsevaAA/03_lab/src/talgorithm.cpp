#include "talgorithm.h"
#include "tstack.h"
#include <iostream>
#include <string>

int Polsk::GetPriority(const char op)
{
    switch (op)
    {
    case '(':
        return 1;
    case ')':
        return 1;
    case '+':
        return 2;
    case '-':
        return 2;
    case '*':
        return 3;
    case '/':
        return 3;
    default:
        throw "Error. Incorrect symbol.";
    }
}

bool  Polsk::isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')');
}

