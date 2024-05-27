#ifndef __TABLE_H__
#define __TABLE_H__

#include "tabrecord.h"
#include <iostream>

using namespace std;

template <typename TKey, typename  TData>
class Table{
protected:
	int count;
	int max_size;
	int curr_pos;
public:
	virtual void insert(const TKey& _key, TData* _data) = 0;
	virtual void remove(const TKey& _key) = 0;
	virtual TabRecord<TKey, TData>* find(const TKey& _key) = 0;
	virtual TabRecord<TKey, TData>* operator[](const TKey& _key) = 0;
	Table();

	bool full() const noexcept;
	bool empty() const noexcept;
	bool ended() const noexcept;

	virtual bool reset() noexcept;
	virtual bool next() noexcept;

	int get_size() const noexcept;
	int get_max_size() const noexcept;
};

template <typename TKey, typename TData>
Table<TKey, TData>::Table() {
	count = 0;
	max_size = 100;
	curr_pos = -1;
}
template <typename TKey, typename TData>
bool Table<TKey, TData>::full() const noexcept {
	return (count == max_size);
}

template <typename TKey, typename TData>
bool Table<TKey, TData>::empty() const  noexcept {
	return (count == 0);
}

template <typename TKey, typename TData>
bool Table<TKey, TData>::ended() const noexcept {
	return (curr_pos >= max_size);
}


template <typename TKey, typename TData>
bool Table<TKey, TData>::reset() noexcept {
	if (!empty()) {
		curr_pos = 0;
		return ended();
	}
	else {
		curr_pos = -1;
		return ended();
	}
}

template <typename TKey, typename TData>
bool Table<TKey, TData>::next() noexcept {
	curr_pos++;
	return ended();
}


template <typename TKey, typename TData>
int Table<TKey, TData>::get_size() const noexcept {
	return count;
}

template <typename TKey, typename TData>
int Table<TKey, TData>::get_max_size() const noexcept {
	return max_size;
}



#endif
