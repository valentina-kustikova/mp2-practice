#include "scantable.h"

void scantable::addSize()
{
	record **t = new record*[num];
	for (int i = 0; i < num; i++)
		t[i] = arrayRecord[i];
	delete[] arrayRecord;
	arrayRecord = new record*[2 * maxnum];
	for (int i = 0; i < num; i++)
		arrayRecord[i] = t[i];
	delete t;
}

scantable::scantable(int size)
{
	arrayRecord = new record*[size];
	maxnum = size;
	num = 0;
	current = 0;
}

scantable::~scantable()
{
	for (int i = 0; i < num; i++)
		delete arrayRecord[i];
	delete[] arrayRecord;
	num = 0;
}

void scantable::insRecord(const key & k, const datValue & data)
{
	if ((double)num / (double)maxnum > 0.7)
		addSize();
	bool f = true;
	for (int i = 0; (i < num) && f; i++)
		if (k == arrayRecord[i]->keyRecord)
			f = false;
	if (f)
	{
		arrayRecord[num] = new record(k, data);
		num++;
	}
}

void scantable::delRecord(const key & k)
{
	int i = findNumberRecord(k);
	if (i != -1)
	{
		delete arrayRecord[i];
		arrayRecord[i] = arrayRecord[num - 1];
		num--;
	}
}

datValue* scantable::findRecord(const key & k)
{
	for (int i = 0; i < num; i++)
		if (arrayRecord[i]->keyRecord == k)
			return &arrayRecord[i]->dataRecord;
	return NULL;
}

int scantable::findNumberRecord(const key & k)
{
	for (int i = 0; i < num; i++)
		if (arrayRecord[i]->keyRecord == k)
			return i;
	return -1;
}

key scantable::getKey()
{
	return arrayRecord[current]->keyRecord;
}

datValue scantable::getData()
{
	return arrayRecord[current]->dataRecord;
}

ostream & operator<<(ostream & out, const scantable & sc)
{
	for (int i = 0; i < sc.num; i++)
		out << sc.arrayRecord[i]->dataRecord << endl;
	return out;
}
