#include "postfix.h" 
#include <gtest.h> 

TEST(TPostfix, can_create_with_correct_example)
{
	string str = "2+2";
	ASSERT_NO_THROW(TPostfix a(str));
}

TEST(TPostfix, cant_create_with_empty_example)
{
	string str = "";
	ASSERT_ANY_THROW(TPostfix a(str));
}

TEST(TPostfix, correcct_example_is_correct)
{
	string str = "1 + (2 - 0.5) * 2 - 3 / (0.5 + 0.5)";
	ASSERT_NO_THROW(TPostfix a(str));
}


//	*)
TEST(TPostfix, incorrect_example_with_const_1)
{
	string str = "(1+2*)";
	ASSERT_ANY_THROW(TPostfix a(str));
}
//	(*
TEST(TPostfix, incorrect_example_with_const_2)
{
	string str = "(*1+2)";
	ASSERT_ANY_THROW(TPostfix a(str));
}

//	(/
TEST(TPostfix, incorrect_example_with_const_3)
{
	string str = "(/1+2)";
	ASSERT_ANY_THROW(TPostfix a(str));
}
//	/(
TEST(TPostfix, incorrect_example_with_const_4)
{
	string str = "(1+2/)";
	ASSERT_ANY_THROW(TPostfix a(str));
} 
//	(+
TEST(TPostfix, incorrect_example_with_const_5)
{
	string str = "(+1+2)";
	ASSERT_ANY_THROW(TPostfix a(str));
}
//	+(
TEST(TPostfix, incorrect_example_with_const_6)
{
	string str = "(1+2+)";
	ASSERT_ANY_THROW(TPostfix a(str));
}
//	(-
TEST(TPostfix, incorrect_example_with_const_7)
{
	string str = "(-1+2)";
	ASSERT_ANY_THROW(TPostfix a(str));
}
//	-(
TEST(TPostfix, incorrect_example_with_const_8)
{
	string str = "(1+2-)";
	ASSERT_ANY_THROW(TPostfix a(str));
}
// ..
TEST(TPostfix, incorrect_example_with_const_9)
{
	string str = "(1+2..2)";
	ASSERT_ANY_THROW(TPostfix a(str));
}
// (()
TEST(TPostfix, incorrect_example_with_const_10)
{
	string str = "((1+2)";
	ASSERT_ANY_THROW(TPostfix a(str));
}
// ())
TEST(TPostfix, incorrect_example_with_const_11)
{
	string str = "(1+2))";
	ASSERT_ANY_THROW(TPostfix a(str));
}
// 2.a
TEST(TPostfix, incorrect_example_with_const_12)
{
	string str = "(1+2.a)";
	ASSERT_ANY_THROW(TPostfix a(str));
}
// 2a
TEST(TPostfix, incorrect_example_with_const_13)
{
	string str = "(1+2a)";
	ASSERT_ANY_THROW(TPostfix a(str));
}
// a2
TEST(TPostfix, incorrect_example_with_const_14)
{
	string str = "(1+a2)";
	ASSERT_ANY_THROW(TPostfix a(str));
}
// ++
TEST(TPostfix, incorrect_example_with_const_15)
{
	string str = "(1++2)";
	ASSERT_ANY_THROW(TPostfix a(str));
}
// --
TEST(TPostfix, incorrect_example_with_const_16)
{
	string str = "(1--2)";
	ASSERT_ANY_THROW(TPostfix a(str));
}
// **
TEST(TPostfix, incorrect_example_with_const_17)
{
	string str = "(1**2)";
	ASSERT_ANY_THROW(TPostfix a(str));
}
// //
TEST(TPostfix, incorrect_example_with_const_18)
{
	string str = "(1//2)";
	ASSERT_ANY_THROW(TPostfix a(str));
}

TEST(TPostfix, correctly_calculate_with_const)
{
	string str = "3 + (1 - 2) * (2) - 2 / (0.5 + 0.5)";
	TPostfix a(str);
	double b = 3 + (1 - 2) * (2) - 2 / (0.5 + 0.5);
	EXPECT_EQ(b, a.Calculate());
}

TEST(TPostfix, correctly_calculate_with_alpha)
{
	string str = "A + (B - C) * D - F / (G + H)";
	TPostfix a(str);
	map<string, double> val = { {"A", 0}, {"B", 1}, {"C", 2}, {"D", -1}, {"F", 2}, {"G", 0.5}, {"H", 0.5} };
	double b = 0 + (1 - 2) * (-1) - 2 / (0.5 + 0.5);
	EXPECT_EQ(a.GetPostfix(), "ABC-D*+FGH+/-");
	EXPECT_EQ(b, a.Calculate(val));
}

TEST(TPostfix, correctly_calculate_with_a_repeat_alpha)
{
	string str = "A + (A - C) * D - F / (A + H)";
	TPostfix a(str);
	map<string, double> val = { {"A", 3}, {"C", 2}, {"D", -1}, {"F", 2}, {"H", 0.5} };
	double b = 3 + (3 - 2) * (-1) - 2 / (3 + 0.5);
	EXPECT_EQ(a.GetPostfix(), "AAC-D*+FAH+/-");
	EXPECT_EQ(b, a.Calculate(val));
}

TEST(TPostfix, division_by_zero)
{
	string str = "1/0";
	ASSERT_NO_THROW(TPostfix a(str));
}

TEST(TPostfix, division_by_zero_1)
{
	string str = "1/0";
	TPostfix a(str);
	ASSERT_ANY_THROW(a.Calculate());
}