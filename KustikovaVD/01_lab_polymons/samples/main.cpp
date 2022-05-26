#include <iostream>

#include "node.h"
#include "monom.h"

int main()
{
    std::cout << "START" << std::endl;
    TNode *node = new TNode;
    node->data = new TMonom(1, 101);
    node->pNext = nullptr;
    std::cout << "FINISH" << std::endl;
	return 0;
}
