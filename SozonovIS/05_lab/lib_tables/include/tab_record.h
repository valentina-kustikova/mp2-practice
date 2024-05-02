#ifndef __TAB_RECORD_H__
#define __TAB_RECORD_H__

template <typename TKey, typename TData>
class TabRecord {
protected:
	TKey key;
	TData* data;
public:
	TabRecord(TKey key, TData* data);
	TKey GetKey()const;
	TData* GetData()const;
}

#endif