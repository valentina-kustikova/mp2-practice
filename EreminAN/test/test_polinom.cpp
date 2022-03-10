#include <gtest.h>
#include "Polynom.h"
#include "Monom.h"
// тесты мономов и полиномов

//==============================“есты из методички==============================
TEST(Polynom, test_from_manual_1)
{
	Polynom P("3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z");
	Polynom Q("4x^3y^2z^6-6x^2yz^8");
	Polynom Res("3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z+4x^3y^2z^6-6x^2yz^8");
	ASSERT_EQ(Res, P + Q);
}

TEST(Polynom, test_from_manual_2)
{
	Polynom P("3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z");
	Polynom Q("4x^7y^2z^6-6x^6yz^8");
	Polynom Res("4x^7y^2z^6-6x^6yz^8+3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z");
	ASSERT_EQ(Res, P + Q);
}

TEST(Polynom, test_from_manual_3)
{
	Polynom P("3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z");
	Polynom Q("4x^5y^2z^5+5x^4y^3z^3");
	Polynom Res("7x^5y^2z^5+7x^3y^5z");
	ASSERT_EQ(Res, P + Q);
}

TEST(Polynom, test_from_manual_4)
{
	Polynom P("3x^5y^2z^5-5x^4y^3z^3+7x^7y^5z");
	Polynom Q("4x^6y^2z^6-6x^2yz^8");
	Polynom Res("7x^7y^5z+4x^6y^2z^6+3x^5y^2z^5-5x^4y^3z^3-6x^2yz^8");
	ASSERT_EQ(Res, P + Q);
}

TEST(Polynom, test_from_manual_5)
{
	Polynom P("3x^5y^2z^5-5x^4y^3z^3+7x^7y^5z");
	Polynom Q("-3x^5y^2z^5+5x^4y^3z^3-7x^7y^5z");
	Polynom Res("0");
	ASSERT_EQ(Res, P + Q);
}
//======================================================================================
TEST(Polynom, can_create_Polynom)
{
	ASSERT_NO_THROW(Polynom p);
}
///////////////////////////////////////////////////////////
TEST(Polynom, can_create_Polynom_with_initial_parameters_1)
{
	ASSERT_NO_THROW(Polynom p("2xyz"));
}

TEST(Polynom, can_create_Polynom_with_initial_parameters_2)
{
	ASSERT_NO_THROW(Polynom p("2zyx"));
}

TEST(Polynom, can_create_Polynom_with_initial_parameters_3)
{
	ASSERT_NO_THROW(Polynom p("2xz"));
}


TEST(Polynom, can_create_Polynom_with_initial_parameters_4)
{
	ASSERT_NO_THROW(Polynom p("2x^5y^4z+3x^2"));
}
///////////////////////////////////////////////////////////
TEST(Polynom, parser_and_lexem_no_throw_test_1)
{
	Polynom P;
	ASSERT_NO_THROW(P.parser("2"));
}

TEST(Polynom, parser_and_lexem_no_throw_test_2)
{
	Polynom P;
	ASSERT_NO_THROW(P.parser("2x^25yz^3"));
}

TEST(Polynom, parser_and_lexem_no_throw_test_3)
{
	Polynom P;
	ASSERT_NO_THROW(P.parser("2x^25z^2y"));
}

TEST(Polynom, parser_and_lexem_no_throw_test_4)
{
	Polynom P;
	ASSERT_NO_THROW(P.parser("-2.6x^2xz^3"));
}

TEST(Polynom, parser_and_lexem_no_throw_test_5)
{
	Polynom P;
	ASSERT_NO_THROW(P.parser("2x^5yz+3x^4y -2.6 x^3z^5+x^2+xy- 8.6+z"));
}

TEST(Polynom, parser_and_lexem_no_throw_test_6)
{
	Polynom P;
	Polynom Q("2xz^5y+5x^2");
	ASSERT_NO_THROW(P.parser("2xz^5y++5x^2"));
	ASSERT_EQ(Q, P);
}

