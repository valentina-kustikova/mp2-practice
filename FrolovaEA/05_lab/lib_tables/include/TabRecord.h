#ifndef  _TABRECORD_H_
#define _TABRECORD_H_
#include "iostream"

using namespace std;

template<typename TKey, typename TData>
class TTabRecord
{

public:

	TKey key;
	TData* data;

public:

	TTabRecord();
	TTabRecord(const TKey& _key, const TData* _data);
	TTabRecord(const TTabRecord<TKey, TData>& record);
	~TTabRecord();

	TKey GetKey() const;
	TData* GetData() const;

	/*void SetData(TData* newData);*/

	const TTabRecord<TKey, TData>& operator=(const TTabRecord<TKey, TData>& TabRec);

};

template<typename TKey, typename TData>
TTabRecord<TKey, TData>::TTabRecord() : key(), data(nullptr) {};

template<typename TKey, typename TData>
TTabRecord<TKey, TData>::TTabRecord(const TKey& _key, const TData* _data)
{
	key = _key;
	data = new TData(*_data);
}

template<typename TKey, typename TData>
TTabRecord<TKey, TData>::TTabRecord(const TTabRecord<TKey, TData>& record)
{
	key = record.key;
	data = new TData(*record.data);
}

template<typename TKey, typename TData>
TTabRecord<TKey, TData>::~TTabRecord()
{
	if (data) delete data;
}

template<typename TKey, typename TData>
TKey TTabRecord<TKey, TData>::GetKey() const
{
	return key;
}

template<typename TKey, typename TData>
TData* TTabRecord<TKey, TData>::GetData() const
{
	return data;
}

template<typename TKey, typename TData>
const TTabRecord<TKey, TData>& TTabRecord<TKey, TData>::operator=(const TTabRecord<TKey, TData>& TabRec)
{
	key = TabRec.key;

	if (data)
		delete data;

	data = new TData(*TabRec.data);

	return(*this);
}

#endif // ! _TABRECORD_H_