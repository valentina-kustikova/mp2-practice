#include "record.h"

record::record(const key & k, const datValue & data)
{
	keyRecord = k;
	dataRecord = data;
}

record::record(const record & rec)
{
	keyRecord = rec.keyRecord;
	dataRecord = rec.dataRecord;
}

record & record::operator=(const record & rec)
{
	if (this != &rec)
	{
		keyRecord = rec.keyRecord;
		dataRecord = rec.dataRecord;
	}
	return *this;
}

bool record::operator==(const record & rec)
{
	return keyRecord == rec.keyRecord;
}

bool record::operator!=(const record & rec)
{
	return keyRecord != rec.keyRecord;
}

bool record::operator>(const record & rec)
{
	return keyRecord > rec.keyRecord;
}

bool record::operator<(const record & rec)
{
	return keyRecord < rec.keyRecord;
}

ostream & operator<<(ostream & out, const record & r)
{
	out << r.dataRecord;
	return out;
}
