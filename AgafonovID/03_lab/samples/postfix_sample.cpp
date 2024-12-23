#include "stack.h"
#include "postfix_form.h"
#include "ListStack.h"
#include "stackArray.h"
#include <iostream>
#include <map>
#include <string>

int main() {
    std::string infixExpression;
    char stackChoice;

    std::cout << "Enter an infix expression (e.g., 3 + 4 * (2 - 1)): ";
    std::getline(std::cin, infixExpression);

   
    std::cout << "Choose stack type (A for ArrayStack, L for ListStack): ";
    std::cin >> stackChoice;
    std::cin.ignore(); 

    StackType stackType;
    if (stackChoice == 'A' || stackChoice == 'a') {
        stackType = StackType::Array;
    }
    else if (stackChoice == 'L' || stackChoice == 'l') {
        stackType = StackType::List;
    }
    else {
        std::cout << "Invalid stack type. Using ArrayStack by default.\n";
        stackType = StackType::Array;
    }

    try {
        ArithmeticExpression<char> expr(infixExpression, stackType);

        expr.convertToPostfix();
        std::cout << "Postfix expression: " << expr.getPostfix() << std::endl;

        std::map<char, double> variables;
        char varChoice;
        do {
            std::cout << "Enter a variable (e.g., 'x') and its value (e.g., 5): ";
            char var;
            double value;
            std::cin >> var >> value;
            variables[var] = value;

            std::cout << "Do you want to enter another variable? (y/n): ";
            std::cin >> varChoice;
            std::cin.ignore();
        } while (varChoice == 'y' || varChoice == 'Y');
        double result = expr.evaluate(variables);
        std::cout << "Result of the expression: " << result << std::endl;

    }
    catch (const std::exception& ex) {
        std::cout << "Error: " << ex.what() << std::endl;
    }

    return 0;
}
