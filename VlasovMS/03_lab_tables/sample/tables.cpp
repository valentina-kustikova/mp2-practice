#include <iostream>
#include "TBinaryTree.h"

int main()
{
    TBinaryTree<int, int> tree;
    tree.insert(1);
    tree.insert(2);
    auto iter = tree.find(2);
    auto iter2 = tree.find__IterPowered(2);
    return 0;
}