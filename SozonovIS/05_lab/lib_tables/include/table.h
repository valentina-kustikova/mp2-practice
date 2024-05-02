#ifndef __TABLE_H__
#define __TABLE_H__

template <typename TKey, typename TData>
class Table {
private:
	int count;
	int maxSize;
	int currPos;
public:
	Table(int maxSize);
	virtual TabRecord* Find(TKey key) = 0;
	virtual void Insert(TKey key, TData* data) = 0;
	virtual void Remove(TKey key) = 0;
	bool IsFull()const;
	bool IsEmpty()const;
	virtual void Reset();
	virtual void Next();
	virtual bool IsEnded()const;
	GetCurrent;
	virtual TKey GetKey() = 0;
	virtual TData* GetData() = 0;
}

#endif