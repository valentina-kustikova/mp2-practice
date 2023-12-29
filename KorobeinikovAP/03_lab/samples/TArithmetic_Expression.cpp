#include "tarithmetic_expression.h"

int main()
{
    string exprStr;
    cout << "Enter expression:     | ";
    getline(cin, exprStr);

    TArithmeticExpression expr(exprStr); 
  
    cout << "Infix form:           | " << expr.GetInfix() << endl;
    cout << "Postfix form:         | " << expr.GetPostfix() << endl;
    cout << "Calculate expression: | " << expr.Calculate() << endl;
    
    return 0;
}
