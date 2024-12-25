#pragma once

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include "stack.h"
#include "stackArray.h"
#include "ListStack.h"
#define N 30
using namespace std;

class PostfixForm {
private:
    string infix;
    string postfix;
    char stackType;
    map<string, int> priority; 
    map<string, double> operands; 
    vector<string> lexems; 
    Stack<string>* operatorsStack; 
    Stack<double>* valuesStack;    

    void parse();       
    void to_postfix();  

public:
    PostfixForm(const string& s, char stype); //интерфейс переделать
    ~PostfixForm();
    vector<string> getOperands() const;
    void setOperands(const map<string, double>& values); 
    string getInfix() const;      
    string getPostfix() const;    
    double calculate();           
};

template<typename T>
Stack<T>* createStack(char stackType) {
    if (stackType == 'A') {
        return new stackArray<T>(N);
    }
    else if (stackType == 'L') {
        return new ListStack<T>();
    }
    else {
        throw std::exception("Invalid stack type");
    }
}

PostfixForm::PostfixForm(const string& s, char stype) : infix(s), stackType(stype), operatorsStack(nullptr), valuesStack(nullptr) {
    priority = { {"+", 1}, {"-", 1}, {"*", 2}, {"/", 2} };
    operatorsStack = createStack<string>(stackType);
    valuesStack = createStack<double>(stackType);

    to_postfix();
}

PostfixForm::~PostfixForm() {
    delete operatorsStack;
    delete valuesStack;
}

vector<string> PostfixForm::getOperands() const {
    vector<string> operandList;
    for (const auto& operand : operands) {
        operandList.push_back(operand.first); 
    }
    return operandList;
}

void PostfixForm::parse() {
    istringstream iss(infix);
    string token;
    while (iss >> token) {
        lexems.push_back(token);
    }
}

void PostfixForm::to_postfix() {
    parse();
    for (const string& token : lexems) {
        if (isalnum(token[0])) {
            postfix += token + " ";
            operands[token] = 0.0;
        }
        else if (token == "(") {
            operatorsStack->Push(token);
        }
        else if (token == ")") {
            while (!operatorsStack->IsEmpty() && operatorsStack->Top() != "(") {
                postfix += operatorsStack->Top() + " ";
                operatorsStack->Pop();
            }
            operatorsStack->Pop();
        }
        else {
            while (!operatorsStack->IsEmpty() &&
                priority[operatorsStack->Top()] >= priority[token]) {
                postfix += operatorsStack->Top() + " ";
                operatorsStack->Pop();
            }
            operatorsStack->Push(token);
        }
    }

    while (!operatorsStack->IsEmpty()) {
        postfix += operatorsStack->Top() + " ";
        operatorsStack->Pop();
    }
}

string PostfixForm::getInfix() const {
    return infix;
}

string PostfixForm::getPostfix() const {
    return postfix;
}

void PostfixForm::setOperands(const map<string, double>& values) {
    for (auto it = values.begin(); it != values.end(); ++it) {
        const string& key = it->first;
        double value = it->second;
        auto operandIt = operands.find(key);
        if (operandIt != operands.end()) {
            operandIt->second = value;
        }
        else {
            throw std::exception("Operand not found");
        }
    }
}

double PostfixForm::calculate() {
    istringstream iss(postfix);
    string token;

    while (iss >> token) {
        if (isalnum(token[0])) {
            auto it = operands.find(token);
            if (it == operands.end()) {
                throw std::exception("Value for operand not provided");
            }
            valuesStack->Push(it->second);
        }
        else {
            if (valuesStack->IsEmpty()) {
                throw std::exception("Missing operands");
            }
            double b = valuesStack->Top(); valuesStack->Pop();
            if (valuesStack->IsEmpty()) {
                throw std::exception("Missing operands");
            }
            double a = valuesStack->Top(); valuesStack->Pop();

            double result = 0.0;
            if (token == "+") result = a + b;
            else if (token == "-") result = a - b;
            else if (token == "*") result = a * b;
            else if (token == "/") {
                if (b == 0) {
                    throw std::exception("Division by zero");
                }
                result = a / b;
            }
            else throw std::exception("Unsupported operator");
            valuesStack->Push(result);
        }
    }

    if (valuesStack->IsEmpty()) {
        throw std::exception("stack is empty.");
    }
    double result = valuesStack->Top(); valuesStack->Pop();
    if (!valuesStack->IsEmpty()) {
        throw std::exception("stack is not empty.");
    }
    return result;
}