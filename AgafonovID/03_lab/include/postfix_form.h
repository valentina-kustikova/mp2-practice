#ifndef POSTFIX_FORM_H
#define POSTFIX_FORM_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdexcept>
#include <cctype>
#include <sstream>
#include "stack.h"
#include "stackArray.h"
#include "ListStack.h"

enum STACK_IMPL {
    ARRAY_STACK = 0,
    LIST_STACK = 1
};

class ArExpression {
private:
    std::string infix;
    std::vector<std::string> postfix;
    std::map<std::string, double> variables;
    Stack<std::string>* stack;
    STACK_IMPL stackType; 
    int getPriority(const std::string& op) const;

    bool isOperator(const std::string& el) const;

    bool isOperand(const std::string& el) const;

    bool isNumber(const std::string& s) const;

    std::vector<std::string> parse(const std::string& expression) const;

public:
    ArExpression(const std::string& expr, STACK_IMPL impl);

    ~ArExpression();

    void convertToPostfix();

    double evaluate(const std::map<std::string, double>& values);

    std::vector<std::string> getPostfix() const;
};
#endif
