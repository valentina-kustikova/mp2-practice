#include <gtest.h>
#include "polinom.h"

TEST(TPolinom, CanCreateNewPolinom)
{
    ASSERT_NO_THROW(TPolinom t);
}

TEST(TPolinom, CanCreateStringPolinom)
{
    ASSERT_NO_THROW(TPolinom t("3x4y5z6+2x4y5z6+xyz"));
}

TEST(TPolinom, CanCreateCopiedPolynom)
{
    TPolinom t;
    ASSERT_NO_THROW(TPolinom t2(t));
}

TEST(TPolinom, CanCreateCopiedPolinom2)
{
    TPolinom p1("x+y+z");
    ASSERT_NO_THROW(TPolinom t(p1));
}

TEST(TPolinom, CanAssignPolynoms)
{
    TPolinom t1("2x");

    TPolinom t2;

    ASSERT_NO_THROW(t2 = t1);
    EXPECT_EQ(t1, t2);
}

TEST(TPolinom, CanAssignPolynomToItself)
{
    TPolinom t("2x");

    ASSERT_NO_THROW(t = t);
    EXPECT_EQ(t, t);
}

TEST(TPolinom, BringingSort)
{
    TPolinom t("xyz+3x2y2z2+2x4y5z6+3x4y5z6");

    TPolinom t1("5x4y5z6+3x2y2z2+xyz");


    EXPECT_EQ(t1, t);
}

TEST(TPolinom, SUMTEST1)
{
    TPolinom p1("3x5y2z5-5x4y3z3+7x3y5z");
    TPolinom p2("4x3y2z6-6x2yz8");
    TPolinom p3(p1 + p2);
    TPolinom p4("3x5y2z5-5x4y3z3+7x3y5z+4x3y2z6-6x2yz8");
    EXPECT_EQ(p4, p3);
}

TEST(TPolinom, SUMTEST2)
{
    TPolinom p1("3x5y2z5-5x4y3z3+7x3y5z");
    TPolinom p2("4x7y2z6-6x6yz8");
    TPolinom p3(p1 + p2);
    TPolinom p4("4x7y2z6-6x6yz8+3x5y2z5-5x4y3z3+7x3y5z");
    EXPECT_EQ(p4, p3);
}

TEST(TPolinom, SUMTEST3)
{
    TPolinom p1("3x5y2z5-5x4y3z3+7x3y5z");
    TPolinom p2("4x5y2z5+5x4y3z3");
    TPolinom p3(p1 + p2);
    TPolinom p4("7x5y2z5+7x3y5z");
    EXPECT_EQ(p4, p3);
}

TEST(TPolinom, SUMTEST4)
{
    TPolinom p1("3x5y2z5-5x4y3z3+7x7y5z");
    TPolinom p2("4x6y2z6-6x2yz8");
    TPolinom p3(p1 + p2);
    TPolinom p4("7x7y5z+4x6y2z6+3x5y2z5-5x4y3z3-6x2yz8");
    EXPECT_EQ(p4, p3);
}

TEST(TPolinom, SUMTEST5)
{
    TPolinom p1("3x5y2z5-5x4y3z3+7x7y5z");
    TPolinom p2("-3x5y2z5+5x4y3z3-7x7y5z");
    TPolinom p3(p1 + p2);
    TPolinom p4("0");
    EXPECT_EQ(p4, p3);
}

TEST(TPolinom, MultiplicationTest)
{
    TPolinom p1("4x3y4z2-xyz+16");
    TPolinom p2("16x4y4z4-2xy2z6+9");
    TPolinom p3(p1 * p2);
    TPolinom p4("64x7y8z6-8x4y6z8+36x3y4z2-16x5y5z5+2x2y3z7-9xyz+256x4y4z4-32xy2z6+144");
    EXPECT_EQ(p4, p3);
}

TEST(TPolinom, MultiplicationTest2)
{
    TPolinom p1("xyz+4x2y");
    TPolinom p2("xy+2x");
    TPolinom p3(p1 * p2);
    TPolinom p4("4x3y2+8x3y+x2y2z+2x2yz");
    EXPECT_EQ(p4, p3);
}

TEST(TPolinom, CanMultiplyPolynomByZeroDouble)
{
    TPolinom t("4x3y2+8x3y+x2y2z+2x2yz");

    TPolinom result;
    ASSERT_NO_THROW(result = t * 0);

    EXPECT_EQ(result, TPolinom());
}

TEST(TPolinom, CanMultiplyPolynomByDouble)
{
    TPolinom t("4x3y2+8x3y+x2y2z+2x2yz");
    TPolinom correct("40x3y2+80x3y+10x2y2z+20x2yz");
    TPolinom result;
    ASSERT_NO_THROW(result = t * 10);

    EXPECT_EQ(correct, result);
}

TEST(TPolinom, CanSumPolynomByDouble)
{
    TPolinom t("4x3y2+8x3y+x2y2z+2x2yz");
    TPolinom correct("4x3y2+8x3y+x2y2z+2x2yz+10");
    TPolinom result;
    ASSERT_NO_THROW(result = t + 10);

    EXPECT_EQ(correct, result);
}

TEST(TPolinom, CanSubtractPolynomByDouble)
{
    TPolinom t("4x3y2+8x3y+x2y2z+2x2yz");
    TPolinom correct("4x3y2+8x3y+x2y2z+2x2yz-10");
    TPolinom result;
    ASSERT_NO_THROW(result = t - 10);

    EXPECT_EQ(correct, result);
}

TEST(TPolinom, CanSubtractPolynoms)
{
    TPolinom t("4x3y2+8x3y+x2y2z+2x2yz+10");
    TPolinom t2("16x4y4z4-2xy2z6+9");
    TPolinom correct("-16x4y4z4+4x3y2+8x3y+x2y2z+2x2yz+2xy2z6+1");
    TPolinom result(t - t2);

    EXPECT_EQ(correct, result);
}
