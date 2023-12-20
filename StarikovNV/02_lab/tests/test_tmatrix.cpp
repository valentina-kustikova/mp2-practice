#include "tmatrix.h"
#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
	ASSERT_NO_THROW(TMatrix<int> m(3));
}

TEST(TMatrix, when_create_matrix_with_negative_length_false)
{
	ASSERT_ANY_THROW(TMatrix<int> m(-2));
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m(3);
	EXPECT_EQ(3, m.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix <int> m(2);
	m[0][0] = 1;
	m[0][1] = 2;
	m[1][0] = 3;
	EXPECT_EQ(3, m[1][0]);
}

TEST(TMatrix, can_create_copied_matrix)
{
	TMatrix<int> m(2);
	m[0][0] = 1;
	m[0][1] = 1;
	m[1][0] = 1;
	ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source)
{
	TMatrix <int> m1(2);
	m1[0][0] = 1;
	m1[0][1] = 1;
	m1[1][0] = 1;
	TMatrix<int> m2(m1);
	ASSERT_TRUE(m1 == m2);
}

TEST(TMatrix, copied_matrix_has_their_own_memory)
{

	TMatrix <int> m1(2);
	m1[0][0] = 1;
	m1[0][1] = 1;
	m1[1][0] = 1;
	TMatrix <int> m2(m1);
	m1[0][0] = 2;
	ASSERT_FALSE(m1 == m2);
}

TEST(TMatrix, when_set_element_with_negative_index_false)
{
	TMatrix <int> m(2);
	m[0][0] = 1;
	m[0][1] = 2;
	m[1][0] = 3;
	ASSERT_ANY_THROW(m[-1][-1] = 1);
}

TEST(TMatrix, compare_equal_matrix)
{
	TMatrix <int> m(2);
	m[0][0] = 1;
	m[0][1] = 2;
	m[1][0] = 3;
	TMatrix <int> m1(2);
	m1[0][0] = 1;
	m1[0][1] = 2;
	m1[1][0] = 3;
	ASSERT_TRUE(m == m1);
}

TEST(TMatrix, compare_matrix_with_itself_true)
{
	TMatrix <int> m(2);
	m[0][0] = 1;
	m[0][1] = 2;
	m[1][0] = 3;
	ASSERT_TRUE(m == m);
}

TEST(TMatrix, may_assign_the_matrix_to_itself)
{
	TMatrix<int>m(2);
	m[0][0] = 1;
	m[0][1] = 2;
	m[1][0] = 3;
	ASSERT_NO_THROW(m = m);
}


TEST(TMatrix, can_assign_matrix_of_different_size)
{

	TMatrix <int> m(2);
	m[0][0] = 1;
	m[0][1] = 2;
	m[1][0] = 3;
	TMatrix <int> m1(1);
	m1[0][0] = 3;
	m1 = m;
	EXPECT_EQ(m, m1);
}

TEST(TMatrix, matrix_with_different_size_not_equal)
{
	TMatrix <int> m(2);
	m[0][0] = 1;
	m[0][1] = 2;
	m[1][0] = 3;
	TMatrix <int> m1(1);
	m1[0][0] = 2;
	ASSERT_FALSE(m == m1);
}

TEST(TMatrix, can_addit_matrices_with_equal_size)
{
	TMatrix <int> m1(2);
	m1[0][0] = 1;
	m1[0][1] = 2;
	m1[1][0] = 3;
	TMatrix <int> m2(2);
	m2[0][0] = 1;
	m2[0][1] = 2;
	m2[1][0] = 3;
	TMatrix <int> m3(2);
	m3[0][0] = 2;
	m3[0][1] = 4;
	m3[1][0] = 6;
	EXPECT_EQ(m3, m1 + m2);
}

TEST(TMatrix, cant_addit_with_not_equal_size)
{
	TMatrix <int> m(2);
	m[0][0] = 1;
	m[0][1] = 2;
	m[1][0] = 3;
	TMatrix<int> m1(1);
	m1[0][0] = 1;
	ASSERT_ANY_THROW(m + m1);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix <int> m1(2);
	m1[0][0] = 1;
	m1[0][1] = 2;
	m1[1][0] = 3;
	TMatrix <int> m2(2);
	m2[0][0] = 1;
	m2[0][1] = 2;
	m2[1][0] = 3;
	TMatrix <int> m3(2);
	m3[0][0] = 0;
	m3[0][1] = 0;
	m3[1][0] = 0;
	EXPECT_EQ(m3, m1 - m2);
}

TEST(TMatrix, can_multiply_with_equal_size)
{
	TMatrix <int> m1(2);
	m1[0][0] = 1;
	m1[0][1] = 2;
	m1[1][0] = 3;
	TMatrix <int> m2(2);
	m2[0][0] = 1;
	m2[0][1] = 2;
	m2[1][0] = 3;
	TMatrix <int> m3(2);
	m3[0][0] = 1;
	m3[0][1] = 8;
	m3[1][0] = 9;
	EXPECT_EQ(m3, m1 * m2);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix <int> m1(2);
	m1[0][0] = 1;
	m1[0][1] = 2;
	m1[1][0] = 3;
	TMatrix<int> m2(1);
	m2[0][0] = 2;
	ASSERT_ANY_THROW(m1 - m2);
}

TEST(TMatrix, cant_multiply_with_not_equal_size)
{
	TMatrix <int> m1(2);
	m1[0][0] = 1;
	m1[0][1] = 2;
	m1[1][0] = 1;
	TMatrix <int> m2(1);
	m2[0][0] = 0;
	ASSERT_ANY_THROW(m1 * m2);
}
