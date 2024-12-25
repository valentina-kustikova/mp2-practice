#pragma once
#include <iostream>
#include "main_stack.h"
#include "list_stack.h"
#include <cctype>
#include <map>
#include <string>
#include <vector>


using namespace std;

class AriExpress {
protected:
    string infix;
    string postfix;
    vector<char> lexems;
    map<char, double> operands;
    map<char, int> priority;
    MainStack<char>* operatorsStack; 
    MainStack<string>* operandsStack;
public:
    AriExpress(string infx, MainStack<char>* opStack, MainStack<string>* opndStack);
    ~AriExpress();
    void Parse();
    string to_postfix();
    map<char, double> getoperands() const;
    double calculate(const map<char, double>& values);
};

AriExpress::AriExpress(string infx, MainStack<char>* opStack, MainStack<string>* opndStack)
    : infix(infx), operatorsStack(opStack), operandsStack(opndStack) {
    priority = { {'(', 0}, {')', 0}, {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2} };
}

AriExpress::~AriExpress() {
    delete operatorsStack; 
    delete operandsStack;
}

void AriExpress:: Parse() {
    for (char c : infix)
        lexems.push_back(c);
}

string AriExpress::to_postfix() {
    Parse();

    for (char item : lexems) {
        if (isspace(item)) continue;
        if (isalnum(item)) { // if operand
            operands.insert({ item, 0.0 });
            operandsStack->Push(string(1, item));
        }
        else if (item == '(') {
            operatorsStack->Push(item);
        }
        else if (item == ')') {
            while (!operatorsStack->IsEmpty() && operatorsStack->Top() != '(') {
                string rightOperand = operandsStack->Pop();
                string leftOperand = operandsStack->Pop();
                char operation = operatorsStack->Pop();
                string expr = leftOperand + rightOperand + operation;
                operandsStack->Push(expr);
            }
            operatorsStack->Pop();
        }
        else { // if operator(+, -, *, /)
            while (!operatorsStack->IsEmpty() &&
                priority[operatorsStack->Top()] >= priority[item]) {
                string rightOperand = operandsStack->Pop();
                string leftOperand = operandsStack->Pop();
                char operation = operatorsStack->Pop();
                string expr = leftOperand + rightOperand + operation;
                operandsStack->Push(expr);
            }
            operatorsStack->Push(item);
        }
    }

    while (!operatorsStack->IsEmpty()) {
        string rightOperand = operandsStack->Pop();
        string leftOperand = operandsStack->Pop();
        char operation = operatorsStack->Pop();
        string expr = leftOperand + rightOperand + operation;
        operandsStack->Push(expr);
    }

    this->postfix = operandsStack->Pop();
    return postfix;
}

map<char, double> AriExpress::getoperands() const {
    vector<char> op;
    for (const auto& item : operands) {
        op.push_back(item.first);
    }

    map<char, double> values;
    double val;

    for (const auto& operand : op) {
        cout << "Enter value of " << operand << ": ";
        cin >> val;
        values[operand] = val;
    }

    return values;
}

double AriExpress::calculate(const map<char, double>& values) {
    if (postfix == "")
    {
        this->to_postfix();
    }

    liststack<double> calc;

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
