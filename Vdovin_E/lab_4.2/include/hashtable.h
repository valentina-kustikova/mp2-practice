#pragma once
#include "table.h"
#include "list.h"

class hashtable : public table
{
	list<record> *arrayRecord; //массив списков записей

	int findNumberRecord(const key &k); //поиск номера записи в массиве по ключу
	int hashfunctable(const key &k); //хэш функция
	void addSize() {}; //перевыделение памяти, если заполнено 70% таблицы (не требуется)
public:
	hashtable(); //конструктор по умолчанию
	~hashtable(); //деструктор

	void insRecord(const key &k, const datValue &data); //добавление новой записи, если такой нет
	void delRecord(const key &k); //удаление записи, если такая имеется
	datValue* findRecord(const key &k); //поиск данных по ключу

	key getKey(); //получение ключа у текущей записи
	datValue getData(); //получение данных у текущей записи

	friend ostream & operator<<(ostream &out, const hashtable &h); //перегрузка оператора вывода
};