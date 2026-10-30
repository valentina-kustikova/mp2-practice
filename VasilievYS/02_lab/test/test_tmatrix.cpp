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
	ASSERT_NE(&m[0][0], &m1[0][0]);
}

TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix<int> m(5);
	EXPECT_EQ(5u, m.size());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> m(5);
	m[3][3] = 3;
	EXPECT_EQ(3, m[3][3]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	TDynamicMatrix<int> m(5);
	ASSERT_ANY_THROW(m.at(-1).at(2) = 2);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	TDynamicMatrix<int> m(5);
	ASSERT_ANY_THROW(m.at(5).at(3) = 2);
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
		for (int j = 0; j < 3; j++)
		{
			m[i][j] = i + j;
			m1[i][j] = 1;
			exp[i][j] = i + j + 1;
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
		for (int j = 0; j < 3; j++)
		{
			m[i][j] = i + j + 1;
			m1[i][j] = 1;
			exp[i][j] = i + j;
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
		for (int j = 0; j < 3; j++)
		{
			m[i][j] = 1;
			exp[i][j] = 1*val;
		}
	ASSERT_NO_THROW(m*val);
	EXPECT_TRUE((m*val) == exp);
}

TEST(TDynamicMatrix, can_multiply_matrix_by_vector)
{
	TDynamicMatrix<int> m(3);
	TDynamicVector<int> v(3), exp(3);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			m[i][j] = 1;
		}
		v[i] = i;
		exp[i] = 3;
	}
	ASSERT_NO_THROW(m * v);
	EXPECT_TRUE((m*v) == exp);
}

TEST(TDynamicMatrix, cant_multiply_matrix_and_vector_with_not_equal_size)
{
	TDynamicMatrix<int> m(3);
	TDynamicVector<int>v(4);
	ASSERT_ANY_THROW(m * v);
}

TEST(TDynamicMatrix, can_multiply_matrices_with_equal_size)
{
	TDynamicMatrix<int> a(2), b(2), exp(2);
	a[0][0] = 1; a[0][1] = 2;
	a[1][0] = 3; a[1][1] = 4;
	b[0][0] = 5; b[0][1] = 6;
	b[1][0] = 7; b[1][1] = 8;
	exp[0][0] = 19; exp[0][1] = 22;
	exp[1][0] = 43; exp[1][1] = 50;

	EXPECT_TRUE((a * b) == exp);
}

TEST(TDynamicMatrix, cant_multiply_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> m(3), m1(5);
	ASSERT_ANY_THROW(m * m1);
}