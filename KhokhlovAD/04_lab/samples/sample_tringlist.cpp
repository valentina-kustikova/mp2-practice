#include <iostream>
#include <tringlist.h>

int main()
{
    TNode<int>* _pFirst = new TNode<int>(2);
    TRingList<int> rl(_pFirst);
    TRingList<int> ringList;
    std::cout << rl << std::endl;
    ringList.InsertFirst(8);
    ringList.InsertFirst(9);
    std::cout << "Created with InsrtFirst ringlist " << std::endl;
    std::cout << ringList << std::endl;

    std::cout << "Lets delete first node in our ringlist " << std::endl;
    ringList.DeleteFirst();
    std::cout << ringList << std::endl;
    ringList.Reset();
    return 0;
}
