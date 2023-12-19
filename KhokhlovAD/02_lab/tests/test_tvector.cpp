#include "tvector.h"

#include <gtest.h>



//constructors
///////////////////////////////////////////////////////////////////////////
TEST(TVec, can_create_vector_with_positive_length)
{
	ASSERT_NO_THROW(TVec<int> vec(3));
}

TEST(TVec, throws_when_create_vector_with_negative_length)
{
	ASSERT_ANY_THROW(TVec<int> vec(-3));
}

TEST(TVec, throws_when_create_vector_with_negative_startind)
{
	ASSERT_ANY_THROW(TVec<int> vec(3,-3));
}

TEST(TVec, can_copy_vector)
{
	TVec<int> vec1(3,1);
	ASSERT_NO_THROW(TVec<int> vec(vec1));
}

TEST(TVec, copy_own_memory) 
{
	TVec<int> vec1(3, 1);
	TVec<int> vec2(vec1);
	vec2[2] = 2;
	ASSERT_NE(vec1, vec2);
}
///////////////////////////////////////////////////////////////////////////




//get
///////////////////////////////////////////////////////////////////////////
TEST(TVec, can_get_length)
{
	TVec<int> vec(3);

	EXPECT_EQ(3, vec.GetSize());
}

TEST(TVec, can_get_startind)
{
	TVec<int> vec(3,5);

	EXPECT_EQ(5, vec.GetStartIndex());
}

TEST(TVec, can_get_index_value)
{
	TVec<int> vec(3);
	vec[0] = 1;
	vec[1] = 3;
	EXPECT_EQ(3, vec[1]);
}

TEST(TVec, cant_get_if_ind_less_zero)
{
	TVec<int> vec(3);
	ASSERT_ANY_THROW(int x = vec[-1]);
}


TEST(TVec, cant_get_if_ind_more_len)
{
	TVec<int> vec(3);
	ASSERT_ANY_THROW(int x = vec[10]);
}
///////////////////////////////////////////////////////////////////////////







//== !=
///////////////////////////////////////////////////////////////////////////
TEST(TVec, equality_equal_vectors_with_equal_start_index_and_equal_size)
{
	TVec<int> vec1(3);
	vec1[0] = 1;
	vec1[1] = 2;
	vec1[2] = 3;
	TVec<int> vec2(3);
	vec2[0] = 1;
	vec2[1] = 2;
	vec2[2] = 3;

	ASSERT_TRUE(vec1 == vec2);
}

TEST(TVec, equality_equal_vectors_with_not_equal_start_index_and_equal_size)
{
	TVec<int> vec1(3);
	vec1[0] = 1;
	vec1[1] = 2;
	vec1[2] = 3;
	TVec<int> vec2(3,1);
	vec2[0] = 1;
	vec2[1] = 2;
	vec2[2] = 3;

	ASSERT_FALSE(vec1 == vec2); 
}

TEST(TVec, equality_not_equal_vectors_with_equal_start_index_and_not_equal_size)
{
	TVec<int> vec1(2);
	vec1[0] = 1;
	vec1[1] = 2;
	TVec<int> vec2(3);
	vec2[0] = 1;
	vec2[1] = 2;
	vec2[2] = 3;

	ASSERT_FALSE(vec1 == vec2);
}

TEST(TVec, equality_not_equal_vectors_with_equal_start_index_and_equal_size)
{
	TVec<int> vec1(3);
	vec1[0] = 1;
	vec1[1] = 7;
	vec1[2] = 3;
	TVec<int> vec2(3);
	vec2[0] = 1;
	vec2[1] = 2;
	vec2[2] = 3;

	ASSERT_FALSE(vec1 == vec2);
}

TEST(TVec, inequality_equal_vectors_with_equal_start_index_and_equal_size)
{
	TVec<int> vec1(3);
	vec1[0] = 1;
	vec1[1] = 2;
	vec1[2] = 3;
	TVec<int> vec2(3);
	vec2[0] = 1;
	vec2[1] = 2;
	vec2[2] = 3;

	ASSERT_FALSE(vec1 != vec2);
}

TEST(TVec, inequality_equal_vectors_with_not_equal_start_index_and_equal_size)
{
	TVec<int> vec1(3);
	vec1[0] = 1;
	vec1[1] = 2;
	vec1[2] = 3;
	TVec<int> vec2(3, 1);
	vec2[0] = 1;
	vec2[1] = 2;
	vec2[2] = 3;

	ASSERT_TRUE(vec1 != vec2);
}

TEST(TVec, inequality_not_equal_vectors_with_equal_start_index_and_not_equal_size)
{
	TVec<int> vec1(2);
	vec1[0] = 1;
	vec1[1] = 2;
	TVec<int> vec2(3);
	vec2[0] = 1;
	vec2[1] = 2;
	vec2[2] = 3;

	ASSERT_TRUE(vec1 != vec2);
}

