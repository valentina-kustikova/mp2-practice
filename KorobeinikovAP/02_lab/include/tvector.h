// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных", С++, ООП
//
// tvector.cpp - бесполезный файл, посольку класс шаблонный 
// Разработано для Microsoft Visual Studio 2022 Коробейниковым А.П. (15.10.2023)
//
// Динамический вектор


#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <iostream>

using namespace std;



template <typename T>
class Vector {
protected:
	int n;
	T* coor;
	int start_index;
public:
	Vector(int size= 10, int start_index = 0);        // конструктор по умолчанию
	Vector(const Vector<T>& obj);                     // конструктор копирования
	~Vector();                                        // деструктор 
	 
	int GetSize() const noexcept;                     // Получить размерность вектора
	int GetStart_index() const noexcept;			  // Получить стартовый индекс вектора

	T& operator[] (const int ind);                   // Прегрузка операции индексации
	T& operator[] (const int ind) const;                   // Прегрузка операции индексации

	Vector <T> operator + (const Vector<T>& obj);    // Прегрузка операции сложения векторов
	Vector <T> operator - (const Vector<T>& obj);    // Прегрузка операции вычитания векторов
	double operator * (const Vector<T>& obj);        // Прегрузка операции умножения векторов

	Vector <T> operator + (const T& obj);                // Прегрузка операции сложения вектора и T
	Vector <T> operator - (const T& obj);                // Прегрузка операции вычитания из вектора T
	Vector <T> operator * (const T& obj);                // Прегрузка операции умножения вектора и T


	double length() const;                           // Длина вектора

	bool operator == (const Vector<T>& obj) const;             // Прегрузка операции равенства
	bool operator != (const Vector<T>& obj) const;             // Прегрузка операции неравенства
	const Vector<T>& operator = (const Vector<T>& obj);

	friend std::ostream& operator << (std::ostream& stream, const Vector<T>& obj) {
		stream << '|';
		for (int i = 0; i < obj.start_index; i++) {
			stream << 0 << " ";
		}
		for (int i = 0; i < obj.n - 1; i++) {
			stream << obj.coor[i] << " ";
		}
		stream << obj.coor[obj.n-1];
		stream << '|' << std::endl;
		return stream;

	}
	friend std::istream& operator >> (std::istream& stream, Vector<T>& obj) {
		for (int i = 0; i < obj.n; i++) {
			stream >> obj.coor[i];
		}
		return stream;
	}
};

// конструкторы

template <typename T>
Vector<T>::Vector(int size, int start_index) {
	if (size < 0) {
		throw "negative length";
	}
	if (start_index < 0) {
		throw "negative start_index";
	}
	n = size;
	this->start_index = start_index;
	coor = new T[size];
}

template <typename T>
Vector<T>::Vector(const Vector<T>& obj) {
	n = obj.n;
	start_index = obj.start_index;
	coor = new T[n];
	for (int i = 0; i < n; i++) {
		coor[i] = obj.coor[i];
	}
}

//деструктор
template <typename T>
Vector<T>::~Vector() {
	n = 0;
	this->start_index = 0;
	delete[] coor;
}

// Get
template <typename T>
int Vector<T>::GetSize() const noexcept {
	return n;
}

template <typename T>
int Vector<T>::GetStart_index() const noexcept {
	return (start_index);
}

// длина вектора
template <typename T>
double Vector<T>::length() const {
	double res = 0.0;
	for (int i = 0; i < n; i++) {
		res += coor[i] * coor[i];
	}
	return (sqrt(res));
}


// перегрузка операций

template <typename T>
T& Vector<T>:: operator[] (const int ind)  //индексация
{ 
	return (coor[ind]);
}

template <typename T>
T& Vector<T>:: operator[] (const int ind) const  //индексация
{
	return (coor[ind]);
}


template <typename T>
Vector<T> Vector<T>:: operator + (const Vector<T>& obj) // сложение векторов
{
	if (n != obj.n) {
		throw "Incorrect data (different size)";
	}
	if (start_index != obj.start_index) {
		throw "Incorrect data (different start_index)";
	}

	Vector<T> tmp(*this);
	for (int i = 0; i < n; i++) {
		tmp.coor[i] = tmp.coor[i] + obj.coor[i];
	}
	return tmp;
}

template <typename T>
Vector <T> Vector<T>:: operator - (const Vector<T>& obj) //вычитание векторов
{
	if (n != obj.n) {
		throw "Incorrect data (different size)";
	}
	if (start_index != obj.start_index) {
		throw "Incorrect data (different start_index)";
	}
	Vector<T> tmp(*this);
	for (int i = 0; i < n; i++) {
		tmp.coor[i] = tmp.coor[i] - obj.coor[i];
	}
	return tmp;
}



template <typename T>
double Vector<T>:: operator * (const Vector<T>& obj) //умножение векторов
{
	if (n != obj.n) {
		throw "Incorrect data (different size)";
	}
	if (start_index != obj.start_index) {
		throw "Incorrect data (different start_index)";
	}
	Vector<T> tmp(*this);
	double res = 0.0;
	for (int i = 0; i < n; i++) {
		res += tmp.coor[i] * obj.coor[i];
	}
	return res;
}


template <typename T>
Vector<T> Vector<T>:: operator + (const T& obj) //сложение вектора и T
{
	Vector<T> tmp(*this);
	for (int i = 0; i < n; i++) {
		tmp.coor[i] += obj;
	}
	return tmp;
}

template <typename T>
Vector<T> Vector<T>:: operator - (const T& obj) //вычитание из вектора  T
{
	Vector<T> tmp(*this);
	for (int i = 0; i < n; i++) {
		tmp.coor[i] -= obj;
	}
	return tmp;
}

template <typename T>
Vector<T> Vector<T>:: operator * (const T& obj) //умножение вектора и T
{
	Vector<T> tmp(*this);
	for (int i = 0; i < n; i++) {
		tmp.coor[i] *= obj;
	}
	return tmp;
}


template <typename T>
bool Vector<T>:: operator == (const Vector<T>& obj) const   //операция проверки на равенство
{
	if (n != obj.n) {
		return false;
	}
	if (start_index != obj.start_index) {
		return false;
	}
	for (int i = 0; i < n; i++) {
		if (coor[i] != obj.coor[i]) {
			return false;
		}
	}
	return true;
}

template <typename T>
bool Vector<T>::operator != (const Vector<T>& obj) const //операция проверки на неравенство
{
	if (n != obj.n) {
		return true;
	}
	if (start_index != obj.start_index) {
		return true;
	}
	for (int i = 0; i < n; i++) {
		if (coor[i] != obj.coor[i]) {
			return true;
		}
	}
	return false;
}



template <typename T>
const Vector<T>& Vector<T>::operator = (const Vector<T>& obj)  //оператор присваивания
{
	if (this == &obj) {
		return(*this);
	}
	if (n != obj.n) {
		delete[] coor;
		n = obj.n;
		coor = new T[n];
	}

	start_index = obj.start_index;

	for (int i = 0; i < n; i++) {
		coor[i] = obj.coor[i];
	}

	return (*this);
}




#endif 
// Структура хранения динамического шаблонного вектора
// 


