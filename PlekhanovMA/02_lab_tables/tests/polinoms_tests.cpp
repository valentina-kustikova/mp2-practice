#include <gtest.h>
#include "polinom.h"

TEST(TPolinom, can_create_polinom)
{
	TPolinom P;
	ASSERT_NO_THROW();
}

TEST(TPolinom, can_copy_polinom)
{
	TPolinom P;
	TPolinom Q(P);
	ASSERT_NO_THROW();
}

TEST(TPolinom, can_sort_polinom)
{
	std::string str = "-16xy5z4 - 37x3y6z + 20x2y5z4 + 100x3y6z2";
	TPolinom P(str);
	ASSERT_TRUE(1 == 1);
}

TEST(TPolinom, can_sort_polinom2)
{
	std::string str = "-16xy5z4 - 37x3y6z";
	TPolinom P(str);
	ASSERT_TRUE(1 == 1);
}

TEST(TPolinom, can_similars)
{
	std::string str = "-16x2y5z4 + 100x3y6z2 - 23x2y5z4 + 16x2y5z4 + 100x3y6z2 - 23x2y5z4";
	std::string str2 = "-46x2y5z4 + 200x3y6z2";
	TPolinom P(str);
	TPolinom Q(str2);
	ASSERT_TRUE(Q == P);
}

TEST(TPolinom, can_add_polinom)
{
	std::string str = "-16x2y5z4 + 100x3y6z2";
	std::string str2 = "6x2y2z2 + 6x3y3z3";
	std::string str3 = "100x3y6z2 + 6x3y3z3 - 16x2y5z4 + 6x2y2z2";
	TPolinom P(str);
	TPolinom Q(str2);
	TPolinom C(str3);
	ASSERT_TRUE(C == P + Q);
}

TEST(TPolinom, can_substruct_polinom)
{
	std::string str = "-16x2y5z4 + 100x3y6z2";
	std::string str2 = "6x2y2z2 + 6x3y3z3";
	std::string str3 = "100x3y6z2 - 6x3y3z3 - 16x2y5z4 - 6x2y2z2";
	TPolinom P(str);
	TPolinom Q(str2);
	TPolinom C(str3);
	ASSERT_TRUE(C == P - Q);
}

TEST(TPolinom, can_multiply_on_const)
{
	std::string str = "2x2y2z1 + 2x3y2z2";
	std::string str2 = "4x2y2z1 + 4x3y2z2";
	TPolinom P(str);
	TPolinom Q(str2);
	ASSERT_TRUE(Q == P * 2);
}

TEST(TPolinom, can_multiply_polinom)
{
	std::string str = "2x2y2z1 + 2x3y2z2";
	std::string str2 = "2x3y2z1 + 2x3y3z1";
	std::string str3 = "4x6y4z1 + 4x9y4z2 + 4x6y6z1 + 4x9y6z2";
	TPolinom P(str);
	TPolinom Q(str2);
	TPolinom C(str3);
	ASSERT_TRUE(C == P * Q);
}

TEST(TPolinom, can_compare_polinom)
{
	std::string str = "2x2y2z1 + 2x3y2z2";
	std::string str2 = "2x2y2z1 + 2x3y2z2";
	TPolinom P(str);
	TPolinom Q(str2);
	ASSERT_TRUE(Q == P);
}

TEST(TPolinom, can_count_result_with_input_values)
{
	std::string str = "2x2y2z1 + 2x3y2z2";
	double res = 4;
	TPolinom P(str);
	ASSERT_TRUE(4 == P(1, 1, 1));
}

TEST(TPolinom, example_1)
{
	std::string str = "3x5y2z5 - 5x4y3z3 + 7x3y5z";
	std::string str2 = "4x3y2z6 - 6x2yz8";
	std::string str3 = "3x5y2z5 - 5x4y3z3 + 7x3y5z + 4x3y2z6 - 6x2yz8";
	TPolinom P(str);
	TPolinom Q(str2);
	TPolinom C(str3);
	ASSERT_TRUE(C == P + Q);
}

TEST(TPolinom, example_2)
{
	std::string str = "3x5y2z5 - 5x4y3z3 + 7x3y5z";
	std::string str2 = "4x7y2z6 - 6x6yz8";
	std::string str3 = "4x7y2z6 - 6x6yz8 + 3x5y2z5 - 5x4y3z3 + 7x3y5z";
	TPolinom P(str);
	TPolinom Q(str2);
	TPolinom C(str3);
	ASSERT_TRUE(C == P + Q);
}

TEST(TPolinom, example_3)
{
	std::string str = "3x5y2z5 - 5x4y3z3 + 7x3y5z";
	std::string str2 = "4x5y2z5 + 5x4y3z3";
	std::string str3 = "7x5y2z5 + 7x3y5z";
	TPolinom P(str);
	TPolinom Q(str2);
	TPolinom C(str3);
	ASSERT_TRUE(C == P + Q);
}

TEST(TPolinom, example_4)
{
	std::string str = "3x5y2z5 - 5x4y3z3 + 7x7y5z";
	std::string str2 = "4x6y2z6 - 6x2yz8";
	std::string str3 = "7x7y5z + 4x6y2z6 + 3x5y2z5 - 5x4y3z3 - 6x2yz8";
	TPolinom P(str);
	TPolinom Q(str2);
	TPolinom C(str3);
	ASSERT_TRUE(C == P + Q);
}

TEST(TPolinom, example_5)
{
	std::string str = "3x5y2z5 - 5x4y3z3 + 7x7y5z";
	std::string str2 = "-3x5y2z5 + 5x4y3z3 - 7x7y5z";
	TPolinom P(str);
	TPolinom Q(str2);
	TPolinom C;
	C = P + Q;
	int a = C.Check();
	ASSERT_TRUE(a == 1);
}