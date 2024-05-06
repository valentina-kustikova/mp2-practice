#ifndef TABLE_H
#define TABLE_H

#include "TabRecord.h"

template<typename TKey, typename TData> class Table {
protected:
	//основные характеристики таблицы
	int max_size;//макс. возможное количество записей
	int count;//индекс последней незанятой записи(количество текущих записей)
	int curr_pos;//номер текущей записи
public:
	Table(int max_size_);
	virtual void Insert(TKey key, const Data<TData>* data_) = 0;
	virtual TTabRecord<TKey,TData>* Find(TKey key) = 0;
	virtual void Remove(TKey key) = 0;
	bool IsFull()const;
	bool IsEmpty()const;
	bool IsTabEnded()const;
	virtual bool next();
	virtual bool reset();
	int GetCount()const;
	int GetSize()const;
	int GetCurrPos()const;
	virtual TKey GetKey()const = 0;
	virtual Data<TData>* GetData()const = 0;
};

template<typename TKey, typename TData>
Table<TKey,TData>::Table(int max_size_) {
	count = 0;
	curr_pos = 0;
	max_size = max_size_;
}

template<typename TKey, typename TData>
bool Table<TKey, TData>::IsFull()const { return count == max_size ? true : false; }

template<typename TKey, typename TData>
bool Table<TKey, TData>::IsEmpty()const { return count == 0 ? true : false; }

template<typename TKey, typename TData>
bool Table<TKey, TData>::IsTabEnded()const { return curr_pos == max_size - 1 ? true : false; }


template<typename TKey, typename TData>
bool Table<TKey, TData>::next() {
	if (!IsTabEnded()) {
		curr_pos++;
	}
	return IsTabEnded();
}

template<typename TKey, typename TData>
bool Table<TKey, TData>::reset() {
	curr_pos = 0;
	return IsTabEnded();
}

template<typename TKey, typename TData>
int Table<TKey, TData>::GetCount()const {
	return count;
}

template<typename TKey, typename TData>
int Table<TKey, TData>::GetCurrPos()const {
	return curr_pos;
}

template<typename TKey, typename TData>
int Table<TKey, TData>::GetSize()const {
	return max_size;
}
#endif