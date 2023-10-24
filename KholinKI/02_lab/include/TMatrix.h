#ifndef _TMATRIX_H
#define _TMATRIX_H

#include "TVector.h"

//#СПРАВКА:
//В реализациях методов достаточно вызвать конструктор базового класса.

template <class Type> class TMatrix : public TVector<TVector<Type>> {
public:
	//#конструкторы
	TMatrix(int mn = 10);//создание матрицы
	TMatrix(const TMatrix& matr);//копирование матриц
	TMatrix(const TVector<TVector<Type>>& v);//преобразование вектора векторов в матрицу

	//const TMatrix& operator=(const TMatrix& matr);//присваивание матриц

	//#сравнение матриц
	int operator ==(const TMatrix& matr)const;//проверка на равенство матриц
	int operator !=(const TMatrix& matr)const;//проверка на неравенство матриц

	//#матрично-скалярные операции
	TMatrix<Type> operator+(const Type& val);//сложение матрицы с элементом
	TMatrix<Type> operator-(const Type& val);//вычитание из матрицы элемента
	TMatrix<Type> operator*(const Type& val);//умножение матрицы с элементом

	//матричное-матричные операции
	TMatrix<Type> operator+(const TMatrix& matr);
	TMatrix<Type> operator-(const TMatrix& matr);
	TMatrix operator*(const TMatrix& matr);

	//#ввод/вывод
	friend istream& operator>>(istream& istr, TMatrix& obj) {
		for (int i = 0; i < obj.GetSize(); i++) {
			for (int j = 0; j < obj.GetSize(); j++) {
				istr >> obj.vector[i][j];
			}
		}
		return istr;
	}
	friend ostream& operator<<(ostream& ostr, const TMatrix& obj) {
		for (int i = 0; i < obj.GetSize(); i++) {
			for (int j = 0; j < obj.GetSize(); j++) {
				ostr << obj.vector[i][j];
			}
		}
		return ostr; 
	}
	
};

template <class Type>
TMatrix<Type>::TMatrix(int mn): TVector<TVector<Type>>(mn) {
	for (int i = 0; i < mn; i++) {
		vector[i] = TVector<Type>(mn - i, i);
	}
}

template <class Type>
TMatrix<Type>::TMatrix(const TMatrix<Type>& matr) {
	TVector<TVector<Type>>(matr);
}

template<class Type>
TMatrix<Type>::TMatrix(const TVector<TVector<Type>>& v): TVector<TVector<Type>>(v) {}   

template<class Type>
int TMatrix<Type>::operator ==(const TMatrix& matr)const {
	return TVector<TVector<Type>>::operator==(matr);
}

template<class Type>
int TMatrix<Type>::operator !=(const TMatrix& matr)const {
	return TVector<TVector<Type>>::operator!=(matr);
}

template<class Type>
TMatrix<Type> TMatrix<Type>::operator+(const Type& val) {
	return TVector<TVector<Type>>::operator+(val);
}

template<class Type>
TMatrix<Type> TMatrix<Type>::operator-(const Type& val) {
	return TVector<TVector<Type>>::operator-(val);
} 

template<class Type>
TMatrix<Type> TMatrix<Type>::operator*(const Type& val) {
	return TVector<TVector<Type>>::operator*(val);
}
template<class Type>
TMatrix<Type> TMatrix<Type>::operator+(const TMatrix& matr) {
	return TVector<TVector<Type>>::operator+(matr);
}

template<class Type>
TMatrix<Type> TMatrix<Type>::operator-(const TMatrix& matr) {
	return TVector<TVector<Type>>::operator-(matr);
}

template<class Type>
TMatrix<Type> TMatrix<Type>::operator*(const TMatrix<Type>& matr) {
	TVector<TVector<Type>> result_matrix(*this); 
	int I, j;
	for (I = 0; I < size; I++) {
		for (j = I; j < size; j++) {
			for (start_index = I; start_index < j; start_index++) {
				result_matrix[I][j] += (*this)[I][start_index] * matr.vector[start_index][j];
			}
		}
	}
	return TMatrix(result_matrix);
}

#endif