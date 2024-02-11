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
TEST(TPostfix, incorrect_example1)
{
	string str = "(1+2*)";
	ASSERT_ANY_THROW(TPostfix a(str));
}
//	(*
TEST(TPostfix, incorrect_example2)
{
	string str = "(*1+2)";
	ASSERT_ANY_THROW(TPostfix a(str));
}

//	(/
TEST(TPostfix, incorrect_example3)
{
	string str = "(/1+2)";
	ASSERT_ANY_THROW(TPostfix a(str));
}
//	/(
TEST(TPostfix, incorrect_example4)
{
	string str = "(1+2/)";
	ASSERT_ANY_THROW(TPostfix a(str));
} 
//	(+
TEST(TPostfix, incorrect_example5)
{
	string str = "(+1+2)";
	ASSERT_ANY_THROW(TPostfix a(str));
}
//	+(
TEST(TPostfix, incorrect_example6)
{
	string str = "(1+2+)";
	ASSERT_ANY_THROW(TPostfix a(str));
}
//	(-
TEST(TPostfix, incorrect_example7)
{
	string str = "(-1+2)";
	ASSERT_ANY_THROW(TPostfix a(str));
}
//	-(
TEST(TPostfix, incorrect_example8)
{
	string str = "(1+2-)";
	ASSERT_ANY_THROW(TPostfix a(str));
}
// ..
TEST(TPostfix, incorrect_example9)
{
	string str = "(1+2..2)";
	ASSERT_ANY_THROW(TPostfix a(str));
}
// (()
TEST(TPostfix, incorrect_example10)
{
	string str = "((1+2)";
	ASSERT_ANY_THROW(TPostfix a(str));
}
// ())
TEST(TPostfix, incorrect_example11)
{
	string str = "(1+2))";
	ASSERT_ANY_THROW(TPostfix a(str));
}
// 2.a
TEST(TPostfix, incorrect_example12)
{
	string str = "(1+2.a)";
	ASSERT_ANY_THROW(TPostfix a(str));
}
// 2a
TEST(TPostfix, incorrect_example13)
{
	string str = "(1+2a)";
	ASSERT_ANY_THROW(TPostfix a(str));
}
// a2
TEST(TPostfix, incorrect_example14)
{
	string str = "(1+a2)";
	ASSERT_ANY_THROW(TPostfix a(str));
}
// ++
TEST(TPostfix, incorrect_example15)
{
	string str = "(1++2)";
	ASSERT_ANY_THROW(TPostfix a(str));
}
// --
TEST(TPostfix, incorrect_example16)
{
	string str = "(1--2)";
	ASSERT_ANY_THROW(TPostfix a(str));
}
// **
TEST(TPostfix, incorrect_example17)
{
	string str = "(1**2)";
	ASSERT_ANY_THROW(TPostfix a(str));
}
// //
TEST(TPostfix, incorrect_example18)
{
	string str = "(1//2)";
	ASSERT_ANY_THROW(TPostfix a(str));
}

TEST(TPostfix, correctly_calculate)
{
	string str = "3 + (1 - 2) * (2) - 2 / (0.5 + 0.5)";
	TPostfix a(str);
	int b = 3 + (1 - 2) * (2) - 2 / (0.5 + 0.5);
	EXPECT_EQ(b, a.Calculate());
}