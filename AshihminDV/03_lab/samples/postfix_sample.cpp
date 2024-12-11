#include "Perem.h"

int main()
{   
    std::cout << "Enter count of the variables" << std::endl;

    int count;

    std::cin >> count;

    std::cout << "Enter the variables" << std::endl;

    perems<int> perems(count);
    std::cin >> perems;
    
    //std::cout << "Enter complete" << std::endl;

    std::cout << perems;
    std::string str;
    std::cout << "Enter the expression" << std::endl;
    std::cin >> str;


    return 0;
}
