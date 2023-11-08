#ifndef _TVECTOR_H
#define _TVECTOR_H
//#include <cmath>
#include <math.h>
#include <iostream>
using namespace std;

template <class T>
class TVector
{
protected:

	T* pVector;
	int Size; // размер вектора
	int StartIndex; // индекс первого элемента вектора

public:

	TVector(int Size = 10, int StartIndex = 0);
	TVector(const TVector<T>& v); // конструктор копирования
	virtual ~TVector<T>();

	int GetSize() { return Size; } // размер вектора
	int GetStartIndex() { return StartIndex; } // индекс первого элемента

	T& operator[](int pos); // доступ

	int operator==(const TVector<T>& v) const; // сравнение
	int operator!=(const TVector<T>& v) const; // сравнение

	const TVector<T>& operator=(const TVector<T>& v); // присванивание

	// скалярные операции
	TVector<T> operator+(const T& val); // прибавить скаляр
	TVector<T> operator-(const T& val); // вычесть скаляр
	TVector<T> operator*(const T& val); // умножить на скаляр

	// векторные операции
	TVector<T> operator+(const TVector<T>& v); // сложение
	TVector<T> operator-(const TVector<T>& v); // вычитание
	T operator* (const TVector<T>& v); // скалярное произведение

	// ввод-вывод
	friend std::istream& operator>>(istream& in, TVector<T>& v)
	{
		for (int i = 0; i < v.GetSize(); i++)
			in >> v.pVector[i];
		return in;
	}

	friend ostream& operator<<(ostream& out, const TVector<T>& v)
	{

		out << "|";
		for (int j = 0; j < v.StartIndex; j++)
		{
			out << "0 ";
		}
		for (int i = 0; i < v.Size; i++)
		{
			out << v.pVector[i] << " ";
		}
		out << "|";
		return out;

	}
};

template <class T>
TVector <T> ::TVector(int Size, int StartIndex)
{
	if (Size <= 0)
		throw"Error";
	if (StartIndex < 0)
		throw"Error";
	this->StartIndex = StartIndex;
	this->Size = Size;
	pVector = new T[Size];
}

template <class T>
TVector <T> ::TVector(const TVector<T>& v)
{
	Size = v.Size;
	StartIndex = v.StartIndex;
	pVector = new T[Size];
	for (int i = 0; i < Size; i++)
		pVector[i] = v.pVector[i];
}

template <class T>
TVector <T>::~TVector()
{
	if (pVector != NULL)
	{
		delete[] pVector;
		pVector = NULL;
		Size = 0;
	}
}

template <class T>
T& TVector <T>:: operator[](int pos)
{
	if (pos < StartIndex || pos >= Size + StartIndex)
		throw"Error";
	return pVector[pos - StartIndex];
}

template<class T>
int TVector<T>::operator==(const TVector<T>& v) const
{
	if (StartIndex != v.StartIndex)
		return 0;
	if (Size != v.Size)
		return 0;
	for (int i = 0; i < Size - StartIndex; i++)
		if (pVector[i] != v.pVector[i])
			return 0;
	return 1;
}

template<class T>
int TVector<T>::operator!=(const TVector<T>& v) const
{
	return !(*this == v);
}

template<class T>
const TVector<T>& TVector<T>::operator=(const TVector<T>& v)
{
	if (this != &v)
	{
		if (Size != v.Size)
		{
			delete[] pVector;
			Size = v.Size;
			pVector = new T[v.Size];
		}
		
		StartIndex = v.StartIndex;
		for (int i = 0; i < Size; i++)
			pVector[i] = v.pVector[i];
	}
	return *this;
}

template<class T>
TVector<T> TVector<T>:: operator+ (const T& val)
{
	TVector<T> tmp(*this);
	for (int i = 0; i < Size; i++)
	{
		tmp.pVector[i] += val;
	}
	return tmp;
}

template<class T>
TVector<T> TVector<T>:: operator- (const T& val)
{
	TVector<T> tmp(*this);
	for (int i = 0; i < Size; i++)
	{
		tmp.pVector[i] -= val;
	}
	return tmp;
}

template<class T>
TVector<T> TVector<T>:: operator* (const T& val)
{
	TVector<T> tmp(*this);
	for (int i = 0; i < Size; i++)
	{
		tmp.pVector[i] *= val;
	}
	return tmp;
}

template <class T>
TVector<T> TVector<T>:: operator+(const TVector<T>& v)
{
	if (Size != v.Size || StartIndex != v.StartIndex)
		throw"Error";
	TVector<T> tmp(*this);
	for (int i = 0; i < Size; i++)
	{
		tmp.pVector[i] = v.pVector[i] + tmp.pVector[i];
	}
	return tmp;
}

template <class T>
TVector<T> TVector<T>:: operator-(const TVector<T>& v)
{
	if (Size != v.Size || StartIndex != v.StartIndex)
		throw"Error";
	TVector<T> tmp(*this);
	for (int i = 0; i < Size; i++)
	{
		tmp.pVector[i] = v.pVector[i] - tmp.pVector[i];
	}
	return tmp;
}

template <class T>
T TVector <T>:: operator* (const TVector<T>& v)
{
	if (Size != v.Size || StartIndex != v.StartIndex)
		throw "Error";
	T res = T();
	for (int i = 0; i < Size; i++)
	{
		res += pVector[i] * v.pVector[i];
	}
	return res;
}


#endif