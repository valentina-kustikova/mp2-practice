#include "gtest.h"
#include "Polinom.h"

TEST(TPolinom, test00)
{
	TPolinom P("2x^2y-z^3");
	if (P(1,2,3) == -23) SUCCEED();
	else FAIL();
}

TEST(TPolinom, test01)
{
	TPolinom P("4x^5y^2z^5+5x^4y^3z^3");
	if (P(1, 2, 3) == 4968) SUCCEED();
	else FAIL();
}
TEST(TPolinom, test0)
{
	TPolinom P("3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z^1+4x^3y^2z^6-6x^2y^1z^8");
	if (P == "3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z^1+4x^3y^2z^6-6x^2y^1z^8") SUCCEED();
	else FAIL();
}
TEST(TPolinom, test1)
{
	TPolinom P("3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z^1");
	TPolinom Q("4x^3y^2z^6-6x^2y^1z^8");
	if ((P+Q)== "3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z^1+4x^3y^2z^6-6x^2y^1z^8") SUCCEED();
		else FAIL();
}
TEST(TPolinom, test2)
{
	TPolinom P("3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z^1");
	TPolinom Q("4x^7y^2z^6-6x^6y^1z^8");
	TPolinom S("-6x^6y^1z^8+4x^7y^2z^6+3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z^1");
	if ((P + Q) == S) SUCCEED();
	else FAIL();
}
TEST(TPolinom, test3)
{
	TPolinom P("3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z^1");
	TPolinom Q("4x^5y^2z^5+5x^4y^3z^3");
	TPolinom S("7x^5y^2z^5+7x^3y^5z^1");
	if ((P + Q) == S) SUCCEED();
	else FAIL();
}
TEST(TPolinom, test4)
{
	TPolinom P("3x^5y^2z^5-5x^4y^3z^3+7x^7y^5z^1");
	TPolinom Q("4x^6y^2z^6-6x^2y^1z^8");
	TPolinom S("7x^7y^5z^1+4x^6y^2z^6+3x^5y^2z^5-5x^4y^3z^3-6x^2y^1z^8");
	if ((P + Q) == S) SUCCEED();
	else FAIL();
}
TEST(TPolinom, test5)
{
	TPolinom P("3x^5y^2z^5-5x^4y^3z^3+7x^7y^5z^1");
	TPolinom Q("-3x^5y^2z^5+5x^4y^3z^3-7x^7y^5z^1");
	TPolinom S("0");
	if ((P+Q) == S) SUCCEED();
	else FAIL();
}
TEST(TPolinom, test6)
{
	TPolinom P("3x^5y^2z^5-5x^4y^3z^3+7x^7y^5z^1");
	TPolinom Q("-3x^5y^2z^5+5x^4y^3z^3-7x^7y^5z^1");
	if ((P + Q) == "0") SUCCEED();
	else FAIL();
}

TEST(TPolinom, can_create_polinom)
{
	ASSERT_NO_THROW(TPolinom l);
}
TEST(TPolinom, can_create_polinom_from_monom)
{
	TMonom m(1, 123);
	ASSERT_NO_THROW(TPolinom l(m));
}
TEST(TPolinom, can_add_monom)
{
	TMonom m(1, 123);
	TPolinom p(m);
	TPolinom b;
	b=b+m;
	if (p == b) SUCCEED();
	else FAIL();
}
TEST(TPolinom, can_insert_to_head)
{
	TMonom m(1, 123);
	TPolinom p;
	TPolinom b(m);

	p.InsertToHead(m);
	if (p == b) SUCCEED();
	else FAIL();
}
TEST(TPolinom, can_insert_current)
{
	TPolinom p;
	TMonom m(1, 123);
	p.insCurrent(m);
	TPolinom b(m);
	if (p == b) SUCCEED();
	else FAIL();
}
TEST(TPolinom, can_insert_last)
{
	TPolinom p;
	TMonom m(1, 123);
	p.insLast(m);
	p.goNext();

}
TEST(TPolinom, can_copy_polinom)
{
	TPolinom p;
	TMonom m(1, 123);
	p=p+m;
	ASSERT_NO_THROW(TPolinom(p));
}
TEST(TPolinom, Can_create_TPolinom_from_string)
{
	ASSERT_NO_THROW(TPolinom p("x^2+5xz+2"));
}

/**/












