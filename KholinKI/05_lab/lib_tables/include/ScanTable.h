#ifndef SCANTABLE_H
#define SCANTABLE_H

#include "TABLE.h"


template<typename T1, typename T2> class TScanTable: public Table<T1,T2> {
protected:
	TTabRecord<T1, T2>** records;
public:
	TScanTable(int max_size_);
	void Insert(T1 Key, const Data<T2>* data_) override;
};

template<typename T1, typename T2>
TScanTable<T1, T2>::TScanTable(int max_size_) :Table<T1,T2>(max_size_){
	records = new TTabRecord<T1, T2>*[max_size];
}


template<typename T1, typename T2>
void TScanTable<T1,T2>::Insert(T1 key, const Data<T2>* data_) {
	if (IsFull()) {
		throw "Table is full!";
	}
	count++;
	records[count] = new TTabRecord<T1, T2>(key, data_);
}

#endif