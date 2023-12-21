#include "tmatrix.h"

#include <gtest.h>

//constructors
///////////////////////////////////////////////////////////////////////////
TEST(TMatrix, can_create_matrix_with_positive_length)
{
	ASSERT_NO_THROW(TMatrix<int> mt(3));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
	ASSERT_ANY_THROW(TMatrix<int> mt(-13));
}

TEST(TMatrix, can_copy_matrix)
{
	TMatrix<int> mt1(3);
	ASSERT_NO_THROW(TMatrix<int> mt1(mt1)); // own memory
}

TEST(TMatrix, copy_own_memory)
{
	TMatrix<int> mt1(3);
	TMatrix<int> mt2(mt1);
	TVec<int> vec(2);
	vec[1] = 2;
	mt2[1] = vec;
	ASSERT_NE(mt1, mt2);
}
///////////////////////////////////////////////////////////////////////////


//assign matrix
///////////////////////////////////////////////////////////////////////////
TEST(TMatrix, can_assign_matrix)
{
	TMatrix<int> mt(2);
	TVec<int> vec1(2), vec2(1);

	vec1[0] = 1;
	vec1[1] = 1;


	vec2[0] = 1;

	mt[0] = vec1;
	mt[1] = vec2;

	TMatrix<int> mt2(2);
	mt2 = mt;

	EXPECT_EQ(mt, mt2);
}

TEST(TMatrix, can_assign_matrix_with_different_size)
{
	TMatrix<int> mt(2);
	TVec<int> vec1(2), vec2(1);

	vec1[0] = 1;
	vec1[1] = 1;


	vec2[0] = 1;

	mt[0] = vec1;
	mt[1] = vec2;

	TMatrix<int> mt2(1);
	mt2 = mt;

	EXPECT_EQ(mt, mt2);
}

TEST(TMatrix, can_assign_3_matrix_with_different_size)
{
	TMatrix<int> mt(2);
	TVec<int> vec1(2), vec2(1);

	vec1[0] = 1;
	vec1[1] = 1;


	vec2[0] = 1;

	mt[0] = vec1;
	mt[1] = vec2;

	TMatrix<int> mt1(3);

	TMatrix<int> mt2(1);
	mt2 = mt1 = mt;

	EXPECT_EQ(mt, mt2);
}
///////////////////////////////////////////////////////////////////////////



//add matrix
///////////////////////////////////////////////////////////////////////////
TEST(TMatrix, can_add_matrix)
{
	TMatrix<int> mt(2);
	TVec<int> vec1(2), vec2(1);

	vec1[0] = 1;
	vec1[1] = 1;


	vec2[0] = 1;

	mt[0] = vec1;
	mt[1] = vec2;
	TMatrix<int> mt2(2);
	TVec<int> vec3(2), vec4(1);

	vec3[0] = 1;
	vec3[1] = 1;

	vec4[0] = 1;


	mt2[0] = vec3;
	mt2[1] = vec4;

	TMatrix<int> res(2);
	TVec<int> res1(2), res2(1);
	res1[0] = 2;
	res1[1] = 2;
	res2[0] = 2;
	res[0] = res1;
	res[1] = res2;
	TMatrix<int> tmp(2);
	tmp = mt + mt2;
	EXPECT_EQ(res, tmp);
}

TEST(TMatrix, cant_add_matrix_with_different_size)
{
	TMatrix<int> mt(100);
	
	TMatrix<int> mt2(2);
	
	ASSERT_ANY_THROW(mt + mt2);
}
///////////////////////////////////////////////////////////////////////////



//subtract matrix
///////////////////////////////////////////////////////////////////////////
TEST(TMatrix, can_subtract_matrix)
{
	TMatrix<int> mt(2);
	TVec<int> vec1(2), vec2(1);

	vec1[0] = 1;
	vec1[1] = 1;


	vec2[0] = 1;

	mt[0] = vec1;
	mt[1] = vec2;
	TMatrix<int> mt2(2);
	TVec<int> vec3(2), vec4(1);

	vec3[0] = 1;
	vec3[1] = 1;

	vec4[0] = 1;


	mt2[0] = vec3;
	mt2[1] = vec4;

	TMatrix<int> res(2);
	TVec<int> res1(2), res2(1);
	res1[0] = 0;
	res1[1] = 0;
	res2[0] = 0;
	res[0] = res1;
	res[1] = res2;
	TMatrix<int> tmp(2);
	tmp = mt - mt2;
	EXPECT_EQ(res, tmp);
}

