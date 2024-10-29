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
    TDynamicMatrix<int> m1(4);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            m1[i][j] = i;
    }
    TDynamicMatrix<int> m2(m1);
    
    EXPECT_EQ(m1, m2);
       
    //EXPECT_EQ(1, 1);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
    TDynamicMatrix<int> m1(4);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            m1[i][j] = i;
    }
    TDynamicMatrix<int> m2(m1);
    EXPECT_NE(&m1[0][0], &m2[0][0]);

}

TEST(TDynamicMatrix, can_get_size)
{
    TDynamicMatrix<int> m(4);

    EXPECT_EQ(4, m[0].size());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
    TDynamicMatrix<int> m(4);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
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
    TDynamicMatrix<int> m(4);

    ASSERT_ANY_THROW(m.at(0, -1));
    ASSERT_ANY_THROW(m.at(-1, 0));
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
    TDynamicMatrix<int> m(4);

    ASSERT_ANY_THROW(m.at(0, 5));
    ASSERT_ANY_THROW(m.at(5, 0));
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
    TDynamicMatrix<int> m(4);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            m[i][j] = i;
    }
    m = m;
    EXPECT_EQ(m, m);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
    TDynamicMatrix<int> m1(4);
    TDynamicMatrix<int> m2(4);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            m1[i][j] = i;
    }
    m2 = m1;
    EXPECT_EQ(m1, m2);

}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
    TDynamicMatrix<int> m1(4);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            m1[i][j] = i;
    }
    TDynamicMatrix<int> m2(3);
    TDynamicMatrix<int> m3(5);
    m2 = m1;
    m3 = m1;
    EXPECT_EQ(m1[0].size(), m2[0].size());
    EXPECT_EQ(m1[0].size(), m3[0].size());
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
    TDynamicMatrix<int> m1(4);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            m1[i][j] = i;
    }
    TDynamicMatrix<int> m2(3);
    TDynamicMatrix<int> m3(5);
    m2 = m1;
    m3 = m1;
    EXPECT_EQ(m1, m2);
    EXPECT_EQ(m1, m3);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
    TDynamicMatrix<int> m1(4);
    TDynamicMatrix<int> m2(4);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            m1[i][j] = i;
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            m2[i][j] = i;
    }
    EXPECT_EQ(1, m1 == m2);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
    TDynamicMatrix<int> m(4);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            m[i][j] = i;
    }
    EXPECT_EQ(1, m == m);

}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
    TDynamicMatrix<int> m1(4);
    TDynamicMatrix<int> m2(5);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            m1[i][j] = i;
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            m2[i][j] = i;
    }
    EXPECT_EQ(0, m1 == m2);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
    TDynamicMatrix<int> m1(4);
    TDynamicMatrix<int> m2(4);
    TDynamicMatrix<int> m3(4);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            m1[i][j] = i;
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            m2[i][j] = i;
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            m3[i][j] = i + i;
    }
    EXPECT_EQ(m1 + m2, m3);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
    TDynamicMatrix<int> m1(4);
    TDynamicMatrix<int> m2(5);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            m1[i][j] = i;
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            m2[i][j] = i;
    }
    ASSERT_ANY_THROW(m1 + m2);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
    TDynamicMatrix<int> m1(4);
    TDynamicMatrix<int> m2(4);
    TDynamicMatrix<int> m3(4);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            m1[i][j] = i + i;
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            m2[i][j] = i;
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            m3[i][j] = i;
    }
    EXPECT_EQ(m1 - m2, m3);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
    TDynamicMatrix<int> m1(4);
    TDynamicMatrix<int> m2(5);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            m1[i][j] = i;
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            m2[i][j] = i;
    }
    ASSERT_ANY_THROW(m1 - m2);
}

