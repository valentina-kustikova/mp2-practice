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


TEST(PostfixFormTest, CalculatePostfixExpression) {
    PostfixForm<double> postfixForm(true, 100); // Используем ArrayStack
    string infix = "a+b";
    string postfix = postfixForm.InfixToPostfix(infix);
    std::cout << "Postfix expression : " << postfix << std::endl; // Добавляем вывод
  
    postfixForm.operands['a'] = 3.0;  
    postfixForm.operands['b'] = 2.0;  

    std::cout << "Postfix expression: " << postfix << std::endl; // Добавляем вывод
    double result = postfixForm.СalculatePostfix(postfix);
    std::cout << "result " << result << std::endl;
    ASSERT_EQ(result, 5.0); // Изменяем ожидаемый результат, т.к. -3 + 2 = -1
}

TEST(PostfixFormTest, CalculatePostfixExpressionWithMinus) {
    PostfixForm<double> postfixForm(true, 100); // Используем ArrayStack
    string infix = "a+b";
    string postfix = postfixForm.InfixToPostfix(infix);
    std::cout << "Postfix expression : " << postfix << std::endl; // Добавляем вывод

    postfixForm.operands['a'] = -3.0;
    postfixForm.operands['b'] = 2.0;

    std::cout << "Postfix expression: " << postfix << std::endl; // Добавляем вывод
    double result = postfixForm.СalculatePostfix(postfix);
    std::cout << "result " << result << std::endl;
    ASSERT_EQ(result, -1.0); // Изменяем ожидаемый результат, т.к. -3 + 2 = -1
}

TEST(PostfixFormTest, InfixToPostfix_ListStack_Correct) {
    PostfixForm<double> postfixForm(false, 100); // Используем ListStack
    string infix = "a+b*(c-a)";
    EXPECT_EQ(postfixForm.InfixToPostfix(infix), "a b c a - * + ");
}


TEST(PostfixFormTest, EvaluatePostfix_ArrayStack_Correct) {
    PostfixForm<double> postfixForm(false, 100); // Используем ListStack
    string infix = "a+b";
    string postfix = postfixForm.InfixToPostfix(infix);
    std::cout << "Postfix expression : " << postfix << std::endl; // Добавляем вывод
  
    postfixForm.operands['a'] = 3.0;  
    postfixForm.operands['b'] = 2.0;  

    std::cout << "Postfix expression: " << postfix << std::endl; // Добавляем вывод
    double result = postfixForm.СalculatePostfix(postfix);
    std::cout << "result " << result << std::endl;
    ASSERT_EQ(result, 5.0); // Изменяем ожидаемый результат, т.к. -3 + 2 = -1
}

TEST(PostfixFormTest, EvaluatePostfix_ListStack_MinusCorrect) {
    PostfixForm<double> postfixForm(false, 100); // Используем ListStack
    string infix = "a+b";
    string postfix = postfixForm.InfixToPostfix(infix);
    std::cout << "Postfix expression : " << postfix << std::endl; // Добавляем вывод

    postfixForm.operands['a'] = -3.0;
    postfixForm.operands['b'] = 2.0;

    std::cout << "Postfix expression: " << postfix << std::endl; // Добавляем вывод
    double result = postfixForm.СalculatePostfix(postfix);
    std::cout << "result " << result << std::endl;
    ASSERT_EQ(result, -1.0); // Изменяем ожидаемый результат, т.к. -3 + 2 = -1
}
