#ifndef __NODE_H__
#define __NODE_H__



#include <iostream>



template <typename T>
class TNode {
private:
	T data;
	TNode* pNext;
public:
	TNode(const T& data_, TNode* pNext_ = nullptr);
	TNode(const TNode<T>& obj);
};

#endif // !__NODE_H__