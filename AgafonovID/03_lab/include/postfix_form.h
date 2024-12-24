#pragma once

#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include <vector>
#include <sstream>
#include "stack.h"
#include "stackArray.h"
#include "ListStack.h"

// Типы стека
enum StackType {
    Array,
    ListSt
};

using namespace std;

template<typename T>
class AriExpress {
protected:
    string infix;
    string postfix;
    vector<char> lexems;
    map<char, double> operands;
    map<char, int> priority;
    Stack<T>* operatorsStack;      
    Stack<string>* operandsStack; 
    StackType stackType;           

public:
    AriExpress(string infx, Stack<T>* operatorsStack, Stack<string>* operandsStack, StackType type);
    ~AriExpress();

    void Parse();
    void to_postfix();
    string get_infix() const { return infix; }
    string get_postfix() const { return postfix; }
    vector<char> getoperands() const;
    double calculate(const map<char, double>& values);
};


template<typename T>
AriExpress<T>::AriExpress(string infx, Stack<T>* opStack, Stack<string>* opndsStack, StackType type)
    : infix(infx), operatorsStack(opStack), operandsStack(opndsStack), stackType(type) {
    priority = { {'(', 0}, {')', 0}, {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2} };
    to_postfix();
}

template<typename T>
AriExpress<T>::~AriExpress() {
    delete operatorsStack;
    delete operandsStack;
}

template<typename T>
void AriExpress<T>::Parse() {
    for (char c : infix) {
        lexems.push_back(c);
    }
}

template<typename T>
void AriExpress<T>::to_postfix() {
    Parse();

    for (char item : lexems) {
        if (isalnum(item)) { 
            operands.insert({ item, 0.0 });
            postfix += item;
        }
        else if (item == '(') { 
            operatorsStack->Push(item);
        }
        else if (item == ')') { 
            while (!operatorsStack->IsEmpty() && operatorsStack->Top() != '(') {
                postfix += operatorsStack->Top();
                operatorsStack->Pop();
            }
            operatorsStack->Pop(); 
        }
        else { 
            while (!operatorsStack->IsEmpty() &&
                priority[operatorsStack->Top()] >= priority[item]) {
                postfix += operatorsStack->Top();
                operatorsStack->Pop();
            }
            operatorsStack->Push(item);
        }
    }

    while (!operatorsStack->IsEmpty()) {
        postfix += operatorsStack->Top();
        operatorsStack->Pop();
    }
}

template<typename T>
vector<char> AriExpress<T>::getoperands() const {
    vector<char> op;
    for (const auto& item : operands) {
        op.push_back(item.first);
    }
    return op;
}

template<typename T>
double AriExpress<T>::calculate(const map<char, double>& values) {
    Stack<double>* calc;
    if (stackType == Array) {
        calc = new stackArray<double>(100);
    }
    else {
        calc = new ListStack<double>();
    }

    for (char item : postfix) {
        if (isalnum(item)) { 
            auto it = values.find(item);
            if (it == values.end()) {
                delete calc;
                throw runtime_error(string("Value for operand ") + item + " not provided.");
            }
            calc->Push(it->second);
        }
        else {
            if (calc->IsEmpty()) {
                delete calc;
                throw runtime_error("Missing operands.");
            }

            double rightOperand = calc->Top();
            calc->Pop();

            if (calc->IsEmpty()) {
                delete calc;
                throw runtime_error("Missing operands.");
            }

            double leftOperand = calc->Top();
            calc->Pop();

            double result = 0.0;
            switch (item) {
            case '+': result = leftOperand + rightOperand; break;
            case '-': result = leftOperand - rightOperand; break;
            case '*': result = leftOperand * rightOperand; break;
            case '/':
                if (rightOperand == 0) {
                    delete calc;
                    throw runtime_error("Division by zero.");
                }
                result = leftOperand / rightOperand; break;
            default:
                delete calc;
                throw runtime_error(string("Unsupported operator: ") + item);
            }
            calc->Push(result);
        }
    }

    if (calc->IsEmpty()) {
        delete calc;
        throw runtime_error("Calculation error: stack is empty.");
    }

    double result = calc->Top();
    calc->Pop();

    if (!calc->IsEmpty()) {
        delete calc;
        throw runtime_error("Calculation error: stack is not empty after calculation.");
    }

    delete calc;
    return result;
}
