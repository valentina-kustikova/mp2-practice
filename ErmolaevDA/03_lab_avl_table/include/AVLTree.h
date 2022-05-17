#pragma once 
#include "BinaryTree.h"
#include <iostream>
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


//класс Звено АВЛ дерева
template <typename TData, typename TKey>
class  BalanceNode : public TreeNode<TData, TKey> 
{ 
public:
  int balance; // индекс балансировки вершины (-1,0,1)
  // Конструкторы
  BalanceNode(TKey k = {}, TData d = {}, TreeNode* P = nullptr, TreeNode* R = nullptr, TreeNode* L = nullptr, int bal = 0): TreeNode<TData, TKey> (k, d, P, L, R), balance(bal) {};
 };

//Класс АВЛ дерево
template <typename TData, typename TKey>
class  AVLTree : public BinaryTree<TData, TKey>
{ 
protected:
  //Методы
  int Insert(BalanceNode<TData,TKey>* & N1, TKey k, TData d);
  int Delete(BalanceNode<TData,TKey>* & N1, TKey k);
  int LBalance(BalanceNode<TData,TKey>* & N1);                        
  int RBalance(BalanceNode<TData,TKey>* & N1);                       
public:
  // Конструкторы
  AVLTree() :BinaryTree<TData, TKey>() {}                                       
  //Методы
  void printTree(BalanceNode<TData, TKey>* node, Trunk* prev, bool isLeft)
  {
      if (node != nullptr)
      {
          std::string prev_str = "    ";
          Trunk* trunk = new Trunk(prev, prev_str);
          printTree((BalanceNode<TData, TKey>*)(node->Right), trunk, true);
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
          printTree((BalanceNode<TData, TKey>*)(node->Left), trunk, false);
      }
  }

  void Insert(TKey k, TData d);   //виртуальные               
  void Delete(TKey k);
  
};

