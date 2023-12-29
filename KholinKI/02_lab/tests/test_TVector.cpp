  #include "TVector.h"

#include <gtest.h>


//#СПРАВКА:clude <clocale>
//Описание макроса TEST():
//1)Пишем имя макроса(TEST)
//2)Первым параметром указываем набор тестов(класс или структура)
//3)Вторым параметром указываем имя теста
//4)В теле теста пишем проверочный код
//5)В конце дописываем утверждение



TEST(TVector, throw_when_create_vector_with_negative_length) {
	ASSERT_ANY_THROW(TVector<double> vec(-5));
}
TEST(TVector, throw_when_create_vector_with_zero_length) {
	ASSERT_ANY_THROW(TVector<double> vec(0));
}

TEST(TVector, can_create_vector_with_positive_length) {
	ASSERT_NO_THROW(TVector<double> vec(5));
}

TEST(TVector, throw_when_create_vector_with_negative_start_index) {
	ASSERT_ANY_THROW(TVector<double> vec(5, -2));
}

TEST(TVector, no_throw_when_create_vector_with_positive_start_index) {
	ASSERT_NO_THROW(TVector<double> vec(5, 2));
}

TEST(TVector, no_throw_when_use_constructor_copy) {
	TVector<double> vec1(3, 4);
	ASSERT_NO_THROW(TVector<double> vec(vec1));
}

TEST(TVector, different_addresses_memory) {
	TVector<double> vec1(3, 1);
	vec1[1] = 4;
	TVector<double> vec2(vec1);
	vec2[1] = 1;
	ASSERT_TRUE(vec1 != vec2);
}

TEST(TVector, no_throw_when_work_destructor) {
	TVector<double>* pVec = new TVector<double>(1, 2);
	ASSERT_NO_THROW(delete pVec);
}

TEST(TVector, can_get_length) {
	TVector<double> vec(10);
	EXPECT_EQ(10, vec.GetSize());
}

TEST(TVector, can_get_start_index) {
	TVector<double> vec(9,5);
	EXPECT_EQ(5, vec.GetStart());
}

TEST(TVector, can_get_element_with_positive_index) {
	TVector<int> vec(5);

	vec[4] = 2;
	
	EXPECT_EQ(2, vec[4]);
}

TEST(TVector, can_get_element) {
	TVector<double> vector(3, 1);
	vector[1] = 3;
	vector[2] = 4;
	EXPECT_EQ(4,vector[2]);
}

TEST(TVector, throw_when_get_element_with_negative_index) {
	TVector<int> vec(5);

	vec[4] = 2;

	ASSERT_ANY_THROW(vec[-4]);
}

TEST(TVector, throw_when_get_element_with_index_less_than_start_index) {
	TVector<int> vec(5,3);

	vec[4] = 2;

	ASSERT_ANY_THROW(vec[2]);
}

TEST(TVector, equality) {
	TVector<double> vector1(10,2),vector2(10,2);
	for (int i = vector1.GetStart(); i < vector1.GetSize(); i++) {
		vector1[i] = i;
	}

	for (int i = vector2.GetStart(); i < vector2.GetSize(); i++) {
		vector2[i] = i;
	}

	ASSERT_TRUE(vector1 == vector2);
}

TEST(TVector, no_equality_values) {
	TVector<double> vector1(10, 2), vector2(10, 2);
	for (int i = vector1.GetStart(); i < vector1.GetSize(); i++) {
		vector1[i] = i;
	}

	for (int i = vector2.GetStart(); i < vector2.GetSize(); i++) {
		vector2[i] = 3*i;
	}

	ASSERT_FALSE(vector1 == vector2);
}



TEST(TVector, no_equality_start_index) {
	TVector<double> vector1(10, 2), vector2(10, 1);
	for (int i = vector1.GetStart(); i < vector1.GetSize(); i++) {
		vector1[i] = i;
	}

	for (int i = vector2.GetStart(); i < vector2.GetSize(); i++) {
		vector2[i] = i;
	}

	ASSERT_FALSE(vector1 == vector2);
}

TEST(TVector, no_equality_lenghts) {
	TVector<double> vector1(7, 2), vector2(10, 1);
	for (int i = vector1.GetStart(); i < vector1.GetSize(); i++) {
		vector1[i] = i;
	}

	for (int i = vector2.GetStart(); i < vector2.GetSize(); i++) {
		vector2[i] = i;
	}

	ASSERT_FALSE(vector1 == vector2);
}

TEST(TVector, can_assign_vectors) {
	TVector<double> vec1(3, 4), vec2(4, 3);
	ASSERT_NO_THROW(vec1 = vec2);
}




