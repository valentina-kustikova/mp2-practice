#include <iostream>
#include "postfix_form.h"

int main() {
    std::string input;
    std::cout << "Input expression:" << std::endl;
    std::cin >> input;

    int type;
    std::cout << "Select stack type\n" 
        << "\t0 - list\n"
        << "\t1 - array\n";
    std::cin >> type;

    auto postfix = Postfix(input, static_cast<stack_type>(type));
    std::cout << "Postfix expression: " << postfix.Get() << std::endl;
    std::cout << "Calculated result: " << postfix.Calculate() << std::endl;

    return 0;
}
