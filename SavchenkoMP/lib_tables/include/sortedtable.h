#ifndef SORTEDTABLE_H
#define SORTEDTABLE_H

#include "scantable.h"
#include "sortings.h"

template <class TKey, class TData>
class SortedTable : public ScanTable<TKey, TData> {
private:
	void Sort();

public:
	SortedTable(int _max_size);
	SortedTable(const ScanTable<TKey, TData>* st);
	SortedTable(const SortedTable<TKey, TData>& srt);

	void Insert(const TKey& _key, const TData* _data);
	void Remove(const TKey& _key);
	TabRecord<TKey, TData>* Find(const TKey& key);
};


template <class TKey, class TData>
void SortedTable<TKey, TData>::Sort() {

	throw "NOT IMPLEMENTED";
}


template <class TKey, class TData>
SortedTable<TKey, TData>::SortedTable(int _max_size) {

	throw "NOT IMPLEMENTED";
}

template <class TKey, class TData>
SortedTable<TKey, TData>::SortedTable(const ScanTable<TKey, TData>* st) {

	throw "NOT IMPLEMENTED";
}

template <class TKey, class TData>
SortedTable<TKey, TData>::SortedTable(const SortedTable<TKey, TData>& srt) {

	throw "NOT IMPLEMENTED";
}


template <class TKey, class TData>
void SortedTable<TKey, TData>::Insert(const TKey& _key, const TData* _data) {

	throw "NOT IMPLEMENTED";
}

template <class TKey, class TData>
void SortedTable<TKey, TData>::Remove(const TKey& _key) {

	throw "NOT IMPLEMENTED";
}

template <class TKey, class TData>
TabRecord<TKey, TData>* SortedTable<TKey, TData>::Find(const TKey& key) {

	throw "NOT IMPLEMENTED";
}

#endif // !SORTEDTABLE_H
