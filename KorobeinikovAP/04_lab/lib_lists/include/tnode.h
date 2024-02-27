#ifndef __NODE_H__
#define __NODE_H__

#include "tdata.h"

template <typename T>
class TNode {
private:
	TData data;
	TNode* pNext;
};




/*
class TNode {
private:
	TData data;
	TNode* pNext;  
};
*/

#endif // !__NODE_H__
