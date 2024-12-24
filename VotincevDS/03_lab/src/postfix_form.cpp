#include <iostream>
#include "postfix_form.h"
#include <unordered_map>
#include <string>
#include <vector>
#include "array_stack.h"
#include "list_stack.h"


using namespace std;



ArithmeticExpression::ArithmeticExpression(const string& s1, STACK_IMPL impl1) {
    expr = convert(s1);
    impl = impl1;
}


vector<string> ArithmeticExpression::convert(const string& input) {
    string expr = removeSpaces(input);
    vector<string> answ;


    string operand_name;
    for (size_t i = 0; i < expr.length(); ++i) {
        string c;
        c.push_back(expr[i]);
        if (c == "(" || c == ")") {
            if (is_op(operand_name) && c == ")") {
                throw "wrong expr";
            }
            /*if (is_op(operand_name)) {
                throw "wrong expression";
            }*/

            if (!operand_name.empty()) {
                answ.push_back(operand_name);
                operand_name.clear();
            }

            answ.push_back(c);
            continue;
        }
        if (is_op(c)) {
            if (!operand_name.empty()) {
                answ.push_back(operand_name);
            }

            if (answ.empty()) {
                if (c != "-") {
                    throw "wrong expression";
                }
                operand_name += c;
                continue;
            }
            if (is_op(answ[answ.size() - 1])) {
                if (i == (expr.length() - 1)) {
                    throw "wrong expression";
                }
                if ('0' <= expr[i + 1] && expr[i + 1] <= '9') {
                    operand_name.clear();
                    operand_name += c;
                    continue;
                }
                else {
                    throw "wrong expression";
                }

            }
            answ.push_back(c);
            operand_name.clear();
            continue;
        }
        operand_name += c;

    }

    if (!operand_name.empty()) {
        answ.push_back(operand_name);
    }


    return answ;
}



std::string removeSpaces(const std::string& str) {
    std::string result = str;
    result.erase(std::remove_if(result.begin(), result.end(),
        [](char c) { return std::isspace(c); }), result.end());
    return result;
}



bool is_op(const string& el) {
    return el == "*" || el == "/" || el == "+" || el == "-";
}



int op_priority(string el) {
    if (el == "*" || el == "/") {
        return 3;
    }
    else if (el == "-" || el == "+") {
        return 2;
    }
    return 1;

}


double make_op(double a, double b, string op) {
    switch (op[0])
    {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    default:
        break;
    }
}

void print_pf(vector<string>& pf) {
    cout << "\nPostfix form:\n";
    for (string el : pf) {
        cout << el << " ";
    }
    cout << '\n';
}



unordered_map<string, double> ArithmeticExpression::fill_variables() {
    unordered_map<string, double> values;
    for (string s : expr) {
        if (is_op(s) || s == "(" || s == ")") {
            continue;
        }
        if (values.find(s) == values.end()) {
            if (s[0] == '-' || '0' <= s[0] && s[0] <= '9') {
                values[s] = stoi(s);
                continue;
            }

            cout << "Type value: \n";
            cout << s << " = ";
            double val;
            cin >> val;
            values[s] = val;
        }
    }
    return values;
}




double ArithmeticExpression::compute(
    const unordered_map<string, double>& values) {




    Stack<string>* op;
    vector<string> pf;


    if (impl == ARRAY_STACK) {
        op = new ArrayStack<string>();
    }
    else {
        op = new ListStack<string>();
    }

    make_pf(op, pf);

    return solve_pf(pf, values);
}




double ArithmeticExpression::solve_pf(vector<string>& pf,
    const unordered_map<string, double>& values) {
    unordered_map<string, double> vals = values;
    if (vals.empty()) {
        vals = fill_variables();
    }


    double answ = 0;

    Stack<double>* variables;
    if (impl == ARRAY_STACK) {
        variables = new ArrayStack<double>();
    }
    else {
        variables = new ListStack<double>();
    }

    for (string el : pf) {
        if (is_op(el)) {
            double b = variables->Top();
            variables->pop();
            if (variables->IsEmpty()) {
                variables->push(-b);
                continue;
            }
            double a = variables->Top();
            variables->pop();

            variables->push(make_op(a, b, el));
            continue;
        }
        variables->push(vals[el]);

    }
    answ = variables->Top();
    return answ;
}



void ArithmeticExpression::make_pf(Stack<string>*& op, vector<string>& pf) {
    for (string el : expr) {

        // является операндом/числом
        if (!is_op(el) && el != "(" && el != ")") {
            pf.push_back(el);
            continue;
        }

        // является оператором
        if (is_op(el)) {
            if (op->IsEmpty()) {
                op->push(el);
                continue;
            }
            else {


                while (!op->IsEmpty() && op_priority(el) <= op_priority(op->Top())) {
                    pf.push_back(op->Top());
                    op->pop();
                }
                op->push(el);
                continue;
            }
        }

        if (el == "(") {
            op->push(el);
            continue;
        }
        if (el == ")") {
            if (op->IsEmpty()) {
                throw "wrong expr";
            }
            while (op->Top() != "(") {
                pf.push_back(op->Top());
                op->pop();
            }
            if (op->IsEmpty()) {
                throw "wrong expr";
            }
            op->pop();
            continue;
        }


    }
    while (!op->IsEmpty()) {
        pf.push_back(op->Top());
        op->pop();
    }
}

