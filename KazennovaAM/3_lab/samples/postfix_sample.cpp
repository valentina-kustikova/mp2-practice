#include "Postfix_form.h"
#include <iostream>
#include <limits> // Для очистки буфера ввода

#include <iostream>
#include <string>
#include <map>
#include <stdexcept>


int main() {
    bool useArrayStack;
    int arrayStackSize;
    std::string infixExpression;

    // 1. Спрашиваем у пользователя, какой стек он хочет использовать
    char stackType;
    std::cout << "Select stack type:" << std::endl;
    std::cout << "1 - Stack on array" << std::endl;
    std::cout << "2 - Stack on list" << std::endl;
    std::cout << "Your choice: ";
    std::cin >> stackType;

    if (stackType == '1') {
        useArrayStack = true;
        std::cout << "Enter the size of the array stack: ";
        std::cin >> arrayStackSize;
    }
    else if (stackType == '2') {
        useArrayStack = false;
        arrayStackSize = 0; // Не используется для стека на списке, но нужно для конструктора
    }
    else {
        std::cerr << "Invalid stack type. Default is list based stack." << std::endl;
        useArrayStack = false;
        arrayStackSize = 0;
    }

    // 2. Ввод арифметического примера
    std::cout << "Enter an arithmetic expression (example: (a-b)/(c-a)*(k+b)+a): ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, infixExpression);

    // 3. Преобразование в постфиксную форму и вывод
    PostfixForm<double> calculator(useArrayStack, arrayStackSize);
    std::string postfixExpression;
    try {
        postfixExpression = calculator.InfixToPostfix(infixExpression);
        std::cout << "Postfix form: " << postfixExpression << std::endl;
    }
    catch (const char* e) {
        std::cerr << "Error converting infix to postfix notation: " << e << std::endl;
        return 1;
    }
    catch (const std::string& e) {
        std::cerr << "Error converting infix to postfix notation:: " << e << std::endl;
        return 1;
    }

    // 4. Запрос значений переменных (операндов)
    calculator.operands = calculator.GetVariableValues(postfixExpression);

    // 5. Вычисление постфиксного выражения и вывод результата
    try {
        double result = calculator.СalculatePostfix(postfixExpression);
        std::cout << "Result: " << result << std::endl;
    }
    catch (const char* e) {
        std::cerr << "Calculation error: " << e << std::endl;
        return 1;
    }
    catch (const std::string& e) {
        std::cerr << "Calculation error: " << e << std::endl;
        return 1;
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Calculation error:" << e.what() << std::endl;
        return 1;
    }

    return 0;
}