#include "tmatrix.h"

#include <gtest.h>

TEST(Matrix, can_create_matrix_with_positive_size)
{
	ASSERT_NO_THROW(TMatrix<int> m(10) );
}

TEST(Matrix, throws_when_create_matrix_with_negative_size)
{
	ASSERT_ANY_THROW(TMatrix<int> m(-3));
}


TEST(Matrix, can_create_copy_of_the_matrix)
{
	TMatrix<int> a(2);
	Vector<int> av(2), bv(1);
	av[0] = 1;
	av[1] = 2;

	bv[0] = 4;

	a[0] = av;
	a[1] = bv;
	 
	TMatrix<int> b(a);

	EXPECT_EQ(4, b[1][0]);
}

TEST(Matrix, can_assign_matrix_with_equal_size)
{
	TMatrix<int> a(2);
	Vector<int> av(2), bv(1);
	av[0] = 1;
	av[1] = 2;

	bv[0] = 4;

	a[0] = av;
	a[1] = bv;

	TMatrix<int> b(2);
	b = a;

	EXPECT_EQ(4, b[1][0]);
}


TEST(Matrix, can_assign_matrix_with_not_equal_size)
{
	TMatrix<int> a(2);
	Vector<int> av(2), bv(1);
	av[0] = 1;
	av[1] = 2;

	bv[0] = 4;

	a[0] = av;
	a[1] = bv;

	TMatrix<int> b(100);
	b = a;

	EXPECT_EQ(4, b[1][0]);
}


TEST(Matrix, matrix_with_equal_size_but_not_eaual)
{
	TMatrix<int> a(2);
	Vector<int> av1(2), av2(1);
	av1[0] = 1;
	av1[1] = 2;

	av2[0] = 4;

	a[0] = av1;
	a[1] = av2;


	TMatrix<int> b(2);
	Vector<int> bv1(2), bv2(1);
	bv1[0] = 100;
	bv1[1] = 100;

	bv2[0] = 100;

	b[0] = bv1;
	b[1] = bv2;


	EXPECT_NE(a, b);
}

TEST(Matrix, equal_matrix_are_equal)
{
	TMatrix<int> a(2);
	Vector<int> av1(2), av2(1);
	av1[0] = 1;
	av1[1] = 2;

	av2[0] = 4;

	a[0] = av1;
	a[1] = av2;

	TMatrix<int> b(2);
	Vector<int> bv1(2), bv2(1);
	bv1[0] = 1;
	bv1[1] = 2;

	bv2[0] = 4;

	b[0] = bv1;
	b[1] = bv2;

	EXPECT_EQ(a, b);
}

TEST(Matrix, matrix_with_different_size_are_not_eaual)
{
	TMatrix<int> a(2);
	Vector<int> av(2), bv(1);
	av[0] = 1;
	av[1] = 2;

	bv[0] = 4;

	a[0] = av;
	a[1] = bv;

	TMatrix<int> b(100);
	
	EXPECT_NE(a, b);
}



TEST(Matrix, can_add_matrix_with_equal_size)
{
	TMatrix<int> a(2);
	Vector<int> av1(2), av2(1);
	av1[0] = 1;
	av1[1] = 2;

	av2[0] = 4;

	a[0] = av1;
	a[1] = av2;

	TMatrix<int> b(2);
	Vector<int> bv1(2), bv2(1);
	bv1[0] = 1;
	bv1[1] = 2;

	bv2[0] = 4;

	b[0] = bv1;
	b[1] = bv2;

	TMatrix<int> c(2);
	c = a + b;
	EXPECT_EQ(8, c[1][0]);
}

TEST(Matrix, throws_when_add_matrix_with_different_size)
{
	TMatrix<int> a(2);
	Vector<int> av1(2), av2(1);
	av1[0] = 1;
	av1[1] = 2;

	av2[0] = 4;

	a[0] = av1;
	a[1] = av2;

	TMatrix<int> b(100);

	ASSERT_ANY_THROW(a + b);
}


TEST(Matrix, can_substract_matrix_with_equal_size)
{
	TMatrix<int> a(2);
	Vector<int> av1(2), av2(1);
	av1[0] = 1;
	av1[1] = 2;

	av2[0] = 8;

	a[0] = av1;
	a[1] = av2;

	TMatrix<int> b(2);
	Vector<int> bv1(2), bv2(1);
	bv1[0] = 1;
	bv1[1] = 2;

	bv2[0] = 4;

	b[0] = bv1;
	b[1] = bv2;

	TMatrix<int> c(2);
	c = a - b;
	EXPECT_EQ(4, c[1][0]);
}

TEST(Matrix, throws_when_substract_matrix_with_different_size)
{
	TMatrix<int> a(2);
	Vector<int> av1(2), av2(1);
	av1[0] = 1;
	av1[1] = 2;

	av2[0] = 4;

	a[0] = av1;
	a[1] = av2;

	TMatrix<int> b(100);

	ASSERT_ANY_THROW(a - b);
}


TEST(Matrix, can_multiply_matrix_with_equal_size)
{
	TMatrix<int> a(2);
	Vector<int> av1(2), av2(1);
	av1[0] = 1;
	av1[1] = 2;

	av2[0] = 4;

	a[0] = av1;
	a[1] = av2;

	TMatrix<int> b(2);
	Vector<int> bv1(2), bv2(1);
	bv1[0] = 1;
	bv1[1] = 2;

	bv2[0] = 4;

	b[0] = bv1;
	b[1] = bv2;

	TMatrix<int> c(2);
	c = a * b;
	EXPECT_EQ(16, c[1][0]);
}

TEST(Matrix, throws_when_multiply_matrix_with_different_size)
{
	TMatrix<int> a(2);
	Vector<int> av1(2), av2(1);
	av1[0] = 1;
	av1[1] = 2;

	av2[0] = 4;

	a[0] = av1;
	a[1] = av2;

	TMatrix<int> b(100);

	ASSERT_ANY_THROW(a * b);
}



TEST(Matrix, triple_assign)
{
	TMatrix<int> a(2);
	Vector<int> av1(2), av2(1);
	av1[0] = 50;
	av1[1] = 2;

	av2[0] = 100;

	a[0] = av1;
	a[1] = av2;

	TMatrix<int> b(2);
	Vector<int> bv1(2), bv2(1);
	bv1[0] = 1;
	bv1[1] = 2;

	bv2[0] = 4;

	b[0] = bv1;
	b[1] = bv2;

	TMatrix<int> c(2);
	b = a;
	c = b;
	EXPECT_EQ(50, c[0][0]);
}

