#ifndef _TDATA_
#define _TDATA

class TData
{
public:
	virtual TData* copy() const = 0;
	virtual bool operator<(const TData& data) const = 0;
	virtual bool operator>(const TData& data) const = 0;
	virtual bool operator==(const TData& data) const = 0;
	virtual bool operator!=(const TData& data) const = 0;
};

#endif