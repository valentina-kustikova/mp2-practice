#include "Perem.h"
#include "postfix_form.h"

int main()
{
    std::cout << "Enter the expression" << std::endl;
    std::string s;
    std::cin >> s;
    TArithmeticExpression arExpr(s);
    std::cout << arExpr << std::endl;

    std::cout << arExpr.Calculate();
    std::cout << std::endl << "End CAlculate";


    return 1;
}