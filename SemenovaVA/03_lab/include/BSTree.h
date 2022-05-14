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
 // TrNode* GetLeft() const { return Left; }
 // TrNode* GetRight() const { return Right; }
 // TrNode* Parent  const { return Parent; }
};

// Класс Бинарное поисковое дерево
template <typename TData, typename TKey>
class BSTree
{
protected:
	TrNode<TData, TKey>* Root;
	TrNode<TData, TKey>* Cur;
public:
	// Конструкторы, деструктор	
	BSTree() { Root = nullptr; Cur = nullptr;}
	BSTree(TKey k, TData d) { Root = new TrNode<TData, TKey>(k, d); }
	~BSTree();
	//Методы
	TrNode<TData, TKey>* Find(TKey k) const;
	TrNode<TData, TKey>* FindMax(TrNode<TData, TKey>* node) const;
	TrNode<TData, TKey>* FindMin(TrNode<TData, TKey>* node) const;
	TrNode<TData, TKey>* FindNext(TrNode<TData, TKey>* node) const;
	TrNode<TData, TKey>* FindPrev(TrNode<TData, TKey>* node) const;
	virtual void Insert(TKey k, TData d); //виртуальные
	virtual void Delete(TKey k);
	//Навигация
	void Reset() { if (Root != nullptr) { Cur = FindMin(Root); }}
	void SetNext() { if (Root != nullptr){ Cur = FindNext(Cur); }}
    bool IsEnd() const { return Cur->GetKey() == FindMax(Root)->GetKey(); }
	TData* GetData() const { if (Cur != nullptr) { return Cur->GetData(); } return nullptr; }
	TKey GetKey() const { if (Cur != nullptr) { return Cur->GetKey(); } return 0; }
	TrNode<TData, TKey>* GetCur() const { return Cur; }
  //Перегрузка операций
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
		os << "\t" << left << setw(15) << n->GetKey() << " | " << *(n->GetData()) << '\n';
		n = n->Right;
	  }
	}
	return os;
  }
  BSTree<TData, TKey>& operator=(const BSTree<TData, TKey>& T1)
  {
	  Root = nullptr;
	  TrNode<TData, TKey>* p1;
	  if (T1.Root != nullptr)
	  {
		  p1 = T1.FindMin();
		  Insert(p1->GetKey(), *(p1->GetData()));
	  	  p1 = T1.FindNext(p1);
	      if(p1!=nullptr)
		  { Insert(p1->GetKey(), *(p1->GetData()));
		     p1 = T1.A1->FindNext(p1);
          }
	  }
	  return *this;
  }
  bool operator== (const BSTree<TData, TKey>& N)  const
  {
	  TrNode<TData, TKey>* C;
	  TrNode<TData, TKey>* CN;
	  if (N.Root != nullptr) { CN = N.FindMin(N.Root); 
	  if (Root != nullptr) 
	  { C = FindMin(Root);
		while (C->GetKey() != FindMax(Root)->GetKey() && CN->GetKey() != FindMax(N.Root)->GetKey())
		{ if (CN->GetKey() != C->GetKey()) { return 0; }
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
  if (node->Right != nullptr)		 // минимальный в правом поддереве
  { res = FindMin(node->Right);
	return res;
  }
  res = node->Parent;
  TrNode<TData, TKey>* tmp = node;	 //родитель с левым потомком 
  while ((res != nullptr) && (tmp == res->Right))
  { tmp = res;
	res = res->Parent;
  }
  return res;
}
template <typename TData, typename TKey>
TrNode<TData, TKey>* BSTree<TData, TKey>::FindPrev(TrNode<TData, TKey>* node) const
{ TrNode<TData, TKey>* res = nullptr;
  if (node->Left != nullptr)		 // максимальный в левом поддереве
  { res = FindMax(node->Left);
	return res;
  }
  res = node->Parent;
  TrNode<TData, TKey>* tmp = node;	  //родитель с правым потомком
  while ((res != nullptr) && (tmp == res->Left))
  { tmp = res;
	res = res->Parent;
  }
  return res;
}
template <typename TData, typename TKey>
void BSTree<TData, TKey>::Insert(TKey k, TData d)
{ 
	if(Find(k)!=nullptr) {throw 1;}	 //повторная вставка элемента 


  if (Root == nullptr)				 //вставка корня
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


  if(Find(k)==nullptr){throw 1;} // удаление не существующего элемента 


  TrNode<TData, TKey>* y = nullptr, * x = nullptr;
  if ((z->Left!=nullptr) && (z->Right!=nullptr)) // y - звено для обмена
  { y = FindNext(z);  } 
  else 
  { y = z; }
  if (y->Left != nullptr) // x - потомок
  { x = y->Left; }
  else
  { x = y->Right;}
  if (x!=nullptr) // меняем указатель родителя у потомка
  { x->Parent = y->Parent; }
  if (y->Parent!=nullptr) //1,3 случай
  { if (y == y->Parent->Left)
	{ y->Parent->Left = x; }
	else
    { y->Parent->Right = x;}
  }
  if (y != z) //2 случай
  { z->SetKey(y->GetKey());
	z->SetData( y->GetData());
  }
  //удаление корня, если это единственный узел
  if(z==Root && z->Left==nullptr && z->Right==nullptr)
  {Root=nullptr; }
  
}

