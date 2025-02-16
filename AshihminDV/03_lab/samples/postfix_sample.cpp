//#include "Perem.h"
#include "postfix_form.h"

int main()
{
    std::cout << "Enter the expression" << std::endl;
    std::string s;
    int t;
    std::cin >> s;
    std::cout << "Select array type" << std::endl << "0 - array stack" << std::endl << "1 - list stack" << std::endl;
    std::cin >> t;
    TArithmeticExpression arExpr(s, static_cast<Stack_type>(t));
    std::cout << arExpr << std::endl;

    std::cout << arExpr.Calculate();
    std::cout << std::endl << "End CAlculate";


    return 1;
}