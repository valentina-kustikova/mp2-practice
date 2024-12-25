#include <iostream>
#include <map>
#include <string>
#include "postfix_form.h"
#include "stackArray.h"
#include "ListStack.h"

using namespace std;

int main() {
    try {
        cout << "Choose stack type (A/L): \n";
        char stackType;
        cin >> stackType;

        if (stackType != 'A' && stackType != 'L') {
            cout << "Incorrect choice" << endl;
            return 1;
        }

        cout << "infix expression: ";
        cin.ignore(); 
        string expr;
        getline(cin, expr);

        PostfixForm pf(expr, stackType);

        cout << "Infix: " << pf.getInfix() << endl;
        cout << "Postfix: " << pf.getPostfix() << endl;

        map<string, double> values;

        cout << "Enter values for operands:" << endl;

        vector<string> operands = pf.getOperands(); 
        for (size_t i = 0; i < operands.size(); ++i) {
            cout << operands[i] << ": ";
            double value;
            cin >> value;
            values[operands[i]] = value;
        }

        pf.setOperands(values);

        double result = pf.calculate();
        cout << "Result: " << result << endl;

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
