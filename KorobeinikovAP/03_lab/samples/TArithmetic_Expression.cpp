#include "tarithmetic_expression.h"

int main()
{
    string exprStr;
    cout << "Enter expression:     | ";
    getline(cin, exprStr);
    try {
        TArithmeticExpression expr(exprStr);

        cout << "Infix form:           | " << expr.GetInfix() << endl;
        cout << "Postfix form:         | " << expr.GetPostfix() << endl;
        cout << "Calculate expression: | " << expr.Calculate() << endl;
    }
    catch (const char* exp){
        cout << exp << endl;
        return 0;
    }
    return 0;
}
