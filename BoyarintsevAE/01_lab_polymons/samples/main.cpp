#include <iostream>
#include "polinom.h"
#include "monom.h"

int main()
{
	/*std::cout << "START" << std::endl;
	TNode *node = new TNode;
	node->data = new TMonom(1, 101);
	node->pNext = nullptr;
	std::cout << "FINISH" << std::endl;
	return 0;*/
	


	TList lst;
	//TNode* node;
	
	lst.InsertToHead(10); //0
	lst.InsertToTail(15); //1
	lst.InsertToTail(28); //2

	//lst.InsertBefore(5, 28);

	lst.Search(15);

	lst.Print();
	



	return 0;
	 
}
