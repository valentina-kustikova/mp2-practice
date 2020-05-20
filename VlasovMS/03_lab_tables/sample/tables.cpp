#include <iostream>
#include "TBinaryTree.h"
#include "TAVLTree.h"
#include "TOrderedTable.h"

int main()
{
    TBinaryTree<int, int> tree;
    tree.insert(1);
    tree.insert(2);
    auto iter = tree.find(2);
    std::cout << iter.key();
    auto iter2 = tree.find__IterPowered(2);
    std::cout << iter2.key();

    TAVLTree<int, int> avl = TAVLTree<int, int>();
    auto iter3 = avl.root();
    //std::cout << iter3.key();

    TArrayTable<int, int> table1(8);
    TOrderedTable<int, int> table2(8);
    table1.insert(2);
    table1.insert(1);
    table1.insert(4);
    std::cout << table1.find(2).key();

    table2.insert(2);
    table2.insert(1);
    table2.insert(4);
    std::cout << table2.find(4).key();
    return 0;
}