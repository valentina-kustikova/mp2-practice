#pragma once
#include "record.h"

class table
{
protected:
	int maxnum; //максимальное число записей
	int num; //текущее количество записей
	int current; //номер текущей записи

	virtual int findNumberRecord(const key &k) = 0; //поиск номера записи в массиве по ключу
	virtual void addSize() = 0; //перевыделение памяти, если заполнено 70% таблицы
public:
	table() { maxnum = 0; num = 0; current = 0; } //конструктор по умолчанию
	virtual ~table() {} //деструктор

	bool isFull() const { return num == maxnum; } //проверка на полноту
	bool isEmpty() const { return num == 0; } //проверка на пустоту

	void reset() { current = 0; } //переход к первой записи
	void goNext() { current++; } //переход к следующей записи
	bool isEnded() const { return current > num; } //проверка на конец таблицы

	virtual void insRecord(const key &k, const datValue &data) = 0; //добавление новой записи, если такой нет
	virtual void delRecord(const key &k) = 0; //удаление записи, если такая имеется
	virtual datValue* findRecord(const key &k) = 0; //поиск данных по ключу

	virtual key getKey() = 0; //получение ключа у текущей записи
	virtual datValue getData() = 0; //получение данных у текущей записи
};