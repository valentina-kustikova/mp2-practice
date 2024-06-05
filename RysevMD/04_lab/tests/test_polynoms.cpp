#include <gtest.h>
#include "TNode.h"
#include "TList.h"
#include "TRingList.h"
#include "TPolynom.h"

TEST(TPolynom, can_create_object_with_default_constructor) {
	ASSERT_NO_THROW(TPolynom());
}

TEST(TPolynom, can_create_object_with_link_str_conctructor) {
	ASSERT_NO_THROW(TPolynom("3*X^3*Y^2*Z + 3*X^3*Y^2 + 3*Y^2*Z + 3*X^3*Z"));
}

TEST(TPolynom, can_create_object_with_link_TRL_constructor) {
	TRingList<Monom> trl;
	Monom a(1, 1, 2, 3), b(2, 3, 4, 5), c(4, 1, 2, 4);
	trl.insertLast(a); trl.insertLast(b), trl.insertLast(c);
	ASSERT_NO_THROW(TPolynom(trl));
}

TEST(TPolynom, can_create_object_with_copy_constructor) {
	TPolynom pol("X^2*Y^3*Z^4");
	ASSERT_NO_THROW(TPolynom(pol));
}

//TEST(TPolynom, can_destroy_object) {
//	TPolynom pol("X^2*Y^3*Z^4 + X^3*Y^3*Z^4");
//	ASSERT_NO_THROW(pol.~TPolynom());
//}

TEST(TPolynom, assignment_operator) {
	TPolynom pol1("X^2*Y^3*Z^4");
	TPolynom pol2 = pol1;
	EXPECT_EQ(pol1, pol2);
}

TEST(TPolynom, plus_operator) {
	TPolynom pol1("X^2*Y^3*Z^4");
	TPolynom pol2("2*X^2*Y^3*Z^4");
	TPolynom pol3("3*X^2*Y^3*Z^4");
	TPolynom pol4 = (pol1 + pol2);
	EXPECT_EQ(pol3, pol4);
}

TEST(TPolynom, minus_operator) {
	TPolynom pol1("X^2*Y^3*Z^4");
	TPolynom pol2("2*X^2*Y^3*Z^4");
	TPolynom pol3("-X^2*Y^3*Z^4");
	TPolynom pol4 = (pol1 - pol2);
	EXPECT_EQ(pol3, pol4);
}

TEST(TPolynom, multiply_operator) {
	TPolynom pol1("2*X^2*Y^3*Z^4");
	TPolynom pol2("X^2*Y^3*Z^4 + 3*X^2*Y^3*Z^3");
	TPolynom pol3("2*X^4*Y^6*Z^8 + 6*X^4*Y^6*Z^7");
	TPolynom pol4 = (pol1 * pol2);
	EXPECT_EQ(pol3, pol4);
}

TEST(TPolynom, multiply_assigment_operator_with_int) {
	TPolynom pol1("2*X^2*Y^3*Z^4");
	TPolynom pol2("6*X^2*Y^3*Z^4");
	pol1 *= 3;
	EXPECT_EQ(pol2, pol1);
}

TEST(TPolynom, multiply_assigment_operator_with_float) {
	TPolynom pol1("2*X^2*Y^3*Z^4");
	TPolynom pol2("6*X^2*Y^3*Z^4");
	pol1 *= 3.0f;
	EXPECT_EQ(pol2, pol1);
}

TEST(TPolynom, calculate) {
	TPolynom pol1("2*X^2*Y^3*Z^4 + 1");
	int res = 145;
	EXPECT_EQ(res, pol1(3, 2, 1));
}

TEST(TPolynom, comparison_for_equality) {
	TPolynom pol1("2*X^2*Y^3*Z^4 + 1");
	TPolynom pol2("2*X^2*Y^3*Z^4 + 1");
	EXPECT_TRUE(pol1 == pol2);
}

TEST(TPolynom, differenyiation_by_X) {
	TPolynom pol1("2*X^2*Y^3*Z^4 + 1");
	TPolynom pol2("4*X*Y^3*Z^4");
	EXPECT_EQ(pol2, pol1.dif_x());
}

TEST(TPolynom, differenyiation_by_Y) {
	TPolynom pol1("2*X^2*Y^3*Z^4 + 1");
	TPolynom pol2("6*X^2*Y^2*Z^4");
	EXPECT_EQ(pol2, pol1.dif_y());
}

TEST(TPolynom, differenyiation_by_Z) {
	TPolynom pol1("2*X^2*Y^3*Z^4 + 1");
	TPolynom pol2("8*X^2*Y^3*Z^3");
	EXPECT_EQ(pol2, pol1.dif_z());
}