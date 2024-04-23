#ifndef TABLE_H
#define TABLE_H

#include "TabRecord.h"

template<typename T1, typename T2> class Table {
protected:
	int count;
	int max_size;
	int curr_pos;
public:
	Table(int max_size_);
	virtual void Insert(T1 key, const Data<T2>* data_) = 0;
	//virtual TTabRecord* Find(T1 key) = 0;
	//virtual void Remove(T1 key) = 0;
	bool IsFull()const;
	bool IsEmpty()const;
};

template<typename T1, typename T2>
Table<T1,T2>::Table(int max_size_) {
	max_size = max_size_;
	count = -1;
	curr_pos = 0;
}
template<typename T1, typename T2>
bool Table<T1,T2>::IsFull()const { return count == max_size ? true : false; }

template<typename T1, typename T2>
bool Table<T1,T2>::IsEmpty()const { return count == -1 ? true : false; }
#endif