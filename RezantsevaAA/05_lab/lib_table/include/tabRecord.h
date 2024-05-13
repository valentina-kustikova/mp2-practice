#ifndef __TABRECORD_H__
#define __TABRECORD_H__
#include "tpolynom.h"

template <typename TKey, typename TData> 
class TTabRecord {
protected:
	TKey key;
	TData* data;
public:
	TTabRecord();
	TTabRecord(const TKey& k, const TData& d);
	TTabRecord(const TTabRecord<TKey, TData>& record);

	TKey GetKey() const;
	TData* GetData() const;
	bool operator==(const TKey& k) const;
	bool operator==(const TTabRecord<TKey, TData>& record) const;
};



template <typename TKey, typename TData>  TTabRecord<TKey, TData>::TTabRecord()
{
}


template <typename TKey, typename TData>  TTabRecord<TKey, TData>::TTabRecord(const TKey& k, const TData& d)
{
	key = k;
	data = new TData(d);
}

template <typename TKey, typename TData>  TTabRecord<TKey, TData>::TTabRecord(const TTabRecord<TKey, TData>& record)
{
	key = record.key;
	data = record.data;
}

template <typename TKey, typename TData> TKey  TTabRecord<TKey, TData>::GetKey() const
{
	return key;
}

template <typename TKey, typename TData> TData*  TTabRecord<TKey, TData>::GetData() const
{
	return data;
}

template <typename TKey, typename TData> bool TTabRecord<TKey, TData>::operator==(const TKey& k) const
{
	return (key == k);
}

template <typename TKey, typename TData> bool  TTabRecord<TKey, TData>::operator==(const TTabRecord<TKey, TData>& record) const
{
	return (key == record.key && data == *record.data);
}
#endif
 