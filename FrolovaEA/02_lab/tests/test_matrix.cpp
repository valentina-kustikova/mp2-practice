
#include "TMatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_size)
{
    ASSERT_NO_THROW(TMatrix<int> m(3));
}

TEST(TMatrix, cant_create_matrix_with_negative_size)
{
    ASSERT_ANY_THROW(TMatrix<int> m(-3));
}

TEST(TMatrix, checking_the_copy_constructor)
{
    TMatrix<int> a(5);
    ASSERT_NO_THROW(TMatrix<int> m(a));
}

TEST(TMatrix, copy_constructor_test_different_memory)
{
    TMatrix<int> a(2);
    a[0][0] = 1;
    a[0][1] = 2;
    a[1][1] = 3;
    TMatrix<int> b(a);
    b[0][0] = 2;
    EXPECT_NE(a, b);
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
    ASSERT_FALSE(a == b);
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
    ASSERT_TRUE(a == b);
}

TEST(TMatrix, equalization_operator)
{
    TMatrix<int> a(5);
    TMatrix<int> b(7);
    a = b;
    EXPECT_EQ(a.GetSize(), b.GetSize());
}

TEST(TMatrix, addition_of_matrices_of_the_same_length)
{
    TMatrix<int> a(3);
    TMatrix<int> b(3);
    TMatrix<int> c(3);
    a[0][0] = 1;
    b[0][0] = 1;
    c = a + b;
    EXPECT_EQ(a + b, c);
}

TEST(TMatrix, addition_of_matrices_of_the_same_length2)
{
    TMatrix<int> a(2);
    TMatrix<int> b(2);
    TMatrix<int> c(2);
    TMatrix<int> d(2);

    a[0][0] = 4;
    a[0][1] = 4;
    a[1][1] = 4;

    b[0][0] = 1;
    b[0][1] = 1;
    b[1][1] = 1;

    d[0][0] = 5;
    d[0][1] = 5;
    d[1][1] = 5;
    c = a + b;
    EXPECT_EQ(c, d);
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

TEST(TMatrix, difference_of_matrices_of_the_same_length2)
{
    TMatrix<int> a(2);
    TMatrix<int> b(2);
    TMatrix<int> c(2);
    TMatrix<int> d(2);

    a[0][0] = 4;
    a[0][1] = 4;
    a[1][1] = 4;

    b[0][0] = 1;
    b[0][1] = 1;
    b[1][1] = 1;

    d[0][0] = 3;
    d[0][1] = 3;
    d[1][1] = 3;
    c = a - b;
    EXPECT_EQ(c, d);
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
    EXPECT_EQ(d, res);
}

