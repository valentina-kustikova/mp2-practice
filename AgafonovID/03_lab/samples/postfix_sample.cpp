#include <iostream>
#include <map>
#include <string>
#include "postfix_form.h"
#include "stackArray.h"
#include "ListStack.h"

using namespace std;

int main() {
    try {
        cout << "1. Array";
        cout << "2. List";
        int answ;
        cin >> answ;

        if (answ != 1 && answ != 2) {
            cerr << "Invalid choice!" << endl;
            return 1;
        }

        Stack<char>* operatorsStack = nullptr;
        Stack<string>* operandsStack = nullptr;
        if (answ == 1) {
            operatorsStack = new stackArray<char>(100);
            operandsStack = new stackArray<string>(100);
        }
        else {
            operatorsStack = new ListStack<char>();
            operandsStack = new ListStack<string>();
        }

        string exprstr;
        cout << "infix expression: ";
        cin >> exprstr;
        StackType stackType = (answ == 1) ? Array : ListSt;
        AriExpress<char> expr(exprstr, operatorsStack, operandsStack, stackType);

        cout << "Infix expression: " << expr.get_infix() << endl;
        cout << "Postfix expression: " << expr.get_postfix() << endl;

        vector<char> operands = expr.getoperands();
        map<char, double> values;
        double val;
        for (const auto& op : operands) {
            cout << "Enter value for " << op << ": ";
            cin >> val;
            values[op] = val;
        }
        double result = expr.calculate(values);
        cout << "Result: " << result << endl;

    }
    catch (const exception& ex) {
        cerr << "Error: " << ex.what() << endl;
    }

    return 0;
}
