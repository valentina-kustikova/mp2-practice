#ifndef _TNODE_
#define _TNODE_
#include "tdata.h"

struct TNode
{
	TData data;
	TNode* pNext;
};

#endif