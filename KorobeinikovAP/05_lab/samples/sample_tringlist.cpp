#include <iostream>
#include "tlist.h"

int main()
{
	TNode<int>* c =  new TNode<int>(54, nullptr);
	TNode<int>* b = new TNode<int>(53, c);
	TNode<int>* a = new TNode<int>(52, b);

	TList<int> l(a);

    return 0;
}
