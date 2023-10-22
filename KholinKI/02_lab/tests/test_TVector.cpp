#include "TVector.h"

#include <gtest.h>


//#СПРАВКА:
//Описание макроса TEST():
//1)Пишем имя макроса(TEST)
//2)Первым параметром указываем набор тестов(класс или структура)
//3)Вторым параметром указываем имя теста
//4)В теле теста пишем проверочный код
//5)В конце дописываем утверждение


//придумать тесты для параметра Vector
//проверить хвосты векторов

TEST(TVector, throw_when_create_vector_with_negative_length) {
	ASSERT_THROW(TVector<double> vec(-5), const Exeptions<int>);
}
TEST(TVector, throw_when_create_vector_with_zero_length) {
	ASSERT_THROW(TVector<double> vec(0), const Exeptions<int>);
}

TEST(TVector, can_create_vector_with_positive_length) {
	ASSERT_NO_THROW(TVector<double> vec(5));
}

TEST(TVector, throw_when_create_vector_with_negative_start_index) {
	ASSERT_THROW(TVector<double> vec(5, -2), const Exeptions<int>);
}

TEST(TVector, can_get_length) {
	TVector<double> vec(10);
	EXPECT_EQ(10, vec.GetSize());
}

TEST(TVector, can_get_start_index) {
	TVector<double> vec(9,5);
	EXPECT_EQ(5, vec.GetStart());
}

TEST(TVector, can_get_element_no_type_class) {
	TVector<int> vec(5);

	vec[4] = 2;
	
	EXPECT_EQ(2, vec[4]);
}

TEST(TVector, equality) {
	TVector<double> vector1(10,2),vector2(10,2);

	EXPECT_EQ(vector1.GetSize(), vector2.GetSize());
	EXPECT_EQ(vector1.GetStart(), vector2.GetStart());

	for (int i = 0; i < vector1.GetSize(); i++) {
		vector1[i] = i;
	}

	vector2 = vector1;
	EXPECT_EQ(vector1, vector2);
	EXPECT_EQ(vector1.GetSize(), vector2.GetSize());  
	EXPECT_EQ(vector1.GetStart(), vector2.GetStart()); 
}

TEST(TVector, plus_operator_with_element) {
	TVector<double> vector1(10),res1(1);

	for (int i = 0; i < vector1.GetSize(); i++) {
		vector1[i] = i;
	}

	res1 = vector1 + 6;

	TVector<double> test_vec(vector1);
	
	for (int i = 0; i < test_vec.GetSize(); i++) {
		test_vec[i] += 6;
	}

	EXPECT_EQ(test_vec, res1);
}

TEST(TVector, minus_operator_with_element) {
	TVector<double> vector1(10), res1(1);

	for (int i = 0; i < vector1.GetSize(); i++) {
		vector1[i] = i;
	}

	res1 = vector1 - 6;

	TVector<double> test_vec(vector1);

	for (int i = 0; i < test_vec.GetSize(); i++) {
		test_vec[i] -= 6;
	}

	EXPECT_EQ(test_vec, res1);
}

TEST(TVector, plus_operator_with_vectors_equal_size) {
	TVector<double> vector1(10), vector2(10),res1(1);

	for (int i = 0; i < vector1.GetSize(); i++) {
		vector1[i] = i;
		vector2[i] = i * 2;
	}
	res1 = vector1 + vector2;

	TVector<double> test_vector(vector1);

	for (int i = 0; i < test_vector.GetSize(); i++) {
		test_vector[i] += vector2[i];
	}
	EXPECT_EQ(test_vector, res1);
}

TEST(TVector, plus_operator_with_vectors_non_equal_size) {
	TVector<double> vector1(9), vector2(10), res1(1);

	for (int i = 0; i < vector1.GetSize(); i++) {
		vector1[i] = i;
		vector2[i] = i * 2;
	}
	res1 = vector1 + vector2;

	TVector<double> test_vector(vector1);

	for (int i = 0; i < test_vector.GetSize(); i++) {
		test_vector[i] += vector2[i];
	}
	EXPECT_EQ(test_vector, res1);
}

TEST(TVector, plus_operator_with_vectors_non_equal_start_index) {
	TVector<double> vector1(10,3), vector2(10), res1(1);

	for (int i = 0; i < vector1.GetSize(); i++) {
		vector1[i] = i;
		vector2[i] = i * 2;
	}
	res1 = vector1 + vector2;

	TVector<double> test_vector(vector1);

	for (int i = 0; i < test_vector.GetSize(); i++) {
		test_vector[i] += vector2[i];
	}
	EXPECT_EQ(test_vector, res1);
}

TEST(TVector, mul_operator_with_vectors_equal_size) {
	TVector<double> vector1(10), vector2(10);

	for (int i = 0; i < vector1.GetSize(); i++) {
		vector1[i] = i;
		vector2[i] = i * 2;
	}
	double res1 = vector1 * vector2;

	double test_res = 0;

	for (int i = 0; i < vector1.GetSize(); i++) {
		test_res += vector1[i] * vector2[i];
	}
	EXPECT_EQ(test_res, res1);
}

TEST(TVector, mul_operator_with_vectors_non_equal_size) {
	TVector<double> vector1(3), vector2(10);

	for (int i = 0; i < vector1.GetSize(); i++) {
		vector1[i] = i;
		vector2[i] = i * 2;
	}
	double res1 = vector1 * vector2;

	double test_res = 0;

	for (int i = 0; i < vector1.GetSize(); i++) {
		test_res += vector1[i] * vector2[i];
	}
	EXPECT_EQ(test_res, res1);
}

TEST(TVector, mul_operator_with_vectors_non_equal_start_index) {
	TVector<double> vector1(10,4), vector2(10);

	for (int i = 0; i < vector1.GetSize(); i++) {
		vector1[i] = i;
		vector2[i] = i * 2;
	}
	double res1 = vector1 * vector2;

	double test_res = 0;

	for (int i = 0; i < vector1.GetSize(); i++) {
		test_res += vector1[i] * vector2[i];
	}
	EXPECT_EQ(test_res, res1);
}





