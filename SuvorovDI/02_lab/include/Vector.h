#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <iostream>
#include <cmath>

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

  ValueType& TVector<ValueType>::operator[] (const int i);

	int operator== (const TVector<ValueType>& v) const;
	int operator!= (const TVector<ValueType>& v) const;

	const TVector& operator= (const TVector<ValueType>& v);

	TVector operator+ (const ValueType val);
	TVector operator- (const ValueType val);
	TVector operator* (const ValueType val);

	TVector operator+ (const TVector<ValueType>& v);
	TVector operator- (const TVector<ValueType>& v);
	double operator* (const TVector<ValueType>& v);

	friend std::istream& operator>> (std::istream& in, TVector<ValueType>& v) {
		for (int i = 0; i < v.size; i++)
			in >> v.pVector[i];

		return in;
	}

	friend std::ostream& operator<< (std::ostream& out, TVector& v) {
		out << "\nVector with size " << v.size << std::endl;
		for (int i = 0; i < v.size; i++)
			out << v.pVector[i] << "  ";
		out << "\n";

		return out;
	}
};

template <typename ValueType>
TVector<ValueType>::TVector(int size, int startIndex) {
  if (size < 0)
    throw std::exception("negative size");
  if (startIndex < 0)
    throw std::exception("negative start index");

	this->size = size;
	this->startIndex = startIndex;

	pVector = new ValueType[size];
  // for (int i = 0; i < size; i++)
  //   pVector[i] = 0; НО ОБНУЛЕНИЕ БУДЕТ СПРАВЕДЛИВО ТОЛЬКО ДЛЯ ЧИСЛОВЫХ ТИПОВ ValueType, ЧТО ДЕЛАТЬ ЕСЛИ ЭТО ПОЛЬЗОВАТЕЛЬСКИЙ ТИП???
}

template <typename ValueType>
TVector<ValueType>::TVector(const TVector<ValueType>& v) {
	size = v.size;
	startIndex = v.startIndex;

	pVector = new ValueType[size];
	for (int i = 0; i < size; i++) {
		pVector[i] = v.pVector[i];
	}
}

template <typename ValueType>
TVector<ValueType>::~TVector() {
	delete[] pVector;
}

template <typename ValueType>
ValueType& TVector<ValueType>::operator[](const int i) {
	if (i < 0 || i >= size)
		throw std::exception("out of range");
	return pVector[i];
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
int TVector<ValueType>::operator== (const TVector<ValueType>& v) const {
	if (size != v.size || startIndex != v.startIndex)
		return 0;

	for (int i = 0; i < size; i++)
		if (pVector[i] != v.pVector[i])
			return 0;
	return 1;
}

template <typename ValueType>
int TVector<ValueType>::operator!= (const TVector<ValueType>& v) const {
	return !(*this == v);
}

template <typename ValueType>
const TVector<ValueType>& TVector<ValueType>::operator= (const TVector<ValueType>& v) {
	if (this == &v)
		return *this;
	if (size != v.size) {
		size = v.size;

		delete[] pVector;
		pVector = new ValueType[size];
	}
	startIndex = v.startIndex;

	for (int i = 0; i < size; i++)
		pVector[i] = v.pVector[i];

	return *this;
}

template <typename ValueType>
TVector<ValueType> TVector<ValueType>::operator+ (const ValueType val) {
	TVector<ValueType> result(*this);
	for (int i = 0; i < size; i++)
		result[i] += val;
	return result;
}

template <typename ValueType>
TVector<ValueType> TVector<ValueType>::operator- (const ValueType val) {
	TVector<ValueType> result(*this);
	for (int i = 0; i < size; i++)
		result[i] -= val;
	return result;
}

template <typename ValueType>
TVector<ValueType> TVector<ValueType>::operator* (const ValueType val) {
	TVector<ValueType> result(*this);
	for (int i = 0; i < size; i++)
		result[i] *= val;
	return result;
}

template <typename ValueType>
TVector<ValueType> TVector<ValueType>::operator+ (const TVector<ValueType>& v) {
	if (size != v.size || startIndex != v.startIndex)
		throw std::exception("diff. sizes");

	TVector<ValueType> result(*this);

	for (int i = 0; i < size; i++)
		result.pVector[i] = result.pVector[i] + v.pVector[i];

	return result;
}

template <typename ValueType>
TVector<ValueType> TVector<ValueType>::operator- (const TVector<ValueType>& v) {
	if (size != v.size || startIndex != v.startIndex)
		throw std::exception("diff. sizes");

	TVector<ValueType> result(*this);

	for (int i = 0; i < size; i++)
		result.pVector[i] = result.pVector[i] - v.pVector[i];

	return result;
}

template <typename ValueType>
double TVector<ValueType>::operator* (const TVector<ValueType>& v) {
	if (size != v.size || startIndex != v.startIndex)
		throw std::exception("diff. sizes");

	double sum = 0.0;
	for (int i = 0; i < size; i++)
		sum += pVector[i] * v.pVector[i];

	return sqrt(sum);
}

#endif