// remember_vectors.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#pragma once 
#include "vector.h"
#include <iostream>
using namespace std;

vector::vector(int n) {
	size = n;
	k = new double[n];
	for (int i = 0; i < size; i++) {
		k[i] = 0;
	}
}
vector::vector(int n, double* x) {
	size = n;
	k = new double[n];
	for (int i = 0; i < size; i++) {
		k[i] = x[i];
	}
}
vector::vector(const  vector& other) {//copy
	size = other.size;
	k = new double[size];
	for (int i = 0; i < size; i++) {
		k[i] = other.k[i];
	}
}
vector::~vector() {
	delete[] k;
}
vector vector::operator+(const vector& other) {
	int tmp1 = size;
	int tmp2 = other.size;
	if (tmp1 == tmp2) {
		vector res(size);
		for (int i = 0; i < size; i++) {
			res.k[i] = this->k[i] + other.k[i];
		}
		return res;
	}
	else {
		//выброс исключения!!
	}
}
vector vector::operator-(const vector& other) {
	int tmp1 = size;
	int tmp2 = other.size;
	if (tmp1 == tmp2) {
		vector res(size);
		for (int i = 0; i < size; i++) {
			res.k[i] = this->k[i] - other.k[i];
		}
		return res;
	}
	else {
		//выброс исключения!!
	}
}
double vector::operator*(const vector& other) {
	int tmp1 = size;
	int tmp2 = other.size;
	if (tmp1 == tmp2) {
		double scalar = 0;
		for (int i = 0; i < size; i++) {
			scalar = scalar + k[i] * other.k[i];
		}
		return scalar;
	}
	else {
		//выброс исключения!!
	}

}

vector vector::operator+(const double x) {
	vector res(size);
	for (int i = 0; i < size; i++) {
		res.k[i] = k[i] + x;
	}
	return res;
}
vector vector::operator*(const double x) {
	vector res(size);
	for (int i = 0; i < size; i++) {
		res.k[i] = k[i] * x;
	}
	return res;
}



vector& vector::operator=(const vector& other) {
	if (this != &other) {
		delete[] k;
		size = other.size;
		k = new double[size];
		for (int i = 0; i < size; i++) {
			k[i] = other.k[i];
		}
	}
	return *this;
}
double vector:: operator[](const int i) const {
	if ((i < 0) or (i >= size)) {
		throw out_of_range("Index out of range");
	}
	return k[i];
}
/*double& vector:: operator[](const int i) {
	if ((i < 0) or (i >= size)) {
		throw out_of_range("Index out of range");
	}
	return k[i];
}
*/
istream& operator>>(std::istream& is, vector& other) {
	for (int i = 0; i < other.size; i++) {
		is >> other.k[i];
	}
	return is;
}

ostream& operator<<(ostream& os, vector& const other) {
	int n = other.fsize();
	os << "(";
	for (int i = 0; i < n; i++) {
		os << other.getk()[i];
		if (i < n - 1) {
			os << ", ";
		}
	}
	os << ")";
	return os;
}
double  vector::norm_of_the_vector() {
	double lenght = 0;
	for (int i = 0; i < size; i++) {
		lenght = k[i] * k[i] + lenght;
	}
	return sqrt(lenght);
}






int main() {
	
	double *arr1 = new double[3];
	cout << "Enter arr num 1"<<endl;
	for (int i = 0; i < 3; i++) {
		cin >> arr1[i];
	}
	vector v1(3, arr1);
	double* arr2 = new double[3];
	cout << "Enter arr num 2"<<endl;
	for (int i = 0; i < 3; i++) {
		cin >> arr2[i];
	}
	vector v2(3, arr2);


	std::cout << "v1: " << v1 << std::endl;
	std::cout << "v2: " << v2 << std::endl;

	vector v3 = v1 + v2;
	std::cout << "v1 + v2: " << v3 << std::endl;

	v3 = v1 - v2;
	cout << "v1 - v2: " << v3 << std::endl;

	double scalar = v1 * v2;
	cout << "v1 * v2: " << scalar << endl;

	v3 = v1 * 2.0;
	cout << "v1 * 2.0: " << v3 << endl;



	cout << "v1 size: " << v1.fsize() << endl;
	cout << "v1 norm: " << v1.norm_of_the_vector() << endl;

	return 0;
}