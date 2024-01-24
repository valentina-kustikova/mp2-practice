#include <iostream>
#include "ArExpression.h"


int main()
{
    setlocale(LC_ALL, "rus");
    string expression_str;
    cout << "Enter expression:" << endl;
    getline(cin, expression_str);
    cout << endl;
    ArithmeticExpression expr(expression_str);
    vector<string> postfix = expr.GetPostfix();
    cout << "infix" << endl;
    cout << expr.GetInfix() << endl;
    cout << endl;
    cout << "postfix" << endl;
    auto iter_begin = postfix.begin();
    auto iter_end = postfix.end();
    while (iter_begin != iter_end) {
        cout << *iter_begin << " ";
        iter_begin++;
    }
    cout << '\n';
    vector<string> operands = expr.GetOperands();
    map<string, double> values_operands = expr.SetOperands(operands);
    cout << "Value of expression it`s " << expr.Calculate(values_operands);
    return 0;
}
