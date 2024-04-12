#ifndef TABLE_H
#define TABLE_H

#include "tabrecord.h"

template <class TKey, class TData>
class Table {
protected:
	int count;
	int max_size;
	int curr_pos;

public:
	virtual void Insert(const TKey& _key, const TData* _data) = 0;
	virtual void Remove(const TKey& _key) = 0;
	virtual TabRecord<TKey, TData>* Find(const TKey& _key) = 0;

	bool IsFull() const;
	bool IsEmpty() const;
	bool IsTabEnded() const;

	virtual bool Reset();
	virtual bool Next();

	int GetDataCount() const;
	int GetMaxSize() const;
	virtual TKey GetKey() const = 0;
	virtual TData* GetData() const = 0;
};


template <class TKey, class TData>
bool Table<TKey, TData>::IsFull() const {

	throw "NOT IMPLEMENTED";
}

template <class TKey, class TData>
bool Table<TKey, TData>::IsEmpty() const {

	throw "NOT IMPLEMENTED";
}

template <class TKey, class TData>
bool Table<TKey, TData>::IsTabEnded() const {

	throw "NOT IMPLEMENTED";
}


template <class TKey, class TData>
bool Table<TKey, TData>::Reset() {

	throw "NOT IMPLEMENTED";
}

template <class TKey, class TData>
bool Table<TKey, TData>::Next() {

	throw "NOT IMPLEMENTED";
}


template <class TKey, class TData>
int Table<TKey, TData>::GetDataCount() const {

	throw "NOT IMPLEMENTED";
}

template <class TKey, class TData>
int Table<TKey, TData>::GetMaxSize() const {

	throw "NOT IMPLEMENTED";
}


#endif // !TABLE_H
