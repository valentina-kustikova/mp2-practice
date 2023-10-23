#ifndef _TVECTOR_H
#define _TVECTOR_H


#include <iostream>
#include <limits>
#include "Exeption .h"

using namespace std;

template <class Type> class TVector {
protected:
	int start_index;
	int size;
	Type* vector;
public:
	//#конструкторы и деструктор
	TVector(int size_ = 10, int start_index_ = 0);//создание вектора
	TVector(const TVector<Type>& obj);//копирование векторов
	~TVector();//удаление вектора

	//#свойства вектора
	int GetSize() const;//получение размера
	int GetStart() const;//получение стартового индекса
	Type& operator[](const int index);//получение элемента вектора

	//#сравнение векторов
	int operator ==(const TVector<Type>& obj) const;//проверка на равенство векторов
	int operator !=(const TVector<Type>& obj) const;//проверка на неравенство векторов 
	
	TVector<Type>& operator=(const TVector<Type>& obj);//присваивание векторов

	//#векторно-скалярные операции
	TVector<Type> operator *(const Type& val);//умножение вектора с элементом 
	TVector<Type> operator +(const Type& val);//сложение вектора с элементом  
	TVector<Type> operator -(const Type& val);//вычитание из вектора элемента

	//#векторно-векторные операции
	TVector<Type> operator +(const TVector<Type>& obj);
	TVector<Type> operator -(const TVector<Type>& obj);
	Type operator*(const TVector<Type>& obj);


	//#ввод/вывод
	friend istream& operator>>(istream& istr, TVector<Type>& obj) {
		for (int i = 0; i < obj.GetSize(); i++) {
			istr >> obj.vector[i];
		}
		return istr;
	}

	friend ostream& operator<<(ostream& ostr,const TVector<Type>& obj) {
		cout << "(";
		for (int i = 0; i < obj.size; i++) {
			ostr << obj.vector[i];
			if (i == obj.size - 1) { continue; }
			cout << ",";
		}
		cout << ")" << endl;
		return ostr;
	}
};




template <class Type>
TVector<Type>::TVector(int size_, int start_index_) {
	if (size_ <= 0 || size_ > INT_MAX) {
		throw Exeptions<int>(WRONG_SIZE, size_);
	}
	if (start_index_ < 0 || start_index_ >= size_) {
		throw Exeptions<int>(WRONG_INDEX, start_index_);
	}
	size = size_;
	start_index = start_index_;
	vector = new Type[size];

}

template <class Type>
TVector<Type>::TVector(const TVector<Type>& obj) {
	size = obj.size;
	start_index = obj.start_index;
	vector = new Type[size];
	for (int i = 0; i < obj.size; i++) {
		vector[i] = obj.vector[i];
	}
}

template<class Type>
TVector<Type>::~TVector() {
	delete[] vector;
	size = 0;
	start_index = 0;
}
template<class Type>
int TVector<Type>::GetSize() const {
	return size;
}

template<class Type>
int TVector<Type>::GetStart() const {
	return start_index;
}

template<class Type>
Type& TVector<Type>::operator[](const int index) {
	return vector[index]; 
}

template<class Type>
TVector<Type>& TVector<Type>::operator=(const TVector<Type>& obj) {
	if (this == &obj) {
		return *this;
	}
	if (start_index != obj.start_index) {
		start_index = obj.start_index;
	}
	if (size != obj.size) {
		delete[] vector;
		size = obj.size;
		vector = new Type[size];
	}
	for (int i = 0; i < size; i++) {
		vector[i] = obj.vector[i];
	}
	return *this;
}

template<class Type>
int TVector<Type>::operator==(const TVector<Type>& obj)const {
	if (size != obj.size) {
		return false;
	}
	if (start_index != obj.start_index) {
		return false;
	}
	for (int i = 0; i < size; i++) {
		if (vector[i] != obj.vector[i]) {
			return false;
		}
	}
	return true;
}

template<class Type>
int TVector<Type>::operator !=(const TVector<Type>& obj) const {
	return !(*this == obj);
}

template<class Type>
TVector<Type> TVector<Type>::operator*(const Type& val) {
	TVector<Type> tmp(*this); 
	for (int i = 0; i < tmp.size; i++) {
		tmp[i] *= val;
	}
	return tmp;
}

template<class Type>
TVector<Type> TVector<Type>::operator+(const Type& val) {
	TVector<Type> tmp(*this);
	for (int i = 0; i < tmp.size; i++) {
		tmp[i] += val;
	}
	return tmp;
}

template<class Type>
TVector<Type> TVector<Type>::operator-(const Type& val) {
	TVector<Type> tmp(*this);
	for (int i = 0; i < tmp.size; i++) {
		tmp[i] -= val;
	}
	return tmp;
}

template<class Type>
TVector<Type> TVector<Type>::operator+(const TVector<Type>& obj) {
	if (size != obj.size || start_index != obj.start_index) {
		Type* tmp_vector = new Type[obj.size]; 
		memcpy(tmp_vector, vector, sizeof(Type)* size);  
		delete[] vector; 
		start_index = obj.start_index; 
		size = obj.size; 
		vector = tmp_vector;
	}
	TVector<Type> result(*this);
	for (int i = 0; i < result.size; i++) {
		result.vector[i] += obj.vector[i];
	}
	return result;
}

template<class Type>
TVector<Type> TVector<Type>::operator-(const TVector<Type>& obj) {
	if (size != obj.size || start_index != obj.start_index) {
		Type* tmp_vector = new Type[obj.size];
		memcpy(tmp_vector, vector, sizeof(Type) * size);
		delete[] vector;
		start_index = obj.start_index;
		size = obj.size;
		vector = tmp_vector;
	}
	TVector<Type> result(*this);
	for (int i = 0; i < result.size; i++) {
		result.vector[i] -= obj.vector[i];
	}
	return result;
}

template<class Type>
Type TVector<Type>::operator*(const TVector<Type>& obj) {
	if (size != obj.size || start_index != obj.start_index) {
		Type* tmp_vector = new Type[obj.size];
		memcpy(tmp_vector, vector, sizeof(Type) * size);
		delete[] vector;
		start_index = obj.start_index;
		size = obj.size;
		vector = tmp_vector;
	}
	Type result=0;
	for (int i = 0; i < size; i++) {
		result += vector[i] * obj.vector[i];
	}
	return result;
}





#endif