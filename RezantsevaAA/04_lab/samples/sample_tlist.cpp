#include <iostream>
#include "tlist.h"
using namespace std;

int main()
{
 
   TList<int> list;
   list.InsertFirst(3);
   list.InsertFirst(8);
   list.InsertFirst(7); //783
   
   std::cout << "Created with InsertFirst list with list length " << list.GetLength() <<" and this data:" << std::endl;
   std::cout << list << std::endl;
   list.Reset();
  
   std::cout << "Let's insert 9 before 8 and insert 4 after 8" << std::endl;
   list.InsertBefore(9, 8); //7983
   list.InsertAfter(4, 8); //79843
   list.Reset();
   std::cout << list << std::endl;
  
   std::cout << "Lets sort our list " << std::endl;
   list.Sort(); //98743
   std::cout << list << std::endl;
 
   std::cout << "Lets insert last 5  in our sorted list and set new data = 6 for current node = 7" << std::endl;
   list.InsertLast(5);
   list.Next();
   list.Next();
   list.setCurrData(6);

   std::cout << list << std::endl;
   std::cout << "Lets insert 7 after current with data = " << list.getCurrData() << std::endl;
   list.InsertAfterCurrent(7);
   std::cout << list << std::endl;

   std::cout << "Lets remove node with data = 7 use RemoveCurrent and remove first node" << std::endl;
   list.RemoveCurrent();
   list.GetLength();
   list.RemoveFirst();
   std::cout << list << std::endl;

   return 0;
}
