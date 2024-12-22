#pragma once
#include <iostream>
#include "stack.h"
#include <cctype>
#include <map>
#include <string>
#include <vector>


using namespace std;
template<typename T>
class AriExpress {
protected:
    string infix;
    string postfix;
    vector<char> lexems;
    map<char, double> operands;
    map<char, int> priority;
public:
    AriExpress(string infx);
    void Parse();
    void to_postfix();
    string get_infix() const { return infix; }
    string get_postfix() const { return postfix; }
    vector<char> getoperands() const;
    double calculate(const map<char, double>& values);
};

template<typename T>
AriExpress<T>::AriExpress(string infx) : infix(infx) {
    priority = { {'(', 0}, {')', 0}, {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2} };
    to_postfix();
}
template<typename T>
void AriExpress<T>:: Parse() {
    for (char c : infix)
        lexems.push_back(c);
}
template<typename T>
void AriExpress<T>::to_postfix() {
    Parse();
    stack<char> operatorsStack;
    stack<string> operandsStack;
    string postfix;

    for (char item : lexems) {
        if (isalnum(item)) { // if operand
            operands.insert({ item, 0.0 });
            operandsStack.Push(string(1, item));
        }
        else if (item == '(') {
            operatorsStack.Push(item);
        }
        else if (item == ')') {
            while (!operatorsStack.IsEmpty() && operatorsStack.Top() != '(') {
                string rightOperand = operandsStack.Pop();
                string leftOperand = operandsStack.Pop();
                char operation = operatorsStack.Pop();
                string expr = leftOperand + rightOperand + operation;
                operandsStack.Push(expr);
            }
            operatorsStack.Pop();
        }
        else { // if operator(+, -, *, /)
            while (!operatorsStack.IsEmpty() &&
                priority[operatorsStack.Top()] >= priority[item]) {
                string rightOperand = operandsStack.Pop();
                string leftOperand = operandsStack.Pop();
                char operation = operatorsStack.Pop();
                string expr = leftOperand + rightOperand + operation;
                operandsStack.Push(expr);
            }
            operatorsStack.Push(item);
        }
    }

    while (!operatorsStack.IsEmpty()) {
        string rightOperand = operandsStack.Pop();
        string leftOperand = operandsStack.Pop();
        char operation = operatorsStack.Pop();
        string expr = leftOperand + rightOperand + operation;
        operandsStack.Push(expr);
    }

    this->postfix = operandsStack.Pop();
}
template<typename T>
vector<char> AriExpress<T>::getoperands() const {
    vector<char> op;
    for (const auto& item : operands)
        op.push_back(item.first);
    return op;
}
template<typename T>
double AriExpress<T>::calculate(const map<char, double>& values) {
    stack<double> calc; 

    for (char item : postfix) {
        if (isalnum(item)) { //if operand
            auto it = values.find(item);
            if (it == values.end()) {
                throw (string("Value for operand ") + item + " not provided.");
            }
            calc.Push(it->second); 
        }
        else { // if operator
            if (calc.IsEmpty()) throw ("missing operands.");

            double rightOperand = calc.Pop();
            if (calc.IsEmpty()) throw ("missing operands.");

            double leftOperand = calc.Pop();

            double result = 0.0;
            switch (item) {
            case '+': result = leftOperand + rightOperand; break;
            case '-': result = leftOperand - rightOperand; break;
            case '*': result = leftOperand * rightOperand; break;
            case '/':
                if (rightOperand == 0) throw("Division by zero.");
                result = leftOperand / rightOperand;
                break;
            default:
                throw (string("Unsupported operator: ") + item);
            }
            calc.Push(result); 
        }
    }
    return calc.Pop();
}
