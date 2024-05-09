#ifndef TABLE_H_
#define TABLE_H_

#include "record.h"
#include <iostream>

#define TabTemplate template <class Key, class Value>
#define DefaultSize 101

using namespace std;


TabTemplate
class Table {
protected:
	int size;
	int max_size;
	int curr;

public:

	bool empty() const noexcept;
	bool full() const noexcept;
	bool reset() noexcept;
	bool next() noexcept;
	size_t get_size() const noexcept;
	size_t get_max_size() const noexcept;
	virtual Record<Key, Value>* find(const Key& key) = 0;
	virtual void insert(const Key& key, const Value& value) = 0;
	virtual void remove(const Key& key) = 0; 

};


TabTemplate
bool Table<Key, Value>::full() const noexcept
{
	return (size == max_size);
}

TabTemplate
bool Table<Key, Value>::empty() const noexcept
{
	return (size == 0);
}

TabTemplate
bool Table<Key, Value>::reset() noexcept
{
	if (!empty()) {
		curr = 0;
		return true;
	}
	else {
		curr = -1;
		return false;
	}

}

TabTemplate
bool Table<Key, Value>::next() noexcept
{

	if (curr < max_size && !empty())
	{
		curr++;
		return true;
	}
	else {
		return false;
	}

}

TabTemplate
size_t Table<Key, Value>::get_size() const noexcept
{
	return size;
}

TabTemplate
size_t Table<Key, Value>::get_max_size() const noexcept
{
	return max_size;
}
#endif // !TABLE_H_
