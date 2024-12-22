#include <gtest.h>
#include "postfix_form.h"

TEST(test_postfix, can_create_postfix_on_arr_stack)
{
    using namespace posfix_form;
    std::string inf = "A+B-C/F*D";
    ASSERT_NO_THROW(ArExpression ex(inf, ARRAY_STACK));
}

TEST(test_postfix, can_define_a_constant_on_arr_stack)
{
    using namespace posfix_form;
    std::string inf = "1+1+1+1";
    ArExpression ex(inf, ARRAY_STACK);
    ASSERT_NO_THROW(ex.GetVariable());
}

TEST(test_postfix, can_calculate_on_arr_stack)
{
    using namespace posfix_form;
    std::string inf = "1+1+1+1";
    ArExpression ex(inf, ARRAY_STACK);
    ex.GetVariable();
    double res;
    ASSERT_NO_THROW(res = ex.Calculate());
}
TEST(test_postfix, correct_calculate_on_arr_stack)
{
    using namespace posfix_form;
    std::string inf = "1+1+1+1";
    ArExpression ex(inf, ARRAY_STACK);
    ex.GetVariable();
    double res = ex.Calculate();
    EXPECT_EQ(4, res);
}
TEST(test_postfix, can_create_postfix_on_list_stack)
{
    using namespace posfix_form;
    std::string inf="A+B-C/F*D";    
    ASSERT_NO_THROW(ArExpression ex(inf, LIST_STACK));
}

TEST(test_postfix, can_define_a_constant_on_list_stack)
{
    using namespace posfix_form;
    std::string inf = "1+1+1+1";
    ArExpression ex(inf, LIST_STACK);
    ASSERT_NO_THROW(ex.GetVariable());
}

TEST(test_postfix, can_calculate_on_list_stack)
{
    using namespace posfix_form;
    std::string inf = "1+1+1+1";
    ArExpression ex(inf, LIST_STACK);
    ex.GetVariable();
    double res;
    ASSERT_NO_THROW(res = ex.Calculate());
}
TEST(test_postfix, correct_calculate_on_list_stack)
{
    using namespace posfix_form;
    std::string inf = "1+1+1+1";
    ArExpression ex(inf, LIST_STACK);
    ex.GetVariable();
    double res = ex.Calculate();
    EXPECT_EQ(4,res);
}