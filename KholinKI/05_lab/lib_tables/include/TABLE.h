#ifndef TABLE_H
#define TABLE_H

#include "TabRecord.h"

template<typename TKey, typename TData> class Table {
protected:
	int count;//индекс последней незанятой записи
public:
	Table();
	virtual void Insert(TKey key, const Data<TData>* data_) = 0;
	virtual TTabRecord<TKey,TData>* Find(TKey key) = 0;
	virtual void Remove(TKey key) = 0;
	virtual bool IsFull()const = 0;
	virtual bool IsEmpty()const = 0;
	virtual bool IsTabEnded()const = 0;
	/*virtual bool Next() = 0;
	virtual bool Reset() = 0;*/
	virtual int GetCount()const = 0;
	virtual TKey GetKey()const = 0;
	virtual Data<TData>* GetData()const = 0;
};

template<typename TKey, typename TData>
Table<TKey,TData>::Table() {
	count = 0;
}
#endif