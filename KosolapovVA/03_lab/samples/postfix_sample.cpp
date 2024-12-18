#include "postfix_form.h"



void main()
{
    using namespace posfix_form;
    try
    {
        int flag = 1;
        while (flag == 1)
        {
            std::cout << "Write: ";
            std::string inf;
            std::cin >> inf;
            ArExpression ex(inf, ARRAY_STACK);
            ex.GetVariable();
            double res = ex.Calculate();
            std::cout << "result: " << res;
            std::cout << "\n If you want to calculate more, enter: 1" << "\n If you want to exit the program, enter: -1\n";
            std::cin >> flag;
        }
        
        std::cout << "\nEnd";
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what();
    }
}
