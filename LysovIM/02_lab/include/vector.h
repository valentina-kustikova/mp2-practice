#ifndef  __VECTOR_H__
#define __VECTOR_H__
#include <iostream>

using namespace std;

template <typename ValueType>
class TVector
{
protected:
	int size;
	ValueType* pVector;
	int start_index;
public:
	TVector(int s = 5, int start_i = 0);
	TVector(const TVector& vector);
	~TVector();

	int getSize() const;
	int getStartIndex() const;

	ValueType& operator[](const int ind);
	int operator==(const TVector& vector) const;
	int operator!=(const TVector& vector) const;
	const TVector& operator=(const TVector& vector);
	TVector  operator+(const TVector& vector);
	TVector  operator-(const TVector& vector);
	double  operator*(const TVector& vector);

	TVector  operator+(const ValueType& value);
	TVector  operator-(const ValueType& value);
	TVector  operator*(const ValueType& value);
	friend istream& operator>>(istream& in, TVector& value)
	{
		for (int i = 0; i < value.size; ++i)
		{
			in >> value.pVector[i];
		}
		return in;
	}
	friend ostream& operator<<(ostream& out, const TVector& value)
	{
		for (int i = 0; i < value.size; ++i) 
		{
			out << value.pVector[i] << " ";
		}
		out << endl;
		return out;
	}
};

template <typename ValueType>
int TVector<ValueType>::getSize() const 
{
	return size;
}

template <typename ValueType>
int TVector<ValueType>::getStartIndex()  const
{
	return start_index;
}

template <typename ValueType>
TVector<ValueType>::TVector(int size, int startIndex) : size(size), start_index(startIndex)
{
	pVector = new ValueType[size];
}

template <typename ValueType>
TVector<ValueType>::TVector(const TVector& vector) : size(vector.size), start_index(vector.start_index)
{
	pVector = new ValueType[size];
	for (int i = 0; i < size; ++i) 
	{
		pVector[i] = vector.pVector[i];
	}
}

template <typename ValueType>
TVector<ValueType>::~TVector()
{
	delete[] pVector;
}

template <typename ValueType>
ValueType& TVector<ValueType>::operator[](const int index)
{
	if (index < 0 || index >= size)
		throw ("Error: the index has gone out of range");
	return pVector[index];
}

template <typename ValueType>
int TVector<ValueType>::operator==(const TVector& vector) const
{
	if (this != &vector)
	{
		if ((size == vector.size) && (start_index == vector.start_index))
		{
			for (int i = 0; i < size; i++)
				if (pVector[i] != vector.pVector[i])
					return 0;
			return 1;
		}
		else
			return 0;
	}
	return 1;
}

template <typename ValueType>
int TVector<ValueType>::operator!=(const TVector& vector) const
{
	return !(*this == vector);
}

template <typename ValueType>
const TVector<ValueType>& TVector<ValueType>::operator=(const TVector& vector)
{
	if (this == &vector) 
		return *this;
	if (this->size != vector.size)
	{
		delete[] pVector;
		size = vector.size;
	}
	start_index = vector.start_index;
	pVector = new ValueType[size];
	for (int i = 0; i < size; ++i) {
		pVector[i] = vector.pVector[i];
	}
	return *this;
}

template <typename ValueType>
TVector<ValueType> TVector<ValueType>::operator+(const TVector<ValueType>& vector)
{
	if ((size != vector.size) || (start_index != vector.start_index))
		throw	("Error: vectors have different sizes");
	TVector result_vector(size, start_index);
	for (int i = 0; i < size; i++)
		result_vector.pVector[i] = pVector[i] + vector.pVector[i];
	return result_vector;
}

template <typename ValueType>
TVector<ValueType> TVector<ValueType>::operator-(const TVector<ValueType>& vector)
{
	if ((size != vector.size) || (start_index != vector.start_index))
		throw	("Error: vectors have different sizes");
	TVector result_vector(size, start_index);
	for (int i = 0; i < size; i++)
		result_vector.pVector[i] = pVector[i] - vector.pVector[i];
	return result_vector;
}

template <typename ValueType>
double TVector<ValueType>::operator*(const TVector<ValueType>& vector)
{
	if ((size != vector.size) || (start_index != vector.start_index))
		throw	("Error: vectors have different sizes");
	double result_vector = 0;
	for (int i = 0; i < size; i++)
		result_vector = result_vector + (pVector[i] * vector.pVector[i]);
	return result_vector;
}

template <typename ValueType>
TVector<ValueType> TVector<ValueType>::operator+(const ValueType& value)
{
	TVector<ValueType> result_vector(*this);
	for (int i = 0; i < size; i++) {
		result_vector.pVector[i] = result_vector.pVector[i] + value;
	}
	return result_vector;
}

template <typename ValueType>
TVector<ValueType> TVector<ValueType>::operator-(const ValueType& value)
{
	TVector<ValueType> result_vector(*this);
	for (int i = 0; i < size; i++)
		result_vector.pVector[i] = result_vector.pVector[i] - value;
	return result_vector;
}

template <typename ValueType>
TVector<ValueType> TVector<ValueType>::operator*(const ValueType& value)
{
	TVector<ValueType> result_vector(*this);
	for (int i = 0; i < size; i++)
		result_vector.pVector[i] = result_vector.pVector[i] * value;
	return result_vector;
}
#endif