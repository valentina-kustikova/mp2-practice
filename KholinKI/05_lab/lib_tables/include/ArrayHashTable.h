#ifndef ARRAYHASHTABLE_H
#define ARRAYHASHTABLE_H

#include "HashTable.h"



template<typename TKey, typename TData> class TArrayHashTable : public THashTable<TKey, TData> {
protected:
	TTabRecord<TKey, TData>** records;//массив указателей на записи
	int index_free_pos;//индекс свободной позиции для вставки
	size_t hash_step;//шаг хеширования
	size_t get_next_pos(size_t index);//получить следующую позицию для ключа
	TTabRecord<TKey, TData>* pMark;// маркер для индикации строк с удаленными записями
	size_t index;//индекс найденной записи
public:
	TArrayHashTable(int max_size_,size_t hash_step_);
	void Insert(TKey key, const Data<TData>* data_);
	TTabRecord<TKey, TData>* Find(TKey key);
	void Remove(TKey key);
	TKey GetKey()const;
	Data<TData>* GetData()const;
	bool next()override;
	bool reset()override;
};

template<typename TKey, typename TData>
TArrayHashTable<TKey, TData>::TArrayHashTable(int max_size_ = 25,size_t hash_step_ = 5): THashTable<TKey,TData>(max_size_) {
	records = new TTabRecord<TKey, TData>* [max_size];
	curr_pos = 0;
	index_free_pos = -1;
	hash_step = hash_step_;
	pMark = new TTabRecord<TKey, TData>();
}

template<typename TKey, typename TData>
size_t TArrayHashTable<TKey,TData>::get_next_pos(size_t index) {//повторное перемешивание
	return (index + hash_step) % max_size;
}


template<typename TKey, typename TData>
TTabRecord<TKey, TData>* TArrayHashTable<TKey, TData>::Find(TKey key) {
	index = HashFunction(key);
	for (int i = 0; i < max_size; i++) {
		if (records[index]->key == key) {
			return records[index]
		}
		else if (records[index] == nullptr) {
			return nullptr;
		}
		else if (records[index] == pMark && index_free_pos == -1) {
			index_free_pos = index;
		}
		index = get_next_pos(index);
	}
	return nullptr;
}

template<typename TKey, typename TData>
void TArrayHashTable<TKey, TData>::Insert(TKey key, const Data<TData>* data_) {
	if (IsFull()) {
		throw "Table is full!";
	}

	if (Find(key) != nullptr) {
		throw "Record already exist!";
	}

	if (index_free_pos != -1) {
		curr_pos = index_free_pos;
	}
	records[curr_pos] = new TTabRecord<TKey, TData>(key, data_);
	count++;
	index_free_pos = -1;
	reset();
}



template<typename TKey, typename TData>
void TArrayHashTable<TKey, TData>::Remove(TKey key) {
	if (IsEmpty()) {
		return;
	}
	if (Find(key) != nullptr) {
		delete records[index];
		records[index] = pMark;
		count--;
	}
	else {
		throw "Record not found in table!";
	}
}

template<typename TKey, typename TData>
TKey TArrayHashTable<TKey,TData>::GetKey()const {
	return records[curr_pos]->key;
}

template<typename TKey, typename TData>
Data<TData>* TArrayHashTable<TKey,TData>::GetData()const {
	return records[curr_pos]->data;
}

template<typename TKey, typename TData>
bool TArrayHashTable<TKey, TData>::next() {
	while(!IsTabEnded()) {
		if (records[curr_pos] != pMark && records[curr_pos] != nullptr) {
			return IsTabEnded();
		}
		curr_pos++;
	}
	return IsTabEnded();
}

template<typename TKey, typename TData>
bool TArrayHashTable<TKey, TData>::reset() {
	curr_pos = 0;
	while (!IsTabEnded()) {
		if (records[curr_pos] != pMark && records[curr_pos] != nullptr) {
			return IsTabEnded();
		}
		curr_pos++;
	}
	return IsTabEnded();
}
#endif