#ifndef TABLE_H
#define TABLE_H

#include "tabrecord.h"

#define DEFAULT_SIZE 101

template <class TKey, class TData>
class Table {
protected:
	int count;
	int max_size;
	int curr_pos;

public:
	Table(int _max_size = DEFAULT_SIZE);
	
	virtual void insert(const TKey& _key, TData* _data) = 0;
	virtual void remove(const TKey& _key) = 0;
	virtual TabRecord<TKey, TData>* find(const TKey& _key) = 0;
	virtual TabRecord<TKey, TData>* operator[](const TKey& _key) = 0;

	bool full() const noexcept;
	bool empty() const noexcept;
	bool ended() const noexcept;

	virtual bool reset() noexcept;
	virtual bool next() noexcept;
	virtual TabRecord<TKey, TData>* get_curr() = 0;

	int get_size() const noexcept;
	int get_max_size() const noexcept;
};

template <class TKey, class TData>
Table<TKey, TData>::Table(int _max_size) {
	max_size = _max_size;
	count = 0;
	curr_pos = -1;
}

template <class TKey, class TData>
bool Table<TKey, TData>::full() const noexcept {
	return (count == max_size);
}

template <class TKey, class TData>
bool Table<TKey, TData>::empty() const  noexcept {
	return (count == 0);
}

template <class TKey, class TData>
bool Table<TKey, TData>::ended() const noexcept {
	return (curr_pos >= max_size);
}


template <class TKey, class TData>
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

template <class TKey, class TData>
bool Table<TKey, TData>::next() noexcept {
	curr_pos++;
	return ended();
}


template <class TKey, class TData>
int Table<TKey, TData>::get_size() const noexcept {
	return count;
}

template <class TKey, class TData>
int Table<TKey, TData>::get_max_size() const noexcept {
	return max_size;
}


#endif // !TABLE_H
