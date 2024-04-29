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
	size_t curr_size;
	size_t max_size;
	int curr;

public:

	bool empty() const;
	bool full() const;
	bool reset();
	bool next();
	size_t size() const;

	virtual Record<Key, Value>* find(const Key& key, const Value& value) = 0;
	virtual void insert(const Key& key, const Value& value) = 0;
	virtual void remove(const Key& key) = 0; 

};


TabTemplate
bool Table<Key, Value>::full() const 
{
	return (curr_size == max_size);
}

TabTemplate
bool Table<Key, Value>::empty() const
{
	return (curr_size == 0);
}

TabTemplate
bool Table<Key, Value>::reset() {
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
bool Table<Key, Value>::next()
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
size_t Table<Key, Value>::size() const
{
	return curr_size;
}

#endif // !TABLE_H_
