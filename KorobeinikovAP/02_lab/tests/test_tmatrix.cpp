#include "tmatrix.h"

#include <gtest.h>

TEST(Matrix, can_create_matrix_with_positive_size)
{
	ASSERT_NO_THROW(TMatrix<int> m(10));
}

TEST(Matrix, throws_when_create_matrix_with_negative_size)
{
	ASSERT_ANY_THROW(TMatrix<int> m(-3));
}


TEST(Matrix, can_create_copy_of_the_matrix)
{
	TMatrix<int> a(2);
	a[0][0] = 1;
	a[0][1] = 2;
	a[1][0] = 2;

	TMatrix<int> b(a);

	EXPECT_EQ(a, b);
}

TEST(Matrix, copied_vector_has_its_own_memory)
{
	TMatrix<int> a(2);
	a[0][0] = 1;
	a[0][1] = 2;
	a[1][0] = 1;

	TMatrix<int> b(a);
	b[0][0] = 2;

	EXPECT_NE(a, b);
}


TEST(Matrix, can_assign_matrix_with_equal_size)
{
	TMatrix<int> a(2);
	a[0][0] = 1;
	a[0][1] = 2;
	a[1][0] = 1;

	TMatrix<int> b(2);
	b = a;

	EXPECT_EQ(a, b);
}


TEST(Matrix, can_assign_matrix_with_not_equal_size)
{
	TMatrix<int> a(2);
	a[0][0] = 1;
	a[0][1] = 2;
	a[1][0] = 1;

	TMatrix<int> b(3);
	b = a;

	EXPECT_EQ(a, b);
}


TEST(Matrix, matrix_with_equal_size_but_not_eaual)
{
	TMatrix<int> a(2);
	a[0][0] = 1;
	a[0][1] = 2;
	a[1][0] = 3;



	TMatrix<int> b(2);
	b[0][0] = 1;
	b[0][1] = 2;
	b[1][0] = 10;


	ASSERT_TRUE(a != b);
}

TEST(Matrix, equal_matrix_are_equal)
{
	TMatrix<int> a(2), b(2);
	a[0][0] = 1;
	a[0][1] = 2;
	a[1][0] = 3;

	b[0][0] = 1;
	b[0][1] = 2;
	b[1][0] = 3;


	ASSERT_TRUE(a == b);
}

TEST(Matrix, matrix_with_different_size_are_not_eaual)
{
	TMatrix<int> a(2), b(3);

	a[0][0] = 1;
	a[0][1] = 2;
	a[1][0] = 3;

	b[0][0] = 1;
	b[0][1] = 2;
	b[0][2] = 3;
	b[1][0] = 4;
	b[1][1] = 5;
	b[2][0] = 6;

	ASSERT_TRUE(a != b);
}



TEST(Matrix, can_add_matrix_with_equal_size)
{
	TMatrix<int> a(2);
	a[0][0] = 1;
	a[0][1] = 2;
	a[1][0] = 3;

	

	TMatrix<int> b(2);
	b[0][0] = 1;
	b[0][1] = 2;
	b[1][0] = 3;

	TMatrix<int> c(2);
	c[0][0] = 2;
	c[0][1] = 4;
	c[1][0] = 6;

	EXPECT_EQ(c, a+b);
}

TEST(Matrix, throws_when_add_matrix_with_different_size)
{
	TMatrix<int> a(2);
	a[0][0] = 1;
	a[0][1] = 2;
	a[1][0] = 3;

	TMatrix<int> b(100);

	ASSERT_ANY_THROW(a + b);
}


TEST(Matrix, can_substract_matrix_with_equal_size)
{
	TMatrix<int> a(2);
	a[0][0] = 1;
	a[0][1] = 2;
	a[1][0] = 3;

	TMatrix<int> b(2);
	b[0][0] = 1;
	b[0][1] = 2;
	b[1][0] = 3;

	TMatrix<int> c(2);
	c[0][0] = 0;
	c[0][1] = 0;
	c[1][0] = 0;

	EXPECT_EQ(c, a - b);
}

TEST(Matrix, throws_when_substract_matrix_with_different_size)
{
	TMatrix<int> a(2);
	a[0][0] = 1;
	a[0][1] = 2;
	a[1][0] = 3;

	TMatrix<int> b(100);

	ASSERT_ANY_THROW(a - b);
}


TEST(Matrix, can_multiply_matrix_with_equal_size)
{
	TMatrix<int> a(2);
	a[0][0] = 1;
	a[0][1] = 2;
	a[1][0] = 3;

	TMatrix<int> b(2);
	b[0][0] = 1;
	b[0][1] = 2;
	b[1][0] = 3;

	TMatrix<int> c(2);
	c[0][0] = 1;
	c[0][1] = 8;
	c[1][0] = 9;

	EXPECT_EQ(c, a * b);;
}

TEST(Matrix, throws_when_multiply_matrix_with_different_size)
{
	TMatrix<int> a(2);
	a[0][0] = 1;
	a[0][1] = 2;
	a[1][0] = 3;

	TMatrix<int> b(100);

	ASSERT_ANY_THROW(a * b);
}



TEST(Matrix, triple_assign)
{
	TMatrix<int> a(2);
	a[0][0] = 1;
	a[0][1] = 2;
	a[1][0] = 3;

	TMatrix<int> b(2);
	b[0][0] = 1;
	b[0][1] = 2;
	b[1][0] = 3;

	TMatrix<int> c(2);
	b = a;
	c = b;
	EXPECT_EQ(c,a);
}

