#ifndef __SORTED_TABLE_H__
#define __SORTED_TABLE_H__

#include "scantable.h"

template <class TKey, class TData>
class SortedTable : public ScanTable<TKey, TData> {
private:
	void sort();
public:
	SortedTable(int _max_size = 100);
	SortedTable(const ScanTable<TKey, TData>* st);
	SortedTable(const SortedTable<TKey, TData>& srt);
	~SortedTable();

	TabRecord<TKey, TData>* find(const TKey& key);
	TabRecord<TKey, TData>* operator[](const TKey& _key);
	void insert(const TKey& _key, TData* _data);
	void remove(const TKey& _key);


	friend ostream& operator<<(ostream& os, const SortedTable& table)
	{
		
		os << "SortTable size: " << table.count << endl;
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
template <class TKey, class TData>
SortedTable<TKey, TData>::SortedTable(int _max_size) : ScanTable(_max_size) {}

template <class TKey, class TData>
SortedTable<TKey, TData>::SortedTable(const ScanTable<TKey, TData>* st) : ScanTable(*st) {
	sort();
}

template <class TKey, class TData>
SortedTable<TKey, TData>::SortedTable(const SortedTable<TKey, TData>& srt) {
	count = srt.count;
	max_size = srt.max_size;
	curr_pos = srt.curr_pos;

	recs = new TabRecord<TKey, TData>* [max_size];
	for (int i = 0; i < count; i++) {
		recs[i] = new TabRecord<TKey, TData>(*srt.recs[i]);
	}
}
//деструктор
template <class TKey, class TData>
SortedTable<TKey, TData>::~SortedTable() {
	//ScanTable<TKey,TData>::~ScanTable();
}


template <class TKey, class TData>
TabRecord<TKey, TData>* SortedTable<TKey, TData>::find(const TKey& key) {
	int left = 0, right = count - 1;
	TabRecord<TKey, TData>* search = nullptr;

	while (left <= right) {
		int mid = (right + left) / 2;

		if (recs[mid]->key == key) {
			search = recs[mid];
			right = mid;
			left = mid + 1;
		}
		else if (recs[mid]->key < key) left = mid + 1;
		else right = mid - 1;
	}
	if (right != -1)
		if (search == nullptr)
			curr_pos = right + 1;
		else
			curr_pos = right;
	else
		curr_pos = 0;
	return search;
 }

template <class TKey, class TData>
TabRecord<TKey, TData>* SortedTable<TKey, TData>::operator[](const TKey& _key) {
	return find(_key);
}

template <class TKey, class TData>
void SortedTable<TKey, TData>::insert(const TKey& _key, TData* _data) {
	if (full()) {
		std::string exp = "ERROR: Table is full.";
		throw exp;
	}
	
	//recs[count] = new TabRecord<TKey, TData>();
	//сделать проверку на find
	if (find(_key) == nullptr) {
		for (int i = count - 1; i >= curr_pos; i--) {
			recs[i + 1] = recs[i];
		}
		recs[curr_pos] = new TabRecord<TKey, TData>(_key, _data);

		count++;
	}
}

template <class TKey, class TData>
void SortedTable<TKey, TData>::remove(const TKey& _key) {
	if (empty()) {
		std::string exp = "ERROR: Table is empty.";
		throw exp;
	}

	TabRecord<TKey, TData>* rec = find(_key);
	if (rec == nullptr) {
		std::string exp = "ERROR: Key nod found.";
		throw exp;
	}
	else {
		delete rec;
		for (int i = curr_pos; i < count - 1; i++) {
			recs[i] = recs[i + 1];
		}
		count--;
	}
}

template <class TKey, class TData>
void SortedTable<TKey, TData>::sort() {
	for (int i = 0; i < count; ++i)
	{
		for (int j = i + 1; j < count; ++j)
		{
			if (recs[i]->key > recs[j]->key)
			{
				TabRecord<TKey, TData>* t = recs[i];
				recs[i] = recs[j];
				recs[j] = t;
			}
		}
	}
}


#endif




