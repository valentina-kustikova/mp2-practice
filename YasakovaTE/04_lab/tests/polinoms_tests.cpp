#include "polinom.h"
#include <gtest.h>

TEST(TPolinom, create_polinom)
{
	ASSERT_NO_THROW(TPolinom p1(""));
}

TEST(TPolinom, empty_polinom_equal)
{
	TPolinom p1("");
	TPolinom p2("");
	EXPECT_EQ(p1, p2);
}

TEST(TPolinom, Build_Pol)
{
	ASSERT_NO_THROW(TPolinom p1("4x^2y"));
}

TEST(TPolinom, create_polinom_after_existing)
{
	TPolinom p1("x^5z");
	ASSERT_NO_THROW(TPolinom p2(p1));
}

TEST(TPolinom, correct_sum_polinom_one)
{
	TPolinom p1("3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z");
	TPolinom p2("4x^3y^2z^6-6x^2yz^8");
	TPolinom sum("3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z+4x^3y^2z^6-6x^2yz^8");
	EXPECT_EQ(sum, p1 + p2);
}

TEST(TPolinom, correct_sum_polinom_two)
{
	TPolinom p1("3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z");
	TPolinom p2("4x^7y^2z^6-6x^6yz^8");
	TPolinom sum("4x^7y^2z^6-6x^6yz^8+3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z");
	EXPECT_EQ(sum, p1 + p2);
}

TEST(TPolinom, correct_sum_polinom_three)
{
	TPolinom p1("3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z");
	TPolinom p2("4x^5y^2z^5+5x^4y^3z^3");
	TPolinom sum("7x^5y^2z^5+7x^3y^5z");
	EXPECT_EQ(sum, p1 + p2);
}

TEST(TPolinom, correct_sum_polinom_four)
{
	TPolinom p1("3x^5y^2z^5-5x^4y^3z^3+7x^7y^5z");
	TPolinom p2("4x^6y^2z^6-5x^2y^1z^8");
	TPolinom sum("7x^7y^5z+4x^6y^2z^6+3x^5y^2z^5-5x^4y^3z^3-6x^2yz^8");
	EXPECT_EQ(sum, p1 + p2);
}

TEST(TPolinom, correct_sum_polinom_five)
{
	TPolinom p1("3x^5y^2z^5-5x^4y^3z^3+7x^7y^5z");
	TPolinom p2("-3x^5y^2z^5+5x^4y^3z^3-7x^7y^5z");
	TPolinom sum("");
	EXPECT_EQ(sum, p1 + p2);
}

TEST(TPolinom, multiply_polinom_one)
{
	TPolinom p1("x^2yz");
	TPolinom p2("y^5z^7");
	ASSERT_NO_THROW(p1 * p2);
}
TEST(TPolinom, multiply_polinom_two)
{
	TPolinom p1("10xy^2+x^7y^5z^3");
	TPolinom p2("11x^2");
	ASSERT_NO_THROW(p1 * p2);
}

TEST(TPolinom, correct_multiply_polinom_one)
{
	TPolinom p1("3x^2");
	TPolinom p2("5y^2");
	TPolinom mul("15x^2y^2");
	EXPECT_EQ(mul, p1 * p2);
}
TEST(TPolinom, correct_multiply_polinom_two)
{
	TPolinom p1("2x+1");
	TPolinom p2("4x-3");
	TPolinom mul("8x^2-2x-3");
	EXPECT_EQ(mul, p1 * p2);
}

TEST(TPolinom, error_multiply_degree_more_10)
{
	TPolinom p1("3x^4");
	TPolinom p2("x^8");
	ASSERT_ANY_THROW(p1 * p2);
}

TEST(TPolinom, multiply_polinom_on_number_one)
{
	TPolinom p1("x^2y^2z^2");
	double b1 = 22.7;
	ASSERT_NO_THROW(p1 * b1);
}
TEST(TPolinom, multiply_polinom_on_number_two)
{
	TPolinom p1("x^2yz");
	double b1 = 13.3;
	ASSERT_NO_THROW(b1 * p1);
}

TEST(TPolinom, correct_multiply_polinom_on_number)
{
	TPolinom p1("100x^3");
	double b1 = 13.5;
	TPolinom mul("1350x^3");
	EXPECT_EQ(mul, p1 * b1);
}
