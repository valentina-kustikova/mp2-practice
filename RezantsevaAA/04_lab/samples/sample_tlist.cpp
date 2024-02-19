#include <iostream>
#include "tlist.h"
using namespace std;
int main()
{
    /*
   TList<int> list;
   list.InsertFirst(2);
   list.InsertFirst(3);
   
    const TNode<int>* tmp = new TNode<int>(1,nullptr);
    TList<int>* list2 = new TList<int>(tmp);

    std::cout << list << std::endl; //выводит ключи списка
*/

    TList<int> list;
    list.InsertFirst(1);
    list.InsertLast(2);

    
    return 0;
}
