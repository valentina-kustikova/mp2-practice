#ifndef TABRECORD_H
#define TABRECORD_H

template <class TKey, class TData>
class TabRecord {
	TKey key;
	TData* data;

public:
	TabRecord(const TKey& _key, TData* _data);
	TabRecord(const TabRecord<TKey, TData>& tr);
	TKey get_key() const;
	TData* get_data() const;
};


template <class TKey, class TData>
TabRecord<TKey, TData>::TabRecord(const TKey& _key, TData* _data) {
	key = _key;
	data = _data;
}

template <class TKey, class TData>
TabRecord<TKey, TData>::TabRecord(const TabRecord<TKey, TData>& tr) {
	key = tr.key;
	data = tr.data;
}

template <class TKey, class TData>
TKey TabRecord<TKey, TData>::get_key() const {
	return key;
}

template <class TKey, class TData>
TData* TabRecord<TKey, TData>::get_data() const {
	return data;
}


#endif // !TABRECORD_H
