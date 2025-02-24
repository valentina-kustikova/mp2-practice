#include "postfix_form.h"
#include <string>

void Postfix::infixToPostfix(std::string s) {
    Stack<char>* st;
    if (type_ == stack_type::array) {
        st = new StackArray<char>;
    } else if (type_ == stack_type::list) {
        st = new StackList<char>;
    }

    auto is_operand = [] (const char& c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    };

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        if (is_operand(c)) {
            std::string operand;
            while (is_operand(s[i]) && i < s.length()) {
                operand += s[i];
                ++i;
            }
            --i;
            postfix_.push_back(operand);
        }

        else if (c == '(')
            st->push('(');

        else if (c == ')') {
            while (st->top() != '(') {
                postfix_.push_back(std::string{st->top()});
                st->pop();
            }
            st->pop(); 
        }

        else {
            while (!st->empty() && prec(c) <= prec(st->top())) {
                postfix_.push_back(std::string{st->top()});
                st->pop();
            }
            st->push(c);
        }
    }

    while (!st->empty()) {
        postfix_.push_back(std::string{st->top()});
        st->pop();
    }

    delete st;
}

int Postfix::prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

int Postfix::do_operation(int& num1, int& num2, std::string& operation) {
    if (operation == "+") {
        return num1 + num2;
    } else if (operation == "-") {
        return num1 - num2;
    } else if (operation == "*") {
        return num1 * num2;
    } else if (operation == "/") {
        return num1 / num2;
    } else if (operation == "^") {
        return pow(num1, num2);
    }
    return 0;
}

bool Postfix::isOperation(std::string& symbol) {
    if (symbol == "+" || 
        symbol == "-" ||
        symbol == "*" ||
        symbol == "/" ||
        symbol == "^") {
        return true;
    }
    return false;
}

Postfix::Postfix(std::string& infix, enum stack_type type) {
    type_ = type;
    infixToPostfix(infix);
}

std::string Postfix::Get() {
    std::string str_postfix;
    for (auto x : postfix_) {
        str_postfix += x;
    }
    return str_postfix;
}

int Postfix::Calculate(std::unordered_map<std::string, int> operands) {
    Stack<char>* order;
    if (type_ == stack_type::array) {
        order = new StackArray<char>;
    } else if (type_ == stack_type::list) {
        order = new StackList<char>;
    }

    for (size_t i = 0; i < postfix_.size(); i++) {
        if (!isOperation(postfix_[i])) {
            int num;
            if (operands.find(postfix_[i]) == operands.end()) {
                num = std::stoi(postfix_[i]);
            }
            else {
                num = operands[postfix_[i]];
            }
            order->push(num);
        }
        else {
            int a = order->top();
            order->pop();
            int b = order->top();
            order->pop();
            order->push(do_operation(b, a, postfix_[i]));
        }

    }

    int res = 0;
    if (!order->empty()) 
        res = order->top();
    delete order;
    return res; 
}
