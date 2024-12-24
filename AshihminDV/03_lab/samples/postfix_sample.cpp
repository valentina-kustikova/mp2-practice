#include "Perem.h"
#include "postfix_form.h"

int main()
{
    //std::cout << "Enter count of the variables" << std::endl;

    //int count;

    //std::cin >> count;

    //std::cout << "Enter the variables" << std::endl;

    //perems<int> perems(count);
    //std::cin >> perems;
    //
    ////std::cout << "Enter complete" << std::endl;

    //std::cout << perems;
    //std::string str;
    //std::cout << "Enter the expression" << std::endl;
    //std::cin >> str;

    std::string s;
    std::cin >> s;
    TArithmeticExpression arExpr(s);
    std::cout << arExpr << std::endl;

    std::cout << arExpr.Calculate();
    std::cout << std::endl << "End CAlculate";


    return 1;
}


//идем по инфиксной строке и проверяем на операнд/операцию, складываем в разные стеки и перекидываем
//идем по инфиксной строке и проверяем на операнд/операцию, в зависимости от приоритета производимо операции в 1 стеке