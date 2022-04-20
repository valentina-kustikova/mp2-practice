#include <gtest.h>
#include "polinom.h"

//Линейный список

TEST(list, can_create_list)
{
	ASSERT_NO_THROW(TList<int> list);
}

TEST(list, correct_insert_first_element_in_list)
{
	TList<int> list;
	ASSERT_NO_THROW(list.InsertToHead(5););
}

TEST(list, can_copy_list)
{
	TList<int> list;
	list.InsertToTail(5);
	list.InsertToTail(7);
	ASSERT_NO_THROW(TList<int> m(list));
}

TEST(list, correct_insert_last_element_in_list)
{
	TList<int>list;
	list.InsertToHead(4);
	ASSERT_NO_THROW(list.InsertToTail(5));
}

TEST(list, can_insert_current_element_in_first_list)
{
	TList<int> list;
	list.InsertToHead(1);
	list.InsertToTail(2);
	list.InsertToTail(3);
	list.InsertToTail(5);
	list.InsertToTail(8);
	list.Reset();
	ASSERT_NO_THROW(list.Insert(13));
}

TEST(list, can_insert_current_element_third_in_list)
{
	TList<int> list;
	list.InsertToHead(1);
	list.InsertToTail(2);
	list.InsertToTail(3);
	list.InsertToTail(5);
	list.InsertToTail(8);
	list.Reset();
	list.Next();
	list.Next();
	ASSERT_NO_THROW(list.Insert(13));
}

TEST(list, can_insert_current_element_in_last_list)
{
	TList<int> list;
	list.InsertToHead(1);
	list.InsertToTail(2);
	list.InsertToTail(3);
	list.InsertToTail(5);
	list.InsertToTail(8);
	list.Reset();
	list.Next();
	list.Next();
	list.Next();
	list.Next();
	list.Next();
	ASSERT_NO_THROW(list.Insert(13));
}

TEST(list, can_delete_first_element_in_list)
{
	TList<int> list;
	list.InsertToHead(1);
	list.InsertToTail(2);
	list.InsertToTail(3);
	list.InsertToTail(5);
	list.InsertToTail(8);
	list.Reset();
	ASSERT_NO_THROW(list.RemoveFirst());
}

TEST(list, can_delete_last_element_in_list)
{
	TList<int> list;
	list.InsertToHead(1);
	list.InsertToTail(2);
	list.InsertToTail(3);
	list.InsertToTail(5);
	list.InsertToTail(8);
	list.Reset();
	ASSERT_NO_THROW(list.RemoveLast());
}

TEST(list, equality_of_two_lists)
{
	TList<int> list1;
	TList<int> list2;
	list1.InsertToTail(1);
	list1.InsertToTail(3);
	list2.InsertToTail(1);
	list2.InsertToTail(3);
	list1.Reset();
	list2.Reset();
	ASSERT_EQ(list1, list2);
}

TEST(list, not_equality_of_two_lists)
{
	TList<int> list1;
	TList<int> list2;
	list1.InsertToTail(1);
	list1.InsertToTail(3);
	list2.InsertToTail(1);
	list2.InsertToTail(5);
	list1.Reset();
	list2.Reset();
	ASSERT_NE(list1, list2);
}

//Моном
TEST(monom, can_create_monom)
{
	ASSERT_NO_THROW(TMonom mon);
}

TEST(monom, can_create_monom_2)
{
	ASSERT_NO_THROW(TMonom mon(1,123));
}

TEST(monom, can_not_create_monom_with_degree_more_999)
{
	ASSERT_ANY_THROW(TMonom mon(3, 1234));
}

//Полином

TEST(polynom, can_create_polinom)
{
	ASSERT_NO_THROW(TPolinom p);
}

TEST(polinom, can_create_polinom_2)
{
	TPolinom p("x^2+y+3z+1");
}

TEST(polinom, can_create_polinom_copy)
{
	TPolinom p("x^2+y+3z+1");
	ASSERT_NO_THROW(TPolinom p1 = p);
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

TEST(polinom, add_polinom_and_monom)
{
	TPolinom a("z^4+xyz+2xy-23-x^2y^3+xz");
	TMonom mon(2, 230);
	TPolinom b = a + mon;
	TPolinom c("z^4+xyz+2xy-23+x^2y^3+xz");
	EXPECT_EQ(b, c);
}

TEST(polinom, add_two_polinoms)
{
	TPolinom a("x^3yz+z^2-y^2-xyz+xy-3");
	TPolinom b("z^4y^5-y^2z^2+xyz+5");
	TPolinom c = a + b;
	TPolinom d("z^4y^5+x^3yz-y^2z^2+z^2-y^2+xy+2");
	EXPECT_EQ(c, d);
}

TEST(polinom, sub_two_polinoms)
{
	TPolinom a("x^3yz+z^2-y^2-xyz+xy-3");
	TPolinom b("z^4y^5-y^2z^2+xyz+5");
	TPolinom c = b - a;
	TPolinom d("z^4y^5-x^3yz-y^2z^2+2xyz-xy+8");
	EXPECT_EQ(c, d);
}

TEST(polinom, mult_two_polinoms)
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
