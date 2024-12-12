#pragma once

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

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
    Stack<string> *stack1; // можно без этих стеков
    Stack<string> *stack2;
    Stack<double>* stackRes;
public:

   

    //ArithmeticExpression() : impl(ARRAY_STACK) {};
    ArithmeticExpression(const string&, STACK_IMPL impl1 = ARRAY_STACK);

    vector<string> convert(const string&); // string to vector<string>
 
    unordered_map<string, double> fill_variables();


    
    double compute(const unordered_map<string, double>&);




    //double compute(const vector<string>&, const unordered_map<string, double>&);
};


std::string removeSpaces(const std::string& str);

bool is_op(char el);

bool is_op(string el);

int op_priority(char el);





//string postfixform(string , ArrayStack<string>& );
//
//string postfixform(string, ListStack<string>&);
//
//double solvepf(ArrayStack<string>);
//
//double solvepf(ListStack<string>&);
//
//double test_solvepf(ArrayStack<string>, unordered_map<string, double>);
//
//double test_solvepf(ListStack<string>&, unordered_map<string, double>);
//

//double make_op(double a, double b, char op);
//
//bool is_number(string s);
//

