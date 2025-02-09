#include "postfix_form.h"
#include <vector>
#include <map>
#include <gtest.h>

TEST(Postfix_form, can_create_postfix_on_Astack)
{
    ASSERT_NO_THROW(PostfixForm tmp("A+B", 'A'));
}

TEST(Postfix_form, can_create_postfix_on_Lstack)
{
    ASSERT_NO_THROW(PostfixForm tmp("A+B", 'L'));
}

TEST(Postfix_form, can_get_infix_on_Astack)
{
    PostfixForm tmp("A+B", 'A');
    EXPECT_EQ(tmp.getInfix(), "A+B");
}

TEST(Postfix_form, can_get_infix_on_Lstack)
{
    PostfixForm tmp("A+B", 'L');
    EXPECT_EQ(tmp.getInfix(), "A+B");
}
TEST(Postfix_form, can_get_infix_on_Astack1)
{
    PostfixForm tmp("A-B", 'A');
    EXPECT_EQ(tmp.getInfix(), "A-B");
}

TEST(Postfix_form, can_get_infix_on_Lstack1)
{
    PostfixForm tmp("A-B", 'L');
    EXPECT_EQ(tmp.getInfix(), "A-B");
}

TEST(Postfix_form, can_get_infix_on_Astack2)
{
    PostfixForm tmp("A-B*(A+C)", 'A');
    cout << tmp.getInfix();
    EXPECT_EQ(tmp.getInfix(), "A-B*(A+C)");
}

TEST(Postfix_form, can_get_infix_on_Lstack2)
{
    PostfixForm tmp("A-B*(A+C)", 'A');
    cout << tmp.getInfix();
    EXPECT_EQ(tmp.getInfix(), "A-B*(A+C)");
}

TEST(Postfix_form, can_turn_infix_to_postfix_on_Astack)
{
    PostfixForm tmp("A+B", 'A');
    EXPECT_EQ(tmp.getPostfix(), "A B + ");
}

TEST(Postfix_form, can_turn_infix_to_postfix_on_Lstack)
{
    PostfixForm tmp("A+B", 'L');
    EXPECT_EQ(tmp.getPostfix(), "A B + ");
}

TEST(Postfix_form, can_turn_infix_to_postfix_on_Astack1)
{
    PostfixForm tmp("A-B", 'A');
    EXPECT_EQ(tmp.getPostfix(), "A B - ");
}

TEST(Postfix_form, can_turn_infix_to_postfix_on_Lstack1)
{
    PostfixForm tmp("A+B", 'L');
    EXPECT_EQ(tmp.getPostfix(), "A B + ");
}

TEST(Postfix_form, can_turn_infix_to_postfix_on_Astack2)
{
    PostfixForm tmp("A-B*(A+C)", 'A');
    EXPECT_EQ(tmp.getPostfix(), "A B A C + * - ");
}

TEST(Postfix_form, can_turn_infix_to_postfix_on_Lstack2)
{
    PostfixForm tmp("A-B*(A+C)", 'L');
    EXPECT_EQ(tmp.getPostfix(), "A B A C + * - ");
}

TEST(Postfix_form, can_calculate_on_Astack)
{
    PostfixForm tmp("2+4", 'A');
    ASSERT_NO_THROW(tmp.calculate());
}

TEST(Postfix_form, can_calculate_on_Lstack)
{
    PostfixForm tmp("2+4", 'L');
    ASSERT_NO_THROW(tmp.calculate());
}

TEST(Postfix_form, calculation_is_correct_on_Astack)
{
    PostfixForm tmp("2+4", 'A');
    EXPECT_EQ(tmp.calculate(), 6);
}
TEST(Postfix_form, Astack_postf1)
{
    PostfixForm tmp("A-B", 'A');
    map<string, double> operands{ {"A", 1}, {"B", 3} };
    tmp.setOperands(operands);
    EXPECT_EQ(tmp.getPostfix(), "A B - ");
}
TEST(Postfix_form, Lstack_postf1)
{
    PostfixForm tmp("A-B", 'L');
    map<string, double> operands{ {"A", 1}, {"B", 3} };
    tmp.setOperands(operands);
    EXPECT_EQ(tmp.getPostfix(), "A B - ");
}

TEST(Postfix_form, calculation_is_correct_on_Lstack)
{
    PostfixForm tmp("2+4", 'L');
}
TEST(Postfix_form, Astack2)
{
    PostfixForm tmp("A-B*(A+C)", 'A');
    map<string, double> operands{ {"A", 1}, {"B", 2}, {"C", 3} };
    tmp.setOperands(operands);
    EXPECT_EQ(tmp.calculate(), -7);
}

TEST(Postfix_form, Lstack2)
{
    PostfixForm tmp("A-B*(A+C)", 'L');
    map<string, double> operands{ {"A", 1}, {"B", 2}, {"C", 3} };
    tmp.setOperands(operands);
    EXPECT_EQ(tmp.calculate(), -7);
}
TEST(PostfixForm, Astack3)
{
    PostfixForm tmp("(A-B)/(C-A)*(K+B)+A", 'A');
    map<string, double>operands{ {"A", 1}, {"B", 3}, {"C", 2}, {"K", -2} };
    tmp.setOperands(operands);
    EXPECT_EQ(tmp.calculate(), -1);
}

TEST(PostfixForm, Lstack3)
{
    PostfixForm tmp("(A-B)/(C-A)*(K+B)+A", 'L');
    map<string, double>operands{ {"A", 1}, {"B", 3}, {"C", 2}, {"K", -2} };
    tmp.setOperands(operands);
    EXPECT_EQ(tmp.calculate(), -1);
}