// Pелизация функциий для класса АВЛ дерево
template <typename TData, typename TKey>
void AVLTree<TData, TKey>::Insert(TKey k, TData d) 
{ 
    try {
        if (Find(k) != nullptr) { throw "Re - inserting an element, cannot complete Insert AVLTree"; } //повторная ввставка элемента 
        Insert((BalanceNode<TData, TKey>*&)Root, k, d);
    }
    catch (const char* exception) {
        std::cerr << "Error: " << exception << '\n';
    }
}
template <typename TData, typename TKey>
int AVLTree<TData, TKey>::Insert(BalanceNode<TData,TKey>*& N1, TKey k, TData d) 
{
    if (N1 == nullptr) // Если дерево пусто, заменить его на дерево с одним корневым узлом ((K,V), null, null) и остановиться
    { N1= new BalanceNode<TData, TKey>(k, d);
    return 1; 
    } 
    if (k < N1->GetKey()) // Если K<X, рекурсивно добавить (K,V) в левое поддерево дерева Ти выполнить балансировку
    {
        if (N1->Left == nullptr) 
        {
            N1->Left = new BalanceNode<TData, TKey>(k, d, N1);
            return LBalance(N1);
        }
        if (Insert((BalanceNode<TData,TKey>*&)(N1->Left), k, d) == 1) // после вставки высота левого поддерева увеличилась - балансировка
        { return LBalance(N1);}
    }
    if (k >= N1->GetKey())  // Если K>=X, рекурсивно добавить (K,V) в правое поддереводерева Т и выполнить балансировку
    {
        if (N1->Right == nullptr)  
        { 
            N1->Right = new BalanceNode<TData, TKey>(k, d, N1);
            return RBalance(N1);           
        }
        if (Insert((BalanceNode<TData,TKey>*&)(N1->Right), k, d) == 1) // после вставки высота правого поддерева увеличилась - балансировка
        {
            return RBalance(N1);
        }
    }
} 
template <typename TData, typename TKey>
void AVLTree<TData, TKey>::Delete(TKey k)
{
  try
  {
      if (Find(k) == nullptr)
      {
         throw "Deleting a non-existing element,cannot complete Delete AVLTree";
      }
      Delete((BalanceNode<TData, TKey>*&)Root, k);
  }
  catch (const char* exception) {
      std::cerr << "Error: " << exception << '\n';
  }
}
template <typename TData, typename TKey>
int AVLTree<TData, TKey>::Delete(BalanceNode<TData,TKey>*& N1, TKey k)
{ 
    if (k < N1->GetKey())
    {
        if (Delete((BalanceNode<TData,TKey>*&)N1->Left, k) == 0)
            return RBalance(N1);
    }
    else
    {
        if (k > N1->GetKey())
        {
        if (Delete((BalanceNode<TData,TKey>*&)N1->Right, k) == 0)
            return LBalance(N1);
        }
        else
        {
        int h=0;
        BalanceNode<TData,TKey>* p1 = (BalanceNode<TData,TKey>*)FindNext(N1);
        if(N1->Right!=nullptr && N1->Left != nullptr)
        {
            h= LBalance(p1);
        }
        BinaryTree::Delete(N1->GetKey());
        return h; 
        }
    }
}
template <typename TData, typename TKey>
int AVLTree<TData, TKey>::LBalance(BalanceNode<TData,TKey>*& N1) 
{
    switch (N1->balance) 
    { 
    case 1: N1->balance=0;   // в поддереве был перевес справа
        break;                // устанавливается равновесие
    case 0: N1->balance=-1;  // в поддереве было равновесие
        break;               // устанавливается перевес слева
    case -1:                     // в поддереве был перевес слева - необходима балансировка
        BalanceNode<TData,TKey>* p1;
        BalanceNode<TData,TKey>* p2;
        BalanceNode<TData,TKey>* p3;
        p1 = (BalanceNode<TData,TKey>*)(N1->Left);
        p3 = (BalanceNode<TData,TKey>*)(N1->Parent);
        if (p1->balance == -1)   // случай 1 - однократный LL поворот
        { //1
             if (p1->Right!= nullptr)
             { p1->Right->Parent = N1; }
             N1->Left = p1->Right;  
             //2
             if (N1 != nullptr)
             { N1->Parent = p1; }
             p1->Right = N1;       
             N1->balance=0;
             (*p1).Parent = p3;
             N1 = p1;
        }
        else  // случай 2 - двукратный LR поворот
        { 
             p2 = (BalanceNode<TData,TKey>*)(p1->Right);
             //1
             if (p2->Left != nullptr)
             { p2->Left->Parent = p1; }
             p1->Right = p2->Left;
             //2
             if (p1 != nullptr) 
             { (*p1).Parent = p2;}
             p2->Left = p1;
             //3
             if (p2->Right != nullptr)
             { p2->Right->Parent = N1; }
             N1->Left = p2->Right;
             //4
             if (N1 != nullptr) 
             { (*N1).Parent = p2; }
             p2->Right = N1;
             if (p2->balance == -1) N1->balance=1;
             else N1->balance = 0;
             if (p2->balance == 1) N1->balance=-1;
             else p1->balance = 0;
             (*p2).Parent= p3;
             N1 = p2;
        }
           N1->balance=0;
    }
  return abs(N1->balance);
}       
template <typename TData, typename TKey>
int AVLTree<TData, TKey>::RBalance(BalanceNode<TData,TKey>*& N1) 
{
    switch (N1->balance)
    {
    case -1: N1->balance=0;        // в поддереве был перевес слева
             break;                    // устанавливается равновесие
    case 0:  N1->balance=1;        // в поддереве было равновесие
             break;                    // устанавливается перевес справа
    case 1:  // в поддереве был перевес справа - необходима балансировка
             BalanceNode<TData,TKey>* p1;
             BalanceNode<TData,TKey>* p2;
             BalanceNode<TData,TKey>* p3 = (BalanceNode<TData,TKey>*)N1->Parent;
             p1 = (BalanceNode<TData,TKey>*)(N1->Right);
             if (p1->balance == 1) // случай 1 - однократный RR поворот
             { //1
               if (p1->Left != nullptr)
               { p1->Left->Parent = N1; }
               N1->Right = p1->Left; 
               //2
               if (N1 != nullptr)
               { (*N1).Parent = p1; }
               p1->Left = N1;
               N1->balance=0;
               N1 = p1;
               (*p1).Parent = p3;
             }
             else // случай 2 - двукратный RL поворот
             { p2 = (BalanceNode<TData,TKey>*)(p1->Left);
               //1
               if (p2->Right != nullptr)
               { p2->Right->Parent = p1; }
               p1->Left = p2->Right;    
               //2
               if (p1 != nullptr)
               { p1->Parent = p2; }
               p2->Right = p1;      
               //3
               if (p2->Left != nullptr)
               { p2->Left->Parent = N1; }
               N1->Right = p2->Left;      
               //4
               if (N1 != nullptr)
               { (*N1).Parent = p2; }
               p2->Left = N1;   
               if (p2->balance == 1) N1->balance=-1;
               else N1->balance = 0;
               if (p2->balance == -1) N1->balance=1;
               else p1->balance = 0;
               (*p2).Parent = p3;
               N1 = p2;
             }
             N1->balance=0;
    }
  return abs(N1->balance);;
}
