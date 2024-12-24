#include "postfix_form.h"

#include <gtest.h>



TEST(ArrayStack, postfixform_counts_correctly_testcase1)
{
    unordered_map<string, double> values;
    values["A"] = 5;
    values["B"] = 3;
    values["C"] = 7;
    string s = "A+B-C";
    ArithmeticExpression expr(s, ARRAY_STACK);
    double res = expr.compute(values);
    EXPECT_EQ(1, res);
}

TEST(ArrayStack, postfixform_counts_correctly_testcase2)
{
    unordered_map<string, double> values;
    values["A"] = 12;
    values["B"] = 3;
    values["C"] = 2;
    string s = "A-B*C-C";
    ArithmeticExpression expr(s, ARRAY_STACK);
    double res = expr.compute(values);
    EXPECT_EQ(4, res);
}

TEST(ArrayStack, postfixform_counts_correctly_testcase3)
{
    unordered_map<string, double> values;
    values["A"] = 12;
    values["B"] = 3;
    values["C"] = 2;
    string s = "A-B*C-C*(A-B)/C";
    ArithmeticExpression expr(s, ARRAY_STACK);
    double res = expr.compute(values);

    EXPECT_EQ(-3, res);
}

TEST(ArrayStack, postfixform_counts_correctly_testcase4)
{
    unordered_map<string, double> values;
    values["A"] = 12;
    values["B"] = 3;
    values["C"] = 2;
    string s = "(A-B*C)/B";
    ArithmeticExpression expr(s, ARRAY_STACK);
    double res = expr.compute(values);
    EXPECT_EQ(2, res);
}

TEST(ArrayStack, postfixform_counts_correctly_testcase5)
{
    unordered_map<string, double> values;
    values["A"] = 2;
    values["B"] = 5;
    values["C"] = 1;
    values["D"] = 8;
    values["F"] = 3;
    string s = "(A-(B-C))*(D-A)*F-(B-D)/F";
    ArithmeticExpression expr(s, ARRAY_STACK);
    double res = expr.compute(values);
    EXPECT_EQ(-35, res);
}

TEST(ArrayStack, postfixform_counts_correctly_testcase6)
{
    unordered_map<string, double> values;
    values["A"] = 2;
    values["B"] = 6;
    values["C"] = 4;
    values["D"] = 2;
    values["F"] = 4;
    string s = "(A+B)/C-(D*(A+B))/F";
    ArithmeticExpression expr(s, ARRAY_STACK);
    double res = expr.compute(values);
    cout << "\n\n\n\n\n" << res << "\n\n\n\n\n";
    EXPECT_EQ(-2, res);
}

