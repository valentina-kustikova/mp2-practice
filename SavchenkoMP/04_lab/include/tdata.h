#ifndef TDATA_H
#define TDATA_H

#include <iostream>

using namespace std;

class TData {
	virtual TData* copy() const = 0;

	virtual bool operator<(const TData& data) const = 0;
	virtual bool operator>(const TData& data) const = 0;
	virtual bool operator==(const TData& data) const = 0;
	virtual bool operator!=(const TData& data) const = 0;
};

#endif // !TDATA_H
