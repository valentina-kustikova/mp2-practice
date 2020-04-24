#ifndef _TABRECORD_H_
#define _TABRECORD_H_

template<typename TKey, class TData>
class TabRecord
{
protected:
	TKey key;
	TData* data;

public:
	TabRecord(TKey _key, TData _data)
	{
		key = _key;
		data = _data;
	}

	TData* GetData() { return data; }
	TKey GetKey() { return key; }
};

#endif
