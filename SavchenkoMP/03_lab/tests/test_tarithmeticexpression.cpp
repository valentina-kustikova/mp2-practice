#include <gtest.h>

#include "tarithmeticexpression_str.h"

/*
1. A+B*C
   A B C * +

2. D/(E-F)
   D E F - /

3. (G+H)*I-J
   G H + I * J -

4. K*L/(M+N)
   K L M N + /

5. (O-P)*Q/R+S
   O P - Q R / S +

6. T*(U+V)-W/X
   T U V * W X / -

7. Y/Z-(A+B)*C
   Y Z / A B + C * -

8. D+(E*F)/G-H
   D E F * G / + H -

9. I*(J-K/L)+M
   I J K L / - * M +

10. N/(O+P)-Q*R+S
	N O P + / Q R * - S +
*/

TEST(TArithmeticExpression_str, ArithmeticExpression1) {
	string str = "A+B*C";
	string expPostfix = "A B C * +";

	ASSERT_NO_THROW(TArithmeticExpression_str ae(str));
	
	TArithmeticExpression_str ae(str);
	EXPECT_EQ(expPostfix, ae.GetStringPostfix());
}

TEST(TArithmeticExpression_str, ArithmeticExpression2) {
	string str = "D/(E-F)";
	string expPostfix = "D E F - /";

	ASSERT_NO_THROW(TArithmeticExpression_str ae(str));

	TArithmeticExpression_str ae(str);
	EXPECT_EQ(expPostfix, ae.GetStringPostfix());
}

TEST(TArithmeticExpression_str, ArithmeticExpression3) {
	string str = "(G+H)*I-J";
	string expPostfix = "G H + I * J -";

	ASSERT_NO_THROW(TArithmeticExpression_str ae(str));

	TArithmeticExpression_str ae(str);
	EXPECT_EQ(expPostfix, ae.GetStringPostfix());
}

TEST(TArithmeticExpression_str, ArithmeticExpression4) {
	string str = "K*L/(M+N)";
	string expPostfix = "K L * M N + /";

	ASSERT_NO_THROW(TArithmeticExpression_str ae(str));

	TArithmeticExpression_str ae(str);
	EXPECT_EQ(expPostfix, ae.GetStringPostfix());
}

TEST(TArithmeticExpression_str, ArithmeticExpression5) {
	string str = "(O-P)*Q/R+S";
	string expPostfix = "O P - Q * R / S +";

	ASSERT_NO_THROW(TArithmeticExpression_str ae(str));

	TArithmeticExpression_str ae(str);
	EXPECT_EQ(expPostfix, ae.GetStringPostfix());
}

TEST(TArithmeticExpression_str, ArithmeticExpression6) {
	string str = "T*(U+V)-W/X";
	string expPostfix = "T U V + * W X / -";

	ASSERT_NO_THROW(TArithmeticExpression_str ae(str));

	TArithmeticExpression_str ae(str);
	EXPECT_EQ(expPostfix, ae.GetStringPostfix());
}

TEST(TArithmeticExpression_str, ArithmeticExpression7) {
	string str = "Y/Z-(A+B)*C";
	string expPostfix = "Y Z / A B + C * -";

	ASSERT_NO_THROW(TArithmeticExpression_str ae(str));

	TArithmeticExpression_str ae(str);
	EXPECT_EQ(expPostfix, ae.GetStringPostfix());
}

TEST(TArithmeticExpression_str, ArithmeticExpression8) {
	string str = "D+(E*F)/G-H";
	string expPostfix = "D E F * G / + H -";

	ASSERT_NO_THROW(TArithmeticExpression_str ae(str));

	TArithmeticExpression_str ae(str);
	EXPECT_EQ(expPostfix, ae.GetStringPostfix());
}

TEST(TArithmeticExpression_str, ArithmeticExpression9) {
	string str = "I*(J-K/L)+M";
	string expPostfix = "I J K L / - * M +";

	ASSERT_NO_THROW(TArithmeticExpression_str ae(str));

	TArithmeticExpression_str ae(str);
	EXPECT_EQ(expPostfix, ae.GetStringPostfix());
}

TEST(TArithmeticExpression_str, ArithmeticExpression10) {
	string str = "N/(O+P)-Q*R+S";
	string expPostfix = "N O P + / Q R * - S +";

	ASSERT_NO_THROW(TArithmeticExpression_str ae(str));

	TArithmeticExpression_str ae(str);
	EXPECT_EQ(expPostfix, ae.GetStringPostfix());
}

