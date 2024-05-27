#ifndef __TAB_RECORD_H__
#define __TAB_RECORD_H__

#include <iostream>

using namespace std;

template <typename TKey, typename TData>
struct TabRecord {
	TKey key;
	TData* data;

	TabRecord();
	TabRecord(TKey _key, TData *_data);
	friend ostream& operator<<(ostream& out, const TabRecord<TKey, TData>& record) {
		out << "| " << record.key << " | " << *record.data << " |";
		return out;
	}
};

template <typename TKey, typename TData>
TabRecord<TKey, TData>::TabRecord() {
	key = TKey();
	data = nullptr;
}

template <typename TKey, typename TData>
TabRecord<TKey, TData>::TabRecord(TKey _key, TData* _data) {
	key = _key;
	data = new TData(*_data);
}

#endif