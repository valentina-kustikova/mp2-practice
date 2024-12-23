#pragma once
#include <vector>
#include <map>
#include <string>
#include "Astack.h"
#include "Lstack.h"
#include <iostream>
using namespace std;

//œŒ—“‘» —
//ÙÛÌÍˆËË
string setInfix();
template <typename TElem>
void allocStack(stack<TElem>*& s, char stackType);
double do_operation(char operation, double a, double b);
char setStackType();

class PostfixForm
{
private:
    string infix;
    string postfix;
    char stackType;
    map<string, int> priorts;
    map<string, double> operands;
    vector<string> lexems;
    void to_postfix();
    void parse();
public:
    PostfixForm(const string& s, char stype) : infix(s)
    {
        priorts = { {"+", 1}, {"-", 1}, {"*", 2}, {"/", 2} };
        stackType = stype;
        to_postfix();
    }
    void setOperands();
    string getInfix() const;
    string getPostfix() const;
    double calculate();
};