
#include "TVector.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_size)
{
    ASSERT_NO_THROW(TVector<int> v(3));
}

TEST(TVector, can_create_vector_with_positive_size_and_StartIndex)
{
    ASSERT_NO_THROW(TVector<int> v(3,1));
}

TEST(TVector, cant_create_vector_with_negative_size)
{
    ASSERT_ANY_THROW(TVector<int> v(-3));
}

TEST(TVector, cant_create_vector_with_negative_StartIndex)
{
    ASSERT_ANY_THROW(TVector<int> v(3,-3));
}

TEST(TVector, checking_the_copy_constructor)
{
    TVector<int> a(3);
    ASSERT_NO_THROW(TVector<int> v(a));
}

TEST(TVector, copy_constructor_test_different_memory)
{
    TVector<int> a(3);
    a[0] = 0;
    a[1] = 1;
    a[2] = 2;
    TVector<int> b(a);
    b[0] = 1;
    EXPECT_NE(a[0], b[0]);
}

TEST(TVector, can_get_the_size)
{
    TVector<int> a(3,0);
    EXPECT_EQ(3, a.GetSize());
}

TEST(TVector, can_get_the_StartIndex)
{
    TVector<int> a(3, 0);
    EXPECT_EQ(0, a.GetStartIndex());
}

TEST(TVector, can_get_elem_by_index)
{
    TVector<int> a(3, 0);
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    EXPECT_EQ(2, a[1]);
}

TEST(TVector, cant_get_elem_by_index_less_then_StartIndex)
{
    TVector<int> a(5, 3);
    ASSERT_ANY_THROW(a[1]);
}

TEST(TVector, cant_get_elem_by_index_more_then_StartIndexPlusSize)
{
    TVector<int> a(3, 0);
    ASSERT_ANY_THROW(a[5]);
}

TEST(TVector, cant_get_elem_by_negative_index)
{
    TVector<int> a(3, 0);
    ASSERT_ANY_THROW(a[-3]);
}

TEST(TVector, checking_for_equality_of_different_vectors_of_the_same_length_1)
{
    TVector<int> a(3, 0);
    TVector<int> b(3, 0);
    for (int i = 0; i < 3; i++)
    {
        a[i] = i;
        b[i] = i;
    }
   ASSERT_TRUE(a == b);
}

TEST(TVector, checking_for_equality_of_different_vectors_of_the_same_length_2)
{
    TVector<int> a(3, 0);
    TVector<int> b(3, 0);
    for (int i = 0; i < 3; i++)
    {
        a[i] = 1 + i;
        b[i] = i;
    }
    ASSERT_FALSE(a == b);
}

TEST(TVector, checking_for_equality_of_different_vectors_of_different_size)
{
    TVector<int> a(3, 0);
    TVector<int> b(4, 0);
    ASSERT_FALSE(a == b);
}

TEST(TVector, checking_for_equality_of_different_vectors_of_different_StartIndex)
{
    TVector<int> a(4, 1);
    TVector<int> b(4, 0);
    ASSERT_FALSE(a == b);
}

TEST(TVector, checking_for_non_equality_of_the_same_vectors_of_the_same_lenght_1)
{
    TVector<int> a(3, 0);
    TVector<int> b(3, 0);
    for (int i = 0; i < 3; i++)
    {
        a[i] = i;
        b[i] = i;
    }
    ASSERT_FALSE(a != b);
}

TEST(TVector, checking_for_non_equality_of_different_vectors_of_the_same_length_2)
{
    TVector<int> a(3, 0);
    TVector<int> b(3, 0);
    for (int i = 0; i < 3; i++)
    {
        a[i] = 1 + i;
        b[i] = i;
    }
    ASSERT_TRUE(a != b);
}

TEST(TVector, checking_for_non_equality_of_different_vectors_of_different_size)
{
    TVector<int> a(3, 0);
    TVector<int> b(4, 0);
    ASSERT_TRUE(a != b);
}

TEST(TVector, checking_for_non_equality_of_different_vectors_of_different_StartIndex)
{
    TVector<int> a(4, 1);
    TVector<int> b(4, 0);
    ASSERT_TRUE(a != b);
}

