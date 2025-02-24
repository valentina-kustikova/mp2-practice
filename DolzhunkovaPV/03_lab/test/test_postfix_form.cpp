#include "postfix_form.h"
#include <gtest.h>

TEST(test_postfix_form, transform_add)
{
    std::string infix = "A+B";
    auto postfix = Postfix(infix, stack_type::array);
	EXPECT_EQ("AB+", postfix.Get());
}

TEST(test_postfix_form, transform_subtraction)
{
    std::string infix = "A-B";
    auto postfix = Postfix(infix, stack_type::list);
	EXPECT_EQ("AB-", postfix.Get());
}

TEST(test_postfix_form, transform_multiplication)
{
    std::string infix = "A-B";
    auto postfix = Postfix(infix, stack_type::array);
	EXPECT_EQ("AB-", postfix.Get());
}

TEST(test_postfix_form, transform_division)
{
    std::string infix = "A-B";
    auto postfix = Postfix(infix, stack_type::list);
	EXPECT_EQ("AB-", postfix.Get());
}

TEST(test_postfix_form, calculate_add)
{
    std::string infix = "1+1";
    auto postfix = Postfix(infix, stack_type::array);
	EXPECT_EQ(2, postfix.Calculate());
}

TEST(test_postfix_form, calculate_subtraction)
{
    std::string infix = "2-1";
    auto postfix = Postfix(infix, stack_type::list);
	EXPECT_EQ(1, postfix.Calculate());
}

TEST(test_postfix_form, calculate_multiplication)
{
    std::string infix = "2*3";
    auto postfix = Postfix(infix, stack_type::array);
	EXPECT_EQ(6, postfix.Calculate());
}

TEST(test_postfix_form, calculate_division)
{
    std::string infix = "4/2";
    auto postfix = Postfix(infix, stack_type::list);
	EXPECT_EQ(2, postfix.Calculate());
}

TEST(test_postfix_form, calculate_operands_add)
{
    std::string infix = "A+B";
    auto postfix = Postfix(infix, stack_type::array);

    std::unordered_map<std::string, int> operands = {
        {"A", 1},
        {"B", 2},
    };

	EXPECT_EQ(3, postfix.Calculate(operands));
}

TEST(test_postfix_form, calculate_operands_subtraction)
{
    std::string infix = "A-B";
    auto postfix = Postfix(infix, stack_type::list);

    std::unordered_map<std::string, int> operands = {
        {"A", 2},
        {"B", 1},
    };

	EXPECT_EQ(1, postfix.Calculate(operands));
}

TEST(test_postfix_form, calculate_operands_multiplication)
{
    std::string infix = "A*B";
    auto postfix = Postfix(infix, stack_type::array);

    std::unordered_map<std::string, int> operands = {
        {"A", 4},
        {"B", 2},
    };

	EXPECT_EQ(8, postfix.Calculate(operands));
}

TEST(test_postfix_form, calculate_operands_division)
{
    std::string infix = "A/B";
    auto postfix = Postfix(infix, stack_type::list);

    std::unordered_map<std::string, int> operands = {
        {"A", 6},
        {"B", 2},
    };

	EXPECT_EQ(3, postfix.Calculate(operands));
}

TEST(test_postfix_form, calculate_operands_add_subtraction)
{
    std::string infix = "A+B-C";
    auto postfix = Postfix(infix, stack_type::array);

    std::unordered_map<std::string, int> operands = {
        {"A", 1},
        {"B", 2},
        {"C", 3},
    };

	EXPECT_EQ(0, postfix.Calculate(operands));
}

TEST(test_postfix_form, calculate_operands_add_subtraction_multiplication)
{
    std::string infix = "(A+B)-C*D";
    auto postfix = Postfix(infix, stack_type::list);

    std::unordered_map<std::string, int> operands = {
        {"A", 2},
        {"B", 2},
        {"C", 2},
        {"D", 2},
    };

	EXPECT_EQ(0, postfix.Calculate(operands));
}

TEST(test_postfix_form, calculate_operands_add_subtraction_multiplication_division)
{
    std::string infix = "(A+B-C)*D/X";
    auto postfix = Postfix(infix, stack_type::array);

    std::unordered_map<std::string, int> operands = {
        {"A", 2},
        {"B", 2},
        {"C", 2},
        {"D", 4},
        {"X", 2},
    };

	EXPECT_EQ(4, postfix.Calculate(operands));
}

TEST(test_postfix_form, transofrm_order1)
{
    std::string infix    = "A*B-A/C";
    std::string expected = "AB*AC/-";

    auto postfix = Postfix(infix, stack_type::list);

	EXPECT_EQ(expected, postfix.Get());
}

TEST(test_postfix_form, transofrm_order2)
{
    std::string infix    = "A+B+C+D+E+F+G";
    std::string expected = "AB+C+D+E+F+G+";

    auto postfix = Postfix(infix, stack_type::array);

	EXPECT_EQ(expected, postfix.Get());
}

TEST(test_postfix_form, transofrm_order3)
{
    std::string infix    = "F-(A-((B+C))+D)";
    std::string expected = "FABC+-D+-";

    auto postfix = Postfix(infix, stack_type::list);

	EXPECT_EQ(expected, postfix.Get());
}

TEST(test_postfix_form, transofrm_order4)
{
    std::string infix    = "(A+A-C)*B/(B*C)";
    std::string expected = "AA+C-B*BC*/";

    auto postfix = Postfix(infix, stack_type::array);

	EXPECT_EQ(expected, postfix.Get());
}
