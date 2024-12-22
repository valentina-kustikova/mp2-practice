#include "postfix_form.h"

void main() {
    string exprstr;
    cout << "Enter expression: ";
    cin >> exprstr;

    AriExpress<char> expr(exprstr); 
    cout << "Infix expression: " << expr.get_infix() << endl;
    cout << "Postfix expression: " << expr.get_postfix() << endl;

    vector<char> operands = expr.getoperands(); 
    map<char, double> values;
    double val;

    for (const auto& op : operands) {
        cout << "Enter value of " << op << ": ";
        cin >> val;
        values[op] = val;
    }

    cout << "Result: " << expr.calculate(values) << endl;
}
