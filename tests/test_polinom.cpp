#include <gtest.h>
#include "polinom.h"

//тесты из методички------------------------------------------------
TEST(Polinom, from_book_1)
{
    Polinom P("3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z");
    Polinom Q("4x^3y^2z^6-6x^2yz^8");
    Polinom S("3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z+4x^3y^2z^6-6x^2yz^8");
    EXPECT_EQ(S, P + Q);
}

TEST(Polinom, from_book_2)
{
    Polinom P("3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z");
    Polinom Q("4x^7y^2z^6-6x^6yz^8");
    Polinom S("4x^7y^2z^6-6x^6yz^8+3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z");
    EXPECT_EQ(S, P + Q);
}

TEST(Polinom, from_book_3)
{
    Polinom P("3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z");
    Polinom Q("4x^5y^2z^5+5x^4y^3z^3");
    Polinom S("7x^5y^2z^5+7x^3y^5z");
    EXPECT_EQ(S, P + Q);
}

TEST(Polinom, from_book_4)
{
    Polinom P("3x^5y^2z^5-5x^4y^3z^3+7x^7y^5z");
    Polinom Q("4x^6y^2z^6-6x^2yz^8");
    Polinom S("7x^7y^5z+4x^6y^2z^6+3x^5y^2z^5-5x^4y^3z^3-6x^2yz^8");
    EXPECT_EQ(S, P + Q);
}

TEST(Polinom, from_book_5)
{
    Polinom P("3x^5y^2z^5-5x^4y^3z^3+7x^7y^5z");
    Polinom Q("-3x^5y^2z^5+5x^4y^3z^3-7x^7y^5z");
    Polinom S("0");
    EXPECT_EQ(S, P + Q);
}
//----------------------------------------------------------------------

TEST(Polinom, can_create_polinom)
{
    ASSERT_NO_THROW(Polinom p);
}

TEST(Polinom, can_create_polinom_from_string)
{
    string s = "x+y+2z";
    ASSERT_NO_THROW(Polinom p(s));
}

TEST(Polinom, build_polinom)
{
    ASSERT_NO_THROW(Polinom p("x+1"));
}

TEST(Polinom, degree_no_more_than_9_1)
{
    Polinom p("x^5");
    Polinom q("x^4");
    ASSERT_NO_THROW(p * q);
}

TEST(Polinom, degree_no_more_than_9_2)
{
    Polinom p("x^5");
    Polinom q("x^5");
    ASSERT_ANY_THROW(p * q);
}

TEST(Polinom, addition_1)
{
    Polinom p("x+y");
    Polinom q("x+y");
    Polinom s("2x+2y");
    EXPECT_EQ(s, p + q);
}

TEST(Polinom, addition_2)
{
    Polinom p("3x^2");
    Polinom q("4x^7");
    Polinom s("3x^2+4x^7");
    EXPECT_EQ(s, p + q);
}

TEST(Polinom, addition_3)
{
    Polinom p("x+y+z");
    Polinom q("x-2y+z^2");
    Polinom s("2x-y+z+z^2");
    EXPECT_EQ(s, p + q);
}

TEST(Polinom, subtraction_1)
{
    Polinom p("x^3+5");
    Polinom q("x^2-4");
    Polinom s("-x^2+x^3+9");
    EXPECT_EQ(s, p - q);
}

TEST(Polinom, subtraction_2)
{
    Polinom p("x+y+z");
    Polinom q("y");
    Polinom s("x+z");
    EXPECT_EQ(s, p - q);
}

TEST(Polinom, subtraction_3)
{
    Polinom p("x+2y");
    Polinom q("x-z");
    Polinom s("z+2y");
    EXPECT_EQ(s, p - q);
}

TEST(Polinom, polinomial_multiplication_1)
{
    Polinom p("x+1");
    Polinom q("x-1");
    Polinom s("x^2-1");
    EXPECT_EQ(s, p * q);
}

TEST(Polinom, polinomial_multiplication_2)
{
    Polinom p("x^3");
    Polinom q("y^4");
    Polinom s("x^3y^4");
    EXPECT_EQ(s, p * q);
}

TEST(Polinom, polinomial_multiplication_3)
{
    Polinom p("15x^2");
    Polinom q("10x^2+14y^2");
    Polinom s("150x^4+210x^2y^2");
    EXPECT_EQ(s, p * q);
}

TEST(Polinom, multiplication_polinom_and_const_1)
{
    Polinom p("x^2");
    double d = 10.0;
    Polinom s("10.0x^2");
    EXPECT_EQ(s, p * d);
}

TEST(Polinom, multiplication_polinom_and_const_2)
{
    Polinom p("x^2+y^2");
    double d = 10.0;
    Polinom s("10.0x^2+10.0y^2");
    EXPECT_EQ(s, p * d);
}

TEST(Polinom, multiplication_polinom_and_const_3)
{
    Polinom p("2x^2+y-z");
    double d = 5.5;
    Polinom s("11x^2+5.5y-5.5z");
    EXPECT_EQ(s, p * d);
}