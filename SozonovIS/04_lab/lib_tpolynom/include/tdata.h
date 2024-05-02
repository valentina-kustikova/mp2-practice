#ifndef __DATA_H__
#define __DATA_H__

#include <iostream>

using namespace std;

class TData {
public:
	virtual TData* copy()const = 0;
	virtual bool operator<(const TData& data)const = 0;
	virtual bool operator>(const TData& data)const = 0;
	virtual bool operator==(const TData& data)const = 0;
	virtual bool operator!=(const TData& data)const = 0;
};

#endif