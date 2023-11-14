#ifndef _TMATRIX_
#define _TMATRIX_

#include "TVector.h"

template <class T>
class TMatrix : public TVec<TVec<T>>
{
public:
	TMatrix(int mn = 10); //����������� �� ���������/� ����������
	TMatrix(const TMatrix& mtrx); //����������� �����������
	TMatrix(const TVec<TVec<T>>& mtrx);//����������� �����������

	const TMatrix operator=(const TMatrix& mtrx);
	bool operator==(const TMatrix& mt)const; //���������� ��������� ��������� �� ���������
	bool operator!=(const TMatrix& mt)const; //���������� ��������� ��������� �� �����������
	TMatrix operator+(const TMatrix& mt); //���������� ��������� �����
	TMatrix operator-(const TMatrix& mt); //���������� ��������� ��������
	TMatrix operator*(const TMatrix& mt); //���������� ��������� ������������

	friend istream& operator>>(istream& istr, TMatrix<T>& mt) //���������� ���������� �����
	{
		for (int i = 0; i < mt.size; i++) {
			istr >> mt.pMem[i];
		}
		return istr;
	}
	friend ostream& operator<<(ostream& ostr, const TMatrix<T>& mt) //���������� ���������� ������
	{
		for (int i = 0; i < mt.size; i++) {
			ostr << mt.pMem[i];
		}
		return ostr;
	}
};

template <class T>
TMatrix<T>::TMatrix(int mn) : TVec<TVec<T>>(mn) {
	if (mn < 0)
		throw "invalid size";
	for (int i = 0; i < mn; i++)
		pMem[i] = TVec<T>(mn - i, i);
}

template <class T>
TMatrix<T>::TMatrix(const TMatrix& mtrx) : TVec<TVec<T>>((TVec<TVec<T>>)mtrx) {}

template <class T>
TMatrix<T>::TMatrix(const TVec<TVec<T>>& mtrx) : TVec<TVec<T>>(mtrx) {}

template <class T>
const TMatrix<T> TMatrix<T>::operator=(const TMatrix& mtrx) {
	return TVec<TVec<T>>::operator=(mtrx);
}

template <class T>
bool TMatrix<T>::operator==(const TMatrix& mt)const {
	return TVec<TVec<T>> :: operator == (mt);
}

template <class T>
bool TMatrix<T>::operator!=(const TMatrix& mt)const {
	return TVec<TVec<T>> :: operator != (mt);
}

template <class T>
TMatrix<T> TMatrix<T>::operator+(const TMatrix& mt) {
	if (size != mt.size)
		throw "invalid size";
	return TVec<TVec<T>> :: operator + (mt);
}

template <class T>
TMatrix<T> TMatrix<T>::operator-(const TMatrix& mt) {
	if (size != mt.size)
		throw "invalid size";
	return TVec<TVec<T>> :: operator - (mt);
}

template <class T>
TMatrix<T> TMatrix<T>::operator*(const TMatrix& mt) {
	if (size != mt.size)
		throw "invalid size";
	TMatrix res(size);

	for (int i = 0; i < size; ++i) {
		for (int j = i; j < size; ++j) {
			res[i][j - i] = 0;
		}
	}

	for (int i = 0; i < size; ++i) {
		for (int j = i; j < size; ++j) {
			for (int k = i; k <= j; ++k) {
				res[i][j - i] += (*this)[i][k - i] * mt[k][j - k];
			}
		}
	}


	return res;
}
#endif
