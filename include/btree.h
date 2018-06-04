#pragma once
#include "Node.h"
using namespace std;



template <typename T>
class btree
{
public:
	int size; 
	Node<T> *root;
	btree();
	~btree();
	btree(const btree<T> &);

	Node<T>* CopyTree(Node<T> *);
	void insert(Node<T>*, const Node<T> *); 
	void remove(Node<T>*, const T &); 

	Node<T>* Findkey(Node<T>*, const T &); 
	Node<T>* FindMax(Node<T>*); 
	Node<T>* FindMin(Node<T>*); 
	int getsize();
	
};

template <typename T>
btree<T>::btree()
{
	root = nullptr;
};

template <typename T>
btree<T>::btree(const btree<T> &a)
{
	root = CopyTree(a.root);
};

template <typename T>
btree<T>::~btree()
{
	delete root;
};

template <typename T>
Node<T>* btree<T>::CopyTree(Node<T>*croot)
{
	if (croot == nullptr)
		return nullptr;

	Node<T>* l = CopyTree(croot->left);
	Node<T>* r = CopyTree(croot->right);
	Node<T>* tree = new Node<T>;
	tree->key = croot->key;
	tree->left = l;
	tree->right = r;
	root = tree;
	return tree;
};

template <typename T>
int btree<T>::getSize()
{
	return size;
}

template <typename T>
void btree<T>::insert(Node<T>* tree, const Node<T> *node)
{
	T a = node->key;
	if (tree == nullptr)
	{
		tree = new Node<T>;
		tree->key = a;
		size++;
		return;
	}
	Node<T>* tmp = tree;
	Node<T>* prev = new Node<T>;
	while (tmp != nullptr)
	{
		prev = tmp;
		if (tmp->key <= a)
			tmp = tmp->right;
		else
			tmp = tmp->left;
	}
	if (prev->key <= a)
		prev->right = new Node<T>(a);
	else prev->left = new Node<T>(a);
	size++;
};

template <typename T>
void btree<T>::remove(Node<T>* tree, const T &k)
{
	Node<T>* x = Findkey(tree, k);
	if (x == nullptr)
		return;

	if ((x->left == nullptr) && (x->right == nullptr))
	{
		delete x;
		return;
	};
	if ((x->left == nullptr) && (x->right != nullptr))
	{
		Node<T>* y = x->right;
		y->parent = x->parent;
		if (x->parent == nullptr)
		{
			tree = y;
			return;
		}
		if (x->parent->right == x)
			x->parent->right = y;
		else
			x->parent->left = y;
		tree = y;
		return;
	}
	if ((x->left != nullptr) && (x->right == nullptr))
	{
		Node<T>* y = x->left;
		y->parent = x->parent;
		if (x->parent->right == x)
			x->parent->right = y;
		else
			x->parent->left = y;
		delete x;
		return;
	}
	Node<TType>* y = FindMin(x->right);
	x->key = y->key;
	y->parent->left = y->right;
	if (y->right != nullptr)
		y->right->parent = y->parent;
	delete y;
};

template <typename T>
Node<T>* btree<T>::Findkey(Node<T> *tree, const T &k)
{
	while ((tree != nullptr) && (tree->key != k))
	{
		if (k < tree->key)
			tree = tree->left;
		if (k > tree->key)
			tree = tree->right;
	}
	if (tree == nullptr)
		return nullptr;
	return tree;
};

template <typename T>
Node<T>*btree<T>::FindMin(Node<T> *tree)
{
	if (tree == nullptr)
		throw "Tree is empty"
	while (tree->left != nullptr)
		tree = tree->left;
	return tree;
}
template<typename T>
int btree<T>::getsize()
{
	return size;
}
;

template <typename T>
Node<T>* btree<T>::FindMax(Node<T> *tree)
{
	if (tree == nullptr)
		throw "Tree is empty";
	while (tree->right != nullptr)
		tree = tree->right;
	return tree;
};
