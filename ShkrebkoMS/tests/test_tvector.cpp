#include "tvector.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_len)
{
	ASSERT_NO_THROW(TVector<int>(5));
}

TEST(TVector, cant_create_vector_with_negative_len)
{
	ASSERT_ANY_THROW(TVector<int>(-5));
}

TEST(TVector, can_create_copied_vector)
{
	TVector<int> v(5);

	ASSERT_NO_THROW(TVector<int> b(v));
}

TEST(TVector, check_copy_vector)
{
	TVector<int> v(3);
	v[0] = 0;
	v[1] = 1;
	v[2] = 2;
	TVector<int> vc(v);
	ASSERT_EQ(v, vc);
}

TEST(TVector, can_get_length)
{
	TVector<int> v(5, 5);

	EXPECT_EQ(5, v.GetSize());
}

TEST(TVector, can_get_index)
{
	TVector<int> v(5, 5);

	EXPECT_EQ(5, v.GetStartIndex());
}


TEST(TVector, throws_when_position_is_less_then_0)
{
	TVector<int> v(6);

	ASSERT_ANY_THROW(v[-1]);
}

TEST(TVector, throws_when_position_is_greatere_then_size)
{
	TVector<int> v(6);

	ASSERT_ANY_THROW(v[8]);
}

 
TEST(TVector, compare_two_vectors_with_equal_sizes_is_true)
{
	TVector<int> v1(4);
	TVector<int> v2(4);
	for (int i = 0; i < 4; i++)
	{
		v1[i] = 1;
		v2[i] = 1;
	}


	ASSERT_TRUE(v1 == v2);
}


TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> v1(4);
	TVector<int> v2(4);
	for (int i = 0; i < 4; i++)
	{
		v1[i] = 1;
		v2[i] = 1;
	}
	ASSERT_NO_THROW(v1 = v2);
}

TEST(TVector, can_assign_vectors_of_non_size)
{
	TVector<int> v1(4);
	TVector<int> v2(5);
	for (int i = 0; i < 4; i++)
	{
		v1[i] = 1;
		v2[i] = 1;
	}
	v2[4] = 1;
	ASSERT_NO_THROW(v1 = v2);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> v1(5);
	for (int i = 0; i < 5; i++)
	{
		v1[i] = 1;
	}
	TVector<int> v2(5);
	v2 = v1;
	EXPECT_EQ(v1,v2);
}

TEST(TVector, compare_two_vectors_of_non_equal_sizes)
{
	TVector<int> v1(4);
	TVector<int> v2(5);
	v1[0] = 2;
	v1[1] = 3;
	v2[0] = 2;
	v2[1] = 3;
	EXPECT_NE(v1,v2);
}


TEST(TVector, can_multiply_vector_and_const)
{
	TVector<int> v(5);
	for (int i = 0; i < 5; i++)
	{
		v[i] = 1;
	}
	TVector<int> v1(5);
	v1 = v * 5;
	EXPECT_EQ(v1, v*5);
}


 
TEST(TVector, can_add_const_to_vector)
{
	TVector<int> v(5);
	for (int i = 0; i < 5; i++)
	{
		v[i] = 1;
	}
	TVector<int> v1(5);
	v1 = v + 5;
	EXPECT_EQ(v1, v + 5);
}


TEST(TVector, can_subtract_const_from_vector)
{
	TVector<int> v(5);
	for (int i = 0; i < 5; i++)
	{
		v[i] = 1;
	}
	TVector<int> v1(5);
	v1 = v - 5;
	EXPECT_EQ(v1, v - 5);
}

TEST(TVector, cant_plus_vectors_with_not_equal_sizes)
{
	TVector<int> v1(3);
	TVector<int> v2(2);
	for (int i = 0; i < 3; i++)
	{
		v1[i] = 1;
	}
	for (int i = 0; i < 2; i++)
	{
		v2[i] = 1;
	}
	ASSERT_ANY_THROW(v1 + v2);
}
TEST(TVector, cant_plus_vectors_with_not_equal_indexes)
{
	TVector<int> v1(3, 3);
	TVector<int> v2(4, 4);
	for (int i = 0; i < 3; i++)
	{
		v1[i] = 1;
	}
	for (int i = 0; i < 4; i++)
	{
		v2[i] = 1;
	}
	ASSERT_ANY_THROW(v1 + v2);
}


TEST(TVector, can_plus_vectors_with_equal_sizes)
{
	TVector<int> v1(3);
	TVector<int> v2(3);
	for (int i = 0; i < 3; i++)
	{
		v1[i] = 1;
	}
	for (int i = 0; i < 3; i++)
	{
		v2[i] = 1;
	}
	TVector<int> v3(3);
	v3 = v1 + v2;
	EXPECT_EQ(v1+v2, v3);
}
TEST(TVector, can_plus_vectors_with_equal_indexes)
{
	TVector<int> v1(3, 3);
	TVector<int> v2(3, 3);
	for (int i = 0; i < 3; i++)
	{
		v1[i] = 1;
	}
	for (int i = 0; i < 3; i++)
	{
		v2[i] = 1;
	}
	TVector<int> v3(3,3);
	v3 = v1 + v2;
	EXPECT_EQ(v1 + v2, v3);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_sizes)
{
	TVector<int> v1(3);
	TVector<int> v2(4);

	ASSERT_ANY_THROW(v1 - v2);
}



TEST(TVector, can_subtract_vectors_with_equal_sizes)
{
	TVector<int> v1(3);
	TVector<int> v2(3);

	ASSERT_NO_THROW(v1 - v2);
}

TEST(TVector, can_subtract_vectors_with_equal_indexes)
{
	TVector<int> v1(3, 3);
	TVector<int> v2(3, 3);

	ASSERT_NO_THROW(v1 - v2);
}

TEST(TVector, can_multiply_vectors_of_equal_sizes)
{
	TVector<int> v1(6);
	TVector<int> v2(6);

	ASSERT_NO_THROW(v1 * v2);
}
TEST(TVector, cant_multiply_vectors_of_not_equal_sizes)
{
	TVector<int> v1(3);
	TVector<int> v2(4);

	ASSERT_ANY_THROW(v1 * v2);
}

TEST(TVector, can_multiply_vectors_of_equal_indexes)
{
	TVector<int> v1(3, 2);
	TVector<int> v2(3, 2);

	ASSERT_NO_THROW(v1 * v2);
}
TEST(TVector, cant_multiply_vectors_of_not_equal_indexes)
{
	TVector<int> v1(3, 2);
	TVector<int> v2(3, 3);

	ASSERT_ANY_THROW(v1 * v2);
}