TEST(Polynom, parser_and_lexem_no_throw_test_7)
{
	Polynom P;
	Polynom Q("2xy+5x^2z");
	ASSERT_NO_THROW(P.parser("2xy--5x^2z"));
	ASSERT_EQ(Q, P);
}

TEST(Polynom, parser_and_lexem_no_throw_test_8)
{
	Polynom P;
	Polynom Q("2xyz-5x^2z");
	ASSERT_NO_THROW(P.parser("2xyz-+5x^2z"));
	ASSERT_EQ(Q, P);
}

TEST(Polynom, parser_and_lexem_no_throw_test_9)
{
	Polynom P;
	Polynom Q("2xyz^3+5x^2-5x^6zy^2");
	ASSERT_NO_THROW(P.parser("2xyz^3+5x^2+-5x^6zy^2"));
	ASSERT_EQ(Q, P);
}

TEST(Polynom, parser_and_lexem_no_throw_test_10)
{
	Polynom P;
	Polynom Q("2xy^5z+5x^2z-5x^6yz");
	ASSERT_NO_THROW(P.parser("+2xy^5z+5x^2z+-5x^6yz"));
	ASSERT_EQ(Q, P);
}

TEST(Polynom, parser_and_lexem_no_throw_test_11)
{
	Polynom P;
	Polynom Q("2x^3y^2z+5");
	ASSERT_NO_THROW(P.parser("2xx^2yyz+5"));
	ASSERT_EQ(Q, P);
}

TEST(Polynom, parser_and_lexem_no_throw_test_12)
{
	Polynom P;
	Polynom Q("2x^2zzy2yx+5xxy5yzz");
	ASSERT_NO_THROW(P.parser("4x^3y^2z^2+25x^2y^2z^2"));
	ASSERT_EQ(Q, P);
}
///////////////////////////////////////////////////////////
TEST(Polynom, parser_and_lexem_any_throw_test_1)
{
	Polynom P;
	ASSERT_ANY_THROW(P.parser("2x^yz"));
}

TEST(Polynom, parser_and_lexem_any_throw_test_2)
{
	Polynom P;
	ASSERT_ANY_THROW(P.parser("2x^2 &+5x"));
}

TEST(Polynom, parser_and_lexem_any_throw_test_3)
{
	Polynom P;
	ASSERT_ANY_THROW(P.parser("2x^5+/3x^4 -2.6 x^3+x^2$$+x- 8.6"));
}
///////////////////////////////////////////////////////////
TEST(Polynom, equality_operator_1)
{
	Polynom P("2x^2yz^3+5x^3z^5y");
	Polynom Q("5yz^5x^3+2x^2z^3y");
	ASSERT_EQ(Q, P);
}

TEST(Polynom, equality_operator_2)
{
	Polynom P("-2.6x^25x-59xyz+8.5x^2z^3y+5");
	Polynom Q("8.5x^2yz^3-2.6x^26-59xzy+5");
	ASSERT_EQ(Q, P);
}

TEST(Polynom, equality_operator_3)
{
	Polynom P("2xyz+6xz^5y-8.6z");
	Polynom Q("-8.6z+2xyz+6xz^5y");
	ASSERT_EQ(Q, P);
}
///////////////////////////////////////////////////////////
TEST(Polynom, function_cancellation_no_throw_1)
{
	Polynom P("2x^2+5x^2");
	ASSERT_NO_THROW(P.cancellation(););
}

TEST(Polynom, function_cancellation_no_throw_2)
{
	Polynom P("-2x^2yyz+5x^2+z+z+zy+yz");
	ASSERT_NO_THROW(P.cancellation(););
}

TEST(Polynom, function_cancellation_1)
{
	Polynom P("2x^2yz+5x^2zy");
	P = P.cancellation();
	Polynom Q("7x^2zy");
	ASSERT_EQ(Q, P);
}

TEST(Polynom, function_cancellation_2)
{
	Polynom P("2xyz+yzx+xzy+5+1");
	P = P.cancellation();
	Polynom Q("4xyz+6");
	ASSERT_EQ(Q, P);
}

