#include "Postfix_form.h"
#include <iostream>
#include <limits> // Для очистки буфера ввода

#include <iostream>
#include <string>
#include <map>
#include <stdexcept>

int main() {
    /*
    int choice;
    std::string infixExpression;

    // Запрос выбора стека
    std::cout << "Выберите тип стека:" << std::endl;
    std::cout << "1 - Стек на массиве" << std::endl;
    std::cout << "2 - Стек на списке" << std::endl;
    std::cout << "Ваш выбор: ";

    std::cin >> choice;

    // Проверка корректности ввода
    while (std::cin.fail() || (choice != 1 && choice != 2)) {
        std::cout << "Некорректный ввод. Введите 1 или 2: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> choice;
    }

    // Очистка буфера ввода перед чтением строки
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    // Запрос ввода выражения
    std::cout << "Введите арифметическое выражение (пример: A+B-C/G*H): ";
    std::getline(std::cin, infixExpression);

    try {
        // Создание PostfixEvaluator с выбранным типом стека
        PostfixForm<char> evaluator(choice == 1, 20);

        // Преобразование и вывод постфиксной формы
        std::string postfixExpression = evaluator.InfixToPostfix(infixExpression);
        std::cout << "Постфиксная форма: " << evaluator.GetPostfix() << std::endl;

    }
    catch (const std::exception& err) {
        std::cerr << "Ошибка: " << err.what() << std::endl;
    }
    */


    // Функция для очистки и подготовки введенного выражения
    return 0;

}

