#ifndef _TLIST_
#define _TLIST
#include "tnode.h"

template <typename T>
class TList
{
private:
	TNode<T>* pFirst;
	TNode<T>* pStop;
	TNode<T>* pLast; //?
	TNode<T>* pPrev; //?
	TNode<T>* pCurr; //?
public:
	TList();
	TList(const TNode<T>* pF);
	TList(const TList<T>& tL);
	~TList();
};

#endif