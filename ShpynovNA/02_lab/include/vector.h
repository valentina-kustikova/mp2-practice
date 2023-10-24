#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>

using namespace std;

template <typename T> class TVector {
protected:
	int size;
	int start_index;
	T* elements;
public:
	TVector(int size, int start_index);
	TVector(const TVector<T>& v);
	~TVector();

	int getsize();
	int getindex();

	TVector operator+(const TVector<T>& v);
	TVector operator+(const T& e);

	TVector operator-(const TVector<T>& v);
	TVector operator-(const T& e);

	T operator*(const TVector<T>& v);
	TVector operator*(const T& e);

	bool operator==(const TVector<T>& v) const;
	bool operator!=(const TVector<T>& v) const;

	const TVector& operator=(const TVector<T>& v);

	T& operator[](const int ind);

	template<typename T> friend ostream& operator<<(ostream& out, const TVector<T>& v);
	template<typename T> friend istream& operator>>(istream& in, TVector<T>& v);
};

template<typename T> ostream& operator<<(ostream& out, const TVector<T>& v) {
	out << "(" << v[0];
	for (int i = 1; i < v.size; i++) {
		out << ", " << v[i];
	}
	out << ")";
	return out;
}
template<typename T> istream& operator>>(istream& in, TVector<T>& v) {
	cout << "enter size: ";
	istr >> v.size;
	cout << "enter elements: ";
	for (int i = 0; i < v.size; i++) {
		istr << v[i];
	}
	return istr;
}
#endif // !VECTOR_H_