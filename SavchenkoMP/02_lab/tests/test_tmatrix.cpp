#include "tmatrix.h"

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
MatrixAdditionTest: 			Проверка оператора сложения двух векторов.
MatrixSubtractionTest: 			Проверка оператора вычитания двух векторов.
MatrixDotProductTest: 			Проверка оператора скалярного произведения векторов.
EqualityTest: 					Проверка оператора сравнения на равенство.
InequalityTest: 				Проверка оператора сравнения на неравенство.
*/


/*

TEST(TMatrix, ){
	
}

*/

// DefaultConstructorTests
TEST(TMatrix, DefaultConstructorTest){
	
}

// ParameterizedConstructorTests
TEST(TMatrix, ParameterizedConstructorTest_PositiveLength){
	
}

TEST(TMatrix, ParameterizedConstructorTest_ZeroLength_throw){
	
}

TEST(TMatrix, ParameterizedConstructorTest_NegativeLength_throw){
	
}

TEST(TMatrix, ParameterizedConstructorTest_NegativeStartIndex_throw){
	
}

// CopyConstructorTests
TEST(TMatrix, CopyConstructorTest){
	
}

// AssignmentOperatorTests
TEST(TMatrix, AssignmentOperatorTest_Self){
	
}

TEST(TMatrix, AssignmentOperatorTest_EqualSize){
	
}

TEST(TMatrix, AssignmentOperatorTest_DifferentSize){
	
}

// GetSizeTests
TEST(TMatrix, GetSizeTest){
	
}

// GetStartIndexTests
TEST(TMatrix, GetStartIndexTest){
	
}

// IndexingTests
TEST(TMatrix, IndexingTest){
	
}

TEST(TMatrix, IndexingTest_TooLargeIndex_throw){
	
}

TEST(TMatrix, IndexingTest_NegativeIndex_throw){
	
}

TEST(TMatrix, IndexingTest_IndexLessThanStartIndex_throw){
	
}

// EqualityTests
TEST(TMatrix, EqualityTest_Equal){
	
}

TEST(TMatrix, EqualityTest_InequalSize){
	
}

TEST(TMatrix, EqualityTest_InequalStartIndex){
	
}

// InequalityTests
TEST(TMatrix, InequalityTest_Equal){
	
}

TEST(TMatrix, InequalityTest_InequalSize){
	
}

TEST(TMatrix, InequalityTest_InequalStartIndex){
	
}

// ScalarMultiplicationTests
TEST(TMatrix, ScalarMultiplicationTest){
	
}

// ScalarAdditionTests
TEST(TMatrix, ScalarAdditionTest){
	
}

// ScalarSubtractionTests
TEST(TMatrix, ScalarSubtractionTest){
	
}

// MatrixAdditionTests
TEST(TMatrix, MatrixAdditionTest){
	
}

TEST(TMatrix, MatrixAdditionTest_InequalSize_throw){
	
}

TEST(TMatrix, MatrixAdditionTest_InequalStartIndex_throw){
	
}

// MatrixSubtractionTests
TEST(TMatrix, MatrixSubtractionTest){
	
}

TEST(TMatrix, MatrixSubtractionTest_InequalSize_throw){
	
}

TEST(TMatrix, MatrixSubtractionTest_InequalStartIndex_throw){
	
}

// MatrixDotProductTests
TEST(TMatrix, MatrixDotProductTest){
	
}

TEST(TMatrix, MatrixDotProductTest_InequalSize_throw){
	
}

TEST(TMatrix, MatrixDotProductTest_InequalStartIndex_throw){
	
}