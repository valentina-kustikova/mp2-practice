#include <iostream>
#include <map>
#include <string>
#include "postfix_form.h"

using namespace std;

int main() {
    try {
        cout << "Choose stack type (A/L): ";
        char stackType;
        cin >> stackType;

        STACK_IMPL impl;
        if (stackType == 'A') impl = ARRAY_STACK;
        else if (stackType == 'L') impl = LIST_STACK;
        else {
            cout << "Incorrect choice" << endl;
            return 1;
        }

        cout << "Infix expression: ";
        cin.ignore();
        string expr;
        getline(cin, expr);

        ArExpression arExpr(expr, impl);

        cout << "Infix: " << expr << endl;
        cout << "Postfix: ";

        vector<string> postfix = arExpr.getPostfix();
        for (int i = 0; i < postfix.size(); i++) {
            cout << postfix[i] << " ";
        }
        cout << endl;

        map<string, double> values;
        cout << "Enter values for operands:" << endl;

        for (int i = 0; i < postfix.size(); i++) {
            if (isalpha(postfix[i][0]) && values.find(postfix[i]) == values.end()) {
                cout << postfix[i] << ": ";
                double value;
                cin >> value;
                values[postfix[i]] = value;
            }
        }

        double result = arExpr.evaluate(values);
        cout << "Result: " << result << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
