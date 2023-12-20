#ifndef __TMATRIX_H__
#define __TMATRIX_H__

#include "tvector.h"

template <typename T> 
class TMatrix : public TVector <TVector<T>>
{
public:
	TMatrix(int mn = 10);
	TMatrix(const TMatrix& m);
	TMatrix(const TVector <TVector<T>>& m);

	//операции
	const TMatrix operator=(const TMatrix& m);
	int operator==(const TMatrix& m) const;
	int operator!=(const TMatrix& m) const;

	TMatrix operator+(const TMatrix& m); // A + B
	TMatrix operator-(const TMatrix& m); // A - B
	TMatrix operator*(const TMatrix& m); // A * B

	template<typename T> friend std::ostream& operator<<(std::ostream& ostr, const TMatrix<T>& v);
	template<typename T> friend std::istream& operator>>(std::istream& istr, TMatrix<T>& v);

};
//конструкторы
template <typename T>
TMatrix<T>::TMatrix<T>(int mn) :TVector<TVector<T>>(mn)
{
	for (int i = 0; i < mn; i++)
	{
		pVec[i] = TVector<T>(mn - i, i);
	}
}

template<typename T>
TMatrix<T>::TMatrix<T>(const TMatrix& m) :TVector<TVector<T>>(m) { };

template <typename T>
TMatrix<T>::TMatrix<T>(const TVector<TVector<T>>& m) :TVector<TVector<T>>(m) { };

//операции
// =
template<typename T>
const TMatrix<T> TMatrix<T>::operator=(const TMatrix<T>& m)
{
	return  TVector<TVector<T>>::operator=(m);
}
// ==
template <typename T>
int TMatrix<T>::operator==(const TMatrix& m) const
{
	return TVector<TVector<T> >::operator==(m);
}
// !=
template <typename T>
int TMatrix<T>::operator!=(const TMatrix& m) const
{
	return TVector<TVector<T> >::operator!=(m);
}

// A + B
template<typename T>
TMatrix<T> TMatrix<T>::operator+(const TMatrix& m)
{
	if (size != m.size)
		throw "Не удается собрать матрицу с разными размерами";
	else
		return TVector<TVector<T> > :: operator+(m);
}

// A - B 
template<typename T>
TMatrix<T> TMatrix<T>::operator-(const TMatrix& m)
{
	if (size != m.size)
		throw "Не удается вычесть матрицу с разными размерами";
	else
		return TVector<TVector<T> > :: operator-(m);
}

// A * B
template<typename T>
TMatrix<T> TMatrix<T>::operator*(const TMatrix& m)
{
	if (size != m.size)
		throw "Не удается умножить матрицу с разными размерами";
	else
		size;
	TMatrix <T> res(size);
	for (int i = 0; i < size; i++)
		for (int j = i; j < size; j++)
		{
			for (int k = i; k <= j; k++)
				res.pVec[i][j - i] += this->pVec[i][k - i] * m.pVec[k][j - k];
		}
	return res;
}

// ввод
template <typename T>
std::istream& operator>>(std::istream& istr, TMatrix<T>& m)
{
	istr >> m.size;
	std::cout << "\nВведите " << m.size << " элементы: ";
	for (int i = 0; i < m.size; i++)
		istr >> m.pVec[i];
	return istr;
}

// вывод
template <typename T>
std::ostream& operator<<(std::ostream& ostr, const TMatrix<T>& m)
{
	for (int i = 0; i < m.size; i++)
	{
		for (int j = 0; j < m.pVec[i].GetIndex(); j++)
			ostr << std::setw(3) << "0" << " ";
		ostr << m.pVec[i] << std::endl;

	}
	return ostr;

}
#endif
