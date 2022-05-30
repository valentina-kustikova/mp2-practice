#pragma once;
template <typename T>
class TNode {
public:
	T data;
	TNode<T>* pNext;
	TNode() {
		pNext = nullptr;
	};
	~TNode() {};
	TNode(const T _data, TNode<T>* Node = nullptr) { data = _data; pNext = Node; }
	TNode<T>& operator=(const TNode<T>& _TNode)
	{
		data = _TNode.data;
		pNext = _TNode.pNext;
		return *this;
	};
	bool operator==(const TNode<T>& Node) const
	{
		return *this->pNext == Node.pNext;
	};
	bool operator!=(const TNode<T>& Node) const
	{
		return !(*this == Node);
	};
};