#pragma once
#include "table.h"

class scantable : public table
{
	record **arrayRecord; //массив записей

	int findNumberRecord(const key &k); //поиск номера записи в массиве по ключу
	void addSize(); //перевыделение памяти, если заполнено 70% таблицы
public:
	scantable(int size = 1000); //конструктор
	~scantable(); //деструктор

	void insRecord(const key &k, const datValue &data); //добавление новой записи, если такой нет
	void delRecord(const key &k); //удаление записи, если такая имеется
	datValue* findRecord(const key &k); //поиск данных по ключу

	key getKey(); //получение ключа у текущей записи
	datValue getData(); //получение данных у текущей записи

	friend ostream & operator<<(ostream &out, const scantable &sc); //перегрузка оператора вывода
};