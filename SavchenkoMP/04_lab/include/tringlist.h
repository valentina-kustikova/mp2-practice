#ifndef TRINGLIST_H
#define TRINGLIST_H

#include <iostream>
#include "tlist.h"
#include "tdata.h"

using namespace std;

template <typename T>
class TRingList : public TList<T> {
private:
	TNode<T>* pHead;
public:

};

#endif // !TRINGLIST_H
