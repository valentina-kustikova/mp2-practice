#pragma once
#define MAX_SIZE 25

template <class TKey, class TData>
class Table
{
protected:
	int DataCount;
public:
	Table()
	{
		DataCount = 0;
	}
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
    virtual void Insert(const TKey& k, const TData& d) = 0;
    virtual void Delete(const TKey& k) = 0;
};

