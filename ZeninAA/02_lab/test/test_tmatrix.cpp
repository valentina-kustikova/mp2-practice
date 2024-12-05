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
    TDynamicMatrix<int> m1(4), m2(4);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4 - i; j++) {
            m1[i][j] = i + j;
        }
    }
    m1 = m2;
    EXPECT_EQ(m1, m2);  
  
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
    m1 = m2; 
    EXPECT_EQ(m1, m2);
    
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

TEST(TDynamicMatrix, can_multiply_matrix_by_constant) {  
    TDynamicMatrix<int> m1(2);
    const int val = 11;
    m1[0][0] = 1;
    m1[0][1] = 3;
    m1[1][0] = 5;
    TDynamicMatrix<int> m2(2);
    m2[0][0] = 11;
    m2[0][1] = 33;
    m2[1][0] = 55;
    TDynamicMatrix<int> m3 = m1 * val;
    EXPECT_TRUE(m3 == m2);
}

TEST(TDynamicMatrix, can_multiply_matrix_by_vector)
{
    TDynamicMatrix<int> m1(3); 
    m1[0][0] = 1;  
    m1[0][1] = 2;  
    m1[0][2] = 6; 
    m1[1][0] = 9; 
    m1[1][1] = 12; 
    m1[2][0] = 11; 
    TDynamicVector<int> v1(3);  
    v1[0] = 2; 
    v1[1] = 4;  
    v1[2] = 6; 
    TDynamicVector<int> v2(3); 
    v2[0] = 2 * 1 + 4 * 2 + 6 * 6;  
    v2[1] = 4 * 9 + 6 * 12;  
    v2[2] = 6 * 11;  

    TDynamicVector<int> v3 = m1 * v1;   
    EXPECT_TRUE(v3 == v2); 
    
}

TEST(TDynamicMatrix, can_multiply_matrix_by_matrix) 
{
    
    TDynamicMatrix<int> m1(2);
    m1[0][0] = 2;
    m1[0][1] = 4;
    m1[1][0] = 6;
    TDynamicMatrix<int> m2(2);
    m2[0][0] = 12;
    m2[0][1] = 15;
    m2[1][0] = 19;
    TDynamicMatrix<int> m3(2); 
    m3[0][0] = 24; 
    m3[0][1] = 106; 
    m3[1][0] = 114; 
    TDynamicMatrix<int> m4 = m1 * m2; 

    EXPECT_TRUE(m4 == m3); 

}

