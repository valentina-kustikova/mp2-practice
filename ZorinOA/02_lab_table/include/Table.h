#pragma once
#include <iostream>

template <class TKey, class TData>
class Table
{
protected:
	int DataCount;
public:
	Table()
		:DataCount(0) {}
	virtual ~Table() {};
	int GetDataCount() const
	{
		return DataCount;
	}
	bool isEmpty() const
	{
		return DataCount == 0;
	}
	virtual void Clear() = 0;
	virtual bool isFull() const = 0;
	virtual TData* Find(const TKey& k) = 0;
	virtual bool Insert(const TKey& k, const TData& d) = 0;
	virtual bool Delete(const TKey& k) = 0;

	virtual void Reset() = 0;
	virtual bool isEnd() const = 0;
	virtual void goNext() = 0;
	virtual TKey getKey() const = 0;
	virtual TData* getData() const = 0;

	friend std::ostream& operator<<(std::ostream& os, Table& t)
	{
		for (t.Reset(); !t.isEnd(); t.goNext())
		{
			os << "key: " << t.getKey() << ", data: " << *(t.getData()) << std::endl;
		}
		return os;
	}
};
