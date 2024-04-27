#ifndef ARRAYTABLE_H
#define ARRAYTABLE_H

#include "TABLE.h"


template<typename TKey, typename TData> class TArrayTable: public Table<TKey,TData> {
protected:
	TTabRecord<TKey, TData>** records;//массив указателей на записи
	int max_size;//макс. возможное количество записей
	int curr_pos;//нумерация с 0
public:
	TArrayTable(int max_size_);
	virtual void Insert(TKey Key, const Data<TData>* data_) = 0;
	virtual TTabRecord<TKey,TData>* Find(TKey Key) = 0;
	virtual void Remove(TKey key) = 0;
	bool IsFull()const;
	bool IsEmpty()const;
	bool IsTabEnded()const;
	//bool Next();
	/*bool Reset();*/
	int GetCount()const;
	TKey GetKey()const;
	Data<TData>* GetData()const;
};

template<typename TKey, typename TData>
TArrayTable<TKey, TData>::TArrayTable(int max_size_) :Table<TKey,TData>(){
	max_size = max_size_;
	curr_pos = 0;
	records = new TTabRecord<TKey, TData>*[max_size];
}

template<typename TKey, typename TData>
bool TArrayTable<TKey, TData>::IsFull()const { return count == max_size ? true : false; }

template<typename TKey, typename TData>
bool TArrayTable<TKey, TData>::IsEmpty()const { return count == 0 ? true : false; } 

template<typename TKey, typename TData>
bool TArrayTable<TKey, TData>::IsTabEnded()const { return curr_pos == max_size-1 ? true : false; }

//template<typename TKey, typename TData>
//bool TArrayTable<TKey, TData>::Next() {
//	if (IsTabEnded()) {
//		return false;
//	}
//	else {
//		curr_pos++;
//		return true;
//	}
//}

//template<typename TKey, typename TData>
//bool TArrayTable<TKey, TData>::Reset() {//??
//	if (IsTabEnded()) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}

template<typename TKey, typename TData>
int TArrayTable<TKey, TData>::GetCount()const {
	return count;
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