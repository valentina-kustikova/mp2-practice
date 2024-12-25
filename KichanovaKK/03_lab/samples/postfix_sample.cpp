#include "postfix_form.h"
#include "stack.h"
#include "list_stack.h"
#include "main_stack.h"

void main() {
    cout << "Choose type of stack:\n";
    cout << "1. Simple stack (stack)\n";
    cout << "2. Stack on TNode (liststack)\n";
    cout << "Your choice: ";
    int choice;
    cin >> choice;

    MainStack<char>* opStack = nullptr;
    MainStack<string>* opndStack = nullptr;

    if (choice == 1) {
        opStack = new stack<char>();
        opndStack = new stack<string>();
        cout << "Simple stack (stack).\n";
    }
    else if (choice == 2) {
        opStack = new liststack<char>();
        opndStack = new liststack<string>();
        cout << "Stack on TNode (liststack).\n";
    }
    else {
        throw "Error";
    }

    string exprstr;
    cout << "Enter expression: ";
    cin >> exprstr;

    AriExpress expr(exprstr, opStack, opndStack);
    cout << "Postfix expression: " << expr.to_postfix() << endl;

    map<char, double> values = expr.getoperands();
    cout << "Result: " << expr.calculate(values) << endl;
}
