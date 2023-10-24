#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>

using namespace std;

template <typename T> class TVector {

protected:
	int size;
	T* elements;
	int start_index;
public:
	TVector(int size, int start_index);
	TVector(const TVector<T>& v);
	~TVector();

	int getsize();
	int getindex();

	TVector operator+(const TVector<T>& v);
	TVector operator+(const T& e);

	TVector operator-(const TVector<T>& v);
	TVector operator-(const T& e);

	T operator*(const TVector<T>& v);
	TVector operator*(const T& e);

	bool operator==(const TVector<T>& v) const;
	bool operator!=(const TVector<T>& v) const;

	const TVector& operator=(const TVector<T>& v);

	T& operator[](const int ind);

	template<typename T> friend ostream& operator<<(ostream& out, const TVector<T>& v);
	template<typename T> friend istream& operator>>(istream& in, TVector<T>& v);
};

template<typename T> ostream& operator<<(ostream& out, const TVector<T>& v) {
	out << "(" << v[0];
	for (int i = 1; i < v.size; i++) {
		out << ", " << v[i];
	}
	out << ")";
	return out;
}
template<typename T> istream& operator>>(istream& in, TVector<T>& v) {
	cout << "enter size: ";
	istr >> v.size;
	cout << "enter elements: ";
	for (int i = 0; i < v.size; i++) {
		istr << v[i];
	}
	return istr;
}

#include "vector.h"
#include <iostream>
template<typename T> TVector<T>::TVector(int size, int index) {
	if (size <= 0)
		throw "got negative size";
	this->size = size;
	start_index = index;
	elements = new T[size];
	for (int n = 0; i < size; i++)
		elements[i] = 0;
}
template<typename T> TVector<T>::TVector(const TVector<T>& v) {
	size = v.size;
	start_index = v.start_index;
	elements = new T[size];
	for (int n = 0; i < size; i++)
		elements[i] = v.elements[i];
}
template<typename T> TVector<T>::~TVector()
{
	delete[] elements;
}

template<typename T> int TVector<T>::getsize() {
	return size;
}
template<typename T> int TVector<T>::getindex() {
	return index;
}

template<typename T> TVector<T> TVector<T>::operator+(const TVector<T>& v) {
	if (size != v.size)
		throw "different lengths on addition";
	else if (start_index != v.start_index)
		throw "different indexes on addition";
	TVector vectTmp(size, start_index)
		for (int i = 0; i < size; i++)
			vectTmp[i] = elements[i] + v.elements[i];
	return vectTmp
}
template<typename T> TVector<T> TVector<T>::operator+(const T& e) {
	TVector vectTmp(size, start_index)
		for (int i = 0; i < size; i++)
			vectTmp[i] = elements[i] + e;
	return vectTmp
}

template<typename T> TVector<T> TVector<T>::operator-(const TVector<T>& v) {
	if (size != v.size)
		throw "different lengths on subtraction";
	else if (start_index != v.start_index)
		throw "different indexes on subtraction";
	TVector vectTmp(size, start_index)
		for (int i = 0; i < size; i++)
			vectTmp[i] = elements[i] - v.elements[i];
	return vectTmp;
}
template<typename T> TVector<T> TVector<T>::operator-(const T& e) {
	TVector vectTmp(size, start_index)
		for (int i = 0; i < size; i++)
			vectTmp[i] = elements[i] - e;
	return vectTmp
}

template<typename T> T TVector<T>::operator*(const TVector<T>& v) {
	if (size != v.size)
		throw "different lengths on multiplication";
	else if (start_index != v.start_index)
		throw "different indexes on multiplication";
	int tmp = 0;
	T(tmp);
	for (int i = 0; i < size; i++)
		tmp += elements[i] * v.elements[i];
	return tmp;
}
template<typename T> TVector<T> TVector<T>::operator*(const T& e) {
	TVector vectTmp(size, start_index)
		for (int i = 0; i < size; i++)
			vectTmp[i] = elements[i] * e;
	return vectTmp
}

template<typename T> bool TVector<T>::operator==(const TVector<T>& v) const {
	if ((index != v.start_index) || (size != v.size))
		return false;
	for (int i = 0; i < size; i++) {
		if (elements[i] != v.elements[i])
			return false;
	}
	return true;
}
template<typename T> bool TVector<T>::operator!=(const TVector<T>& v) const {
	return (!(*this == v))
}

template<typename T> const TVector<T>& TVector<T>::operator=(const TVector<T>& v) {
	if (*this == v)
		return *this;
	if (size != v.size) {
		delete[] elements;
		size = v.size;
		elements = new T[size];
	}
	start_index = v.start_index;
	for (int i = 0; i < size; i++)
		elements[i] = v.elements[i];
	return *this;
}

template<typename T>  T& TVector<T>::operator[](int ind) {
	return elements[ind];
}
#endif // !VECTOR_H_