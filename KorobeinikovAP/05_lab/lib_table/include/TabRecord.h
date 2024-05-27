#ifndef __TABRECORD_H__
#define __TABRECORD_H__

template <typename  TKey, typename  TData>
struct TabRecord {
	TKey key;
	TData* data;

	TabRecord();
	TabRecord(const TKey& _key, TData* _data);
	TabRecord(const TabRecord<TKey, TData>& tr);
	~TabRecord();

	const TabRecord<TKey, TData>& operator=(const TabRecord<TKey, TData>& tr);
};

template <typename TKey, typename TData>
TabRecord<TKey, TData>::TabRecord() {
	key = TKey();
	data = new TData();
}


template <typename TKey, typename TData>
TabRecord<TKey, TData>::TabRecord(const TKey& _key, TData* _data) {
	key = _key;
	data = new TData(*_data);
}

template <typename TKey, typename TData>
TabRecord<TKey, TData>::TabRecord(const TabRecord<TKey, TData>& tr) {
	key = tr.key;
	data = new TData(*tr.data);
}

template <typename TKey, typename TData>
TabRecord<TKey, TData>::~TabRecord() {
	if (data) delete data;
}

template <typename TKey, typename TData>
const TabRecord<TKey, TData>& TabRecord<TKey, TData>::operator=(const TabRecord<TKey, TData>& tr) {
	key = tr.key;

	if (data) delete data;
	data = new TData(*tr.data);

	return (*this);
}


#endif // !TABRECORD_H