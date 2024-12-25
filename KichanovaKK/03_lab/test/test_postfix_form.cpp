#include "stack.h"
#include "list_stack.h"
#include "main_stack.h"
#include "postfix_form.h"
#include <gtest.h>

TEST(postfixtest, postfixform_on_stack_write_correct)
{
    MainStack<char>* opStack = new stack<char>();
    MainStack<string>* opndStack = new stack<string>();
    AriExpress expr("a+b*(c-a)", opStack, opndStack);
    EXPECT_EQ(expr.to_postfix(), "abca-*+");
}

TEST(postfixtest, postfixform_on_stack_count_correct)
{
    MainStack<char>* opStack = new stack<char>();
    MainStack<string>* opndStack = new stack<string>();
    AriExpress expr("a+b*(c-a)", opStack, opndStack);
    expr.to_postfix();
    std::map<char, double> values = { {'a',3},{'b',5},{'c',7} };
    ASSERT_EQ(expr.calculate(values), 23);
}
TEST(postfixtest, postfixform_on_stack_count_minus_correct)
{
    MainStack<char>* opStack = new stack<char>();
    MainStack<string>* opndStack = new stack<string>();
    AriExpress expr("a+b", opStack, opndStack);
    expr.to_postfix();
    std::map<char, double> values = { {'a',-2},{'b',3} };
    ASSERT_EQ(expr.calculate(values), 1);
}

TEST(postfixtest, postfixform_on_liststack_write_correct)
{
    MainStack<char>* opStack = new liststack<char>();
    MainStack<string>* opndStack = new liststack<string>();
    AriExpress expr("a+b*(c-a)", opStack, opndStack);
    EXPECT_EQ(expr.to_postfix(), "abca-*+");
}

TEST(postfixtest, postfixform_on_liststack_count_correct)
{
    MainStack<char>* opStack = new liststack<char>();
    MainStack<string>* opndStack = new liststack<string>();
    AriExpress expr("a+b*(c-a)", opStack, opndStack);
    expr.to_postfix();
    std::map<char, double> values = { {'a',3},{'b',5},{'c',7} };
    ASSERT_EQ(expr.calculate(values), 23);
}
TEST(postfixtest, postfixform_on_liststack_count_minus_correct)
{
    MainStack<char>* opStack = new liststack<char>();
    MainStack<string>* opndStack = new liststack<string>();
    AriExpress expr("a+b", opStack, opndStack);
    std::map<char, double> values = { {'a',-2},{'b',3} };
    ASSERT_EQ(expr.calculate(values), 1);
}


