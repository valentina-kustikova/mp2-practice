#ifndef _TRINGLIST_
#define _TRINGLIST_
#include "tlist.h"


template <typename T>
class TRingList : public TList<T>
{
private:
	TNode<T>* pHead;
public:
	//перегрузить некоторые функциии, в том числе конструктор
	//pHead - фективный элемент
};


#endif