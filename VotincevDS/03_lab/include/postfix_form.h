#pragma once

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include "stack.h"

using namespace std;


enum STACK_IMPL
{
    ARRAY_STACK = 0,
    LIST_STACK = 1
};

class ArithmeticExpression {
private:
    vector<string> expr;
    STACK_IMPL impl = ARRAY_STACK;
public:

    ArithmeticExpression(const string&, STACK_IMPL impl1 = ARRAY_STACK);

    vector<string> convert(const string&); // string to vector<string>
    unordered_map<string, double> fill_variables();


    double compute(const unordered_map<string, double>&);
    void make_pf(Stack<string>*& , vector<string>& );
    double solve_pf(vector<string>& , const unordered_map<string, double>& );
};


std::string removeSpaces(const std::string& str);


bool is_op(string el);


void print_pf(vector<string>&);


