#include "sorttable.h"

void sorttable::addSize()
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

sorttable::sorttable(int size)
{
	arrayRecord = new record*[size];
	num = 0;
	maxnum = size;
	current = 0;
}

sorttable::~sorttable()
{
	for (int i = 0; i < num; i++)
		delete arrayRecord[i];
	delete[] arrayRecord;
	num = 0;
}

void sorttable::insRecord(const key & k, const datValue & data)
{	
	if (findNumberRecord(k) == -1)
	{
		if ((double)num / (double)maxnum > 0.7)
			addSize();
		bool f = true;
		for (int i = num; f && (i > 0); i--)
		{
			if (k < arrayRecord[i - 1]->keyRecord)
				arrayRecord[i] = arrayRecord[i - 1];
			else
			{
				arrayRecord[i] = new record(k, data);
				num++;
				f = false;
			}
		}
	}
}

void sorttable::delRecord(const key & k)
{
	int f = findNumberRecord(k);
	if (f != -1)
	{
		delete arrayRecord[f];
		for (int i = f; i < num - 1; i++)
			arrayRecord[i] = arrayRecord[i + 1];
		num--;
	}
	
}

datValue * sorttable::findRecord(const key & k)
{
	int left = 0;
	int right = num - 1;
	while (left < right)
	{
		int i = (right - left) / 2;
		key elem = arrayRecord[i]->keyRecord;
		if (k == elem)
			return &arrayRecord[i]->dataRecord;
		else
			if (k > elem)
				left = i + 1;
			else
				right = i - 1;
	}
	if (left == right)
		if (k == arrayRecord[left]->keyRecord)
			return &arrayRecord[left]->dataRecord;
	return NULL;
}

int sorttable::findNumberRecord(const key & k)
{
	int left = 0;
	int right = num - 1;
	while (left < right)
	{
		int i = (right - left) / 2;
		key elem = arrayRecord[i]->keyRecord;
		if (k == elem)
			return i;
		else
			if (k > elem)
				left = i + 1;
			else
				right = i - 1;
	}
	if (left == right)
		if (k == arrayRecord[left]->keyRecord)
			return left;
	return -1;
}

key sorttable::getKey()
{
	return arrayRecord[current]->keyRecord;
}

datValue sorttable::getData()
{
	return arrayRecord[current]->dataRecord;
}

ostream & operator<<(ostream & out, const sorttable & sr)
{
	for (int i = 0; i < sr.num; i++)
		out << sr.arrayRecord[i]->dataRecord << endl;
	return out;
}