TEST(Polynom, function_cancellation_3)
{
	Polynom P("x^2yz+zyx^2+1+1+1+1+xy+yx+xy+x^3yz^5");
	P = P.cancellation();
	Polynom Q("x^3yz^5+2x^2zy+3xy+4");
	ASSERT_EQ(Q, P);
}
///////////////////////////////////////////////////////////
TEST(Polynom, addition_operation_no_throw_1)
{
	Polynom P("2xyz");
	Polynom Q("3zxy");
	ASSERT_NO_THROW(P + Q);
}

TEST(Polynom, addition_operation_no_throw_2)
{
	Polynom P("2xyz+5xy+5");
	Polynom Q("3zxy+2+x");
	ASSERT_NO_THROW(P + Q);
}

TEST(Polynom, addition_operation_1)
{
	Polynom P("2xyz");
	Polynom Q("3zxy");
	Polynom Res("5xyz");
	ASSERT_EQ(Res, P + Q);
}

TEST(Polynom, addition_operation_2)
{
	Polynom P("2.3xyz+2x-3z+5.1x^2z");
	Polynom Q("3.1zxy+5+5,5x^2z");
	Polynom Res("5.4xyz+10,6x^2z+2x-3z+5");
	ASSERT_EQ(Res, P + Q);
}

TEST(Polynom, addition_operation_3)
{
	Polynom P("5,5xy^2-2xyz-6");
	Polynom Q("-1,5y^2x-2xyz+6");
	Polynom Res("4xy^2-4xyz");
	ASSERT_EQ(Res, P + Q);
}

TEST(Polynom, addition_operation_zero_1)
{
	Polynom P("2xyz");
	Polynom Q("2x-2x");
	Q.cancellation();
	Polynom Res("2xyz");
	ASSERT_EQ(Res, P + Q);
}

TEST(Polynom, addition_operation_zero_2)
{
	Polynom Q("2xyz");
	Polynom P("2x-2x");
	Q.cancellation();
	Polynom Res("2xyz");
	ASSERT_EQ(Res, P + Q);
}
///////////////////////////////////////////////////////////
TEST(Polynom, minus_operation_no_throw_1)
{
	Polynom P("2xyz");
	Polynom Q("3zxy");
	ASSERT_NO_THROW(P - Q);
}

TEST(Polynom, minus_operation_no_throw_2)
{
	Polynom P("2xyz-z^2");
	Polynom Q("2zxy-z^2");
	ASSERT_NO_THROW(P - Q);
}

TEST(Polynom, minus_operation_1)
{
	Polynom P("2x^2yz^3-5xy+5");
	Polynom Q("2x^2yz^3+5xy");
	Polynom Res("-10xy+5");
	ASSERT_EQ(Res, P - Q);
}

TEST(Polynom, minus_operation_2)
{
	Polynom P("5.6xyz+4+1+x");
	Polynom Q("0.1xyz+6-x^2");
	Polynom Res("5.5xyz-1+x+x^2");
	ASSERT_EQ(Res, P - Q);
}

TEST(Polynom, minus_operation_3)
{

	Polynom P("3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z");
	Polynom Q("4x^7y^2z^6-6x^6yz^8");
	Polynom Res("3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z-4x^7y^2z^6+6x^6yz^8");
	ASSERT_EQ(Res, P - Q);
}

TEST(Polynom, minus_operation_zero_1)
{

	Polynom P("2xy^2");
	Polynom Q("2xy-2xy");
	Q.cancellation();
	Polynom Res("2xy^2");
	ASSERT_EQ(Res, P - Q);
}

TEST(Polynom, minus_operation_zero_2)
{

	Polynom P("2xy^2");
	Polynom Q("2xy-2xy");
	Q.cancellation();
	Polynom Res("-2xy^2");
	ASSERT_EQ(Res, Q-P);
}
///////////////////////////////////////////////////////////
TEST(Polynom, multi_operation_no_throw_1)
{
	Polynom P("2xyz");
	Polynom Q("3zxy");
	ASSERT_NO_THROW(P * Q);
}

