#ifndef __DATA_H__
#define __DATA_H__

class TData {
public:
	virtual TData* copy() const = 0;
	virtual bool operator < (const TData&) const = 0;
	virtual bool operator > (const TData&) const = 0;
	virtual bool operator == (const TData&) const = 0;
	virtual bool operator != (const TData&) const = 0;
};

#endif // !__DATA_H__