TEST(TVector, checking_the_equalization_operator_for_vectors_with_the_same_length)
{
    TVector<int> a(3);
    TVector<int> b(3);
    for (int i = 0; i < 3; i++)
    {
        a[i] = i;
        b[i] = 1 + i;
    }
    ASSERT_NO_THROW(a = b);
}

TEST(TVector, checking_the_equalization_operator_for_vectors_with_different_lengths)
{
    TVector<int> a(5);
    TVector<int> b(3);
    for (int i = 0; i < 3; i++)
    {
        b[i] = 1 + i;
    }
    for (int j = 0; j < 5; j++)
    {
        a[j] = j;
    }
    ASSERT_NO_THROW(a = b);
}

TEST(TVector, checking_the_equalization_operator_for_vectors_with_different_StartIndex)
{
    TVector<int> a(4,0);
    TVector<int> b(4,1);
    ASSERT_NO_THROW(a = b);
}

TEST(TVector, self_equalization_check)
{
    TVector<int> a(4, 0);
    ASSERT_NO_THROW(a = a);
}

TEST(TVector, can_add_a_constant_to_the_vector)
{
    TVector<int> a(3);
    TVector<int> b(3);
    for (int i = 0; i < 3; i++)
    {
        a[i] = 1;
        b[i] = 4;
    }
    a = a + 3;
    EXPECT_EQ(a, b);
}

TEST(TVector, can_subtract_a_constant)
{
    TVector<int> a(3);
    TVector<int> b(3);
    for (int i = 0; i < 3; i++)
    {
        a[i] = 1;
        b[i] = 4;
    }
    b = b - 3;
    EXPECT_EQ(a, b);
}

TEST(TVector, can_multiply_by_a_constant)
{
    TVector<int> a(3);
    TVector<int> b(3);
    for (int i = 0; i < 3; i++)
    {
        a[i] = 1;
        b[i] = 3;
    }
    a = a * 3;
    EXPECT_EQ(a, b);
}

TEST(TVector, addition_of_vectors_of_the_same_length)
{
    TVector<int> a(3);
    TVector<int> b(3);
    for (int i = 0; i < 3; i++)
    {
        a[i] = 1;
        b[i] = 3;
    }
    ASSERT_NO_THROW(a+b);
}

TEST(TVector, addition_of_vectors_of_different_size)
{
    TVector<int> a(3);
    TVector<int> b(4);
    
    ASSERT_ANY_THROW(a + b);
}

TEST(TVector, addition_of_vectors_of_different_StartIndex)
{
    TVector<int> a(4,0);
    TVector<int> b(4,2);

    ASSERT_ANY_THROW(a + b);
}

TEST(TVector, addition_of_vectors_of_the_same_length_and_startIndex)
{
    TVector<int> a(4, 2);
    TVector<int> b(4, 2);

    ASSERT_NO_THROW(a + b);
}

TEST(TVector, difference_of_vectors_of_the_same_length)
{
    TVector<int> a(3);
    TVector<int> b(3);
    for (int i = 0; i < 3; i++)
    {
        a[i] = 1;
        b[i] = 3;
    }
    ASSERT_NO_THROW(b - a);
}

TEST(TVector, difference_of_vectors_of_different_size)
{
    TVector<int> a(3);
    TVector<int> b(4);

    ASSERT_ANY_THROW(a - b);
}

TEST(TVector, difference_of_vectors_of_different_StartIndex)
{
    TVector<int> a(4, 0);
    TVector<int> b(4, 2);

    ASSERT_ANY_THROW(a - b);
}

TEST(TVector, difference_of_vectors_of_the_same_length_and_startIndex)
{
    TVector<int> a(4, 2);
    TVector<int> b(4, 2);

    ASSERT_NO_THROW(a - b);
}


TEST(TVector, scalar_product_of_vectors_of_the_same_length)
{
    TVector<int> a(3);
    TVector<int> b(3);
    for (int i = 0; i < 3; i++)
    {
        a[i] = 1;
        b[i] = 3;
    }
    ASSERT_NO_THROW(b * a);
}

TEST(TVector, scalar_product_of_vectors_of_different_size)
{
    TVector<int> a(3);
    TVector<int> b(4);

    ASSERT_ANY_THROW(a * b);
}

