#include "tvector.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length_without_startindex)
{
	ASSERT_NO_THROW(TVector<int>(3));
}

TEST(TVector, can_create_vector_with_positive_length_with_startindex)
{
	ASSERT_NO_THROW(TVector<int>(3, 1));
}

TEST(TVector, cannot_create_vector_with_negative_length_and_without_startindex)
{
	ASSERT_ANY_THROW(TVector<int>(-3));
}

TEST(TVector, cannot_create_vector_with_negative_length_and_with_startindex)
{
	ASSERT_ANY_THROW(TVector<int>(-3, 0));
}

TEST(TVector, can_create_copied_vector_without_startindex)
{
	TVector<int> a(3);

	ASSERT_NO_THROW(TVector<int> b(a));
}
TEST(TVector, can_create_copied_vector_with_startindex)
{
	TVector<int> a(3, 1);

	ASSERT_NO_THROW(TVector<int> b(a));
}
//get length
TEST(TVector, can_get_length_without_startindex)
{
	TVector<int> v(3);

	EXPECT_EQ(3, v.GetSize());
}

TEST(TVector, can_get_length_with_startindex)
{
	TVector<int> v(3, 3);

	EXPECT_EQ(3, v.GetSize());
}
//get index
TEST(TVector, can_get_index_with_startindex)
{
	TVector<int> v(3, 3);

	EXPECT_EQ(3, v.GetIndex());
}

TEST(TVector, can_get_index_without_startindex)
{
	TVector<int> v(3);

	EXPECT_EQ(0, v.GetIndex());
}

//operator []
TEST(TVector, throws_when_position_is_less_then_0_without_startindex)
{
	TVector<int> a1(6);

	ASSERT_ANY_THROW(a1[-5]);
}

TEST(TVector, throws_when_position_is_less_then_0_with_startindex)
{
	TVector<int> a1(6,1);

	ASSERT_ANY_THROW(a1[-5]);
}

TEST(TVector, throws_when_position_is_greatere_then_size_without_startindex)
{
	TVector<int> a1(6);

	ASSERT_ANY_THROW(a1[8]);
}

TEST(TVector, throws_when_position_is_greatere_then_size_with_startindex)
{
	TVector<int> a1(6,1);

	ASSERT_ANY_THROW(a1[8]);
}

TEST(TVector, when_position_is_adequate_without_startindex)
{
	TVector<int> a1(6);

	ASSERT_NO_THROW(a1[4]);
}

TEST(TVector, when_position_is_adequate_with_startindex)
{
	TVector<int> a1(6,1);

	ASSERT_NO_THROW(a1[4]);
}
//operator == 
TEST(TVector, compare_two_vectors_with_equal_sizes_is_true_without_startindex)
{
	TVector<int> v1(4);
	TVector<int> v2(4);
	for (int i = 0; i < 4; ++i)
	{
		v1[i] = 1;
		v2[i] = 1;
	}
	
	ASSERT_TRUE(v1 == v1);
}
TEST(TVector, compare_two_vectors_with_equal_sizes_is_true_with_startindex)
{
	TVector<int> v1(4,1);
	TVector<int> v2(4,1);
	for (int i = 0; i < 4; ++i)
	{
		v1[i] = 1;
		v2[i] = 1;
	}

	ASSERT_TRUE(v1 == v1);
}
TEST(TVector, compare_two_vectors_with_equal_sizes_is_true_with_different_startindex)
{
	TVector<int> v1(4, 1);
	TVector<int> v2(4, 2);
	for (int i = 0; i < 4; ++i)
	{
		v1[i] = 1;
		v2[i] = 1;
	}


	ASSERT_TRUE(v1 == v1);
}
//

TEST(TVector, can_assign_vectors_of_equal_size_without_startindex)
{
	TVector<int> v1(4);
	TVector<int> v2(4);

	ASSERT_NO_THROW(v1 = v2);
}

