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
    TDynamicMatrix<int> m1(5);
    m1[0][0] = 0;
    m1[1][0] = 1;
    m1[2][0] = 2;
    TDynamicMatrix<int> m2(m1);
    EXPECT_EQ(m1, m2);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
    TDynamicMatrix<int> m(10), m1(m);
    m1[0][0] = 100;
    EXPECT_FALSE(m == m1);
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
    TDynamicMatrix<int> m(5);

    ASSERT_ANY_THROW(m.at(-1).at(-1) = 0);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
    TDynamicMatrix<int> m(5);

    ASSERT_ANY_THROW(m.at(10).at(10) = 0);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
    TDynamicMatrix<int> m(5);
    ASSERT_NO_THROW(m = m);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
    TDynamicMatrix<int> m1(5), m2(5);
    m1[0][0] = 0;
    m1[1][0] = 1;
    m1[2][0] = 2;
    m2 = m1;
    EXPECT_EQ(m1, m2);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
    TDynamicMatrix<int> m1(5), m2(10);

    m1 = m2;
    ASSERT_EQ(m1.size(), m2.size());
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
    TDynamicMatrix<int> m1(5), m2(10);
    m1[0][0] = 0;
    m1[1][0] = 1;
    m1[2][0] = 2;
    m2 = m1;
    EXPECT_EQ(m1, m2);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
    TDynamicMatrix<int> m1(5),m2(5);
    m1[0][0] = 0;
    m1[1][0] = 1;
    m1[2][0] = 2;
    m2 = m1;
    EXPECT_TRUE(m1 == m2); 
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
    TDynamicMatrix<int> m(5);
    m[0][0] = 0;
    m[1][0] = 1;
    m[2][0] = 2;
    EXPECT_TRUE(m == m);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
    TDynamicMatrix<int> m1(5),m2(10);

    EXPECT_FALSE(m1 == m2); 
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
    TDynamicMatrix<int> m1(5), m2(5), m3(5);
    m1[1][0] = 3;
    m2[1][0] = 1;
    m3[1][0] = 4;
    EXPECT_EQ(m1 + m2, m3);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
    TDynamicMatrix<int> m1(5),m2(10);

    ASSERT_ANY_THROW(m1 + m2);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)//
{
    TDynamicMatrix<int> m1(5), m2(5), m3(5);
    m1[1][1] = 3;
    m2[1][1] = 1;
    m3[1][1] = 2;
    TDynamicMatrix<int> m4 = m1 - m2;
    EXPECT_EQ(m3, m4);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
    TDynamicMatrix<int> m1(5);
    TDynamicMatrix<int> m2(10);

    ASSERT_ANY_THROW(m1 - m2);
}
TEST(TDynamicMatrix, can_multiply_matrixes_with_equal_size)
{
    TDynamicMatrix<int> m1(5), m2(5), m3(5);
    m1[1][0] = 3;
    m2[1][0] = 2;
    m3[1][0] = 6;
    EXPECT_EQ(m1 * m2, m3);
}

TEST(TDynamicMatrix, cant_multiply_matrixes_with_not_equal_size)
{
    TDynamicMatrix<int> m1(5);
    TDynamicMatrix<int> m2(10);

    ASSERT_ANY_THROW(m1 * m2);
}
TEST(TDynamicMatrix, can_multiply_scalar_by_matrix)
{
    TDynamicMatrix<int> m1(5), m2(5);
    m1[1][0] = 3;
    m2[1][0] = 9;
    EXPECT_EQ(m1 * 3, m2);
}
TEST(TDynamicMatrix, can_multiply_matrix_and_vector_with_equal_size)
{
   TDynamicMatrix<int> m(2);
    TDynamicVector<int> v(2), res(2);
    m[0][0] = 3;
    m[0][1] = 3;
    m[1][0] = 3;
    v[0] = 2;
    v[1] = 2;
    res[0] = 12;
    res[1] = 6;
    EXPECT_EQ(m * v, res);
}
