#ifndef TABRECORD_H
#define TABRECORD_H

template <class TKey, class TData>
struct TabRecord {
	
	TKey key;
	TData* data;

	TabRecord(const TKey& _key, TData* _data);
	TabRecord(const TabRecord<TKey, TData>& tr);
	~TabRecord();

	const TabRecord<TKey, TData>& operator=(const TabRecord<TKey, TData>& tr);
};


template <class TKey, class TData>
TabRecord<TKey, TData>::TabRecord(const TKey& _key, TData* _data) {
	key = _key;
	data = new TData(*_data);
}

template <class TKey, class TData>
TabRecord<TKey, TData>::TabRecord(const TabRecord<TKey, TData>& tr) { 
	key = tr.key;
	data = new TData(*tr.data);
}

template <class TKey, class TData>
TabRecord<TKey, TData>::~TabRecord() {
	if (data) delete data;
}

template <class TKey, class TData>
const TabRecord<TKey, TData>& TabRecord<TKey, TData>::operator=(const TabRecord<TKey, TData>& tr) {
	key = tr.key;

	if (data) delete data;
	data = new TData(*tr.data);

	return (*this);
}


#endif // !TABRECORD_H
