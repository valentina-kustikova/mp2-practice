#include "tvector.h"

#include <gtest.h>

/*
DefaultConstructorTest: 		Проверка конструктора по умолчанию.
ParameterizedConstructorTest: 	Проверка параметризованного конструктора.
CopyConstructorTest: 			Проверка конструктора копирования.
AssignmentOperatorTest: 		Проверка оператора присваивания.
GetSizeTest: 					Проверка метода GetSize().
GetStartIndexTest: 				Проверка метода GetStartIndex().
IndexingTest: 					Проверка оператора индексации operator[].
ScalarMultiplicationTest: 		Проверка оператора умножения на скаляр.
ScalarAdditionTest: 			Проверка оператора сложения с скаляром.
ScalarSubtractionTest: 			Проверка оператора вычитания с скаляром.
VectorAdditionTest: 			Проверка оператора сложения двух векторов.
VectorSubtractionTest: 			Проверка оператора вычитания двух векторов.
VectorDotProductTest: 			Проверка оператора скалярного произведения векторов.
EqualityTest: 					Проверка оператора сравнения на равенство.
InequalityTest: 				Проверка оператора сравнения на неравенство.
*/

// DefaultConstructorTests
TEST(TVector, DefaultConstructorTest){
	ASSERT_NO_THROW(TVector<int> v);
}

// ParameterizedConstructorTests
TEST(TVector, ParameterizedConstructorTest_PositiveLength){
	ASSERT_NO_THROW(TVector<int> v(3));
}

TEST(TVector, throw_ParameterizedConstructorTest_ZeroLength){
	ASSERT_ANY_THROW(TVector<int> v(0));
}

TEST(TVector, throw_ParameterizedConstructorTest_NegativeLength){
	ASSERT_ANY_THROW(TVector<int> v(-3));
}

TEST(TVector, throw_ParameterizedConstructorTest_NegativeStartIndex){
	ASSERT_ANY_THROW(TVector<int> v(3, -1));
}

// CopyConstructorTests
TEST(TVector, CopyConstructorTest){
	TVector<int> v(3);

	ASSERT_NO_THROW(TVector<int> test(v));
}

// GetSizeTests
TEST(TVector, GetSizeTest){
	TVector<int> v(3);

	EXPECT_EQ(3, v.GetSize());
}

// GetStartIndexTests
TEST(TVector, GetStartIndexTest){
	TVector<int> v(2, 2);

	EXPECT_EQ(2, v.GetStartIndex());
}

// IndexingTests
TEST(TVector, IndexingTest){
	TVector<int> v(3);
	v[2] = 2;
	EXPECT_EQ(2, v[2]);
}

TEST(TVector, throw_IndexingTest_TooLargeIndex){
	TVector<int> v1(3);
	ASSERT_ANY_THROW(v1[5]);

	TVector<int> v2(3, 1);
	ASSERT_ANY_THROW(v2[5]);
}

TEST(TVector, throw_IndexingTest_NegativeIndex){
	TVector<int> v(3);

	ASSERT_ANY_THROW(v[-1]);
}

TEST(TVector, throw_IndexingTest_IndexLessThanStartIndex){
	TVector<int> v(3, 2);
	ASSERT_ANY_THROW(v[0]);
}

// EqualityTests
TEST(TVector, EqualityTest_Equal) {
	int size = 3;
	TVector<int> v1(size);
	TVector<int> v2(size);
	for (int i = 0; i < size; i++) {
		v1[i] = i;
		v2[i] = i;
	}

	EXPECT_EQ(1, v1 == v2);


	TVector<int> v3(size, 2);
	TVector<int> v4(size, 2);
	for (int i = v3.GetStartIndex(); i < size; i++) {
		v3[i] = i;
		v4[i] = i;
	}

	EXPECT_EQ(1, v3 == v4);
}

TEST(TVector, EqualityTest_InequalSize) {
	int size1 = 3;
	int size2 = 4;
	
	TVector<int> v1(size1);
	TVector<int> v2(size2);

	EXPECT_EQ(0, v1 == v2);
}

