#ifndef TABRECORD_H
#define TABRECORD_H

#include "TPolynom.h"
#include "Data.h"

template<typename T1, typename T2> class TTabRecord {
private:
	T1 key;
	Data<T2>* data;
public:
	TTabRecord(const T1& key_, const Data<T2>* data_);
	T1 GetKey()const { return key; }
	T2 GetData()const { return data; }
};

template<typename T1, typename T2>
TTabRecord<T1, T2>::TTabRecord(const T1& key_, const Data<T2>* data_) {
	key = key_;
	data = new Data<T2>(data_->value);
}


#endif