TEST(TVector, triple_assign_vectors) {
	TVector<short> vector1(4), vector2(4), vector3(4);

	int i = 0;
	for (i = vector1.GetStart(); i < vector1.GetSize(); i++) {
		vector1[i] = i;
	}

	for (i = vector2.GetStart(); i < vector2.GetSize(); i++) {
		vector2[i] = 2*i;
	}

	for (i = vector3.GetStart(); i < vector3.GetSize(); i++) {
		vector3[i] = 3*i;
	}

	vector1 = vector2 = vector3;

	ASSERT_TRUE(vector1 == vector2);
	ASSERT_TRUE(vector2 == vector3);
	ASSERT_TRUE(vector1 == vector3);
}

TEST(TVector, no_throw_when_plus_operator_with_element) {
	TVector<double> vector1(10),res(1);

	for (int i = vector1.GetStart(); i < vector1.GetSize(); i++) {
		vector1[i] = i;
	}

	ASSERT_NO_THROW(res = vector1 + 6);
}


TEST(TVector, minus_operator_with_element) {
	TVector<double> vector1(10), res(1);

	for (int i = vector1.GetStart(); i < vector1.GetSize(); i++) {
		vector1[i] = i;
	}

	res = vector1 - 6;

	TVector<double> vector2(10);
	for (int i = vector2.GetStart(); i < vector2.GetSize(); i++) {
		vector2[i] = vector1[i] - 6;
	}
	EXPECT_EQ(res, vector2);
}

TEST(TVector, plus_operator_with_vectors_equal_size_and_start_index) {
	TVector<double> vector1(10), vector2(10),res1(1);

	for (int i = vector1.GetStart(); i < vector1.GetSize(); i++) {
		vector1[i] = i;
		
	}
	for (int i = vector2.GetStart(); i < vector2.GetSize(); i++) {
		vector2[i] = i;

	}

	ASSERT_NO_THROW(res1 = vector1 + vector2);
}

TEST(TVector, throw_when_plus_operator_with_vectors_non_equal_size) {
	TVector<double> vector1(9,4), vector2(10,4),res(1);

	for (int i = vector1.GetStart(); i < vector1.GetSize(); i++) {
		vector1[i] = i;
	}

	for (int i = vector1.GetStart(); i < vector2.GetSize(); i++) {
		vector2[i] = i;
	}
	
	ASSERT_ANY_THROW(res = vector1 + vector2);
}

TEST(TVector, can_plus_operator_with_vectors_equal_size_and_start_index) {
	TVector<double> vector1(10), vector2(10), res(1);

	for (int i = vector1.GetStart(); i < vector1.GetSize(); i++) {
		vector1[i] = i;

	}
	for (int i = vector2.GetStart(); i < vector2.GetSize(); i++) {
		vector2[i] = i;

	}

	res = vector1 + vector2;

	TVector<double> vec3(10);
	for (int i = vec3.GetStart(); i < vec3.GetSize(); i++) {
		vec3[i] = vector1[i]+vector2[i];
	}
	EXPECT_EQ(res, vec3);
}


TEST(TVector, throw_when_plus_operator_with_vectors_non_equal_start_index) {
	TVector<double> vector1(10, 3), vector2(10, 4), res1(1);

	for (int i = vector1.GetStart(); i < vector1.GetSize(); i++) {
		vector1[i] = i;
	}
	for (int i = vector2.GetStart(); i < vector2.GetSize(); i++) {
		vector2[i] = i;

	}

	ASSERT_ANY_THROW(vector1 + vector2);
}


TEST(TVector, mul_operator_with_vectors_equal_size_and_start_index) {
	TVector<double> vector1(10), vector2(10);

	for (int i = vector1.GetStart(); i < vector1.GetSize(); i++) {
		vector1[i] = i;
	}

	for (int i = vector1.GetStart(); i < vector2.GetSize(); i++) {
		vector2[i] = i;
	}
	double res;
    res = vector1 * vector2;
	EXPECT_EQ(285, res);
}


TEST(TVector, throw_when_mul_operator_with_vectors_non_equal_size) {
	TVector<double> vector1(10,4), vector2(9,4);

	for (int i = vector1.GetStart(); i < vector1.GetSize(); i++) {
		vector1[i] = i;
	}

	for (int i = vector2.GetStart(); i < vector2.GetSize(); i++) {
		vector2[i] = i;
	}
	double res;
	ASSERT_ANY_THROW(res = vector1 * vector2);	
}

TEST(TVector, throw_when_mul_operator_with_vectors_non_equal_start_index) {
	TVector<double> vector1(10, 3), vector2(10, 4);

	for (int i = vector1.GetStart(); i < vector1.GetSize(); i++) {
		vector1[i] = i;
	}

	for (int i = vector2.GetStart(); i < vector2.GetSize(); i++) {
		vector2[i] = i;
	}
	double res;
	ASSERT_ANY_THROW(res = vector1 * vector2);
}





