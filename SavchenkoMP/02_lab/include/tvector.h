#ifndef _TVECTOR_H
#define _TVECTOR_H

#include <iostream>

using namespace std;

template <typename T>
class TVector {
protected:
	int size;
	int startIndex;
	T* pMem;
public:
	TVector(int _size = 10, int _startIndex = 0);
	TVector(const TVector<T>& v);
	virtual ~TVector();

	int GetSize() const noexcept;
	int GetStartIndex() const noexcept;

	T& operator[](const int index);

	const TVector<T>& operator=(const TVector<T>& v);

	//скал€рные
	TVector<T> operator*(const T& scalar);
	TVector<T> operator+(const T& scalar);
	TVector<T> operator-(const T& scalar);

	//векторные
	TVector<T> operator+(const TVector<T>& v);
	TVector<T> operator-(const TVector<T>& v);
	T operator*(const TVector<T>& v);

	int operator==(const TVector<T>& v) const;
	int operator!=(const TVector<T>& v) const;

	friend ostream& operator<<(ostream& out, const TVector<T>& v) {
		out << "| ";
		for (int i = 0; i < v.GetStartIndex(); i++)
			out << "0 ";
		for (int i = 0; i < v.GetSize(); i++)
			out << v.pMem[i] << " ";
		out << "|";
		return out;
	}
	friend istream& operator>>(istream& in, TVector<T>& v) {
		for (int i = 0; i < v.GetSize(); i++)
			in >> v.pMem[i];
		return in;
	}
};

///////////////////////////////////////////////////////////////////////////

template <typename T>
TVector<T>::TVector(int _size, int _startIndex) {
	if (_size <= 0) throw "ERROR: Vector size less than 1";
	if (_startIndex < 0) throw "ERROR: Vector startIndex less than 0";

	size = _size;
	startIndex = _startIndex;
	pMem = new T[size];
}
template <typename T>
TVector<T>::TVector(const TVector<T>& v) {
	size = v.size;
	startIndex = v.startIndex;
	pMem = new T[size];
	for (int i = 0; i < size; i++)
		pMem[i] = v.pMem[i];
}
template <typename T>
TVector<T>::~TVector() {
	if (size > 0)
		delete[] pMem;
}

template <typename T>
int TVector<T>::GetSize() const noexcept {
	return size;
}
template <typename T>
int TVector<T>::GetStartIndex() const noexcept {
	return startIndex;
}

template <typename T>
T& TVector<T>::operator[](const int index) {
	if (index < 0 || index >= size + startIndex) throw "ERROR: index out of range";
	
	
	if (index < startIndex) throw "ERROR: attempt to access a non-existent vector element";
	return pMem[index - startIndex];
}

template <typename T>
const TVector<T>& TVector<T>::operator=(const TVector<T>& v) {
	if (this == &v) return (*this);

	if (size != v.size) {
		delete[] pMem;
		size = v.size;
		pMem = new T[size];
	}

	startIndex = v.startIndex;
	for (int i = 0; i < size; i++)
		pMem[i] = v.pMem[i];

	return (*this);
}

//скал€рные
template <typename T>
TVector<T> TVector<T>::operator*(const T& scalar) {
	TVector<T> res(*this);
	for (int i = 0; i < size; i++)
		res.pMem[i] *= scalar;
	return res;
}
template <typename T>
TVector<T> TVector<T>::operator+(const T& scalar) {
	TVector<T> res(*this);
	for (int i = 0; i < size; i++)
		res.pMem[i] += scalar;
	return res;
}
template <typename T>
TVector<T> TVector<T>::operator-(const T& scalar) {
	TVector<T> res(*this);
	for (int i = 0; i < size; i++)
		res.pMem[i] -= scalar;
	return res;
}

//векторные
template <typename T>
TVector<T> TVector<T>::operator+(const TVector<T>& v) {
	if (size != v.size) throw "ERROR: Vector diffirent size";
	if (startIndex != v.startIndex) throw "ERROR: Vector diffirent startIndex";

	TVector<T> res(*this);
	for (int i = 0; i < size; i++)
		res.pMem[i] = res.pMem[i] + v.pMem[i];
	return res;
}
template <typename T>
TVector<T> TVector<T>::operator-(const TVector<T>& v) {
	if (size != v.size) throw "ERROR: Vector diffirent size";
	if (startIndex != v.startIndex) throw "ERROR: Vector diffirent startIndex";

	TVector<T> res(*this);
	for (int i = 0; i < size; i++)
		res.pMem[i] = res.pMem[i] - v.pMem[i];
	return res;
}
template <typename T>
T TVector<T>::operator*(const TVector<T>& v) {
	if (size != v.size) throw "ERROR: Vector diffirent size";
	if (startIndex != v.startIndex) throw "ERROR: Vector diffirent startIndex";

	T res = pMem[0] * v.pMem[0];
	for (int i = 1; i < size; i++)
		res = res + pMem[i] * v.pMem[i];
	return res;
}

template <typename T>
int TVector<T>::operator==(const TVector<T>& v) const {
	if (size != v.size || startIndex != v.startIndex) return 0;
	if (this == &v) return 1;

	int flag = 1;
	for (int i = 0; i < size; i++) {
		if (pMem[i] != v.pMem[i]) {
			flag = 0;
			break;
		}
	}
	return flag;
}
template <typename T>
int TVector<T>::operator!=(const TVector<T>& v) const {
	return !(*this == v);
}

#endif // !_TVECTOR_H