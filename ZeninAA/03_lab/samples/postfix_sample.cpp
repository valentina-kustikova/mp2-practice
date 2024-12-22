#include "postfix_form.h"
#include "list.h"



void main()
{
    List<int> a;
    a.PushBack(8);
    a.PushFront(7);
    a.PopBack();
    a.PopFront();
    
    using namespace posfix_form;
    try
    {
        int flag = 1;
        while (flag == 1)
        {
            std::cout << "INPUT: ";
            std::string inf;
            std::cin >> inf;
            ArithmeticExpression ex(inf, LIST_STACK);
            ex.GetVariable();
            double res = ex.Calculate();
            std::cout << "The result is: " << res;
            std::cout << "\n Continue: 1" << "\n EXIT: 0\n";
            std::cin >> flag;
        }

        std::cout << "\nYou ended the program";
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what();
    }
}