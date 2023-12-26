#pragma once

#include <iostream>
#include <iomanip>

using namespace std;

template <typename T>
class TVector {
protected:
	int size;
	int StartIndex;
	T* elems;
public:
	TVector(int _size = 10, int _st = 0);
	TVector(const TVector<T>& vec);
	virtual ~TVector();

	int GetSize() const;
	int GetStartIndex() const;

	T& operator[] (const int ind);

	friend std::istream& operator >> (std::istream& in, TVector& vec) {
		for (int i = 0; i < vec.GetSize(); i++) in >> vec.elems[i];
		return in;
	}
	friend ostream& operator << (ostream& out, TVector& vec) {
		for (int i = 0; i < vec.GetStartIndex(); i++) out << " 0 ";
		for (int i = 0; i < vec.GetSize(); i++) out << " " << vec.elems[i] << " ";
		return out;
	}

	const TVector<T>& operator = (const TVector<T>& vec);
	
	// vector - vector operation
	TVector<T> operator + (const TVector<T>& vec) const;
	TVector<T> operator - (const TVector<T>& vec) const;
	T operator * (const TVector<T>& vec) const;

	//vector - scalar operation
	TVector<T> operator + (const T num) const;
	TVector<T> operator - (const T num) const;
	TVector<T> operator * (const T num) const;

	//bool operation
	int operator == (const TVector<T>& vec) const;
	int operator != (const TVector<T>& vec) const;
};

template <typename T>
TVector<T>::TVector(int _size, int _st) {
	if (_size < 0 || _st < 0) throw "out_of_range";
	size = _size;
	StartIndex = _st;
	elems = new T[size];
}

template <typename T>
TVector<T>::TVector(const TVector<T>& vec) {
	size = vec.size;
	StartIndex = vec.StartIndex;
	elems = new T[size];
	for (int i = 0; i < size; i++) elems[i] = vec.elems[i];
}

template <typename T>
TVector<T>::~TVector() {
	if (size > 0) delete[] elems;
}

template <typename T>
int TVector<T>::GetSize() const {
	return size;
}

template <typename T>
int TVector<T>::GetStartIndex() const {
	return StartIndex;
}

template <typename T>
T& TVector<T>::operator[] (const int ind) {
	if (ind < 0 || ind > size + StartIndex) throw "out_of_range";
	if (ind < StartIndex) throw "elemen_not_exist";
	return elems[ind - StartIndex];
}

template <typename T>
const TVector<T>& TVector<T>::operator=(const TVector<T>& vec) {
	if ((*this) == vec) return (*this);
	if (size != vec.size) {
		size = vec.size;
		delete[] elems;
		elems = new T[size];
	}
	StartIndex = vec.StartIndex;
	for (int i = 0; i < size; i++) elems[i] = vec.elems[i];
	return (*this);
}

template<typename T>
TVector<T> TVector<T>::operator + (const TVector<T>& vec) const {
	if (size != vec.size) throw "Different sizes";
	if (StartIndex != vec.StartIndex) throw "Different start indexes";

	TVector<T> res(vec.size, vec.StartIndex);
	for (int i = 0; i < size; i++) 
		res.elems[i] = elems[i] + vec.elems[i];
	return res;
}

template<typename T>
TVector<T> TVector<T>::operator - (const TVector<T>& vec) const {
	if (size != vec.size) throw "Different sizes";
	if (StartIndex != vec.StartIndex) throw "Different start indexes";

	TVector<T> res(vec.size, vec.StartIndex);
	for (int i = 0; i < size; i++) 
		res.elems[i] = elems[i] - vec.elems[i];
	return res;
}

template <typename T>
T TVector<T>::operator * (const TVector<T>& vec) const {
	if (size != vec.size) throw "Different spaces";
	if (StartIndex != vec.StartIndex) throw "Different start indexes";

	T res = 0;
	for (int i = 0; i < size; i++) res += elems[i] * vec.elems[i];
	return res;
}

template <typename T>
TVector<T> TVector<T>::operator + (const T num) const {
	TVector<T> res(*this);
	for (int i = 0; i < size; i++) res.elems[i] += num;
	return res;
}

template <typename T>
TVector<T> TVector<T>::operator - (const T num) const {
	TVector<T> res(*this);
	for (int i = 0; i < size; i++) res.elems[i] -= num;
	return res;
}

template <typename T>
TVector<T> TVector<T>::operator * (const T num) const {
	TVector<T> res(*this);
	for (int i = 0; i < size; i++) res.elems[i] *= num;
	return res;
}

template <typename T>
int TVector<T>::operator == (const TVector<T>& vec) const {
	if (size != vec.size || StartIndex != vec.StartIndex) return false;
	for (int i = 0; i < size; i++) {
		if (elems[i] != vec.elems[i]) return false;
	}
	return true;
}

template <typename T>
int TVector<T>::operator != (const TVector<T>& vec) const {
	return !((*this) == vec);
}