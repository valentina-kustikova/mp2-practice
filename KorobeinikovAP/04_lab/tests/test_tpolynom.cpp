#include "tpolynom.h"

#include <gtest.h>

TEST(TPolynom, can_create_empty_polynom)
{
	ASSERT_NO_THROW(TPolynom pl());
}


TEST(TPolynom, can_create_polynom_from_string)
{
	string a = "1+x^2-y^3+x*y*z-x^2*y*z^2";
	ASSERT_NO_THROW(TPolynom pl(a));
}

