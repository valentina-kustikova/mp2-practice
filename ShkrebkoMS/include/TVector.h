#ifndef __TVECTOR_H__
#define __TVECTOR_H__

#include <iostream>
using namespace std;

template <typename ValueType> class TVector
{
protected:
	int Size;
	int StartIndex;
	ValueType* pVector;
public:
	TVector(int s = 10, int i = 0); 
	TVector(const TVector<ValueType>& vec);
	~TVector();
	int GetSize() const;
	int GetStartIndex() const;

	ValueType& operator[](const int i);
	int operator==(const TVector<ValueType>& v) const;
	int operator!=(const TVector<ValueType>& v) const;

	TVector operator*(const ValueType& v); 
	TVector operator+(const ValueType& v);
	TVector operator-(const ValueType& v);

	TVector operator+(const TVector<ValueType>& v); 
	double operator*(const TVector<ValueType>& v);
	TVector operator-(const TVector<ValueType>& v);

	const TVector& operator=(const TVector<ValueType>& v);

	friend istream& operator>>(istream& istr, TVector<ValueType>& v)
	{
		std::cout << "Enter size " << endl;;
		istr >> v.Size;
		std::cout << "\nEnter the " << v.Size << " coordinates: \n";
		for (int i = 0; i < v.Size; i++)
			istr >> v.pVector[i];
		return istr;
	}
	friend ostream& operator<<(ostream& ostr, TVector<ValueType>& v)
	{
		for (int i = 0; i < v.Size; i++)
			ostr << v.pVector[i] << " ";
		return ostr;
	}
};


template <typename ValueType>
TVector<ValueType> ::TVector(int s, int i)
{
	if (s < 0)
		throw "out of range";
	else
		if (s == 0)
		{
			Size = s;
			pVector = nullptr;
		}

	StartIndex = i;
	Size = s;
	pVector = new ValueType[Size];
	for (int i = 0; i < Size; i++)
		pVector[i] = 0;
}

template <typename ValueType>
TVector<ValueType> ::TVector(const TVector<ValueType>& v)
{
	Size = v.Size;
	StartIndex = v.StartIndex;
	pVector = new ValueType[Size];
	for (int i = 0; i < Size; i++)
	{
		pVector[i] = v.pVector[i];
	}
}


template <typename ValueType>
TVector<ValueType>::~TVector()
{
	delete[] pVector;
}


template <typename ValueType>
int TVector<ValueType> ::GetSize() const
{
	return Size;
}

template <typename ValueType>
int TVector<ValueType>::GetStartIndex() const
{
	return StartIndex;
}


template <typename ValueType>
ValueType& TVector<ValueType> :: operator [](const int i)
{
	if (i < 0 || i >= Size)
		throw "out of range";
	return pVector[i];
}

template <typename ValueType>
int TVector<ValueType>::operator==(const TVector<ValueType>& v) const
{
	if (Size != v.Size || StartIndex != v.StartIndex) {
		return 0;
	}

	for (int i = 0; i < Size; i++) {
		if (pVector[i] != v.pVector[i]) {
			return 0;
		}
	}
	return 1;

}

template <typename ValueType>
int TVector<ValueType>::operator!=(const TVector<ValueType>& v) const
{
	return !((*this) == v);
}


template <typename ValueType>
TVector<ValueType> TVector<ValueType>::operator*(const ValueType& v)
{
	TVector<ValueType> tmp(Size, StartIndex);
	for (int i = 0; i < Size; i++)
		tmp[i] = pVector[i] * v;
	return tmp;
}

template <typename ValueType>
TVector<ValueType> TVector<ValueType>::operator+(const ValueType& n)
{
	TVector<ValueType> tmp(Size, StartIndex);
	for (int i = 0; i < Size; i++)
		tmp[i] = pVector[i] + n;
	return tmp;
}

template <typename ValueType>
TVector<ValueType> TVector<ValueType>::operator-(const ValueType& n)
{
	TVector<ValueType> tmp(Size, StartIndex);
	for (int i = 0; i < Size; i++)
		tmp[i] = pVector[i] - n;
	return tmp;
}


template <typename ValueType>
TVector<ValueType> TVector<ValueType>:: operator+(const TVector<ValueType>& v)
{
	if ((Size != v.Size) || (StartIndex != v.StartIndex))
		throw "diff size or start index";

	TVector<ValueType> tmp(Size, StartIndex);
	for (int i = 0; i < Size; i++)
	{
		tmp.pVector[i] = pVector[i] + v.pVector[i];
	}
	return tmp;
}

template <typename ValueType>
TVector<ValueType> TVector<ValueType>:: operator-(const TVector<ValueType>& v)
{
	if ((Size != v.Size) || (StartIndex != v.StartIndex))
		throw "diff size";

	TVector<ValueType> tmp(Size, StartIndex);
	for (int i = 0; i < Size; i++)
	{
		tmp.pVector[i] = pVector[i] - v.pVector[i];
	}
	return tmp;
}

template <typename ValueType>
double TVector<ValueType>::operator*(const TVector<ValueType>& v)
{
    if ((Size != v.Size) || (StartIndex != v.StartIndex))
        throw "diff size";

    double sum = 0.0;
    for (int i = 0; i < Size; i++)
    {
        sum += pVector[i] * v.pVector[i];
    }
    return sum;
}


template <typename ValueType>
const TVector<ValueType>& TVector<ValueType>::operator=(const TVector<ValueType>& v)
{
	if (this == &v)
		return *this;

	if (Size != v.Size)
	{
		delete[] pVector;
		Size = v.Size;
		pVector = new ValueType[Size];
	}

	StartIndex = v.StartIndex;
	for (int i = 0; i < Size; i++)
	{
		pVector[i] = v.pVector[i];
	}
	return *this;
}

#endif
