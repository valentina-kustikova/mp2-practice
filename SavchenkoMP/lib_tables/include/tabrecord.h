#ifndef TABRECORD_H
#define TABRECORD_H

template <class TKey, class TData>
class TabRecord {
	TKey key;
	TData* data;

public:
	TabRecord(const TKey& _key, TData* _data);
	TabRecord(const TabRecord<TKey, TData>& tr);
	TKey GetKey() const;
	TData* GetData() const;

	const TabRecord<TKey, TData>& operator=(const TabRecord<TKey, TData>& tr);

	/*bool operarator==(const TabRecord<TKey, TData>&tr) const;
	bool operarator!=(const TabRecord<TKey, TData>&tr) const;
	bool operarator<(const TabRecord<TKey, TData>&tr) const;
	bool operarator>(const TabRecord<TKey, TData>& tr) const;
	bool operarator<(const TabRecord<TKey, TData>& tr) const;
	bool operarator>(const TabRecord<TKey, TData>& tr) const;*/
};


template <class TKey, class TData>
TabRecord<TKey, TData>::TabRecord(const TKey& _key, TData* _data) {
	key = _key;
	data = _data;
}

template <class TKey, class TData>
TabRecord<TKey, TData>::TabRecord(const TabRecord<TKey, TData>& tr) { 
	key = tr.key;
	data = tr.data; // ÍÀÄÎ ËÈ ÂÛÄÅËßÒÜ ÍÎÂÓŞ ÏÀÌßÒÜ?
}

template <class TKey, class TData>
TKey TabRecord<TKey, TData>::GetKey() const {
	return key;
}

template <class TKey, class TData>
TData* TabRecord<TKey, TData>::GetData() const {
	return data;
}

template <class TKey, class TData>
const TabRecord<TKey, TData>& TabRecord<TKey, TData>::operator=(const TabRecord<TKey, TData>& tr) {
	key = tr.key;
	data = tr.data;

	return (*this);
}


#endif // !TABRECORD_H
