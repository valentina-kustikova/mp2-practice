#ifndef SCANTABLE_H
#define SCANTABLE_H

#include "table.h"

template <class TKey, class TData>
class ScanTable : public Table<TKey, TData> {
protected:
	TabRecord<TKey, TData>** recs;

public:
	ScanTable(int _max_size);
	ScanTable(const ScanTable<TKey, TData>& obj);
	virtual ~ScanTable();
	
	void Insert(const TKey& _key, const TData* _data);
	void Remove(const TKey& _key);
	TabRecord<TKey, TData>* Find(const TKey& key);

	TKey GetKey() const;
	TData* GetData() const;
};


template <class TKey, class TData>
ScanTable<TKey, TData>::ScanTable(int _max_size) {

	throw "NOT IMPLEMENTED";
}

template <class TKey, class TData>
ScanTable<TKey, TData>::ScanTable(const ScanTable<TKey, TData>& obj) {

	throw "NOT IMPLEMENTED";
}

template <class TKey, class TData>
ScanTable<TKey, TData>::~ScanTable() {

	throw "NOT IMPLEMENTED";
}


template <class TKey, class TData>
void ScanTable<TKey, TData>::Insert(const TKey& _key, const TData* _data) {

	throw "NOT IMPLEMENTED";
}

template <class TKey, class TData>
void ScanTable<TKey, TData>::Remove(const TKey& _key) {

	throw "NOT IMPLEMENTED";
}

template <class TKey, class TData>
TabRecord<TKey, TData>* ScanTable<TKey, TData>::Find(const TKey& key) {

	throw "NOT IMPLEMENTED";
}


template <class TKey, class TData>
TKey ScanTable<TKey, TData>::GetKey() const {

	throw "NOT IMPLEMENTED";
}

template <class TKey, class TData>
TData* ScanTable<TKey, TData>::GetData() const {

	throw "NOT IMPLEMENTED";
}

#endif // !SCANTABLE_H
