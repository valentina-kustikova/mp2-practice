#include "postfix_form.h"



int main()
{
    std::cout << "Enter the expression: ";
    std::string inf;
    std::cin >> inf;
    std::map<char, double> variety;
    
    ArrStack<char> post(1);
    post = InfToPost(inf);
    GetValue(variety, post);
    double res=Counting(variety, post);
    std::cout << inf << "=" << res;
    return 0;
}
