#pragma once
#include "BinarySearchTree.h"

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
inline void ShowTrunks(Trunk* p)
{
	if (p != nullptr)
	{
		ShowTrunks(p->prev);
		std::cout << p->str;
	}
}

template <class TKey, class TData>
struct BalanceTreeNode : public TreeNode<TKey, TData>
{
	int balance;

	BalanceTreeNode()
		:TreeNode<TKey, TData>(), balance(0) {}
	BalanceTreeNode(TKey _key, TData _data, int _balance, BalanceTreeNode* p = nullptr, BalanceTreeNode* l = nullptr, BalanceTreeNode* r = nullptr)
		:TreeNode<TKey, TData>(_key, _data, p, l, r), balance(_balance) {}
	BalanceTreeNode(const TreeNode<TKey, TData>& tn)
		:TreeNode<TKey, TData>(tn), balance(0) {}
	BalanceTreeNode(const BalanceTreeNode& btn)
		:TreeNode<TKey, TData>(btn), balance(btn.balance) {}

	BalanceTreeNode*& Left()
	{
		return (BalanceTreeNode*&)this->left;
	}
	BalanceTreeNode*& Right()
	{
		return (BalanceTreeNode*&)this->right;
	}
	BalanceTreeNode*& Parent()
	{
		return (BalanceTreeNode*&)this->parent;
	}
};

template <class TKey, class TData>
class AVLTree : public BSTree<TKey, TData>
{
protected:
	void fix_balance_del(BalanceTreeNode<TKey, TData>* child)
	{
		BalanceTreeNode<TKey, TData>* parent = child->Parent();
		if (child == parent->Left())
			parent->balance += 1;
		else
			parent->balance -= 1;
	}
	void fix_balance_ins(BalanceTreeNode<TKey, TData>* child)
	{
		BalanceTreeNode<TKey, TData>* parent = child->Parent();
		if (child == parent->left)
			parent->balance += -1;
		else if (child == parent->right)
			parent->balance += 1;
	}
	void left_rotate(BalanceTreeNode<TKey, TData>* x)
	{
		BalanceTreeNode<TKey, TData>* y = (BalanceTreeNode<TKey, TData>*)(x->right);
		x->right = y->left;
		if (y->left != nullptr)
			y->left->parent = x;
		y->parent = x->parent;
		if (x->parent == nullptr)
			this->root = y;
		else if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
		y->left = x;
		x->parent = y;
	}
	void right_rotate(BalanceTreeNode<TKey, TData>* x)
	{
		BalanceTreeNode<TKey, TData>* y = (BalanceTreeNode<TKey, TData>*)(x->left);
		x->left = y->right;
		if (y->right != nullptr)
			y->right->parent = x;
		y->parent = x->parent;
		if (x->parent == nullptr)
			this->root = y;
		else if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
		y->right = x;
		x->parent = y;
	}
	BalanceTreeNode<TKey, TData>* balancing(BalanceTreeNode<TKey, TData>* x)
	{
		if (x->balance > 1) //rotate to left
		{
			BalanceTreeNode<TKey, TData>* y = (BalanceTreeNode<TKey, TData>*)(x->right);
			if (y->balance < 0) // big rotate to left
			{
				BalanceTreeNode<TKey, TData>* z = (BalanceTreeNode<TKey, TData>*)(y->left);
				if (z->balance == 1)
				{
					y->balance = 0;
					x->balance = -1;
				}
				else if (z->balance == -1)
				{
					y->balance = 1;
					x->balance = 0;
				}
				else
				{
					y->balance = 0;
					x->balance = 0;
				}
				z->balance = 0;
				right_rotate(y);
				left_rotate(x);
				return z;
			}
			else if (y->balance > 0) // small rotate to left
			{
				left_rotate(x);
				x->balance = 0;
				y->balance = 0;
				return y;
			}
			else // small rotate to left only from delete
			{
				left_rotate(x);
				x->balance = 1;
				y->balance = -1;
				return y;
			}
		}
		else if (x->balance < -1) // rotate to right
		{
			BalanceTreeNode<TKey, TData>* y = (BalanceTreeNode<TKey, TData>*)(x->left);
			if (y->balance > 0) // big rotate to right
			{
				BalanceTreeNode<TKey, TData>* z = (BalanceTreeNode<TKey, TData>*)(y->right);
				if (z->balance == 1)
				{
					x->balance = 0;
					y->balance = -1;
				}
				else if (z->balance == -1)
				{
					x->balance = 1;
					y->balance = 0;
				}
				else
				{
					y->balance = 0;
					x->balance = 0;
				}
				z->balance = 0;
				left_rotate(y);
				right_rotate(x);
				return z;
			}
			else if (y->balance < 0) // small rotate to right
			{
				right_rotate(x);
				x->balance = 0;
				y->balance = 0;
				return y;
			}
			else // small rotate to right only from delete
			{
				right_rotate(x);
				x->balance = -1;
				y->balance = 1;
				return y;
			}
		}
		return x;
	}

