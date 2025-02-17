using namespace std;
#include <iostream>
#pragma once
class vector {
private:
	int size;
	double* k;
public:
	vector(int n);// по умолчанию
	vector(int n, double* q);//с параметром
	vector(const  vector& other);//copy
	~vector();

	vector operator +(const vector& other);
	vector operator -(const vector& other);
	double operator *(const vector& other);

	vector operator +(const double x);
	vector operator *(const double x);

	vector& operator =(const vector& other);
	double operator[](const int index) const;

	friend istream& operator>>(istream& is, vector& other);
	friend ostream& operator<<(istream& os, vector & const other);

	const int fsize() { return size; };
	double* getk() { return k; };

	double norm_of_the_vector();


};