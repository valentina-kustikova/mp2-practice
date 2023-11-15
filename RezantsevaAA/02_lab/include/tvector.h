
#ifndef __TVECTOR_H__
#define __TVECTOR_H__

#include <iostream>
#include <ostream>
#include <istream>
#include <iomanip>

template <class T> class TVector
{
protected:
	int size;
	int start_index;
	T* pVec;
public:
	TVector(int s = 10, int index = 0); //s = size
	TVector(const TVector<T>& vec);
	~TVector();
	int GetSize() const;
	int GetIndex() const;

	T& operator[](const int index);
	int operator==(const TVector<T>& v) const;
	int operator!=(const TVector<T>& v) const;

	TVector operator*(const T& v); //multiplying by a number
	TVector operator+(const T& v);
	TVector operator-(const T& v);

	TVector operator+(const TVector<T>& v); // v1 + v2
	T operator*(const TVector<T>& v); //scalar
	TVector operator-(const TVector<T>& v);

	const TVector& operator=(const TVector<T>& v);

	template<typename T> friend std::ostream& operator<<(std::ostream& ostr, const TVector<T>& v);
	template<typename T> friend std::istream& operator>>(std::istream& istr, TVector<T>& v);
};

//constructors:
template <typename T> 
TVector<T> ::TVector(int s, int index)
{
	if (s < 0)
		throw - 1;
	else 
		if (s == 0)
		{
			size = s;
			pVec = NULL;
		}
	else
	{
		start_index = index;
		size = s;
		pVec = new T[size];
		for (int i = 0; i < size; i++)
				pVec[i] = 0;
	}
}

template <typename T>
TVector<T> ::TVector(const TVector<T>& vec)
{
	size = vec.size;
	start_index = vec.start_index;
	pVec = new T[size];
	for (int i = 0; i < size; i++)
	{
		pVec[i] = vec.pVec[i];
	}
}

//destruct
template <typename T>
TVector<T>::~TVector()
{
	if (size > 0) 
	{
		size = 0;
		delete[] pVec;
		pVec = NULL;
	}
}

//Get
template <typename T>
int TVector<T> :: GetSize() const
{
	return size;
}

template <typename T>
int TVector<T>::GetIndex() const
{
	return start_index;
}

//operators
template <typename T>
T& TVector<T> :: operator [](const int index)
{
	if (index < 0 || index >= size)

		throw "index can't be negative or bigger then size";
	else
		return pVec[index];
}

template <typename T>
int TVector<T>::operator==(const TVector<T>& v) const
{
	if (size != v.size) {
		return 0;
	}

	for (int i = 0; i < size; i++) {
		if (pVec[i] != v.pVec[i]) {
			return 0;
		}
	}
	return 1;
	
}

template <typename T>
int TVector<T>::operator!=(const TVector<T>& v) const
{
	return !((*this) == v);
}

//operations vector with num
//vec * n
template <typename T>
TVector<T> TVector<T>::operator*(const T& v)
{
	TVector<T> res(size);
	for (int i = 0; i < size; i++)
		res[i] = (*this)[i] * v;
	return res;
}
// vec + const
template <typename T>
TVector<T> TVector<T>::operator+(const T& n)
{
	TVector<T> res(size);
	for (int i = 0; i < size; i++)
		res[i] = (*this)[i] + n;
	return res;
}
//vec - const
template <typename T>
TVector<T> TVector<T>::operator-(const T& n)
{
	TVector<T> res(size);
	for (int i = 0; i < size; i++)
		res[i] = (*this)[i] - n;
	return res;
}

//operations vec with vec
//vec + vec
template <typename T>
TVector<T> TVector<T>:: operator+(const TVector<T>& v)
{
	if (size != v.size)
		throw "Can't accumulate vectors with different dimensions!";
	
	if (start_index != v.start_index)
		throw "Can't accumulate vectors with different indexes";
	
	TVector<T> tmp(*this);
	for (int i = 0; i < size; i++)
	{
		tmp.pVec[i] = pVec[i] + v.pVec[i];
	}
	return tmp;
}
//vec - vec
template <typename T>
TVector<T> TVector<T>:: operator-(const TVector<T>& v)
{
	if (size != v.size)
		throw "Can't subtract vectors with different dimensions!";

	if (start_index != v.start_index)
		throw "Can't subtract vectors with different indexes";

	TVector<T> tmp(*this);
	for (int i = 0; i < size; i++)
	{
		tmp.pVec[i] = pVec[i] - v.pVec[i];
	}
	return tmp;
}
// scalar *
template <typename T>
T TVector<T>::operator*(const TVector<T>& v)
{
	if (size != v.size)
		throw "Can't scalar multiply vectors with different size!";

	if (start_index != v.start_index)
		throw "Can't scalar multiply vectors with different indexes";

	T res = 0;
	for (int i = 0; i < size; i++)
	{
		res += pVec[i] * v.pVec[i];
	}
	return res;
}

// =
template <typename T> 
const TVector<T>& TVector<T>::operator=(const TVector<T>& v)
{
	if (this == &v)
		return *this;

	if (size != v.size)
	{
		delete[] pVec;
		size = v.size;
		pVec = new T[size];
	}

	start_index = v.start_index;
	for (int i = 0; i < size; i++)
	{
		pVec[i] = v.pVec[i];
	}
	return *this;
}

// out
template <typename T>
std::ostream& operator<<(std::ostream& ostr, const TVector<T>& v) 
{
	for (int i = 0; i < v.size; i++)
		ostr  << std::setw(3) << v.pVec[i] << " ";
	return ostr;

}
//in
template <typename T>
std::istream& operator>>(std::istream& istr, TVector<T>& v)
{
	istr >> v.size;
	std::cout << "\nEnter the " << v.size << " coordinates: ";
	for (int i = 0; i < v.size; i++)
		istr >> v.pVec[i];
	return istr;
}
#endif
