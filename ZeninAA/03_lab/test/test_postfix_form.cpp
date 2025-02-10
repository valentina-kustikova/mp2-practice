#include "postfix_form.h"
#include <gtest.h>
TEST(Postfix_form, can_create_postfix_on_Arraystack)
{
    ASSERT_NO_THROW(PostfixForm let("A*B", 'A'));
}

TEST(Postfix_form, can_create_postfix_on_Liststack)
{
    ASSERT_NO_THROW(PostfixForm let("A*B", 'L'));
}

TEST(Postfix_form, can_get_infix_on_Arraystack)
{
    PostfixForm let("5+3", 'A');
    EXPECT_EQ(let.getInfix(), "5+3");
}

TEST(Postfix_form, can_get_infix_on_Liststack) 
{
    PostfixForm let("7+4", 'L');
    EXPECT_EQ(let.getInfix(), "7+4");
}

TEST(Postfix_form, letters_can_get_infix_on_Arraystack)
{
    PostfixForm let("A-B*(A+C)", 'A');
    EXPECT_EQ(let.getInfix(), "A-B*(A+C)");
}

TEST(Postfix_form, letters_can_get_infix_on_Liststack)
{
    PostfixForm let("A-B*(A+C)", 'L');
    EXPECT_EQ(let.getInfix(), "A-B*(A+C)");
}

TEST(Postfix_form, letters2_can_get_infix_on_Arraystack)
{
    PostfixForm let("(A-B)/(C-A)*(K+B)+A", 'A');
    EXPECT_EQ(let.getInfix(), "(A-B)/(C-A)*(K+B)+A");
}

TEST(Postfix_form, letters2_can_get_infix_on_Liststack)
{
    PostfixForm let("(A-B)/(C-A)*(K+B)+A", 'L');
    EXPECT_EQ(let.getInfix(), "(A-B)/(C-A)*(K+B)+A");
}

TEST(Postfix_form, can_change_infix_to_postfix_on_Arraystack)
{
    PostfixForm let("2*5", 'A');
    EXPECT_EQ(let.getPostfix(), "2 5 * ");
}

TEST(Postfix_form, can_change_infix_to_postfix_on_Liststack)
{
    PostfixForm let("2*5", 'L');
    EXPECT_EQ(let.getPostfix(), "2 5 * ");
}

TEST(Postfix_form, can_count_using_Arraystack)
{
    PostfixForm let("2+5", 'A');
    ASSERT_NO_THROW(let.count());
}

TEST(Postfix_form, can_count_using_Liststack)
{
    PostfixForm let("2+5", 'L');
    ASSERT_NO_THROW(let.count());
} 

TEST(Postfix_form, can_convert_expression_to_postfix_using_Arraystack)
{
    PostfixForm let("A+B", 'A');
    EXPECT_EQ(let.getPostfix(), "A B + ");
}

TEST(Postfix_form, can_convert_expression_to_postfix_using_Liststack)
{
    PostfixForm let("A+B", 'L');
    EXPECT_EQ(let.getPostfix(), "A B + ");
}

TEST(Postfix_form, can_convert_difexpression_to_postfix_using_Arraystack)
{
    PostfixForm let("A-B*(A+C)", 'A');
    EXPECT_EQ(let.getPostfix(), "A B A C + * - ");
}

TEST(Postfix_form, can_convert_difexpression_to_postfix_using_Liststack)
{
    PostfixForm let("A-B*(A+C)", 'L');
    EXPECT_EQ(let.getPostfix(), "A B A C + * - ");
}

TEST(Postfix_form, can_convert_LASTexpression_to_postfix_using_Arraystack)
{
    PostfixForm let("(A-B)/(C-A)*(K+B)+A", 'A');
    EXPECT_EQ(let.getPostfix(), "A B - C A - / K B + * A + ");
}

TEST(Postfix_form, can_convert_LASTexpression_to_postfix_using_Liststack)
{
    PostfixForm let("(A-B)/(C-A)*(K+B)+A", 'L');
    EXPECT_EQ(let.getPostfix(), "A B - C A - / K B + * A + ");
}

TEST(PostfixForm, can_count__expression_1_on_Array_stack)
{
    PostfixForm let("A+B", 'A');
    map<string, double>operands{ {"A", 1}, {"B", 3} };
    let.setOp(operands);
    EXPECT_EQ(let.count(), 4);
}

TEST(PostfixForm, can_count__expression_1_on_List_stack)
{
    PostfixForm let("A+B", 'L');
    map<string, double>operands{ {"A", 1}, {"B", 3} };
    let.setOp(operands);
    EXPECT_EQ(let.count(), 4);
}

TEST(PostfixForm, can_count__expression_2_on_Array_stack)
{
    PostfixForm let("A-B", 'A');
    map<string, double>operands{ {"A", 1}, {"B", 3} };
    let.setOp(operands);
    EXPECT_EQ(let.count(), -2);
}

TEST(PostfixForm, can_count__expression_2_on_List_stack)
{
    PostfixForm let("A-B", 'L');
    map<string, double>operands{ {"A", 1}, {"B", 3} };
    let.setOp(operands);
    EXPECT_EQ(let.count(), -2);
}

TEST(PostfixForm, can_count__expression_3_on_Array_stack)
{
    PostfixForm let("A-B*(A+C)", 'A');
    map<string, double>operands{ {"A", 1}, {"B", 2}, {"C", 3} };
    let.setOp(operands);
    EXPECT_EQ(let.count(), -7);
}

TEST(PostfixForm, can_count__expression_3_on_List_stack)
{
    PostfixForm let("A-B*(A+C)", 'L');
    map<string, double>operands{ {"A", 1}, {"B", 2}, {"C", 3} };
    let.setOp(operands);
    EXPECT_EQ(let.count(), -7);
}

TEST(PostfixForm, can_count__expression_4_on_Array_stack)
{
    PostfixForm let("(A-B)/(C-A)*(K+B)+A", 'A');
    map<string, double>operands{ {"A", 1}, {"B", 3}, {"C", 2}, {"K", -2} };
    let.setOp(operands);
    EXPECT_EQ(let.count(), -1);
}

TEST(PostfixForm, can_count__expression_4_on_List_stack)
{
    PostfixForm let("(A-B)/(C-A)*(K+B)+A", 'L');
    map<string, double>operands{ {"A", 1}, {"B", 3}, {"C", 2}, {"K", -2} };
    let.setOp(operands);
    EXPECT_EQ(let.count(), -1);
}