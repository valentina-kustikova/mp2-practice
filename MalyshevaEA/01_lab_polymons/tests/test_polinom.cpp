#include <gtest.h>
#include "polinom.h"
// ����� ������� � ���������*/

TEST(headlist, CanCreateNewHList)
{
	ASSERT_NO_THROW(headlist<int> t);
}

TEST(headlist, CanInsertFirstElement)
{
    headlist<int> t;
	ASSERT_NO_THROW(t.pushfront(2));
}

TEST(headlist, CanDeleteFirstElement)
{
    headlist<int> t;
    t.pushfront(2);
	ASSERT_NO_THROW(t.dlfront());
}

TEST(list, CanCreateNewList)
{
	ASSERT_NO_THROW(list<int> t);
}

TEST(list, CanInsertFirstElement)
{
    list<int> t;
	ASSERT_NO_THROW(t.pushfront(1));
}

TEST(list, CanInsertLastElement)
{
    list<int> t;
	ASSERT_NO_THROW(t.pushback(1));
}

TEST(list, CanInsertElement)
{
    list<int> t;
    t.pushback(3);
    t.pushback(3);
	ASSERT_NO_THROW(t.insert(2, 1));
}

TEST(list, CanDeleteFirstElement)
{
    list<int> t;
    t.pushfront(1);
	ASSERT_NO_THROW(t.dlfront());
}

TEST(list, CanDeleteBackElement)
{
    list<int> t;
    t.pushfront(1);
	ASSERT_NO_THROW(t.dlback());
}

TEST(list, CanDeleteThisElement)
{
    list<int> t;
    t.pushfront(1);
    t.pushfront(2);
    t.pushfront(3);
	ASSERT_NO_THROW(t.dlat(1));
}

TEST(list, CanClearList)
{
    list<int> t;
    t.pushfront(1);
    t.pushfront(2);
    t.pushfront(3);
	ASSERT_NO_THROW(t.clear());
}

TEST(list, CanTakeElem)
{
    list<int> t;
    t.pushfront(1);
    t.pushfront(2);
    t.pushfront(3);
	ASSERT_NO_THROW(t[0]);
}

TEST(list, TakeFirstElement)
{
    list<int> t;
    t.pushfront(1);
    t.pushfront(2);
    t.pushfront(3);
	ASSERT_TRUE(t[0] == 3);
}

TEST(list, TakeLastElement)
{
    list<int> t;
    t.pushfront(1);
    t.pushfront(2);
    t.pushfront(3);
	ASSERT_TRUE(t[2] == 1);
}

TEST(node, CanCreateNewNode)
{
	ASSERT_NO_THROW(node<int> t);
}

TEST(monom, CanCreateNewMonom)
{
	ASSERT_NO_THROW(monom t);
}

TEST(monom, CanCreateMonom)
{
	ASSERT_NO_THROW(monom t(1, 1, 1, 1));
}

TEST(monom, CanMultiplyMonoms)
{
    monom m1(1, 1, 1, 1);
    monom m2(2, 2, 2, 2);
	ASSERT_NO_THROW(m1 * m2);
}

TEST(monom, CorMultiplyMonoms)
{
    monom m1(1, 1, 1, 1);
    monom m2(2, 2, 2, 2);
    monom m3(m1 * m2);
    monom m4(2, 3, 3, 3);
	EXPECT_EQ(m4, m3);
}

TEST(monom, CanPlussMonoms)
{
    monom m1(1, 1, 1, 1);
    monom m2(2, 1, 1, 1);
	ASSERT_NO_THROW(m1 + m2);
}

TEST(monom, CorPlussMonoms)
{
    monom m1(1, 1, 1, 1);
    monom m2(2, 1, 1, 1);
    monom m3(m1 + m2);
    monom m4(3, 1, 1, 1);
	EXPECT_EQ(m4, m3);
}

TEST(monom, CanMultiplyDouble)
{
    monom m1(1, 1, 1, 1);
	ASSERT_NO_THROW(m1 * 20);
}

TEST(monom, CorMultiplyDouble)
{
    monom m1(1, 1, 1, 1);
    monom m3(m1 * 20);
    monom m4(20, 1, 1, 1);
	EXPECT_EQ(m4, m3);
}

TEST(polinom, CanCreateNewPolinom)
{
    ASSERT_NO_THROW(polinom t);
}

TEST(polinom, CanCreateStringPolinom)
{
    ASSERT_NO_THROW(polinom t("3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z"));
}

TEST(polinom, CanCreatePolinom)
{
    polinom p1("x+y");
    ASSERT_NO_THROW(polinom t(p1));
}

TEST(polinom, TEST1)
{
    polinom p1("3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z");
    polinom p2("4x^3y^2z^6-6x^2yz^8");
    polinom p3(p1 + p2);
    polinom p4("-6x^2yz^8+4x^3y^2z^6+7x^3y^5z-5x^4y^3z^3+3x^5y^2z^5");
	EXPECT_EQ(p4, p3);
}

TEST(polinom, TEST2)
{
    polinom p1("3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z");
    polinom p2("4x^7y^2z^6-6x^6yz^8");
    polinom p3(p1 + p2);
    polinom p4("7x^3y^5z-5x^4y^3z^3+3x^5y^2z^5-6x^6yz^8+4x^7y^2z^6");
	EXPECT_EQ(p4, p3);
}

TEST(polinom, TEST3)
{
    polinom p1("3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z");
    polinom p2("4x^5y^2z^5+5x^4y^3z^3");
    polinom p3(p1 + p2);
    polinom p4("7x^3y^5z+7x^5y^2z^5");
	EXPECT_EQ(p4, p3);
}

TEST(polinom, TEST4)
{
    polinom p1("3x^5y^2z^5-5x^4y^3z^3+7x^7y^5z");
    polinom p2("4x^6y^2z^6-6x^2yz^8");
    polinom p3(p1 + p2);
    polinom p4("-6x^2yz^8-5x^4y^3z^3+3x^5y^2z^5+4x^6y^2z^6+7x^7y^5z");
	EXPECT_EQ(p4, p3);
}

TEST(polinom, TEST5)
{
    polinom p1("3x^5y^2z^5-5x^4y^3z^3+7x^7y^5z");
    polinom p2("-3x^5y^2z^5+5x^4y^3z^3-7x^7y^5z");
    polinom p3(p1 + p2);
    polinom p4("");
	EXPECT_EQ(p4, p3);
}