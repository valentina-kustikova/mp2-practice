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
    m1[0][0] = 1;
    TDynamicMatrix<int> m2(m1);

    ASSERT_EQ(m1, m2);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
    TDynamicMatrix<int> m(5);
    TDynamicMatrix<int> m1(m);
    m[0][0] = 15;  // Изменяем одну из матриц
    EXPECT_NE(m, m1);  // Значения должны различаться
}

TEST(TDynamicMatrix, can_get_size) {
    TDynamicMatrix<int> m(5);
    EXPECT_EQ(m.size(), 5); // Проверяем размер
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
    TDynamicMatrix<int> m(5);
    m[1][1] = 10;
    EXPECT_EQ(m[1][1], 10);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
    TDynamicMatrix<int> m(5);
    ASSERT_ANY_THROW(m.at(-1).at(0) = 10);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
    TDynamicMatrix<int> m(5);
    ASSERT_ANY_THROW(m.at(5).at(0) = 10);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
    TDynamicMatrix<int> m(5);
    ASSERT_NO_THROW(m = m);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
    TDynamicMatrix<int> m1(5);
    TDynamicMatrix<int> m2(5);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 2 - i; j++)
        {
            m1[i][j] = i + j;
        }
    }
    m2 = m1;

    // заполнить
    // m1=m2
    // EXPECT_EQ(m1, m2)
    EXPECT_EQ(m1, m2);
    
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size) {
    TDynamicMatrix<int> m1(3);
    TDynamicMatrix<int> m2(4);
    m2 = m1;
    ASSERT_EQ(m1.size(), m2.size());
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)//todo
{
    TDynamicMatrix<int> m1(5);
    TDynamicMatrix<int> m2(10);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5 - i; j++)
        {
            m1[i][j] = i + j;
        }
    }

    // заполнить
    m1 = m2;
    EXPECT_EQ(m1, m2);
    //ASSERT_NO_THROW(m1 = m2);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
    TDynamicMatrix<int> m1(5);
    TDynamicMatrix<int> m2(5);
    EXPECT_TRUE(m1 == m2);  // равные матрицы дадут true
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
    TDynamicMatrix<int> m(5);
    EXPECT_TRUE(m == m);  // true при сравнении с самого собой
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
    TDynamicMatrix<int> m1(5);
    TDynamicMatrix<int> m2(10);
    EXPECT_FALSE(m1 == m2);  //false для матриц разного размера
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
    TDynamicMatrix<int> m1(5);
    TDynamicMatrix<int> m2(5);
    TDynamicMatrix<int> sum(5);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5 - i; j++)
        {
            m1[i][j] = i + j;
            m2[i][j] = i + j + 1;
            sum[i][j] = (i + j) + (i + j + 1);
        }
    }
    //ASSERT_NO_THROW(m1 + m2);
    ASSERT_EQ(sum, m1 + m2);// todo сравнить с результатотм
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
    TDynamicMatrix<int> m1(20);
    TDynamicMatrix<int> m2(15);

    ASSERT_NO_THROW(m1 + m2);
  
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
    TDynamicMatrix<int> m1(5);
    TDynamicMatrix<int> m2(5);
    TDynamicMatrix<int> diff(5);
    //ASSERT_NO_THROW(m1 - m2);
    // todo сравнить с результатотм
   
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5 - i ; j++)
        {
            m1[i][j] = i + j + 1;
            m2[i][j] = i + j;
            diff[i][j] = (i + j + 1) - (i + j);
        }
    }
    //ASSERT_NO_THROW(m1 + m2);
    EXPECT_EQ(diff, m1 - m2);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
    TDynamicMatrix<int> m1(5);
    TDynamicMatrix<int> m2(15);

    ASSERT_ANY_THROW(m1 - m2);// Ожидаем исключение при вычитании матриц разного размера;
}

TEST(TDynamicMatrix, can_multiply_matrices_with_equal_size)
{
    TDynamicMatrix<int> m1(5);
    TDynamicMatrix<int> m2(5);
    TDynamicMatrix<int> mult(5);

    // todo сравнить с результатотм

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 2 - i; j++)
        {
            m1[i][j] = i + j + 1;
            m2[i][j] = i + j;
            mult[i][j] = (i + j + 1) * (i + j);
        }
    }
    EXPECT_EQ(mult, m1 * m2);
}

TEST(TDynamicMatrix, cant_multiply_matrixes_with_not_equal_size)
{
    TDynamicMatrix<int> m1(5), m2(15);

    ASSERT_ANY_THROW(m1 * m2);
}

TEST(TDynamicMatrix, can_multiply_matrixes_and_scalar)
{
    TDynamicMatrix<int> m1(5), mult(5);
    m1[0][0] = 1;
    mult[0][0] = 5;
    EXPECT_EQ(mult, m1 * 5);
}

TEST(TDynamicMatrix, can_multiply_matrixes_and_vector)
{
    TDynamicMatrix<int> m1(2);
    TDynamicMatrix<int> v(2), res(2);
    m1[0][0] = 1;
    v[0][0] = 5;
    res[0][0] = 10;
    EXPECT_EQ(res, m1 * v);
}

