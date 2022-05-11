#pragma once
#include <stack>
#include <iostream>
#include <string>

struct Trunk
{
	Trunk* prev;
	std::string str;

	Trunk(Trunk* prev, std::string str)
	{
		this->prev = prev;
		this->str = str;
	}
};

// Helper function to print branches of the binary tree
void showTrunks(Trunk* p)
{
	if (p != nullptr)
	{
		showTrunks(p->prev);
		std::cout << p->str;
	}
}

template <class TKey, class TData>
struct TreeNode
{
	TKey key;
	TData* data;
	TreeNode* left;
	TreeNode* right;
	TreeNode* parent;

	TreeNode(TKey _key = {}, TData* _data = nullptr, TreeNode* p = nullptr, TreeNode* l = nullptr, TreeNode* r = nullptr)
		:key(_key), data(_data), parent(p), left(l), right(r) {}
	TreeNode(TKey _key, TData _data, TreeNode* p = nullptr, TreeNode* l = nullptr, TreeNode* r = nullptr)
		:key(_key), data(new TData(_data)), parent(p), left(l), right(r) {}
	~TreeNode()
	{
		delete data;
	}
	TreeNode(const TreeNode& tn)
		:key(tn.key), data(new TData(*(tn.data))), left(nullptr), right(nullptr), parent(nullptr) {}
};

template <class TKey, class TData>
class BSTree
{
protected:
	TreeNode<TKey, TData>* root;

	TreeNode<TKey, TData>* FindRec(const TKey& key)
	{
		TreeNode<TKey, TData>* node = root;
		while (node != nullptr && node->key != key)
		{
			if (key < node->key)
				node = node->left;
			else
				node = node->right;
		}
		return node;
	}
	TreeNode<TKey, TData>* FindMin(TreeNode<TKey, TData>* _node)
	{
		TreeNode<TKey, TData>* node = _node;
		while (node->left != nullptr)
		{
			node = node->left;
		}
		return node;
	}
	TreeNode<TKey, TData>* FindMax(TreeNode<TKey, TData>* _node)
	{
		TreeNode<TKey, TData>* node = _node;
		while (node->right != nullptr)
		{
			node = node->right;
		}
		//curr = &node;
		return node;
	}
	TreeNode<TKey, TData>* FindPrev(TreeNode<TKey, TData>* _node)
	{
		if (_node->left != nullptr)
			return FindMax(_node->left);

		TreeNode<TKey, TData>* res = _node->parent;
		TreeNode<TKey, TData>* tmp = _node;
		while (res != nullptr && tmp == res->left)
		{
			tmp = res;
			res = res->parent;
		}
		return res;
	}
	TreeNode<TKey, TData>* FindNext(TreeNode<TKey, TData>* _node)
	{
		if (_node->right != nullptr)
			return FindMin(_node->right);

		TreeNode<TKey, TData>* res = _node->parent;
		TreeNode<TKey, TData>* tmp = _node;
		while (res != nullptr && tmp == res->right)
		{
			tmp = res;
			res = res->parent;
		}
		return res;
	}
	void printTree(TreeNode<TKey, TData>* node, Trunk* prev, bool isLeft)
	{
		if (node != nullptr)
		{
			std::string prev_str = "    ";
			Trunk* trunk = new Trunk(prev, prev_str);

			printTree(node->right, trunk, true);

			if (!prev)
			{
				trunk->str = "---";
			}
			else if (isLeft)
			{
				trunk->str = ".---";
				prev_str = "   |";
			}
			else
			{
				trunk->str = "`---";
				prev->str = prev_str;
			}

			showTrunks(trunk);
			std::cout << *node << std::endl;

			if (prev)
			{
				prev->str = prev_str;
			}
			trunk->str = "   |";

			printTree(node->left, trunk, false);
		}
	}
public:
	BSTree()
		:root(nullptr) {}
	BSTree(const BSTree& tr)
	{
		if (!tr.isEmpty())
		{
			TreeNode<TKey, TData>** cur = &root;
			TreeNode<TKey, TData>* prev = nullptr;
			TreeNode<TKey, TData>* node = tr.root;
			std::stack< TreeNode<TKey, TData>** > st1;
			std::stack< TreeNode<TKey, TData>* > st2;
			st1.push(cur);
			st2.push(node);
			while (!st2.empty())
			{
				node = st2.top(); st2.pop();
				cur = st1.top(); st1.pop();
				*cur = new TreeNode<TKey, TData>*(*node);

				if (node->parent != nullptr)
				{
					(*cur)->parent = FindRec(node->parent->key);
				}

				if (node->right != nullptr)
				{
					st2.push(node->right);
					st1.push(&((*cur)->right));
				}
				if (node->left != nullptr)
				{
					st2.push(node->left);
					st1.push(&((*cur)->left));
				}
			}
		}
	}
	~BSTree()
	{
		Clear();
	}
	TData* Find(const TKey& key)
	{
		TreeNode<TKey, TData>* tmp = FindRec(key);
		if (tmp != nullptr)
			return tmp->data;
		else
			return nullptr;
	}
	virtual bool Insert(const TKey& key, const TData& data)
	{
		TreeNode<TKey, TData>** node = &root;
		TreeNode<TKey, TData>* prev = nullptr;
		while (*node)
		{
			prev = *node;
			TreeNode<TKey, TData>& tmp = **node;
			if (key == tmp.key)
				return false;
			else if (key < tmp.key)
				node = &tmp.left;
			else
				node = &tmp.right;
		}
		*node = new TreeNode<TKey, TData>(key, data, prev);
		return true;
	}
	virtual bool Delete(const TKey& key)
	{
		TreeNode<TKey, TData>* z = FindRec(key);
		if (z != nullptr)
		{
			TreeNode<TKey, TData>* y = (z->left != nullptr && z->right != nullptr) ? FindNext(z) : z;
			TreeNode<TKey, TData>* x = (y->left != nullptr) ? y->left : y->right;
			if (x != nullptr)
				x->parent = y->parent;
			if (y->parent != nullptr)
			{
				if (y == y->parent->left)
					y->parent->left = x;
				else
					y->parent->right = x;
			}
			else
				root = x;

			if (y != z)
			{
				z->key = y->key;
				delete z->data;
				z->data = y->data;
				y->data = nullptr;
			}
			delete y;
			return true;
		}
		else
			return false;
	}
	bool isEmpty()
	{
		return root == nullptr;
	}
	void Clear()
	{
		if (!isEmpty())
		{
			TreeNode<TKey, TData>* node = root;
			std::stack< TreeNode<TKey, TData>* > st1, st2;
			st1.push(node);
			while (!st1.empty())
			{
				node = st1.top();
				st1.pop();
				if (node->left != nullptr)
					st1.push(node->left);
				if (node->right != nullptr)
					st1.push(node->right);
				st2.push(node);
			}
			while (!st2.empty())
			{
				node = st2.top();
				st2.pop();
				delete node;
			}
			root = nullptr;
		}
	}

	void Print()
	{
		printTree(root, nullptr, false);
	}
};