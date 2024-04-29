#ifndef TABRECORD_H
#define TABRECORD_H

#include "TPolynom.h"
#include "Data.h"

template<typename TKey, typename TData> struct TTabRecord {
	TKey key;//ключ
	Data<TData>* data;//данные

	TTabRecord(const TKey& key_, const Data<TData>* data_);

	const TTabRecord& operator=(const TTabRecord& record);
};

template<typename TKey, typename TData>
TTabRecord<TKey, TData>::TTabRecord(const TKey& key_, const Data<TData>* data_) {
	key = key_;
	data = new Data<TData>(data_->value);
}

template<typename TKey, typename TData>
const TTabRecord<TKey,TData>& TTabRecord<TKey,TData>::operator=(const TTabRecord& record) {
	if (this == &record) {
		return *this;
	}
	key = record.key;
	data = new Data<TData>(*record.data);
	return *this;
}


#endif