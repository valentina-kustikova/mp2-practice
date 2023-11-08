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

TEST(TVector, cannot_create_vector_with_negative_length)
{
	ASSERT_ANY_THROW(TVector<int>(-3));
}

TEST(TVector, can_create_copied_vector)
{
	TVector<int> a(3);

	ASSERT_NO_THROW(TVector<int> b(a));
}
//get length
TEST(TVector, can_get_length)
{
	TVector<int> v(3, 3);

	EXPECT_EQ(3, v.GetSize());
}
//get index
TEST(TVector, can_get_index)
{
	TVector<int> v(3, 3);

	EXPECT_EQ(3, v.GetIndex());
}

//operator []
TEST(TVector, throws_when_position_is_less_then_0)
{
	TVector<int> a1(6);

	ASSERT_ANY_THROW(a1[-5]);
}

TEST(TVector, throws_when_position_is_greatere_then_size)
{
	TVector<int> a1(6);

	ASSERT_ANY_THROW(a1[8]);
}

TEST(TVector, when_position_is_adequate)
{
	TVector<int> a1(6);

	ASSERT_NO_THROW(a1[4]);
}
//operator == 
TEST(TVector, compare_two_vectors_with_equal_sizes_is_true)
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
//

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> v1(4);
	TVector<int> v2(4);

	ASSERT_NO_THROW(v1 = v2);
}

TEST(TVector, can_assign_vectors_of_non_equal_size)
{
	TVector<int> v1(4);
	TVector<int> v2(5);

	ASSERT_NO_THROW(v1 = v2);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> a(7);

	ASSERT_NO_THROW(a = a);
}
//operator !=
TEST(TVector, compare_two_vectors_of_non_equal_sizes)
{
	TVector<int> v1(4);
	TVector<int> v2(5);

	ASSERT_TRUE(v1 != v2);
}

// vec * num
TEST(TVector, can_multiply_vector_and_const)
{
	TVector<int> a1(6);

	ASSERT_NO_THROW(a1 * 5);
}

TEST(TVector, can_mult)
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

// vec add const 
TEST(TVector, can_add_const_to_vector)
{
	TVector<int> a1(6);

	ASSERT_NO_THROW(a1 + 5);
}

//vec subtract const
TEST(TVector, can_subtract_const_from_vector)
{
	TVector<int> a1(6);

	ASSERT_NO_THROW(a1 - 5);
}
// vec + vec
TEST(TVector, cannot_plus_vectors_with_not_equal_sizes)
{
	TVector<int> a1(3,3);
	TVector<int> a2(4,3);

	ASSERT_ANY_THROW(a1 + a2);
}

TEST(TVector, cannot_plus_vectors_with_not_equal_indexes)
{
	TVector<int> a1(3,3);
	TVector<int> a2(4,4);

	ASSERT_ANY_THROW(a1 + a2);
}

TEST(TVector, can_plus_vectors_with_equal_sizes)
{
	TVector<int> a1(3,3);
	TVector<int> a2(3, 3);

	ASSERT_NO_THROW(a1 + a2);
}

TEST(TVector, can_plus_vectors_with_equal_indexes)
{
	TVector<int> a1(3, 3);
	TVector<int> a2(3, 3);

	ASSERT_NO_THROW(a1 + a2);
}
// vec - vec 
TEST(TVector, cannot_subtract_vectors_with_not_equal_sizes)
{
	TVector<int> a1(3, 3);
	TVector<int> a2(4, 3);

	ASSERT_ANY_THROW(a1 - a2);
}

TEST(TVector, cannot_subtract_vectors_with_not_equal_indexes)
{
	TVector<int> a1(3, 3);
	TVector<int> a2(4, 4);

	ASSERT_ANY_THROW(a1 - a2);
}

TEST(TVector, can_subtract_vectors_with_equal_sizes)
{
	TVector<int> a1(3, 3);
	TVector<int> a2(3, 3);

	ASSERT_NO_THROW(a1 - a2);
}

TEST(TVector, can_subtract_vectors_with_equal_indexes)
{
	TVector<int> a1(3, 3);
	TVector<int> a2(3, 3);

	ASSERT_NO_THROW(a1 - a2);
}
//scalar *
TEST(TVector, can_multiply_vectors_of_equal_sizes)
{
	TVector<int> a1(6,2);
	TVector<int> a2(6,2);

	ASSERT_NO_THROW(a1 * a2);
}
TEST(TVector, cannot_multiply_vectors_of_not_equal_sizes)
{
	TVector<int> a1(6,2);
	TVector<int> a2(8,2);

	ASSERT_ANY_THROW(a1 * a2);
}

TEST(TVector, can_multiply_vectors_of_equal_indexes)
{
	TVector<int> a1(4, 2);
	TVector<int> a2(4, 2);

	ASSERT_NO_THROW(a1 * a2);
}
TEST(TVector, cannot_multiply_vectors_of_not_equal_indexes)
{
	TVector<int> a1(6,2);
	TVector<int> a2(6,3);

	ASSERT_ANY_THROW(a1 * a2);
}