TEST(TVector, EqualityTest_InequalStartIndex) {
	int size = 3;
	int sind1 = 1, sind2 = 2;

	TVector<int> v1(size, sind1);
	TVector<int> v2(size, sind2);

	EXPECT_EQ(0, v1 == v2);
}

// InequalityTests
TEST(TVector, InequalityTest_Equal) {
	int size = 3;
	TVector<int> v1(size);
	TVector<int> v2(size);
	for (int i = 0; i < size; i++) {
		v1[i] = i;
		v2[i] = i;
	}
	
	EXPECT_EQ(0, v1 != v2);


	TVector<int> v3(size, 2);
	TVector<int> v4(size, 2);
	for (int i = v3.GetStartIndex(); i < size; i++) {
		v3[i] = i;
		v4[i] = i;
	}

	EXPECT_EQ(0, v3 != v4);
}

TEST(TVector, InequalityTest_InequalSize) {
	int size1 = 3;
	int size2 = 4;

	TVector<int> v1(size1);
	TVector<int> v2(size2);

	EXPECT_EQ(1, v1 != v2);
}

TEST(TVector, InequalityTest_InequalStartIndex) {
	int size = 3;
	int sind1 = 1, sind2 = 2;

	TVector<int> v1(size, sind1);
	TVector<int> v2(size, sind2);

	EXPECT_EQ(1, v1 != v2);
}

// AssignmentOperatorTests
TEST(TVector, AssignmentOperatorTest_Self) {
	int size = 3;

	TVector<int> v1(size), expv(size);

	for (int i = 0; i < size; i++) {
		expv[i] = i;
		v1[i] = i;
	}

	v1 = v1;

	EXPECT_EQ(expv, v1);
}

TEST(TVector, AssignmentOperatorTest_EqualSize){
	int size = 3;

	TVector<int> v1(size), expv(size);

	for (int i = 0; i < size; i++) {
		expv[i] = i;
	}

	v1 = expv;

	EXPECT_EQ(expv, v1);
}

TEST(TVector, AssignmentOperatorTest_DifferentSize){
	int size = 3;
	int expsize = 5;

	TVector<int> v1(size), expv(expsize);

	for (int i = 0; i < expsize; i++) {
		expv[i] = i;
	}

	v1 = expv;

	EXPECT_EQ(expv, v1);
}

// ScalarMultiplicationTests
TEST(TVector, ScalarMultiplicationTest){
	int size = 4;
	int scalar = 2;
	
	// 1 2 3 4
	TVector<int> v(size);
	// 2 4 6 8
	TVector<int> expv(size);

	for (int i = 0; i < size; i++) {
		v[i] = i + 1;
		expv[i] = (i + 1) * scalar;
	}

	v = v * scalar;

	EXPECT_EQ(expv, v);
}

TEST(TVector, ScalarMultiplicationTest_WithStartIndex) {
	int size = 4;
	int sind = 2;
	int scalar = 2;

	// 0 0 1 2 3 4
	TVector<int> v(size, sind);
	// 0 0 2 4 6 8
	TVector<int> expv(size, sind);

	for (int i = sind; i < size + sind; i++) {
		v[i] = i + 1;
		expv[i] = (i + 1) * scalar;
	}

	v = v * scalar;

	EXPECT_EQ(expv, v);
}

// ScalarAdditionTests
TEST(TVector, ScalarAdditionTest){
	int size = 4;
	int scalar = 2;

	// 1 2 3 4
	TVector<int> v(size);
	// 3 4 5 6
	TVector<int> expv(size);

	for (int i = 0; i < size; i++) {
		v[i] = i + 1;
		expv[i] = (i + 1) + scalar;
	}

	v = v + scalar;

	EXPECT_EQ(expv, v);
}

TEST(TVector, ScalarAdditionTest_WithStartIndex) {
	int size = 4;
	int sind = 2;
	int scalar = 2;

	// 0 0 1 2 3 4
	TVector<int> v(size, sind);
	// 0 0 3 4 5 6
	TVector<int> expv(size, sind);

	for (int i = sind; i < size + sind; i++) {
		v[i] = i + 1;
		expv[i] = (i + 1) + scalar;
	}

	v = v + scalar;

	EXPECT_EQ(expv, v);
}

