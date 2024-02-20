#include "tPostfixNotation.h"
#include <vector>
tPostfix::tPostfix(const string& S){
    expression = S;
    postfix_notation();
}

int tPostfix::get_operator_priority(const string op){
    switch(op[0]) {
    case '(':
    case ')':
        return 1;
        break;
    case '+':
    case '-':
        return 2;
        break;
    case '*':
    case '/':
        return 3;
        break;
    default:
        throw "not an operator";
        break;
    }
}

bool tPostfix::is_operator(const int i) const{
    char TMP[6] = { '+', '-', '(', ')', '*', '/' };
    for (int j = 0; j < 6; j++)
        if (TMP[j] == expression[i])
            return true;
    return false;
}
bool tPostfix::is_operator(char c) const{
    char TMP[6] = { '+', '-', '(', ')', '*', '/'};
    for (int j = 0; j < 6; j++)
        if (TMP[j] == c)
            return true;
    return false;
}
bool tPostfix::is_operator(const string c) const {
    string TMP[6] = { "+", "-", "*", "/", "(", ")" };
    for (int j = 0; j < 6; j++)
        if (TMP[j] == c)
            return true;
    return false;
}

void tPostfix::divide_string(){
    string tmp = "";
    string tmpOp = "";
    for (int i = 0; i < expression.size(); i++){
        if(!is_operator(expression[i]))
            tmp += expression[i];
        else{
            if (tmp != "") {
                expression_refined.push_back(tmp);
                add_a_new_variable(tmp);
            }
            tmpOp += expression[i];
            expression_refined.push_back(tmpOp);
            tmp = "";
            tmpOp = "";
        }
    }
    if (tmp != "") {
        expression_refined.push_back(tmp);
        add_a_new_variable(tmp);
    }
    if (vars.size() <= 1)
        throw "less than two operators";
}

void tPostfix::add_a_new_variable(const string S){
     operand tmp(S);
    for (int i = 0; i < vars.size(); i++)
        if (tmp.name == vars[i].name)
            return;
    vars.push_back(tmp);
}

void tPostfix::get_values_for_variables(){
    double tmp;
    for (int i = 0; i < vars.size(); i++)
    {
        try {
            vars[i].value = stoi(vars[i].name);
        }
        catch (...) {
            cout << vars[i].name << " value: ";
            cin >> tmp;
            vars[i].value = tmp;
        }
    }
    cout << endl;
    for (int i = 0; i < vars.size(); i++)
    {
        try {
            double tmp = stoi(vars[i].name);
        }
        catch (...) {
            cout << vars[i].name << " = " << vars[i].value << endl;
        }
    }
}

void tPostfix::postfix_notation(){
    divide_string();
    TStack<string> VariableStack(expression_refined.size()+1);
    TStack<string> OperatorStack(expression_refined.size()+1);
    for (int i = 0; i < expression_refined.size(); i++) {
        if(!is_operator(expression_refined[i]))
        VariableStack.add(expression_refined[i]);
        else {
            if((OperatorStack.is_empty()) || (expression_refined[i] == "(")){
                OperatorStack.add(expression_refined[i]);
                continue;
            }
            if (expression_refined[i] == ")"){
                while(!OperatorStack.is_empty()){
                    string op = OperatorStack.top();
                    OperatorStack.del();
                    if (op == "(")
                        break;
                    VariableStack.add(op);
                }
            } else {
                if (get_operator_priority(expression_refined[i]) <= get_operator_priority(OperatorStack.top())){
                    while(!OperatorStack.is_empty()){
                        if (get_operator_priority(expression_refined[i])<= get_operator_priority(OperatorStack.top())){
                        VariableStack.add(OperatorStack.top());
                        OperatorStack.del();
                        } else break;
                    }
                }
                OperatorStack.add(expression_refined[i]);
            }
        }
    }
    while (!OperatorStack.is_empty()){
        VariableStack.add(OperatorStack.top());
        OperatorStack.del();
    }
    create_postfixed_expression(VariableStack);

}

void tPostfix::create_postfixed_expression(TStack<string>& S) {
    TStack<string> Reversed(40);
    while (!S.is_empty()){
        Reversed.add(S.top());
        S.del();
    }
    while (!Reversed.is_empty()){
        expression_postfixed.push_back(Reversed.top());
        Reversed.del();
    }
}

double tPostfix::calculate_the_result(){
    TStack<double> ValueStack(expression_postfixed.size());
    for (int i = 0; i < expression_postfixed.size(); i++) {
        if (is_operator(expression_postfixed[i])) {
            double st = ValueStack.top();
            ValueStack.del();
            double nd = ValueStack.top();
            ValueStack.del();
            ValueStack.add(operation(nd, expression_postfixed[i][0], st));
        }
        else {
            string A;
            for (int j = 0; j < vars.size(); j++)
                if (expression_postfixed[i] == vars[j].name)
                    ValueStack.add(vars[j].value);
        }
    }
    return ValueStack.top();
}

double tPostfix::operation (double a, char op, double b){
    switch (op){
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0)
                throw "can't divide by zero";
                return a/b;
        default:
            throw "smth";
    }
}