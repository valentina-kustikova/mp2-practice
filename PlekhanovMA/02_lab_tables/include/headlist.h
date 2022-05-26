#pragma once
#include "list.h"

class THeadList: public TList
{
public:
	TNode* pHead;

public:
	THeadList();
	~THeadList();

	void InsertToTail(TData* const data);
	void InsertToHead(TData* const data);
	void InsertAfter(TData* const data, TData* const after_data);
	void RemoveFirst();
	void RemoveLast();
	void Remove(TData* curr_data);
	void Clear();
};