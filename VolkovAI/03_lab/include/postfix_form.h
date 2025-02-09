#pragma once
#include <vector>
#include <map>
#include <string>
#include <iostream>

#include "array_stack.h"
#include "list_stack.h"

using namespace std;

void menu();

enum Stack_type {
    arraystack = 0,
    liststack = 1
};
template <typename TElem> void stack_allocate(Stack<TElem>*& Stack, enum Stack_type type) {
    if (type == arraystack) {
        Stack = new array_stack<TElem>(100);
    }
    else if (type == liststack) {
        Stack = new list_stack<TElem>();
    }
    else {
        throw std::invalid_argument("Invalid stack type");
    }
};

class ReversePolishNotation {
private:
    string infix;
    string postfix;
    Stack_type type;
    map<string, int> priorities;
    map<string, double> operands;
    vector<string> symbols;
public:
    ReversePolishNotation(const string& infix, Stack_type type) {
        this->infix = infix;
        this->type = type;
        priorities = { {"*", 2}, {"/", 2}, {"+", 1}, {"-", 1} };
        convert_expression_to_RPN();
    }
    void convert_expression_to_RPN();
    void infix_handling();
    void to_RPN(Stack<string>& operator_stack, Stack<string>& operands_stack);
    string get_postfix() const;
    double evaluate_postfix(const map<string, double>& values);
};