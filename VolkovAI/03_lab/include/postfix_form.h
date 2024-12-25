#pragma once
#include <vector>
#include <map>
#include <string>
#include <iostream>

#include "array_stack.h"
#include "list_stack.h"

using namespace std;

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
    vector<string> lexems;

public:
    ReversePolishNotation(const string& infix, Stack_type type) {
        this->infix = infix;
        this->type = type;
        priorities = { {"*" , 2}, {"/",3}, {"+", 1}, {"-", 1} };
        convert_expression_to_RPN();
    }
    void convert_expression_to_RPN() {
        Stack<string>* operator_stack, * operands_stack;
        stack_allocate(operator_stack, type);
        stack_allocate(operands_stack, type);

        tokenize_infix();
        /// 
    }

    void tokenize_infix() {
        string token;
        char c;
        for (size_t i = 0; i < infix.size(); i++) {
            c = infix[i];
            if (i == 0 && c == '-') {
                token += c;
            }
            if (strchr("+-*/()", c) != nullptr){
                if (!(token.empty())) {
                    lexems.push_back(token);
                }
                token = c;
                lexems.push_back(token);
                token.clear();
            }
            else {
                token += c;
            }

        }
        lexems.push_back(token);
        return;
    }
    string get_postfix() const {
        cout << postfix;
        return postfix;
    }
};