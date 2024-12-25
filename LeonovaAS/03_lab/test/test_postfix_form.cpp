#include "postfix_form.h"
#include <vector>
#include <map>
#include <gtest.h>

TEST(Postfix_form, can_create_postfix_on_Astack)
{
    ASSERT_NO_THROW(PostfixForm bob("A+B", 'A'));
}

TEST(Postfix_form, can_create_postfix_on_Lstack)
{
    ASSERT_NO_THROW(PostfixForm bob("A+B", 'L'));
}

TEST(Postfix_form, can_get_infix_on_Astack)
{
    PostfixForm bob("1+3", 'A');
    EXPECT_EQ(bob.getInfix(), "1+3");
}

TEST(Postfix_form, can_get_infix_on_Lstack)
{
    PostfixForm bob("1+3", 'L');
    EXPECT_EQ(bob.getInfix(), "1+3");
}

TEST(Postfix_form, can_turn_infix_to_postfix_on_Astack)
{
    PostfixForm bob("1+3", 'A');
    EXPECT_EQ(bob.getPostfix(), "1 3 + ");
}

TEST(Postfix_form, can_turn_infix_to_postfix_on_Lstack)
{
    PostfixForm bob("1+3", 'L');
    EXPECT_EQ(bob.getPostfix(), "1 3 + ");
}

TEST(Postfix_form, can_calculate_on_Astack)
{
    PostfixForm bob("1+3", 'A');
    ASSERT_NO_THROW(bob.calculate());
}

TEST(Postfix_form, can_calculate_on_Lstack)
{
    PostfixForm bob("1+3", 'L');
    ASSERT_NO_THROW(bob.calculate());
}

TEST(Postfix_form, Astack)
{
    PostfixForm bob("A+B", 'A');
    map<string, double> operands{ {"A", 1}, {"B", 3} };
    bob.setOperands(operands);
    EXPECT_EQ(bob.calculate(), 4);
}

TEST(Postfix_form, Lstack)
{
    PostfixForm bob("A+B", 'L');
    map<string, double> operands{ {"A", 1}, {"B", 3} };
    bob.setOperands(operands);
    EXPECT_EQ(bob.calculate(), 4);
}

TEST(Postfix_form, Astack_postf)
{
    PostfixForm bob("A+B", 'A');
    map<string, double> operands{ {"A", 1}, {"B", 3} };
    bob.setOperands(operands);
    EXPECT_EQ(bob.getPostfix(), "A B + ");
}

TEST(Postfix_form, Lstack_postf)
{
    PostfixForm bob("A+B", 'L');
    map<string, double> operands{ {"A", 1}, {"B", 3} };
    bob.setOperands(operands);
    EXPECT_EQ(bob.getPostfix(), "A B + ");
}

TEST(Postfix_form, Astack1)
{
    PostfixForm bob("A-B", 'A');
    map<string, double> operands{ {"A", 1}, {"B", 3} };
    bob.setOperands(operands);
    EXPECT_EQ(bob.calculate(), -2);
}

TEST(Postfix_form, Lstack1)
{
    PostfixForm bob("A-B", 'L');
    map<string, double> operands{ {"A", 1}, {"B", 3} };
    bob.setOperands(operands);
    EXPECT_EQ(bob.calculate(), -2);
}

TEST(Postfix_form, Astack_postf1)
{
    PostfixForm bob("A-B", 'A');
    map<string, double> operands{ {"A", 1}, {"B", 3} };
    bob.setOperands(operands);
    EXPECT_EQ(bob.getPostfix(), "A B - ");
}

TEST(Postfix_form, Lstack_postf1)
{
    PostfixForm bob("A-B", 'L');
    map<string, double> operands{ {"A", 1}, {"B", 3} };
    bob.setOperands(operands);
    EXPECT_EQ(bob.getPostfix(), "A B - ");
}

TEST(Postfix_form, Astack2)
{
    PostfixForm bob("A-B*(A+C)", 'A');
    map<string, double> operands{ {"A", 1}, {"B", 2}, {"C", 3} };
    bob.setOperands(operands);
    EXPECT_EQ(bob.calculate(), -7);
}

TEST(Postfix_form, Lstack2)
{
    PostfixForm bob("A-B*(A+C)", 'L');
    map<string, double> operands{ {"A", 1}, {"B", 2}, {"C", 3} };
    bob.setOperands(operands);
    EXPECT_EQ(bob.calculate(), -7);
}

TEST(Postfix_form, Astack_postf2)
{
    PostfixForm bob("A-B*(A+C)", 'A');
    map<string, double> operands{ {"A", 1}, {"B", 2}, {"C", 3} };
    bob.setOperands(operands);
    EXPECT_EQ(bob.getPostfix(), "A B A C + * - ");
}

TEST(Postfix_form, Lstack_postf2)
{
    PostfixForm bob("A-B*(A+C)", 'L');
    map<string, double> operands{ {"A", 1}, {"B", 2}, {"C", 3} };
    bob.setOperands(operands);
    EXPECT_EQ(bob.getPostfix(), "A B A C + * - ");
}

TEST(Postfix_form, Astack3)
{
    PostfixForm bob("(A-B)/(C-A)*(K+B)+A", 'A');
    map<string, double> operands{ {"A", 1}, {"B", 3}, {"C", 2}, {"K", -2}};
    bob.setOperands(operands);
    EXPECT_EQ(bob.calculate(), -1);
}

TEST(Postfix_form, Lstack3)
{
    PostfixForm bob("(A-B)/(C-A)*(K+B)+A", 'L');
    map<string, double> operands{ {"A", 1}, {"B", 3}, {"C", 2}, {"K", -2} };
    bob.setOperands(operands);
    EXPECT_EQ(bob.calculate(), -1);
}

TEST(Postfix_form, Astack_postf3)
{
    PostfixForm bob("(A-B)/(C-A)*(K+B)+A", 'A');
    map<string, double> operands{ {"A", 1}, {"B", 3}, {"C", 2}, {"K", -2} };
    bob.setOperands(operands);
    EXPECT_EQ(bob.getPostfix(), "A B - C A - / K B + * A + ");
}

TEST(Postfix_form, Lstack_postf3)
{
    PostfixForm bob("(A-B)/(C-A)*(K+B)+A", 'L');
    map<string, double> operands{ {"A", 1}, {"B", 3}, {"C", 2}, {"K", -2} };
    bob.setOperands(operands);
    EXPECT_EQ(bob.getPostfix(), "A B - C A - / K B + * A + ");
}