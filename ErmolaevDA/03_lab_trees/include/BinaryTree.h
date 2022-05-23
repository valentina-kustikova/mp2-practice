#pragma once 
#include <iostream>
#include <stack>
#include "Table.h"
using namespace std;

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


// Класс Звено дерева
template <typename TData, typename TKey>
class TreeNode : public TabRecord<TData, TKey>
{ public:
  TreeNode* Left;
  TreeNode* Right;
  TreeNode* Parent;
  // Конструкторы, деструктор	

  TreeNode(TKey k = {}, TData d = {}, TreeNode* P = nullptr, TreeNode* R = nullptr, TreeNode* L = nullptr):
		TabRecord<TData, TKey>(k, d), Left(L), Right(R), Parent(P) {}
  TreeNode(const TreeNode& T1):TabRecord<TData,TKey>(T1.GetGetKey()(),T1.pData),Left(nullptr),Right(nullptr),Parent(nullptr) {}
  ~TreeNode();

};

// Класс Бинарное поисковое дерево
template <typename TData, typename TKey>
class BinaryTree
{
//protected:
public:
int size = 0;
TreeNode<TData, TKey>* Root;
TreeNode<TData, TKey>* Cur;
//public:

	// Конструкторы, деструктор	
	BinaryTree() {Root = nullptr;}
	BinaryTree(TKey k, TData d) { Root = new TreeNode<TData, TKey>(k, d); size += 1; }
	~BinaryTree();

	//Методы
	TreeNode<TData, TKey>* Find(TKey k) const;
	TreeNode<TData, TKey>* FindMax(TreeNode<TData, TKey>* node) const;
	TreeNode<TData, TKey>* FindMin(TreeNode<TData, TKey>* node) const;
	TreeNode<TData, TKey>* FindNext(TreeNode<TData, TKey>* node) const;
	TreeNode<TData, TKey>* FindPrev(TreeNode<TData, TKey>* node) const;

	//виртуальные
	virtual void Insert(TKey k, TData d); 
	virtual void Delete(TKey k);

	//Навигация
	void Reset() { if (Root != nullptr) { Cur = FindMin(Root); } }
	void SetNext() { if (Root != nullptr) { Cur = FindNext(Cur); } }
	bool IsEnd() const { return Cur->GetKey() == FindMax(Root)->GetKey(); }
	TData* GetData() const { if (Cur != nullptr) { return Cur->GetData(); } return nullptr; }
	TKey GetKey() const { if (Cur != nullptr) { return Cur->GetKey(); } return 0; }
	TreeNode<TData, TKey>* GetCur() const { return Cur; }
	bool isEmpty() const
	{
		return Root == nullptr;
	}

	void Clear()
	{
		if (!isEmpty())
		{
			TreeNode<TData,TKey>* node = Root;
			std::stack< TreeNode<TData,TKey>* > st1, st2;
			st1.push(node);
			while (!st1.empty())
			{
				node = st1.top();
				st1.pop();
				if (node->Left != nullptr)
					st1.push(node->Left);
				if (node->Right != nullptr)
					st1.push(node->Right);
				st2.push(node);
			}
			while (!st2.empty())
			{
				node = st2.top();
				st2.pop();
				delete node;
			}
			Root = nullptr;
		}
	}

	void printTree(TreeNode<TData, TKey>* node, Trunk* prev, bool isLeft)
	{
		if (node != nullptr)
		{
			std::string prev_str = "    ";
			Trunk* trunk = new Trunk(prev, prev_str);
			printTree((TreeNode<TData, TKey>*)(node->Right), trunk, true);
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
			std::cout << node->GetKey() << "[" << *(node->GetData()) << "]" << std::endl;
			if (prev)
			{
				prev->str = prev_str;
			}
			trunk->str = "   |";
			printTree((TreeNode<TData, TKey>*)(node->Left), trunk, false);
		}
	}

    //Перегрузка операций
    //template<class TData>
  friend std::ostream& operator<< (std::ostream& os, const BinaryTree<TData, TKey>& T1)
  { 
	stack<TreeNode<TData, TKey>*> S1;
	TreeNode<TData, TKey>* n = T1.Root;
	while (!(S1.size()==0 && n == nullptr))
	{
		if (n != nullptr) 
		{
			S1.push(n);
			n = n->Left;
		}
		else
		{
			n = S1.top();
			S1.pop();
			os << "Key:" << left << n->GetKey() << " | Data: " << *(n->GetData()) << '\n';
			n = n->Right;
		}
	}
	return os;
  }
  BinaryTree<TData, TKey>& operator=(const BinaryTree<TData, TKey>& T1)
  {
	  Root = nullptr;
	  TreeNode<TData, TKey>* p1;
	  if (T1.Root != nullptr)
	  {
		  p1 = T1.FindMin();
		  Insert(p1->GetKey(), *(p1->GetData()));
	  	  p1 = T1.FindNext(p1);
	      if(p1!=nullptr)
		  { 
			 Insert(p1->GetKey(), *(p1->GetData()));
		     p1 = T1.A1->FindNext(p1);
          }
	  }
	  return *this;
  }
  bool operator== (const BinaryTree<TData, TKey>& N)  const
  {
	  TreeNode<TData, TKey>* C;
	  TreeNode<TData, TKey>* CN;
	  if (N.Root != nullptr) 
	  { 
		CN = N.FindMin(N.Root); 
	    if (Root != nullptr) 
	    { 
			C = FindMin(Root);
			while (C->GetKey() != FindMax(Root)->GetKey() && CN->GetKey() != FindMax(N.Root)->GetKey())
			{
				if (CN->GetKey() != C->GetKey()) { return 0; }
				CN = FindNext(CN); C = FindNext(C);
			}
			if (CN->GetKey() != C->GetKey()) { return 0; }
			else { return 1; }
		} 
	  } 
	  return 0;
  }
};

