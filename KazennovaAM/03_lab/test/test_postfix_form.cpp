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

    // ���� �������� ���������� (�������� �����)
    std::stringstream input;
    input << values['a'] << std::endl;
    input << values['b'] << std::endl;
    input << values['c'] << std::endl;
    input << values['a'] << std::endl;

    // �������������� cin, ��������� ������ �����
    streambuf* oldCout = std::cin.rdbuf();
    cin.rdbuf(input.rdbuf());

    // �������� � ������������� �������� ����������
    map<char, double> actualValues = postfixForm.GetVariableValues(postfix);

    // ��������������� cin
    cin.rdbuf(oldCout);

    //������ ����� ��������� �������� ���������, ��������� known values
    double result = postfixForm.EvaluatePostfix(postfix);
    ASSERT_EQ(result, 23);
}

TEST(PostfixFormTest, EvaluatePostfix_ArrayStack_MinusCorrect) {
    PostfixForm<double> postfixForm(true, 100);
    string infix = "a+b";
    string postfix = postfixForm.InfixToPostfix(infix);

    map<char, double> values = { {'a', -2}, {'b', 3} };

    // ���� �������� ���������� (�������� �����)
    stringstream input;
    input << values['a'] << std::endl;
    input << values['b'] << std::endl;

    // �������������� cin, ��������� ������ �����
    streambuf* oldCout = std::cin.rdbuf();
    cin.rdbuf(input.rdbuf());

    // �������� � ������������� �������� ����������
    map<char, double> actualValues = postfixForm.GetVariableValues(postfix);

    // ��������������� cin
    cin.rdbuf(oldCout);

    double result = postfixForm.EvaluatePostfix(postfix);
    ASSERT_EQ(result, 1);
}

TEST(PostfixFormTest, InfixToPostfix_ListStack_Correct) {
    PostfixForm<double> postfixForm(false); // ���������� ListStack
    string infix = "a+b*(c-a)";
    EXPECT_EQ(postfixForm.InfixToPostfix(infix), "a b c a - * + ");
}

TEST(PostfixFormTest, EvaluatePostfix_ListStack_Correct) {
    PostfixForm<double> postfixForm(false); // ���������� ListStack
    string infix = "a+b*(c-a)";
    string postfix = postfixForm.InfixToPostfix(infix);

    map<char, double> values = { {'a', 3}, {'b', 5}, {'c', 7} };

    // ���� �������� ���������� (�������� �����)
    stringstream input;
    input << values['a'] << std::endl;
    input << values['b'] << std::endl;
    input << values['c'] << std::endl;
    input << values['a'] << std::endl;

    // �������������� cin, ��������� ������ �����
    streambuf* oldCout = std::cin.rdbuf();
    cin.rdbuf(input.rdbuf());

    // �������� � ������������� �������� ����������
    map<char, double> actualValues = postfixForm.GetVariableValues(postfix);

    // ��������������� cin
    cin.rdbuf(oldCout);

    double result = postfixForm.EvaluatePostfix(postfix);
    ASSERT_EQ(result, 23);
}

TEST(PostfixFormTest, EvaluatePostfix_ListStack_MinusCorrect) {
    PostfixForm<double> postfixForm(false); // ���������� ListStack
    string infix = "a+b";
    string postfix = postfixForm.InfixToPostfix(infix);
    map<char, double> values = { {'a', -2}, {'b', 3} };

    // ���� �������� ���������� (�������� �����)
    stringstream input;
    input << values['a'] << std::endl;
    input << values['b'] << std::endl;

    // �������������� cin, ��������� ������ �����
    streambuf* oldCout = std::cin.rdbuf();
    cin.rdbuf(input.rdbuf());

    // �������� � ������������� �������� ����������
    map<char, double> actualValues = postfixForm.GetVariableValues(postfix);

    // ��������������� cin
    cin.rdbuf(oldCout);

    double result = postfixForm.EvaluatePostfix(postfix);
    ASSERT_EQ(result, 1);
}
