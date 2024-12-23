#include "stack.h"
#include "stackArray.h"
#include "ListStack.h"
#include <string>
#include <map>
#include <cctype>
#include <stdexcept>

enum class StackType {
    Array,
    List
};

template <typename T>
class ArithmeticExpression {
private:
    std::string infix;
    std::string postfix;
    Stack<T>* operatorsStack;
    Stack<double>* evaluationStack;
    StackType stackType;
    std::map<char, int> precedence = {
        {'(', 0}, {')', 0}, {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}
    };

    void parseToPostfix();

public:
    ArithmeticExpression(const std::string& expression, StackType type);
    ~ArithmeticExpression();

    void convertToPostfix();
    double evaluate(const std::map<char, double>& variables);

    std::string getPostfix() const { return postfix; }
    std::string getInfix() const { return infix; }
};

template <typename T>
ArithmeticExpression<T>::ArithmeticExpression(const std::string& expression, StackType type)
    : infix(expression), stackType(type) {
    switch (stackType) {
    case StackType::Array:
        operatorsStack = new stackArray<T>();
        evaluationStack = new stackArray<double>();
        break;
    case StackType::List:
        operatorsStack = new ListStack<T>();
        evaluationStack = new ListStack<double>();
        break;
    default:
        throw std::invalid_argument("Unsupported stack type.");
    }
}

template <typename T>
ArithmeticExpression<T>::~ArithmeticExpression() {
    delete operatorsStack;
    delete evaluationStack;
}

template <typename T>
void ArithmeticExpression<T>::convertToPostfix() {
    parseToPostfix();
}

template <typename T>
void ArithmeticExpression<T>::parseToPostfix() {
    for (char c : infix) {
        if (std::isalnum(c)) {
            postfix += c;
        }
        else if (c == '(') {
            operatorsStack->Push(c);
        }
        else if (c == ')') {
            while (!operatorsStack->IsEmpty() && operatorsStack->Top() != '(') {
                postfix += operatorsStack->Pop();
            }
            operatorsStack->Pop();
        }
        else {
            while (!operatorsStack->IsEmpty() &&
                precedence[operatorsStack->Top()] >= precedence[c]) {
                postfix += operatorsStack->Pop();
            }
            operatorsStack->Push(c);
        }
    }
    while (!operatorsStack->IsEmpty()) {
        postfix += operatorsStack->Pop();
    }
}

template <typename T>
double ArithmeticExpression<T>::evaluate(const std::map<char, double>& variables) {
    for (char c : postfix) {
        if (std::isalnum(c)) {
            if (variables.find(c) == variables.end()) {
                throw std::invalid_argument(std::string("Undefined variable: ") + c);
            }
            evaluationStack->Push(variables.at(c));
        }
        else {
            if (evaluationStack->Size() < 2) {
                throw std::runtime_error("Invalid expression.");
            }
            double b = evaluationStack->Top();
            evaluationStack->Pop();
            double a = evaluationStack->Top();
            evaluationStack->Pop();
            switch (c) {
            case '+':
                evaluationStack->Push(a + b);
                break;
            case '-':
                evaluationStack->Push(a - b);
                break;
            case '*':
                evaluationStack->Push(a * b);
                break;
            case '/':
                if (b == 0) {
                    throw std::runtime_error("Division by zero.");
                }
                evaluationStack->Push(a / b);
                break;
            default:
                throw std::invalid_argument(std::string("Unsupported operator: ") + c);
            }
        }
    }
    if (evaluationStack->Size() != 1) {
        throw std::runtime_error("Invalid postfix expression.");
    }
    return evaluationStack->Top();
}
