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
	virtual void Insert(const TKey& _key, TData* _data) = 0;
	virtual void Remove(const TKey& _key) = 0;
	virtual TabRecord<TKey, TData>* Find(const TKey& _key) = 0;
	virtual TData* operator[](const TKey& _key) = 0;

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
	return (count == max_size);
}

template <class TKey, class TData>
bool Table<TKey, TData>::IsEmpty() const {
	return (count == 0);
}

template <class TKey, class TData>
bool Table<TKey, TData>::IsTabEnded() const {
	return (curr_pos >= max_size);
}


template <class TKey, class TData>
bool Table<TKey, TData>::Reset() { // ×ÒÎ ÈÌÅÍÍÎ ÂÎÇÂĞÀÙÀÅÒÑß?
	if (!IsEmpty()) {
		curr_pos = 0;
		return true;
	}
	else {
		curr_pos = -1;
		return false;
	}
	// curr_pos = 0;
}

template <class TKey, class TData>
bool Table<TKey, TData>::Next() { // ×ÒÎ ÈÌÅÍÍÎ ÂÎÇÂĞÀÙÀÅÒÑß?
	if (!IsTabEnded() && !IsEmpty()) {
		curr_pos++;
		return true;
	}
	else {
		return false;
	}
	
	//curr_pos++;
	//if (IsTabEnded()) Reset();
}


template <class TKey, class TData>
int Table<TKey, TData>::GetDataCount() const {
	return count;
}

template <class TKey, class TData>
int Table<TKey, TData>::GetMaxSize() const {
	return max_size;
}


#endif // !TABLE_H
