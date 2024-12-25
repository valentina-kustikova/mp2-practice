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
    TDynamicMatrix<int> m(2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    TDynamicMatrix<int> m1(m);
    EXPECT_EQ(m, m1);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{

    TDynamicMatrix<int> m(2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    TDynamicMatrix<int> m1(m);
    m1[0][0] = 10;
    EXPECT_FALSE(m == m1);
}

TEST(TDynamicMatrix, can_get_size)
{
    TDynamicMatrix<int> m(100);
    EXPECT_EQ(100, m[0].size());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
    TDynamicMatrix<int> m(2);
    TDynamicMatrix<int> m1(2);
    int elem = 245321;
    m[0][0] = elem;
    EXPECT_EQ(1, elem == m[0][0]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
    TDynamicMatrix<int> m(2);
    m[0][0] = 5;
    m[0][1] = 21;
    m[1][0] = 334;
    ASSERT_ANY_THROW(m[1].at(-5) = 5);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
    TDynamicMatrix<int> m(2);
    m[0][0] = 5;
    m[0][1] = 21;
    m[1][0] = 334;
    ASSERT_ANY_THROW(m[1].at(MAX_VECTOR_SIZE) = 5);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
    TDynamicMatrix<int> m(2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    m = m;
    EXPECT_EQ(m, m);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
    TDynamicMatrix<int> m(2);
    TDynamicMatrix<int> m1(2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    m1 = m;
    EXPECT_EQ(m1, m);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
    TDynamicMatrix<int> m(2);
    TDynamicMatrix<int> m1(10);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    m1 = m;
    EXPECT_EQ(m.size(), m1.size());
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
    TDynamicMatrix<int> m(2);
    TDynamicMatrix<int> m1(10);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    ASSERT_NO_THROW(m1 = m);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
    TDynamicMatrix<int> m(2);
    TDynamicMatrix<int> m1(2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;

    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[1][0] = 3;

    EXPECT_TRUE(m == m1);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
    TDynamicMatrix<int> m(2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    EXPECT_TRUE(m == m);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{

    TDynamicMatrix<int> m(2);
    TDynamicMatrix<int> m1(1);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;

    m1[0][0] = 5;
    EXPECT_FALSE(m == m1);

}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{

    TDynamicMatrix<int> m(2);
    TDynamicMatrix<int> m1(2);
    TDynamicMatrix<int> m2(2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;

    m1[0][0] = 5;
    m1[0][1] = 6;
    m1[1][0] = 7;

    m2[0][0] = 6;
    m2[0][1] = 8;
    m2[1][0] = 10;

    EXPECT_EQ(m2, m1 + m);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{

    TDynamicMatrix<int> m(2);
    TDynamicMatrix<int> m1(1);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;

    m1[0][0] = 5;
    ASSERT_ANY_THROW(m1 + m);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
    TDynamicMatrix<int> m(2);
    TDynamicMatrix<int> m1(2);
    TDynamicMatrix<int> m2(2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;

    m1[0][0] = 5;
    m1[0][1] = 6;
    m1[1][0] = 7;

    m2[0][0] = -4;
    m2[0][1] = -4;
    m2[1][0] = -4;

    EXPECT_EQ(m2, m - m1);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{

    TDynamicMatrix<int> m(2);
    TDynamicMatrix<int> m1(1);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;

    ASSERT_ANY_THROW(m - m1);

}




//--------------------------
//
//
// ADDITIONAL TESTS
//
// 
// 
//--------------------------



TEST(TDynamicMatrix, can_multiply_matrix_by_vector)
{
    // 1  2  3
    //    4  5
    //       6
    // 3 5 7

    TDynamicMatrix<int> m(3);
    m[0][0] = 1;
    m[0][1] = 2;
    m[0][2] = 3;
    m[1][0] = 4;
    m[1][1] = 5;
    m[2][0] = 6;


    TDynamicVector<int> v(3);
    v[0] = 3;
    v[1] = 5;
    v[2] = 7;

    TDynamicVector<int> answ(3);
    answ[0] = 3 * 1 + 5 * 2 + 7 * 3;
    answ[1] = 4 * 5 + 5 * 7;
    answ[2] = 6 * 7;

    TDynamicVector<int> real = m * v;
    EXPECT_TRUE(real == answ);
}

TEST(TDynamicMatrix, can_multiply_matricies)
{
    // 3   5
    //     7

    // 11  13
    //     17 
    TDynamicMatrix<int> m1(2);
    m1[0][0] = 3;
    m1[0][1] = 5;
    m1[1][0] = 7;

    TDynamicMatrix<int> m2(2);
    m2[0][0] = 11;
    m2[0][1] = 13;
    m2[1][0] = 17;

    TDynamicMatrix<int> answ(2);
    answ[0][0] = 33;
    answ[0][1] = 124;
    answ[1][0] = 119;
    TDynamicMatrix<int> real = m1 * m2;

    EXPECT_TRUE(real == answ);

}

TEST(TDynamicMatrix, can_multiply_matrix_by_const) {
    TDynamicMatrix<int> m(2);
    const int val = 10;
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;   
    TDynamicMatrix<int> answ(2);
    answ[0][0] = 10;
    answ[0][1] = 20;
    answ[1][0] = 30;
    TDynamicMatrix<int> real = m * val;


    EXPECT_TRUE(real == answ);

}