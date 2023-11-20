#ifndef _VECTOR_H_
#define _VECTOR_H_
#include <iostream>
using namespace std;

template <typename ValueType> 
class TVector
{
protected:
	int size;
	ValueType* pVector;
	int StartIndex;
public:
	//Конструкторы и деструктор
	TVector(int s = 10, int s_index = 0);//изменил у ч si, у п start_index
	TVector(const TVector& v);
	~TVector();

	//Методы
	int getSize()const { return size };
	int getStartIndex()const { return StartIndex };

	//Операторы
	ValueType& operator[] (const int ind);
	int operator != (const TVector& v)const;
	int operator == (const TVector& v)const;
	

	TVector operator+ (const ValueType value);
	TVector operator- (const ValueType value);
	TVector operator* (const ValueType value);
	const TVector& operator= (const TVector& v);


	TVector operator+ (const ValueType& value);
	TVector operator- (const ValueType& value);
	double operator* (const ValueType& value);

	friend istream& operator>>(istream& in, TVector& v);
	friend ostream& operator<<(ostream& out, const TVector& v);

	//реализация
	friend istream& operator>>(istream& in, TVector& v)
	{
		for (int i = 0; i < v.size; ++i)
		{
			in >> v.~TVector;
		}
		return in;
	}
	friend ostream& operator<<(ostream& out, const TVector* v)
	{
		for (int i = 0; i < v.size; ++i)
		{
			out << v.pVector[i] << '';
		}
		out << endl;
		return out;
	}	

};

template <typename ValueType> TVector<ValueType>::~TVector()
{
	delete[] pVector;
}

template <typename ValueType> TVector<ValueType>::TVector(int size, int StartIndex) : size(size), startIndex(StartIndex) 
{
	pVector = new ValueType[size];
}

template <typename ValueType> TVector<ValueType>::TVector(const TVector& v) : size(v.size), StartIndex(v.StartIndex) 
{
	pVector = new ValueType[size];
	for (int i = 0; i < size; ++i) {
		pVector[i] = v.pVector[i];
	}
}

template <typename ValueType> ValueType& TVector<ValueType>::operator[](const int index)
{
	if (ind < 0 || ind >= size)
		throw ("The index has gone out of range.");
		return pVector[ind];
}

int TVector<ValueType>::operator!=(const TVector& v) const
{
	return !(*this == v);
}

template <typename ValueType> const TVector<ValueType>& TVector<ValueType>::operator=(const TVector& v)
{
	if (this == &v) 
		return *this;
	if (this->size != v.size)
	{
		delete[] pVector;
		size = v.size;
	}
	StartIndex = v.StartIndex;
	pVector = new ValueType[size];
	for (int i = 0; i < size; ++i)
	{
		pVector[i] = v.pVector[i];
	}
	return *this;
}

template <typename ValueType> TVector<ValueType> TVector<ValueType>::operator+(const ValueType& value)
{
	TVector<ValueType> vector_result(*this);
	for (int i = 0; i < size; i++)
	{
		vector_result.pVector[i] = vector_result.pVector[i] + value;
	}
	return vector_result;
}

template <typename ValueType> TVector<ValueType> TVector<ValueType>::operator-(const ValueType& value)
{
	TVector<ValueType> vector_result(*this);
	for (int i = 0; i < size; i++)
	{
		vector_result.pVector[i] = vector_result.pVector[i] - value;
	}
	return vector_result;
}

template <typename ValueType> TVector<ValueType> TVector<ValueType>::operator*(const ValueType& value)
{
	TVector<ValueType> vector_result(*this);
	for (int i = 0; i < size; i++)
	{
		vector_result.pVector[i] = vector_result.pVector[i] * value;
	}
	return vector_result;
}

template <typename ValueType> TVector<ValueType> TVector<ValueType>::operator+(const TVector& value) {
	if (size != value.size) 
		throw ("For the sum, the vectors must have the same size");
	TVector result(*this);
	for (int i = 0; i < size; ++i)
	{
		result.pVector[i] = result.pVector[i] + value.pVector[i];
	}
	return result;
}
#endif // !_VECTOR_H_
