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
    TDynamicMatrix<int> m(3);
    TDynamicMatrix<int> m1(m);
    EXPECT_EQ(m1, m);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
    TDynamicMatrix<int> m(3);
    TDynamicMatrix<int> m1(m);
    EXPECT_NE(&m1, &m);
}

TEST(TDynamicMatrix, can_get_size)
{
    TDynamicMatrix<int> m(5);
    EXPECT_EQ(5, m.size());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
    TDynamicMatrix<int> m(3);
    m[2][1] = 100;
    EXPECT_EQ(100, m[2][1]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
    TDynamicMatrix<int> m(3);
    ASSERT_ANY_THROW(m[0].at(-1));
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
    TDynamicMatrix<int> m(3);
    ASSERT_ANY_THROW(m[0].at(MAX_MATRIX_SIZE));
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
    TDynamicMatrix<int> m(3);
    EXPECT_EQ(1, m == m);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
    TDynamicMatrix<int> m(4);
    TDynamicMatrix<int> m1(4);
    m1 = m;
    EXPECT_EQ(m1, m);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
    TDynamicMatrix<int> m(4);
    TDynamicMatrix<int> m1(5);
    m1 = m;
    EXPECT_EQ(m1[1].size(), m[1].size());
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
    TDynamicMatrix<int> m(4);
    TDynamicMatrix<int> m1(5);
    m1 = m;
    EXPECT_EQ(m1, 4);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
    TDynamicMatrix<int> m(4);
    TDynamicMatrix<int> m1(4);
    m1 = m;
    EXPECT_EQ(1, m1 == m);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
    TDynamicMatrix<int> m(4);
    EXPECT_EQ(1, m == m);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
    TDynamicMatrix<int> m(4);
    TDynamicMatrix<int> m1(5);
    EXPECT_NE(1, m1 == m);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
    TDynamicVector<int> m(5), m1(5), m2(5);
    for (int i = 0; i < 5; i++)
    {
        m[i] = i;
        m1[i] = i;
        m2[i] = m1[i] + m[i];
    }
    EXPECT_EQ(m2, m1 + m);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
    TDynamicMatrix<int> m(4);
    TDynamicMatrix<int> m1(5);

    ASSERT_ANY_THROW(m + m1);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
    TDynamicVector<int> m(5), m1(5), m2(5);
    for (int i = 0; i < 5; i++)
    {
        m[i] = i;
        m1[i] = i;
        m2[i] = m1[i] - m[i];
    }
    EXPECT_EQ(m2, m1 - m);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
    TDynamicMatrix<int> m(4);
    TDynamicMatrix<int> m1(5);

    ASSERT_ANY_THROW(m - m1);
}

