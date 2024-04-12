#ifndef TABRECORD_H
#define TABRECORD_H

template <class TKey, class TData>
class TabRecord {
	TKey key;
	TData* data;

public:
	TabRecord(const TKey& _key, const TData* _data);
	TKey get_key() const;
	TData* get_data() const;
};


template <class TKey, class TData>
TabRecord<TKey, TData>::TabRecord(const TKey& _key, const TData* _data) {

	throw "NOT IMPLEMENTED";
}

template <class TKey, class TData>
TKey TabRecord<TKey, TData>::get_key() const {

	throw "NOT IMPLEMENTED";
}

template <class TKey, class TData>
TData* TabRecord<TKey, TData>::get_data() const {

	throw "NOT IMPLEMENTED";
}


#endif // !TABRECORD_H
