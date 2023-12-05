#include <iostream>
#include "tstack.h"

int main()
{
    try {
        TStack<int> S;
        S.Push(10);
        S.Push(5);
        int b = S.Pop();
        std::cout << "Put 10 and then 5 in stack" << std::endl;
        std::cout << "Get value = " << b << std::endl;
        S.Push(8);
        b = S.Pop();
        std::cout << "Put 8" << std::endl;
        std::cout << "Get value = " << b << std::endl;
    }
    catch (std::invalid_argument const& ex)
    {
    };
    
    return 0;
}
