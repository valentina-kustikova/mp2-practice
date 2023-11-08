#include "tmatrix.h"

#include <gtest.h>

/*
DefaultConstructorTest: 		Проверка конструктора по умолчанию.
ParameterizedConstructorTest: 	Проверка параметризованного конструктора.
CopyConstructorTest: 			Проверка конструктора копирования.
GetSizeTest: 					Проверка метода GetSize().
IndexingTest: 					Проверка оператора индексации operator[].
EqualityTest: 					Проверка оператора сравнения на равенство.
InequalityTest: 				Проверка оператора сравнения на неравенство.
AssignmentOperatorTest: 		Проверка оператора присваивания.
MatrixAdditionTest: 			Проверка оператора сложения двух векторов.
MatrixSubtractionTest: 			Проверка оператора вычитания двух векторов.
MatrixDotProductTest: 			Проверка оператора скалярного произведения векторов.
*/

// DefaultConstructorTests
TEST(TMatrix, DefaultConstructorTest){
	ASSERT_NO_THROW(TMatrix<int> m);
}

// ParameterizedConstructorTests
TEST(TMatrix, ParameterizedConstructorTest_PositiveLength){
	ASSERT_NO_THROW(TMatrix<int> m(3));
}

TEST(TMatrix, throw_ParameterizedConstructorTest_ZeroLength){
	ASSERT_ANY_THROW(TMatrix<int> m(0));
}

TEST(TMatrix, throw_ParameterizedConstructorTest_NegativeLength){
	ASSERT_ANY_THROW(TMatrix<int> m(-3));
}

// CopyConstructorTests
TEST(TMatrix, CopyConstructorTest){
	TMatrix<int> m(3);

	ASSERT_NO_THROW(TMatrix<int> test(m));
}

// GetSizeTests
TEST(TMatrix, GetSizeTest){
	TMatrix<int> m(3);

	EXPECT_EQ(3, m.GetSize());
}

// IndexingTests
TEST(TMatrix, IndexingTest_Value){
	int size = 3;
	
	// 1 2 3
	// 0 3 4
	// 0 0 5
	TMatrix<int> m(size);
	for (int i = 0; i < size; i++)
		for (int j = i; j < size; j++)
			m[i][j] = i + j + 1;

	int expValue = 4;
	EXPECT_EQ(expValue, m[1][2]);
}

TEST(TMatrix, IndexingTest_Vector) {
	int size = 3;

	// 1 2 3
	// 0 3 4
	// 0 0 5
	TMatrix<int> m(size);
	for (int i = 0; i < size; i++)
		for (int j = i; j < size; j++)
			m[i][j] = i + j + 1;

	TVector<int> expv(size);
	expv[0] = 1;
	expv[1] = 2;
	expv[2] = 3;
	EXPECT_EQ(expv, m[0]);

}

TEST(TMatrix, IndexingTest_VectorWithStartIndex) {
	int size = 3;

	// 1 2 3
	// 0 3 4
	// 0 0 5
	TMatrix<int> m(size);
	for (int i = 0; i < size; i++)
		for (int j = i; j < size; j++)
			m[i][j] = i + j + 1;

	TVector<int> expv(size - 1, 1);
	expv[1] = 3;
	expv[2] = 4;
	EXPECT_EQ(expv, m[1]);
}

TEST(TMatrix, throw_IndexingTest_TooLargeIndex){
	TMatrix<int> m(3);

	ASSERT_ANY_THROW(m[3]);

	ASSERT_ANY_THROW(m[0][4]);
}

TEST(TMatrix, throw_IndexingTest_NegativeIndex){
	TMatrix<int> m(3);

	ASSERT_ANY_THROW(m[-1]);

	ASSERT_ANY_THROW(m[0][-1]);
}

TEST(TMatrix, throw_IndexingTest_IndexLessThanStartIndex){
	TMatrix<int> m(3);

	ASSERT_ANY_THROW(m[2][0]);
}

// EqualityTests
TEST(TMatrix, EqualityTest_Equal){
	int size = 3;

	TMatrix<int> m1(size);
	TMatrix<int> m2(size);
	for (int i = 0; i < size; i++)
		for (int j = i; j < size; j++) {
			m1[i][j] = i + 1;
			m2[i][j] = i + 1;
		}

	EXPECT_EQ(1, m1 == m2);
}

TEST(TMatrix, EqualityTest_Inequal) {
	int size = 3;

	TMatrix<int> m3(size);
	TMatrix<int> m4(size);
	for (int i = 0; i < size; i++)
		for (int j = i; j < size; j++) {
			m3[i][j] = i + 1;
			m4[i][j] = i + 2;
		}
	EXPECT_EQ(0, m3 == m4);
}

