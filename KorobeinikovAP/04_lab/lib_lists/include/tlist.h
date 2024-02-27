#ifndef __TLIST_H__
#define __TLIST_H__

#include "tnode.h"

template <typename T>
class TList {
protected:
	TNode<T>* pFirst;
	TNode<T>* pCurr;
	TNode<T>* pLast;
	TNode<T>* pStop;
public:
	TList();
	TList(const TNode<T>* pFirst_);
	TList(const TList<T>& obj);
	~TList();
	TNode * Search(const T& data_);
	void InsertFirst(const T& data_);
	void InsertBefore(const T& data_, const T& NextData);
	void InsertAfter(const T& data_, const T& BeforeData);
	void InsertBefore(const T& data_); //текущего
	void InsertAfter(const T& data_);  //текущего
	void Remove(const T& data_);
	void Clear();
	int GetSize();
	bool IsEmpty();
	bool IsFull();
	void Reset();
	TNode* GetCurrent();
	void IsEnted();
};


#endif // !1
