#include "tmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
	ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
	ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
	TMatrix<int> m(5);

	ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, check_copied)
{
	TMatrix<int> m(3);
	TMatrix<int> m1(m);
	EXPECT_EQ(m, m1);
}
TEST(TMatrix, check_copied_that_diff_view)
{
	TMatrix<int> m(3);
	TMatrix<int> m1(m);
	m[0][0] = 2;
	EXPECT_NE(m, m1);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m(5);
	EXPECT_EQ(5, m.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> m(5);
	m[1][2] = 3;
	EXPECT_EQ(3, m[1][2]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m(5);
	ASSERT_ANY_THROW(m[-1][1] = 1);
}
TEST(TMatrix, throws_when_set_element_with_negative_index_2)
{
	TMatrix<int> m(5);
	ASSERT_ANY_THROW(m[1][-1] = 1);
}
TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> m(5);
	ASSERT_ANY_THROW(m[6][1] = 1);
}
TEST(TMatrix, throws_when_set_element_with_too_large_index_2)
{
	TMatrix<int> m(5);
	ASSERT_ANY_THROW(m[1][6] = 1);
}

TEST(TMatrix, matrix_are_not_equal)
{
	TMatrix<int> m1(4);
	TMatrix<int> m2(3);

	ASSERT_TRUE(m1 != m2);
}

TEST(TMatrix, an_equality_matrix_true_check)
{
	TMatrix <int> m1(3), m2(3);

	for (int i = 0; i < m1.GetSize(); i++)
		for (int j = 0; j < m1.GetSize() - i; j++)
		{
			m1[i][j] = i * 2;
			m2[i][j] = i * 2;
		}

	ASSERT_TRUE(m1 == m2);
}

TEST(TMatrix, an_equality_matrix_with_diff_size)
{
	TMatrix <int> m1(5), m2(3);

	ASSERT_FALSE(m1 == m2);
}

TEST(TMatrix, an_inequality_matrix_true_check)
{
	TMatrix <int> m1(5), m2(5);

	for (int i = 0; i < m1.GetSize(); i++)
		for (int j = 0; j < m2.GetSize() - i; j++)
		{
			m1[i][j] = i;
			m2[i][j] = i + j;
		}

	ASSERT_TRUE(m1 != m2);
}


TEST(TMatrix, can_add_matrix_with_equal_size)
{
	TMatrix<int> m1(3);
	TMatrix<int> m2(3);
	TMatrix<int> m3(3);
	m1[1][1] = 1;
	m2[1][1] = 1;
	m3[1][1] = 2;
	m2 = m1 + m2;
	EXPECT_EQ(m3[1][1], m2[1][1]);
}

TEST(TMatrix, cant_plus_with_not_equal_size)
{
	TMatrix<int> m1(4);
	TMatrix<int> m2(5);

	ASSERT_ANY_THROW(m1 + m2);
}

TEST(TMatrix, summ_is_correct)
{
	TMatrix<int> m1(2), m2(2), m(2);

	for (int i = 0; i < m1.GetSize(); i++)
		for (int j = 0; j < m1.GetSize() - i; j++)
		{
			m1[i][j] = i;
			m2[i][j] = j;
			m[i][j] = i+j;
		}
	EXPECT_EQ(m, m1 + m2);
}
TEST(TMatrix, cant_minus_with_not_equal_size)
{
	TMatrix<int> m1(3);
	TMatrix<int> m2(4);
\
	ASSERT_ANY_THROW(m1 - m2);
}

TEST(TMatrix, minus_is_correct)
{
	TMatrix<int> m1(3), m2(3), m(3);

	for (int i = 0; i < m1.GetSize(); i++)
		for (int j = 0; j < m1.GetSize() - i; j++)
		{
			m1[i][j] = i;
			m2[i][j] = j;
			m[i][j] = i-j;
		}
	EXPECT_EQ(m, m1 - m2);
}

TEST(TMatrix, can_mult_matrix)
{
	TMatrix <int> m1(2), m2(2), res(2);

	m1[0][0] = 1;
	m1[0][1] = 2;
	m1[1][0] = 3;

	m2[0][0] = 1;
	m2[0][1] = 2;
	m2[1][0] = 3;

	res[0][0] = 1;
	res[0][1] = 8;
	res[1][0] = 9;

	ASSERT_TRUE(res == m1 * m2);
}

TEST(TMatrix, can_mult_with_equal_size)
{
	TMatrix<int> m1(3);
	TMatrix<int> m2(3);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3 - i; j++)
		{
			m1[i][j] = 1;
			m2[i][j] = 2;

		}
	ASSERT_NO_THROW(m1 * m2);
}

TEST(TMatrix, cant_mult_with_not_equal_size)
{
	TMatrix<int> m1(4);
	TMatrix<int> m2(5);
	ASSERT_ANY_THROW(m1 * m2);
}