#include "matrix.h"
#include <gtest.h>

TEST(Matrix, can_create_matrix_with_positive_length)
{
	ASSERT_NO_THROW(Matrix<int> m(5));
}

TEST(Matrix, throws_when_create_matrix_with_negative_length)
{
	ASSERT_ANY_THROW(Matrix<int> m(-5));
}

TEST(Matrix, can_create_copied_matrix)
{
	Matrix<int> m(2);
	m[0][0] = 4;
	m[0][1] = 4;
	m[1][0] = 4;
	ASSERT_NO_THROW(Matrix<int> m1(m));
}

TEST(Matrix, copied_matrix_is_equal_to_source_one)
{
	Matrix <int> m1(2);
	m1[0][0] = 1;
	m1[0][1] = 2;
	m1[1][0] = 1;
	Matrix<int> m2(m1);
	EXPECT_EQ(m1 == m2, 1);
}

TEST(Matrix, copied_matrix_has_its_own_memory)
{

	Matrix <int> m1(2);
	m1[0][0] = 1;
	m1[0][1] = 2;
	m1[1][0] = 1;
	Matrix <int> m2(m1);
	m1[0][0] = 3;
	EXPECT_EQ(m1 == m2, 0);
}

TEST(Matrix, can_get_size)
{
	Matrix<int> m1(4);
	EXPECT_EQ(4, m1.getSize());
}

TEST(Matrix, can_set_and_get_element)
{
	Matrix <int> m1(2);
	m1[0][0] = 2;
	m1[0][1] = 2;
	m1[1][0] = 1;
	EXPECT_EQ(2, m1[0][0]);
}

TEST(Matrix, throws_when_set_element_with_negative_index)
{
	Matrix <int> m1(2);
	m1[0][0] = 1;
	m1[0][1] = 2;
	m1[1][0] = 1;
	ASSERT_ANY_THROW(m1[-1][-1] = 1);
}

TEST(Matrix, can_assign_matrix_to_itself)
{
	Matrix<int>m(2);
	m[0][0] = 1;
	m[0][1] = 2;
	m[1][0] = 1;
	ASSERT_NO_THROW(m = m);
}

TEST(Matrix, can_assign_matrix_of_equal_size)
{
	Matrix <int> m1(2);
	m1[0][0] = 1;
	m1[0][1] = 2;
	m1[1][0] = 1;
	Matrix <int> m2(2);
	m2[0][0] = 1;
	m2[0][1] = 2;
	m2[1][0] = 1;
	m2 = m1;
	EXPECT_EQ(m1, m2);
}

TEST(Matrix, can_assign_matrix_of_different_size)
{

	Matrix <int> m1(2);
	m1[0][0] = 1;
	m1[0][1] = 2;
	m1[1][0] = 1;
	Matrix <int> m2(1);
	m2[0][0] = 1;
	m2 = m1;
	EXPECT_EQ(m1, m2);
}

TEST(Matrix, assign_operator_change_matrix_size)
{
	Matrix <int> m1(2);
	m1[0][0] = 1;
	m1[0][1] = 2;
	m1[1][0] = 1;
	Matrix <int> m2(1);
	m2[0][0] = 1;
	m2 = m1;
	EXPECT_EQ(2, m2.getSize());
}

TEST(Matrix, compare_equal_matrix_return_true)
{
	Matrix <int> m1(2);
	m1[0][0] = 1;
	m1[0][1] = 2;
	m1[1][0] = 1;
	Matrix <int> m2(2);
	m2[0][0] = 1;
	m2[0][1] = 2;
	m2[1][0] = 1;
	EXPECT_EQ(m1, m2);
}

TEST(Matrix, compare_matrix_with_itself_return_true)
{
	Matrix <int> m(2);
	m[0][0] = 1;
	m[0][1] = 2;
	m[1][0] = 1;
	ASSERT_TRUE(m == m);
}

TEST(Matrix, matrix_with_different_size_are_not_equal)
{
	Matrix <int> m1(2);
	m1[0][0] = 1;
	m1[0][1] = 2;
	m1[1][0] = 1;
	Matrix <int> m2(1);
	m2[0][0] = 1;
	ASSERT_TRUE(m1 != m2);
}

TEST(Matrix, can_add_matrices_with_equal_size)
{
	Matrix <int> m1(2);
	m1[0][0] = 1;
	m1[0][1] = 2;
	m1[1][0] = 1;
	Matrix <int> m2(2);
	m2[0][0] = 0;
	m2[0][1] = 1;
	m2[1][0] = 2;
	Matrix <int> m3(2);
	m3[0][0] = 1;
	m3[0][1] = 3;
	m3[1][0] = 3;
	EXPECT_EQ(m3, m1 + m2);
}

TEST(Matrix, cannot_plus_with_not_equal_size)
{
	Matrix <int> m1(2);
	m1[0][0] = 1;
	m1[0][1] = 2;
	m1[1][0] = 1;
	Matrix<int> m2(1);
	m2[0][0] = 1;
	ASSERT_ANY_THROW(m1 + m2);
}

TEST(Matrix, can_subtract_matrices_with_equal_size)
{
	Matrix <int> m1(2);
	m1[0][0] = 1;
	m1[0][1] = 2;
	m1[1][0] = 1;
	Matrix <int> m2(2);
	m2[0][0] = 1;
	m2[0][1] = 1;
	m2[1][0] = 2;
	Matrix <int> m3(2);
	m3[0][0] = 0;
	m3[0][1] = 1;
	m3[1][0] = -1;
	EXPECT_EQ(m3, m1 - m2);
}

TEST(Matrix, cant_subtract_matrixes_with_not_equal_size)
{
	Matrix <int> m1(2);
	m1[0][0] = 1;
	m1[0][1] = 2;
	m1[1][0] = 1;
	Matrix<int> m2(1);
	m2[0][0] = 1;
	ASSERT_ANY_THROW(m1 - m2);
}

TEST(Matrix, can_mult_with_equal_size)
{
	Matrix <int> m1(2);
	m1[0][0] = 1;
	m1[0][1] = 2;
	m1[1][0] = 1;
	Matrix <int> m2(2);
	m2[0][0] = 0;
	m2[0][1] = 1;
	m2[1][0] = 2;
	Matrix <int> m3(2);
	m3[0][0] = 0;
	m3[0][1] = 5;
	m3[1][0] = 2;
	EXPECT_EQ(m3, m1 * m2);
}

TEST(Matrix, cant_mult_with_not_equal_size)
{
	Matrix <int> m1(2);
	m1[0][0] = 1;
	m1[0][1] = 2;
	m1[1][0] = 1;
	Matrix <int> m2(1);
	m2[0][0] = 0;
	ASSERT_ANY_THROW(m1 * m2);
}