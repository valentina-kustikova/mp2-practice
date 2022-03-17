#include "gtest.h"
#include "Polinom.h"


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
	b.addMonom(m);
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
	p.addMonom(m);
	ASSERT_NO_THROW(TPolinom(p));
}
TEST(TPolinom, Can_create_TPolinom_from_string)
{
	ASSERT_NO_THROW(TPolinom p("x^2+5xz+2"));
}














