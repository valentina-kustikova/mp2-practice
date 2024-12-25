#pragma once


#include "Arraystack.h"
#include "Liststack.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

string setInfix();
template <typename TElem>
void allocateStack(stack<TElem>*& s, char type_of_stack);
double do_op(char op, double a, double b);
char set_type_of_stack();

class PostfixForm
{
private:
    string postfix;
    string infix;
    char type_of_stack;
    map<string, int> priority;
    map<string, double> operands;
    vector<string> lex;
    void to_postfix();
    void parsing(); //разбор
public:

    PostfixForm(const string& s, char stype) : infix(s)
    {
        priority = { {"+", 1}, {"-", 1}, {"*", 2}, {"/", 3} }; 
        type_of_stack = stype;
        to_postfix();
    }

    double count(); 
    void setOp();
    void setOp(map<string, double> operndes);
    bool isOperand(const string& name) const;
    string getInfix() const;
    string getPostfix() const;
    
};