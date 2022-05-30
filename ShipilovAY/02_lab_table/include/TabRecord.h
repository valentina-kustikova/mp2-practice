#pragma once
using namespace std;

template <class TData, class TKey>
class TabRecord
{
protected:
	TKey Key;
	TData* Data;
public:
	TabRecord(TData _data = {}, TKey _key = {}) { Key = _key; Data = new TData(_data); }
	TabRecord(const TabRecord& Table)
	{
		Key = Table.Key;
		Data = new TData(*(Table.Data));
	}
	~TabRecord() {}
	TKey GetKey() const { return Key; }
	TData* GetData() const { return Data; }
	TabRecord<TData, TKey>& operator=(const TabRecord<TData, TKey>& Table)
	{
		Key = Table.Key;
		Data = new TData(*(Table.Data));
		return *this;
	}
	bool operator==(const TabRecord& tab)
	{
		return Key == tab.Key;
	}
	bool operator<(const TabRecord& tab)
	{
		return Key < tab.Key;
	}
	bool operator>(const TabRecord& tab)
	{
		return Key > tab.Key;
	}
};
