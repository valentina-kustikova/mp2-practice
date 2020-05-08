#ifndef _TABRECORDLINK_H_
#define _TABRECORDLINK_H_

#include "tabrecord.h"

template<typename TKey, class TData> class TTabRecordList;

template<typename TKey, class TData>
class TTabRecordLink : public TTabRecord<TKey, TData>
{
protected:
	TTabRecordLink* pNext;

public:
	TTabRecordLink(TKey _key = {}, TData* _data = nullptr, TTabRecordLink* _pNext = nullptr) :
		TTabRecord<TKey, TData>(_key, _data), pNext(_pNext) {};
	~TTabRecordLink() { pNext = nullptr; }

	TTabRecordLink* GetNext() const { return pNext; }

	void SetNext(TTabRecordLink* _pNext) { pNext = _pNext; }

	friend TTabRecordList<TKey, TData>;
};

#endif