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
    int size = 2;
    TDynamicMatrix<int> m(size);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size-i; j++)
            m[i][j] = i;
    }
    TDynamicMatrix<int> m1(m);
    EXPECT_EQ(m, m1);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
    int size = 5;
    TDynamicMatrix<int> m(size);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size-i; j++)
            m[i][j] = i;
    }
    TDynamicMatrix<int> m1(m);
    m1[0][0] = -10;
    EXPECT_NE(m, m1);
}

TEST(TDynamicMatrix, can_get_size)
{
    int size = 5;
    TDynamicMatrix<int> m(size);
    EXPECT_EQ(5, m.size());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
    int size = 5;
    TDynamicMatrix<int> m(size);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size-i; j++)
            m[i][j] = i;
    }
    m[0][0] = 9;
    int res = 0;
    res = m[0][0];
    EXPECT_EQ(9, m[0][0]);
    EXPECT_EQ(9, res);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
    int size = 5;
    TDynamicMatrix<int> m(size);
    ASSERT_ANY_THROW(m.at(-1,-1)=-1);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
    int size = 5;
    TDynamicMatrix<int> m(size);
    ASSERT_ANY_THROW(m.at(MAX_MATRIX_SIZE+1, MAX_MATRIX_SIZE + 1) = -1);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
    TDynamicMatrix<int> m(3);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2-i; j++)
            m[i][j] = 1;
    }
    ASSERT_NO_THROW(m = m);
    m = m;
    EXPECT_EQ(1, m==m);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
    TDynamicMatrix<int> m(2),m1(2);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2-i; j++)
            m[i][j] = 3;
    }
    ASSERT_NO_THROW(m1 = m);
    m1 = m;
    EXPECT_EQ(m, m1);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
    TDynamicMatrix<int> m(3), m1(2);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3-i; j++)
            m[i][j] = 3;
    }
    m1 = m;
    EXPECT_EQ(m1.size(), 3);
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
    TDynamicMatrix<int> m(2), m1(3);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2-i; j++)
            m[i][j] = 3;
    }
    m1 = m;
    EXPECT_EQ(m.size(), m1.size());
    EXPECT_EQ(m, m1);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
    TDynamicMatrix<int> m(2), m1(2);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2-i; j++)
            m[i][j] = 3;
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2-i; j++)
            m1[i][j] = 3;
    }
    EXPECT_EQ(1, (m1 == m));
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
    TDynamicMatrix<int> m(2);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2-i; j++)
            m[i][j] = 1;
    }
    EXPECT_EQ(1, m == m);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
    TDynamicMatrix<int> m(3), m1(2);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3-i; j++)
            m[i][j] = 3;
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2-i; j++)
            m1[i][j] = 3;
    }
    EXPECT_EQ(0, m == m1);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
    TDynamicMatrix<int> m(2), m1(2), m2(2),mr(2);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2-i; j++)
            m[i][j] = m1[i][j] = 3;
    }
    ASSERT_NO_THROW(mr = m + m1);
    mr = m + m1;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2-i; j++)
            m2[i][j]=6;
    }
    EXPECT_EQ(mr, m2);

}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
    TDynamicMatrix<int> m(2), m1(3), mr(3);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2-i; j++)
            m[i][j] = 3;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3-i; j++)
            m1[i][j] = 3;
    }
    ASSERT_ANY_THROW(mr = m + m1);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
    TDynamicMatrix<int> m(2), m1(2), m2(2), mr(2);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2-i; j++)
            m[i][j] = m1[i][j] = 3;
    }
    ASSERT_NO_THROW(mr = m - m1);
    mr = m - m1;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2-i; j++)
            m2[i][j] = 0;
    }
    EXPECT_EQ(mr, m2);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
    TDynamicMatrix<int> m(2), m1(3), mr(3);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2-i; j++)
            m[i][j] = 3;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3-i; j++)
            m1[i][j] = 3;
    }
    ASSERT_ANY_THROW(mr = m - m1);
}

TEST(TDynamicMatrix, can_multiply_matrices_with_equal_size)
{
    TDynamicMatrix<int> m(2), m1(2), mr(2),res;
    m[0][0] = 3;
    m[0][1] = 5;
    m[1][0] = 7;

    m1[0][0] = 11;
    m1[0][1] = 13;
    m1[1][0] = 17;

    mr[0][0] = 33;
    mr[0][1] = 124;
    mr[1][0] = 119;

    ASSERT_NO_THROW(res = m * m1);
    res = m * m1;    
    EXPECT_EQ(res, mr);
}

TEST(TDynamicMatrix, cant_multiply_matrixes_with_not_equal_size)
{
    TDynamicMatrix<int> m(2), m1(3), mr(3);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2-i; j++)
            m[i][j] = 3;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3-i; j++)
            m1[i][j] = 3;
    }
    ASSERT_ANY_THROW(mr = m * m1);
}


