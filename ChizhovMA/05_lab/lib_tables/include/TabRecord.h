#ifndef TAB_RECORD_H
#define TAB_RECORD_H

template <class TKey, class TData>
class TabRecord
{
	TKey key;
	TData* data;
public:
	TabRecord();
	TabRecord(const TKey& _key, TData* _data);
	TabRecord(const TabRecord<TKey, TData>& tr);
	TKey GetKey() const;
	TData* GetData() const;
};

template <class TKey, class TData>
TabRecord<TKey, TData>::TabRecord(){}
template <class TKey, class TData>
TabRecord<TKey, TData>::TabRecord(const TKey& _key, TData* _data) 
{
	key = _key;
	data = new TData(*_data);
}

template <class TKey, class TData>
TabRecord<TKey, TData>::TabRecord(const TabRecord<TKey, TData>& tr)
{
	key = tr.key;
	data = new TData(*tr.data);
}

template <class TKey, class TData>
TKey TabRecord<TKey, TData>::GetKey() const
{
	return key;
}

template <class TKey, class TData>
TData* TabRecord<TKey, TData>::GetData() const
{
	return data;
}
#endif //! TAB_RECORD_H
