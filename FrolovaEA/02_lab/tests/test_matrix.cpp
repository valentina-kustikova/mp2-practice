
#include "TMatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_size)
{
    ASSERT_NO_THROW(TMatrix<int> m(3));
}

TEST(TVector, cant_create_matrix_with_negative_size)
{
    ASSERT_NO_THROW(TMatrix<int> m(-3));
}

TEST(TMatrix, checking_the_copy_constructor)
{
    TMatrix<int> a(5);
    ASSERT_NO_THROW(TMatrix<int> m(a));
}

TEST(TMatrix, can_get_elem)
{
    TMatrix<int> a(3);
    a[0][0] = 3;
    EXPECT_EQ(3, a[0][0]);
}

TEST(TMatrix, cant_get_elem_by_negative_index)
{
    TMatrix<int> a(3);
    ASSERT_ANY_THROW(a[-2][3]);
}

TEST(TMatrix, cant_get_elem_by_index_more_then_size)
{
    TMatrix<int> a(5);
    ASSERT_ANY_THROW(a[7][1]);
}

TEST(TMatrix, checking_for_equality_of_matrices_of_different_lengths)
{
    TMatrix<int> a(5);
    TMatrix<int> b(7);
    EXPECT_EQ(0,a==b);
}

TEST(TMatrix, checking_for_equality_of_matrices_of_the_same_lengths_1)
{
    TMatrix<int> a(3);
    TMatrix<int> b(3);
    a[0][0] = 1;
    a[0][1] = 1;
    a[0][2] = 1;
    a[1][1] = 1;
    a[1][2] = 1;
    a[2][2] = 1;

    b = a;
    EXPECT_EQ(1, a == b);
}

TEST(TMatrix, checking_for_equality_of_matrices_of_the_same_lengths_1)
{
    TMatrix<int> a(3);
    TMatrix<int> b(3);
    a[0][0] = 1;
    a[0][1] = 1;
    a[0][2] = 1;
    a[1][1] = 1;
    a[1][2] = 1;
    a[2][2] = 1;

    b[0][0] = 2;
    b[0][1] = 2;
    b[0][2] = 2;
    b[1][1] = 2;
    b[1][2] = 2;
    b[2][2] = 2;

    
    EXPECT_EQ(0, a == b);
}

TEST(TMatrix, equalization_operator)
{
    TMatrix<int> a(5);
    TMatrix<int> b(7);
    a = b;
    EXPECT_EQ(1, (a.GetSize()==b.GetSize()));
}

TEST(TMatrix, addition_of_matrices_of_the_same_length)
{
    TMatrix<int> a(3);
    TMatrix<int> b(3);
    TMatrix<int> c(3);
    a[0][0] = 1;
    b[0][0] = 1;
    c = a + b;
    EXPECT_EQ(2, c[0][0]);
}

TEST(TMatrix, addition_of_matrices_of_the_non_same_length)
{
    TMatrix<int> a(3);
    TMatrix<int> b(5);
    ASSERT_ANY_THROW(a + b);
}

TEST(TMatrix, difference_of_matrices_of_the_same_length)
{
    TMatrix<int> a(3);
    TMatrix<int> b(3);
    TMatrix<int> c(3);
    a[0][0] = 4;
    b[0][0] = 1;
    c = a - b;
    EXPECT_EQ(3, c[0][0]);
}

TEST(TMatrix, difference_of_matrices_of_the_non_same_length)
{
    TMatrix<int> a(3);
    TMatrix<int> b(5);
    ASSERT_ANY_THROW(a - b);
}

TEST(TMatrix, the_product_of_matrices_of_the_same_length)
{
    TMatrix<int> m1(3);
    TMatrix<int> m2(3);
    TMatrix<int> res(3);
    TMatrix<int> d(3);
    m1[0][0] = 1;
    m1[0][1] = 1;
    m1[0][2] = 1;
    m1[1][1] = 1;
    m1[1][2] = 1;
    m1[2][2] = 1;
    m2 = m1;

    res[0][0] = 1;
    res[0][1] = 2;
    res[0][2] = 3;
    res[1][1] = 1;
    res[1][2] = 2;
    res[2][2] = 1;

    d = m1 * m2;
    EXPECT_EQ(1, (res==d));
}

