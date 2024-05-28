#ifndef __SCAN_TABLE_H__
#define __SCAN_TABLE_H__


#include "table.h"



template <typename TKey, typename TData>
class ScanTable : public Table<TKey, TData> {
protected:
	TabRecord<TKey, TData>** recs;
public:
	ScanTable(int _max_size = 100);
	ScanTable(const ScanTable<TKey, TData>& st);
	virtual ~ScanTable();

	virtual void insert(const TKey& _key, TData* _data);
	virtual void remove(const TKey& _key);

	virtual TabRecord<TKey, TData>* find(const TKey& key);
	TabRecord<TKey, TData>* operator[](const TKey& _key);


	friend ostream& operator<<(ostream& os, const ScanTable& table)
	{
		
		os << "ScanTable size: " << table.count << endl;
		string str1 = string(32, '-'), str2 = string(62, '-');
		os << '+' << str1 << '+' << str2 << '+' << endl;
		for (int i = 0; i < table.count; ++i)
		{
			if (table.recs[i]) {
				os << "| " << setw(30) << table.recs[i]->key << " | " << setw(60) << *table.recs[i]->data << " |\n";
				os << '+' << str1 << '+' << str2 << '+' << endl;
			}
		}
		os << endl;
		return os;
	}
};


//конструкторы
template <typename TKey, typename TData>
ScanTable<TKey, TData>::ScanTable(int _max_size) {
	if (_max_size <= 0) {
		std::string exp = "ERROR: Table max_size cant be less or equal than 0.";
		throw exp;
	}

	max_size = _max_size;
	recs = new TabRecord<TKey, TData>*[max_size];

	this->count = 0;
	curr_pos = -1;

}

template <typename TKey, typename TData>
ScanTable<TKey, TData>::ScanTable(const ScanTable<TKey, TData>& st) {
	max_size = st.max_size;
	this->count = st.count;
	curr_pos = st.curr_pos;

	recs = new TabRecord<TKey, TData>* [max_size];
	for (int i = 0; i < count; i++) {
		TKey key = st.recs[i]->key;
		TData* data = st.recs[i]->data;
		recs[i] = new TabRecord<TKey, TData>(key, data);
	}
}

//деструктор
template <typename TKey, typename TData>
ScanTable<TKey, TData>::~ScanTable() {
	if (recs != nullptr) {
		for (int i = 0; i < count; i++)
			if (recs[i] != nullptr) delete recs[i];
		delete recs;
	}
}


//3 метода и оператор
template <typename TKey, typename TData>
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


template <typename TKey, typename TData>
void ScanTable<TKey, TData>::insert(const TKey& _key, TData* _data) {
	if (full()) {
		throw "ERROR: Table is full.";
	}

	if (find(_key) == nullptr) {
		recs[count++] = new TabRecord<TKey, TData>(_key, _data);
	}
	else {
		throw "Key repeat, it's not good";
	}
}

template <typename TKey, typename TData>
void ScanTable<TKey, TData>::remove(const TKey& _key) {
	if (empty()) {
		string exp = "ERROR: Table is empty.";
		throw exp;
	}

	if (find(_key) != nullptr) {
		delete recs[curr_pos];
		if (count - 1 != curr_pos) {
			recs[curr_pos] = new TabRecord<TKey, TData>(*recs[count - 1]);
			delete recs[count - 1];
		}
		else {
			recs[curr_pos] = nullptr;
		}	
		count--;
	}
	else {
		throw "ERROR: key not found.";
	}
}



template <typename TKey, typename TData>
TabRecord<TKey, TData>* ScanTable<TKey, TData>::operator[](const TKey& _key) {
	return find(_key);
}


#endif