TEST(TMatrix, cant_subtrac_matrix_with_different_size)
{
	TMatrix<int> mt(3);

	TMatrix<int> mt2(2);

	ASSERT_ANY_THROW(mt - mt2);
}
///////////////////////////////////////////////////////////////////////////



//multiply matrix
///////////////////////////////////////////////////////////////////////////
TEST(TMatrix, can_multiply_matrix)
{
	TMatrix<int> mt(2);
	TVec<int> vec1(2), vec2(1);

	vec1[0] = 1;
	vec1[1] = 1;


	vec2[0] = 1;

	mt[0] = vec1;
	mt[1] = vec2;
	TMatrix<int> mt2(2);
	TVec<int> vec3(2), vec4(1);

	vec3[0] = 1;
	vec3[1] = 1;

	vec4[0] = 1;


	mt2[0] = vec3;
	mt2[1] = vec4;

	TMatrix<int> res(2);
	TVec<int> res1(2), res2(1,1);
	res1[0] = 1;
	res1[1] = 2;
	res2[0] = 1;
	res[0] = res1;
	res[1] = res2;
	TMatrix<int> tmp(2);
	tmp = mt * mt2;
	EXPECT_EQ(res, tmp);
}

TEST(TMatrix, cant_multiply_matrix_with_different_size)
{
	TMatrix<int> mt(3);

	TMatrix<int> mt2(2);

	ASSERT_ANY_THROW(mt * mt2);
}
///////////////////////////////////////////////////////////////////////////


//== !=
///////////////////////////////////////////////////////////////////////////
TEST(TMatrix, equality_equal_matrix_with_equal_size)
{
	TMatrix<int> mt(2);
	TVec<int> vec1(2), vec2(1);

	vec1[0] = 1;
	vec1[1] = 1;


	vec2[0] = 1;


	mt[0] = vec1;
	mt[1] = vec2;
	TMatrix<int> mt2(2);
	TVec<int> vec3(2), vec4(1);

	vec3[0] = 1;
	vec3[1] = 1;

	vec4[0] = 1;


	mt2[0] = vec3;
	mt2[1] = vec4;
	ASSERT_TRUE(mt == mt2);
}

TEST(TMatrix, equality_not_equal_matrix_with_equal_size)
{
	TMatrix<int> mt(2);
	TVec<int> vec1(2), vec2(1);

	vec1[0] = 1;
	vec1[1] = 2;


	vec2[0] = 1;

	mt[0] = vec1;
	mt[1] = vec2;
	TMatrix<int> mt2(2);
	TVec<int> vec3(2), vec4(1);

	vec3[0] = 1;
	vec3[1] = 1;

	vec1[0] = 1;


	mt2[0] = vec3;
	mt2[1] = vec4;
	ASSERT_FALSE(mt == mt2);
}

TEST(TMatrix, equality_matrix_with_not_equal_size)
{
	TMatrix<int> mt(100);

	TMatrix<int> mt2(2);

	ASSERT_FALSE(mt == mt2);
}


TEST(TMatrix, unequality_equal_matrix_with_equal_size)
{
	TMatrix<int> mt(2);
	TVec<int> vec1(2), vec2(1);

	vec1[0] = 1;
	vec1[1] = 1;


	vec2[0] = 1;

	mt[0] = vec1;
	mt[1] = vec2;
	TMatrix<int> mt2(2);
	TVec<int> vec3(2), vec4(1);

	vec3[0] = 1;
	vec3[1] = 1;

	vec4[0] = 1;


	mt2[0] = vec3;
	mt2[1] = vec4;
	ASSERT_FALSE(mt != mt2);
}
TEST(TMatrix, unequality_equal_matrix_with_not_equal_size)
{
	TMatrix<int> mt(1000);

	TMatrix<int> mt2(2);

	ASSERT_TRUE(mt != mt2);
}

TEST(TMatrix, unequality_not_equal_matrix_with_equal_size)
{
	TMatrix<int> mt(2);
	TVec<int> vec1(2), vec2(1);

	vec1[0] = 1;
	vec1[1] = 2;


	vec2[0] = 1;

	mt[0] = vec1;
	mt[1] = vec2;
	TMatrix<int> mt2(2);
	TVec<int> vec3(2), vec4(1);

	vec3[0] = 1;
	vec3[1] = 1;

	vec1[0] = 1;


	mt2[0] = vec3;
	mt2[1] = vec4;
	ASSERT_TRUE(mt != mt2);
}
///////////////////////////////////////////////////////////////////////////