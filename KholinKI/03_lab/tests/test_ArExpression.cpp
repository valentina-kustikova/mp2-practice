#include "ArExpression.h"

#include <gtest.h>


TEST(Stack, can_ToPostfix) {
	ArithmeticExpression<double> Expr("(a+b*c)*(d/c-e)+g");//контроль на чужеродные символы
}
