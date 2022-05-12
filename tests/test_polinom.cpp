#include <gtest.h>
#include "polynom.h"

//тесты из методички------------------------------------------------
TEST(Polynom, from_book_1)
{
    Polynom P("3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z");
    Polynom Q("4x^3y^2z^6-6x^2yz^8");
    Polynom S("3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z+4x^3y^2z^6-6x^2yz^8");
    EXPECT_EQ(S, P + Q);
}

TEST(Polynom, from_book_2)
{
    Polynom P("3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z");
    Polynom Q("4x^7y^2z^6-6x^6yz^8");
    Polynom S("4x^7y^2z^6-6x^6yz^8+3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z");
    EXPECT_EQ(S, P + Q);
}

TEST(Polynom, from_book_3)
{
    Polynom P("3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z");
    Polynom Q("4x^5y^2z^5+5x^4y^3z^3");
    Polynom S("7x^5y^2z^5+7x^3y^5z");
    EXPECT_EQ(S, P + Q);
}

TEST(Polynom, from_book_4)
{
    Polynom P("3x^5y^2z^5-5x^4y^3z^3+7x^7y^5z");
    Polynom Q("4x^6y^2z^6-6x^2yz^8");
    Polynom S("7x^7y^5z+4x^6y^2z^6+3x^5y^2z^5-5x^4y^3z^3-6x^2yz^8");
    EXPECT_EQ(S, P + Q);
}

TEST(Polynom, from_book_5)
{
    Polynom P("3x^5y^2z^5-5x^4y^3z^3+7x^7y^5z");
    Polynom Q("-3x^5y^2z^5+5x^4y^3z^3-7x^7y^5z");
    Polynom S("0");
    EXPECT_EQ(S, P + Q);
}
//----------------------------------------------------------------------

TEST(Polynom, can_create_polynom)
{
    ASSERT_NO_THROW(Polynom p);
}

TEST(Polynom, can_create_polynom_from_string)
{
    string s = "x+y+2z";
    ASSERT_NO_THROW(Polynom p(s));
}

TEST(Polynom, can_copy_polynom)
{
    Polynom p;
    ASSERT_NO_THROW(Polynom m(p));
}

TEST(Polynom, build_polynom)
{
    ASSERT_NO_THROW(Polynom p("x+1"));
}

TEST(Polynom, degree_no_more_than_9_1)
{
    Polynom p("x^5");
    Polynom q("x^4");
    ASSERT_NO_THROW(p * q);
}

TEST(Polynom, degree_no_more_than_9_2)
{
    Polynom p("x^5");
    Polynom q("x^5");
    ASSERT_ANY_THROW(p * q);
}

TEST(Polynom, addition_1)
{
    Polynom p("x+y");
    Polynom q("x+y");
    Polynom s("2x+2y");
    EXPECT_EQ(s, p + q);
}

TEST(Polynom, addition_2)
{
    Polynom p("3x^2");
    Polynom q("4x^7");
    Polynom s("3x^2+4x^7");
    EXPECT_EQ(s, p + q);
}

TEST(Polynom, addition_3)
{
    Polynom p("x+y+z");
    Polynom q("x-2y+z^2");
    Polynom s("2x-y+z+z^2");
    EXPECT_EQ(s, p + q);
}

TEST(Polynom, subtraction_1)
{
    Polynom p("x^3+5");
    Polynom q("x^2-4");
    Polynom s("-x^2+x^3+9");
    EXPECT_EQ(s, p - q);
}

TEST(Polynom, subtraction_2)
{
    Polynom p("x+y+z");
    Polynom q("y");
    Polynom s("x+z");
    EXPECT_EQ(s, p - q);
}

TEST(Polynom, subtraction_3)
{
    Polynom p("x+2y");
    Polynom q("x-z");
    Polynom s("z+2y");
    EXPECT_EQ(s, p - q);
}

TEST(Polynom, polynomial_multiplication_1)
{
    Polynom p("x+1");
    Polynom q("x-1");
    Polynom s("x^2-1");
    EXPECT_EQ(s, p * q);
}

TEST(Polynom, polynomial_multiplication_2)
{
    Polynom p("x^3");
    Polynom q("y^4");
    Polynom s("x^3y^4");
    EXPECT_EQ(s, p * q);
}

TEST(Polynom, polynomial_multiplication_3)
{
    Polynom p("15x^2");
    Polynom q("10x^2+14y^2");
    Polynom s("150x^4+210x^2y^2");
    EXPECT_EQ(s, p * q);
}

TEST(Polynom, multiplication_polynom_and_const_1)
{
    Polynom p("x^2");
    double d = 10.0;
    Polynom s("10.0x^2");
    EXPECT_EQ(s, p * d);
}

TEST(Polynom, multiplication_polynom_and_const_2)
{
    Polynom p("x^2+y^2");
    double d = 10.0;
    Polynom s("10.0x^2+10.0y^2");
    EXPECT_EQ(s, p * d);
}

TEST(Polynom, multiplication_polynom_and_const_3)
{
    Polynom p("2x^2+y-z");
    double d = 5.5;
    Polynom s("11x^2+5.5y-5.5z");
    EXPECT_EQ(s, p * d);
}