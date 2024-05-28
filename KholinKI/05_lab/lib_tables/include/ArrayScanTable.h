#ifndef SCANTABLE_H
#define SCANTABLE_H

#include "ArrayTable.h"

template<typename TKey, typename TData> class TArrayScanTable : public TArrayTable<TKey,TData>{
public:
	TArrayScanTable(int max_size_ = 25);
	TArrayScanTable(const TArrayScanTable& scan_table);
	virtual void Insert(TKey Key, const Data<TData>* data_);
	virtual TTabRecord<TKey,TData>* Find(TKey Key);
	virtual void Remove(TKey key);
	TKey GetKey()const;
	Data<TData>* GetData()const;
};

template<typename TKey,typename TData>
TArrayScanTable<TKey, TData>::TArrayScanTable(int max_size_):TArrayTable<TKey, TData>(max_size_){}

template<typename TKey, typename TData>
TArrayScanTable<TKey, TData>::TArrayScanTable(const TArrayScanTable& scan_table) {
	max_size = scan_table.GetSize();
	count = scan_table.GetCount();
	curr_pos = scan_table.GetCurrPos();
	records = new TTabRecord<TKey, TData>* [max_size];
	TTabRecord<TKey, TData>** scan_records = scan_table.GetRecords();
	for (int i = 0; i < count; i++) {
		records[i] = new TTabRecord<TKey, TData>(scan_records[i]->key, scan_records[i]->data);
	}
	for (int j = count; j < max_size; j++) {
		records[j] = nullptr;
	}
}

template<typename TKey, typename TData>
void TArrayScanTable<TKey,TData>::Insert(TKey key, const Data<TData>* data_) {
	if (IsFull()) {
		throw "Table is full!";
	}
	TTabRecord<TKey, TData>* search = Find(key);
	if (search != nullptr)throw "Key already exist!!";
	records[count] = new TTabRecord<TKey, TData>(key, data_);
	count++;
	reset();
}

template<typename TKey, typename TData>
TTabRecord<TKey, TData>* TArrayScanTable<TKey,TData>::Find(TKey Key) {
	for (int i = 0; i < count; i++) {
		if (records[i]->key == Key) {
			curr_pos = i;
			return records[i];
		}
	}
	return nullptr;
}

template<typename TKey, typename TData>
void TArrayScanTable<TKey, TData>::Remove(TKey Key) {
	if (IsEmpty()) {
		return;
	}
	TTabRecord<TKey, TData>* record = Find(Key);
	if (record == nullptr) {
		throw "Record not found!";
	}
	else {
		delete record;
		for (int i = curr_pos; i < count; i++) {
			records[i] = records[i + 1];
		}
		count--;
		reset();
	}
}

template<typename TKey, typename TData>
TKey TArrayScanTable<TKey, TData>::GetKey()const {
	return records[curr_pos]->key;
}

template<typename TKey, typename TData>
Data<TData>* TArrayScanTable<TKey, TData>::GetData()const {
	return records[curr_pos]->data;
}



#endif