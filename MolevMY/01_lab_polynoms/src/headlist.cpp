#include <headlist.h>

TNode* THeadList::GetEmpty()
{
	return pHead;
}

THeadList::THeadList()
{
	pHead = new TNode(nullptr);
	pHead->pNext = pHead;
	this->pCurr = this->pPrev = this->pNext = this->pFirst = this->pStop = pHead;
}
THeadList::~THeadList()
{
	TList::~TList();
	delete pHead;
}