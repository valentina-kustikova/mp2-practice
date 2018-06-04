#include "hashtable.h"

int hashtable::hashfunctable(const key & k)
{
	int h = 0;
	int len = k.length();
	for (int i = 0; i < len; i++)
		h += k[i];
	h = h % 256;
	return h;
}

hashtable::hashtable()
{
	arrayRecord = new list<record>[256];
	maxnum = 256;
	num = 0;
	current = 0;
}

hashtable::~hashtable()
{
	for (int i = 0; i < num; i++)
		arrayRecord[i].cleanlist();
	delete[] arrayRecord;
}

void hashtable::insRecord(const key & k, const datValue & data)
{
	record newRecord(k, data);
	int i = hashfunctable(k);
	arrayRecord[i].insert_to_tail(newRecord);
	num++;
}

void hashtable::delRecord(const key & k)
{
	int i = hashfunctable(k);
	datValue p;
	record del(k, p);
	arrayRecord[i].elemdelete(del);
	num--;
}

datValue * hashtable::findRecord(const key & k)
{
	int i = hashfunctable(k);
	datValue p;
	record f(k, p);
	node<record>* t = arrayRecord[i].search(f);
	if (t != NULL)
		return &t->data.dataRecord;
	else
		return NULL;
}

int hashtable::findNumberRecord(const key & k)
{
	return hashfunctable(k);
}

key hashtable::getKey()
{
	return key();
}

datValue hashtable::getData()
{
	return datValue();
}

ostream & operator<<(ostream & out, const hashtable & h)
{
	for (int i = 0; i < h.maxnum; i++)
		out << h.arrayRecord[i];
	return out;
}
