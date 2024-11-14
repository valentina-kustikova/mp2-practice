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
    TDynamicMatrix<int> m1(2), m2(m1);
    EXPECT_EQ(m1, m2);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
    TDynamicMatrix<int> m1(4), m2(m1);
    m2[0][2] = 17;
    EXPECT_NE(m1, m2);
   
}

TEST(TDynamicMatrix, can_get_size)
{
    TDynamicMatrix<int> m(6);
    EXPECT_EQ(6, m.size());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
  TDynamicMatrix<int> m(2);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2 - i; j++)
        {
            m[i][j] = i + j;
        }
    }
    EXPECT_EQ(1, m[1][0]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
    TDynamicMatrix<int> m(2);
    ASSERT_ANY_THROW(m.at(-5).at(-5) = 5);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
    TDynamicMatrix<int> m(4);
    ASSERT_ANY_THROW(m.at(7).at(4) = 3);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
    TDynamicMatrix<int> m1(3);
    ASSERT_NO_THROW(m1 = m1); 
  
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size) // todo
{
    TDynamicMatrix<int> m1(3);
    TDynamicMatrix<int> m2(3);
    ASSERT_NO_THROW(m1 = m2);
  
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
    TDynamicMatrix<int> m1(3), m2(5);
    m1 = m2;
    
    EXPECT_EQ(5, m1.size());
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size) // todo
{
    TDynamicMatrix<int> m1(2), m2(7);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2 - i; j++)
        {
            m1[i][j] = i + j;
        }
    }
    ASSERT_NO_THROW(m2 = m1);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
    TDynamicMatrix<int> m1(3), m2(3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3 - i; j++)
        {
            m1[i][j] = i + j;
            m2[i][j] = i + j;
        }
    }
    EXPECT_TRUE(m1 == m2);
   
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
    TDynamicMatrix<int> m1(5);
    EXPECT_TRUE(m1 == m1); 

}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
    TDynamicMatrix<int> m1(4), m2(5);
    EXPECT_FALSE(m1 == m2); 
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
    TDynamicMatrix<int> m1(2), m2(2), tmp(2);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2 - i; j++)
        {
            m1[i][j] = i + j;
            m2[i][j] = i + j;
            tmp[i][j] = 2 * i + 2 * j;
        }
    }
    EXPECT_EQ(m1 + m2, tmp);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
    TDynamicMatrix<int> m1(4), m2(5);
    ASSERT_ANY_THROW(m1 + m2);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
    TDynamicMatrix<int> m1(5), m2(5), tmp(5);  
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5 - i; j++)
        {
            m1[i][j] = i + j;
            m2[i][j] = i + j; 
            tmp[i][j] = i + j - i - j;
        }
    }
    EXPECT_EQ(m1 - m2, tmp);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
    TDynamicMatrix<int> m1(4), m2(5);
    ASSERT_ANY_THROW(m1 - m2);
}

// todo (Написать тесты умножения матрицу на вектор и матрицу на матрицу)