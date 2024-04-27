#ifndef TABRECORD_H
#define TABRECORD_H

#include "TPolynom.h"
#include "Data.h"

template<typename TKey, typename TData> struct TTabRecord {
	TKey key;//ключ
	Data<TData>* data;//данные

	TTabRecord(const TKey& key_, const Data<TData>* data_);
};

template<typename TKey, typename TData>
TTabRecord<TKey, TData>::TTabRecord(const TKey& key_, const Data<TData>* data_) {
	key = key_;
	data = new Data<TData>(data_->value);
}


#endif