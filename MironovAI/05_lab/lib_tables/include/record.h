#ifndef RECORD_H_
#define RECORD_H_

template <class Key, class Value>
struct Record
{
	Key key;
	Value data;
	Record();
	Record(const Key& _key, const Value& _data);
	Record(const Record<Key, const Value>& record);
	~Record();
	bool operator==(const Key& key) const;
	bool operator==(const Record<Key, Value>& record) const;
	bool operator<(const Record<Key, Value>& record) const;
	bool operator>(const Record<Key, Value>& record) const;
};

template <class Key, class Value>
Record<Key, Value>::Record() :data(Value()), key(Key())
{
}
template <class Key, class Value>
Record<Key, Value>::Record(const Key& _key, const Value& _data) : key(_key)
{
	data = _data;
}


template <class Key, class Value>
Record<Key, Value>::Record(const Record<Key, const Value>& record)
{
	key = record.key;
	data = record.data;
}

template <class Key, class Value>
Record<Key, Value>::~Record()
{
	
}

template <class Key, class Value>
bool Record<Key, Value>::operator==(const Record<Key, Value>& record) const
{
	return key == record.key && data == *record.data;
}

template <class Key, class Value>
bool Record<Key, Value>::operator==(const Key& key) const
{
	return this->key == key;
}

template <class Key, class Value>
bool Record<Key, Value>::operator<(const Record<Key, Value>&record) const
{
	return key < record.key;
}

template <class Key, class Value>
bool Record<Key, Value>::operator>(const Record<Key, Value>& record) const
{
	return key > record.key;
}

#endif // !RECORD_H_