	void printTree(BalanceTreeNode<TKey, TData>* node, Trunk* prev, bool isLeft)
	{
		if (node != nullptr)
		{
			std::string prev_str = "    ";
			Trunk* trunk = new Trunk(prev, prev_str);
			printTree((BalanceTreeNode<TKey, TData>*)(node->right), trunk, true);
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
			ShowTrunks(trunk);
			std::cout << node->key << "(" << node->balance << ")" << std::endl;
			if (prev)
			{
				prev->str = prev_str;
			}
			trunk->str = "   |";
			printTree((BalanceTreeNode<TKey, TData>*)(node->left), trunk, false);
		}
	}
public:
	virtual bool Insert(const TKey& key, const TData& data) override
	{
		BalanceTreeNode<TKey, TData>** node = (BalanceTreeNode<TKey, TData>**)(&this->root);
		BalanceTreeNode<TKey, TData>* prev = nullptr;
		while (*node)
		{
			prev = *node;
			BalanceTreeNode<TKey, TData>& tmp = **node;
			if (key == tmp.key)
				return false;
			else if (key < tmp.key)
				node = (BalanceTreeNode<TKey, TData>**)(&tmp.left);
			else
				node = (BalanceTreeNode<TKey, TData>**)(&tmp.right);
		}
		*node = new BalanceTreeNode<TKey, TData>(key, data, 0, prev);

		BalanceTreeNode<TKey, TData>* child = *node;
		while (prev != nullptr)
		{
			fix_balance_ins(child);
			prev = balancing(prev);
			if (prev->balance == 0)
				break;
			child = prev;
			prev = prev->Parent();
		}
		return true;
	}
	virtual bool Delete(const TKey& key) override
	{
		BalanceTreeNode<TKey, TData>* z = (BalanceTreeNode<TKey, TData>*)this->FindRec(key);
		if (z != nullptr)
		{
			BalanceTreeNode<TKey, TData>* y = (z->left != nullptr && z->right != nullptr) ? (BalanceTreeNode<TKey, TData>*)this->FindNext(z) : z;
			BalanceTreeNode<TKey, TData>* x = (y->left != nullptr) ? y->Left() : y->Right();
			if (x != nullptr)
				x->parent = y->parent;
			if (y->parent != nullptr)
			{
				BalanceTreeNode<TKey, TData>* c = y;
				BalanceTreeNode<TKey, TData>* p = c->Parent();
				while (p != nullptr)
				{
					fix_balance_del(c);
					p = balancing(p);
					if (p->balance != 0)
						break;
					c = p;
					p = p->Parent();
				}

				if (y == y->Parent()->Left())
					y->Parent()->Left() = x;
				else
					y->Parent()->Right() = x;
			}
			else
				this->root = x;

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

	void Print()
	{
		printTree((BalanceTreeNode<TKey, TData>*)(this->root), nullptr, false);
	}
};
