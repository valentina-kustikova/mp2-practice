#ifndef __TAB_RECORD_H__
#define __TAB_RECORD_H__

template <typename TKey, typename TData>
struct TabRecord {
	TKey key;
	TData* data;

	TabRecord();
	TabRecord(TKey _key, TData *_data);
	TKey GetKey()const;
	TData* GetData()const;
};

template <typename TKey, typename TData>
TabRecord<TKey, TData>::TabRecord() {
	key = TKey();
	data = nullptr;
}

template <typename TKey, typename TData>
TabRecord<TKey, TData>::TabRecord(TKey _key, TData* _data) {
	key = _key;
	data = new TData(*_data);
}

template <typename TKey, typename TData>
TKey TabRecord<TKey, TData>::GetKey()const {
	return key;
}

template <typename TKey, typename TData>
TData* TabRecord<TKey, TData>::GetData()const {
	return data;
}

#endif