// Pелизация функциий для класса звено дерева
template <typename TData, typename TKey>
TreeNode<TData, TKey>::~TreeNode()
{

}

//Pелизация функциий для класса бинарное поисковое дерево
// Конструкторы, деструктор	
template <typename TData, typename TKey>
BinaryTree<TData, TKey>::~BinaryTree()
{ 
 
}


//Методы
template <typename TData, typename TKey>
TreeNode<TData, TKey>* BinaryTree<TData, TKey>::Find(TKey k)  const
{ 
	
  TreeNode<TData, TKey>* tmp = Root;
  while ((tmp != nullptr) && (tmp->GetKey() != k))
  { 
      if (k < tmp->GetKey())
      {
      tmp = tmp->Left;
      }
      else
      { 
      tmp = tmp->Right;
      }
  }
  return tmp;
}

template <typename TData, typename TKey>
TreeNode<TData, TKey>* BinaryTree<TData, TKey>::FindMin(TreeNode<TData, TKey>* node) const
{
	TreeNode<TData, TKey>* tmp = node;
	while (tmp->Left != nullptr)
	{
		tmp = tmp->Left;
	}
	return tmp;
}

template <typename TData, typename TKey>
TreeNode<TData, TKey>* BinaryTree<TData, TKey>::FindMax(TreeNode<TData, TKey>* node)  const
{
  TreeNode<TData, TKey>* tmp = node;
  while (tmp->Right != nullptr)
  {
  tmp = tmp->Right;
  }
  return tmp;
}

template <typename TData, typename TKey>
TreeNode<TData, TKey>* BinaryTree<TData, TKey>::FindPrev(TreeNode<TData, TKey>* node) const
{

	TreeNode<TData, TKey>* res = nullptr;
	if (node->Left != nullptr)		 // максимальный в левом поддереве
	{
		return FindMax(node->Left);
	}
	res = node->Parent;

	TreeNode<TData, TKey>* tmp = node;	  //родитель с правым потомком
	while ((res != nullptr) && (tmp == res->Left))
	{
		tmp = res;
		res = res->Parent;
	}
	return res;
}

template <typename TData, typename TKey>
TreeNode<TData, TKey>* BinaryTree<TData, TKey>::FindNext(TreeNode<TData, TKey>* node) const
{ 
  TreeNode<TData, TKey>* res = nullptr;
  if (node->Right != nullptr)		 // минимальный в правом поддереве
  { 
	return FindMin(node->Right);
  }
  res = node->Parent;

  TreeNode<TData, TKey>* tmp = node;//родитель с левым потомком 
  while ((res != nullptr) && (tmp == res->Right))
  { tmp = res;
	res = res->Parent;
  }
  return res;
}


template <typename TData, typename TKey>
void BinaryTree<TData, TKey>::Insert(TKey k, TData d)
{ 
	try {

		if (Find(k) != nullptr)
		{
			throw "Re-inserting an element,cannot complete Insert BinaryTree";
		}	 


		if (Root == nullptr)				 //вставка корня
		{
			Root = new TreeNode<TData, TKey>(k, d);
			size += 1;
			return;
		}
		TreeNode<TData, TKey>* x = Root, * y;
		while (x != nullptr)
		{
			y = x;
			if (k < x->GetKey()) { x = x->Left; }
			else { x = x->Right; }
		}
		if (k < y->GetKey())
		{
			y->Left = new TreeNode<TData, TKey>(k, d, y);
			size += 1;
		}
		else
		{
			y->Right = new TreeNode<TData, TKey>(k, d, y);
			size += 1;
		}
		
	}
	catch (const char* exception) {
		std::cerr << "Error: " << exception << '\n';
	}
}

template <typename TData, typename TKey>
void BinaryTree<TData, TKey>::Delete(TKey k)
{ 
	TreeNode<TData,TKey>* z = Find(k);
	if (z != nullptr)
	{
		TreeNode<TData,TKey>* y = (z->Left != nullptr && z->Right != nullptr) ? FindNext(z) : z;
		TreeNode<TData,TKey>* x = (y->Left != nullptr) ? y->Left : y->Right;
		if (x != nullptr)
			x->Parent = y->Parent;
		if (y->Parent != nullptr)
		{
			if (y == y->Parent->Left)
				y->Parent->Left = x;
			else
				y->Parent->Right = x;
		}
		else
			Root = x;

		if (y != z)
		{
			TreeNode<TData, TKey>* tmp = z;
			z->key = y->key;
			delete z->data;
			z->data = y->data;
			y->data = nullptr;
		}
		delete y;
		return;
	}
	else
		return;
}

