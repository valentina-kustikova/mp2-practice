#include "TMatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_size)
{
	ASSERT_NO_THROW(TMatrix<int> m(3));
}

TEST(TMatrix, can_create_matrix_with_zero_size) 
{
	ASSERT_ANY_THROW(TMatrix<int> m(0));
}

TEST(TMatrix, create_matrix_with_negative_size)
{
	ASSERT_ANY_THROW(TMatrix<int> m(-3));
}

TEST(TMatrix, copy_constructor_test)
{
	TMatrix<int> m(3);
	ASSERT_NO_THROW(TMatrix<int> matrix(m));
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m(3);
	EXPECT_EQ(3, m.GetSize());
}

TEST(TMatrix, can_get_start_index)
{
	TMatrix<int> m(3);
	EXPECT_EQ(1, m[1].GetStart());
}
//index
TEST(TMatrix, index_test_matrix)
{
	TMatrix<int> m(3);
	for (int i = 0; i < 3; i++)
		for (int j = i; j < 3; j++)
			m[i][j] = i + j + 1;

	TVector<int> vec2(2, 1);
	for (int i = 1; i < 3; i++)
		vec2[i] = i + 2;
	EXPECT_EQ(vec2, m[1]);
}

TEST(TMatrix, index_test_matrix_value)
{
	TMatrix<int> m(3);
	for (int i = 0; i < 3; i++)
		for (int j = i; j < 3; j++)
			m[i][j] = i + j + 1;

	EXPECT_EQ(3, m[1][1]);
}

TEST(TMatrix, large_index_test)
{
	TMatrix<int> m(3);

	ASSERT_ANY_THROW(m[3]);
}

TEST(TMatrix, large_index_vector_test)
{
	TMatrix<int> m(3);

	ASSERT_ANY_THROW(m[0][4]);
}

TEST(TMatrix, negative_index)
{
	TMatrix<int> m(3);

	ASSERT_ANY_THROW(m[-1]);
}

TEST(TMatrix, less_than_start_index)
{
	TMatrix<int> m(3);

	ASSERT_ANY_THROW(m[1][0]);
}
//equal
TEST(TMatrix, comparison_for_equality_true)
{
	TMatrix<int> m1(3);
	TMatrix<int> m2(3);
	for (int i = 0; i < 3; i++)
		for (int j = i; j < 3; j++)
		{
			m1[i][j] = i + 1;
			m2[i][j] = i + 1;
		}

	EXPECT_EQ(1, m1 == m2);
}

TEST(TMatrix, comparison_for_equality_false)
{
	TMatrix<int> m1(3);
	TMatrix<int> m2(3);
	for (int i = 0; i < 3; i++)
		for (int j = i; j < 3; j++) {
			m1[i][j] = i + 1;
			m2[i][j] = i + 2;
		}
	EXPECT_EQ(0, m1 == m2);
}

TEST(TMatrix, comparison_for_equality_with_diferent_size)
{
	TMatrix<int> m1(3);
	TMatrix<int> m2(4);

	EXPECT_EQ(0, m1 == m2);
}
//inequal
TEST(TMatrix, comparison_for_inequality_true)
{
	TMatrix<int> m1(3);
	TMatrix<int> m2(3);
	for (int i = 0; i < 3; i++)
		for (int j = i; j < 3; j++)
		{
			m1[i][j] = i + 1;
			m2[i][j] = i + 2;
		}

	EXPECT_EQ(1, m1 != m2);
}

TEST(TMatrix, comparison_for_inequality_false)
{
	TMatrix<int> m1(3);
	TMatrix<int> m2(3);
	for (int i = 0; i < 3; i++)
		for (int j = i; j < 3; j++) 
		{
			m1[i][j] = i + 1;
			m2[i][j] = i + 1;
		}
	EXPECT_EQ(0, m1 != m2);
}

TEST(TMatrix, comparison_for_inequality_with_diferent_size)
{
	TMatrix<int> m1(3);
	TMatrix<int> m2(4);

	EXPECT_EQ(1, m1 != m2);
}
//operator=
TEST(TMatrix, assignment_check)
{
	TMatrix<int> m1(3);
	TMatrix<int> m2(3);
	for (int i = 0; i < 3; i++)
		for (int j = i; j < 3; j++) 
		{
			m1[i][j] = i + 1;
			m2[i][j] = i + 1;
		}
	m1 = m2;

	EXPECT_EQ(m2, m1);
}

TEST(TMatrix, assignment_with_different_size)
{
	TMatrix<int> m1(3);
	TMatrix<int> m2(4);

	for (int i = 0; i < 4; i++)
		for (int j = i; j < 4; j++) 
			m2[i][j] = i + 1;

	m1 = m2;

	EXPECT_EQ(m2, m1);
}
//+matrix
TEST(TMatrix, matrix_plus_matrix) 
{
	TMatrix<int> m1(3);
	TMatrix<int> m2(3);
	TMatrix<int> res(3);

	for (int i = 0; i < 3; i++)
		for (int j = i; j < 3; j++)
		{
			m1[i][j] = 1;
			m2[i][j] = 2;
			res[i][j] = 3;
		}

	EXPECT_EQ(res, m1 + m2);
}

TEST(TMatrix, exception_matrix_plus_matrix) 
{
	TMatrix<int> m1(3);
	TMatrix<int> m2(4);

	ASSERT_ANY_THROW(m1 + m2);
}
//-matrix
TEST(TMatrix, matrix_minus_matrix) 
{
	TMatrix<int> m1(3);
	TMatrix<int> m2(3);
	TMatrix<int> res(3);

	for (int i = 0; i < 3; i++)
		for (int j = i; j < 3; j++)
		{
			m1[i][j] = 3;
			m2[i][j] = 1;
			res[i][j] = 2;
		}

	EXPECT_EQ(res, m1 - m2);
}

TEST(TMatrix, exception_matrix_minus_matrix)
{
	TMatrix<int> m1(3);
	TMatrix<int> m2(4);

	ASSERT_ANY_THROW(m1 - m2);
}
//*matrix
TEST(TMatrix, matrix_multiply_matrix)
{
	TMatrix<int> m1(3);
	TMatrix<int> m2(3);
	TMatrix<int> res(3);

	for (int i = 0; i < 3; i++)
		for (int j = i; j < 3; j++)
		{
			m1[i][j] = 1;
			m2[i][j] = 3;
		}

	res[0][0] = 3;
	res[0][1] = 6;
	res[0][2] = 9;
	res[1][1] = 3;
	res[1][2] = 6;
	res[2][2] = 3;

	EXPECT_EQ(res, m1 * m2);
}

TEST(TMatrix, exception_matrix_multiply_matrix) 
{
	TMatrix<int> m1(3);
	TMatrix<int> m2(4);

	ASSERT_ANY_THROW(m1 * m2);
}