TEST(TVec, inequality_not_equal_vectors_with_equal_start_index_and_equal_size)
{
	TVec<int> vec1(3);
	vec1[0] = 1;
	vec1[1] = 7;
	vec1[2] = 3;
	TVec<int> vec2(3);
	vec2[0] = 1;
	vec2[1] = 2;
	vec2[2] = 3;

	ASSERT_TRUE(vec1 != vec2);
}
/////////////////////////////////////////////////////////////////////////////


//multiply vectirs
/////////////////////////////////////////////////////////////////////////////
TEST(TVec, can_multiply_vector_by_number)
{
	TVec<int> vec(3);
	vec[0] = 1;
	vec[1] = 2;
	vec[2] = 3;
	TVec<int> vec2(3);
	vec2[0] = 3;
	vec2[1] = 6;
	vec2[2] = 9;
	int value = 3;
	TVec<int> tmp(3);
	tmp = vec * value;
	EXPECT_EQ(tmp, vec2); 
}

TEST(TVec, cant_multiply_vector_by_number_with_different_start_index)
{
	TVec<int> vec1(3,1);
	vec1[0] = 1;
	vec1[1] = 2;
	vec1[2] = 3;
	TVec<int> vec2(3,5);
	vec2[0] = 4;
	vec2[1] = 5;
	vec2[2] = 6;
	ASSERT_ANY_THROW(vec1 * vec2);
}

TEST(TVec, cant_multiply_vector_by_number_with_different_size)
{
	TVec<int> vec1(4);
	vec1[0] = 1;
	vec1[1] = 2;
	vec1[2] = 3;
	TVec<int> vec2(3);
	vec2[0] = 4;
	vec2[1] = 5;
	vec2[2] = 6;
	ASSERT_ANY_THROW(vec1 * vec2);
}

TEST(TVec, can_multiply_vector_by_vector_with_equal_size_and_equal_start_index)
{
	TVec<int> vec1(3);
	vec1[0] = 1;
	vec1[1] = 2;
	vec1[2] = 3;
	TVec<int> vec2(3);
	vec2[0] = 4;
	vec2[1] = 5;
	vec2[2] = 6;
	double tmp = vec1 * vec2;
	EXPECT_EQ(32, tmp);
}

TEST(TVec, can_multiply_vector_by_vector_with_equal_size_and_equal_start_index_more_0)
{
	TVec<int> vec1(3,1);
	vec1[0] = 1;
	vec1[1] = 2;
	vec1[2] = 3;
	TVec<int> vec2(3,1);
	vec2[0] = 4;
	vec2[1] = 5;
	vec2[2] = 6;
	double tmp = vec1 * vec2;
	EXPECT_EQ(32, tmp);
}
/////////////////////////////////////////////////////////////////////////////




//add vectors
/////////////////////////////////////////////////////////////////////////////
TEST(TVec, can_add_vectors) 
{
	TVec<int> vec1(3);
	vec1[0] = 1;
	vec1[1] = 2;
	vec1[2] = 3;
	TVec<int> vec2(3);
	vec2[0] = 4;
	vec2[1] = 5;
	vec2[2] = 6;
	TVec<int> res(3);
	res[0] = 5;
	res[1] = 7;
	res[2] = 9;
	TVec<int> tmp(3);
	tmp = vec1 + vec2;
	EXPECT_EQ(res, tmp); 
}

TEST(TVec, cant_add_vectors_with_different_size)
{
	TVec<int> vec1(3);
	vec1[0] = 1;
	vec1[1] = 2;
	vec1[2] = 3;
	TVec<int> vec2(4);
	vec2[0] = 4;
	vec2[1] = 5;
	vec2[2] = 6;

	ASSERT_ANY_THROW(vec1 + vec2);
}

TEST(TVec, cant_add_vectors_with_different_start_index)
{
	TVec<int> vec1(3,1);
	vec1[0] = 1;
	vec1[1] = 2;
	vec1[2] = 3;
	TVec<int> vec2(3,5);
	vec2[0] = 4;
	vec2[1] = 5;
	vec2[2] = 6;

	ASSERT_ANY_THROW(vec1 + vec2);
}

TEST(TVec, can_add_vectors_with_start_index_more_0)
{
	TVec<int> vec1(3,6);
	vec1[0] = 1;
	vec1[1] = 2;
	vec1[2] = 3;
	TVec<int> vec2(3,6);
	vec2[0] = 4;
	vec2[1] = 5;
	vec2[2] = 6;
	TVec<int> res(3, 6);
	res[0] = 5;
	res[1] = 7;
	res[2] = 9;
	TVec<int> tmp(3,6);
	tmp = vec1 + vec2;
	EXPECT_EQ(res, tmp); 
}
/////////////////////////////////////////////////////////////////////////////




//substract vectors
/////////////////////////////////////////////////////////////////////////////
TEST(TVec, can_subtract_vectors)
{
	TVec<int> vec1(3);
	vec1[0] = 1;
	vec1[1] = 2;
	vec1[2] = 7;
	TVec<int> vec2(3);
	vec2[0] = 4;
	vec2[1] = 5;
	vec2[2] = 3;
	TVec<int> res(3);
	res[0] = -3;
	res[1] = -3;
	res[2] = 4;
	TVec<int> tmp(3);
	tmp = vec1 - vec2;
	EXPECT_EQ(res, tmp);
}

