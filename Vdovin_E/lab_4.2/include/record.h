#pragma once
#include "polinom.h"

typedef string key;
typedef polinom datValue;

class record
{
public:
	key keyRecord; //ключ записи
	datValue dataRecord; //данные записи

	record() {} //конструктор по умолчанию
	~record() {} //деструктор

	record(const key &k, const datValue &data); //конструктор от ключа и данных
	record(const record &rec); //конструктор копирования

	record& operator=(const record &rec); //оператор присваивания

	bool operator==(const record &rec); //проверка на равенство
	bool operator!=(const record &rec); //проверка на неравенство
	bool operator>(const record &rec); //проверка на больше
	bool operator<(const record &rec); //проверка на меньше

	friend ostream & operator<<(ostream &out, const record &r); //перегрузка оператора вывода
};