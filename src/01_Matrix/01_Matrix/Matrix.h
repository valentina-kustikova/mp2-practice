#pragma once
#include "Vector.h"
template <class ValType>
class TMatrix : public TVector<TVector<ValType> > // сделать правильоне наследование полей // наладить throw
{
public:
	TMatrix(int size = 10);
	TMatrix(const TMatrix&);
	TMatrix(const TVector<TVector<ValType>>&);
	~TMatrix();
	bool operator ==(const TMatrix&) const;
	bool operator !=(const TMatrix&) const;
	TMatrix operator +(ValType);
	TMatrix operator -(ValType);
	TMatrix operator *(ValType);
	TVector<ValType> operator *(const TVector<ValType>&);
	TMatrix operator +(const TMatrix&);
	TMatrix operator -(const TMatrix&);
	TMatrix& operator =(const TMatrix&);
	friend ostream& operator <<(ostream& o, const TMatrix &a)
	{
		for (int i = 0; i < a.size; i++)
		{
			for (int j = 0; j < i; j++)
				cout << "  ";
			o << a.elements[i];
			cout << endl;
		}
		return o;
	}
	friend istream& operator >>(istream& in, TMatrix &a)
	{
		for (int i = 0; i < a.size; i++)
		{
			cout << "введите " << i << " строку матрицы" << endl;
			in >> a.elements[i];
		}
		return in;
	}
};
template <class ValType>
TMatrix <ValType> ::TMatrix(int _size) : TVector<TVector<ValType> >(_size)
{
	if (_size < 1)
		throw "Матрица не может быть построена";
	for (int i = 0; i < _size; i++)
		this->elements[i] = TVector<ValType>(_size - i, i);
}
template <class ValType>
TMatrix <ValType> ::TMatrix(const TMatrix<ValType>& a) : TVector<TVector<ValType> >(a)
{}
template <class ValType>
TMatrix <ValType> ::TMatrix(const TVector<TVector<ValType>>& a) : TVector<TVector<ValType> >(a)
{}
template <class ValType>
TMatrix <ValType> :: ~TMatrix()
{}
template <class ValType>
bool TMatrix <ValType> ::operator ==(const TMatrix<ValType>& a) const
{
	int flag = 0;
	if (this->size != a.size)
		return false;
	for (int i = 0; i < a.size; i++)
	{
		if (this->elements[i] != a.elements[i])
			flag = 1;
	}
	if (flag == 0)
		return true;
	return false;
}
template <class ValType>
bool TMatrix<ValType> :: operator !=(const TMatrix<ValType>& a) const
{
	return !(*this == a);
}
template <class ValType>
TMatrix <ValType> TMatrix <ValType> :: operator +(ValType a)
{
	TMatrix b(this->size);
	for (int i = 0; i < this->size; i++)
		b.elements[i] = this->elements[i] + a;
	return b;
}
template <class ValType>
TMatrix <ValType> TMatrix <ValType> :: operator -(ValType a)
{
	TMatrix b(this->size);
	for (int i = 0; i < this->size; i++)
		b.elements[i] = this->elements[i] - a;
	return b;
}
template <class ValType>
TMatrix <ValType> TMatrix <ValType> :: operator *(ValType a)
{
	TMatrix b(this->size);
	for (int i = 0; i < this->size; i++)
		b.elements[i] = this->elements[i] * a;
	return b;
}
template <class ValType>
TVector <ValType> TMatrix <ValType> :: operator *(const TVector <ValType> &a)
{
	if (this->size != a.size)
		throw "Размер матрицы и вектора не совпадает";
	TVector<ValType> b(a.size, 0);
	for (int i = 0; i < this->size; i++)
	{
		b.elements[i] = 0;
		for (int j = i; j < this->size; j++)
			b.elements[i] += this->elements[i][j - i] * a.elements[j];
	}
	return b;
}
template <class ValType>
TMatrix <ValType> TMatrix <ValType> :: operator + (const TMatrix<ValType> &a)
{
	if (this->size != a.size)
		throw "Размер матрицы не совпадает";
	TMatrix b(a.size);
	for (int i = 0; i < this->size; i++)
		b.elements[i] = this->elements[i] + a.elements[i];
	return b;
}
template <class ValType>
TMatrix <ValType> TMatrix <ValType> :: operator - (const TMatrix<ValType> &a)
{
	if (this->size != a.size)
		throw "Размер матрицы не совпадает";
	TMatrix b(a.size);
	for (int i = 0; i < this->size; i++)
		b.elements[i] = this->elements[i] - a.elements[i];
	return b;
}
template <class ValType>
TMatrix <ValType>& TMatrix <ValType> ::operator = (const TMatrix<ValType> &a)
{
	if (*this == a)
		return *this;
	if (this->size != a.size)
	{
		delete[] this->elements;
		this->size = a.size;
		this->elements = new TVector<ValType>[this->size];
	}
	for (int i = 0; i < this->size; i++)
		this->elements[i] = a.elements[i];
	return *this;
}
