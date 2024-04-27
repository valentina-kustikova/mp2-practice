#ifndef SCANTABLE_H
#define SCANTABLE_H

#include "ArrayTable.h"

template<typename TKey, typename TData> class TArrayScanTable : public TArrayTable<TKey,TData>{
public:
	TArrayScanTable(int max_size_);
	void Insert(TKey Key, const Data<TData>* data_);
	TTabRecord<TKey,TData>* Find(TKey Key) override;
	void Remove(TKey key);
};

template<typename TKey,typename TData>
TArrayScanTable<TKey, TData>::TArrayScanTable(int max_size_):TArrayTable<TKey, TData>(max_size_){}

template<typename TKey, typename TData>
void TArrayScanTable<TKey,TData>::Insert(TKey key, const Data<TData>* data_) {
	if (IsFull()) {
		throw "Table is full!";
	}
	records[count] = new TTabRecord<TKey, TData>(key, data_);
	count++;
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
		curr_pos = 0;
	}
}

#endif