TEST(TVector, scalar_product_of_vectors_of_different_StartIndex)
{
    TVector<int> a(4, 0);
    TVector<int> b(4, 2);

    ASSERT_ANY_THROW(a * b);
}

TEST(TVector, scalar_product_of_vectors_of_the_same_length_and_startIndex)
{
    TVector<int> a(4, 2);
    TVector<int> b(4, 2);

    ASSERT_NO_THROW(a * b);
}

TEST(TVector, checking_for_equality_of_different_vectors_of_the_same_length_and_different_startIndex)
{
    TVector<int> a(3, 1);
    TVector<int> b(3, 0);
    for (int i = 0; i < 3; i++)
    {
        b[i] = i;
    }
    for (int i = a.GetStartIndex(); i < 3; i++)
    {
        a[i] = i;
    }
    EXPECT_NE(a, b);
}

TEST(TVector, checking_for_equality_of_different_vectors_of_the_same_length_and_equal_startIndex)
{
    TVector<int> a(3, 1);
    TVector<int> b(3, 1);
    for (int i = b.GetStartIndex(); i < 3; i++)
    {
        b[i] = i;
    }
    for (int i = a.GetStartIndex(); i < 3; i++)
    {
        a[i] = i;
    }
    EXPECT_EQ(a, b);
}

TEST(TVector, checking_for_no_equality_of_different_vectors_of_the_same_length_and_equal_startIndex)
{
    TVector<int> a(3, 1);
    TVector<int> b(3, 1);
    for (int i = b.GetStartIndex(); i < 3; i++)
    {
        b[i] = i + 1;
    }
    for (int i = a.GetStartIndex(); i < 3; i++)
    {
        a[i] = i;
    }
    EXPECT_NE(a, b);
}

TEST(TVector, adding_two_vectors_checking_the_answer)
{
    TVector<int> a(3, 1);
    TVector<int> b(3, 1);
    TVector<int> c(3, 1);
    for (int i = b.GetStartIndex(); i < 3; i++)
    {
        b[i] = 1;
        a[i] = 2;
        c[i] = 3;
    }
    
    EXPECT_EQ(c, a+b);
}

TEST(TVector, adding_two_vectors_with_startIndex_checking_the_answer)
{
    TVector<int> a(3, 1);
    TVector<int> b(3, 1);
    TVector<int> c(3, 1);
    for (int i = b.GetStartIndex(); i < 3; i++)
    {
        b[i] = 1;
        a[i] = 2;
        c[i] = 3;
    }

    EXPECT_EQ(c, a + b);
}

TEST(TVector, the_difference_of_two_vectors_checking_the_response)
{
    TVector<int> a(3);
    TVector<int> b(3);
    TVector<int> c(3);
    TVector<int> k(3);
    for (int i = 0; i < 3; i++)
    {
        b[i] = 2;
        a[i] = 3;
        c[i] = -1;
    }
    k = b - a;

    EXPECT_EQ(c, k);
}

TEST(TVector, the_difference_of_two_vectors_with_startIndex_checking_the_response)
{
    TVector<int> a(3,1);
    TVector<int> b(3,1);
    TVector<int> c(3,1);
    TVector<int> k(3);
    for (int i = a.GetStartIndex(); i < a.GetSize(); i++)
    {
        b[i] = 3;
        a[i] = 2;
        c[i] = 1;
    }
 

    EXPECT_EQ(c, b-a);
}

TEST(TVector, scalar_product_of_two_vectors_checking_the_answer)
{
    TVector<int> a(3);
    TVector<int> b(3);
    for (int i = b.GetStartIndex(); i < 3; i++)
    {
        b[i] = 3;
        a[i] = 2; 
    }
    double v = b * a;
    double c = 18;

    EXPECT_EQ(c,v);
}

TEST(TVector, scalar_product_of_two_vectors_with_startIndex_checking_the_answer)
{
    TVector<int> a(2,1);
    TVector<int> b(2,1);
    for (int i = b.GetStartIndex(); i < 3; i++)
    {
        b[i] = 3;
        a[i] = 2;
    }
    double v = b * a;
    double c = 12;

    EXPECT_EQ(c, b*a);
}


