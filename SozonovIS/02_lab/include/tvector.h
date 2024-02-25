#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <iostream>

using namespace std;

template <typename ValueType>
class TVector {
protected:
	int size;
	int startIndex;
	ValueType* pVector;
public:
	TVector(int size = 5, int startIndex = 0);
	TVector(const TVector<ValueType>& v);
	~TVector();
	int GetSize() const;
	int GetStartIndex() const;
	ValueType& operator[](const int i);
	int operator==(const TVector<ValueType>& v) const;
	int operator!=(const TVector<ValueType>& v) const;
	const TVector& operator=(const TVector<ValueType>& v);
	TVector operator+(const ValueType t);
	TVector operator-(const ValueType t);
	TVector operator*(const ValueType t);
	TVector operator+(const TVector<ValueType>& v);
	TVector operator-(const TVector<ValueType>& v);
	double operator*(const TVector<ValueType>& v);
	friend istream& operator>>(istream& in, TVector<ValueType>& v) {
		for (int i = 0; i < v.size; i++)
			in >> v.pVector[i];
		return in;
	}
	friend ostream& operator<<(ostream& out, const TVector<ValueType>& v) {
		for (int i = 0; i < v.size; i++)
			out << v.pVector[i] << " ";
		return out;
	}
};

template <typename ValueType>
TVector<ValueType>::TVector(int size, int startIndex) : size(size), startIndex(startIndex) {
	if (size <= 0)
		throw exception("vector size should be greater than zero");
	if (startIndex < 0)
		throw exception("vector start index should be at least zero");
	pVector = new ValueType[size]();
}

template <typename ValueType>
TVector<ValueType>::TVector(const TVector<ValueType>& v) : size(v.size), startIndex(v.startIndex) {
	pVector = new ValueType[size];
	for (int i = 0; i < size; i++)
		pVector[i] = v.pVector[i];
}

template <typename ValueType>
TVector<ValueType>::~TVector() {
	delete[] pVector;
}

template <typename ValueType>
int TVector<ValueType>::GetSize() const {
	return size;
}

template <typename ValueType>
int TVector<ValueType>::GetStartIndex() const {
	return startIndex;
}

template <typename ValueType>
ValueType& TVector<ValueType>::operator[](const int i) {
	if (i < 0 || i >= size)
		throw exception("out of range");
	return pVector[i];
}

template <typename ValueType>
int TVector<ValueType>::operator==(const TVector<ValueType>& v) const {
	if (size != v.size || startIndex != v.startIndex)
		return 0;
	for (int i = 0; i < size; i++)
		if (pVector[i] != v.pVector[i])
			return 0;
	return 1;
}

template <typename ValueType>
int TVector<ValueType>::operator!=(const TVector<ValueType>& v) const {
	return !(*this == v);
}

template <typename ValueType>
const TVector<ValueType>& TVector<ValueType>::operator=(const TVector<ValueType>& v) {
	if (this == &v)
		return *this;
	if (size != v.size || startIndex != v.startIndex) {
		delete[] pVector;
		size = v.size;
		startIndex = v.startIndex;
		pVector = new ValueType[size];
	}
	for (int i = 0; i < size; i++) {
		pVector[i] = v.pVector[i];
	}
	return *this;
}

template <typename ValueType>
TVector<ValueType> TVector<ValueType>::operator+(const ValueType t) {
	TVector<ValueType> tmp(*this);
	for (int i = 0; i < size; i++)
		tmp[i] += t;
	return tmp;
}

template <typename ValueType>
TVector<ValueType> TVector<ValueType>::operator-(const ValueType t) {
	TVector<ValueType> tmp(*this);
	for (int i = 0; i < size; i++)
		tmp[i] -= t;
	return tmp;
}

template <typename ValueType>
TVector<ValueType> TVector<ValueType>::operator*(const ValueType t) {
	TVector<ValueType> tmp(*this);
	for (int i = 0; i < size; i++)
		tmp[i] *= t;
	return tmp;
}
template <typename ValueType>
TVector<ValueType> TVector<ValueType>::operator+(const TVector<ValueType>& v) {
	if (size != v.size || startIndex != v.startIndex)
		throw exception("different sizes");
	TVector<ValueType> tmp(*this);
	for (int i = 0; i < size; i++)
		tmp.pVector[i] = tmp.pVector[i] + v.pVector[i];
	return tmp;
}

template <typename ValueType>
TVector<ValueType> TVector<ValueType>::operator-(const TVector<ValueType>& v) {
	if (size != v.size || startIndex != v.startIndex)
		throw exception("different sizes");
	TVector<ValueType> tmp(*this);
	for (int i = 0; i < size; i++)
		tmp.pVector[i] = tmp.pVector[i] - v.pVector[i];
	return tmp;
}

template <typename ValueType>
double TVector<ValueType>::operator*(const TVector<ValueType>& v) {
	if (size != v.size || startIndex != v.startIndex)
		throw exception("different sizes");
	double sum = 0.0;
	for (int i = 0; i < size; i++)
		sum += pVector[i] * v.pVector[i];
	return sum;
}

#endif