TEST(TMatrix, EqualityTest_InequalSize){
	TMatrix<int> m1(3);
	TMatrix<int> m2(4);

	EXPECT_EQ(0, m1 == m2);
}

// InequalityTests
TEST(TMatrix, InequalityTest_Equal){
	int size = 3;

	TMatrix<int> m1(size);
	TMatrix<int> m2(size);
	for (int i = 0; i < size; i++)
		for (int j = i; j < size; j++) {
			m1[i][j] = i + 1;
			m2[i][j] = i + 1;
		}

	EXPECT_EQ(0, m1 != m2);
}

TEST(TMatrix, InequalityTest_Inequal) {
	int size = 3;

	TMatrix<int> m3(size);
	TMatrix<int> m4(size);
	for (int i = 0; i < size; i++)
		for (int j = i; j < size; j++) {
			m3[i][j] = i + 1;
			m4[i][j] = i + 2;
		}
	EXPECT_EQ(1, m3 != m4);
}

TEST(TMatrix, InequalityTest_InequalSize){
	TMatrix<int> m1(3);
	TMatrix<int> m2(4);

	EXPECT_EQ(1, m1 != m2);
}

// AssignmentOperatorTests
TEST(TMatrix, AssignmentOperatorTest_Self) {
	int size = 3;

	TMatrix<int> m(size), expm(size);

	for (int i = 0; i < size; i++)
		for (int j = i; j < size; j++) {
			m[i][j] = i + 1;
			expm[i][j] = i + 1;
		}

	m = m;

	EXPECT_EQ(expm, m);
}

TEST(TMatrix, AssignmentOperatorTest_EqualSize) {
	int size = 3;
	
	TMatrix<int> m(size), expm(size);

	for (int i = 0; i < size; i++)
		for (int j = i; j < size; j++) {
			expm[i][j] = i + 1;
		}

	m = expm;

	EXPECT_EQ(expm, m);
}

TEST(TMatrix, AssignmentOperatorTest_DifferentSize_SmallerToLarger) {
	int size1 = 3;
	int size2 = 4;

	TMatrix<int> m(size1), expm(size2);

	for (int i = 0; i < size2; i++)
		for (int j = i; j < size2; j++) {
			expm[i][j] = i + 1;
		}

	m = expm;

	EXPECT_EQ(expm, m);
}

TEST(TMatrix, AssignmentOperatorTest_DifferentSize_LargerToSmaller) {
	int size1 = 3;
	int size2 = 4;

	TMatrix<int> m(size2), expm(size1);

	for (int i = 0; i < size1; i++)
		for (int j = i; j < size1; j++) {
			expm[i][j] = i + 1;
		}

	m = expm;

	EXPECT_EQ(expm, m);
}

// MatrixAdditionTests
TEST(TMatrix, MatrixAdditionTest){
	int size = 3;
	
	TMatrix<int> m1(size), m2(size), expm(size);

	for (int i = 0; i < size; i++)
		for (int j = i; j < size; j++) {
			m1[i][j] = 1;
			m2[i][j] = 2;
			expm[i][j] = 3;
		}

	EXPECT_EQ(expm, m1 + m2);
}

TEST(TMatrix, throw_MatrixAdditionTest_InequalSize){
	int size1 = 3;
	int size2 = 4;

	TMatrix<int> m1(size1), m2(size2);

	ASSERT_ANY_THROW(m1 + m2);
}

// MatrixSubtractionTests
TEST(TMatrix, MatrixSubtractionTest){
	int size = 3;

	TMatrix<int> m1(size), m2(size), expm(size);

	for (int i = 0; i < size; i++)
		for (int j = i; j < size; j++) {
			m1[i][j] = 3;
			m2[i][j] = 1;
			expm[i][j] = 2;
		}

	EXPECT_EQ(expm, m1 - m2);
}

TEST(TMatrix, throw_MatrixSubtractionTest_InequalSize){
	int size1 = 3;
	int size2 = 4;

	TMatrix<int> m1(size1), m2(size2);

	ASSERT_ANY_THROW(m1 - m2);
}

// MatrixDotProductTests
TEST(TMatrix, MatrixMultiTest){
	int size = 3;

	TMatrix<int> m1(size), m2(size), expm(size);

	for (int i = 0; i < size; i++)
		for (int j = i; j < size; j++) {
			m1[i][j] = 2;
			m2[i][j] = 3;
		}

	expm[0][0] = 6;
	expm[0][1] = 12;
	expm[0][2] = 18;
	expm[1][1] = 6;
	expm[1][2] = 12;
	expm[2][2] = 6;

	EXPECT_EQ(expm, m1 * m2);
}

TEST(TMatrix, throw_MatrixMultiTest_InequalSize){
	int size1 = 3;
	int size2 = 4;

	TMatrix<int> m1(size1), m2(size2);

	ASSERT_ANY_THROW(m1 * m2);
}