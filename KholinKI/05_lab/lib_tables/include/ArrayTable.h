#ifndef ARRAYTABLE_H
#define ARRAYTABLE_H

#include "TABLE.h"


template<typename TKey, typename TData> class TArrayTable: public Table<TKey,TData> {
protected:
	TTabRecord<TKey, TData>** records;//массив указателей на записи
public:
	TArrayTable(int max_size_);
	TKey GetKey()const;
	Data<TData>* GetData()const;
};

template<typename TKey, typename TData>
TArrayTable<TKey, TData>::TArrayTable(int max_size_ = 25) :Table<TKey,TData>(max_size_){
	records = new TTabRecord<TKey, TData>*[max_size];
	for (int i = 0; i < max_size; i++) {
		records[i] = nullptr;
	}
}

template<typename TKey, typename TData>
TKey TArrayTable<TKey, TData>::GetKey()const {
	return records[curr_pos]->key;
}

template<typename TKey, typename TData>
Data<TData>* TArrayTable<TKey, TData>::GetData()const {
	return records[curr_pos]->data;
}

#endif