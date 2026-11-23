#include  <iostream>
#include "postfix_form.h"

int main() {

    try {
        std::string expression;
        std::cout << "Enter expression: ";
        std::getline(std::cin, expression);

        PostfixForm form(expression);

        std::cout << "Result: " << form.Calculate() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}