TEST(Polynom, multi_operation_no_throw_2)
{
	Polynom P("2xyz-5");
	Polynom Q("3zxy+x^2");
	ASSERT_NO_THROW(P * Q);
}

TEST(Polynom, multi_operation_1)
{
	Polynom P("5.5xyz+4+1+x");
	Polynom Q("xyz+6-x^2");
	Polynom Res("5,5x^2y^2z^2+38xyz-5.5x^3yz+30-5x^2+x^2yz+6x-x^3");
	ASSERT_EQ(Res, P * Q);
}

TEST(Polynom, multi_operation_2)
{
	Polynom P("5.6xyz+4+1+x");
	Polynom Q("0");
	Polynom Res("0");
	ASSERT_EQ(Res, P * Q);
}


TEST(Polynom, multi_operation_3)
{
	Polynom P("3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z");
	Polynom Q("4x^7y^2z^6-6x^6yz^8");
	Polynom Res("12x^12y^4z^11-18x^11y^3z^13-20x^11y^5z^9+30x^10y^4z^11+28x^10y^7z^7-42x^9y^6z^9");
	ASSERT_EQ(Res, P * Q);
}
///////////////////////////////////////////////////////////
TEST(Polynom, addition_const_operation_no_throw_1)
{
	Polynom P("3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z");
	ASSERT_NO_THROW(P + 5);
}

TEST(Polynom, addition_const_operation_1)
{
	Polynom P("2xyz");
	Polynom Res("2xyz+5");
	ASSERT_EQ(Res, P + 5);
}

TEST(Polynom, addition_const_operation_2)
{
	Polynom P("2xyz");
	Polynom Res("2xyz");
	ASSERT_EQ(Res, P + 0);
}

TEST(Polynom, addition_const_operation_3)
{
	Polynom P("5.5xyz+4+1+x");
	Polynom Res("5.5xyz+x+10");
	ASSERT_EQ(Res, P + 5);
}

TEST(Polynom, addition_const_operation_4)
{
	Polynom P("5.5xyz+4+1+2+3+x");
	Polynom Res("5.5xyz+x+15");
	ASSERT_EQ(Res, P + 5);
}
///////////////////////////////////////////////////////////
TEST(Polynom, minus_const_operation_no_throw_1)
{
	Polynom P("15xyz^2+5");
	ASSERT_NO_THROW(P - 5);
}

TEST(Polynom, minus_const_operation_1)
{
	Polynom P("5.5xyz+4+1+2+3+x");
	Polynom Res("5.5xyz+x+5");
	ASSERT_EQ(Res, P - 5);
}

TEST(Polynom, minus_const_operation_2)
{
	Polynom P("-10+5.5xyz^2+yz");
	Polynom Res("-16+5.5xyz^2+yz");
	ASSERT_EQ(Res, P - 6);
}

TEST(Polynom, minus_const_operation_3)
{
	Polynom P("3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z");
	Polynom Res("3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z");
	ASSERT_EQ(Res, P - 0);
}
///////////////////////////////////////////////////////////
TEST(Polynom, multi_const_operation_no_throw_1)
{
	Polynom P("25x^2zy+5xyz+5z+x");
	ASSERT_NO_THROW(P * 5);
}

TEST(Polynom, multi_const_operation_1)
{
	Polynom P("5x^2zy+5xyz-2z+x");
	Polynom Res("25x^2zy+25xyz-10z+5x");
	ASSERT_EQ(Res, P * 5);
}

TEST(Polynom, multi_const_operation_2)
{
	Polynom P("3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z");
	Polynom Res("-6x^5y^2z^5+10x^4y^3z^3-14x^3y^5z");
	ASSERT_EQ(Res, P * (-2));
}

TEST(Polynom, multi_const_operation_3)
{
	Polynom P("3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z");
	Polynom Res("0");
	ASSERT_EQ(Res, P * (0));
}
///////////////////////////////////////////////////////////