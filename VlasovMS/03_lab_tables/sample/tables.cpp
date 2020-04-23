#include <iostream>
#include "TBinaryTree.h"
#include "TAVLTree.h"

int main()
{
    TBinaryTree<int, int> tree;
    tree.insert(1);
    tree.insert(2);
    auto iter = tree.find(2);
    auto iter2 = tree.find__IterPowered(2);

    TAVLTree<int, int> avl = TAVLTree<int, int>();
    auto iter3 = avl.root();
    return 0;
}