TEST(TVec, cant_subtract_vectors_with_different_size)
{
	TVec<int> vec1(3);
	vec1[0] = 1;
	vec1[1] = 2;
	vec1[2] = 6;
	TVec<int> vec2(4);
	vec2[0] = 4;
	vec2[1] = 5;
	vec2[2] = 3;
	ASSERT_ANY_THROW(vec1 - vec2);
}

TEST(TVec, cant_subtract_vectors_with_different_start_index)
{
	TVec<int> vec1(3,1);
	vec1[0] = 1;
	vec1[1] = 2;
	vec1[2] = 6;
	TVec<int> vec2(3,5);
	vec2[0] = 4;
	vec2[1] = 5;
	vec2[2] = 3;
	ASSERT_ANY_THROW(vec1 - vec2);
}

TEST(TVec, can_subtract_vectors_with_start_index_more_0)
{
	TVec<int> vec1(3,5);
	vec1[0] = 1;
	vec1[1] = 2;
	vec1[2] = 6;
	TVec<int> vec2(3,5);
	vec2[0] = 4;
	vec2[1] = 5;
	vec2[2] = 3;
	TVec<int> res(3, 5);
	res[0] = -3;
	res[1] = -3;
	res[2] = 3;
	TVec<int> tmp(3,5);
	tmp = vec1 - vec2;
	EXPECT_EQ(res, tmp);
}
/////////////////////////////////////////////////////////////////////////////




//add vector and const
/////////////////////////////////////////////////////////////////////////////
TEST(TVec, can_add_vector_and_const)
{
	TVec<int> vec1(3);
	vec1[0] = 1;
	vec1[1] = 2;
	vec1[2] = 3;
	TVec<int> res(3);
	res[0] = 3;
	res[1] = 4;
	res[2] = 5;
	int value = 2;
	TVec<int> tmp(3);
	tmp = vec1 + value;
	EXPECT_EQ(res, tmp);
}

TEST(TVec, can_add_vector_with_start_index_more_0_and_const)
{
	TVec<int> vec1(3,6);
	vec1[0] = 1;
	vec1[1] = 2;
	vec1[2] = 3;
	TVec<int> vec2(3, 6);
	vec2[0] = 3;
	vec2[1] = 4;
	vec2[2] = 5;
	int value = 2;
	TVec<int> tmp(3,6);
	tmp = vec1 + value;
	EXPECT_EQ(vec2, tmp);
}
/////////////////////////////////////////////////////////////////////////////




//subtract vector and const
/////////////////////////////////////////////////////////////////////////////
TEST(TVec, can_subtract_vector_and_const)
{
	TVec<int> vec1(3);
	vec1[0] = 1;
	vec1[1] = 2;
	vec1[2] = 6;
	TVec<int> res(3);
	res[0] = -1;
	res[1] = 0;
	res[2] = 4;
	int value = 2;
	TVec<int> tmp(3);
	tmp = vec1 - value;
	EXPECT_EQ(res, tmp);
}

TEST(TVec, can_subtract_vector_with_start_index_more_0_and_const)
{
	TVec<int> vec1(3,6);
	vec1[0] = 1;
	vec1[1] = 2;
	vec1[2] = 6;
	TVec<int> res(3,6);
	res[0] = -1;
	res[1] = 0;
	res[2] = 4;
	int value = 2;
	TVec<int> tmp(3,6);
	tmp = vec1 - value;
	EXPECT_EQ(res, tmp);
}
/////////////////////////////////////////////////////////////////////////////


//assign vectors
/////////////////////////////////////////////////////////////////////////////
TEST(TVec, can_assign_vectos)
{
	TVec<int> vec1(3);
	vec1[0] = 1;
	vec1[1] = 2;
	vec1[2] = 3;

	TVec<int> vec2(3);
	vec2 = vec1;

	EXPECT_EQ(vec2, vec1);
}

TEST(TVec, can_assign_vectos_with_different_size)
{
	TVec<int> vec1(3);
	vec1[0] = 1;
	vec1[1] = 2;
	vec1[2] = 3;

	TVec<int> vec2(5);
	vec2 = vec1;

	EXPECT_EQ(vec1, vec2);
}

TEST(TVec, can_assign_vectos_with_different_start_index)
{
	TVec<int> vec1(3,1);
	vec1[0] = 1;
	vec1[1] = 2;
	vec1[2] = 3;

	TVec<int> vec2(3,5);
	vec2 = vec1;

	EXPECT_EQ(vec1, vec2);
}

TEST(TVec, can_assign_3_vectors)
{
	TVec<int> vec1(3,2);
	vec1[0] = 1;
	vec1[1] = 2;
	vec1[2] = 3;

	TVec<int> vec2(2);
	TVec<int> vec3(1);
	vec2 = vec3 = vec1;

	EXPECT_EQ(vec2, vec1);
}
/////////////////////////////////////////////////////////////////////////////