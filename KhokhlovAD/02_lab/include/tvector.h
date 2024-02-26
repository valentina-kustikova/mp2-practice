#ifndef _TVECTOR_
#define _TVECTOR_

#include<iostream>

using namespace std;

template <class T>
class TVec {
protected:
	int size;
	int start_ind;
	T* pMem;
public:
	TVec(int size = 5, int start_ind = 0); //конструктор по умолчанию/с параметром
	TVec(const TVec<T>& vec); //конструктор копирования
	~TVec(); //дестроктор

	int GetSize()const noexcept; //длина вектора
	int GetStartIndex()const noexcept; //стартовый индекс

	T& operator[](const int index); //перегрузка оператора индексации
	T& operator[](const int index)const; //перегрузка оператора индексации
	bool operator==(const TVec<T>& vec)const; //перегрузка оператора сравнения на равенство
	bool operator!=(const TVec<T>& vec)const; //перегрузка оператора сравнения на неравенство
	TVec operator*(const T& value); //перегрузка оператора умножения вектора на константу
	T operator*(const TVec<T>& vec); //перегрузка оператора произведения векторов
	TVec operator+(const T& value); //перегрузка оператора суммы вектора и числа
	TVec operator-(const T& value); //перегрузка оператора разности вектора и числа
	TVec operator+(const TVec<T>& vec); //перегрузка оператора суммы векторов
	TVec operator-(const TVec<T>& vec); //перегрузка оператора разности векторов
	const TVec& operator=(const TVec<T>& vec); //перегрузка операции присваивания

	friend ostream& operator<<(ostream& ostr, const TVec<T>& vec) //перегрузка потокового вывода
	{
		ostr << "|";
		for (int i = 0; i < vec.start_ind; i++) {
			ostr << "0 ";
		}
		for (int i = 0; i < vec.size - 1; i++) {
			ostr << vec.pMem[i] << " ";
		}
		ostr << vec.pMem[vec.size-1];
		ostr << "|" << endl;
		return ostr;
	};
	friend istream& operator>>(istream& istr, TVec<T>& vec) //перегрузка потокового ввода
	{
		cout << endl << "vec(start ind = " << vec.GetStartIndex() << " size = " << vec.GetSize() << ") = ";
		for (int i = 0; i < vec.size; i++) {
			istr >> vec.pMem[i];
		}
		cout << endl;
		return istr;
	};
};

template <class T>
TVec<T>::TVec(int size, int start_ind) {
	if (size < 0)
		throw "invalid size";
	this->size = size;
	if (start_ind < 0)
		throw "invalid start index";
	this->start_ind = start_ind;
	pMem = new T[size];
}

template <class T>
TVec<T>::TVec(const TVec<T>& vec) {
	size = vec.size;
	start_ind = vec.start_ind;
	pMem = new T[size];
	for (int i = 0; i < size; i++)
		pMem[i] = vec.pMem[i];
}

template <class T>
TVec<T>::~TVec() {
	delete[] pMem;
}

template <class T>
int TVec<T>::GetSize()const noexcept {
	return size;
}

template <class T>
int TVec<T>::GetStartIndex()const noexcept {
	return start_ind;
}

template <class T>
T& TVec<T>::operator[](const int index) {
	if (index < 0)
		throw "invalid index";
	if (index > size)
		throw "invalid index";
	return pMem[index];
}

template <class T>
T& TVec<T>::operator[](const int index)const {
	if (index < 0)
		throw "invalid index";
	if (index > size)
		throw "invalid index";
	return pMem[index];
}

template <class T>
bool TVec<T>::operator==(const TVec<T>& vec)const {
	if (start_ind != vec.start_ind)
		return false;
	if (size != vec.size)
		return false;
	for (int i = 0; i < size; i++)
		if (pMem[i] != vec.pMem[i])
			return false;
	return true;
}

template <class T>
bool TVec<T>::operator!=(const TVec<T>& vec)const {
	return !(*this == vec);
}

template <class T>
TVec<T> TVec<T>::operator*(const T& value) {
	TVec<T> tmp(*this);
	for (int i = 0; i < size; i++) {
		tmp.pMem[i] = pMem[i] * value;
	}
	return tmp;
}

template <class T>
T  TVec<T>::operator*(const TVec<T>& vec) {
	if (start_ind != vec.start_ind)
		throw "invalid size";
	if (size != vec.size)
		throw "invalid start index";
	T res = T();
	for (int i = 0; i < size; i++)
		res += pMem[i] * vec.pMem[i];
	return res;
}

template <class T>
TVec<T> TVec<T>::operator+(const TVec<T>& vec) {
	if (start_ind != vec.start_ind)
		throw "invalid size";
	if (size != vec.size)
		throw "invalid start index";
	TVec<T> tmp(size, start_ind);
	for (int i = 0; i < size; i++)
		tmp.pMem[i] = pMem[i] + vec.pMem[i];
	return tmp;
}

template <class T>
TVec<T> TVec<T>::operator-(const TVec<T>& vec) {
	if (start_ind != vec.start_ind)
		throw "invalid size";
	if (size != vec.size)
		throw "invalid start index";
	TVec<T> tmp(size, start_ind);
	for (int i = 0; i < size; i++)
		tmp.pMem[i] = pMem[i] - vec.pMem[i];
	return tmp;
}

template <class T>
TVec<T> TVec<T>::operator+(const T& value) {
	TVec<T> tmp(size, start_ind);
	for (int i = 0; i < size; i++)
		tmp.pMem[i] = pMem[i] + value;
	return tmp;
}

template <class T>
TVec<T> TVec<T>::operator-(const T& value) {
	TVec<T> tmp(size, start_ind);
	for (int i = 0; i < size; i++)
		tmp.pMem[i] = pMem[i] - value;
	return tmp;
}

template <class T>
const TVec<T>& TVec<T>::operator=(const TVec<T>& vec) {
	if (*this == vec)
		return *this;
	if (size != vec.size)
	{
		size = vec.size;
		delete[] pMem;
		pMem = new T[size];
	}
	start_ind = vec.start_ind;
	for (int i = 0; i < size; i++)
		pMem[i] = vec.pMem[i];
	return *this;
}
#endif