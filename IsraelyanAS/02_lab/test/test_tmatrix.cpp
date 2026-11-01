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
	TDynamicMatrix<int> m(3);
	for (size_t i = 0; i < 3; ++i) {
		for (size_t j = 0; j < m[i].size(); ++j) {
			m[i][j] = 1+j;
		}
	}
	TDynamicMatrix<int> copy(m);
	EXPECT_TRUE(copy == m);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	TDynamicMatrix<int> m(3);
	for (size_t i = 0; i < 3; ++i) {
		for (size_t j = 0; j < m[i].size(); ++j) {
			m[i][j] = 1 + j;
		}
	}
	TDynamicMatrix<int> copy(m);
	m[0][0] = 10;
	EXPECT_EQ(copy[0][0], 1);
}

TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix<int> m(4);
	EXPECT_EQ(4, m.size());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> m(4);
	m[0][0] = 4;

	EXPECT_EQ(4, m[0][0]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	TDynamicMatrix<int> m(10);
	ASSERT_ANY_THROW(m[-1][-1] = 10);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	TDynamicMatrix<int> m(10);
	ASSERT_ANY_THROW(m[10][10] = 10);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	TDynamicMatrix<int> m(3);
	for (size_t i = 0; i < 3; ++i) {
		for (size_t j = 0; j < m[i].size(); ++j) {
			m[i][j] = 1 + j;
		}
	}
	ASSERT_NO_THROW(m = m);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	TDynamicMatrix<int> m1(3);
	TDynamicMatrix<int> m2(3);
	for (size_t i = 0; i < 3; ++i) {
		for (size_t j = 0; j < m1[i].size(); ++j) {
			m1[i][j] = 1 + j;
		}
	}
	ASSERT_NO_THROW(m2 = m1);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	TDynamicMatrix<int> m1(1);
	TDynamicMatrix<int> m2(3);
	m2 = m1;
	EXPECT_EQ(m2.size(), m1.size());
	EXPECT_EQ(m2.size(), 1);
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	TDynamicMatrix<int> m1(3);
	TDynamicMatrix<int> m2(6);
	for (size_t i = 0; i < 3; ++i) {
		for (size_t j = 0; j < m1[i].size(); ++j) {
			m1[i][j] = 1 + j;
		}
	}
	ASSERT_NO_THROW(m2 = m1);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	TDynamicMatrix<int> m1(3);
	TDynamicMatrix<int> m2(3);
	for (size_t i = 0; i < 3; ++i) {
		for (size_t j = 0; j < m1[i].size(); ++j) {
			m1[i][j] = 1 + j;
			m2[i][j] = 1 + j;
		}
	}
	EXPECT_TRUE(m1 == m2);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	TDynamicMatrix<int> m(3);
	for (size_t i = 0; i < 3; ++i) {
		for (size_t j = 0; j < m[i].size(); ++j) {
			m[i][j] = 1 + j;
		}
	}
	EXPECT_TRUE(m == m);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	TDynamicMatrix<int> m1(3);
	TDynamicMatrix<int> m2(5);
	for (size_t i = 0; i < 3; ++i) {
		for (size_t j = 0; j < m1[i].size(); ++j) {
			m1[i][j] = 1 + j;
		}
	}
	for (size_t i = 0; i < 3; ++i) {
		for (size_t j = 0; j < m2[i].size(); ++j) {
			m2[i][j] = 1 + j;
		}
	}
	EXPECT_FALSE(m1 == m2);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	TDynamicMatrix<int> m1(3), m2(3), res(3);
	for (size_t i = 0; i < 3; ++i) {
		for (size_t j = 0; j < m1[i].size(); ++j) {
			m1[i][j] = 1 + j;
			m2[i][j] = 1 + j;
		}
	}
	ASSERT_NO_THROW(res = m1 + m2);
	for (size_t i = 0; i < 3; ++i) {
		for (size_t j = 0; j < res[i].size(); ++j) {
			EXPECT_EQ(res[i][j], m1[i][j] + m2[i][j]);
		}
	}
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> m1(3), m2(5);
	for (size_t i = 0; i < 3; ++i) {
		for (size_t j = 0; j < m1[i].size(); ++j) {
			m1[i][j] = 1 + j;
			
		}
	}
	for (size_t i = 0; i < 5; ++i) {
		for (size_t j = 0; j < m2[i].size(); ++j) {
			m2[i][j] = 1 + j;
		}
	}
	EXPECT_ANY_THROW(m1 + m2);
	EXPECT_ANY_THROW(m2 + m1);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	TDynamicMatrix<int> m1(3), m2(3), res(3);
	for (size_t i = 0; i < 3; ++i) {
		for (size_t j = 0; j < m1[i].size(); ++j) {
			m1[i][j] = 1 + j;
			m2[i][j] = 1 + j;
		}
	}
	ASSERT_NO_THROW(res = m1 - m2);
	ASSERT_NO_THROW(res = m2 - m1);
	for (size_t i = 0; i < 3; ++i) {
		for (size_t j = 0; j < res[i].size(); ++j) {
			EXPECT_EQ(res[i][j], m1[i][j] - m2[i][j]);
		}
	}
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> m1(3), m2(5);
	for (size_t i = 0; i < 3; ++i) {
		for (size_t j = 0; j < m1[i].size(); ++j) {
			m1[i][j] = 1 + j;
		}
	}
	for (size_t i = 0; i < 5; ++i) {
		for (size_t j = 0; j < m2[i].size(); ++j) {
			m2[i][j] = 1 + j;
		}
	}
	EXPECT_ANY_THROW(m1 - m2);
	EXPECT_ANY_THROW(m2 - m1);
}

