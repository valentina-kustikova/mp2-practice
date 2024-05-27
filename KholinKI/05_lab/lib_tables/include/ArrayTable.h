#ifndef ARRAYTABLE_H
#define ARRAYTABLE_H

#include "TABLE.h"


template<typename TKey, typename TData> class TArrayTable: public Table<TKey,TData> {
protected:
	TTabRecord<TKey, TData>** records;//массив указателей на записи
public:
	TArrayTable(int max_size_=25);
	TTabRecord<TKey, TData>** GetRecords()const;
	virtual ~TArrayTable();
};

template<typename TKey, typename TData>
TArrayTable<TKey, TData>::TArrayTable(int max_size_ = 25) :Table<TKey,TData>(max_size_){
	records = new TTabRecord<TKey, TData>*[max_size];
	for (int i = 0; i < max_size; i++) {
		records[i] = nullptr;
	}
}

template<typename TKey, typename TData>
TTabRecord<TKey, TData>** TArrayTable<TKey, TData>::GetRecords()const {
	return records;
}

template<typename TKey, typename TData>
TArrayTable<TKey, TData>::~TArrayTable() {
	for (int i = 0; i < count; i++) {
		delete records[i];
	}
	delete[] records;
}

#endif