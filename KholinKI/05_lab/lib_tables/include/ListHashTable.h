#include "HashTable.h"
#include <TList.h>

template<typename TKey, typename TData> class TListHashTable: public THashTable<TKey,TData> {
protected:
	TTabRecord<TKey, TData>** records;
public:
	TListHashTable(int max_size_);
};

template<typename TKey,typename TData> 
TListHashTable<TKey, TData>::TListHashTable(int max_size_) {
	count = 0;
	curr_pos = 0;
	max_size = max_size_;
	records = new TList<TKey, TData>* [max_size];
	for (int i = 0; i < max_size; i++) {
		records[i] = new TList<TKey, TData>();
	}
}