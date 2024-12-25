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
TEST(test_postfix, correct_create_postfix_on_arr_stack)
{
    using namespace posfix_form;
    std::map <std::string, double> var = { {"A",1},{"B",3},{"C",2},{"K",-2} };
    std::string inf = "(A-B)/(C-A)*(K+B)+A";
    ArExpression ex(inf, ARRAY_STACK);
    std::string postfix = ex.GetPostfix();
    EXPECT_EQ("A B - C A - / K B + * A + ", postfix);
}

TEST(test_postfix, can_calculate_on_arr_stack)
{
    using namespace posfix_form;
    std::map <std::string, double> var = { {"A",1},{"B",3},{"C",2},{"K",-2} };
    std::string inf = "(A-B)/(C-A)*(K+B)+A";
    ArExpression ex(inf, ARRAY_STACK);
    ex.GetVariable(var);
    double res;
    ASSERT_NO_THROW(res = ex.Calculate());
}
TEST(test_postfix, correct_calculate_on_arr_stack)
{
    using namespace posfix_form;
    std::map <std::string, double> var = { {"A",1},{"B",3},{"C",2},{"K",-2} };
    std::string inf = "(A-B)/(C-A)*(K+B)+A";
    ArExpression ex(inf, ARRAY_STACK);
    ex.GetVariable(var);
    double res = ex.Calculate();
    EXPECT_EQ(-1, res);
}
TEST(test_postfix, correct_create_postfix_on_arr_stack_2)
{
    using namespace posfix_form;
    std::map <std::string, double> var = { {"A",1},{"B",2},{"C",3} };
    std::string inf = "A-B*(A+C)";
    ArExpression ex(inf, ARRAY_STACK);
    std::string postfix = ex.GetPostfix();
    EXPECT_EQ("A B A C + * - ", postfix);
}

TEST(test_postfix, correct_calculate_on_arr_stack_2)
{
    using namespace posfix_form;
    std::map <std::string, double> var = { {"A",1},{"B",2},{"C",3} };
    std::string inf = "A-B*(A+C)";
    ArExpression ex(inf, ARRAY_STACK);
    ex.GetVariable(var);
    double res = ex.Calculate();
    EXPECT_EQ(-7, res);
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
TEST(test_postfix, correct_create_postfix_on_list_stack)
{
    using namespace posfix_form;
    std::map <std::string, double> var = { {"A",1},{"B",3},{"C",2},{"K",-2} };
    std::string inf = "(A-B)/(C-A)*(K+B)+A";
    ArExpression ex(inf, ARRAY_STACK);
    std::string postfix = ex.GetPostfix();
    EXPECT_EQ("A B - C A - / K B + * A + ", postfix);
}

TEST(test_postfix, can_calculate_on_list_stack)
{
    using namespace posfix_form;
    std::map <std::string, double> var = { {"A",1},{"B",3},{"C",2},{"K",-2} };
    std::string inf = "(A-B)/(C-A)*(K+B)+A";
    ArExpression ex(inf, ARRAY_STACK);
    ex.GetVariable(var);
    double res;
    ASSERT_NO_THROW(res = ex.Calculate());
}
TEST(test_postfix, correct_calculate_on_list_stack)
{
    using namespace posfix_form;
    std::map <std::string, double> var = { {"A",1},{"B",3},{"C",2},{"K",-2} };
    std::string inf = "(A-B)/(C-A)*(K+B)+A";
    ArExpression ex(inf, ARRAY_STACK);
    ex.GetVariable(var);
    double res = ex.Calculate();
    EXPECT_EQ(-1, res);
}
TEST(test_postfix, correct_create_postfix_on_list_stack_2)
{
    using namespace posfix_form;
    std::map <std::string, double> var = { {"A",1},{"B",2},{"C",3} };
    std::string inf = "A-B*(A+C)";
    ArExpression ex(inf, ARRAY_STACK);
    std::string postfix = ex.GetPostfix();
    EXPECT_EQ("A B A C + * - ", postfix);
}

TEST(test_postfix, correct_calculate_on_list_stack_2)
{
    using namespace posfix_form;
    std::map <std::string, double> var = { {"A",1},{"B",2},{"C",3} };
    std::string inf = "A-B*(A+C)";
    ArExpression ex(inf, ARRAY_STACK);
    ex.GetVariable(var);
    double res = ex.Calculate();
    EXPECT_EQ(-7, res);
}