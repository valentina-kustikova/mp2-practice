
#ifndef __TVECTOR_H__
#define __TVECTOR_H__

#include <iostream>

template <class T> class TVector
{
private:
	int size;
	int start_indx;
	T* pMem;
public:
	TVector(int size = 0, int indx = 0);
	TVector(const TVector<T>& vec);
	~TVector();
	int GetSize() const;
	int GetIndex() const;

	T& operator[](const int index);
	int operator==(const TVector<T>& vec) const;
	int operator!=(const TVector<T>& vec) const;

	TVector operator*(const T& v); //multiplying by a number
	TVector operator+(const T& v);
	TVector operator-(const T& v);

	TVector operator+(const TVector<T>& v); // v1 * v2
	TVector operator*(const TVector<T>& v);
	TVector operator-(const TVector<T>& v);

	const TVector& operator=(const TVector<T>& v);

	friend std::ostream& operator<<(std::ostream& ostr, const TVector<T>& v);
	friend std::istream& operator>>(std::istream& istr, TVector<T>& v);
};
#endif