// ScalarSubtractionTests
TEST(TVector, ScalarSubtractionTest){
	int size = 4;
	int scalar = 2;

	// 1 2 3 4
	TVector<int> v(size);
	// -1 0 1 2
	TVector<int> expv(size);

	for (int i = 0; i < size; i++) {
		v[i] = i + 1;
		expv[i] = (i + 1) - scalar;
	}

	v = v - scalar;

	EXPECT_EQ(expv, v);
}

TEST(TVector, ScalarSubtractionTest_WithStartIndex) {
	int size = 4;
	int sind = 2;
	int scalar = 2;

	// 0 0 1 2 3 4
	TVector<int> v(size, sind);
	// 0 0 -1 0 1 2
	TVector<int> expv(size, sind);

	for (int i = sind; i < size + sind; i++) {
		v[i] = i + 1;
		expv[i] = (i + 1) - scalar;
	}

	v = v - scalar;

	EXPECT_EQ(expv, v);
}

// VectorAdditionTests
TEST(TVector, VectorAdditionTest){
	int size = 4;
	
	// 1 2 3 4
	TVector<int> v1(size);
	// 5 5 5 5
	TVector<int> v2(size);
	// 6 7 8 9
	TVector<int> expv(size);

	for (int i = 0; i < size; i++) {
		v1[i] = i + 1;
		v2[i] = 5;
		expv[i] = i + 1 + 5;
	}

	EXPECT_EQ(expv, v1 + v2);
}

TEST(TVector, throw_VectorAdditionTest_InequalSize){
	int size1 = 4;
	int size2 = 5;

	TVector<int> v1(size1);
	TVector<int> v2(size2);

	ASSERT_ANY_THROW(v1 + v2);
}

TEST(TVector, throw_VectorAdditionTest_InequalStartIndex){
	int size = 4;

	TVector<int> v1(size);
	TVector<int> v2(size, 1);

	ASSERT_ANY_THROW(v1 + v2);
}

// VectorSubtractionTests
TEST(TVector, VectorSubtractionTest){
	int size = 4;

	// 1 2 3 4
	TVector<int> v1(size);
	// 5 5 5 5
	TVector<int> v2(size);
	// -4 -3 -2 -1
	TVector<int> expv(size);

	for (int i = 0; i < size; i++) {
		v1[i] = i + 1;
		v2[i] = 5;
		expv[i] = i + 1 - 5;
	}

	EXPECT_EQ(expv, v1 - v2);
}

TEST(TVector, throw_VectorSubtractionTest_InequalSize){
	int size1 = 4;
	int size2 = 5;

	TVector<int> v1(size1);
	TVector<int> v2(size2);

	ASSERT_ANY_THROW(v1 - v2);
}

TEST(TVector, throw_VectorSubtractionTest_InequalStartIndex){
	int size = 4;

	TVector<int> v1(size);
	TVector<int> v2(size, 1);

	ASSERT_ANY_THROW(v1 - v2);
}

// VectorDotProductTests
TEST(TVector, VectorDotProductTest){
	int size = 4;
	
	// 1 2 3 4
	TVector<int> v1(size);
	// 5 5 5 5
	TVector<int> v2(size);
	
	int expValue = 50;

	for (int i = 0; i < size; i++) {
		v1[i] = i + 1;
		v2[i] = 5;
	}
	EXPECT_EQ(expValue, v1 * v2);
}

TEST(TVector, throw_VectorDotProductTest_InequalSize){
	int size1 = 4;
	int size2 = 5;

	TVector<int> v1(size1);
	TVector<int> v2(size2);

	ASSERT_ANY_THROW(v1 * v2);
}

TEST(TVector, throw_VectorDotProductTest_InequalStartIndex){
	int size = 4;

	TVector<int> v1(size);
	TVector<int> v2(size, 1);

	ASSERT_ANY_THROW(v1 * v2);
}