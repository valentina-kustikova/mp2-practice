#include "tpolynom.h"

#include <gtest.h>

TEST(TPolynom, can_create_empty_polynom)
{
	ASSERT_NO_THROW(TPolynom pl());
}


TEST(TPolynom, can_create_polynom_from_string_1)
{
	string a = "1";
	ASSERT_NO_THROW(TPolynom pl(a));
}

TEST(TPolynom, check_correct_create_polynom_from_string_1)
{
	string a = "1";
	TPolynom pl(a);
	EXPECT_EQ(pl.GetCurrent()->data.st, 0);
	EXPECT_EQ(pl.GetCurrent()->data.koef, 1);
}


TEST(TPolynom, can_create_polynom_from_string_2)
{
	string a = "1+x^2-y^3+x*y*z-x^2*y*z^2";
	ASSERT_NO_THROW(TPolynom pl(a));
}

TEST(TPolynom, check_correct_create_polynom_from_string_2)
{
	string a = "1+ x^2 -y^3 + x*y*z - x^2*y*z^2";
	TPolynom pl(a);
	EXPECT_EQ(pl.GetCurrent()->data.st, 0);
	EXPECT_EQ(pl.GetCurrent()->data.koef, 1);

	EXPECT_EQ(pl.GetCurrent()->pNext->data.st, 30);
	EXPECT_EQ(pl.GetCurrent()->pNext->data.koef, -1);
}


TEST(TPolynom, can_create_polynom_from_string_3)
{
	string a = "1+x^2*y*z^9-y^3+x*y*z-x^2*y*z^2";
	ASSERT_NO_THROW(TPolynom pl(a));
}

TEST(TPolynom, check_correct_create_polynom_from_string_3)
{
	string a = "1+x^2*y*z^9-y^3+x*y*z-x^2*y*z^2";
	TPolynom pl(a);
	EXPECT_EQ(pl.GetCurrent()->data.st, 0);
	EXPECT_EQ(pl.GetCurrent()->pNext->data.st, 30);
}


TEST(TPolynom, can_create_polynom_from_ringlist_1)
{
	TNode<TMonom>* c = new TNode<TMonom>(TMonom(111, 2.0), nullptr);
	TNode<TMonom>* b = new TNode<TMonom>(TMonom(11, 2.0), c);
	TNode<TMonom>* a = new TNode<TMonom>(TMonom(1, 2.0), b);

	TRingList<TMonom>* rl = new TRingList<TMonom>(a);

	ASSERT_NO_THROW(TPolynom pl(rl));
}


TEST(TPolynom,check_correct_create_polynom_from_ringlist_1)
{
	TNode<TMonom>* c = new TNode<TMonom>(TMonom(111, 2.0), nullptr);
	TNode<TMonom>* b = new TNode<TMonom>(TMonom(11, 2.0), c);
	TNode<TMonom>* a = new TNode<TMonom>(TMonom(1, 2.0), b);

	TRingList<TMonom>* rl = new TRingList<TMonom>(a);

	TPolynom pl(rl);

	EXPECT_EQ(pl.GetString(), "2.000000*z+2.000000*y*z+2.000000*x*y*z");

}