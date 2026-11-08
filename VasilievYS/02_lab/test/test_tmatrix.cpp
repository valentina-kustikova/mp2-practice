#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
	ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
	ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
	ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
	TDynamicMatrix<int> m(5);

	ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
	TDynamicMatrix<int> m(5);
	TDynamicMatrix<int> m1(m);
	EXPECT_TRUE(m1 == m);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	TDynamicMatrix<int> m(5);
	TDynamicMatrix<int> m1(m);
	ASSERT_NE(&m(0, 0), &m1(0, 0));
}

TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix<int> m(5);
	EXPECT_EQ(5u, m.size());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> m(5);
	m(3, 4) = 3;
	EXPECT_EQ(3, m(3, 4));
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	TDynamicMatrix<int> m(5);
	ASSERT_ANY_THROW(m(-1, 2) = 2);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_row_index)
{
	TDynamicMatrix<int> m(5);
	ASSERT_ANY_THROW(m(5, 3) = 2);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_column_index)
{
	TDynamicMatrix<int> m(5);
	ASSERT_ANY_THROW(m(2, 5) = 2);
}

TEST(TDynamicMatrix, throws_when_set_element_below_main_diagonal)
{
	TDynamicMatrix<int> m(5);
	ASSERT_ANY_THROW(m(3, 1) = 2);
}

TEST(TDynamicMatrix, element_below_main_diagonal_of_const_matrix_is_zero)
{
	TDynamicMatrix<int> m(5);
	m(1, 1) = 4;
	const TDynamicMatrix<int> cm(m);
	EXPECT_EQ(0, cm(3, 1));
	EXPECT_EQ(4, cm(1, 1));
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	TDynamicMatrix<int> m(5);
	ASSERT_NO_THROW(m = m);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	TDynamicMatrix<int> m(5);
	TDynamicMatrix<int> m1(5);
	ASSERT_NO_THROW(m1 = m);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	TDynamicMatrix<int> m(3);
	TDynamicMatrix<int> m1(5);
	m1 = m;
	EXPECT_EQ(m1.size(), 3u);
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	TDynamicMatrix<int> m(3);
	TDynamicMatrix<int> m1(5);
	ASSERT_NO_THROW(m1 = m);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	TDynamicMatrix<int> m(3);
	TDynamicMatrix<int> m1(5);
	m1 = m;
	EXPECT_TRUE(m1 == m);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	TDynamicMatrix<int> m(3);
	EXPECT_TRUE(m == m);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	TDynamicMatrix<int> m(3);
	TDynamicMatrix<int> m1(5);
	EXPECT_FALSE(m1 == m);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	TDynamicMatrix<int> m(3), m1(3), exp(3);
	for (int i = 0; i < 3; i++)
		for (int j = i; j < 3; j++)
		{
			m(i, j) = i + j;
			m1(i, j) = 1;
			exp(i, j) = i + j + 1;
		}
	EXPECT_TRUE(exp == (m + m1));
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> m(3), m1(5);
	ASSERT_ANY_THROW(m + m1);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	TDynamicMatrix<int> m(3), m1(3), exp(3);
	for (int i = 0; i < 3; i++)
		for (int j = i; j < 3; j++)
		{
			m(i, j) = i + j + 1;
			m1(i, j) = 1;
			exp(i, j) = i + j;
		}
	EXPECT_TRUE(exp == (m - m1));
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> m(3), m1(5);
	ASSERT_ANY_THROW(m - m1);
}

TEST(TDynamicMatrix, can_multiply_matrix_by_scalar)
{
	TDynamicMatrix<int> m(3), exp(3);
	int val = 3;
	for (int i = 0; i < 3; i++)
		for (int j = i; j < 3; j++)
		{
			m(i, j) = 1;
			exp(i, j) = 1 * val;
		}
	EXPECT_TRUE((m * val) == exp);
}

TEST(TDynamicMatrix, can_multiply_matrix_by_vector)
{
	TDynamicMatrix<int> m(3);
	TDynamicVector<int> v(3), exp(3);
	for (int i = 0; i < 3; i++)
	{
		for (int j = i; j < 3; j++)
			m(i, j) = 1;
		v[i] = i;
	}
	exp[0] = 3;
	exp[1] = 3;
	exp[2] = 2;
	EXPECT_TRUE((m * v) == exp);
}

TEST(TDynamicMatrix, cant_multiply_matrix_and_vector_with_not_equal_size)
{
	TDynamicMatrix<int> m(3);
	TDynamicVector<int> v(4);
	ASSERT_ANY_THROW(m * v);
}

TEST(TDynamicMatrix, can_multiply_matrices_with_equal_size)
{
	// | 1 2 |   | 4 5 |   | 4 17 |
	// | 0 3 | * | 0 6 | = | 0 18 |
	TDynamicMatrix<int> a(2), b(2), exp(2);
	a(0, 0) = 1; a(0, 1) = 2;
				 a(1, 1) = 3;
	b(0, 0) = 4; b(0, 1) = 5;
	             b(1, 1) = 6;
	exp(0, 0) = 4; exp(0, 1) = 17;
	               exp(1, 1) = 18;
	EXPECT_TRUE((a * b) == exp);
}

TEST(TDynamicMatrix, cant_multiply_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> m(3), m1(5);
	ASSERT_ANY_THROW(m * m1);
}