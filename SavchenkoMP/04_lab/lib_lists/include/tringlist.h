#ifndef TRINGLIST_H
#define TRINGLIST_H

#include <iostream>
#include "tlist.h"

using namespace std;

template <typename T>
class TRingList : public TList<T> {
private:
	TNode<T>* pHead;
public:
	//TRingList();
	//TRingList(const TNode<T>* _pFirst, const TNode<T>* _pHead = nullptr);
	//TRingList(const TRingList<T>& obj);
	//TRingList(const TList<T>& obj, const TNode<T>* _pHead = nullptr);
};



#endif // !TRINGLIST_H