TEST(TVector, can_assign_vectors_of_equal_size_with_startindex)
{
	TVector<int> v1(4,1);
	TVector<int> v2(4,1);

	ASSERT_NO_THROW(v1 = v2);
}

TEST(TVector, can_assign_vectors_of_non_equal_size_without_startindex)
{
	TVector<int> v1(4);
	TVector<int> v2(5);

	ASSERT_NO_THROW(v1 = v2);
}

TEST(TVector, can_assign_vectors_of_non_equal_size_with_startindex)
{
	TVector<int> v1(4,1);
	TVector<int> v2(5,1);

	ASSERT_NO_THROW(v1 = v2);
}

TEST(TVector, can_assign_vector_to_itself_without_startindex)
{
	TVector<int> a(7);

	ASSERT_NO_THROW(a = a);
}

TEST(TVector, can_assign_vector_to_itself_with_startindex)
{
	TVector<int> a(7,2);

	ASSERT_NO_THROW(a = a);
}
//operator !=
TEST(TVector, compare_two_vectors_of_non_equal_sizes_without_startindex)
{
	TVector<int> v1(4);
	TVector<int> v2(5);

	ASSERT_TRUE(v1 != v2);
}

TEST(TVector, compare_two_vectors_of_non_equal_sizes_with_startindex)
{
	TVector<int> v1(4,1);
	TVector<int> v2(5,1);

	ASSERT_TRUE(v1 != v2);
}

TEST(TVector, compare_two_vectors_with_equal_sizes_with_startindex)
{
	TVector<int> v1(4, 1);
	TVector<int> v2(4, 1);
	for (int i = 0; i < 4; ++i)
	{
		v1[i] = 1;
		v2[i] = 2;
	}


	EXPECT_TRUE(v1 != v2);
}

TEST(TVector, compare_two_vectors_of_non_equal_sizes_with_different_startindex)
{
	TVector<int> v1(4, 1);
	TVector<int> v2(5, 2);

	ASSERT_TRUE(v1 != v2);
}

// vec * num
TEST(TVector, can_multiply_vector_and_const_without_startindex)
{
	TVector<int> a1(6);
	ASSERT_NO_THROW(a1 * 5);
}

TEST(TVector, can_multiply_const_vector_and_const_without_startindex)
{
	TVector<int> a1(6);
	TVector<int> a2(6);
	for (int i = 0; i < 6; i++)
	{
		a1[i] = 1 + i;
		a2[i] = (1 + i) * 5;
	}
	a1 = a1 * 5;

	EXPECT_EQ(a2, a1);
}

TEST(TVector, can_multiply_vector_and_const_with_startindex)
{
	TVector<int> a1(6,1);

	ASSERT_NO_THROW(a1 * 5);
}

TEST(TVector, can_multiply_const_vector_and_const_with_startindex)
{
	TVector<int> a1(6, 1);
	TVector<int> a2(6, 1);
	for (int i = 0; i < 6; i++)
	{
		a1[i] = 1 + i;
		a2[i] = (1 + i) * 5;
	}
	a1 = a1 * 5;
	
	EXPECT_EQ(a2, a1);
}

TEST(TVector, can_mult_without_startindex)
{
	TVector<int> v1(4);
	TVector<int> v2(4);
	for (int i(0); i < 4; ++i)
	{
		v1[i] = 1;
		v2[i] = 4;
	}

	v1 = v1 * 4;
	EXPECT_EQ(v1, v2);
}

TEST(TVector, can_mult_with_startindex)
{
	TVector<int> v1(4,1);
	TVector<int> v2(4,1);
	for (int i(0); i < 4; ++i)
	{
		v1[i] = 1;
		v2[i] = 4;
	}

	v1 = v1 * 4;
	EXPECT_EQ(v1, v2);
}

// vec add const 
TEST(TVector, can_add_const_to_vector_without_startindex)
{
	TVector<int> a1(6);

	ASSERT_NO_THROW(a1 + 5);
}

