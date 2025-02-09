#ifndef POSTFIX_FORM_H
#define POSTFIX_FORM_H

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
    int getPriority(const std::string& op) const {
        if (op == "+" || op == "-") return 1;
        if (op == "*" || op == "/") return 2;
        return 0;
    }

    bool isOperator(const std::string& el) const {
        return el == "+" || el == "-" || el == "*" || el == "/";
    }

    bool isOperand(const std::string& el) const {
        if (std::isdigit(el[0])) return true;
        if (el.size() > 1 && el[0] == '-' && std::isdigit(el[1])) return true;
        if (std::isalpha(el[0])) return true;
        return false;
    }

    bool isNumber(const std::string& s) const {
        try {
            std::stod(s);
            return true;
        }
        catch (...) {
            return false;
        }
    }

    std::vector<std::string> parse(const std::string& expression) const {
        std::vector<std::string> elems;
        std::string current;
        bool expect_operand = true;

        for (size_t i = 0; i < expression.size(); ++i) {
            char c = expression[i];

            if (std::isspace(c)) {
                if (!current.empty()) {
                    elems.push_back(current);
                    current.clear();
                }
                expect_operand = true;
                continue;
            }
            if (c == '-' && expect_operand) {
                if (!current.empty()) {
                    elems.push_back(current);
                    current.clear();
                }
                current += c;
                expect_operand = true;
                continue;
            }
            if (std::isdigit(c) || (c == '.' && !current.empty())) {
                current += c;
                expect_operand = false;
            }
            else if (std::isalpha(c)) {
                if (!current.empty() && (current[0] == '-' || !std::isalpha(current[0]))) {
                    elems.push_back(current);
                    current.clear();
                }
                current += c;
                expect_operand = false;
            }
            else {
                if (!current.empty()) {
                    elems.push_back(current);
                    current.clear();
                }
                elems.push_back(std::string(1, c));
                expect_operand = (c == '(' || isOperator(std::string(1, c)));
            }
        }

        if (!current.empty()) {
            elems.push_back(current);
        }
        std::cout << "Tokens: ";
        for (const auto& t : elems) std::cout << "[" << t << "] ";
        std::cout << std::endl;
        return elems;
    }

public:
    ArExpression(const std::string& expr, STACK_IMPL impl) : infix(expr), stackType(impl) {
        if (impl == ARRAY_STACK) {
            stack = new stackArray<std::string>();
        }
        else {
            stack = new ListStack<std::string>();
        }
        convertToPostfix();
    }

    ~ArExpression() {
        delete stack;
    }

    void convertToPostfix() {
        std::vector<std::string> elems = parse(infix);

        for (int i = 0; i < elems.size(); i++) {
            const std::string& el = elems[i];
            if (isOperand(el)) {  
                postfix.push_back(el);
            }
            else if (isOperator(el)) {
                while (!stack->IsEmpty() && getPriority(stack->Top()) >= getPriority(el)) {
                    postfix.push_back(stack->Top());
                    stack->Pop();
                }
                stack->Push(el);
            }
            else if (el == "(") {
                stack->Push(el);
            }
            else if (el == ")") {
                while (!stack->IsEmpty() && stack->Top() != "(") {
                    postfix.push_back(stack->Top());
                    stack->Pop();
                }
                if (!stack->IsEmpty() && stack->Top() == "(") {
                    stack->Pop();
                }
            }
        }

        while (!stack->IsEmpty()) {
            postfix.push_back(stack->Top());
            stack->Pop();
        }
    }

    double evaluate(const std::map<std::string, double>& values) {
        Stack<double>* evalStack;

        if (stackType == ARRAY_STACK) {
            evalStack = new stackArray<double>();
        }
        else {
            evalStack = new ListStack<double>();
        }

        for (int i = 0; i < postfix.size(); i++) {
            const std::string& el = postfix[i];
            if (isNumber(el)) { 
                evalStack->Push(std::stod(el));
            }
            else if (values.find(el) != values.end()) { 
                evalStack->Push(values.at(el));
            }
            else if (isOperator(el)) {
                if (evalStack->IsEmpty()) {
                    throw std::exception("Invalid expression");
                }
                double b = evalStack->Top();
                evalStack->Pop();
                if (evalStack->IsEmpty()) {
                    throw std::exception("Invalid expression");
                }
                double a = evalStack->Top();
                evalStack->Pop();

                if (el == "+") {
                    evalStack->Push(a + b);
                }
                else if (el == "-") {
                    evalStack->Push(a - b);
                }
                else if (el == "*") {
                    evalStack->Push(a * b);
                }
                else if (el == "/") {
                    if (b == 0) {
                        throw std::exception("Division by zero");
                    }
                    evalStack->Push(a / b);
                }
            }
        }

        double result = evalStack->Top();
        delete evalStack;
        return result;
    }

    std::vector<std::string> getPostfix() const {
        return postfix;
    }
};
#endif
