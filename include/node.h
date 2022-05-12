#pragma once
//#include <cstddef>


template<class T>

class Node
{
public:
	T data;//������ �������� 
	Node<T>* next;//��������� �� ���������

	Node(); //����������� �� ���������
	Node(T d, Node<T>* _next = nullptr); //����������� � �����������
	Node(const Node<T>& node);// ����������� �����������
	~Node() {};//����������


	bool operator< (const Node& node)const; //<
	bool operator> (const Node& node)const; //>
	bool operator==(const Node<T>& node2) const;// ==
	bool operator!=(const Node<T>& node2) const;  // !=
};

template<class T>
Node<T>::Node()
{
	next = nullptr;
}

template<class T>
Node<T>::Node(T d, Node<T>* _next)
{
	data = d;
	next = _next;
}

template<class T>
Node<T>::Node(const Node<T>& node)
{
	data = node.data;
	next = node.next;
}

template<class T>
bool Node<T>::operator<(const Node& node) const
{
	return (data < node.data);
}

template<class T>
bool Node<T>::operator>(const Node& node) const
{
	return (data > node.data);
}

template <class T>
bool Node<T>::operator==(const Node<T>& node2) const
{
	return (data == node2.data) && (next == node2.next);
}

template <class T>
bool Node<T>::operator!=(const Node<T>& node) const
{
	return !(*this == node);
}