TEST(TVector, can_add_const_to_const_vector_without_startindex)
{
	TVector<int> a1(6);
	TVector<int> a2(6);
	for (int i = 0; i < 6; i++)
	{
		a1[i] = 1 + i;
		a2[i] = a1[i] + 5;
	}
	a1 = a1 + 5;
	EXPECT_EQ(a1, a2);
}

TEST(TVector, can_add_const_to_vector_with_startindex)
{
	TVector<int> a1(6,1);

	ASSERT_NO_THROW(a1 + 5);
}

TEST(TVector, can_add_const_to_const_vector_with_startindex)
{
	TVector<int> a1(6,1);
	TVector<int> a2(6,1);
	for (int i = 0; i < 6; i++)
	{
		a1[i] = 1 + i;
		a2[i] = a1[i] + 5;
	}
	a1 = a1 + 5;
	EXPECT_EQ(a1, a2);
}
//vec subtract const
TEST(TVector, can_subtract_const_from_vector_without_startindex)
{
	TVector<int> a1(6);

	ASSERT_NO_THROW(a1 - 5);
}

TEST(TVector, can_subtract_const_from_const_vector_without_startindex)
{
	TVector<int> a1(6);
	TVector<int> a2(6);
	for (int i = 0; i < 6; i++)
	{
		a1[i] = 1 + i;
		a2[i] = a1[i] - 5;
	}
	a1 = a1 - 5;
	EXPECT_EQ(a1, a2);
}

TEST(TVector, can_subtract_const_from_vector_with_startindex)
{
	TVector<int> a1(6,1);

	ASSERT_NO_THROW(a1 - 5);
}

TEST(TVector, can_subtract_const_from_const_vector_with_startindex)
{
	TVector<int> a1(6, 1);
	TVector<int> a2(6, 1);
	for (int i = 0; i < 6; i++)
	{
		a1[i] = 1 + i;
		a2[i] = a1[i] - 5;
	}
	a1 = a1 - 5;
	EXPECT_EQ(a1, a2);;
}

// vec + vec
TEST(TVector, cannot_plus_vectors_with_not_equal_sizes_with_startindex)
{
	TVector<int> a1(3,3);
	TVector<int> a2(4,3);

	ASSERT_ANY_THROW(a1 + a2);
}

TEST(TVector, cannot_plus_vectors_with_not_equal_sizes_without_startindex)
{
	TVector<int> a1(3);
	TVector<int> a2(4);

	ASSERT_ANY_THROW(a1 + a2);
}

TEST(TVector, cannot_plus_vectors_with_not_equal_indexes)
{
	TVector<int> a1(3,3);
	TVector<int> a2(4,4);

	ASSERT_ANY_THROW(a1 + a2);
}

TEST(TVector, can_plus_vectors_with_equal_sizes_with_startindex)
{
	TVector<int> a1(3,3);
	TVector<int> a2(3, 3);

	ASSERT_NO_THROW(a1 + a2);
}

TEST(TVector, can_plus_const_vectors_with_equal_sizes_with_startindex)
{
	TVector<int> a1(3, 3);
	TVector<int> a2(3, 3);
	TVector<int> v(3, 3);
	for (int i = 0; i < 3; i++)
	{
		a1[i] = 1 + i;
		a2[i] = i + 5;
		v[i] = 6 + 2*i;
	} 
	EXPECT_EQ(a1 + a2, v);
}

TEST(TVector, can_plus_vectors_with_equal_indexes_without_startindex)
{
	TVector<int> a1(3);
	TVector<int> a2(3);

	ASSERT_NO_THROW(a1 + a2);
}

