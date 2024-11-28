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
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4 - i; j++)
            m1[i][j] = i;
    }
    TDynamicMatrix<int> m2(m1);
    
    EXPECT_EQ(m1, m2);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
    TDynamicMatrix<int> m1(4);
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4 - i; j++)
            m1[i][j] = i;
    }
    TDynamicMatrix<int> m2(m1);
    m2[0][0] = 1000;
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
    m[0][0] = 9;
    EXPECT_EQ(9, m[0][0]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
    TDynamicMatrix<int> m(4);

    ASSERT_ANY_THROW(m[-1][-1] = 10);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
    TDynamicMatrix<int> m(4);

    ASSERT_ANY_THROW(m[5][5] = 10);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
    TDynamicMatrix<int> m(4);
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4 - i; j++)
            m[i][j] = i;
    }
    ASSERT_NO_THROW(m = m);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
    TDynamicMatrix<int> m1(4);
    TDynamicMatrix<int> m2(4);
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4 - i; j++)
            m1[i][j] = i;
    }
    m2 = m1;
    EXPECT_EQ(m1, m2);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
    TDynamicMatrix<int> m1(4);
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4 - i; j++)
            m1[i][j] = i;
    }
    TDynamicMatrix<int> m2(3);
    m2 = m1;
    EXPECT_EQ(m1[0].size(), m2[0].size());
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
    TDynamicMatrix<int> m1(4);
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4 - i; j++)
            m1[i][j] = i;
    }
    TDynamicMatrix<int> m2(3);
    m2 = m1;
    EXPECT_EQ(m1, m2);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
    TDynamicMatrix<int> m1(4);
    TDynamicMatrix<int> m2(4);
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4 - i; j++)
            m1[i][j] = i;
    }
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4 - i; j++)
            m2[i][j] = i;
    }
    EXPECT_TRUE(m1 == m2);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
    TDynamicMatrix<int> m(4);
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4 - i; j++)
            m[i][j] = i;
    }
    EXPECT_TRUE(m == m);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
    TDynamicMatrix<int> m1(4);
    TDynamicMatrix<int> m2(5);
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4 - i; j++)
            m1[i][j] = i;
    }
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5 - i; j++)
            m2[i][j] = i;
    }
    EXPECT_FALSE(m1 == m2);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
    TDynamicMatrix<int> m1(4);
    TDynamicMatrix<int> m2(4);
    TDynamicMatrix<int> m3(4);
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4 - i; j++)
            m1[i][j] = i;
    }
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4 - i; j++)
            m2[i][j] = i;
    }
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4 - i; j++)
            m3[i][j] = i + i;
    }
    EXPECT_EQ(m1 + m2, m3);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
    TDynamicMatrix<int> m1(4);
    TDynamicMatrix<int> m2(5);
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4 - i; j++)
            m1[i][j] = i;
    }
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5 - i; j++)
            m2[i][j] = i;
    }
    ASSERT_ANY_THROW(m1 + m2);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
    TDynamicMatrix<int> m1(4);
    TDynamicMatrix<int> m2(4);
    TDynamicMatrix<int> m3(4);
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4 - i; j++)
            m1[i][j] = i + i;
    }
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4 - i; j++)
            m2[i][j] = i;
    }
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4 - i; j++)
            m3[i][j] = i;
    }
    EXPECT_EQ(m1 - m2, m3);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
    TDynamicMatrix<int> m1(4);
    TDynamicMatrix<int> m2(5);
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4 - i; j++)
            m1[i][j] = i;
    }
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5 - i; j++)
            m2[i][j] = i;
    }
    ASSERT_ANY_THROW(m1 - m2);
}


TEST(TDynamicMatrix, can_multiply_matrices_with_equal_size)
{
    TDynamicMatrix<int> m1(4);
    TDynamicMatrix<int> m2(4);
    TDynamicMatrix<int> m3(4);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4 - i; j++)
            m1[i][j] = i;
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4 - i; j++)
            m2[i][j] = i;
    }

    cout << m1;
    cout << m2;
 
    m3[0][0] = 0;
    m3[0][1] = 0;
    m3[0][2] = 0;
    m3[0][3] = 0;
    m3[1][0] = 1;
    m3[1][1] = 3;
    m3[1][2] = 6;
    m3[2][0] = 4;
    m3[2][1] = 10;
    m3[3][0] = 9;
    EXPECT_EQ(m1 * m2, m3);
}

TEST(TDynamicMatrix, cant_multiply_matrices_with_not_equal_size)
{
    TDynamicMatrix<int> m1(4);
    TDynamicMatrix<int> m2(5);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4 - i; j++)
            m1[i][j] = i;
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5 - i; j++)
            m2[i][j] = i;
    }
    ASSERT_ANY_THROW(m1 * m2);
};
