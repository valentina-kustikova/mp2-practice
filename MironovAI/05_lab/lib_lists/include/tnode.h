#ifndef _TNODE_H_
#define _TNODE_H_


template <class Type>
struct TNode
{
	Type value;
	TNode<Type>* next;

	TNode(const Type& value = Type());


	bool operator<(const TNode<Type>& node) const;
	bool operator>(const TNode<Type>& node) const;
	bool operator==(const TNode<Type>& node) const;
	bool operator!=(const TNode<Type>& node) const;

};

template <class Type>
TNode<Type>::TNode(const Type& new_value) : value(new_value), next(nullptr) {}



template <class Type>
bool TNode<Type>::operator<(const TNode<Type>& node) const
{
	return this->value < node.value;
}


template <class Type>
bool TNode<Type>::operator>(const TNode<Type>& node) const
{
	return this->value > node.value;;
}


template <class Type>
bool TNode<Type>::operator==(const TNode<Type>& node) const
{
	return this->value == node.value;;
}


template <class Type>
bool TNode<Type>::operator!=(const TNode<Type>& node) const
{
	return this->value != node.value;;
}


#endif // !_TNODE_H_
