#ifndef TVECTOR_H
#define TVECTOR_H

#include <iostream>

using namespace std;

template <typename T>
class TVector
{
protected:
	T* vec;
	int size;
	int start_ind;
public:
	TVector(int _size=5, int _start=0);
	TVector(const TVector<T>& obj);
	virtual ~TVector();

	int GetSize() const;
	int GetStart() const;
	T& operator [](const int index);

	int operator ==(const TVector<T>& obj) const;
	int operator !=(const TVector<T>& obj) const;
	TVector<T> operator *(const T& val);
	TVector<T> operator +(const T& val);
	TVector<T> operator -(const T& val);

	TVector<T> operator +(const TVector<T>& obj);
	TVector<T> operator -(const TVector<T>& obj);
	T operator *(const TVector<T>& obj);

	const TVector<T>& operator =(const TVector<T>& obj);

	friend istream& operator >>(istream& in, TVector<T>& obj)
	{
		for (int i = 0; i < obj.GetSize(); i++)
		{
			in >> obj.vec[i];
			in.ignore();
		}
		return in;
	};
	friend ostream& operator <<(ostream& out, const TVector<T>& obj)
	{
		for (int i = 0; i < obj.start_ind; i++)
			out << "0 ";
		for (int i = 0; i < obj.size; i++)
			out << obj.vec[i] << " ";
		return out;
	};
};

template <typename T>
TVector<T>::TVector(int _size, int _start)
{
	if (_size <= 0 || _start < 0)
		throw "Error";
	size = _size;
	start_ind = _start;
	vec = new T[size];
};
template <typename T>
TVector<T>::TVector(const TVector<T>& obj)
{
	size = obj.size;
	start_ind = obj.start_ind;
	vec = new T[size];
	for (int i = 0; i < size; i++)
		vec[i] = obj.vec[i];
};
template <typename T>
TVector<T>::~TVector()
{
	if (size > 0)
		delete[] vec;
};
template <typename T>
int TVector<T>::GetSize() const
{
	return size;
}
template <typename T>
int TVector<T>::GetStart() const
{
	return start_ind;
}
template <typename T>
T& TVector<T>::operator [](const int index)
{
	if (index < 0 || index >= size + start_ind) 
		throw "error";
	if (index < start_ind)
		throw "error";
	
	return vec[index - start_ind];
}
template <typename T>
int TVector<T>::operator==(const TVector<T>& obj) const
{
	if (size != obj.size || start_ind != obj.start_ind)
		return 0;
	for (int i = 0; i < size; i++)
		if (vec[i] != obj.vec[i])
			return 0;
	return 1;
};
template <typename T>
int TVector<T>::operator!=(const TVector<T>& obj) const
{
	return !((*this) == obj);
};
template <typename T>
TVector<T> TVector<T>::operator *(const T& val)
{
	TVector<T> result(size, start_ind);
	for (int i = 0; i < size; i++)
		result.vec[i] = vec[i] * val;
	return result;
}
template <typename T>
TVector<T> TVector<T>::operator +(const T& val)
{
	TVector<T> result(size, start_ind);
	for (int i = 0; i < size; i++)
		result.vec[i] = vec[i] + val;
	return result;
}
template <typename T>
TVector<T> TVector<T>::operator -(const T& val)
{
	TVector<T> result(size, start_ind);
	for (int i = 0; i < size; i++)
		result.vec[i] = vec[i] - val;
	return result;
}

template <typename T>
TVector<T> TVector<T>::operator +(const TVector<T>& obj)
{
	if (size != obj.size || start_ind != obj.start_ind)
		throw "Error";
	TVector<T> res(size, start_ind);
	for (int i = 0; i < size; i++)
		res.vec[i] = vec[i] + obj.vec[i];
	return res;
};
template <typename T>
TVector<T> TVector<T> ::operator -(const TVector<T>& obj)
{
	if (size != obj.size || start_ind != obj.start_ind)
		throw "Error";
	TVector<T> res(size, start_ind);
	for (int i = 0; i < size; i++)
		res.vec[i] = vec[i] - obj.vec[i];
	return res;
};
template <typename T>
T TVector<T>::operator *(const TVector<T>& obj)
{
	if (size != obj.size || start_ind != obj.start_ind)
		throw "Error";
	T res = 0;
	for (int i = 0; i < size; i++)
		res += vec[i] * obj.vec[i];
	return res;
};

template <typename T>
const TVector<T>& TVector<T>::operator=(const TVector<T>& obj)
{
	if (*this == obj)
		return (*this);
	if (size != obj.size)
	{
		delete[] vec;
		size = obj.size;
		vec = new T[size];
	}
	start_ind = obj.start_ind;
	for (int i = 0; i < size; i++)
		vec[i] = obj.vec[i];
	return (*this);
};
#endif // !TVECTOR_H

