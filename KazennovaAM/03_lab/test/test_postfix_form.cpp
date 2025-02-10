#include <gtest.h>
#include "stack.h"
#include "list_stack.h"
#include "stack_array.h"
#include "postfix_form.h"
#include <gtest.h>


TEST(PostfixFormTest, InfixToPostfix_ArrayStack_Correct) {
    PostfixForm<double> postfixForm(true, 100);
    string infix = "a+b*(c-a)";
    EXPECT_EQ(postfixForm.InfixToPostfix(infix), "a b c a - * + ");
}

TEST(PostfixFormTest, EvaluatePostfix_ArrayStack_Correct) {
    PostfixForm<double> postfixForm(true, 100);
    string infix = "a+b*(c-a)";
    string postfix = postfixForm.InfixToPostfix(infix);
    map<char, double> values = { {'a', 3}, {'b', 5}, {'c', 7} };

    // Ввод значений переменных (имитация ввода)
    std::stringstream input;
    input << values['a'] << std::endl;
    input << values['b'] << std::endl;
    input << values['c'] << std::endl;
    input << values['a'] << std::endl;

    // Перенаправляем cin, сохраняем старый буфер
    streambuf* oldCout = std::cin.rdbuf();
    cin.rdbuf(input.rdbuf());

    // Получаем и устанавливаем значения переменных
    map<char, double> actualValues = postfixForm.GetVariableValues(postfix);

    // Восстанавливаем cin
    cin.rdbuf(oldCout);

    //Теперь можем вычислить значение выражения, используя known values
    double result = postfixForm.EvaluatePostfix(postfix);
    ASSERT_EQ(result, 23);
}

TEST(PostfixFormTest, EvaluatePostfix_ArrayStack_MinusCorrect) {
    PostfixForm<double> postfixForm(true, 100);
    string infix = "a+b";
    string postfix = postfixForm.InfixToPostfix(infix);

    map<char, double> values = { {'a', -2}, {'b', 3} };

    // Ввод значений переменных (имитация ввода)
    stringstream input;
    input << values['a'] << std::endl;
    input << values['b'] << std::endl;

    // Перенаправляем cin, сохраняем старый буфер
    streambuf* oldCout = std::cin.rdbuf();
    cin.rdbuf(input.rdbuf());

    // Получаем и устанавливаем значения переменных
    map<char, double> actualValues = postfixForm.GetVariableValues(postfix);

    // Восстанавливаем cin
    cin.rdbuf(oldCout);

    double result = postfixForm.EvaluatePostfix(postfix);
    ASSERT_EQ(result, 1);
}

TEST(PostfixFormTest, InfixToPostfix_ListStack_Correct) {
    PostfixForm<double> postfixForm(false); // Используем ListStack
    string infix = "a+b*(c-a)";
    EXPECT_EQ(postfixForm.InfixToPostfix(infix), "a b c a - * + ");
}

TEST(PostfixFormTest, EvaluatePostfix_ListStack_Correct) {
    PostfixForm<double> postfixForm(false); // Используем ListStack
    string infix = "a+b*(c-a)";
    string postfix = postfixForm.InfixToPostfix(infix);

    map<char, double> values = { {'a', 3}, {'b', 5}, {'c', 7} };

    // Ввод значений переменных (имитация ввода)
    stringstream input;
    input << values['a'] << std::endl;
    input << values['b'] << std::endl;
    input << values['c'] << std::endl;
    input << values['a'] << std::endl;

    // Перенаправляем cin, сохраняем старый буфер
    streambuf* oldCout = std::cin.rdbuf();
    cin.rdbuf(input.rdbuf());

    // Получаем и устанавливаем значения переменных
    map<char, double> actualValues = postfixForm.GetVariableValues(postfix);

    // Восстанавливаем cin
    cin.rdbuf(oldCout);

    double result = postfixForm.EvaluatePostfix(postfix);
    ASSERT_EQ(result, 23);
}

TEST(PostfixFormTest, EvaluatePostfix_ListStack_MinusCorrect) {
    PostfixForm<double> postfixForm(false); // Используем ListStack
    string infix = "a+b";
    string postfix = postfixForm.InfixToPostfix(infix);
    map<char, double> values = { {'a', -2}, {'b', 3} };

    // Ввод значений переменных (имитация ввода)
    stringstream input;
    input << values['a'] << std::endl;
    input << values['b'] << std::endl;

    // Перенаправляем cin, сохраняем старый буфер
    streambuf* oldCout = std::cin.rdbuf();
    cin.rdbuf(input.rdbuf());

    // Получаем и устанавливаем значения переменных
    map<char, double> actualValues = postfixForm.GetVariableValues(postfix);

    // Восстанавливаем cin
    cin.rdbuf(oldCout);

    double result = postfixForm.EvaluatePostfix(postfix);
    ASSERT_EQ(result, 1);
}
