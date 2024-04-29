#ifndef RECORD_H_
#define RECORD_H_

template <class Key, class Value>
struct Record
{
	Key key;
	Value* data;

	Record(const Key& _key, Value& _data);
	Record(const Record<Key, Value>& record);

	bool operator==(const Key& key) const;
	bool operator==(const Record<Key, Value>& record) const;
	bool operator<(const Record<Key, Value>& record) const;
	bool operator>(const Record<Key, Value>& record) const;
};

template <class Key, class Value>
Record<Key, Value>::Record(const Key& _key, Value& _data) : key(_key)
{
	data = new Value; *data = _data
}

template <class Key, class Value>
Record<Key, Value>::Record(const Record<Key, Value>& record)
{
	key = record.key;
	data = record.data;
}

template <class Key, class Value>
bool Record<Key, Value>::operator==(const Record<Key, Value>& record) const
{
	if (!data || !record.data) return data == record.data && key == record.key;
	return key == record.key && *data == *record.data;
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