TEST(TVector, can_plus_const_vectors_with_equal_indexes_without_startindex)
{
	TVector<int> a1(3);
	TVector<int> a2(3);
	TVector<int> v(3);
	for (int i = 0; i < 3; i++)
	{
		a1[i] = 1 + i;
		a2[i] = i + 5;
		v[i] = 6 + 2 * i;
	}
	EXPECT_EQ(a1 + a2, v);
}

// vec - vec 
TEST(TVector, cannot_subtract_vectors_with_not_equal_sizes_with_startindex)
{
	TVector<int> a1(3, 3);
	TVector<int> a2(4, 3);

	ASSERT_ANY_THROW(a1 - a2);
}

TEST(TVector, cannot_subtract_vectors_with_not_equal_sizes_without_startindex)
{
	TVector<int> a1(3);
	TVector<int> a2(4);

	ASSERT_ANY_THROW(a1 - a2);
}

TEST(TVector, cannot_subtract_vectors_with_not_equal_indexes)
{
	TVector<int> a1(3, 3);
	TVector<int> a2(4, 4);

	ASSERT_ANY_THROW(a1 - a2);
}

TEST(TVector, can_subtract_vectors_with_equal_sizes_with_startindexes)
{
	TVector<int> a1(3, 3);
	TVector<int> a2(3, 3);

	ASSERT_NO_THROW(a1 - a2);
}

TEST(TVector, can_subtract_vectors_with_equal_sizes_without_startindexes)
{
	TVector<int> a1(3);
	TVector<int> a2(3);

	ASSERT_NO_THROW(a1 - a2);
}

TEST(TVector, can_subtract_const_vectors_with_equal_sizes_with_startindexes)
{
	TVector<int> a1(3, 3);
	TVector<int> a2(3, 3);
	TVector<int> v(3);
	for (int i = 0; i < 3; i++)
	{
		a1[i] = 1 + i;
		a2[i] = i + 5;
		v[i] = -4; 
	}
	EXPECT_EQ(a1 - a2, v);
}
TEST(TVector, can_subtract_const_vectors_with_equal_sizes_without_startindexes)
{
	TVector<int> a1(3);
	TVector<int> a2(3);
	TVector<int> v(3);
	for (int i = 0; i < 3; i++)
	{
		a1[i] = 1 + i;
		a2[i] = i + 5;
		v[i] = -4;
	}
	EXPECT_EQ(a1 - a2, v);
}
//scalar *
TEST(TVector, can_multiply_vectors_of_equal_sizes_with_startindexes)
{
	TVector<int> a1(3,1);
	TVector<int> a2(3,1);

	ASSERT_NO_THROW(a1 * a2);
}

TEST(TVector, can_multiply_const_vectors_of_equal_sizes_with_startindexes)
{
	TVector<int> a1(3, 1);
	TVector<int> a2(3, 1);
	int s = 38;
	for (int i = 0; i < 3; i++)
	{
		a1[i] = 1 + i;
		a2[i] = i + 5;
	}

	EXPECT_EQ(a1 * a2, s);
}

TEST(TVector, can_multiply_vectors_of_equal_sizes_without_startindexes)
{
	TVector<int> a1(6);
	TVector<int> a2(6);

	ASSERT_NO_THROW(a1 * a2);
}

TEST(TVector, can_multiply_const_vectors_of_equal_sizes_without_startindexes)
{
	TVector<int> a1(3);
	TVector<int> a2(3);
	int s = 38;
	for (int i = 0; i < 3; i++)
	{
		a1[i] = 1 + i;
		a2[i] = i + 5;
	}

	EXPECT_EQ(a1 * a2, s);
}

TEST(TVector, cannot_multiply_vectors_of_not_equal_sizes)
{
	TVector<int> a1(6,2);
	TVector<int> a2(8,2);

	ASSERT_ANY_THROW(a1 * a2);
}

TEST(TVector, cannot_multiply_vectors_of_not_equal_indexes)
{
	TVector<int> a1(6,2);
	TVector<int> a2(6,3);

	ASSERT_ANY_THROW(a1 * a2);
}