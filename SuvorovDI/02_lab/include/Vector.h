#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <iostream>

template <typename ValueType>
class TVector {
protected:
	int size;
	int startIndex;
	ValueType* pVector;

public:
	ValueType& operator[] (const int i);

	TVector(int size = 5, int startIndex = 0);
	TVector(const TVector& v);
	~TVector();

	int GetSize() const;
	int GetStartIndex() const;

	int operator== (const TVector& v) const;
	int operator!= (const TVector& v) const;

	const TVector& operator= (const TVector& v);

	TVector operator+ (const ValueType val);
	TVector operator- (const ValueType val);
	TVector operator* (const ValueType val);

	TVector operator+ (const TVector& v);
	TVector operator- (const TVector& v);
	double operator* (const TVector& v);

	friend std::istream& operator>> (std::istream& in, TVector& v) {
		/*std::cout << "\nEnter vector size: ";
		in >> v.size;
		delete[] v.pVector;
		v.pVector = new ValueType[v.size];*/

		for (int i = 0; i < v.size; i++)
			in >> v.pVector[i]; // если написать v[i] -- то при запуске программа завершиться с кодом -10 миллиардов...

		return in;
	}

	friend std::ostream& operator<< (std::ostream& out, const TVector& v) {
		out << "\nVector with size " << v.size << std::endl;
		for (int i = 0; i < v.size; i++)
			out << v.pVector[i] << "  "; // Почему-то нельзя написать v[i] - ошибка..
		out << "\n";

		return out;
	}
};

template <typename ValueType>
TVector<ValueType>::TVector(int size, int startIndex) {
	this->size = size;
	this->startIndex = startIndex;

	pVector = new ValueType[size];
}

template <typename ValueType>
TVector<ValueType>::TVector(const TVector<ValueType>& v) { // Не требует указания шаблонного типа в параметре! Почему?
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
		throw std::exception("out of range");
	return pVector[i];
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
		pVector[i] = v.pVector[i]; // ПОчему-то не работает v[i]

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
		throw std::exception("deff. sizes");

	TVector<ValueType> result(*this);

	for (int i = 0; i < size; i++)
		result.pVector[i] = result.pVector[i] + v.pVector[i];

	return result;
}

template <typename ValueType>
TVector<ValueType> TVector<ValueType>::operator- (const TVector<ValueType>& v) {
	if (size != v.size || startIndex != v.startIndex)
		throw std::exception("deff. sizes");

	TVector<ValueType> result(*this);

	for (int i = 0; i < size; i++)
		result.pVector[i] = result.pVector[i] - v.pVector[i];

	return result;
}

template <typename ValueType>
double TVector<ValueType>::operator* (const TVector<ValueType>& v) {
	if (size != v.size || startIndex != v.startIndex)
		throw std::exception("deff. sizes");

	double sum = 0.0;
	for (int i = 0; i < size; i++)
		sum += pVector[i] * v.pVector[i];

	return sum;
}

#endif