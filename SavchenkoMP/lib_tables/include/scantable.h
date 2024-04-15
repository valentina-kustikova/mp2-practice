#ifndef SCANTABLE_H
#define SCANTABLE_H

#include <iostream>
#include "table.h"

//using namespace std;

template <class TKey, class TData>
class ScanTable : public Table<TKey, TData> {
protected:
	TabRecord<TKey, TData>** recs;

public:
	ScanTable(int _max_size);
	ScanTable(const ScanTable<TKey, TData>& st);
	virtual ~ScanTable();
	
	virtual void  Insert(const TKey& _key, TData* _data);
	virtual void Remove(const TKey& _key);
	virtual TabRecord<TKey, TData>* Find(const TKey& key);

	virtual TKey GetKey() const;
	virtual TData* GetData() const;
};


template <class TKey, class TData>
ScanTable<TKey, TData>::ScanTable(int _max_size) {
	if (_max_size <= 0) {
		std::string exp = "ERROR: Table max_size cant be less or equal than 0.";
		//string exp = "ERROR: Table max_size can't be less or equal than 0.";
		throw exp;
	}

	max_size = _max_size;
	recs = new TabRecord<TKey, TData>* [max_size];

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
		TKey key = st.recs[i]->GetKey();
		TData* data = new TData(*st.recs[i]->GetData()); // мюдн бшдекърэ мнбсч оюлърэ хкх апюрэ ясыеярбсчысч?
		recs[i] = new TabRecord<TKey, TData>(key, data)
	}
}

template <class TKey, class TData>
ScanTable<TKey, TData>::~ScanTable() {
	/*if (recs) {
		for (int i = 0; i < max_size; i++) {
			if (recs[i]) delete recs[i];
		}
		delete recs;
	}*/
	if (recs != nullptr) {
		for (int i = 0; i < count; i++)
			if (recs[i] != nullptr) delete recs[i];
		delete recs;
	}
	
}


template <class TKey, class TData>
void ScanTable<TKey, TData>::Insert(const TKey& _key, TData* _data) {
	if (IsFull()) {
		std::string exp = "ERROR: Table is full.";
		//string exp = "ERROR: Table is full.";
		throw exp;
	}
	
	if (Find(_key) == nullptr) { // мюдн кх гюлемърэ дюммше, еякх мюидеряъ?
		recs[count] = new TabRecord<TKey, TData>(_key, _data);
		count++;
	}
}

template <class TKey, class TData>
void ScanTable<TKey, TData>::Remove(const TKey& _key) {
	if (IsEmpty()) {
		std::string exp = "ERROR: Table is empty.";
		//string exp = "ERROR: Table is empty.";
		throw exp;
	}

	if (Find(_key) != nullptr) {
		delete recs[curr_pos];
		for (int i = curr_pos; i < count; i++) {
			recs[i] = recs[i + 1];
		}
		count--;
	}
	else {
		std::string exp = "ERROR: key not found.";
		//string exp = "ERROR: key not found.";
		throw exp;
	}
}

template <class TKey, class TData>
TabRecord<TKey, TData>* ScanTable<TKey, TData>::Find(const TKey& key) {
	TabRecord<TKey, TData>* res = nullptr;
	
	for (int i = 0; i < count; i++) {
		if (recs[i]->GetKey() == key) {
			curr_pos = i;
			res = recs[i];
			break;
		}
	}

	return res;
}


template <class TKey, class TData>
TKey ScanTable<TKey, TData>::GetKey() const { // recs[curr_pos]->key ??? 
	if (IsEmpty()) {
		std::string exp = "ERROR: Table is empty.";
		//string exp = "ERROR: Table is empty.";
		throw exp;
	}
	//if (IsTabEnded()) Reset();
	if (IsTabEnded()) {
		std::string exp = "ERROR: Table is ended.";
		//string exp = "ERROR: Table is ended.";
		throw exp;
	}

	return recs[curr_pos]->GetKey(); // бнгбпюыюеряъ рейсыхи йкчв?
}

template <class TKey, class TData>
TData* ScanTable<TKey, TData>::GetData() const { // recs[curr_pos]->data ???
	if (IsEmpty()) {
		std::string exp = "ERROR: Table is empty.";
		//string exp = "ERROR: Table is empty.";
		throw exp;
	}
	//if (IsTabEnded()) Reset();
	if (IsTabEnded()) {
		std::string exp = "ERROR: Table is ended.";
		//string exp = "ERROR: Table is ended.";
		throw exp;
	}

	return recs[curr_pos]->GetData(); // бнгбпюыюеряъ рейсыхе дюммше?
}

#endif // !SCANTABLE_H
