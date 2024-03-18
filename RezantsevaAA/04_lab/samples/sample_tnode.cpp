#include <iostream>
#include "tnode.h"
using namespace std;
int main()
{
    TNode<double> node;
    std::cout << "Create an empty node, node data = " << node.data <<std::endl;
    node.data = 5;
    std::cout << "Chage node data: node new data = " << node.data << std::endl;
    std::cout << "Node pNext = " << node.pNext << std::endl;
    node.pNext = new TNode<double>();
    node.pNext->data = 7;
    std::cout << "Create new node, new node data = " << node.pNext->data << std::endl;
    std::cout << "Node changed pNext = " << node.pNext << std::endl;
    return 0;
}
