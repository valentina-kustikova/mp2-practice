#include "postfix_form.h"
#include <gtest.h>

TEST(postfixtest, postfixform_write_correct)
{
    AriExpress<char> expr("a+b*(c-a)");
    EXPECT_EQ(expr.get_postfix(), "abca-*+");
}

TEST(postfixtest, postfixform_count_correct)
{
    AriExpress<char> expr("a+b*(c-a)");
    vector<char> operands = expr.getoperands();
    std::map<char, double> values = { {'a',3},{'b',5},{'c',7} };
    ASSERT_EQ(expr.calculate(values), 23);
}
TEST(postfixtest, postfixform_count_minus_correct)
{
    AriExpress<int> expr("a+b");
    std::map<char, double> values = { {'a',-2},{'b',3} };
    ASSERT_EQ(expr.calculate(values), 1);
}


