#include <iostream>
#include "tarithmetic_expression.h"

int main()
{
    string exprStr;
    cout << "Enter expression :";
    cin >> exprStr;
    TArithmeticExpression expr(exprStr); 
    cout << expr.GetInfix() << endl;
    cout << expr.GetPostfix() << endl;
    vector<char> operands = expr.GetOperands();
    map<char, double> values;
    double val;
    for (const auto& op : operands)
    {
        cout << "Enter value of " << op << ": ";
        cin >> val;
        values[op] = val;
    }
  
    cout << expr.Calculate(values) << endl;
    setlocale(LC_ALL, "Russian");
}
