#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main()
{
	BSTree<int, char> T;
	T.Insert(5, ' ');
	T.Insert(3, ' ');
	T.Insert(10, ' ');
	T.Insert(6, ' ');
	T.Insert(9, ' ');
	T.Print();

	return 0;
}