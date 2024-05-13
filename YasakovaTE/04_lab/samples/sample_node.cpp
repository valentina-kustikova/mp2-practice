#include <iostream>
#include "node.h" 

int main() {
    TNode<double> node;
    int data;
    std::cout << "Let's create node, please enter node data " << std::endl;
    std::cin >> node.data;
    std::cout << "Our node: " << node.data << std::endl;
    std::cout << "pNext of our node: " << node.pNext << std::endl;
    return 0;
}