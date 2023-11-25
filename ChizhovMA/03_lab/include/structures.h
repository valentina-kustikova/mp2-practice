#ifndef Value_H
#define Value_H

#include "stack.h"
#include <map>
using namespace std;

struct ArithmeticSymbol 
{
    string symbol;
    int priority;
};

extern map<string, double> variableDict;

TStack<string> Postfix_Form(const string& s);
double Calculate(TStack<string>& st, const map<string, double>& values);
int Is_Symbol(const ArithmeticSymbol symbols[], string s);
int Get_Priority(const string symbol);
void Add_to_Stack1(TStack<string>& st1, TStack<string>& st2, string s);
bool Is_Number(const string& str);
bool isValidExpression(const string& expression);
bool isOperand(char c);
bool isOperator(string s);
string FilteredExpression(const string& s);
map<string, double> GetVariables(TStack<string>& postfixExpression);
#endif
