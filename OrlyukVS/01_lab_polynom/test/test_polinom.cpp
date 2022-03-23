#include <gtest.h>
#include "polinom.h"
#include "monom.h"
#include "list.h"

//Список

TEST(list, can_create_empty_list)
{
	ASSERT_NO_THROW(TList<int> m);
}

TEST(list, can_copy_filled_list)
{
	TList<int> tmp;
	tmp.InsertToTail(5);
	tmp.InsertToTail(7);
	ASSERT_NO_THROW(TList<int> m(tmp));
}

TEST(list, copied_filled_list_is_correct)
{
	TList<int> tmp;
	tmp.InsertToTail(5);
	tmp.InsertToTail(7);
	TList<int> m(tmp);
	m.Reset();
	EXPECT_EQ(5, m.GetCur()->data);
	EXPECT_EQ(7, m.GetCur()->pNext->data);
	EXPECT_EQ(m.GetCur(), m.GetCur()->pNext->pNext->pNext);
	m.Reset(); tmp.Reset();
	EXPECT_NE(m.GetCur()->pNext->pNext, tmp.GetCur()->pNext->pNext);
}

TEST(list, can_assign_filled_list)
{
	TList<int> tmp;
	tmp.InsertToTail(5);
	tmp.InsertToTail(7);
	ASSERT_NO_THROW(TList<int> m = tmp);
}

TEST(list, insert_in_the_beginning)
{
	TList<int> tmp1;
	TList<int> tmp;
	tmp.InsertToTail(5);
	tmp.InsertToTail(7);
	tmp.InsertToTail(0);
	tmp.Reset();
	EXPECT_EQ(0, tmp.GetCur()->data);
	EXPECT_EQ(5, tmp.GetCur()->pNext->data);
	EXPECT_EQ(7, tmp.GetCur()->pNext->pNext->data);
	EXPECT_EQ(tmp1.GetCur()->pNext->pNext->pNext->pNext, tmp1.GetCur());
}

TEST(list, insert_in_the_middle)
{ 
	TList<int> tmp1;
	TList<int> tmp;
	tmp.InsertToTail(5);
	tmp.InsertToTail(7);
	tmp.InsertToTail(6);
	tmp.Reset();
	EXPECT_EQ(5, tmp.GetCur()->data);
	EXPECT_EQ(6, tmp.GetCur()->pNext->data);
	EXPECT_EQ(7, tmp.GetCur()->pNext->pNext->data);
	EXPECT_EQ(tmp1.GetCur()->pNext->pNext->pNext->pNext, tmp1.GetCur());
}

TEST(list, insert_in_the_end)
{
	TList<int> tmp1;
	TList<int> tmp;
	tmp.InsertToTail(5);
	tmp.InsertToTail(7);
	tmp.InsertToTail(15);
	tmp.Reset();
	EXPECT_EQ(5, tmp.GetCur()->data);
	EXPECT_EQ(7, tmp.GetCur()->pNext->data);
	EXPECT_EQ(15, tmp.GetCur()->pNext->pNext->data);
	EXPECT_EQ(tmp1.GetCur()->pNext->pNext->pNext->pNext, tmp1.GetCur());
}

//Полином

TEST(polynom, can_create_polinom)
{
	ASSERT_NO_THROW(TPolinom p("x^2+y+3z+1"));
}

TEST(polinom, can_create_polinom_copy)
{
	TPolinom p("x^2+y+3z+1");
	ASSERT_NO_THROW(TPolinom p1=p);
}

TEST(polynom, degree_not_more_than_9_1)
{
	TPolinom a("x^4"), b("x^5");
	ASSERT_NO_THROW(a * b);
}

TEST(polynom, degree_not_more_than_9_2)
{
	TPolinom a("x^5"), b("x^5");
	ASSERT_ANY_THROW(a * b);
}

TEST(polinom, add_two_polinom)
{
	TPolinom a("x^3yz+z^2-y^2-xyz+xy-3");
	TPolinom b("z^4y^5-y^2z^2+xyz+5");
	TPolinom c = a + b;
	TPolinom d("z^4y^5+x^3yz-y^2z^2+z^2-y^2+xy+2");
	EXPECT_EQ(c, d);
}

TEST(polinom, sub_two_polinom)
{
	TPolinom a("x^3yz+z^2-y^2-xyz+xy-3");
	TPolinom b("z^4y^5-y^2z^2+xyz+5");
	TPolinom c = b - a;
	TPolinom d("z^4y^5-x^3yz-y^2z^2+2xyz-xy+8");
	EXPECT_EQ(c, d);
}

TEST(polinom, mult_two_polinom)
{
	TPolinom a("x^2+y^2z^3+5");
	TPolinom b("z+2y-x-3");
	TPolinom c = a * b;
	TPolinom d("x^2z+2x^2y-x^3-3x^2+y^2z^4+2y^3z^3-3y^2z^3+5z+10y-5x-15");
	EXPECT_EQ(c, d);
}

TEST(polinom, mult_polinom_on_const)
{
	TPolinom a("x^2+y^2z^3+5");
	double b = 3;
	TPolinom c = a * b;
	TPolinom d("3x^2+3y^2z^3+15");
	EXPECT_EQ(c, d);
}