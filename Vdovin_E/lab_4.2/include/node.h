#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class valtype>
class node
{
public:
	valtype data; //данные
	node<valtype> *next; //указатель на следующее звено

	node() { next = NULL; } //конструктор по умолчанию
	~node() {} //деструктор

	node(const valtype &d); //конструктор от данных
	node(const node<valtype> &nod); //конструктор копирования
	node(const valtype &d, const node<valtype> *n); //конструктор от данных и указателя на следующее звено

	const node<valtype>& operator=(const node<valtype> &nod); //оператор присваивания

	bool operator==(const node<valtype> &n) const; //проверка на равно
	bool operator!=(const node<valtype> &n) const; //проверка на неравно
};

template<class valtype>
inline node<valtype>::node(const node<valtype>& nod)
{
	data = nod.data;
	next = nod.next;
}

template<class valtype>
inline node<valtype>::node(const valtype & d)
{
	data = d;
	next = NULL;
}

template<class valtype>
inline node<valtype>::node(const valtype & d, const node<valtype> * n)
{
	data = d;
	next = n;
}

template<class valtype>
inline const node<valtype>& node<valtype>::operator=(const node<valtype>& nod)
{
	data = nod.data;
	next = nod.next;
	return *this;
}

template<class valtype>
inline bool node<valtype>::operator==(const node<valtype>& n) const
{
	return (data == n.data);
}

template<class valtype>
inline bool node<valtype>::operator!=(const node<valtype>& n) const
{
	return !(*this == n);
}
