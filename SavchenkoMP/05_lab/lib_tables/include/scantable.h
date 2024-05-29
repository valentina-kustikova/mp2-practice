#ifndef SCANTABLE_H
#define SCANTABLE_H

#include <iostream>
#include "table.h"

template <class TKey, class TData>
class ScanTable : public Table<TKey, TData> {
protected:
	TabRecord<TKey, TData>** recs;

public:
	ScanTable(int _max_size = DEFAULT_SIZE);
	ScanTable(const ScanTable<TKey, TData>& st);
	virtual ~ScanTable();

	virtual void insert(const TKey& _key, TData* _data);
	virtual void remove(const TKey& _key);
	
	virtual TabRecord<TKey, TData>* find(const TKey& key);
	TabRecord<TKey, TData>* operator[](const TKey& _key);

	virtual TabRecord<TKey, TData>* get_curr();

	friend std::ostream& operator<<(std::ostream& out, ScanTable& table) {
		out << "Table size: " << table.count << endl;
		table.reset();
		while (!table.ended()) {
			auto curr = table.get_curr();
			if (curr) {
				out << "(" << curr->key << ", " << *curr->data << "); " << endl;
			}
			table.next();
		}
		//for (int i = 0; i < table.count; i++) {
		//	if (table.recs[i]) {
		//		out << "(" << table.recs[i]->key << ", " << *table.recs[i]->data << "); " << endl;
		//	}
		//}
		return out;
	}
};


template <class TKey, class TData>
ScanTable<TKey, TData>::ScanTable(int _max_size) {
	if (_max_size <= 0) {
		std::string exp = "ERROR: Table max_size cant be less or equal than 0.";
		throw exp;
	}

	max_size = _max_size;
	recs = new TabRecord<TKey, TData>* [max_size];
	for (int i = 0; i < max_size; i++) {
		recs[i] = nullptr;
	}

	count = 0;
	curr_pos = -1;

}

template <class TKey, class TData>
ScanTable<TKey, TData>::ScanTable(const ScanTable<TKey, TData>& st) {
	max_size = st.max_size;
	count = st.count;
	curr_pos = st.curr_pos;

	recs = new TabRecord<TKey, TData>* [max_size];
	for (int i = 0; i < count; i++) {
		TKey key = st.recs[i]->key;
		TData* data = st.recs[i]->data;
		recs[i] = new TabRecord<TKey, TData>(key, data);
	}
}

template <class TKey, class TData>
ScanTable<TKey, TData>::~ScanTable() {
	if (recs != nullptr) {
		for (int i = 0; i < count; i++)
			if (recs[i] != nullptr) delete recs[i];
		delete recs;
	}

}


template <class TKey, class TData>
void ScanTable<TKey, TData>::insert(const TKey& _key, TData* _data) {
	if (full()) {
		std::string exp = "ERROR: Table is full.";
		throw exp;
	}

	if (find(_key) == nullptr) {
		recs[count] = new TabRecord<TKey, TData>(_key, _data);
		count++;
	}
	else {
		throw std::string("ERROR: Record is already exist.");
	}
}

template <class TKey, class TData>
void ScanTable<TKey, TData>::remove(const TKey& _key) {
	if (empty()) {
		std::string exp = "ERROR: Table is empty.";
		throw exp;
	}

	if (find(_key) != nullptr) {
		delete recs[curr_pos];
		recs[curr_pos] = recs[count - 1];
		count--;
	}
	else {
		std::string exp = "ERROR: key not found.";
		throw exp;
	}
}

template <class TKey, class TData>
TabRecord<TKey, TData>* ScanTable<TKey, TData>::find(const TKey& key) {
	TabRecord<TKey, TData>* res = nullptr;

	for (int i = 0; i < count; i++) {
		if (recs[i]->key == key) {
			curr_pos = i;
			res = recs[i];
			break;
		}
	}

	return res;
}

template <class TKey, class TData>
TabRecord<TKey, TData>* ScanTable<TKey, TData>::operator[](const TKey& _key) {
	return find(_key);
}

template <class TKey, class TData>
TabRecord<TKey, TData>* ScanTable<TKey, TData>::get_curr() {
	return recs[curr_pos];
}

#endif // !SCANTABLE_H