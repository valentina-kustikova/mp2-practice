#pragma once
#include <cstring>
#include <iostream>
using namespace std;
template <class ValType>
class TVector
{
public:
	int size;
	ValType* elements;
	int startIndex;
public:
	explicit TVector(int size = 3, int startIndex = 10);
	TVector(const TVector&);
	~TVector();
	bool operator ==(const TVector&) const;
	bool operator !=(const TVector&) const;
	TVector operator +(ValType);
	TVector operator -(ValType);
	TVector operator *(ValType);
	TVector operator /(ValType);
	TVector operator +(const TVector&);
	TVector operator -(const TVector&);
	ValType operator *(const TVector&);
	float Length() const;
	TVector& operator =(const TVector&);
	ValType operator[](int);
	friend ostream& operator <<(ostream& o, const TVector& a)
	{
		for (int i = 0; i < a.size; i++)
			o << a.elements[i] << " ";
		return o;
	}
	friend istream& operator >>(istream& in, TVector& a)
	{
		for (int i = 0; i < a.size; i++)
			in >> a.elements[i];
		return in;
	}
};
template <class ValType>
TVector <ValType> ::TVector(int _size, int _startindex)
{
	if (_size < 1)
		throw "Вектор не может быть построен";
	size = _size;
	startIndex = _startindex;
	elements = new ValType[size];
}
template <class ValType>
TVector <ValType> ::TVector(const TVector& a)
{
	size = a.size;
	startIndex = a.startIndex;
	elements = new ValType[size];
	for (int i = 0; i < size; i++)
		elements[i] = a.elements[i];
}
template <class ValType>
TVector <ValType> ::~TVector()
{
	size = 0;
	startIndex = 0;
	delete[] elements;
	elements = NULL;
}
template <class ValType>
bool TVector <ValType> :: operator ==(const TVector& a) const
{
	int flag = 0;
	if ((size != a.size) || (startIndex != a.startIndex))
		return false;
	for (int i = 0; i < size; i++)
	{
		if (elements[i] != a.elements[i])
			flag = 1;
	}
	if (flag == 0)
		return true;
	return false;
}
template <class ValType>
bool TVector <ValType> :: operator !=(const TVector& a) const
{
	return !(*this == a);
}
template <class ValType>
TVector <ValType> TVector <ValType> :: operator +(ValType a)
{
	TVector b(size, startIndex);
	for (int i = 0; i < size; i++)
		b.elements[i] = elements[i] + a;
	return b;
}
template <class ValType>
TVector <ValType> TVector <ValType> :: operator -(ValType a)
{
	TVector b(size, startIndex);
	for (int i = 0; i < size; i++)
		b.elements[i] = elements[i] - a;
	return b;
}
template <class ValType>
TVector <ValType> TVector <ValType> :: operator *(ValType a)
{
	TVector b(size, startIndex);
	for (int i = 0; i < size; i++)
		b.elements[i] = elements[i] * a;
	return b;
}
template <class ValType>
TVector <ValType> TVector <ValType> :: operator /(ValType a)
{
	TVector b(size, startIndex);
	for (int i = 0; i < size; i++)
		b.elements[i] = elements[i] / a;
	return b;
}
template <class ValType>
TVector <ValType> TVector <ValType> :: operator +(const TVector& a)
{
	if ((size != a.size) || (startIndex != a.startIndex))
		throw "Длина векторов не совпадает!";
	TVector b(size, startIndex);
	for (int i = 0; i < size; i++)
		b.elements[i] = elements[i] + a.elements[i];
	return b;
}
template <class ValType>
TVector <ValType> TVector <ValType> :: operator -(const TVector& a)
{
	if ((size != a.size) || (startIndex != a.startIndex))
		throw "Длина векторов не совпадает!";
	TVector b(size, startIndex);
	for (int i = 0; i < size; i++)
		b.elements[i] = elements[i] - a.elements[i];
	return b;
}
template <class ValType>
ValType TVector <ValType> :: operator *(const TVector& a)
{
	if ((size != a.size) || (startIndex != a.startIndex))
		throw "Длина векторов не совпадает!";
	ValType b = 0;
	for (int i = 0; i < size; i++)
		b += elements[i] * a.elements[i];
	return b;
}
template <class ValType>
float TVector <ValType> ::Length() const
{
	float b = 0, c = 0;
	for (int i = 0; i < size; i++)
		b += elements[i] * elements[i];
	c = sqrt(b);
	return c;
}
template <class ValType>
TVector <ValType>& TVector <ValType> :: operator =(const TVector& a)
{
	if (*this == a)
		return *this;
	if (size != a.size)
	{
		delete[] elements;
		size = a.size;
		elements = new ValType[size];
	}
	for (int i = 0; i < size; i++)
		elements[i] = a.elements[i];
	startIndex = a.startIndex;
	return *this;
}
template <class ValType>
ValType TVector <ValType> :: operator [](int index)
{
	if ((index < 0) && (index >= size))
		throw "Индекс не существует";
	return elements[index];
}


