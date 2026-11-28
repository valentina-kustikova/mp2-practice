#include "tmatrix.h"

#include <gtest\gtest.h>

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
	TDynamicMatrix<int> m1(5);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5 - i; j++) {
			m1[i][j] = i * 5 + j + 1;
		}
	}
	TDynamicMatrix<int> m2(m1);
	EXPECT_TRUE(m1 == m2);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	TDynamicMatrix<int> m1(5);
	m1[0][2] = 3;
	TDynamicMatrix<int> m2(m1);
	m2[0][2] = 10;
	EXPECT_EQ(m1[0][2], 3);
}

TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix<int> m(5);
	EXPECT_EQ(5, m.size());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> m(5);
	m[0][0] = 4;
	EXPECT_EQ(4, m[0][0]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	TDynamicMatrix<int> m(5);
	ASSERT_ANY_THROW(m.at(-3).at(-3) = 5);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	TDynamicMatrix<int> m(5);
	ASSERT_ANY_THROW(m.at(5).at(5) = 5);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	TDynamicMatrix<int> m(5);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5 - i; j++) {
			m[i][j] = i * 5 + j + 1;
		}
	}
	ASSERT_NO_THROW(m = m);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	TDynamicMatrix<int> m1(5);
	TDynamicMatrix<int> m2(5);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5 - i; j++) {
			m1[i][j] = i * 5 + j + 1;
		}
	}
	m2 = m1;
	EXPECT_EQ(m1, m2);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	TDynamicMatrix<int> m1(3);
	TDynamicMatrix<int> m2(5);
	m1 = m2;
	EXPECT_EQ(m1.size(), m2.size());
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	TDynamicMatrix<int> m1(3);
	TDynamicMatrix<int> m2(5);
	ASSERT_NO_THROW(m1 = m2);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	TDynamicMatrix<int> m1(5);
	TDynamicMatrix<int> m2(5);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5 - i; j++) {
			m1[i][j] = i * 5 + j + 1;
			m2[i][j] = i * 5 + j + 1;
		}
	}
	EXPECT_TRUE(m1 == m2);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	TDynamicMatrix<int> m(5);
	EXPECT_TRUE(m == m);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	TDynamicMatrix<int> m1(5);
	TDynamicMatrix<int> m2(3);
	EXPECT_FALSE(m1 == m2);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	TDynamicMatrix<int> m1(5);
	TDynamicMatrix<int> m2(5);
	TDynamicMatrix<int> result(5);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5 - i; j++) {
			m1[i][j] = i * 5 + j + 1;
			m2[i][j] = i * 5 + j + 2;
			result[i][j] = 2 * (i * 5 + j) + 3;
		}
	}
	EXPECT_EQ(m1 + m2, result);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> m1(5), m2(3);
	ASSERT_ANY_THROW(m1 + m2);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	TDynamicMatrix<int> m1(5);
	TDynamicMatrix<int> m2(5);
	TDynamicMatrix<int> result(5);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5 - i; j++) {
			m1[i][j] = i * 5 + j + 3;
			m2[i][j] = i * 5 + j + 2;
			result[i][j] = 1;
		}
	}
	EXPECT_EQ(m1 - m2, result);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> m1(5), m2(3);
	ASSERT_ANY_THROW(m1 - m2);
}

TEST(TDynamicMatrix, can_multiply_matrix_by_scalar)
{
	TDynamicMatrix<int> m(3);
	TDynamicMatrix<int> result(3);

	m[0][0] = 1; m[0][1] = 2; m[0][2] = 3;
	m[1][0] = 4; m[1][1] = 5; m[2][0] = 6;

	result[0][0] = 2; result[0][1] = 4; result[0][2] = 6;
	result[1][0] = 8; result[1][1] = 10; result[2][0] = 12;

	EXPECT_EQ(m * 2, result);
}

TEST(TDynamicMatrix, can_multiply_matrix_by_vector)
{
	TDynamicMatrix<int> m(3);
	TDynamicVector<int> v(3);
	TDynamicVector<int> result(3);

	v[0] = 1; v[1] = 2; v[2] = 3;

	m[0][0] = 1; m[0][1] = 2; m[0][2] = 3;
	m[1][0] = 4; m[1][1] = 5; m[2][0] = 6;

	result[0] = 14; result[1] = 23; result[2] = 18;

	EXPECT_EQ(m * v, result);
}

TEST(TDynamicMatrix, cant_multiply_matrix_and_vector_with_not_equal_size)
{
	TDynamicMatrix<int> m(3);
	TDynamicVector<int> v(2);
	ASSERT_ANY_THROW(m * v);
}

TEST(TDynamicMatrix, can_multiply_matrices_with_equal_size)
{
	TDynamicMatrix<int> m1(3), m2(3), result(3);
	m1[0][0] = 1; m1[0][1] = 2; m1[0][2] = 3;
	m1[1][0] = 4; m1[1][1] = 5; m1[2][0] = 6;

	m2[0][0] = 12; m2[0][1] = 11; m2[0][2] = 10;
	m2[1][0] = 9; m2[1][1] = 8; m2[2][0] = 7;

	result[0][0] = 12; result[0][1] = 29; result[0][2] = 47;
	result[1][0] = 36; result[1][1] = 67; result[2][0] = 42;

	EXPECT_EQ(m1 * m2, result);
}

TEST(TDynamicMatrix, cant_multiply_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> m1(3), m2(2);
	ASSERT_ANY_THROW(m1 * m2);
}