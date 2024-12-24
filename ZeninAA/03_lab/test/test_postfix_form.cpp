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