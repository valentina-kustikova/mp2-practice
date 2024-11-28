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
	int size = 5;
	TDynamicMatrix<int> m(size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i; j++)
		{
			m[i][j] = i + j;
		}
	}
	TDynamicMatrix<int> m1(m);

	EXPECT_EQ(m, m1);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	const int size = 5;
	TDynamicMatrix<int> m1(size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i; j++)
		{
			m1[i][j] = i + j;
		}
	}
	TDynamicMatrix<int> m2(m1);
	m1[0][0] = 10000;

	EXPECT_NE(m1, m2);
}

TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix<int> m(4);

	EXPECT_EQ(4, m.size());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> m(4);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4 - i; j++)
		{
			m[i][j] = 1;
		}
	}
	m[0][0] = 2;
	EXPECT_EQ(2, m[0][0]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
  TDynamicMatrix<int> m(4);
  ASSERT_ANY_THROW(m.at(-1, -1));
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	TDynamicMatrix<int> m(4);
	ASSERT_ANY_THROW(m.at(MAX_MATRIX_SIZE+1, MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	TDynamicMatrix<int> m(4);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4 - i; j++)
		{
			m[i][j] = 1;
		}
	}
	ASSERT_NO_THROW(m = m);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	TDynamicMatrix<int> m(4), m2(4);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4 - i; j++)
		{
			m[i][j] = 1;
		}
	}
	m2 = m;
	EXPECT_EQ(m, m2);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	TDynamicMatrix<int> m(4), m2(3);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4 - i; j++)
		{
			m[i][j] = 1;
		}
	}
	m2 = m;
	EXPECT_EQ(m.size(), m2.size());
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	TDynamicMatrix<int> m(4), m2(3);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4 - i; j++)
		{
			m[i][j] = 1;
		}
	}
	m2 = m;
	EXPECT_EQ(m, m2);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	TDynamicMatrix<int> m(4), m2(4);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4 - i; j++)
		{
			m[i][j] = 1;
		}
	}
	m2 = m;
	EXPECT_TRUE(m2 == m);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	TDynamicMatrix<int> m(4);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4 - i; j++)
		{
			m[i][j] = 1;
		}
	}
	EXPECT_TRUE(m == m);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	TDynamicMatrix<int> m(4), m2(5);
	EXPECT_FALSE(m2 == m);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	TDynamicMatrix<int> m(4), m2(4), m3(4);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4 - i; j++)
		{
			m[i][j] = 1;
			m2[i][j] = 3;
			m3[i][j] = 4;
		}
	}
	EXPECT_EQ(m3, m + m2);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> m(4), m2(5);
	ASSERT_ANY_THROW(m + m2);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	TDynamicMatrix<int> m1(3), m2(3), m3(3);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3 - i; j++)
		{
			m1[i][j] = 1;
			m2[i][j] = 1;
			m3[i][j] = j+1;
		}
	}	
	EXPECT_EQ(m3, m1 * m2);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> m(4), m2(5);
	ASSERT_ANY_THROW(m * m2);
}

TEST(TDynamicMatrix, can_multiply_matrix_by_vector)
{
	TDynamicMatrix<int> m1(2);
	TDynamicVector<int> v1(2), v2(2), v3(2);
	for (int i = 0; i < 2; i++)
	{
		v1[i] = 19;
		for (int j = 0; j < 2 - i; j++)
		{
			m1[i][j] = i+j+1;
		}
	}
	v2 = m1 * v1;
	v3[0] = 57;
	v3[1] = 38;
	EXPECT_EQ(v2, v3);
}

TEST(TDynamicMatrix, cant_multiply_matrix_by_vector)
{
	TDynamicMatrix<int> m1(2);
	TDynamicVector<int> v1(3);
	ASSERT_ANY_THROW(m1*v1);
}

TEST(TDynamicMatrix, can_multiply_matrix_by_matrix)
{
	TDynamicMatrix<int> m1(2), m2(2), m3(2), m_res(2);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2 - i; j++)
		{
			m1[i][j] = i + j + 1;
			m2[i][j] = 3;
		}
	}
	m3[0][0] = 3;
	m3[0][1] = 9;
	m3[1][0] = 6;

	m_res = m1 * m2;

	EXPECT_EQ(m3, m_res);
}

TEST(TDynamicMatrix, cant_multiply_matrix_by_matrix)
{
	TDynamicMatrix<int> m1(2), m2(4);
	ASSERT_ANY_THROW(m1 * m2);
}