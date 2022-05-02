#pragma once 
#include <iostream>
#include <stack>
#include "Table.h"
using namespace std;

// Класс Звено дерева
template <typename TData, typename TKey>
class TrNode : public TabRecord<TData, TKey>
{ public:
  TrNode* Left;
  TrNode* Right;
  TrNode* Parent;
  // Конструкторы, деструктор	
  TrNode(TKey k = {}, TData d = {}, TrNode* P = nullptr, TrNode* R = nullptr, TrNode* L = nullptr):
		TabRecord<TData, TKey>(k, d), Left(L), Right(R), Parent(P) {}
  TrNode(const TrNode& T1):
		TabRecord<TData,TKey>(T1.key,T1.pData),Left(nullptr),Right(nullptr),Parent(nullptr) {}
  ~TrNode();
  //Методы
  TrNode* GetLeft() const { return Left};
  TrNode* GetRight() const { return Right};
  TrNode* GetParent()  const { return Parent};
  // Перегрузка операций
  TrNode<TData, TKey>& operator=(const TrNode<TData, TKey>& T1)
	{
		data = new TData(*(T1.data)); 
		key = T1.key
		Left = T1.Left;
		Right = T1.Right;
		Parent = T1.Parent;
		return *this;
	}
};

// Класс Бинарное поисковое дерево
template <typename TData, typename TKey>
class BSTree
{ protected:
  TrNode<TData, TKey>* Root;
  public:
  // Конструкторы, деструктор	
  BSTree(){Root = nullptr;}
  BSTree(TKey k, TData d) { Root = new TrNode<TData, TKey>(k, d); }
  ~BSTree();
  //Методы
  void Insert(TKey k, TData d);
  void Delete(TKey k);
  TrNode<TData, TKey>* Find(TKey k) const;
  TrNode<TData, TKey>* FindMax(TrNode<TData, TKey>* node) const;
  TrNode<TData, TKey>* FindMin(TrNode<TData, TKey>* node) const;
  TrNode<TData, TKey>* FindNext(TrNode<TData, TKey>* node) const;
  TrNode<TData, TKey>* FindPrev(TrNode<TData, TKey>* node) const;
  // Перегрузка операций
  template<class TData> friend std::ostream& operator<< (std::ostream& os, const BSTree<TData, TKey>& T1)
  { stack<TrNode<TData, TKey>*> S1;
	TrNode<TData, TKey>* n = T1.Root;
	while (!(S1.size()==0 && n == nullptr))
	{ if (n != nullptr) 
	  { S1.push(n);
		n = n->Left;
	  }
      else
	  {	n = S1.top();
		S1.pop();
		os<< n->GetKey()<<" ";
		n = n->Right;
	  }
	}
	return os;
  }
};

// Pелизация функциий для класса звено дерева
template <typename TData, typename TKey>
TrNode<TData, TKey>::~TrNode()
{
	if (Left)
		delete Left;
	if (Right)
		delete Right;
	if (Parent)
		delete Parent;
}

//Pелизация функциий для класса бинарное поисковое дерево
// Конструкторы, деструктор	
template <typename TData, typename TKey>
BSTree<TData, TKey>::~BSTree()
{ stack<TrNode<TData, TKey>*> S1;
  TrNode<TData, TKey>* n = Root;
  while (S1.size() != 0 || n != nullptr) 
  { if (n != nullptr) 
    { S1.push(n);
	  n = n->Left;
	}
    else
    { n = S1.top();
	  S1.pop();
	  Delete(n->GetKey());
	  n = n->Right;
	}
  }
  }
//Методы
template <typename TData, typename TKey>
TrNode<TData, TKey>* BSTree<TData, TKey>::Find(const TKey k)  const
{ TrNode<TData, TKey>* tmp = Root;
  while ((tmp != nullptr) && (tmp->GetKey() != k))
  { if (k < tmp->GetKey())
    { tmp = tmp->Left;}
	else
    { tmp = tmp->Right;}
  }
  return tmp;
}
template <typename TData, typename TKey>
TrNode<TData, TKey>* BSTree<TData, TKey>::FindMax(TrNode<TData, TKey>* node)  const
{ TrNode<TData, TKey>* tmp = node;
  while (tmp->Right != nullptr)
  { tmp = tmp->Right;}
  return tmp;
}
template <typename TData, typename TKey>
TrNode<TData, TKey>* BSTree<TData, TKey>::FindMin(TrNode<TData, TKey>* node) const
{ TrNode<TData, TKey>* tmp = node;
  while (tmp->Left != nullptr)
  { tmp = tmp->Left;}
  return tmp;
}
template <typename TData, typename TKey>
TrNode<TData, TKey>* BSTree<TData, TKey>::FindNext(TrNode<TData, TKey>* node) const
{ TrNode<TData, TKey>* res = nullptr;
  if (node->Right != nullptr)
  { res = FindMin(node->Right);
	return res;
  }
  res = node->Parent;
  TrNode<TData, TKey>* tmp = node; 
  while ((res != nullptr) && (tmp == res->Right))
  { tmp = res;
	res = res->Parent;
  }
  return res;
}
template <typename TData, typename TKey>
TrNode<TData, TKey>* BSTree<TData, TKey>::FindPrev(TrNode<TData, TKey>* node) const
{ TrNode<TData, TKey>* res = nullptr;
  if (node->Left != nullptr)
  { res = FindMax(node->Left);
	return res;
  }
  res = node->Parent;
  TrNode<TData, TKey>* tmp = node;
  while ((res != nullptr) && (tmp == res->Left))
  { tmp = res;
	res = res->Parent;
  }
  return res;
}
template <typename TData, typename TKey>
void BSTree<TData, TKey>::Insert(TKey k, TData d)
{ if(Find(k)!=nullptr)
  {throw 1;}
  if (Root == nullptr)
  { Root = new TrNode<TData, TKey> (k, d);
	return;
  }
  TrNode<TData, TKey>* x = Root, * y;
  while (x != nullptr)
  {	y = x;
	if (k < x->GetKey())
	{ x = x->Left;}
	else
	{ x = x->Right;}
  }
  if (k < y->GetKey())
  { y->Left = new TrNode<TData, TKey>(k, d, y);}
  else
  { y->Right = new TrNode<TData, TKey>(k, d, y);}
}
template <typename TData, typename TKey>
void BSTree<TData, TKey>::Delete(TKey k)
{ TrNode<TData, TKey>* z = Find(k);
  if(Find(k)==nullptr)
  {throw 1;}
  TrNode<TData, TKey>* y = nullptr, * x = nullptr;
  if ((z->Left!=nullptr) && (z->Right!=nullptr))
  { y = FindNext(z);  }
  else 
  { y = z; }
  if (y->Left != nullptr) 
  { x = y->Left; }
  else
  { x = y->Right;}
  if (x!=nullptr)
  { x->Parent = y->Parent; if (x->Parent == nullptr) { Root = x;} 
  }
  if (y->Parent!=nullptr)
  { if (y == y->Parent->Left)
	{ y->Parent->Left = x; }
	else
    { y->Parent->Right = x;}
  }
  if (y != z)
  { z->SetKey(y->GetKey());
	z->SetData( y->GetData());
  }
}
