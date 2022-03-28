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

TEST(TPolinom, can_compare_polinom)
{
	std::string str = "2x2y2z1 + 2x3y2z2";
	std::string str2 = "2x2y2z1 + 2x3y2z2";
	TPolinom P;
	P.Input(str);
	P.StrToList();
	TPolinom Q;
	Q.Input(str2);
	Q.StrToList();
	ASSERT_TRUE(Q == P);
}

TEST(TPolinom, can_input_polinom)
{
	std::string str = "-16x2y5z4 + 100x3y6z2";
	TPolinom P;
	P.Input(str);
	std::vector<std::string> buff = P.LookPolinom();
	std::vector<std::string> buff2 = {"-", "16", "x", "2", "y", "5", "z", "4", "+", "100", "x", "3", "y", "6", "z", "2"};
	int k = buff.size();
	int m = buff2.size();
	ASSERT_TRUE(m = k);
}

TEST(TPolinom, can_similars)
{
	std::string str = "-16x2y5z4 + 100x3y6z2 - 23x2y5z4 + 16x2y5z4 + 100x3y6z2 - 23x2y5z4";
	std::string str2 = "-46x2y5z4 + 200x3y6z2";
	TPolinom P;
	TPolinom Q;
	P.Input(str);
	P.StrToList();
	P.Similar();
	Q.Input(str2);
	Q.StrToList();
	ASSERT_TRUE(Q == P);
}

TEST(TPolinom, can_add_polinom)
{
	std::string str = "-16x2y5z4 + 100x3y6z2";
	std::string str2 = "6x2y2z2 + 6x3y3z3";
	std::string str3 = "-16x2y5z4 + 100x3y6z2 + 6x2y2z2 + 6x3y3z3";
	TPolinom P;
	P.Input(str);
	P.StrToList();
	TPolinom Q;
	Q.Input(str2);
	Q.StrToList();
	TPolinom C;
	C.Input(str3);
	C.StrToList();
	ASSERT_TRUE(C == P + Q);
}

TEST(TPolinom, can_substruct_polinom)
{
	std::string str = "-16x2y5z4 + 100x3y6z2";
	std::string str2 = "6x2y2z2 + 6x3y3z3";
	std::string str3 = "-16x2y5z4 + 100x3y6z2 - 6x2y2z2 - 6x3y3z3";
	TPolinom P;
	P.Input(str);
	P.StrToList();
	TPolinom Q;
	Q.Input(str2);
	Q.StrToList();
	TPolinom C;
	C.Input(str3);
	C.StrToList();
	ASSERT_TRUE(C == P - Q);
}

TEST(TPolinom, can_multiply_polinom)
{
	std::string str = "2x2y2z1 + 2x3y2z2";
	std::string str2 = "2x3y2z1 + 2x3y3z1";
	std::string str3 = "4x6y4z1 + 4x9y4z2 + 4x6y6z1 + 4x9y6z2";
	TPolinom P;
	P.Input(str);
	P.StrToList();
	TPolinom Q;
	Q.Input(str2);
	Q.StrToList();
	TPolinom C;
	C.Input(str3);
	C.StrToList();
	ASSERT_TRUE(C == P * Q);
}

TEST(TPolinom, can_multiply_on_const)
{
	std::string str = "2x2y2z1 + 2x3y2z2";
	std::string str2 = "4x2y2z1 + 4x3y2z2";
	double a = 2;
	TPolinom P;
	P.Input(str);
	P.StrToList();
	TPolinom Q;
	Q.Input(str2);
	Q.StrToList();
	ASSERT_TRUE(Q == P*2);
}

TEST(TPolinom, can_count_result_with_input_values)
{
	std::string str = "2x2y2z1 + 2x3y2z2";
	double res = 4;
	TPolinom P;
	P.Input(str);
	P.StrToList();
	ASSERT_TRUE(4 == P.Values(1, 1, 1));
}