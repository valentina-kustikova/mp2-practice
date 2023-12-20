#ifndef Value_H
#define Value_H

#include "stack.h"
#include <map>
using namespace std;

struct ArithmeticSymbol
{
    string symbol;
    int priority;
    static map<string, double> variableDict; // объявление статического словаря внутри структуры
    static map<string, double> symbolDict; // второй статический словарь
};

class ArithmeticExpression
{
public:
    static TStack<string> Postfix_Form(const string& s);
    static double Calculate(TStack<string>& st, const map<string, double>& values);
    static map<string, double> GetVariables(TStack<string>& postfixExpression);
    static int Is_Symbol(string sm);
    static int Get_Priority(const string symbol);
    static void Add_to_Stack1(TStack<string>& st1, TStack<string>& st2, string s);
    static bool Is_Number(const string& str);
    static bool isValidExpression(const string& expression);
    static bool isOperand(char c);
    static string FilteredExpression(const string& s);

};
#endif
