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
    Matrix<int> m(5);
    ASSERT_NO_THROW(Matrix<int> m1(m));
}

TEST(Matrix, copied_matrix_is_equal_to_source_one)
{
    Matrix<int> m(4);
    Matrix<int> m1(m);
    EXPECT_EQ(m, m1);
}

TEST(Matrix, copied_matrix_has_its_own_memory)
{
    Matrix<int> m(4);
    Matrix<int> m1(m);
    m1[0][0] += 1;
    m1[1][1] += 11;
    EXPECT_NE(m, m1);
}

TEST(Matrix, can_get_size)
{
    Matrix<int> m(4);
    EXPECT_EQ(4, m.getSize());;
}

TEST(Matrix, can_set_and_get_element)
{
    Matrix<int> m(4);
    ASSERT_NO_THROW(m[0][2] = 2);
    EXPECT_EQ(2, m[0][2]);
}

TEST(Matrix, throws_when_set_element_with_negative_index)
{
    Matrix<int> m(3);
    ASSERT_ANY_THROW(m.setElement(-1, TVector<int>(4)));
}

TEST(Matrix, throws_when_set_element_with_too_large_index)
{
    Matrix<int> m(4);
    ASSERT_ANY_THROW(m.setElement(10, TVector<int>(4)));
}

TEST(Matrix, can_assign_matrix_to_itself)
{
    Matrix<int> m(4);
    ASSERT_NO_THROW(m = m);
}

TEST(Matrix, can_assign_matrices_of_equal_size)
{
    Matrix<int> m(4);
    Matrix<int> m1(4);
    m1[1][1] = 5;
    m = m1;
    ASSERT_EQ(m, m1);
}

TEST(Matrix, assign_operator_change_matrix_size)
{
    Matrix<int> m(3);
    Matrix<int> m1(4);
    m1[1][1] = 5;
    m = m1;
    ASSERT_EQ(4, m.getSize());
}

TEST(Matrix, can_assign_matrices_of_different_size)
{
    Matrix<int> m(3);
    Matrix<int> m1(4);
    m1[1][1] = 5;
    m = m1;
    ASSERT_EQ(m, m1);
}

TEST(Matrix, compare_equal_matrices_return_true)
{
    Matrix<int> m(4);
    Matrix<int> m1(m);
    EXPECT_EQ(true, m == m1);
}

TEST(Matrix, compare_matrix_with_itself_return_true)
{
    Matrix<int> m(4);
    EXPECT_EQ(true, m == m);
}

TEST(Matrix, matrices_with_different_size_are_not_equal)
{
    Matrix<int> m(4);
    Matrix<int> m1(10);
    EXPECT_EQ(true, m != m1);
}

TEST(Matrix, can_add_matrices_with_equal_size)
{
    Matrix<int> m(4);
    Matrix<int> m1(4);
    m[0][0] = 1;
    m1[0][0] = 1;
    ASSERT_NO_THROW(m + m1);
    EXPECT_EQ((m + m1)[0][0], 2);
}

TEST(Matrix, cant_add_matrices_with_not_equal_size)
{
    Matrix<int> m(1);
    Matrix<int> m1(10);
    ASSERT_ANY_THROW(m1 + m);
}

TEST(Matrix, can_subtract_matrices_with_equal_size)
{
    Matrix<int> m(4);
    Matrix<int> m1(4);
    m[0][0] = 5;
    m1[0][0] = 8;
    ASSERT_NO_THROW(m1 - m);
    EXPECT_EQ((m1 - m)[0][0], 3);
}

TEST(Matrix, cant_subtract_matrixes_with_not_equal_size)
{
    Matrix<int> m(1);
    Matrix<int> m1(10);
    ASSERT_ANY_THROW(m1 - m);
}

TEST(Matrix, can_mult_with_equal_size)
{
	Matrix<int> m1(3), m2(3), m3(3);
	m1[0][0] = 1;
	m2[0][0] = 2;
	m3 = m1*m2;
	EXPECT_EQ(2, m3[0][0]);
}

TEST(Matrix, cant_mult_with_not_equal_size)
{
	Matrix<int> m1(1);
	Matrix<int> m2(2);
	ASSERT_ANY_THROW(m1 * m2);
}