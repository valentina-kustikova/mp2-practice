#pragma once
#include "stack.h"
#include "array_stack.h"
#include <unordered_map>

using namespace std;

namespace posfix_form
{
    enum STACK_IMPL
    {
        ARRAY_STACK = 0,
        LIST_STACK = 1,
    };

    class ArithmeticExpression
    {
    private:

    public:
        ArithmeticExpression(const string&, STACK_IMPL impl = ARRAY_STACK);

        vector<string> convert(const string&);
        unordered_map<string, double> fill_variables(const vector<string>&);
        double compute(const vector<string>&, const unordered_map<string, double>&);
    }
};


string postfixform(string , ArrayStack<string>& );

string postfixform(string, ListStack<string>&);

double solvepf(ArrayStack<string>);

double solvepf(ListStack<string>&);

double test_solvepf(ArrayStack<string>, unordered_map<string, double>);

double test_solvepf(ListStack<string>&, unordered_map<string, double>);

bool is_op(char el);

bool is_op(string el);

int op_priority(char el);

double make_op(double a, double b, char op);

bool is_number(string s);

